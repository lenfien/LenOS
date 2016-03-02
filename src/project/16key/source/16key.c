#include "base_rcc.h"
#include "base_gpio.h"

#include "font.h"


#define COLUM_PORT 	GPIO_A
#define COLUM_1		8
#define COLUM_2		9
#define COLUM_3		10
#define COLUM_4		11

#define LINE_PORT	GPIO_A
#define LINE_1		12
#define LINE_2		13
#define LINE_3		14
#define LINE_4		15

#define PWR_PORT	GPIO_B
#define PWR_PIN		0

#define GND_PORT	GPIO_A
#define GND_PIN		9


void KEY16_init()
{
	//使能GPIO时钟
	RCC_enable_GPIO_x_clock(GPIO_B);
	//配置行线为上下拉输出
	
	//配置列线为输入
	GPIO_set_input_PP(COLUM_PORT, COLUM_1);
	GPIO_set_input_PP(COLUM_PORT, COLUM_2);
	GPIO_set_input_PP(COLUM_PORT, COLUM_3);
	GPIO_set_input_PP(COLUM_PORT, COLUM_4);
	
	//配置电源
	GPIO_set_output_50MHZ_PP(PWR_PORT, PWR_PIN);
	GPIO_send_pin(PWR_PORT, PWR_PIN, 1);
}


void KEY16_test()
{
	U16 i;
	KEY16_init();
	
	i = GPIO_receive_port(COLUM_PORT);
	FONT_printf(0,0, "0x%X", i);
}
