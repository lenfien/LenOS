
#ifndef __BUTTON_TYPE
#define __BUTTON_TYPE

#include "ssd1289_type.h"
typedef struct tagButton
{
	//������Ϣ
	S16 xStart;
	S16 yStart;
	S16 buttonWidth;
	S16 buttonHigh;
	U32 buttonColor;
	char content[15];
	U32 fontColor;
	
	void (*clickHandler)(struct tagButton*);
	void (*holdHandler)(POINT* p, struct tagButton*);
	void (*releaseHandler)(struct tagButton*);
	
	//����״̬
	U8 isHold;		//�����Ƿ񱣳�
	U8 isPressed;	//�Ƿ���
	U8 isRelease;	//�Ƿ��ͷ�
	U8 pressEffect;		// =0 ���� =1����
	
	//���ý��
	U8 isEnabled;		//=0 =1 ��־�ð�ť�Ƿ���Ч
	U8 wasPressed;	//�Ƿ�����������,��һ�㷢����isEnabled = 0ʱ
}BUTTON;

typedef BUTTON* PBUTTON;

//����ڵ㶨��
typedef struct tagButtonNode
{
	struct tagButtonNode *pPre;
	struct tagButtonNode *pNext;
	BUTTON *pButton;
}BUTTON_NODE;

typedef BUTTON_NODE* PBUTTON_NODE;
typedef PBUTTON_NODE PBTNNODE;

//����ṹ����
typedef struct
{
	BUTTON_NODE* pHead;
	BUTTON_NODE* pEnd;
	int num;
}BUTTON_LIST;

typedef BUTTON_LIST*	PBUTTON_LIST;
typedef PBUTTON_LIST	PBTNLIST;


#endif
