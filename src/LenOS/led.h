#ifndef __LED__
#define __LED__
#include "base.h"

#define LED_PORT 	GPIO_E
#define LED_PIN		2



#define LED_ON		GPIO_send_pin(LED_PORT, LED_PIN, 0)
#define LED_OFF 	GPIO_send_pin(LED_PORT, LED_PIN,  1)

#define LED(a)		(a ? LED_ON : LED_OFF)

void LED_init() 
{
	RCC_enable_GPIO_E_clock();
	GPIO_set_output_50MHZ_PP(LED_PORT, LED_PIN);
	LED_OFF;
}

#endif
