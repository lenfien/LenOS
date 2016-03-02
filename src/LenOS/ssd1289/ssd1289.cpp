#define __CPlusPlus

#include "base.h"
#include "ssd1289.h"
#include "font.h"
#include "color.h"
#include "out.h"
#include "datas.h"
#include "touch.h"
/*
	��̬���ݳ�Ա��ʼ��
*/
SSD1289::InitialStruct SSD1289::state = 
{
		ORITATION_320_240,
		Color::COLOR_262K,
		0,
		1
};

bool SSD1289::isInitialized = false;


//���ų�ʼ��
void SSD1289::pins_init()
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
	
void SSD1289::FSMC_init()
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
		��ΪLCDֻ��ʹ����FSMC�е� DB[0-15]��RC��RS,NOE ��NWE,��ַ�����һλ��ѡ��RS��
		����0λ(��AHB�������ǵ�1λ)Ϊ
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
void SSD1289::internal_init(SSD1289::InitialStruct state)
{
	send_data(0x0000,0x0001);		//�򿪾���
	send_data(0x0003,0xA8A4);		//��Դ��������1
	send_data(0x000C,0x0000);     	//��Դ��������2 
	send_data(0x000D,0x080C);     	//��Դ��������3 
	send_data(0x000E,0x2B00);       //��Դ��������4 
	send_data(0x001E,0x00B0);     	//��Դ��������5
	
	//�����������240*320 0x2B3F 320*240 0x293F 
	/*
		ԭ��:TBλ��������G0 - G319 or G319 - G0 ��TBΪ1ʱΪ���ߣ���Ҳ��0x2B3F��293F�Ĳ�֮ͬ����
			 RLλ��������S0 - S719 or S719 - S0	��������û�����ϡ�
	*/	
	send_data(0x0001,(state.oritation == ORITATION_240_320)?0x2B3F:0x293F);		//���ݷ������д������  	
	
	send_data(0x0002,0x0600);     	//LCD Driving Waveform control
	send_data(0x0010,0x0000);       //LCD ˯��ģʽ����(�ر�)
	
	/*
		�����������趨��ʾ����ɫ�͵�ַ�ĸ��·���
		������Ϊ240*320����ʱ: ��ַ�������Ĵ����Ͻǵ����½�
		������Ϊ320*240����ʱ������Gate��ת(Ϊ�����㣨0,0����Ϊ��ʱ��Ļ��������Ͻ�)
			��ʱ�ĵ�ַ���·�ʽҲ�Ǹ÷�������Ͻǵ����½ǣ����������ת��Gate�Ļ�����
			Ч���ᶪʧ��
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
	send_data(0x000F,0x0000);	//ɨ�迪ʼ��ַ
	send_data(0x0041,0x0000);     
	send_data(0x0042,0x0000);     
	send_data(0x0048,0x0000);     
	send_data(0x0049,0x013F);     
	send_data(0x004A,0x0000);     
	send_data(0x004B,0x0000);     
	send_data(0x0044,0xEF00);  	//ˮƽĩβ + ˮƽ��ʼ   
	send_data(0x0045,0x0000);  	//��ֱ��ʼ
	send_data(0x0046,0x013F);  	//��ֱĩβ     
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
void SSD1289::init(SSD1289::InitialStruct initialState)
{ 
	state = initialState;
	pins_init();														//��ʼ������
	initialState.backLight ? turn_on_back_light() : turn_off_back_light();
	FSMC_init(); 	  												//��ʼ��FSMCģ��
	internal_init(initialState);  					//LCD�ڲ���ʼ��	
	SSD1289::isInitialized = true;			
}




//���x,y�㴦����ɫ
Color::ColorValue SSD1289::get_point_262K(U16 x, U16 y)
{
	if(x > width() || y > high())
		return 0;
	
	REG_INDEX = 0x22;
	
	set_GDDRAM_position(x, y);
	
	REG_INDEX = 0x22;
	
	U16 color1 = REG_VALUE;	//�ٶ�
	
	color1 = REG_VALUE;	//��һ�ζ���16λ
	
	U16 color2 = REG_VALUE;
	
	U16 b = (color1&0xFC00)>> 10;
	U16 g = (color1&0xFC) >> 2;
	U16 r = (color2&0xFC00)>>10;
	
	return Color::RGB262K(r, g, b) ;
}



//���x,y�㴦����ɫ
U32 SSD1289::get_point_65K(U16 x, U16 y)
{
	if(x > width() || y > high())
		return 0;
	
	REG_INDEX = 0x22;
	
	set_GDDRAM_position(x, y);
	
	REG_INDEX = 0x22;
	
	U16 color1 = REG_VALUE;	//�ٶ�
	
	color1 = REG_VALUE;	//��һ�ζ���16λ
	
	return color1;
}






//���һ������ĵ����ɫ����. ����ŵ�dis��ָ��Ŀ��ռ�, ���ص�����
U32 SSD1289::get_points_262K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, unsigned char *dis)
{
	ADS7843::sleep();
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//�ٶ�
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




//���һ������ĵ����ɫ����. ����ŵ�dis��ָ��Ŀ��ռ�, ���ص�����
U32 SSD1289::get_points_262K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, Datas<Color::ColorType>& dis)
{
	ADS7843::sleep();
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//�ٶ�
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






//���һ������ĵ����ɫ����. ����ŵ�dis��ָ��Ŀ��ռ�, ���ص�����
U32 SSD1289::get_points_65K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, unsigned char *dis)
{
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//�ٶ�
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




//���һ������ĵ����ɫ����. ����ŵ�dis��ָ��Ŀ��ռ�, ���ص�����
U32 SSD1289::get_points_65K(U16 xStart, U16 yStart, U16 xLen, U16 yLen, Datas<Color::ColorType>& dis)
{
	int max = xLen * yLen;
	set_window(xStart, yStart, xLen, yLen);
	
	REG_INDEX = 0x22;
	U16 color1 = REG_VALUE;	//�ٶ�
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
	����LCD
	֧����262K��ɫ����(��262Kģʽ��)
	֧����65K��ɫ����(��65Kģʽ��)
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
	����LCD
	֧����262K��ɫ����(��262Kģʽ��)
	֧����65K��ɫ����(��65Kģʽ��)
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
������ʾ����
	�������˸ú�������һ�����õĵ㽫�Ӹô��ڵ����Ͻǿ�ʼ����
	֮��ĵ���Ʋ���Ҫ�������õ�λ��
	������������Զ����������õĴ��ڴӴ��ڵ����ϽǺ�����������½�
	ÿ����һ���㣬����һ��
	����ͨ������LCD_SSD1289_set_full_window��Ĩ���ô��ڣ�ʹ������ʾΪȫ��(���忴LCD_SSD1289_set_full_window˵��)
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
		�����320 * 240�ķ���Gate�Ǵӣ�G319 - G0��ģ���Ҳ���ǵ�
		��GRAM��������(0 , 0)ʱ�� ��ʱ��G319��S0, ������windowʱҲһ����
		window����ʼ��ĩβҲ�Ǵ�G319��G0�����.
	*/
	if(state.oritation == ORITATION_320_240)   
	{
		newhStart = vStart;
		newvStart = hStart;
		newhEnd = vLen;
		newvEnd = hLen;
	}
	
	h_temp = (newhStart&0xFF) | ((newhEnd&0xFF) << 8);
	send_data(0x44, h_temp);				//����window����Χ
	send_data(0x45, newvStart&0x1FF);	
	send_data(0x46, newvEnd&0x1FF);
	
	ADS7843::sleep();
	set_GDDRAM_position(hStart, vStart);	//����ACΪ���ڵ����Ͻ�λ��(�����320*240��240*320)	
}



/*
�ָ�ȫ������
	�ָ���Ĵ��ڽ�Ϊȫ��
	���һ��Ƶĵ�һ�㽫�ڴ��ڵ����Ͻ�λ��
*/
void SSD1289::set_full_window()
{
	state.oritation == ORITATION_240_320 ? set_window(0, 0, 239, 319) : set_window(0, 0, 319, 239);
	set_GDDRAM_position(0 , 0);
	ADS7843::awake();
}





