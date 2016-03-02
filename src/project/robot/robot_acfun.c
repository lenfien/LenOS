#include <stdio.h>
#include <stdlib.h>

#include "lenfien.h"

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"
#include "base.h"


#include "cnf.h"

#include "robot.h"

//如果所有的动作都执行完了,则返回0
U8	ROBOT_update_state()
{
	U8 state = 0;
	LIMB_ACTION_NODE* pNode = LimbActionList->pHead;
	
	while(pNode)
	{
		if(pNode->pLimbAction->actionState != ALREADY)
		{
			if(pNode->pLimbAction->startTime <= ROBOT_TIME_COUNTER && pNode->pLimbAction->actionState == NEVER)	//如果该动作的时间到了,或已超过,并且该动作从未被执行过
			{
				ROBOT_action(pNode->pLimbAction->limb, pNode->pLimbAction->action);	//开启电机
				pNode->pLimbAction->actionState = GOING;							//更新状态
			}
			
			if(pNode->pLimbAction->stopTime <= ROBOT_TIME_COUNTER && pNode->pLimbAction->actionState == GOING)	//如果到了或超过了停止时间,而电机还在转
			{
				ROBOT_action(pNode->pLimbAction->limb, HALT);				//停止
				pNode->pLimbAction->actionState = ALREADY;		//更新动作状态
			}
			state = 1;
		}
		
		pNode = pNode->pNext;
	}
	return state;	
}
