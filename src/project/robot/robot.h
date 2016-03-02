
#ifndef __ROBOT
#define __ROBOT


//***************************
//������֫���
typedef enum
{
	LLEG,			//����
	RLEG,			//����
	LRWAIST,	//������
	FBWAIST,	//ǰ����
	RARM			//�ұ�
}LIMB;


//ÿ��֫��Ŀ�����Ϣ
typedef struct
{
	LIMB limb;
	GPIO_PORT cport1;		//�����ź�1
	GPIO_PIN	cpin1;			
	GPIO_PORT cport2;		//�����ź�2
	GPIO_PIN  cpin2;
}LIMB_INF;

//������ÿ�������״̬
typedef enum
{
	HALT,	//ֹͣ
	DIRL,	//��ת
	DIRR	//��ת
}MOTOR_ACTION;	//����

//������һ��������״̬ 
typedef enum
{
	NEVER,	//����û�б�ִ��
	GOING,	//����ִ��
	ALREADY	//�Ѿ�ִ�й���
}ACTION_STATE;

typedef struct
{
	LIMB 					limb;					//Ҫ��ִ�ж����ĵ�� 
	MOTOR_ACTION 	action;				//���Ӧ�õ�״̬
	U32						startTime; 		//��ʼʱ��
	U32						delayTime;		//��������ʱ��
	U32						stopTime;			//����ʱ��
	ACTION_STATE 	actionState;	//��ǰ������״̬
}LIMB_ACTION;

typedef struct tagNode
{
	LIMB_ACTION* pLimbAction;
	struct tagNode* pPre;
	struct tagNode* pNext;
}LIMB_ACTION_NODE;

typedef struct
{
	U32 actionNum;	//����������
	LIMB_ACTION_NODE* pHead;
	LIMB_ACTION_NODE* pEnd;
}LIMB_ACTION_LIST;

#define MAX_TIME	800	//����ִ�е����ʱ��Ϊ800,�������800,��������������

extern LIMB_ACTION_LIST* LimbActionList;
extern LIMB_INF LimbsInf[];					//
extern LIMB_ACTION LimbActions[];		//������
extern U32 ROBOT_TIME_COUNTER;	//������ʱ��������
extern U32 LIMB_NUM;						//��ǰ֫�������
extern U32 ACTION_NUM;					//��ǰ��������

/*
	����֫���źͶ�������ִ����Ӧ����
*/
LIMB_INF*	ROBOT_action(LIMB limb, MOTOR_ACTION act);

/*
	 ��һ���������붯��������
*/
LIMB_ACTION_NODE* ROBOT_insert_action(LIMB_ACTION *pAction);

//���¶�������
void ROBOT_init_list(void);

//�������еĵ��״̬
U8	ROBOT_update_state(void);


#endif
