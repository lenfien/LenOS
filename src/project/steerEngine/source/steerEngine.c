#include "com_type_define.h"

#include "ssd1289.h"
#include "button.h"
#include "font.h"

#include "base_gpio.h"
#include "base_rcc.h"
#include "base_atime.h"

#include "cnf_atime.h"

void STEER_draw_UI(void);

void STEER_buttonAdd_holdHandler(POINT *p, BUTTON* pBtn);
void STEER_buttonSub_holdHandler(POINT *p, BUTTON* pBtn);
void STEER_update_UI(void);

//信号输出在PA8上
void STEER_init()
{
	
	//STEER_draw_UI();
	TIM1_CH1_generate_pwm(19592, 500, 0, 0);//产生20ms周期，占空比为0.5ms的波形的前PWM波
	GPIO_set_output_50MHZ_PP(GPIO_A, 10);
	GPIO_set_output_50MHZ_PP(GPIO_A, 12);
	GPIO_send_pin(GPIO_A, 10, 1);
	GPIO_send_pin(GPIO_A, 12, 0);
	//LCD_draw_empty_rectangle(70, 70, 170, 40, RGB_WHITE);
	//LCD_printf(0, 1, "The sinal port at PA8\n - 100 pin");
	//LCD_draw_line(0, 120, SCREEN_SIZE_X, 120, RGB_BLUE);
	//LCD_printf(0, 130, " pos:\n duty:\n angle:\n");
	//STEER_update_UI();
}

//占空比最低位0.5ms,最高位2.5ms
//对应位:500us和2500ms,中间有2000个幅度可以调节
//pos = 1 - 2000
void STEER_set_pos(U32 pos)
{
	TIM1_CH1_set_pwm_duty(500 + pos);
}

void STEER_draw_UI()
{
	BUTTON* pButtonAdd = BUTTON_create_button(50,
						20,
						0xFFFFFF,
						"TurnAdd",
						0,
						null,
						STEER_buttonAdd_holdHandler,
						null
						);
	BUTTON* pButtonSub = BUTTON_create_button(50,
						20,
						0xFFFFFF,
						"TurnSub",
						0,
						null,
						STEER_buttonSub_holdHandler,
						null
						);
	BUTTON_draw_button(80, 80, pButtonAdd);
	BUTTON_draw_button(160, 80, pButtonSub);
}

U32 SteerPos = 1;
void STEER_buttonAdd_holdHandler(POINT *p, BUTTON* pBtn)
{
	if(SteerPos < 2000)
		SteerPos ++;
	STEER_set_pos(SteerPos);
	STEER_update_UI();
}


void STEER_buttonSub_holdHandler(POINT *p, BUTTON* pBtn)
{	
	if(SteerPos > 1)
		SteerPos--;
	STEER_set_pos(SteerPos);
	
	STEER_update_UI();
}


void STEER_update_UI()
{
	const FONT_LIB* font = FONT_get_lib_info(FontFormat.fontType);
	//LCD_printf(70, 130, "%-d/2000   ", SteerPos);
	//LCD_printf(70, 130 + font->fontHigh, "%-.2fms/2.5ms   ", ((float)(SteerPos + 500.0)/1000.0));
	LCD_printf(70, 130 + 2*font->fontHigh, "%d/180`    ", (int)(180 * ((float)SteerPos/2000)));
}
