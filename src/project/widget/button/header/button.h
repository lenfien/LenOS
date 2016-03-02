

#ifndef __BUTTON
#define __BUTTON

#include "button_type.h"
#include "button_list.h"
//����һ��BUTTON
BUTTON* BUTTON_create_button(int buttonWidth, //��
							int buttonHigh,  //��
							U32 buttonColor, //������ɫ
							char* content,   //����
							U32 fontColor,   //������ɫ
							void (*clickHanler)(BUTTON*), 			//���������:�ڰ�ť���һ��ʱִ��
							void (*holdHandler)(POINT *p, BUTTON*),	//���ִ�����:�ڰ�ť���ְ���ʱִ��
							void (*releaseHandler)(BUTTON*)
							);
							
							
//����pButton����������һ��Button
//�˺�����ı�Button����ʼλ����Ϣ
BUTTON* 	BUTTON_draw_button(U32 xStart, U32 yStart,BUTTON *pButton);

/*
	ֻ���»���һ��Button�����Button�������������ƻ����
*/
BUTTON* BUTTON_redraw_button(BUTTON *pButton);

//���˺��������ⲿ7�ж�,��ʹ����������
//ע:�˺���������ADS7483_update_state֮�����
void 		BUTTON_process(void);

extern BUTTON_LIST* PButtonList;

#define BUTTON_delete_button(pButton)	BTNLIST_delete_button(pButton ,PButtonList);

#endif
