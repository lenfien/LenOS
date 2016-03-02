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


LIMB_ACTION_LIST*	ROBOT_create_list()
{
	LIMB_ACTION_LIST* list = (LIMB_ACTION_LIST*)malloc(sizeof(LIMB_ACTION_LIST));
	list->actionNum = 0;
	list->pHead = list->pEnd = null;
	
	return list;
}

//将一个Action插入到list中
LIMB_ACTION_NODE* ROBOT_insert_action(LIMB_ACTION *pAction)
{
	LIMB_ACTION_NODE* pNode = null;
	if(pAction == NULL)
		return null;
	
	if(LimbActionList == null)
		LimbActionList = ROBOT_create_list();
	
	pNode = (LIMB_ACTION_NODE*)malloc(sizeof(LIMB_ACTION_NODE));
	pNode->pLimbAction = pAction;
	pNode->pPre = pNode->pNext = null;
	
	if(LimbActionList->pHead == null)
		LimbActionList->pHead = LimbActionList->pEnd = pNode;
	else
	{
		LimbActionList->pEnd->pNext = pNode;
		pNode->pPre = LimbActionList->pEnd;
		LimbActionList->pEnd = pNode;
	}
	LimbActionList->actionNum ++;
	return pNode;
}

//更新动作链表
void ROBOT_init_list()
{
	int index = 0;
	for(index = 0; index < ACTION_NUM; index++)
	{
		LimbActions[index].actionState = NEVER;
		if(LimbActions[index].delayTime > 800)
			LimbActions[index].delayTime = 800;
		LimbActions[index].stopTime = LimbActions[index].startTime + LimbActions[index].delayTime;
		ROBOT_insert_action(LimbActions + index);
	}
}

