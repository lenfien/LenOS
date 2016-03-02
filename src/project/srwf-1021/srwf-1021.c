#include <stdio.h>

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
#include "cnf_atime.h"

//接到无线传感模块上的接收引脚
#define SRWF1021_RX_PORT	GPIO_A
#define SRWF1021_RX_PIN		9

//接到无线传感模块上的发送引脚
#define SRWF1021_TX_PORT	GPIO_A
#define SRWF1021_TX_PIN		10

//睡眠控制 始终为高
#define SRWF1021_SLP_PORT	GPIO_A
#define SRWF1021_SLP_PIN	11

//始终为高
#define SRWF1021_RST_PORT	GPIO_A
#define SRWF1021_RSR_PIN	12

void SRWF1021_reset(void);
void SRWF1021_sleep(void);
//USART1_TX	PA9
//USART1_RX PA10

//USART2_TX PA2
//USART2_RX PA3

void SRWF1021_test()
{
	USART1_init(BAUD_9600);	
	USART2_init(BAUD_9600);
	
	while(1)
	{
		USART1_put_char('h');
		delay_ms(1000);
	}
}
