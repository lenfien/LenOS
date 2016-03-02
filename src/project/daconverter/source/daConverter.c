
#include "base_dac.h"
#include "cnf_dac.h"

#include "ssd1289.h"

#include "button.h"
#include "font.h"

#include "daConverter.h"

#define BUTTON_COLOR		RGB(0x1A, 0x20, 0)
#define SLIDER_COLOR		RGB_GREEN
#define SLIDER_PRESS_COLOR	(SLIDER_COLOR - 0xFF)

#define BUTTON_X			(SCREEN_SIZE_X - BUTTON_WIDTH)
#define BUTTON_Y			0
#define BUTTON_WIDTH		19
#define BUTTON_HIGH			(SCREEN_SIZE_Y-50) 

#define SLIDER_HIGH			(BUTTON_HIGH/10)
#define SLIDER_WIDTH		BUTTON_WIDTH
#define DA_RANGE			(BUTTON_HIGH - SLIDER_HIGH)

#define SLIDER_X 			BUTTON_X			//小滑块的X坐标
U16 SLIDER_Y;				//小滑块的Y坐标
U16 SLIDER_POS;				// 0 - DA_RANGE


//初始化
void DAConverter_init()
{
	DAC_cnf_mode1();		//将DAC配置为非触发模式
	
	DAC_channel1_set_holding_data(0xFFF/2);	// 设置默认的电压值为中间位置
	SLIDER_Y = BUTTON_Y + BUTTON_HIGH/2;
	
	DAConverter_draw_UI();	//绘制UI
}


void DAConverter_draw_UI()
{
	BUTTON* pButton = BUTTON_create_button(BUTTON_WIDTH, BUTTON_HIGH, BUTTON_COLOR, 
											" ", BUTTON_COLOR, 
											DAConverter_click_handler, 
											DAConverter_hold_handler, 
											DAConverter_release_handler);
	
	BUTTON_draw_button(BUTTON_X, BUTTON_Y, pButton);
	
	LCD_draw_rectangle(SLIDER_X, SLIDER_Y - SLIDER_HIGH/2, SLIDER_WIDTH, SLIDER_HIGH, SLIDER_COLOR);
}

void DAConverter_draw_slider(U16 y,  U32 color)
{
	LCD_draw_rectangle(SLIDER_X, y - SLIDER_HIGH/2, SLIDER_WIDTH, SLIDER_HIGH, color);
}

S8 DAConverter_update_slider(U16 newY)
{
	static U16 oldY = 0;
	
	
	//如果点击点在小滑块的滚动范围外则 返回-1
	if(newY < BUTTON_Y + SLIDER_HIGH/2 || newY > BUTTON_Y + BUTTON_HIGH - SLIDER_HIGH/2)
		return -1;
	
	SLIDER_Y = newY;
	
	//计算Slide的位置
	SLIDER_POS = newY - BUTTON_Y - SLIDER_HIGH/2;
		
	if(oldY)
		DAConverter_draw_slider(oldY, ~BUTTON_COLOR);
	DAConverter_draw_slider(newY, SLIDER_COLOR);
	
	oldY = newY;
	return SLIDER_Y;
}


void DAConverter_click_handler(BUTTON* pBtn)
{
	
}

void DAConverter_hold_handler(POINT* pPoint, BUTTON* pBtn)
{
	
	DAConverter_update_slider(pPoint->y);
	DAC_channel1_set_holding_data(4095 * (((float)(DA_RANGE - SLIDER_POS)/DA_RANGE)));
	//LCD_printf(0,0, "%3d", SLIDER_POS);
}

void DAConverter_release_handler(BUTTON* pBtn)
{
	DAConverter_draw_slider(SLIDER_Y, SLIDER_COLOR);
}
