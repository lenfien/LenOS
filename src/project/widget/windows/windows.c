#include <stdio.h>
#include <string.h>

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"

#include "base_dma.h"
#include "base_gpio.h"
#include "base_rcc.h"
#include "base_exti.h"
#include "base_afio.h"
#include "base_pwr.h"
#include "base_rtc.h"
#include "base_atime.h"
#include "base_usart.h"
#include "base_crc.h"
#include "base_adc.h"
#include "base_dac.h"

#include "led.h"

#include "cnf_rcc.h"
#include "cnf_usart.h"
#include "cnf_dma.h"
#include "cnf_crc.h"
#include "cnf_rtc.h"
#include "cnf_atime.h"
#include "cnf_adc.h"
#include "cnf_systick.h"
#include "cnf_dac.h"

#include "ssd1289_base.h"
#include "ssd1289_graphic.h"
#include "ssd1289_type.h"
#include "ads7483_base.h"
#include "ssd1289_font.h"
#include "ds18b20_base.h"

#include "font.h"
#include "button.h"
#include "button_list.h"
#include "adconverter.h"
#include "daConverter.h"
#include "steerEngine.h"

//#define WINDOW_ANIMATION	//注销了这句会让窗口没有动画显示

#define DWINDOW_YESNO 	0
#define DWINDOW_OK		1

BUTTON *PButtonYes = null;
BUTTON *PButtonNo = null;
BUTTON *PButtonOk = null;
U8 dialogOkFlag = 1;
U8 dialogResult = 0;

void WINDOW_btnHandler_yes(BUTTON* pBtn);
void WINDOW_btnHandler_no(BUTTON* pBtn);
void WINDOW_btnHandler_ok(BUTTON* pBtn);
void WINDOW_delete_button(void);

U8	WINDOW_show_dialog_box( char *msg, char* title, U32 backColor, U8 type)
{
	U32 oldBackColor;
	U32 oldFontColor;
	
#ifdef	WINDOW_ANIMATION
	float aniX = 0;
	float aniY = 0;
	while(aniX <= SCREEN_SIZE_X + 10|| aniY <= SCREEN_SIZE_Y * 4/6 )
	{
		LCD_draw_rectangle(0, SCREEN_SIZE_Y/6, aniX, aniY, backColor);
		aniX += SCREEN_SIZE_X / 3.0;
		aniY += SCREEN_SIZE_Y *4.0/6.0/3.0;
	}
#else
	LCD_draw_rectangle(0, SCREEN_SIZE_Y/6, SCREEN_SIZE_X, SCREEN_SIZE_Y * 4/6, backColor);
#endif
	if(type == DWINDOW_YESNO)
	{
		PButtonYes = BUTTON_create_button(50, 20, ScreenState.backgroundColor, "YES", ~ScreenState.backgroundColor, null, null, WINDOW_btnHandler_yes);
		PButtonNo  = BUTTON_create_button(50, 20, ScreenState.backgroundColor, "NO", ~ScreenState.backgroundColor, null, null, WINDOW_btnHandler_no);
		BUTTON_draw_button(SCREEN_SIZE_X*2/5, 	SCREEN_SIZE_Y*3/5 + 30, PButtonYes);
		BUTTON_draw_button(SCREEN_SIZE_X*3/5 + 10, 	SCREEN_SIZE_Y*3/5 + 30, PButtonNo);
	}
	else
	{
		PButtonOk = BUTTON_create_button(50, 20, ScreenState.backgroundColor, "OK", ~ScreenState.backgroundColor, null, null, WINDOW_btnHandler_ok);
		BUTTON_draw_button(SCREEN_SIZE_X /2, SCREEN_SIZE_Y*3/5 + 30, PButtonOk);
	}
	LCD_draw_line(0, SCREEN_SIZE_Y*3/5 + 25, SCREEN_SIZE_X,  SCREEN_SIZE_Y*3/5 + 25, ScreenState.backgroundColor);
	LCD_draw_line(0, SCREEN_SIZE_Y/5 + 20, SCREEN_SIZE_X, SCREEN_SIZE_Y/5 + 20, ScreenState.backgroundColor);
	
	oldBackColor = LCD_set_font_backColor(backColor);
	oldFontColor = LCD_set_font_color(ScreenState.backgroundColor);
	LCD_printf(0, SCREEN_SIZE_Y/5 - 5, title);
	LCD_set_font_backColor(oldBackColor);
	LCD_set_font_color(oldFontColor);
	
	oldBackColor = LCD_set_font_backColor(backColor);
	oldFontColor = LCD_set_font_color(~backColor);
	
	LCD_printf(20, SCREEN_SIZE_Y/4 + 10 , msg);
	LCD_set_font_backColor(oldBackColor);
	LCD_set_font_color(oldFontColor);
	
	while(dialogOkFlag);
	dialogOkFlag= 1;
	WINDOW_delete_button();
	SSD1289_clear_screen(ScreenState.backgroundColor);
	return dialogResult;
}


void WINDOW_btnHandler_yes(BUTTON* pBtn)
{
	dialogResult = 1;
	dialogOkFlag = 0;
}

void WINDOW_btnHandler_no(BUTTON* pBtn)
{
	dialogResult = 0;
	dialogOkFlag = 0;
}

void WINDOW_btnHandler_ok(BUTTON* pBtn)
{
	dialogOkFlag = 0;
}

void WINDOW_delete_button()
{
	if(PButtonYes != null)
	{
		BTNLIST_delete_button(PButtonYes, PButtonList);
		PButtonYes = null;
	}
	if(PButtonNo != null)
	{
		BTNLIST_delete_button(PButtonNo, PButtonList);
		PButtonNo = null;
	}
	if(PButtonOk != null)
	{
		BTNLIST_delete_button(PButtonOk, PButtonList);
		PButtonOk = null;
	}
}
	

void WINDOW_test()
{
	//LCD_printf(0,0, "%d", WINDOW_show_dialog_box("hello, do you want to continue?", RGB_RED, DWINDOW_YESNO));
}



