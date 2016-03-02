#include <stdio.h>
#include <stdlib.h>

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"
#include "base.h"

#include "button.h"
#include "button_list.h"

#include "cnf.h"

#include "ssd1289.h"

#include "ads7483_base.h"
#include "ssd1289_font.h"
#include "ds18b20_base.h"

#include "font.h"

#include "adconverter.h"
#include "daConverter.h"
#include "steerEngine.h"

#include "window.h"

void BtHandler_adConverter(BUTTON* pBtn);
void BtHandler_drawLine(BUTTON* pBtn);
void BtHandler_touchTest(BUTTON* pBtn);
void BtHandler_exit(BUTTON* pBtn);

void EXAM_delete_button(void);

BUTTON* pButtonADC;
BUTTON* pButtonDrawLine;
BUTTON* pButtonTouchTest;
BUTTON* pButtonExit;
U8 EXAM_mode = 0;
S8 mode = -1;

void EXAM_init()
{
	pButtonADC = BUTTON_create_button(SCREEN_SIZE_X, 20, 
										RGB_262K_BLACK,
										"AdConverter",
										RGB_262K_BLUE,
										null, 
										null,
										BtHandler_adConverter);
	pButtonDrawLine = BUTTON_create_button(SCREEN_SIZE_X, 20, 
										RGB_262K_BLACK,
										"DrawLine",
										RGB_262K_WHITE,
										null, 
										null,
										BtHandler_drawLine);
	pButtonTouchTest = BUTTON_create_button(SCREEN_SIZE_X, 20, 
										RGB_262K_BLACK,
										"TouchTest",
										RGB_262K_RED,
										null, 
										null,
										BtHandler_touchTest);

	pButtonExit = BUTTON_create_button(10, 10, 
										RGB_262K_RED, 
										"Exit", 
										RGB_262K_GREEN, 
										null, 
										null, 
										BtHandler_exit);
										
	BUTTON_draw_button(0, 20, pButtonADC);
	BUTTON_draw_button(0, 80, pButtonDrawLine);
	BUTTON_draw_button(0, 140, pButtonTouchTest);
	
	while(mode == -1);
	
	EXAM_delete_button();
	SSD1289_clear_screen(0);
	
	switch(mode)
	{
		case 0:
			WINDOW_show_dialog_box("ADConverter, press Ok to continue", "ADConverter",RGB_BLUE, DWINDOW_OK);
			ADConverter_init();
			DAConverter_init();
			break;
		case 1:
			WINDOW_show_dialog_box("You can draw a line on the screen with your finger.", "DrawLine",RGB_WHITE, DWINDOW_OK);
			EXAM_mode = 1;
			break;
		case 2:
			WINDOW_show_dialog_box("Test your touch position, and show the coordination where your finger at.", "COORDINATION",RGB_RED, DWINDOW_OK);
			EXAM_mode = 2;
			break;
	}
	mode = -1;
}


void BtHandler_adConverter(BUTTON* pBtn)
{
	mode = 0;
}

void BtHandler_drawLine(BUTTON* pBtn)
{
	EXAM_delete_button();
	SSD1289_clear_screen(0);
	mode = 1;
}

void BtHandler_touchTest(BUTTON* pBtn)
{
	EXAM_delete_button();
	SSD1289_clear_screen(0);
	mode = 2;
}

void BtHandler_exit(BUTTON* pBtn)
{
	EXAM_delete_button();
	SSD1289_clear_screen(ScreenState.backgroundColor);
	LCD_printf(0, 0, "thank you for use\n\n\n\n\n\t\t\t\t\t---lenfien");
}

void EXAM_delete_button()
{
	BTNLIST_delete_button(pButtonADC, PButtonList);
	BTNLIST_delete_button(pButtonDrawLine, PButtonList);
	BTNLIST_delete_button(pButtonTouchTest, PButtonList);
	BTNLIST_delete_button(pButtonExit, PButtonList);	
}



