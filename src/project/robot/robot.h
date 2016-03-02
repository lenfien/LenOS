
#ifndef __ROBOT
#define __ROBOT


//***************************
//定义了肢体号
typedef enum
{
	LLEG,			//左腿
	RLEG,			//右腿
	LRWAIST,	//左右腰
	FBWAIST,	//前后腰
	RARM			//右臂
}LIMB;


//每个肢体的控制信息
typedef struct
{
	LIMB limb;
	GPIO_PORT cport1;		//控制信号1
	GPIO_PIN	cpin1;			
	GPIO_PORT cport2;		//控制信号2
	GPIO_PIN  cpin2;
}LIMB_INF;

//定义了每个电机的状态
typedef enum
{
	HALT,	//停止
	DIRL,	//左转
	DIRR	//右转
}MOTOR_ACTION;	//动作

//定义了一个动作的状态 
typedef enum
{
	NEVER,	//从来没有被执行
	GOING,	//正在执行
	ALREADY	//已经执行过了
}ACTION_STATE;

typedef struct
{
	LIMB 					limb;					//要被执行动作的电机 
	MOTOR_ACTION 	action;				//电机应该的状态
	U32						startTime; 		//起始时间
	U32						delayTime;		//动作保持时间
	U32						stopTime;			//结束时间
	ACTION_STATE 	actionState;	//当前动作的状态
}LIMB_ACTION;

typedef struct tagNode
{
	LIMB_ACTION* pLimbAction;
	struct tagNode* pPre;
	struct tagNode* pNext;
}LIMB_ACTION_NODE;

typedef struct
{
	U32 actionNum;	//动作的数量
	LIMB_ACTION_NODE* pHead;
	LIMB_ACTION_NODE* pEnd;
}LIMB_ACTION_LIST;

#define MAX_TIME	800	//动作执行的最大时间为800,如果超过800,电流将急剧增大

extern LIMB_ACTION_LIST* LimbActionList;
extern LIMB_INF LimbsInf[];					//
extern LIMB_ACTION LimbActions[];		//动作库
extern U32 ROBOT_TIME_COUNTER;	//机器人时基计数器
extern U32 LIMB_NUM;						//当前肢体的数量
extern U32 ACTION_NUM;					//当前动作数量

/*
	根据肢体编号和动作类型执行相应动作
*/
LIMB_INF*	ROBOT_action(LIMB limb, MOTOR_ACTION act);

/*
	 将一个动作插入动作链表中
*/
LIMB_ACTION_NODE* ROBOT_insert_action(LIMB_ACTION *pAction);

//更新动作链表
void ROBOT_init_list(void);

//更新所有的电机状态
U8	ROBOT_update_state(void);


#endif
