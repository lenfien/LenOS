#include <stdio.h>
#include <stdlib.h>

#include "lenfien.h"

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"
#include "base.h"


#include "cnf.h"

#include "robot.h"

//������еĶ�����ִ������,�򷵻�0
U8	ROBOT_update_state()
{
	U8 state = 0;
	LIMB_ACTION_NODE* pNode = LimbActionList->pHead;
	
	while(pNode)
	{
		if(pNode->pLimbAction->actionState != ALREADY)
		{
			if(pNode->pLimbAction->startTime <= ROBOT_TIME_COUNTER && pNode->pLimbAction->actionState == NEVER)	//����ö�����ʱ�䵽��,���ѳ���,���Ҹö�����δ��ִ�й�
			{
				ROBOT_action(pNode->pLimbAction->limb, pNode->pLimbAction->action);	//�������
				pNode->pLimbAction->actionState = GOING;							//����״̬
			}
			
			if(pNode->pLimbAction->stopTime <= ROBOT_TIME_COUNTER && pNode->pLimbAction->actionState == GOING)	//������˻򳬹���ֹͣʱ��,���������ת
			{
				ROBOT_action(pNode->pLimbAction->limb, HALT);				//ֹͣ
				pNode->pLimbAction->actionState = ALREADY;		//���¶���״̬
			}
			state = 1;
		}
		
		pNode = pNode->pNext;
	}
	return state;	
}
