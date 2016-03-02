

#ifndef __BUTTON_LIST
#define __BUTTON_LIST

#include "button_type.h"


/*
	创建一个按钮的链表
	如果内存不足，返回0
	否则返回创建好的的链表指针
	
*/
BUTTON_LIST* BTNLIST_create_list(void);


/*
	将创建好的button以参数带进这个函数，第二个参数为链表，
	这个button将加入这个list中.
*/
BUTTON* BTNLIST_insert_button(BUTTON* pButton, BUTTON_LIST* pList);


//从按钮链表中找到pButton所在的节点,并删除它
//删除失败返回0 否则返回1
U8 BTNLIST_delete_button(BUTTON* pButton, BUTTON_LIST* pList);

#endif
