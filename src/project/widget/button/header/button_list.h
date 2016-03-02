

#ifndef __BUTTON_LIST
#define __BUTTON_LIST

#include "button_type.h"


/*
	����һ����ť������
	����ڴ治�㣬����0
	���򷵻ش����õĵ�����ָ��
	
*/
BUTTON_LIST* BTNLIST_create_list(void);


/*
	�������õ�button�Բ�����������������ڶ�������Ϊ����
	���button���������list��.
*/
BUTTON* BTNLIST_insert_button(BUTTON* pButton, BUTTON_LIST* pList);


//�Ӱ�ť�������ҵ�pButton���ڵĽڵ�,��ɾ����
//ɾ��ʧ�ܷ���0 ���򷵻�1
U8 BTNLIST_delete_button(BUTTON* pButton, BUTTON_LIST* pList);

#endif
