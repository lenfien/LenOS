#define __CPlusPlus

#include "base.h"
#include "ssd1289.h"
#include "font.h"
#include "color.h"
#include "out.h"
#include "datas.h"
#include "touch.h"
/*
	静态数据成员初始化
*/
SSD1289::InitialStruct SSD1289::state = 
{
		ORITATION_320_240,
		Color::COLOR_262K,
		0,
		1
};

bool SSD1289::isInitialized = false;


//引脚初始化
void SSD1289::pins_init()
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
	
void SSD1289::FSMC_init()
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
		因为LCD只是使用了FSMC中的 DB[0-15]，RC，RS,NOE ，NWE,地址的最后一位来选中RS，
		当第0位(在AHB总线上是第1位)为
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
void SSD1289::internal_init(SSD1289::InitialStruct state)
{
	send_data(0x0000,0x0001);		//打开晶振
	send_data(0x0003,0xA8A4);		//电源控制配置1
	send_data(0x000C,0x0000);     	//电源控制配置2 
	send_data(0x000D,0x080C);     	//电源控制配置3 
	send_data(0x000E,0x2B00);       //电源控制配置4 
	send_data(0x001E,0x00B0);     	//电源控制配置5
	
	//驱动输出控制240*320 0x2B3F 320*240 0x293F 
	/*
		原理:TB位用来控制G0 - G319 or G319 - G0 当TB为1时为后者，这也是0x2B3F和293F的不同之处。
			 RL位用来控制S0 - S719 or S719 - S0	但在这里没有用上。
	*/	
	send_data(0x0001,(state.oritation == ORITATION_240_320)?0x2B3F:0x293F);		//根据方向参数写入命令  	
	
	send_data(0x0002,0x0600);     	//LCD Driving Waveform control
	send_data(0x0010,0x0000);       //LCD 睡眠模式控制(关闭)
	
	/*
		此命令用来设定显示的颜色和地址的更新方向
		当设置为240*320方向时: 地址按正常的从左上角到右下角
		当设置为320*240方向时，由于Gate翻转(为了满足（0,0）点为此时屏幕方向的左上角)
			此时的地址更新方式也是该方向的左上角到右下角，但如果不翻转的Gate的话，此
			效果会丢失。
	*/
	if(state.colorQuality == Color::COLOR_262K)
		send_data(0x0011, state.oritation == ORITATION_240_320 ? 0x4070 : 0x4078);
	else
		send_data(0x0011, state.oritation == ORITATION_240_320 ? 0x6070 : 0x6078);
	
	send_data(0x0005,0x0000);     
	send_data(0x0006,0x0000);     
	send_data(0x0016,0xEF1C);     
	send_data(0x0017,0x0003);     
	send_data(0x0007,0x0233);		     
	send_data(0x000B,0x0000);     
	send_data(0x000F,0x0000);	//扫描开始地址
	send_data(0x0041,0x0000);     
	send_data(0x0042,0x0000);     
	send_data(0x0048,0x0000);     
	send_data(0x0049,0x013F);     
	send_data(0x004A,0x0000);     
	send_data(0x004B,0x0000);     
	send_data(0x0044,0xEF00);  	//水平末尾 + 水平起始   
	send_data(0x0045,0x0000);  	//垂直开始
	send_data(0x0046,0x013F);  	//垂直末尾     
	send_data(0x0030,0x0707);     
	send_data(0x0031,0x0204);     
	send_data(0x0032,0x0204);     
	send_data(0x0033,0x0502);     
	send_data(0x0034,0x0507);     
	send_data(0x0035,0x0204);     
	send_data(0x0036,0x0204);     
	send_data(0x0037,0x0502);     
	send_data(0x003A,0x0302);     
	send_data(0x003B,0x0302);     
	send_data(0x0023,0x0000);     
	send_data(0x0024,0x0000);     
	send_data(0x0025,0x8000);     
	send_data(0x004e,0);        
	send_data(0x004f,0);        
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
void SSD1289::init(SSD1289::InitialStruct initialState)
{ 
	state = initialState;
	pins_init();														//初始化引脚
	initialState.backLight ? turn_on_back_light() : turn_off_back_light();
	FSMC_init(); 	  												//初始化FSMC模块
	internal_init(initialState);  					//LCD内部初始化	
	SSD1289::isInitialized = true;			
}




//获得x,y点处的颜色
Color::ColorValue SSD1289::get_point_262K(U16 x, U16 y)
{
	if(x > width() || y > high())
		return 0;
	
	REG_INDEX = 0x22;
	
	set_GDDRAM_position(x, y);
	
	REG_INDEX = 0x22;
	
	U16 color1 = REG_VALUE;	//假读
	
	color1 = REG_VALUE;	//第一次读上16位
	
	U16 color2 = REG_VALUE;
	
	U16 b = (color1&0xFC00)>> 10;
	U16 g = (color1&0xFC) >> 2;
	U16 r = (color2&0xFC00)>>10;
	
	return Color::RGB262K(r, g, b) ;
}



//获得x,y点处的颜色
U32 SSD1289::get_point_65K(U16 x, U16 y)
{
	if(x > width() || y > high())
		return 0;
	
	REG_INDEX = 0x22;
	
	set_GDDRAM_position(x, y);
	
	REG_INDEX = 0x22;
	
	U16 color1 = REG_VALUE;	//假读
	
	color1 = REG_VALUE;	//第一次读上16位
	
	return color1;
}






//获得一个区域的点的颜色数组. 并存放到dis所指的目标空间, 返回点阵数
U32 SSD1289::get_points_262K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, unsigned char *dis)
{
	ADS7843::sleep();
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//假读
	U16 color2;
	int index = 0;
	
	while(index < max)
	{
		color1 = REG_VALUE;
		color2 = REG_VALUE;
		
		U8 b = (color1&0xFC00)>> 10;
		U8 g = (color1&0xFC) >> 2;
		U8 r = (color2&0xFC00)>>10;
		
		*dis++ = r;
		*dis++ = g;
		*dis++ = b;
		
		index ++;
	}
	set_full_window();
	ADS7843::awake();
	return max;
}




//获得一个区域的点的颜色数组. 并存放到dis所指的目标空间, 返回点阵数
U32 SSD1289::get_points_262K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, Datas<Color::ColorType>& dis)
{
	ADS7843::sleep();
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//假读
	U16 color2;
	int index = 0;
	Color::ColorType c;
	while(index < max)
	{
		color1 = REG_VALUE;
		color2 = REG_VALUE;
		
		c.r = (color1&0xFC00)>> 10;
		c.g = (color1&0xFC) >> 2;
		c.b = (color2&0xFC00)>>10;

		dis.push_back(c);
		
		index ++;
	}
	set_full_window();
	ADS7843::awake();
	return max;
}






//获得一个区域的点的颜色数组. 并存放到dis所指的目标空间, 返回点阵数
U32 SSD1289::get_points_65K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, unsigned char *dis)
{
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//假读
	int index = 0;
	
	while(index < max)
	{
		color1 = REG_VALUE;
		
		U8 b = (color1&0x1F);
		U8 g = (color1&0x7E) >> 5;
		U8 r = (color1&0xF8)>>11;
		
		*dis++ = r;
		*dis++ = g;
		*dis++ = b;
		
		index ++;
	}
	set_full_window();
	return max;
}




//获得一个区域的点的颜色数组. 并存放到dis所指的目标空间, 返回点阵数
U32 SSD1289::get_points_65K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, Datas<Color::ColorType>& dis)
{
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//假读
	int index = 0;
	Color::ColorType c;
	while(index < max)
	{
		color1 = REG_VALUE;
		
		c.b = (color1&0x1F);
		c.g = (color1&0x7E) >> 5;
		c.r = (color1&0xF8)>>11;
		
		dis.push_back(c);
		
		index ++;
	}
	set_full_window();
	return max;
}







/*
	清屏LCD
	支持用262K颜色清屏(在262K模式下)
	支持用65K颜色清屏(在65K模式下)
*/
void SSD1289::clear_screen_262K(U32 color)
{
	ADS7843::sleep();
	U32 index = 0;
	set_GDDRAM_position(0, 0);
	for(index = 0;index < 172800; index++)
		set_point_262K(color);
	ADS7843::awake();
}





/*
	清屏LCD
	支持用262K颜色清屏(在262K模式下)
	支持用65K颜色清屏(在65K模式下)
*/
void SSD1289::clear_screen_65K(U32 color)
{
	ADS7843::sleep();
	U32 index = 0;
	set_GDDRAM_position(0, 0);
	for(index = 0;index < 172800; index++)
		set_point_65K(color);
	ADS7843::awake();
}






/*
设置显示窗口
	在设置了该函数后，下一步设置的点将从该窗口的左上角开始绘制
	之后的点绘制不需要重新设置点位置
	点阵计数器会自动按照所设置的窗口从窗口的左上角横向递增到右下角
	每设置一个点，递增一次
	可以通过条用LCD_SSD1289_set_full_window来抹除该窗口，使窗口显示为全屏(具体看LCD_SSD1289_set_full_window说明)
*/
void SSD1289::set_window(U16 hStart, U16 vStart, U16 hLen, U16 vLen)
{
	hLen = hStart + hLen - 1;
	vLen = vStart + vLen - 1;
	S16 newhStart = hStart;
	S16 newvStart = vStart;
	S16 newhEnd = hLen;
	S16 newvEnd = vLen;
	
	U16 h_temp;

	/*
		如果是320 * 240的方向，Gate是从（G319 - G0算的），也就是当
		在GRAM设置坐标(0 , 0)时， 此时是G319和S0, 在设置window时也一样。
		window的起始和末尾也是从G319到G0来算的.
	*/
	if(state.oritation == ORITATION_320_240)   
	{
		newhStart = vStart;
		newvStart = hStart;
		newhEnd = vLen;
		newvEnd = hLen;
	}
	
	h_temp = (newhStart&0xFF) | ((newhEnd&0xFF) << 8);
	send_data(0x44, h_temp);				//设置window横向范围
	send_data(0x45, newvStart&0x1FF);	
	send_data(0x46, newvEnd&0x1FF);
	
	ADS7843::sleep();
	set_GDDRAM_position(hStart, vStart);	//设置AC为窗口的左上角位置(相对于320*240或240*320)	
}



/*
恢复全屏窗口
	恢复后的窗口将为全屏
	并且绘制的第一点将在窗口的左上角位置
*/
void SSD1289::set_full_window()
{
	state.oritation == ORITATION_240_320 ? set_window(0, 0, 239, 319) : set_window(0, 0, 319, 239);
	set_GDDRAM_position(0 , 0);
	ADS7843::awake();
}





