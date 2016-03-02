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
	��ʼ��Limbs
*/
void ROBOT_init()
{
	int index = 0;
	//��ʼ��IO��
	for(index = 0; index < LIMB_NUM; index ++)
	{
		RCC_enable_GPIO_x_clock(LimbsInf[index].cport1);
		RCC_enable_GPIO_x_clock(LimbsInf[index].cport2);
		GPIO_set_output_50MHZ_PP(LimbsInf[index].cport1, LimbsInf[index].cpin1);
		GPIO_set_output_50MHZ_PP(LimbsInf[index].cport2, LimbsInf[index].cpin2);
	}
	ROBOT_init_list();				//�����û���ActionList�ж��嶯����ʼ����Ӧ������
	RCC_enable_TIM1_clock();	//ʹ��ʱ��TIM1ʱ��
	TIM1_init_ms(1, 1);				//ʹ������ÿ1ms�����ж�
}

//����֫��Ż�ø�֫������Ӧ��֫����Ϣ,û���ҵ�����null
LIMB_INF* ROBOT_get_gpio(LIMB limb)
{
	int index;
	for(index = 0; index < LIMB_NUM; index++)
		if(limb == LimbsInf[index].limb)
			return LimbsInf + index;
	return null;
}

//����֫��Ͷ�������ָ�������ת����
LIMB_INF*	ROBOT_action(LIMB limb, MOTOR_ACTION act)
{
	LIMB_INF* pLI;
	pLI = ROBOT_get_gpio(limb);	
	if(pLI == null)
		return null;
	switch(act)
	{
		case HALT:			//ֹͣ
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 0);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 0);
			break;
		case DIRL:			//��ת
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 1);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 0);
			break;
		case DIRR:			//��ת
			GPIO_send_pin(pLI->cport1, pLI->cpin1, 0);
			GPIO_send_pin(pLI->cport2, pLI->cpin2, 1);
			break;
		default:
			abort();			//����,��ֹ����
	}
	return pLI;
}


void ROBOT_test()
{
	ROBOT_init();
}
