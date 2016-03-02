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

#define HORIZEN_RANGE 	SCREEN_SIZE_X			//水平占屏幕的份数(共10份)
#define VERTICAL_RANGE  (SCREEN_SIZE_Y-50)      //垂直占屏幕的份数(共10份)

#define ADC_UI_X		
#define ADC_UI_Y
#define ADC_RANGE	4095	    //AD的最大值

#define ADC_VOLTAGE_MAX 3.3
#define ADC_VOLTAGE_MIN 0.0


#define ADC_COLOR			//如果想让ADConverter变得五颜六色就不要注释这一行

#ifdef  ADC_COLOR
	#define ADC_BACKCOLOR	RGB_BLACK				//转换区域的背景色
	#define ADC_REFCOLOR	RGB(0x9, 0x0, 0)		//参考线颜色
	#define ADC_CURVECOLOR 	RGB(0x1F, 0x0, 0x0)		//曲线颜色
	#define ADC_BUTTONCOLOR	RGB(0x1A, 0x20, 0)		//按键颜色
	#define ADC_TEXTCOLOR	RGB(0x27, 0x2C, 0x26)	//文字颜色
	#define ADC_LINECOLOR	RGB(0x1A, 0x20, 0)		//分界线颜色
#else
	#define ADC_BACKCOLOR	RGB_BLACK	//转换区域的背景色
	#define ADC_REFCOLOR	RGB_WHITE	//参考线颜色
	#define ADC_CURVECOLOR 	RGB_WHITE	//曲线颜色
	#define ADC_BUTTONCOLOR	RGB_WHITE		//按键颜色
	#define ADC_TEXTCOLOR	RGB_WHITE	//文字颜色
	#define ADC_LINECOLOR	RGB_WHITE	//分界线颜色
#endif


#define ADC_SAMPLE_MAX  600
#define ADC_SAMPLE_MIN	30

#define ADC_STARTPOS_X 	28
#define ADC_ENDPOS_X	(SCREEN_SIZE_X - 23)

#define ADC_SAMPLETIME_COUNTER_MAX 1000
#define ADC_SAMPLETIME_COUNTER_MIN 10

#define ADC_SAMPLE_MUL	10

U32 ADC_SAMPLETIME = 100;	//us ADC的采样频率

//初始化ADConverter
void ADConverter_init()
{
	NVIC_set_PRIx(_EXTI9_5_IRQn, 0x40);			//配置中断优先级(触屏为最低)
	NVIC_set_PRIx(_TIM1_UP_IRQn, 0x20);			//计数器成为次级优先级
	NVIC_set_PRIx(_DMA1_Channel1_IRQn, 0x00);	//DMA为最高优先级
	
	ADConverter_draw_UI();
	
	DMA1_CH1_init();		//ADC1通道10初始化
	ADC1_IN10_init();

	TIM1_init_us(1, ADC_SAMPLETIME);			//将TIM1配置为ADC_SAMPLETIME计数一次，并在每1次产生一次中断
}

void BUTTON_BtnAdd_hold_handler(POINT* p, BUTTON* pBtn);
void BUTTON_BtnSub_hold_handler(POINT* p, BUTTON* pBtn);

//绘制UI
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


U16 ADC_VALUE[325];           //定义两个ADC的存储区是为了在显示本次结果时同时能清除上一次的结果
U16 _ADC_VALUE[325];          //

U16   *PCurADV = ADC_VALUE;		//指向当前
U16   *PPreADV = _ADC_VALUE;  	//指向之前

int ADConverter_record_ADValue(U32 ADValue)
{
	static int curPos = 0;
	static int ADy;
	
	//转换AD值为纵坐标
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

//获得平均电压
float ADConverter_get_voltage()
{
	int index = 0;
	int sum = 0;

	for(index = 0; index < HORIZEN_RANGE; index ++)
		sum += ADConverter_AD2COR(PCurADV[index]);
	sum /= (HORIZEN_RANGE/1);
	
	return (1 - (float)sum/VERTICAL_RANGE) * ADC_VOLTAGE_MAX;
}

//获得周期us
int  ADConverter_get_cycle()
{
	int index = 10;
	int fre = 0;
	U16 curADV = PCurADV[index];
	U16 nextADV = PCurADV[index + 1];
	
	if(curADV > nextADV)									//如果第一个沿处于下降沿,则等待这个下降沿结束
	{
		for(;index < HORIZEN_RANGE; index += 1)
			if(PCurADV[index] <= PCurADV[index + 1])
				break;
			
		for(;index < HORIZEN_RANGE; index += 1)	//开始计数上升沿
		{
			if(PCurADV[index] > PCurADV[index + 1]) 			//如果当前的大于等于下一个，则表示下降沿出现
				break;
			fre ++;
		}
		return fre*ADC_SAMPLETIME;
	}
	else if(curADV < nextADV)								//如果第一个沿处于上升沿，则等待这个上升沿结合
	{
		
		for(;index < HORIZEN_RANGE; index += 1)
			if(PCurADV[index] >= PCurADV[index + 1])
				break;
			
		for(;index < HORIZEN_RANGE; index += 1)	//开始计数下降沿
		{
			if(PCurADV[index] <= PCurADV[index + 1]) 			//如果当前的小于等于下一个，则表示上升沿降沿出现
				break;
			fre ++;
		}
		return fre*ADC_SAMPLETIME;
	}
	else
	{
		//方波可能出现在这里
	}
	return 0;
}

U16 ADConverter_AD2COR(U16 adV)
{
	return VERTICAL_RANGE - ((float)adV/ADC_RANGE) * ((float)VERTICAL_RANGE);
}


//更新UI
void ADConverter_update_UI()
{
	int x;
	U16* temp;
	U32 oldColor;
	
	for(x = ADC_STARTPOS_X; x <= ADC_ENDPOS_X ; x += 1)	
	{
		LCD_draw_line(x, ADConverter_AD2COR(PPreADV[x]), x + 1, ADConverter_AD2COR(PPreADV[x + 1]), ADC_BACKCOLOR); //清除上一轮显示的东西
		LCD_draw_line(x, ADConverter_AD2COR(PCurADV[x]), x + 1, ADConverter_AD2COR(PCurADV[x + 1]), ADC_CURVECOLOR);        //显示这一轮显示的东西
	}

	LCD_draw_line(ADC_STARTPOS_X, VERTICAL_RANGE/2, ADC_ENDPOS_X, VERTICAL_RANGE/2, ADC_REFCOLOR);
	
	//获得平均电压
	oldColor = LCD_set_font_color(ADC_TEXTCOLOR);
	LCD_printf(50, VERTICAL_RANGE + 2, "%.2fV",   ADConverter_get_voltage());
	LCD_set_font_color(oldColor);
	
	LENFIEN_logo_animation();

	//交换上一轮和这一轮的指针
	temp = PCurADV;
	PCurADV = PPreADV;
	PPreADV = temp;
}


//按钮事件
//Click事件
//采样周期增加事件发生时调用该函数
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


//按钮事件
//Click事件
//采样周期减少事件发生时调用该函数
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




