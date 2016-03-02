
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

#define REG_INDEX 	FSMC_NORPSRAM4_VALUE(0)  //ֻ��д
#define REG_STATE		FSMC_NORPSRAM4_VALUE(0)	 //ֻ�ܶ�
#define REG_VALUE		FSMC_NORPSRAM4_VALUE(2)	 //�ɶ���д

#define LCD_REG			FSMC_NORPSRAM4_VALUE(0)		//��IR��д����
#define LCD_RAM			FSMC_NORPSRAM4_VALUE(2)     //��RAM��д����

#define SSD1289_CMD_X_POS
#define SSD1289_CMD_Y_POS

#define SSD1289_CMD_WINDOW_H_START_END	0x44  	//X�����
#define SSD1289_CMD_WINDOW_V_START  0x45		//Y��ʼ
#define SSD1289_CMD_WINDOW_V_END    0x46    	//Yĩβ

#define LCD_SSD1289_turn_on_back_light()	GPIO_send_pin(GPIO_A, 1, 1)
#define LCD_SSD1289_turn_off_back_light()	GPIO_send_pin(GPIO_A, 1, 0)

//״̬���岿��
SSD1289_INITIAL_STRUCT ScreenState = 
{
	ORITATION_240_320, 
	COLOR_262K,
	0x00,
	1,
	0	//δ��ʼ��
};


//***************************************LCD_SSD1289��ʼ������*********************************//
//���ų�ʼ��
void SSD1289_pins_init()
{
	RCC_enable_FSMC_clock();	//��FSMCģ���ṩʱ��
	
//��GPIO�ṩʱ�� 
	RCC_enable_GPIO_B_clock();
	RCC_enable_GPIO_D_clock();
	RCC_enable_GPIO_E_clock();
	RCC_enable_GPIO_G_clock();
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_G_clock();
	RCC_enable_GPIO_F_clock();
	
//������ģ���ṩʱ��
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

//Back Light ��������
	GPIO_set_output_50MHZ_PP(GPIO_A, 1);			
}




/*
SD1289��ʹ�õ�FSMC����
	��FSMC����
	FSMC������ⲿ�洢������ͨ��
	�ṩ�˶Բ�ͬ�ӿ����ķ���ʱ����źŴ���
	
	�ú���ʹ�õ���FSMCģ����NOR/PSRAMģ���BAND4
	���ڲ�ͬ��BandֻӰ���ַ�����2λ ��ѡ��Band��
	�����ڴ�ѡ��Band4��ѡ��Band1����ͬ��Ч��
	
	F103�ڲ��Բ�ͬ��Band�ж����Ŀ��ƼĴ���
	���ڴ�ʹ�õ�Band4�ļĴ�������������ź�
	
	�ú���ʹ��SRAM������ʱ����źŴ���
	��SSD1289�ķ��ʲ���Ҫ��ַ��
	SSD1289���ڲ�IR�Ĵ���ָʾ����һ����Ҫ���ʵ�GRAM��GDDRAM��ַ
	��RS���ſ���IR�Ĵ����ͣǣң��ͷ���
	RS���Ž�FSMCģ��A0����
	���Ը�FSMCʹ�ò�ͬ��A0��ַ��������ͬ��RS�ź�
	�����ⲿΪ16λ�洢�����ʣ��ڲ�AHB���ߵ�A1�߽��ӵ�FSMC��A0��
	�����ڲ����������õĵ�ַ�ĵ�1λ����RS
	
	�˺�����FSMC����Ϊ��дͬʱ���ģʽ������չģʽ��
	SSD1289��ʱ��û��Ҫ��
	ֻ����Ƭѡʱ���ݽ���
	
	�����ŵ����òμ�:LCD_SSD1289_pins_init
*/
	
void SSD1289_FSMC_init()
{
	//ʱ������
	FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK();	//��ַ����ʱ��Ϊ2��HCLK(������RS��������������֮����ӳ�)
	//FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK();		//��ַ����ʱ��Ϊ2��HCLK(����)
	FSMC_NORPSRAM4_set_data_setup_phase_duration(3);			//���ݵĽ���ʱ��
	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK();				//���ߵĻָ�ʱ��Ϊ1��HCLK
	//FSMC_NORPSRAM4_div_HCLK_with_2();  							//CLK�ķ�Ƶ(����)
	//FSMC_NORPSRAM4_latency_is_2_CLK();							//��һ�η�����Ҫ�ȴ���ʱ�䣨���ã�
	FSMC_NORPSRAM4_access_mode_A();								//����ģʽΪAģʽ
	/*
		��ע:����LCD��˵����ν�ĸ�ģʽ�ˣ�
		��ΪLCDֻ��ʹ����FSMC�е� DB[0-15]��RC��RS,NOE ��NWE,��ַ�����һλ��ѡ��RS������0λ(��AHB�������ǵ�1λ)Ϊ
		1ʱ�Ƿ���GDDRAM�����ݣ������Ƿ���IR�Ĵ��������ݣ�Ҳ��������/����ѡ��
		�����������й����У�û���ϸ��ʱ�򣬱Ͼ�LCD���������������ϵĴ洢����
		û��ʱ��֮˵��
	*/
	//��������
	FSMC_NORPSRAM4_disable_multiplexed();						//��ֹ��ַ�ߺ������߸���
	FSMC_NORPSRAM4_memory_type_is_SRAM();						//ѡ��洢������ΪSRAM
	FSMC_NORPSRAM4_data_width_is_16();							//�洢�������ߵĿ��Ϊ16λ
	FSMC_NORPSRAM4_disable_burst_access();						//��ֹ����ģʽ����
	FSMC_NORPSRAM4_NWAIT_active_low();							//�ȴ��ź�Ϊ����Ч
	FSMC_NORPSRAM4_disable_split();								//��ֹ�Ƕ���ĵ�ַ����
	FSMC_NORPSRAM4_NWAIT_inserted_before_wait_state();			//�ȴ��ź��ڵȴ�״̬֮ǰ����
	FSMC_NORPSRAM4_enable_write_operation();					//д����ʹ��
	FSMC_NORPSRAM4_disable_wait_signal();						//���Ƶȴ��ź�
	FSMC_NORPSRAM4_disable_extended_mode();						//��ֹ��չģʽ(дʱ��Ͷ�ʱ����ͬ)
	
	//ʹ��FSMCģ��
	FSMC_NORPSRAM4_enable_bank();								//ʹ��ģ��
}


/*
SSD1289�ڲ���ʼ�� 
	��SSD1289���ղ���ָ���ķ�ʽ��ʼ��
	��LCD_SSD1289_init����ϸ˵��
*/
void SSD1289_internal_init(SSD1289_INITIAL_STRUCT state)
{
	
	SSD1289_send_data(0x0000,0x0001);		//�򿪾���
	SSD1289_send_data(0x0003,0xA8A4);		//��Դ��������1
	SSD1289_send_data(0x000C,0x0000);     	//��Դ��������2 
	SSD1289_send_data(0x000D,0x080C);     	//��Դ��������3 
	SSD1289_send_data(0x000E,0x2B00);       //��Դ��������4 
	SSD1289_send_data(0x001E,0x00B0);     	//��Դ��������5
	
	
	//�����������240*320 0x2B3F 320*240 0x293F 
	/*
		ԭ��:TBλ��������G0 - G319 or G319 - G0 ��TBΪ1ʱΪ���ߣ���Ҳ��0x2B3F��293F�Ĳ�֮ͬ����
			 RLλ��������S0 - S719 or S719 - S0	��������û�����ϡ�
	*/	
	SSD1289_send_data(0x0001,(state.oritation == ORITATION_240_320)?0x2B3F:0x293F);		//���ݷ������д������  	
	
	SSD1289_send_data(0x0002,0x0600);     	//LCD Driving Waveform control
	SSD1289_send_data(0x0010,0x0000);       //LCD ˯��ģʽ����(�ر�)
	
	/*
		�����������趨��ʾ����ɫ�͵�ַ�ĸ��·���
		������Ϊ240*320����ʱ: ��ַ�������Ĵ����Ͻǵ����½�
		������Ϊ320*240����ʱ������Gate��ת(Ϊ�����㣨0,0����Ϊ��ʱ��Ļ��������Ͻ�)
			��ʱ�ĵ�ַ���·�ʽҲ�Ǹ÷�������Ͻǵ����½ǣ����������ת��Gate�Ļ�����
			Ч���ᶪʧ��
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
	SSD1289_send_data(0x000F,0x0000);	//ɨ�迪ʼ��ַ
	SSD1289_send_data(0x0041,0x0000);     
	SSD1289_send_data(0x0042,0x0000);     
	SSD1289_send_data(0x0048,0x0000);     
	SSD1289_send_data(0x0049,0x013F);     
	SSD1289_send_data(0x004A,0x0000);     
	SSD1289_send_data(0x004B,0x0000);     
	SSD1289_send_data(0x0044,0xEF00);  	//ˮƽĩβ + ˮƽ��ʼ   
	SSD1289_send_data(0x0045,0x0000);  	//��ֱ��ʼ
	SSD1289_send_data(0x0046,0x013F);  	//��ֱĩβ     
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
SSD1289��ʼ�� 
	���ݲ����������ֵ��ʼ��LCD
	�ɿ��Ƶĳ�ʼ��������
		LCD����ɫ
		LCD��ʾ����:
			ORITATION_240_320
			ORITATION_320_240
		LCD��ɫ����:
			COLOR_262K
			COLOR_65K
*/
void SSD1289_init(SSD1289_INITIAL_STRUCT initialState)
{
	//ScreenState = initialState;
	FontFormat.backColor = initialState.backgroundColor;
	FontFormat.color = ~(FontFormat.backColor);
	SSD1289_pins_init();										//��ʼ������
	initialState.backLight ? LCD_SSD1289_turn_on_back_light() : LCD_SSD1289_turn_off_back_light();
	SSD1289_FSMC_init(); 	  									//��ʼ��FSMCģ��
	SSD1289_internal_init(initialState);  						//LCD�ڲ���ʼ��
	
	SSD1289_clear_screen(ScreenState.backgroundColor);			//����	
	
	ScreenState.isInit = 1;
	
}


//***************************************LCD_SSD1289�ڲ���������*********************************//
//��SSD1289��������
//regIndex = 0x00 - 0xFF
//regValue = 16λ
static void SSD1289_send_data(U16 regIndex, U16 regValue)
{
	REG_INDEX = regIndex;
	REG_VALUE = regValue;
}

//��SSD1289����RAM�е�����
static U32 SSD1289_get_data(U16 regIndex)
{
	REG_INDEX = regIndex;
	return REG_VALUE; 
}


/*
������һ����ɫ��Ҫȥ�ĵ�ַ
	��λ������Ч������Ļ�����й�
	��Ļ�����TBλ�й�
	TBλ����G0 - G319 
	Ҳ�������õ�X��Y�������ĵ�ַ����Ӧ��Gate����Ļ�����й�

	��������240 * 320�����
	��������320 * 240�����
	��������ͬ��Gate��ַ
*/
void SSD1289_set_GDDRAM_position(U16 x, U16 y)
{
	if(ScreenState.oritation == ORITATION_240_320)  //�����240*320ģʽ
	{
		if(x > 240 || y > 320 )
		return;
		SSD1289_send_data(0x004e, x);	//����x����
		SSD1289_send_data(0x004f, y);   //����y����
	}
	else											//�����320*240ģʽ
	{
		if(x > 320 || y > 240)
		return;
	
		SSD1289_send_data(0x004e, y);
		SSD1289_send_data(0x004f, x);
	}
}


//***************************************LCD_SSD1289��ͼ����*********************************//
/*
��AC��ָGDDRAM��������ɫ
	����COLOR_262Kģʽ��
	����COLOR_65Kģʽ��
	262K��ɫ��Ҫ18λ:R,G,B��6λ
	65K��ɫ��Ҫ16λ:R5 G6 B5 
*/
void SSD1289_set_point(U32 RGB_color)
{
	if(ScreenState.color == COLOR_65K)   //�����65k����ֻ�跢��һ������   (1.RGB (5.6.5))
	{
		SSD1289_send_data(0x22, RGB_color);
		//Debug:
		//USART1_printf("color == 0X%X\n", RGB_color);
	}	
	else                                       //�����262K��ɫ����Ҫ�����������İ���(1.RG 2.0x0B)
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
���AC��ָGDDRAM������ɫ
	����COLOR_262Kģʽ��
	����COLOR_65Kģʽ��
*/
U32 SSD1289_get_point()
{
	if(ScreenState.color == COLOR_65K)   //�����65k����ֻ�跢��һ������   (1.RGB (5.6.5))
	{
		return SSD1289_get_data(0x22);
		//Debug:
		//USART1_printf("color == 0X%X\n", RGB_color);
	}	
	else                                       //�����262K��ɫ����Ҫ�����������İ���(1.RG 2.0x0B)
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
	����LCD
	֧����262K��ɫ����(��262Kģʽ��)
	֧����65K��ɫ����(��65Kģʽ��)
*/
void SSD1289_clear_screen(U32 color)
{
	U32 index = 0;
	SSD1289_set_GDDRAM_position(0, 0);
	for(index = 0;index < 172800; index++)
		SSD1289_set_point(color);
}

/*
������ʾ����
	�������˸ú�������һ�����õĵ㽫�Ӹô��ڵ����Ͻǿ�ʼ����
	֮��ĵ���Ʋ���Ҫ�������õ�λ��
	������������Զ����������õĴ��ڴӴ��ڵ����ϽǺ�����������½�
	ÿ����һ���㣬����һ��
	����ͨ������LCD_SSD1289_set_full_window��Ĩ���ô��ڣ�ʹ������ʾΪȫ��(���忴LCD_SSD1289_set_full_window˵��)
*/
void SSD1289_set_window(U16 hStart, U16 vStart, U16 hEnd, U16 vEnd)
{
	U16 newhStart = hStart;
	U16 newvStart = vStart;
	U16 newhEnd = hEnd;
	U16 newvEnd = vEnd;
	U16 h_temp;
	/*
		�����320 * 240�ķ���Gate�Ǵӣ�G319 - G0��ģ���Ҳ���ǵ�
		��GRAM��������(0 , 0)ʱ�� ��ʱ��G319��S0, ������windowʱҲһ����
		window����ʼ��ĩβҲ�Ǵ�G319��G0�����.
	*/
	if(ScreenState.oritation == ORITATION_320_240)   
	{
		newhStart = vStart;
		newvStart = hStart;
		newhEnd = vEnd;
		newvEnd = hEnd;
	}
	
	h_temp = (newhStart&0xFF) | ((newhEnd&0xFF) << 8);
	SSD1289_send_data(0x44, h_temp);				//����window����Χ
	SSD1289_send_data(0x45, newvStart&0x1FF);	
	SSD1289_send_data(0x46, newvEnd&0x1FF);

	SSD1289_set_GDDRAM_position(hStart, vStart);	//����ACΪ���ڵ����Ͻ�λ��(�����320*240��240*320)	
	//Debug:
	//USART1_printf("x Start = %d y Start = %d\n", newhStart, newvStart );
}


/*
�ָ�ȫ������
	�ָ���Ĵ��ڽ�Ϊȫ��
	���һ��Ƶĵ�һ�㽫�ڴ��ڵ����Ͻ�λ��
*/
void SSD1289_set_full_window()
{
	ScreenState.oritation == ORITATION_240_320 ? SSD1289_set_window(0, 0, 239, 319) : SSD1289_set_window(0, 0, 319, 239);
	SSD1289_set_GDDRAM_position(0 , 0);
}


/*
	��������:���ݲ�������Ļ�ϻ���һ��262K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void SSD1289_draw_bitmap_262K(U16 bitMapWidth, U16 bitMapHigh, U16 xStart, U16 yStart, const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                   //�����������
	U32 color_temp;
	                                  
	SSD1289_set_window(xStart, yStart, bitMapWidth - 1, bitMapHigh - 1); //���ô���
	while(index--)
	{
		color_temp = RGB_262K((*pPic), *(pPic + 1), (*pPic + 2));
		pPic += 3;
		SSD1289_set_point(color_temp);
	}
	SSD1289_set_full_window();               
}


/*
	��������:���ݲ�������Ļ�ϻ���һ��65K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void SSD1289_draw_bitmap_65K(	U16 bitMapWidth, 
									U16 bitMapHigh, 
									U16 xStart, 
									U16 yStart, 
									const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                    //�����������
	U32 color_temp;
	
	SSD1289_set_window(xStart, yStart, bitMapWidth - 1, bitMapHigh - 1); //���ô���
	
	while(index--)
	{
		color_temp = *pPic;
		color_temp = (color_temp << 8) | *(pPic + 1);
		pPic += 2;
		SSD1289_set_point(color_temp);
	}
	SSD1289_set_full_window();
}


//*************************************������ʾ����*****************************************//
/*
	������������ʾ8*16�ĵȿ�����
*/
void SSD1289_draw_font_8_16(
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 fontHigh = 8;
	U32 bitOp = 0x1 << 7;
	
	SSD1289_set_window(xStart, yStart, xStart + 7, yStart + 15);	//�������ִ���
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
	��ʾ�������Ҷ��뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void SSD1289_draw_font_right_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 bitOp = 0x1 << 7;
	U32 byteNumPerLine = (fontWidth%8) ? (fontWidth/8 + 1) : (fontWidth/8);		//ÿһ����Ҫ�����ֽ�
		
	SSD1289_set_window(xStart, yStart, xStart + fontWidth - 1, yStart + fontHigh - 1);	//�������ִ���
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //λ����
		U32 temp ;
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if(index_temp == 1)		                        //ÿһ�еĿ�ʼ��ȡһ������
			{
				font_temp = *pFont++;
				temp = 8*byteNumPerLine - fontWidth;	//temp��ʾ����λ�ĸ���
				font_temp  <<= temp;
				bitCounter -= temp;							//bitCounter��������λ�ĸ���
			}	
			if(bitCounter == 0)		//���һ���ֽ���ʾ���ˣ�����һ���ֽ�
			{
				bitCounter = 8;
				font_temp =  *pFont++;
			}	
			SSD1289_set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
			bitCounter -- ;				//��ʾһ��λ����
			
		}		
	}
	SSD1289_set_full_window();
}


/*
	��ʾ����������뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void SSD1289_draw_font_left_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	U32 index_temp;
	U32 font_temp;
	U32 bitOp = 0x1 << 7;	
	SSD1289_set_window(xStart, yStart, xStart + fontWidth - 1, yStart + fontHigh - 1);	//�������ִ���
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //λ����
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if((index_temp == 1) || (bitCounter == 0) || ((index_temp < fontWidth) && (index_temp%fontWidth == 0)))	                        //ÿһ�еĿ�ʼ��ȡһ������
			{
				font_temp = *pFont++;
				bitCounter = 8;
			}	
			SSD1289_set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
			bitCounter -- ;			//��ʾһ��λ����
		}		
	}
	SSD1289_set_full_window();
}



//*****************************************************************************************//
//***********************************����ĺ�����Ҫ��������LCD�Ĺ���***********************//
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
	//LCD_big_to_small();      //��������...
//	LCD_SSD1289_draw_font_left_align(24, 31, 10, 10, RGB_RED, BACKGROUND_COLOR, char_24x31);
//	LCD_SSD1289_draw_font_left_align(15, 31, 100, 10, RGB_RED, BACKGROUND_COLOR, char_12x31);
//	LCD_SSD1289_draw_font_left_align(10, 19, 50, 50, RGB_GREEN, BACKGROUND_COLOR, ansi_font10x19['S'- 0x20]);
}

//�˺�����������
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


//���Խ�����Ŵ���ʾ�ķ�ʽ
//�˺�����������
void _LCD_SSD1289_draw_font(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
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
				for(mulX_temp = 1; mulX_temp < mulX; mulX_temp ++)		//X�Ŵ���ٱ���ÿһ�����������ٴ�
					SSD1289_set_point((font_temp&bitOp)?color:backColor);
				
				font_temp <<= 1;
			}
		}
	}
	SSD1289_set_full_window();
}

//�˺�����������
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


















