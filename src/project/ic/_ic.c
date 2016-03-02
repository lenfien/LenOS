
#include "base_gpio.h"
#include "base_rcc.h"
#include "com_functions.h"


#define IC_CLK_PORT		GPIO_B
#define IC_CLK_PIN		0
#define IC_DAT_PORT		GPIO_B
#define IC_DAT_PIN		1

#define IC_DAT_INPUT	GPIO_set_input_FLT(IC_DAT_PORT, IC_DAT_PIN)
#define IC_DAT_OUTPUT	GPIO_set_output_50MHZ_OD(IC_DAT_PORT, IC_DAT_PIN)

#define IC_DAT_HIGH		GPIO_send_pin(IC_DAT_PORT, IC_DAT_PIN, 1)
#define IC_DAT_LOW		GPIO_send_pin(IC_DAT_PORT, IC_DAT_PIN, 0)

#define IC_CLK_HIGH		GPIO_send_pin(IC_CLK_PORT, IC_CLK_PIN, 1)
#define IC_CLK_LOW		GPIO_send_pin(IC_CLK_PORT, IC_CLK_PIN, 1)

#define IC_DAT_IN		GPIO_receive_pin(IC_DAT_PORT, IC_DAT_PIN)

void IC_cnf_gpio()
{
	RCC_enable_GPIO_B_clock();
	
	GPIO_set_output_50MHZ_OD(IC_CLK_PORT, IC_CLK_PIN);
	
	IC_CLK_LOW;
	IC_DAT_HIGH;
}

//发送一个起始位
void IC_send_start()
{
	IC_DAT_OUTPUT;
	IC_CLK_LOW;		
	IC_DAT_HIGH;	//数据保持高
	delay_us(5);	//延迟5us
	IC_CLK_HIGH;	//
	delay_us(5);	//
	IC_DAT_LOW;		//
	delay_us(5);   	
	IC_CLK_LOW;		
}

// LSB first
char IC_send_byte(char b)
{
	int temp = 0;
	char ack = 1;
	IC_DAT_OUTPUT;

	for(temp = 0; temp < 8; temp ++)
	{
		IC_CLK_LOW;
		delay_us(5);
		(b & 0x01) ? IC_DAT_HIGH : IC_DAT_LOW;
		delay_us(5);
		IC_CLK_HIGH;
		delay_us(10);
		b >>= 1;
	}

	//接收回馈信号
	IC_DAT_HIGH;
	IC_DAT_INPUT;
	
	IC_CLK_HIGH;
	delay_us(5);
	ack = IC_DAT_IN;
	delay_us(5);
	IC_CLK_LOW;

	return ack;
}


char IC_read_byte()
{
	char b = 0;
	int temp = 0;

	IC_DAT_INPUT;
	
	for(temp = 0; temp < 8; temp ++)
	{
		IC_CLK_HIGH;
		delay_us(5);
		temp >>= 1;
		if(IC_DAT_IN)
			temp |= 0x80;
		delay_us(5);
		IC_CLK_LOW;
		delay_us(5);
	}
	return b;	
}


void IC_send_stop()
{
	IC_DAT_OUTPUT;
	IC_DAT_LOW;

	IC_CLK_LOW;
	delay_us(5);
	IC_CLK_HIGH;
	delay_us(5);
	IC_DAT_HIGH;
	delay_us(5);
	IC_CLK_LOW;
	delay_us(5);
}

void IC_process()
{	
	char a;
	char b;
	IC_cnf_gpio();
	IC_send_start();
	IC_send_byte(0xA0);
	IC_send_byte(0x00);
	IC_send_byte(0x19);
	IC_send_stop();

	IC_send_start();
	IC_send_byte(0xA0);
	IC_send_byte(0x00);
	IC_send_start();
	IC_send_byte(0xA1);
	a = IC_read_byte();
	IC_send_stop();

	b = a;
	while(1);

}








