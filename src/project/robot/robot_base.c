#include <stdio.h>
#include <stdlib.h>

#include "lenfien.h"

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"

#include "base.h"

#include "led.h"
#include "beep.h"

#include "cnf_rcc.h"
#include "cnf_atime.h"


#include "font.h"
#include "window.h"

#include "adconverter.h"
#include "daConverter.h"
#include "steerEngine.h"
#include "robot.h"


/*
	初始化Limbs
*/
void ROBOT_init()
{
	int index = 0;
	//初始化IO口
	for(index = 0; index < LIMB_NUM; index ++)
	{
		RCC_enable_GPIO_x_clock(LimbsInf[index].cport1);
		RCC_enable_GPIO_x_clock(LimbsInf[index].cport2);
		GPIO_set_output_50MHZ_PP(LimbsInf[index].cport1, LimbsInf[index].cpin1);
		GPIO_set_output_50MHZ_PP(LimbsInf[index].cport2, LimbsInf[index].cpin2);
	}
	ROBOT_init_list();				//根据用户在ActionList中定义动作初始化对应的链表
	RCC_enable_TIM1_clock();	//使能时钟TIM1时钟
	TIM1_init_ms(1, 1);				//使计数器每1ms产生中断
}

//根据肢体号获得该肢体所对应的肢体信息,没有找到返回null
LIMB_INF* ROBOT_get_gpio(LIMB limb)
{
	int index;
	for(index = 0; index < LIMB_NUM; index++)
		if(limb == LimbsInf[index].limb)
			return LimbsInf + index;
	return null;
}

//根据肢体和动作类型指定电机旋转方向
LIMB_INF*	ROBOT_action(LIMB limb, MOTOR_ACTION act)
{
	LIMB_INF* pLI;
	pLI = ROBOT_get_gpio(limb);	
	if(pLI == null)
		return null;
	switch(act)
	{
		case HALT:			//停止
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 0);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 0);
			break;
		case DIRL:			//左转
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 1);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 0);
			break;
		case DIRR:			//右转
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 0);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 1);
			break;
		default:
			abort();			//错误,终止程序
	}
	return pLI;
}


void ROBOT_test()
{
	ROBOT_init();
}
