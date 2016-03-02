

#ifndef __BUTTON
#define __BUTTON

#include "button_type.h"
#include "button_list.h"
//创建一个BUTTON
BUTTON* BUTTON_create_button(int buttonWidth, //宽
							int buttonHigh,  //高
							U32 buttonColor, //背景颜色
							char* content,   //内容
							U32 fontColor,   //字体颜色
							void (*clickHanler)(BUTTON*), 			//点击处理函数:在按钮点击一下时执行
							void (*holdHandler)(POINT *p, BUTTON*),	//保持处理函数:在按钮保持按下时执行
							void (*releaseHandler)(BUTTON*)
							);
							
							
//按照pButton的描述绘制一个Button
//此函数会改变Button的起始位置信息
BUTTON* 	BUTTON_draw_button(U32 xStart, U32 yStart,BUTTON *pButton);

/*
	只重新绘制一个Button，这个Button必须是曾经绘制会过的
*/
BUTTON* BUTTON_redraw_button(BUTTON *pButton);

//将此函数带入外部7中断,可使按键起作用
//注:此函数必须在ADS7483_update_state之后调用
void 		BUTTON_process(void);

extern BUTTON_LIST* PButtonList;

#define BUTTON_delete_button(pButton)	BTNLIST_delete_button(pButton ,PButtonList);

#endif
