
#include "base_fsmc.h"
#include "base_rcc.h"
#include "base_gpio.h"

#include "cnf_usart.h"

#include "com.h"

#include "ssd1289_base.h"
#include "ssd1289_type.h"
#include "ssd1289_font.h"
#include "ssd1289_graphic.h"

#include "bitmap.h"
#include "font_lib.h"

#define REG_INDEX 	FSMC_NORPSRAM4_VALUE(0)  //只能写
#define REG_STATE		FSMC_NORPSRAM4_VALUE(0)	 //只能读
#define REG_VALUE		FSMC_NORPSRAM4_VALUE(2)	 //可读可写

#define LCD_REG			FSMC_NORPSRAM4_VALUE(0)		//向IR处写数据
#define LCD_RAM			FSMC_NORPSRAM4_VALUE(2)     //向RAM中写数据

#define SSD1289_CMD_X_POS
#define SSD1289_CMD_Y_POS

#define SSD1289_CMD_WINDOW_H_START_END	0x44  	//X后半字
#define SSD1289_CMD_WINDOW_V_START  0x45		//Y起始
#define SSD1289_CMD_WINDOW_V_END    0x46    	//Y末尾

#define LCD_SSD1289_turn_on_back_light()	GPIO_send_pin(GPIO_A, 1, 1)
#define LCD_SSD1289_turn_off_back_light()	GPIO_send_pin(GPIO_A, 1, 0)

//状态定义部分
SSD1289_INITIAL_STRUCT ScreenState = 
{
	ORITATION_240_320, 
	COLOR_262K,
	0x00,
	1,
	0	//未初始化
};


//***************************************LCD_SSD1289初始化部分*********************************//
//引脚初始化
void SSD1289_pins_init()
{
	RCC_enable_FSMC_clock();	//给FSMC模块提供时钟
	
//给GPIO提供时钟 
	RCC_enable_GPIO_B_clock();
	RCC_enable_GPIO_D_clock();
	RCC_enable_GPIO_E_clock();
	RCC_enable_GPIO_G_clock();
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_G_clock();
	RCC_enable_GPIO_F_clock();
	
//给复用模块提供时钟
	RCC_enable_AFIO_clock();

//D0 - D15	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 10);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 9);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 8);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 15);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 14);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 13);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 12);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 11);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 10);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 9);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 8);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_E, 7);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 1);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 0);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 15);
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 14);

//RS
	GPIO_set_output_50MHZ_PP_MUL(GPIO_F, 0);
	
//NOE - read enable
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 4);
	
//NWE - Write enable
	GPIO_set_output_50MHZ_PP_MUL(GPIO_D, 5);
	
//NE4 - CS	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_G, 12);

//Back Light 背光设置
	GPIO_set_output_50MHZ_PP(GPIO_A, 1);			
}




/*
SD1289所使用的FSMC配置
	对FSMC配置
	FSMC是灵活外部存储器访问通道
	提供了对不同接口外存的访问时序和信号处理
	
	该函数使用的是FSMC模块中NOR/PSRAM模块的BAND4
	由于不同的Band只影响地址线最高2位 （选择Band）
	所以在此选用Band4和选用Band1是相同的效果
	
	F103内部对不同的Band有独立的控制寄存器
	而在此使用的Band4的寄存器来控制输出信号
	
	该函数使用SRAM外存访问时序的信号处理
	对SSD1289的访问不需要地址线
	SSD1289的内部IR寄存器指示了下一个将要访问的GRAM或GDDRAM地址
	由RS引脚控制IR寄存器和ＧＲＡＭ访问
	RS引脚接FSMC模块A0引脚
	所以给FSMC使用不同的A0地址将产生不同的RS信号
	由于外部为16位存储器访问，内部AHB总线的A1线将接到FSMC的A0线
	所以内部程序所设置的地址的第1位控制RS
	
	此函数将FSMC配置为读写同时序的模式（非扩展模式）
	SSD1289对时序没有要求
	只需在片选时数据进入
	
	对引脚的配置参见:LCD_SSD1289_pins_init
*/
	
void SSD1289_FSMC_init()
{
	//时序配置
	FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK();	//地址建立时间为2个HCLK(做用于RS到接下来的数据之间的延迟)
	//FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK();		//地址保持时间为2个HCLK(无用)
	FSMC_NORPSRAM4_set_data_setup_phase_duration(3);			//数据的建立时间
	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK();				//总线的恢复时间为1个HCLK
	//FSMC_NORPSRAM4_div_HCLK_with_2();  							//CLK的分频(无用)
	//FSMC_NORPSRAM4_latency_is_2_CLK();							//第一次访问需要等待的时间（无用）
	FSMC_NORPSRAM4_access_mode_A();								//访问模式为A模式
	/*
		上注:对于LCD来说无所谓哪个模式了，
		因为LCD只是使用了FSMC中的 DB[0-15]，RC，RS,NOE ，NWE,地址的最后一位来选中RS，当第0位(在AHB总线上是第1位)为
		1时是访问GDDRAM的数据，否则是访问IR寄存器的数据，也就是数据/命令选择。
		而在整个运行过程中，没有严格的时序，毕竟LCD并不是真正意义上的存储器。
		没有时序之说。
	*/
	//控制配置
	FSMC_NORPSRAM4_disable_multiplexed();						//禁止地址线和数据线复用
	FSMC_NORPSRAM4_memory_type_is_SRAM();						//选择存储器类型为SRAM
	FSMC_NORPSRAM4_data_width_is_16();							//存储器数据线的宽度为16位
	FSMC_NORPSRAM4_disable_burst_access();						//禁止成组模式访问
	FSMC_NORPSRAM4_NWAIT_active_low();							//等待信号为低有效
	FSMC_NORPSRAM4_disable_split();								//禁止非对其的地址访问
	FSMC_NORPSRAM4_NWAIT_inserted_before_wait_state();			//等待信号在等待状态之前插入
	FSMC_NORPSRAM4_enable_write_operation();					//写操作使能
	FSMC_NORPSRAM4_disable_wait_signal();						//进制等待信号
	FSMC_NORPSRAM4_disable_extended_mode();						//禁止扩展模式(写时序和读时序相同)
	
	//使能FSMC模块
	FSMC_NORPSRAM4_enable_bank();								//使能模块
}


/*
SSD1289内部初始化 
	对SSD1289按照参数指定的方式初始化
	见LCD_SSD1289_init的详细说明
*/
void SSD1289_internal_init(SSD1289_INITIAL_STRUCT state)
{
	
	SSD1289_send_data(0x0000,0x0001);		//打开晶振
	SSD1289_send_data(0x0003,0xA8A4);		//电源控制配置1
	SSD1289_send_data(0x000C,0x0000);     	//电源控制配置2 
	SSD1289_send_data(0x000D,0x080C);     	//电源控制配置3 
	SSD1289_send_data(0x000E,0x2B00);       //电源控制配置4 
	SSD1289_send_data(0x001E,0x00B0);     	//电源控制配置5
	
	
	//驱动输出控制240*320 0x2B3F 320*240 0x293F 
	/*
		原理:TB位用来控制G0 - G319 or G319 - G0 当TB为1时为后者，这也是0x2B3F和293F的不同之处。
			 RL位用来控制S0 - S719 or S719 - S0	但在这里没有用上。
	*/	
	SSD1289_send_data(0x0001,(state.oritation == ORITATION_240_320)?0x2B3F:0x293F);		//根据方向参数写入命令  	
	
	SSD1289_send_data(0x0002,0x0600);     	//LCD Driving Waveform control
	SSD1289_send_data(0x0010,0x0000);       //LCD 睡眠模式控制(关闭)
	
	/*
		此命令用来设定显示的颜色和地址的更新方向
		当设置为240*320方向时: 地址按正常的从左上角到右下角
		当设置为320*240方向时，由于Gate翻转(为了满足（0,0）点为此时屏幕方向的左上角)
			此时的地址更新方式也是该方向的左上角到右下角，但如果不翻转的Gate的话，此
			效果会丢失。
	*/
	if(state.color == COLOR_262K)
		SSD1289_send_data(0x0011, state.oritation == ORITATION_240_320 ? 0x4070 : 0x4078);
	else
		SSD1289_send_data(0x0011, state.oritation == ORITATION_240_320 ? 0x6070 : 0x6078);
	
	SSD1289_send_data(0x0005,0x0000);     
	SSD1289_send_data(0x0006,0x0000);     
	SSD1289_send_data(0x0016,0xEF1C);     
	SSD1289_send_data(0x0017,0x0003);     
	SSD1289_send_data(0x0007,0x0233);		     
	SSD1289_send_data(0x000B,0x0000);     
	SSD1289_send_data(0x000F,0x0000);	//扫描开始地址
	SSD1289_send_data(0x0041,0x0000);     
	SSD1289_send_data(0x0042,0x0000);     
	SSD1289_send_data(0x0048,0x0000);     
	SSD1289_send_data(0x0049,0x013F);     
	SSD1289_send_data(0x004A,0x0000);     
	SSD1289_send_data(0x004B,0x0000);     
	SSD1289_send_data(0x0044,0xEF00);  	//水平末尾 + 水平起始   
	SSD1289_send_data(0x0045,0x0000);  	//垂直开始
	SSD1289_send_data(0x0046,0x013F);  	//垂直末尾     
	SSD1289_send_data(0x0030,0x0707);     
	SSD1289_send_data(0x0031,0x0204);     
	SSD1289_send_data(0x0032,0x0204);     
	SSD1289_send_data(0x0033,0x0502);     
	SSD1289_send_data(0x0034,0x0507);     
	SSD1289_send_data(0x0035,0x0204);     
	SSD1289_send_data(0x0036,0x0204);     
	SSD1289_send_data(0x0037,0x0502);     
	SSD1289_send_data(0x003A,0x0302);     
	SSD1289_send_data(0x003B,0x0302);     
	SSD1289_send_data(0x0023,0x0000);     
	SSD1289_send_data(0x0024,0x0000);     
	SSD1289_send_data(0x0025,0x8000);     
	SSD1289_send_data(0x004e,0);        
	SSD1289_send_data(0x004f,0);        
}



/*
SSD1289初始化 
	根据参数所定义的值初始化LCD
	可控制的初始化包括：
		LCD背景色
		LCD显示方向:
			ORITATION_240_320
			ORITATION_320_240
		LCD颜色质量:
			COLOR_262K
			COLOR_65K
*/
void SSD1289_init(SSD1289_INITIAL_STRUCT initialState)
{
	//ScreenState = initialState;
	FontFormat.backColor = initialState.backgroundColor;
	FontFormat.color = ~(FontFormat.backColor);
	SSD1289_pins_init();										//初始化引脚
	initialState.backLight ? LCD_SSD1289_turn_on_back_light() : LCD_SSD1289_turn_off_back_light();
	SSD1289_FSMC_init(); 	  									//初始化FSMC模块
	SSD1289_internal_init(initialState);  						//LCD内部初始化
	
	SSD1289_clear_screen(ScreenState.backgroundColor);			//清屏	
	
	ScreenState.isInit = 1;
	
}


//***************************************LCD_SSD1289内部操作部分*********************************//
//向SSD1289发送数据
//regIndex = 0x00 - 0xFF
//regValue = 16位
static void SSD1289_send_data(U16 regIndex, U16 regValue)
{
	REG_INDEX = regIndex;
	REG_VALUE = regValue;
}

//从SSD1289接收RAM中的数据
static U32 SSD1289_get_data(U16 regIndex)
{
	REG_INDEX = regIndex;
	return REG_VALUE; 
}


/*
设置下一个颜色将要去的地址
	该位产生的效果跟屏幕方向有关
	屏幕方向跟TB位有关
	TB位控制G0 - G319 
	也就是设置的X，Y所产生的地址所对应的Gate跟屏幕方向有关

	可配置在240 * 320情况下
	可配置在320 * 240情况下
	来产生不同的Gate地址
*/
void SSD1289_set_GDDRAM_position(U16 x, U16 y)
{
	if(ScreenState.oritation == ORITATION_240_320)  //如果是240*320模式
	{
		if(x > 240 || y > 320 )
		return;
		SSD1289_send_data(0x004e, x);	//设置x坐标
		SSD1289_send_data(0x004f, y);   //设置y坐标
	}
	else											//如果是320*240模式
	{
		if(x > 320 || y > 240)
		return;
	
		SSD1289_send_data(0x004e, y);
		SSD1289_send_data(0x004f, x);
	}
}


//***************************************LCD_SSD1289绘图部分*********************************//
/*
在AC所指GDDRAM处绘制颜色
	可在COLOR_262K模式下
	可在COLOR_65K模式下
	262K颜色需要18位:R,G,B各6位
	65K颜色需要16位:R5 G6 B5 
*/
void SSD1289_set_point(U32 RGB_color)
{
	if(ScreenState.color == COLOR_65K)   //如果是65k，则只需发送一个半子   (1.RGB (5.6.5))
	{
		SSD1289_send_data(0x22, RGB_color);
		//Debug:
		//USART1_printf("color == 0X%X\n", RGB_color);
	}	
	else                                       //如果是262K颜色，则要发两个连续的半子(1.RG 2.0x0B)
	{
		//Debug:
		
		U32 R = ((RGB_color)>>12)&0x3F;
		U32 G = ((RGB_color)>>6)&0x3F;
		U32 B = RGB_color&0x3F;
		
		SSD1289_send_data(0x22, (R<<10) | (G << 2));
		REG_VALUE = (B<<2);
	}	
}

/*
获得AC所指GDDRAM处的颜色
	可在COLOR_262K模式下
	可在COLOR_65K模式下
*/
U32 SSD1289_get_point()
{
	if(ScreenState.color == COLOR_65K)   //如果是65k，则只需发送一个半子   (1.RGB (5.6.5))
	{
		return SSD1289_get_data(0x22);
		//Debug:
		//USART1_printf("color == 0X%X\n", RGB_color);
	}	
	else                                       //如果是262K颜色，则要发两个连续的半子(1.RG 2.0x0B)
	{
		//error here!!!
		U32 r, g, b;
	
		REG_INDEX = 0x22;
		
		r = REG_VALUE;
		g = REG_VALUE;
		b = REG_VALUE;
		
		return RGB_262K(r, g, b);
	}
}

/*
	清屏LCD
	支持用262K颜色清屏(在262K模式下)
	支持用65K颜色清屏(在65K模式下)
*/
void SSD1289_clear_screen(U32 color)
{
	U32 index = 0;
	SSD1289_set_GDDRAM_position(0, 0);
	for(index = 0;index < 172800; index++)
		SSD1289_set_point(color);
}

/*
设置显示窗口
	在设置了该函数后，下一步设置的点将从该窗口的左上角开始绘制
	之后的点绘制不需要重新设置点位置
	点阵计数器会自动按照所设置的窗口从窗口的左上角横向递增到右下角
	每设置一个点，递增一次
	可以通过条用LCD_SSD1289_set_full_window来抹除该窗口，使窗口显示为全屏(具体看LCD_SSD1289_set_full_window说明)
*/
void SSD1289_set_window(U16 hStart, U16 vStart, U16 hEnd, U16 vEnd)
{
	U16 newhStart = hStart;
	U16 newvStart = vStart;
	U16 newhEnd = hEnd;
	U16 newvEnd = vEnd;
	U16 h_temp;
	/*
		如果是320 * 240的方向，Gate是从（G319 - G0算的），也就是当
		在GRAM设置坐标(0 , 0)时， 此时是G319和S0, 在设置window时也一样。
		window的起始和末尾也是从G319到G0来算的.
	*/
	if(ScreenState.oritation == ORITATION_320_240)   
	{
		newhStart = vStart;
		newvStart = hStart;
		newhEnd = vEnd;
		newvEnd = hEnd;
	}
	
	h_temp = (newhStart&0xFF) | ((newhEnd&0xFF) << 8);
	SSD1289_send_data(0x44, h_temp);				//设置window横向范围
	SSD1289_send_data(0x45, newvStart&0x1FF);	
	SSD1289_send_data(0x46, newvEnd&0x1FF);

	SSD1289_set_GDDRAM_position(hStart, vStart);	//设置AC为窗口的左上角位置(相对于320*240或240*320)	
	//Debug:
	//USART1_printf("x Start = %d y Start = %d\n", newhStart, newvStart );
}


/*
恢复全屏窗口
	恢复后的窗口将为全屏
	并且绘制的第一点将在窗口的左上角位置
*/
void SSD1289_set_full_window()
{
	ScreenState.oritation == ORITATION_240_320 ? SSD1289_set_window(0, 0, 239, 319) : SSD1289_set_window(0, 0, 319, 239);
	SSD1289_set_GDDRAM_position(0 , 0);
}


/*
	函数功能:根据参数在屏幕上绘制一个262K颜色的图片
	bitMapWidth和bitMapHigh根据xStar,yStart的不同有不同的范围，不要超过该范围，否则图片会重叠显示
*/
void SSD1289_draw_bitmap_262K(U16 bitMapWidth, U16 bitMapHigh, U16 xStart, U16 yStart, const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                   //就算点阵数量
	U32 color_temp;
	                                  
	SSD1289_set_window(xStart, yStart, bitMapWidth - 1, bitMapHigh - 1); //设置窗口
	while(index--)
	{
		color_temp = RGB_262K((*pPic), *(pPic + 1), (*pPic + 2));
		pPic += 3;
		SSD1289_set_point(color_temp);
	}
	SSD1289_set_full_window();               
}


/*
	函数功能:根据参数在屏幕上绘制一个65K颜色的图片
	bitMapWidth和bitMapHigh根据xStar,yStart的不同有不同的范围，不要超过该范围，否则图片会重叠显示
*/
void SSD1289_draw_bitmap_65K(	U16 bitMapWidth, 
									U16 bitMapHigh, 
									U16 xStart, 
									U16 yStart, 
									const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                    //就算点阵数量
	U32 color_temp;
	
	SSD1289_set_window(xStart, yStart, bitMapWidth - 1, bitMapHigh - 1); //设置窗口
	
	while(index--)
	{
		color_temp = *pPic;
		color_temp = (color_temp << 8) | *(pPic + 1);
		pPic += 2;
		SSD1289_set_point(color_temp);
	}
	SSD1289_set_full_window();
}


//*************************************文字显示部分*****************************************//
/*
	本函数可以显示8*16的等宽字体
*/
void SSD1289_draw_font_8_16(
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 fontHigh = 8;
	U32 bitOp = 0x1 << 7;
	
	SSD1289_set_window(xStart, yStart, xStart + 7, yStart + 15);	//设置文字窗口
	while(fontHigh--)
	{
		font_temp = *pFont ++;
		for(index_temp = 0; index_temp < 8; index_temp ++)
		{
			SSD1289_set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
		}		
	}
	SSD1289_set_full_window();
}


/*
	显示数据以右对齐方式排列的字符
		右对齐如: 	0011 1111 1111 1111 
		左对齐如:   1111 1111 1111 1100
	fontWidth指定字体大小:
		适用于所有大小的字体
	指定显示位置:
		xStart，yStart 范围应该在相应屏幕方向的对应的x，y内
	前景色
		color
	背景色
		backColor
	指向字符地址
*/
void SSD1289_draw_font_right_align(
							U16 fontWidth,   //字符宽度
							U16 fontHigh,    //字符高度
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 bitOp = 0x1 << 7;
	U32 byteNumPerLine = (fontWidth%8) ? (fontWidth/8 + 1) : (fontWidth/8);		//每一行需要几个字节
		
	SSD1289_set_window(xStart, yStart, xStart + fontWidth - 1, yStart + fontHigh - 1);	//设置文字窗口
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //位计数
		U32 temp ;
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if(index_temp == 1)		                        //每一行的开始，取一次数据
			{
				font_temp = *pFont++;
				temp = 8*byteNumPerLine - fontWidth;	//temp表示无用位的个数
				font_temp  <<= temp;
				bitCounter -= temp;							//bitCounter减掉无用位的个数
			}	
			if(bitCounter == 0)		//如果一个字节显示完了，换下一个字节
			{
				bitCounter = 8;
				font_temp =  *pFont++;
			}	
			SSD1289_set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
			bitCounter -- ;				//显示一个位完了
			
		}		
	}
	SSD1289_set_full_window();
}


/*
	显示数据以左对齐方式排列的字符
		右对齐如: 	0011 1111 1111 1111 
		左对齐如:   1111 1111 1111 1100
	fontWidth指定字体大小:
		适用于所有大小的字体
	指定显示位置:
		xStart，yStart 范围应该在相应屏幕方向的对应的x，y内
	前景色
		color
	背景色
		backColor
	指向字符地址
*/
void SSD1289_draw_font_left_align(
							U16 fontWidth,   //字符宽度
							U16 fontHigh,    //字符高度
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 bitOp = 0x1 << 7;	
	SSD1289_set_window(xStart, yStart, xStart + fontWidth - 1, yStart + fontHigh - 1);	//设置文字窗口
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //位计数
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if((index_temp == 1) || (bitCounter == 0) || ((index_temp < fontWidth) && (index_temp%fontWidth == 0)))	                        //每一行的开始，取一次数据
			{
				font_temp = *pFont++;
				bitCounter = 8;
			}	
			SSD1289_set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
			bitCounter -- ;			//显示一个位完了
		}		
	}
	SSD1289_set_full_window();
}



//*****************************************************************************************//
//***********************************下面的函数主要用来测试LCD的功能***********************//
//*****************************************************************************************//




void LCD_window_test(void)
{
	//LCD_draw_moving_rectangle();
	//LCD_draw_rectangle(0, 	100,  	100, 	100, 	RGB(0, 0, 0xF));
	//LCD_draw_rectangle(150, 100,  	100,	100, 	RGB(0, 0, 0xF));
	//LCD_SSD1289_draw_bitmap_65K(180, 240, 0, 0, R_bitmap_2);
	//LCD_SSD1289_draw_bitmap_262K(180, 240, 0, 0, R_bitmap_1);
	//LCD_SSD1289_set_point();
	//_LCD_SSD1289_draw_font(8, 16, 10, 10, RGB_RED, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20], 3, 3);
    // LCD_SSD1289_draw_font(8, 16, 50, 10, RGB_RED, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20]);
	//LCD_SSD
	//LCD_big_to_small();      //娱乐娱乐...
//	LCD_SSD1289_draw_font_left_align(24, 31, 10, 10, RGB_RED, BACKGROUND_COLOR, char_24x31);
//	LCD_SSD1289_draw_font_left_align(15, 31, 100, 10, RGB_RED, BACKGROUND_COLOR, char_12x31);
//	LCD_SSD1289_draw_font_left_align(10, 19, 50, 50, RGB_GREEN, BACKGROUND_COLOR, ansi_font10x19['S'- 0x20]);
}

//此函数仅供娱乐
void LCD_draw_moving_rectangle()
{
	int x = 0;
	int y = 0;
	
	for(x = 0, y = 0; x < 100 && y < 100; x ++, y++)
	{
		LCD_draw_rectangle(x, y, 100, 100, RGB(0x3F, 0x3F, 0x3F));
		LCD_draw_rectangle(x, y, 100, 100, RGB(0, 0, 0));
	}
	LCD_draw_rectangle(x, y, 100, 100, RGB(0x3F, 0x3F, 0x3F));
}


//可以将字体放大显示的方式
//此函数仅供娱乐
void _LCD_SSD1289_draw_font(
							U16 fontWidth,   //字符宽度
							U16 fontHigh,    //字符高度
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont,
							U32 mulX,
							U32 mulY
							)
{
	U8 temp;
	U32 font_temp;
	U32 bitOp = 0x1 << (fontWidth - 1);
	U32 mulX_temp = 1;
	U32 mulY_temp = 1;
	SSD1289_set_window(xStart, yStart, xStart + fontWidth * mulX - 1, yStart + fontHigh * mulY - 1);
	while(fontHigh--)
	{
		font_temp = *pFont++;
		for(mulY_temp = 1; mulY_temp <= mulY; mulY_temp ++)
		{
			for(temp = 1; temp <= fontWidth; temp++)
			{
				for(mulX_temp = 1; mulX_temp < mulX; mulX_temp ++)		//X放大多少倍，每一个点就输出多少次
					SSD1289_set_point((font_temp&bitOp)?color:backColor);
				
				font_temp <<= 1;
			}
		}
	}
	SSD1289_set_full_window();
}

//此函数仅供娱乐
void LCD_big_to_small()
{
	int mul;
	while(1)
	{
		for(mul = 2; mul <= 15; mul ++)
		{
			_LCD_SSD1289_draw_font(8, 16, 50, 50, RGB_RED, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20], mul, mul);
			_LCD_SSD1289_draw_font(8, 16, 50, 50, BACKGROUND_COLOR, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20], mul, mul);
			delay(1000);
		}
			
		for(mul = 15; mul >= 2; mul --)
		{
			_LCD_SSD1289_draw_font(8, 16, 50, 50, RGB_RED, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20], mul, mul);
			_LCD_SSD1289_draw_font(8, 16, 50, 50, BACKGROUND_COLOR, BACKGROUND_COLOR, ansi_font8x16['S' - 0x20], mul, mul);
			delay(1000);
		}
	}
}


















