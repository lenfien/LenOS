#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "lenfien.h"

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"


#include "base.h"


#include "cnf.h"


#include "ssd1289.h"

#include "ads7483_base.h"
#include "ds18b20_base.h"

#include "font.h"
#include "button.h"
#include "window.h"

#include "adconverter.h"
#include "daConverter.h"

#include "cortex_msp.h"


S8 AckSignal = 0;  		//当MSP对第一个数据有回馈信号时，此值被置一
S8 AckSignalSure = 0;	//当MSP响应完成命令时，第二个ACK
S8 FreeState = -1;		//是否小车处于自由状态
S8 OnLineState = 0;
S8 BarrierState = -1;

extern BUTTON* btnPad;
/**************************************************************************************/
/***********************************初始化部分*****************************************/
/**************************************************************************************/
/*
	绘制控制小车的UI
	创建时间:2012年11.5，19:55
	内容:只建立了4个按钮，分别为前,后,左,右
	更新:大量更新。。。
*/
BUTTON* btnFree;
BUTTON* btnGetBarrier;
BUTTON* btnBarrierSwitch;
BUTTON* btnGetAngle;
BUTTON* btnOnOff;

#define UI_LINE_COLOR	RGB(0x7, 0x7, 0x0)

void cortexMsp_UI_init()
{
	btnBarrierSwitch = BUTTON_create_button(20, //宽
							1,  					//高
							RGB(0x7, 0, 0), 				//背景颜色
							"BarSwitch",//内容
							~RGB_RED,   		//字体颜色
							cortexMsp_btnHandler_barrierSwitch_press, 			//点击处理函数:在按钮点击一下时执行
							cortexMsp_btnHandler_barrierSwitch_hold,	//保持处理函数:在按钮保持按下时执行
							cortexMsp_btnHandler_barrierSwitch_release
							);
	
	btnGetAngle = BUTTON_create_button(20, //宽
							1,  					//高
							RGB(0x7, 0x7, 0), 				//背景颜色
							"GetAngle",		//内容
							~RGB_RED, 		//字体颜色
							cortexMsp_btnHandler_getAngle_press, 			//点击处理函数:在按钮点击一下时执行
							cortexMsp_btnHandler_getAngle_hold,	//保持处理函数:在按钮保持按下时执行
							cortexMsp_btnHandler_getAngle_release
							);
	
	btnGetBarrier = BUTTON_create_button(20, //宽
							1,  					//高
							RGB(0x37, 0x16, 0x1), 				//背景颜色
							"GetBarr",//内容
							~RGB_RED,   		//字体颜色
							cortexMsp_btnHandler_getBarrier_press, 			//点击处理函数:在按钮点击一下时执行
							cortexMsp_btnHandler_getBarrier_hold,	//保持处理函数:在按钮保持按下时执行
							cortexMsp_btnHandler_getBarrier_release
							);
							
	btnFree = BUTTON_create_button(100, 	//宽
							1,  														//高
							RGB(0x37, 0x16, 0x1), 					//背景颜色
							"FreeCar",													//内容
							~RGB_RED,   		//字体颜色
							cortexMsp_btnHandler_free_press, 			//点击处理函数:在按钮点击一下时执行
							cortexMsp_btnHandler_free_hold,	//保持处理函数:在按钮保持按下时执行
							cortexMsp_btnHandler_free_release
							);
							
	btnPad = BUTTON_create_button(100, //宽
							100,  //高
							ScreenState.backgroundColor, //背景颜色
							" ",   //内容
							~RGB_RED,   //字体颜色
							cortexMsp_btnHandler_pad_press, 			//点击处理函数:在按钮点击一下时执行
							cortexMsp_btnHandler_pad_hold,	//保持处理函数:在按钮保持按下时执行
							cortexMsp_btnHandler_pad_release
							);
							
	btnOnOff = BUTTON_create_button(1, 1, 
							OnLineState ? RGB_GREEN: RGB(0x37, 0x16, 0x1), 
							OnLineState ? "ON" : "OFF", 
							RGB_WHITE,
							null,
							null,
							cortexMsp_btnHandler_onOff_release
							);
	
	//绘制Pad及其附属
	BUTTON_draw_button(SCREEN_SIZE_X/9, 	SCREEN_SIZE_Y/2 - 20, 		btnPad);
	LCD_draw_line(btnPad->xStart + btnPad->buttonWidth/2,  btnPad->yStart + btnPad->buttonHigh/2, 
	btnPad->xStart + btnPad->buttonWidth/2 + 80,  btnPad->yStart + btnPad->buttonHigh/2 + 30, PAD_FRAME_COLOR);
	LCD_draw_line(btnPad->xStart + btnPad->buttonWidth/2 + 1,  btnPad->yStart + btnPad->buttonHigh/2 + 1, 
	btnPad->xStart + btnPad->buttonWidth/2 + 81,  btnPad->yStart + btnPad->buttonHigh/2 + 31, PAD_FRAME_COLOR);
	
	LCD_draw_circle(btnPad->xStart + btnPad->buttonWidth/2,  btnPad->yStart + btnPad->buttonHigh/2, 
		btnPad->buttonWidth/2 + 10, PAD_FRAME_COLOR);
	LCD_draw_circle(btnPad->xStart + btnPad->buttonWidth/2,  btnPad->yStart + btnPad->buttonHigh/2, 
		btnPad->buttonWidth/2, PAD_BACK_COLOR);
	LCD_draw_rectangle(btnPad->xStart + btnPad->buttonWidth/2 + 80,  btnPad->yStart + btnPad->buttonHigh/2 + 30,
	85, 2, PAD_FRAME_COLOR);
	cortexMsp_update_pad_state("lenfien");
	
	LCD_draw_circle(btnPad->xStart + btnPad->buttonHigh/2, 
		btnPad->yStart + btnPad->buttonWidth/2,  20, PAD_FRONT_COLOR); 	//让小圆回到中心点
	
	BUTTON_draw_button(0, 		SCREEN_SIZE_Y/6, btnFree);	
	BUTTON_draw_button(SCREEN_SIZE_X*2/3, SCREEN_SIZE_Y*1/3, btnBarrierSwitch);
	{
		POINT ps[3];
		ps[0].x = btnBarrierSwitch->xStart;
		ps[0].y = btnBarrierSwitch->yStart + btnBarrierSwitch->buttonHigh/2;
		ps[1].x = btnBarrierSwitch->xStart - 20;
		ps[1].y = btnBarrierSwitch->yStart + btnBarrierSwitch->buttonHigh * 2;
		ps[2].x = btnBarrierSwitch->xStart - 60;
		ps[2].y = btnBarrierSwitch->yStart + btnBarrierSwitch->buttonHigh * 2;
		LCD_draw_lines(ps, 3, btnBarrierSwitch->buttonColor);
		cortexMsp_update_barrier_state();
	}
	
	BUTTON_draw_button(SCREEN_SIZE_X*2/3, btnBarrierSwitch ->yStart  + btnBarrierSwitch->buttonHigh + 2, btnGetBarrier);
	BUTTON_draw_button(SCREEN_SIZE_X*2/3, btnGetBarrier ->yStart  + btnGetBarrier->buttonHigh + 2, btnGetAngle);
	{
		POINT ps[3];
		ps[0].x = btnFree->xStart + btnFree->buttonWidth;
		ps[0].y = btnFree->yStart + btnFree->buttonHigh/2;
		ps[1].x = btnFree->xStart + btnFree->buttonWidth - 20;
		ps[1].y = btnFree->yStart + btnFree->buttonHigh /2 + 35;
		ps[2].x = btnFree->xStart + 20;
		ps[2].y = btnFree->yStart + btnFree->buttonHigh /2 + 35;
		LCD_draw_lines(ps, 3, btnFree->buttonColor);
		cortexMsp_update_free_state();
	}
	
	LCD_draw_line(0, FONT_HIGH + 2, 
		SCREEN_SIZE_X * 2/3, FONT_HIGH + 2, UI_LINE_COLOR);
	LCD_draw_line(0, SCREEN_SIZE_Y - FONT_HIGH - 2, SCREEN_SIZE_X, SCREEN_SIZE_Y - FONT_HIGH - 2, UI_LINE_COLOR);
	LCD_draw_line(SCREEN_SIZE_X*3/5 + 10, SCREEN_SIZE_Y/6, SCREEN_SIZE_X, SCREEN_SIZE_Y/6, UI_LINE_COLOR);
	
	BUTTON_draw_button(SCREEN_SIZE_X - btnOnOff->buttonWidth, 
			SCREEN_SIZE_Y - 50, btnOnOff);
	
	COMPASS_draw_UI();
	cortexMsp_update_supersonic_state();
}


U8 FreeState_isRequestData = 1;
void cortexMsp_init()
{
	SSD1289_INITIAL_STRUCT it = 
	{
		ORITATION_320_240,
		COLOR_262K,
		RGB_262K_BLACK,
		1
	};
	
	NVIC_set_PRIx(_USART1_IRQn, 0x20);			//配置中断优先级
	NVIC_set_PRIx(_EXTI9_5_IRQn, 0x40);			//计数器成为次级优先级
	
	SSD1289_init(it);	//初始化显示器
	//ADS7483_init();		//初始化触摸屏
	
	//DEBUG_color_init();
	//while(1);
	USART1_init(BAUD_9600);
	
	cortexMsp_UI_init();
	cortexMsp_send_data(CMD_GET_STATE);
	//cortexMsp_update_supersonic_state();
	
	while(1)
	{
		if(FreeState == 1)
		{
			//cortexMsp_send_data(CMD_GET_COMPASS_DATA);
			//cortexMsp_send_data(CMD_GET_BARRIER_DATA);
			//delay(10000);
		}
	}
}

/*
	更新Compass指针位置 
*/
void cortexMsp_update_compass_state()
{
	COMPASS_update_UI(intBuffer[0]);
}

#define UNCONNECT_FONT_COLOR	RGB(0x1, 0x16, 0x1)
#define UNCONNECT_BACK_COLOR		RGB_RED
#define CONNECT_FONT_COLOR		RGB(0x7, 0x7, 0x7)
#define CONNECT_BACK_COLOR		RGB_GREEN
void cortexMsp_update_connect_state()
{
	U32 oldColor = LCD_set_font_color(OnLineState ? CONNECT_FONT_COLOR: UNCONNECT_FONT_COLOR);
	U32 oldBackColor = LCD_set_font_backColor(OnLineState ? CONNECT_BACK_COLOR: UNCONNECT_BACK_COLOR);
	U32 oldRowSpacing = LCD_set_rowSpacing(0);
	LCD_printf(SCREEN_SIZE_X - FONTS_WIDTH("OFF LINE"), SCREEN_SIZE_Y - FONT_HIGH, OnLineState ? "ON LINE " : "OFF LINE");
	LCD_set_font_color(oldColor);
	LCD_set_font_backColor(oldBackColor);
	LCD_set_rowSpacing(oldRowSpacing);
	strcpy(btnOnOff->content, OnLineState ? "ON" : "OFF");
	btnOnOff->buttonColor = OnLineState ? RGB_GREEN: RGB(0x37, 0x16, 0x1);
	BUTTON_redraw_button(btnOnOff);
}

//更新Pad状态
//主要用来更新Pad旁边的文字
void cortexMsp_update_pad_state(char *msg)
{
	U32 oldColor = LCD_set_font_color(PAD_WORD_COLOR);
	LCD_printf(btnPad->xStart + btnPad->buttonWidth/2 + 85,  btnPad->yStart + btnPad->buttonHigh/2 + 10, msg);
	LCD_set_font_color(oldColor);
}

#define SUPERSONIC_FONT_COLOR	RGB(0x37, 0x16, 0x1)
void cortexMsp_update_supersonic_state()
{
	U32 oldColor = LCD_set_font_color(SUPERSONIC_FONT_COLOR);
	if(intBuffer[0] > 500 || intBuffer[1] > 500 || intBuffer[2] > 500)
		LCD_printf(0, SCREEN_SIZE_Y - FONT_HIGH, "BAR:invalue, try again");
	LCD_printf(0, SCREEN_SIZE_Y - FONT_HIGH, "BAR:%3d %3d %3d       ", intBuffer[0], intBuffer[1], intBuffer[2]);
	LCD_set_font_color(oldColor);
}

#define FREE_FONT_COLOR ~RGB(0x37, 0x16, 0x1)
void cortexMsp_update_free_state()
{
	U32 oldColor = LCD_set_font_color(FreeState == 1 ? FREE_FONT_COLOR : FreeState == 0 ? RGB(0x37, 0x16, 0x1) : RGB_RED);
	LCD_printf(btnFree->xStart + 20, btnFree->yStart + btnFree->buttonHigh /2 + 37 - FONT_HIGH , 
				(FreeState == 1 )? "Free  " : (FreeState == 0) ? "Ctrled" : "--    ");
	LCD_set_font_color(oldColor);
}

void cortexMsp_update_state()
{
	cortexMsp_update_free_state();
	cortexMsp_update_barrier_state();
	cortexMsp_update_connect_state();
}

//更新BarrierSwitch按钮的文字提示信息
void cortexMsp_update_barrier_state()
{
	U32 oldColor = LCD_set_font_color(BarrierState == 1? RGB_GREEN : BarrierState == 0 ? btnBarrierSwitch->buttonColor : RGB_RED);
	LCD_printf(btnBarrierSwitch->xStart - 50, btnBarrierSwitch->yStart + btnBarrierSwitch->buttonHigh * 2 - FONT_HIGH, 
		BarrierState == 1 ? "ON " : BarrierState == 0 ? "OFF" : "-- ");
	LCD_set_font_color(oldColor);
}


	
void cortexMsp_test()
{
	cortexMsp_init();
	//while(1);
	while(1)
	{
		if(FreeState)
		{
			cortexMsp_send_data(CMD_GET_COMPASS_DATA);
		}
	}
}

///////////////////////////COMPASS/////////////////////////////////
#define COMPASS_CENTRE_X  SCREEN_SIZE_X/2
#define COMPASS_CENTRE_Y  SCREEN_SIZE_Y/4
#define COMPASS_RADIUS    28
#define COMPASS_INDICATOR 25
#define COMPASS_FRAME_COLOR  	RGB(0x20, 0x20, 	0x10)
#define COMPASS_FRONT_COLOR		RGB(0x7, 0x7, 0)
#define COMPASS_INDI_COLOR		COMPASS_FRAME_COLOR
#define COMPASS_FONT_COLOR		COMPASS_FRAME_COLOR

//将角度值转换为坐标值
POINT COMPASS_angle2point(S16 angle, S16 x, S16 y, S16 lineLength)
{
  POINT p;
  p.x = (S16)((double)x + (cos((double)angle/360.0 * 6.28) * (double)lineLength));
  p.y = (S16)((double)y - (sin((double)angle/360.0 * 6.28) * (double)lineLength));
  return p;
}

void COMPASS_draw_indicator(S16 angle, S16 length, U32 p)
{
  POINT point = COMPASS_angle2point(angle, COMPASS_CENTRE_X, COMPASS_CENTRE_Y, length);
  LCD_draw_line(COMPASS_CENTRE_X, COMPASS_CENTRE_Y, point.x, point.y, p);
  point = COMPASS_angle2point(angle + 180, COMPASS_CENTRE_X, COMPASS_CENTRE_Y, length/5);
  LCD_draw_line(COMPASS_CENTRE_X, COMPASS_CENTRE_Y, point.x, point.y, p);
}

void COMPASS_update_UI(S16 angle)
{
  static S16 old = -1;
  U32 oldColor;
  if(old != -1)
     COMPASS_draw_indicator(old, COMPASS_INDICATOR, COMPASS_FRONT_COLOR);
  COMPASS_draw_indicator(angle, COMPASS_INDICATOR, COMPASS_INDI_COLOR);
	oldColor = LCD_set_font_color(COMPASS_FONT_COLOR);
	LCD_printf(COMPASS_CENTRE_X + COMPASS_RADIUS + 15, COMPASS_CENTRE_Y - 12, "%4dDeg  ", angle);
	LCD_set_font_color(oldColor);
  old = angle;
}

void COMPASS_draw_UI()
{
	LCD_draw_line(COMPASS_CENTRE_X, COMPASS_CENTRE_Y + COMPASS_RADIUS, 
	COMPASS_CENTRE_X + COMPASS_RADIUS + 10, COMPASS_CENTRE_Y + 5, COMPASS_FRAME_COLOR);
	LCD_draw_line(COMPASS_CENTRE_X + COMPASS_RADIUS + 10, COMPASS_CENTRE_Y + 5, 
	COMPASS_CENTRE_X + COMPASS_RADIUS + 100, COMPASS_CENTRE_Y + 5, COMPASS_FRAME_COLOR);
  LCD_draw_circle(COMPASS_CENTRE_X, COMPASS_CENTRE_Y, COMPASS_RADIUS + 3, COMPASS_FRAME_COLOR);
	LCD_draw_circle(COMPASS_CENTRE_X, COMPASS_CENTRE_Y, COMPASS_RADIUS, COMPASS_FRONT_COLOR);
}


