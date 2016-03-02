


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


//------------------------------------按键全局变量定义开始-----------------------------//

/*
	pButtonList中包含了现在正在显示器上显示的所有按键信息,
	通过链表实现了这些按键之间的索引。
	需要注意的是:只有按键显示在屏幕上后，按钮的信息才会加到这个链表中.
	具体的实现细节参看文档:button_list.c
*/
BUTTON_LIST* PButtonList = null;			//所有的BUTTON 都将存贮在这个链表中

//************************************按键全局变量定义结束**************************//

//------------------------------------按键初始化区域开始-----------------------------//
//初始化链表
BUTTON_LIST* BUTTON_init()
{
	return PButtonList = BTNLIST_create_list();
}
//************************************按键初始化区域结束****************************//

//------------------------------------按键基本操作区开始-----------------------------//

/*
	按照参数给定的信息创建一个按钮，并将其指针返回出来
	函数可能会执行失败:
				内存不足以创建该按钮
*/
BUTTON* BUTTON_create_button(int buttonWidth, //宽
							int buttonHigh,  //高
							U32 buttonColor, //背景颜色
							char* content,   //内容
							U32 fontColor,   //字体颜色
							void (*clickHanler)(BUTTON*), 			//点击处理函数:在按钮点击一下时执行
							void (*holdHandler)(POINT *p, BUTTON*),	//保持处理函数:在按钮保持按下时执行
							void (*releaseHandler)(BUTTON*)		//释放处理函数:在按钮释放时执行(执行后被清零)
							)
{
	BUTTON* pButton = (BUTTON*)malloc(sizeof(BUTTON));
	U16 fontWidth = FONT_get_string_width(content, FontFormat.fontType);				//获得字符串的宽度
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //获得字体的高度

	if(pButton == null)					//如果内存不足，则返回0
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
	按照pButton描述的方式显示一个button
		在函数执行过程中，带入的按键的宽和高可能会被改变
			当文字要求的宽度或高度大于按钮提供的宽度或高度时，按钮的宽度或高度会增加到文字的宽度或高度
		在函数执行过程中，按键的xStart和yStart属性会被初始化
		如果函数成功的将按钮绘制到屏幕上，则同时将该按钮添加到按钮链表中
		函数可能会绘制按键失败:	按键的要求宽度或高度与其显示位置的综合使按钮显示在了屏幕之外.
*/
BUTTON* BUTTON_draw_button(U32 xStart, U32 yStart, BUTTON *pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//获得字符串的宽度
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //获得字体的高度
	
	U32 oldColor; 		//旧颜色
	U32 oldBackColor;   //新颜色

	pButton->xStart = xStart;
	pButton->yStart = yStart;
	//pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth + 10: pButton->buttonWidth;
	//pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh + 10:pButton-> buttonHigh;
	
	//如果指定的位置导致按钮会被显示在屏幕外面,则不显示，并返回0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(xStart, yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//设置新颜色，保存旧颜色
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//设置新背景色,保存旧背景色
	
	xStart = xStart + (pButton->buttonWidth - fontWidth)/2;    			//获得字体的x起始显示位置
	yStart = yStart + (pButton->buttonHigh - fontHigh)/2;				//获得字体的y起始显示位置
	
	LCD_printf(xStart, yStart, pButton->content);       //显示文字
	LCD_set_font_backColor(oldBackColor);								//恢复原来的字体背景色
	LCD_set_font_color(oldColor);                       //恢复原来的字体颜色

	//如果显示成功,则将该按键加入到按键链表中
	if(PButtonList == null)
		BUTTON_init();
	
	BTNLIST_insert_button(pButton, PButtonList);
	
	return pButton;										//返回这个按键
}

/*
	只重新绘制一个Button，这个Button必须是曾经绘制会过的
*/
BUTTON* BUTTON_redraw_button(BUTTON *pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//获得字符串的宽度
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //获得字体的高度
	
	U32 oldColor; 		//旧颜色
	U32 oldBackColor;   //新颜色
	U16 xStart;
	U16 yStart;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//设置新颜色，保存旧颜色
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//设置新背景色,保存旧背景色
	
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;    			//获得字体的x起始显示位置
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;				//获得字体的y起始显示位置
	
	LCD_printf(xStart, yStart, pButton->content);       //显示文字
	LCD_set_font_backColor(oldBackColor);								//恢复原来的字体背景色
	LCD_set_font_color(oldColor);                       //恢复原来的字体颜色

	return pButton;										//返回这个按键
}

/*
	绘制一个按钮的按下效果
*/
BUTTON* BUTTON_draw_press_effect(BUTTON* pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//获得字符串的宽度
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //获得字体的高度
	
	U32 oldColor; 		//旧颜色
	U32 oldBackColor;   //新颜色
	
	U16 xStart;
	U16 yStart;
	
	pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth : pButton->buttonWidth;
	pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh :pButton-> buttonHigh;
	
	//如果指定的位置导致按钮会被显示在屏幕外面,则不显示，并返回0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								~pButton->buttonColor);
	
	oldColor = LCD_set_font_color(~pButton->fontColor);  				//设置新颜色，保存旧颜色
	oldBackColor = LCD_set_font_backColor(~pButton->buttonColor);		//设置新背景色,保存旧背景色
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;   	//获得字体的x起始显示位置
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;		//获得字体的y起始显示位置
	
	LCD_printf(xStart, yStart, pButton->content);       //显示文字
	LCD_set_font_backColor(oldBackColor);				//恢复原来的字体背景色
	LCD_set_font_color(oldColor);                       //恢复原来的字体颜色
	
	return pButton;										//返回这个按键
}

/*
	绘制一个按钮的弹起效果
*/
BUTTON* BUTTON_draw_release_effect(BUTTON* pButton)
{
	U16 fontWidth = FONT_get_string_width(pButton->content, FontFormat.fontType);				//获得字符串的宽度
	U16 fontHigh  = FONT_get_lib_info(FontFormat.fontType)->fontHigh;                           //获得字体的高度
	
	U32 oldColor; 		//旧颜色
	U32 oldBackColor;   //新颜色
	
	U16 xStart;
	U16 yStart;
	
	pButton->buttonWidth = fontWidth > pButton->buttonWidth ? fontWidth : pButton->buttonWidth;
	pButton->buttonHigh = fontHigh > pButton->buttonHigh ? fontHigh :pButton-> buttonHigh;
	
	//如果指定的位置导致按钮会被显示在屏幕外面,则不显示，并返回0
	if(pButton->xStart+pButton->buttonWidth > SCREEN_SIZE_X || pButton->yStart + pButton->buttonHigh > SCREEN_SIZE_Y)
		return null;
	
	LCD_draw_rectangle(pButton->xStart, pButton->yStart, 
						pButton->buttonWidth, 
							pButton->buttonHigh, 
								pButton->buttonColor);
	
	oldColor = LCD_set_font_color(pButton->fontColor);  				//设置新颜色，保存旧颜色
	oldBackColor = LCD_set_font_backColor(pButton->buttonColor);		//设置新背景色,保存旧背景色
	xStart = pButton->xStart + (pButton->buttonWidth - fontWidth)/2;    			//获得字体的x起始显示位置
	yStart = pButton->yStart + (pButton->buttonHigh - fontHigh)/2;				//获得字体的y起始显示位置
	
	LCD_printf(xStart, yStart, pButton->content);       //显示文字
	LCD_set_font_backColor(oldBackColor);				//恢复原来的字体背景色
	LCD_set_font_color(oldColor);                       //恢复原来的字体颜色
	
	return pButton;	
}

/*
	根据button的当前状态更新按下或弹起效果
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

//***********************************按键基本操作区结束**********************************//



//-----------------------------------链表相关的按键操作开始---------------------------------//
/*
	更新链表里所有的按键的状态
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
	执行Button的处理事件
	如果Button的颜色和背景颜色不同则更新按下效果
	如果不想让Button有按下效果，则将其颜色指定为屏幕的背景颜色
		屏幕的背景颜色在ScreenState里定义
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



//***********************************链表相关的按键操作结束****************************//




//-----------------------------------综合功能的函数-----------------------------------//
//将该函数加入到外部中断7服务段中可以加入按键功能
void BUTTON_process()
{
	BUTTON_update_states();
	BUTTON_execute_handlers();
}


//***********************************综合功能的函数***********************************//




//-----------------------------------按键测试部分-------------------------------------//
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






//***********************************按键测试部分*************************************//



