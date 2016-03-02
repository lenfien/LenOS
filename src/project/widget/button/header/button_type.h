
#ifndef __BUTTON_TYPE
#define __BUTTON_TYPE

#include "ssd1289_type.h"
typedef struct tagButton
{
	//按键信息
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
	
	//按键状态
	U8 isHold;		//按下是否保持
	U8 isPressed;	//是否按下
	U8 isRelease;	//是否被释放
	U8 pressEffect;		// =0 弹起 =1按下
	
	//禁用解禁
	U8 isEnabled;		//=0 =1 标志该按钮是否有效
	U8 wasPressed;	//是否曾经被按下,这一般发生在isEnabled = 0时
}BUTTON;

typedef BUTTON* PBUTTON;

//链表节点定义
typedef struct tagButtonNode
{
	struct tagButtonNode *pPre;
	struct tagButtonNode *pNext;
	BUTTON *pButton;
}BUTTON_NODE;

typedef BUTTON_NODE* PBUTTON_NODE;
typedef PBUTTON_NODE PBTNNODE;

//链表结构定义
typedef struct
{
	BUTTON_NODE* pHead;
	BUTTON_NODE* pEnd;
	int num;
}BUTTON_LIST;

typedef BUTTON_LIST*	PBUTTON_LIST;
typedef PBUTTON_LIST	PBTNLIST;


#endif
