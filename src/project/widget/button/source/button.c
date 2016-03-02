


#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "base_gpio.h"

#include "base_usart.h"

#include "ssd1289_base.h"
#include "ssd1289_type.h"
#include "ssd1289_graphic.h"
#include "ssd1289_configure.h"
#include "ssd1289_font.h"

#include "ads7483_base.h"
#include "ads7483_button.h"

#include "com.h"

#include "font_lib.h"
#include "font_operation.h"
#include "ads7483_type.h"

#include "button_list.h"


//------------------------------------����ȫ�ֱ������忪ʼ-----------------------------//

/*
	pButtonList�а���������������ʾ������ʾ�����а�����Ϣ,
	ͨ������ʵ������Щ����֮���������
	��Ҫע�����:ֻ�а�����ʾ����Ļ�Ϻ󣬰�ť����Ϣ�Ż�ӵ����������.
	�����ʵ��ϸ�ڲο��ĵ�:button_list.c
*/
BUTTON_LIST* PButtonList = null;			//���е�BUTTON �������������������

//************************************����ȫ�ֱ����������**************************//

//------------------------------------������ʼ������ʼ-----------------------------//
//��ʼ������
BUTTON_LIST* BUTTON_init()
{
	return PButtonList = BTNLIST_create_list();
}
//************************************������ʼ���������****************************//

//------------------------------------����������������ʼ-----------------------------//

/*
	���ղ�����������Ϣ����һ����ť��������ָ�뷵�س���
	�������ܻ�ִ��ʧ��:
				�ڴ治���Դ����ð�ť
*/
BUTTON* BUTTON_create_button(int buttonWidth, //��
							int buttonHigh,  //��
							U32 buttonColor, //������ɫ
							char* content,   //����
							U32 fontColor,   //������ɫ
							void (*clickHanler)(BUTTON*), 			//���������:�ڰ�ť���һ��ʱִ��
							void (*holdHandler)(POINT *p, BUTTON*),	//���ִ�����:�ڰ�ť���ְ���ʱִ��
							void (*releaseHandler)(BUTTON*)		//�ͷŴ�����:�ڰ�ť�ͷ�ʱִ��(ִ�к�����)
							)
{
	BUTTON* pButton = (BUTTON*)malloc(sizeof(BUTTON));
	U16 fontWidth = FONT_get_string_width(content, FontFormat.fontType);				//����ַ����Ŀ��
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //�������ĸ߶�

	if(pButton == null)					//����ڴ治�㣬�򷵻�0
		return 0;
	
	pButton->buttonWidth = fontWidth > buttonWidth ? fontWidth + 3: buttonWidth;
	pButton->buttonHigh = fontHigh > buttonHigh ? fontHigh + 3:buttonHigh;
	
	pButton->buttonColor = buttonColor;
	if(content != null)
		strcpy(pButton->content, content);
	
	pButton->fontColor = fontColor;
	pButton->clickHandler = clickHanler;
	pButton->holdHandler = holdHandler;
	pButton->releaseHandler = releaseHandler;
	//pButton->isEnabled = 1;
	//pButton->wasPressed = 0;
	
	return pButton;
}


/*
	����pButton�����ķ�ʽ��ʾһ��button
		�ں���ִ�й����У�����İ����Ŀ�͸߿��ܻᱻ�ı�
			������Ҫ��Ŀ�Ȼ�߶ȴ��ڰ�ť�ṩ�Ŀ�Ȼ�߶�ʱ����ť�Ŀ�Ȼ�߶Ȼ����ӵ����ֵĿ�Ȼ�߶�
		�ں���ִ�й����У�������xStart��yStart���Իᱻ��ʼ��
		��������ɹ��Ľ���ť���Ƶ���Ļ�ϣ���ͬʱ���ð�ť��ӵ���ť������
		�������ܻ���ư���ʧ��:	������Ҫ���Ȼ�߶�������ʾλ�õ��ۺ�ʹ��ť��ʾ������Ļ֮��.
*/
BUTTON* BUTTON_draw_button(U32 xStart, U32 yStart, BUTTON *pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//����ַ����Ŀ��
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //�������ĸ߶�
	
	U32 oldColor; 		//����ɫ
	U32 oldBackColor;   //����ɫ

	pButton->xStart = xStart;
	pButton->yStart = yStart;
	//pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth + 10: pButton->buttonWidth;
	//pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh + 10:pButton-> buttonHigh;
	
	//���ָ����λ�õ��°�ť�ᱻ��ʾ����Ļ����,����ʾ��������0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(xStart, yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//��������ɫ���������ɫ
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//�����±���ɫ,����ɱ���ɫ
	
	xStart = xStart + (pButton->buttonWidth - fontWidth)/2;    			//��������x��ʼ��ʾλ��
	yStart = yStart + (pButton->buttonHigh - fontHigh)/2;				//��������y��ʼ��ʾλ��
	
	LCD_printf(xStart, yStart, pButton->content);       //��ʾ����
	LCD_set_font_backColor(oldBackColor);								//�ָ�ԭ�������屳��ɫ
	LCD_set_font_color(oldColor);                       //�ָ�ԭ����������ɫ

	//�����ʾ�ɹ�,�򽫸ð������뵽����������
	if(PButtonList == null)
		BUTTON_init();
	
	BTNLIST_insert_button(pButton, PButtonList);
	
	return pButton;										//�����������
}

/*
	ֻ���»���һ��Button�����Button�������������ƻ����
*/
BUTTON* BUTTON_redraw_button(BUTTON *pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//����ַ����Ŀ��
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //�������ĸ߶�
	
	U32 oldColor; 		//����ɫ
	U32 oldBackColor;   //����ɫ
	U16 xStart;
	U16 yStart;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//��������ɫ���������ɫ
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//�����±���ɫ,����ɱ���ɫ
	
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;    			//��������x��ʼ��ʾλ��
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;				//��������y��ʼ��ʾλ��
	
	LCD_printf(xStart, yStart, pButton->content);       //��ʾ����
	LCD_set_font_backColor(oldBackColor);								//�ָ�ԭ�������屳��ɫ
	LCD_set_font_color(oldColor);                       //�ָ�ԭ����������ɫ

	return pButton;										//�����������
}

/*
	����һ����ť�İ���Ч��
*/
BUTTON* BUTTON_draw_press_effect(BUTTON* pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//����ַ����Ŀ��
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //�������ĸ߶�
	
	U32 oldColor; 		//����ɫ
	U32 oldBackColor;   //����ɫ
	
	U16 xStart;
	U16 yStart;
	
	pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth : pButton->buttonWidth;
	pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh :pButton-> buttonHigh;
	
	//���ָ����λ�õ��°�ť�ᱻ��ʾ����Ļ����,����ʾ��������0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								~pButton->buttonColor);
	
	oldColor = LCD_set_font_color(~pButton->fontColor);  				//��������ɫ���������ɫ
	oldBackColor = LCD_set_font_backColor(~pButton->buttonColor);		//�����±���ɫ,����ɱ���ɫ
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;   	//��������x��ʼ��ʾλ��
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;		//��������y��ʼ��ʾλ��
	
	LCD_printf(xStart, yStart, pButton->content);       //��ʾ����
	LCD_set_font_backColor(oldBackColor);				//�ָ�ԭ�������屳��ɫ
	LCD_set_font_color(oldColor);                       //�ָ�ԭ����������ɫ
	
	return pButton;										//�����������
}

/*
	����һ����ť�ĵ���Ч��
*/
BUTTON* BUTTON_draw_release_effect(BUTTON* pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//����ַ����Ŀ��
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //�������ĸ߶�
	
	U32 oldColor; 		//����ɫ
	U32 oldBackColor;   //����ɫ
	
	U16 xStart;
	U16 yStart;
	
	pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth : pButton->buttonWidth;
	pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh :pButton-> buttonHigh;
	
	//���ָ����λ�õ��°�ť�ᱻ��ʾ����Ļ����,����ʾ��������0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//��������ɫ���������ɫ
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//�����±���ɫ,����ɱ���ɫ
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;    			//��������x��ʼ��ʾλ��
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;				//��������y��ʼ��ʾλ��
	
	LCD_printf(xStart, yStart, pButton->content);       //��ʾ����
	LCD_set_font_backColor(oldBackColor);				//�ָ�ԭ�������屳��ɫ
	LCD_set_font_color(oldColor);                       //�ָ�ԭ����������ɫ
	
	return pButton;	
}

/*
	����button�ĵ�ǰ״̬���°��»���Ч��
*/
void BUTTON_update_press_effect(BUTTON* pButton)
{
	//
	if(pButton->isPressed && !pButton->pressEffect)
	{
		BUTTON_draw_press_effect(pButton);
		pButton->pressEffect = 1;
		return ;
	}
	
	if(pButton->isRelease && pButton->pressEffect)
	{
		BUTTON_draw_release_effect(pButton);
		pButton->pressEffect = 0;
		return;
	}
}

//***********************************������������������**********************************//



//-----------------------------------������صİ���������ʼ---------------------------------//
/*
	�������������еİ�����״̬
*/
void BUTTON_update_states()
{
	PBTNNODE pNode = PButtonList->pHead; 
	if(PButtonList == null)
		return;
	
	while(pNode)
	{
		ADS7483_BUTTON_update_state(pNode->pButton);
		pNode = pNode ->pNext;
	}
}

void BUTTON_update_press_effects()
{
	/*
	PBTNNODE pNode = PButtonList->pHead; 
	if(PButtonList == null)
		return;
	
	while(pNode)
	{
		BUTTON_update_press_effect(pNode->pButton);
		pNode = pNode ->pNext;
	}
	*/
}


/*
	ִ��Button�Ĵ����¼�
	���Button����ɫ�ͱ�����ɫ��ͬ����°���Ч��
	���������Button�а���Ч����������ɫָ��Ϊ��Ļ�ı�����ɫ
		��Ļ�ı�����ɫ��ScreenState�ﶨ��
*/
void BUTTON_execute_handlers()
{
	PBTNNODE pNode = PButtonList->pHead;
	
	if(PButtonList == null)
		return;
	
	while(pNode)
	{
			if(pNode->pButton->buttonColor != ScreenState.backgroundColor)
				BUTTON_update_press_effect(pNode->pButton);
			ADS7483_BUTTON_execute_handler(pNode->pButton);
			
		pNode = pNode->pNext;
	}
}

void BUTTON_enable_button(BUTTON* pBtn)
{
	
}



//***********************************������صİ�����������****************************//




//-----------------------------------�ۺϹ��ܵĺ���-----------------------------------//
//���ú������뵽�ⲿ�ж�7������п��Լ��밴������
void BUTTON_process()
{
	BUTTON_update_states();
	BUTTON_execute_handlers();
}


//***********************************�ۺϹ��ܵĺ���***********************************//




//-----------------------------------�������Բ���-------------------------------------//
void BUTTON_btn1_click_handler(BUTTON* pBtn)
{
	static int time = 0;
	time++;
	LCD_printf(0, 0, "bt1 click times :%d", time);
}

void BUTTON_btn1_hold_handler(POINT* pPoint, BUTTON* pBtn)
{
	LCD_printf(0, 20, "btn1 hold point: [%3d, %3d]", pPoint->x, pPoint->y);
}

void BUTTON_btn2_click_handler(BUTTON* pBtn)
{
	static int time = 0;
	time++;
	LCD_printf(0, 50, "btn2 click times:%d", time);
}

void BUTTON_btn2_hold_handler(POINT* pPoint, BUTTON* pBtn)
{
	LCD_printf(0, 80, "btn1 hold point: [%3d, %3d]", pPoint->x, pPoint->y);
}

void BUTTON_test()
{
	PBUTTON pBtn1;
	PBUTTON pBtn2;
	
	pBtn1 = BUTTON_create_button(50, 30, 0xFFFF, "OK", RGB_BLACK, BUTTON_btn1_click_handler, BUTTON_btn1_hold_handler, 0);
	pBtn2 = BUTTON_create_button(50, 30, 0xFFFF, "Cancel", RGB_BLACK, BUTTON_btn2_click_handler, BUTTON_btn2_hold_handler, 0);
	
	BUTTON_draw_button(20, 100, pBtn1);
	BUTTON_draw_button(80, 100, pBtn2);
}






//***********************************�������Բ���*************************************//



