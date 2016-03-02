#include <stdio.h>

#include "core_NVIC.h"
#include "base_atime.h"
#include "cnf_adc.h"
#include "cnf_atime.h"
#include "cnf_dma.h"

#include "com.h"

#include "SSD1289.h"

#include "ads7483_base.h"
#include "adconverter.h"
#include "daconverter.h"
#include "lenfien.h"
#include "button.h"

#define HORIZEN_RANGE 	SCREEN_SIZE_X			//ˮƽռ��Ļ�ķ���(��10��)
#define VERTICAL_RANGE  (SCREEN_SIZE_Y-50)      //��ֱռ��Ļ�ķ���(��10��)

#define ADC_UI_X		
#define ADC_UI_Y
#define ADC_RANGE	4095	    //AD�����ֵ

#define ADC_VOLTAGE_MAX 3.3
#define ADC_VOLTAGE_MIN 0.0


#define ADC_COLOR			//�������ADConverter���������ɫ�Ͳ�Ҫע����һ��

#ifdef  ADC_COLOR
	#define ADC_BACKCOLOR	RGB_BLACK				//ת������ı���ɫ
	#define ADC_REFCOLOR	RGB(0x9, 0x0, 0)		//�ο�����ɫ
	#define ADC_CURVECOLOR 	RGB(0x1F, 0x0, 0x0)		//������ɫ
	#define ADC_BUTTONCOLOR	RGB(0x1A, 0x20, 0)		//������ɫ
	#define ADC_TEXTCOLOR	RGB(0x27, 0x2C, 0x26)	//������ɫ
	#define ADC_LINECOLOR	RGB(0x1A, 0x20, 0)		//�ֽ�����ɫ
#else
	#define ADC_BACKCOLOR	RGB_BLACK	//ת������ı���ɫ
	#define ADC_REFCOLOR	RGB_WHITE	//�ο�����ɫ
	#define ADC_CURVECOLOR 	RGB_WHITE	//������ɫ
	#define ADC_BUTTONCOLOR	RGB_WHITE		//������ɫ
	#define ADC_TEXTCOLOR	RGB_WHITE	//������ɫ
	#define ADC_LINECOLOR	RGB_WHITE	//�ֽ�����ɫ
#endif


#define ADC_SAMPLE_MAX  600
#define ADC_SAMPLE_MIN	30

#define ADC_STARTPOS_X 	28
#define ADC_ENDPOS_X	(SCREEN_SIZE_X - 23)

#define ADC_SAMPLETIME_COUNTER_MAX 1000
#define ADC_SAMPLETIME_COUNTER_MIN 10

#define ADC_SAMPLE_MUL	10

U32 ADC_SAMPLETIME = 100;	//us ADC�Ĳ���Ƶ��

//��ʼ��ADConverter
void ADConverter_init()
{
	NVIC_set_PRIx(_EXTI9_5_IRQn, 0x40);			//�����ж����ȼ�(����Ϊ���)
	NVIC_set_PRIx(_TIM1_UP_IRQn, 0x20);			//��������Ϊ�μ����ȼ�
	NVIC_set_PRIx(_DMA1_Channel1_IRQn, 0x00);	//DMAΪ������ȼ�
	
	ADConverter_draw_UI();
	
	DMA1_CH1_init();		//ADC1ͨ��10��ʼ��
	ADC1_IN10_init();

	TIM1_init_us(1, ADC_SAMPLETIME);			//��TIM1����ΪADC_SAMPLETIME����һ�Σ�����ÿ1�β���һ���ж�
}

void BUTTON_BtnAdd_hold_handler(POINT* p, BUTTON* pBtn);
void BUTTON_BtnSub_hold_handler(POINT* p, BUTTON* pBtn);

//����UI
void ADConverter_draw_UI()
{
	U32 oldColor;
	BUTTON* pBtnAdd = BUTTON_create_button(1, 40, ADC_BUTTONCOLOR, "AddSR", RGB_BLACK, 0, BUTTON_BtnAdd_hold_handler, 0);
	BUTTON* pBtnSub = BUTTON_create_button(1, 40, ADC_BUTTONCOLOR, "SubSR", RGB_BLACK, 0, BUTTON_BtnSub_hold_handler, 0);
	
	LCD_clear_screen(ScreenState.backgroundColor);
	BUTTON_draw_button((HORIZEN_RANGE/3 + 22), VERTICAL_RANGE + 8, pBtnAdd);
	BUTTON_draw_button((HORIZEN_RANGE/3 + 22) + (SCREEN_SIZE_X - (HORIZEN_RANGE/3 + 22) - pBtnAdd->buttonWidth), VERTICAL_RANGE + 8, pBtnSub);
	
	LCD_draw_rectangle(ADC_STARTPOS_X, 0, HORIZEN_RANGE, VERTICAL_RANGE, ADC_BACKCOLOR);
	LCD_draw_line(0, VERTICAL_RANGE + 1, HORIZEN_RANGE, VERTICAL_RANGE + 1, ADC_LINECOLOR);
	LCD_draw_line(HORIZEN_RANGE/3 + 20, VERTICAL_RANGE + 1, HORIZEN_RANGE/3 + 20, SCREEN_SIZE_Y, ADC_LINECOLOR);
	LCD_draw_line(ADC_STARTPOS_X-1, 0, ADC_STARTPOS_X, VERTICAL_RANGE, ADC_LINECOLOR);
	LCD_draw_line(ADC_ENDPOS_X + 2, 0, ADC_ENDPOS_X + 2, VERTICAL_RANGE, ADC_LINECOLOR);
	LCD_draw_line(ADC_STARTPOS_X, VERTICAL_RANGE/2, ADC_ENDPOS_X + 2, VERTICAL_RANGE/2, ADC_REFCOLOR);
	
	oldColor = LCD_set_font_color(ADC_TEXTCOLOR);
	LCD_printf(0, 0, "3V");
	LCD_printf(0, VERTICAL_RANGE-15, "0V");
	LCD_printf(0, VERTICAL_RANGE + 2 ,   "AveV:");
	
	LCD_printf(0, VERTICAL_RANGE + 32, "SamR:");
	
	LCD_printf(50, VERTICAL_RANGE + 32, "%-3dus\t", ADC_SAMPLETIME);
	LCD_set_font_color(oldColor);
}


U16 ADC_VALUE[325];           //��������ADC�Ĵ洢����Ϊ������ʾ���ν��ʱͬʱ�������һ�εĽ��
U16 _ADC_VALUE[325];          //

U16   *PCurADV = ADC_VALUE;		//ָ��ǰ
U16   *PPreADV = _ADC_VALUE;  	//ָ��֮ǰ

int ADConverter_record_ADValue(U32 ADValue)
{
	static int curPos = 0;
	static int ADy;
	
	//ת��ADֵΪ������
    ADy = ((float)ADValue/ADC_RANGE) * ((float)VERTICAL_RANGE);
	PCurADV[curPos] = VERTICAL_RANGE - ADy;
	
	curPos += 1;
	
	if(curPos > HORIZEN_RANGE)  
	{
		curPos = 0;
		return 1;
	}
	return 0;
}

//���ƽ����ѹ
float ADConverter_get_voltage()
{
	int index = 0;
	int sum = 0;

	for(index = 0; index < HORIZEN_RANGE; index ++)
		sum += ADConverter_AD2COR(PCurADV[index]);
	sum /= (HORIZEN_RANGE/1);
	
	return (1 - (float)sum/VERTICAL_RANGE) * ADC_VOLTAGE_MAX;
}

//�������us
int  ADConverter_get_cycle()
{
	int index = 10;
	int fre = 0;
	U16 curADV = PCurADV[index];
	U16 nextADV = PCurADV[index + 1];
	
	if(curADV > nextADV)									//�����һ���ش����½���,��ȴ�����½��ؽ���
	{
		for(;index < HORIZEN_RANGE; index += 1)
			if(PCurADV[index] <= PCurADV[index + 1])
				break;
			
		for(;index < HORIZEN_RANGE; index += 1)	//��ʼ����������
		{
			if(PCurADV[index] > PCurADV[index + 1]) 			//�����ǰ�Ĵ��ڵ�����һ�������ʾ�½��س���
				break;
			fre ++;
		}
		return fre*ADC_SAMPLETIME;
	}
	else if(curADV < nextADV)								//�����һ���ش��������أ���ȴ���������ؽ��
	{
		
		for(;index < HORIZEN_RANGE; index += 1)
			if(PCurADV[index] >= PCurADV[index + 1])
				break;
			
		for(;index < HORIZEN_RANGE; index += 1)	//��ʼ�����½���
		{
			if(PCurADV[index] <= PCurADV[index + 1]) 			//�����ǰ��С�ڵ�����һ�������ʾ�����ؽ��س���
				break;
			fre ++;
		}
		return fre*ADC_SAMPLETIME;
	}
	else
	{
		//�������ܳ���������
	}
	return 0;
}

U16 ADConverter_AD2COR(U16 adV)
{
	return VERTICAL_RANGE - ((float)adV/ADC_RANGE) * ((float)VERTICAL_RANGE);
}


//����UI
void ADConverter_update_UI()
{
	int x;
	U16* temp;
	U32 oldColor;
	
	for(x = ADC_STARTPOS_X; x <= ADC_ENDPOS_X ; x += 1)	
	{
		LCD_draw_line(x, ADConverter_AD2COR(PPreADV[x]), x + 1, ADConverter_AD2COR(PPreADV[x + 1]), ADC_BACKCOLOR); //�����һ����ʾ�Ķ���
		LCD_draw_line(x, ADConverter_AD2COR(PCurADV[x]), x + 1, ADConverter_AD2COR(PCurADV[x + 1]), ADC_CURVECOLOR);        //��ʾ��һ����ʾ�Ķ���
	}

	LCD_draw_line(ADC_STARTPOS_X, VERTICAL_RANGE/2, ADC_ENDPOS_X, VERTICAL_RANGE/2, ADC_REFCOLOR);
	
	//���ƽ����ѹ
	oldColor = LCD_set_font_color(ADC_TEXTCOLOR);
	LCD_printf(50, VERTICAL_RANGE + 2, "%.2fV",   ADConverter_get_voltage());
	LCD_set_font_color(oldColor);
	
	LENFIEN_logo_animation();

	//������һ�ֺ���һ�ֵ�ָ��
	temp = PCurADV;
	PCurADV = PPreADV;
	PPreADV = temp;
}


//��ť�¼�
//Click�¼�
//�������������¼�����ʱ���øú���
void BUTTON_BtnAdd_hold_handler(POINT* p, BUTTON* pBtn)
{
	U32 oldColor;
	if(ADC_SAMPLETIME< ADC_SAMPLE_MAX)
		ADC_SAMPLETIME ++;
	
	oldColor = LCD_set_font_color(ADC_TEXTCOLOR);
	LCD_printf(50, VERTICAL_RANGE + 32, "%3dus\t", ADC_SAMPLETIME);
	TIM1_set_counter_auto_reload(ADC_SAMPLETIME);
	LCD_set_font_color(oldColor);
}


//��ť�¼�
//Click�¼�
//�������ڼ����¼�����ʱ���øú���
void BUTTON_BtnSub_hold_handler(POINT* p, BUTTON* pBtn)
{
	U32 oldColor;
	if(ADC_SAMPLETIME > ADC_SAMPLE_MIN)
		ADC_SAMPLETIME --;
	oldColor = LCD_set_font_color(ADC_TEXTCOLOR);
	LCD_printf(50, VERTICAL_RANGE + 32, "%3dus\t", ADC_SAMPLETIME);
	TIM1_set_counter_auto_reload(ADC_SAMPLETIME);
	LCD_set_font_color(oldColor);
}




