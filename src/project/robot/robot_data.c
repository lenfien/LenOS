#include <stdio.h>
#include <stdlib.h>

#include "lenfien.h"

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
#include "beep.h"

#include "cnf_rcc.h"
#include "cnf_atime.h"

#include "robot.h"

extern U32 ROBOT_TIME_COUNTER = 0;

LIMB_ACTION_LIST* LimbActionList = null;

//所有的肢体定义在这里
U32 LIMB_NUM = 4;							//当前肢体的数量
LIMB_INF LimbsInf[20] = 
{
	{LLEG, GPIO_D, PIN_1, GPIO_D, PIN_2},
	{RLEG, GPIO_D, PIN_3, GPIO_D, PIN_4},
	{LRWAIST, GPIO_D, PIN_5, GPIO_D, PIN_6},
	{FBWAIST, GPIO_D, PIN_8, GPIO_D, PIN_9}
};

#define BACK_TIME 800

#define HALF_TIME 	200
#define WHOLE_TIME 	2*HALF_TIME

U32 ACTION_NUM = 24;
LIMB_ACTION LimbActions[50] = 
{
	//肢体号	方向 起始时间	保持时间
	{FBWAIST, DIRL, 	0,			200				},		{FBWAIST, DIRR, 	500,		200				},
	{LLEG, 		DIRL, 	1000, 	HALF_TIME	},		{RLEG,  	DIRR, 	1000, 	HALF_TIME},			{LRWAIST, DIRR, 	1000, 	100				},	//1
	{LLEG, 		DIRR, 	1200, 	WHOLE_TIME},		{RLEG, 		DIRL, 	1200, 	WHOLE_TIME},		{LRWAIST, DIRL, 	1200, 	100				},//2
	{LLEG, 		DIRL, 	1600, 	WHOLE_TIME},		{RLEG, 		DIRR, 	1600, 	WHOLE_TIME},		{LRWAIST, DIRR, 	1600, 	100				},//3
	{LLEG, 		DIRR, 	2000, 	WHOLE_TIME},		{RLEG, 		DIRL, 	2000, 	WHOLE_TIME},		{LRWAIST, DIRL, 	2000, 	100				},//4
	{LLEG, 		DIRL, 	2400, 	WHOLE_TIME},		{RLEG, 		DIRR, 	2400, 	WHOLE_TIME},		{LRWAIST, DIRR, 	2400, 	100				},//5
	{LLEG, 		DIRR, 	2800, 	WHOLE_TIME},		{RLEG, 		DIRL, 	2800, 	WHOLE_TIME},		{LRWAIST, DIRL, 	2800, 	100				},//6
	{LLEG, 		DIRL, 	3200, 	WHOLE_TIME},		{RLEG, 		DIRR, 	3200, 	WHOLE_TIME},		{LRWAIST, DIRR, 	3200, 	100				},//7
	{LLEG, 		DIRR, 	3600, 	WHOLE_TIME},		{RLEG, 		DIRL, 	3600, 	WHOLE_TIME},		{LRWAIST, DIRL, 	3600, 	100				},//8
	{LLEG, 		DIRL, 	4000, 	WHOLE_TIME},		{RLEG, 		DIRR, 	4000, 	WHOLE_TIME},		{LRWAIST, DIRR, 	4000, 	100				},//9
	{LLEG, 		DIRR, 	4400, 	WHOLE_TIME},		{RLEG, 		DIRL, 	4400, 	WHOLE_TIME},		{LRWAIST, DIRL, 	4400, 	100				},	//10
	
		
	
	{LRWAIST, DIRR,   1400, 	100				},
	{LRWAIST, DIRL, 	1600, 	100				}
};


