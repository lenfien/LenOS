

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
	����һ����ť������
	����ڴ治�㣬����0
	���򷵻ش����õĵ�����ָ��
	
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
	�������õ�button�Բ�����������������ڶ�������Ϊ����
	���button���������list��.
*/
BUTTON* BTNLIST_insert_button(BUTTON* pButton, BUTTON_LIST* pList)
{
	//���һ����ť��Ϣ,���������½���node��
	BUTTON_NODE* pNode = (BUTTON_NODE*)malloc(sizeof(BUTTON_NODE));
	
	pNode->pButton = pButton;

	//��ʼ���뵽ԭʼ����
	if(pList->num == 0)	//���֮ǰ������û�а�ť
	{
		pNode->pPre= 0;
		pNode->pNext = 0;
		pList->pHead = pNode;
		pList->pEnd = pNode;
	}
	else								//���֮ǰ�������а�ť
	{
		pNode->pNext = 0;
		pNode->pPre = pList->pEnd;
		
		pList->pEnd->pNext = pNode;
		pList->pEnd = pNode;
	}
	pList->num ++;
	
	return (pNode->pButton);
}

//�Ӱ�ť�������ҵ�pButton���ڵĽڵ�,��ɾ����
//ɾ��ʧ�ܷ���0 ���򷵻�1
U8 BTNLIST_delete_button(BUTTON* pButton, BUTTON_LIST* pList)
{
	BUTTON_NODE *pNode = pList->pHead;
	while(pNode)
	{
		if(pNode->pButton == pButton)	//����ýڵ��еİ�ť��ָ��ͽ�Ҫ��ɾ���������ָ�����,��ɾ��
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


