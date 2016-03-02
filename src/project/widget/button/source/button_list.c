

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ssd1289_type.h"
#include "ssd1289_graphic.h"
#include "ssd1289_configure.h"
#include "ssd1289_font.h"

#include "ads7483_base.h"
#include "ads7483_button.h"

#include "com.h"

#include "button_list.h"


/*
	创建一个按钮的链表
	如果内存不足，返回0
	否则返回创建好的的链表指针
	
*/
BUTTON_LIST* BTNLIST_create_list()
{
	BUTTON_LIST* pList = (BUTTON_LIST*)malloc(sizeof(BUTTON_LIST));
	
	if(pList == null)
		return null;
	
	pList->num = 0;
	pList->pHead = null;
	pList->pEnd = null;
	
	return pList;
}


/*
	将创建好的button以参数带进这个函数，第二个参数为链表，
	这个button将加入这个list中.
*/
BUTTON* BTNLIST_insert_button(BUTTON* pButton, BUTTON_LIST* pList)
{
	//获得一个按钮信息,并保存在新建的node中
	BUTTON_NODE* pNode = (BUTTON_NODE*)malloc(sizeof(BUTTON_NODE));
	
	pNode->pButton = pButton;

	//开始插入到原始链表
	if(pList->num == 0)	//如果之前链表中没有按钮
	{
		pNode->pPre= 0;
		pNode->pNext = 0;
		pList->pHead = pNode;
		pList->pEnd = pNode;
	}
	else								//如果之前链表中有按钮
	{
		pNode->pNext = 0;
		pNode->pPre = pList->pEnd;
		
		pList->pEnd->pNext = pNode;
		pList->pEnd = pNode;
	}
	pList->num ++;
	
	return (pNode->pButton);
}

//从按钮链表中找到pButton所在的节点,并删除它
//删除失败返回0 否则返回1
U8 BTNLIST_delete_button(BUTTON* pButton, BUTTON_LIST* pList)
{
	BUTTON_NODE *pNode = pList->pHead;
	while(pNode)
	{
		if(pNode->pButton == pButton)	//如果该节点中的按钮的指针和将要被删除的链表的指针相等,则删除
		{
			if(pNode->pPre == null && pNode->pNext == null)
			{
				pList->pHead = null;
				pList->pEnd = null;
			}
			else if(pNode->pPre == null)
			{
				pList->pHead = pNode->pNext;
				pNode->pNext->pPre = null;
			}
				
			else if(pNode ->pNext == null)
			{
				pList->pEnd = pNode->pPre;
				pNode->pPre->pNext = null;
			}
			else
			{
				pNode->pPre->pNext = pNode->pNext;
				pNode->pNext->pPre = pNode->pPre;
			}
			free(pButton);
			free(pNode);
			pList->num --;
			return 1;
		}
		else
		{
			pNode = pNode->pNext;
		}
	}
	return 0;
}


