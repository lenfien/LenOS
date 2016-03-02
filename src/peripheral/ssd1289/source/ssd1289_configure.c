#include <stdio.h>
#include <stdarg.h>

#include "cnf_usart.h"

#include "ssd1289_base.h"
#include "ssd1289_type.h"
#include "ssd1289_font.h"

#include "com.h"

#include "font_operation.h"
#include "font_lib.h"


//**************************下面的函数主要用来设置LCD的显示参数*******************//
//设置行距
int LCD_set_lineSpacing(int lineSpacing)
{
	int temp = FontFormat.lineSpacing;
	if(lineSpacing < SCREEN_SIZE_X && lineSpacing >= 0)
	{
		FontFormat.lineSpacing = lineSpacing;
		return temp;
	}
	
	return -1;	
}

//设置列距
int LCD_set_rowSpacing(int rowSpacing)
{
	int temp = FontFormat.rowSpacing;
	if(rowSpacing < SCREEN_SIZE_X && rowSpacing >= 0)
	{
		FontFormat.rowSpacing = rowSpacing;
		return temp;
	}
	return -1;	
}

//设置文字颜色
U32 LCD_set_font_color(U32 color)
{
	U32 temp = FontFormat.color;

	FontFormat.color = color;
	return temp;
}


//设置文字背景色
U32 LCD_set_font_backColor(U32 backColor)
{
	U32 temp = FontFormat.backColor;

	FontFormat.backColor = backColor;
	return temp;
}

//设置字体
FONT_TYPE LCD_set_font(FONT_TYPE newFont)
{
	FONT_TYPE temp = FontFormat.fontType;
	
	FontFormat.fontType = newFont;
	
	return temp;
}

//设置屏幕背景
U32 LCD_set_screen_backColor(U32 backColor)
{
	U32 temp = ScreenState.backgroundColor;
	ScreenState.backgroundColor = backColor;
	return temp;
}



