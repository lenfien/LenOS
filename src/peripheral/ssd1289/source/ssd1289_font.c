
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "ssd1289_base.h"
#include "ssd1289_type.h"
#include "ssd1289_configure.h"

#include "com.h"

#include "font_operation.h"
#include "font_lib.h"

LCD_FONT_FORMAT FontFormat = 
{
	5, 			//行距
	2,  		//列距
	0xFFFF, //白色前景(默认)
	0,      //黑色背景
	FONT_ASCII_8x16
};

//******************************下面的函数用来输出文字********************************/

/*
根据fontType定义的字体类型在x,y处显示这个字符c
	显示字符
	如果显示的字体会超过屏幕边界 则不显示 并返回0
	返回值:
		-2:	显示失败,x越界
		-3: 显示失败,y越界
		-1: 显示成功
		c:	显示成功，转义字符
*/
S8	LCD_print_char(S16 x, S16 y, char c, FONT_TYPE fontType)
{
	
	
	//	这里可以对可变宽和固定宽度字符获取信息
	
	PFONT pFont = FONT_get_font_info(c, fontType);      	//根据fontType获取这个字符的信息
	
	if(x < 0)
		x = 0;
	
	if(y < 0)
		y = 0;
	
	if(pFont->pChar == 0)									//如果字符不在可视字符范围内该字符
		return c;
	
	if((x + pFont->fontWidth > SCREEN_SIZE_X))   			//如果显示的字体会超过屏幕边界 则不显示 并返回-2,-3
		return -2;
	
	if((y + pFont->fontHigh) > SCREEN_SIZE_Y)
		return -3;
	
	
	if(pFont->pLib->align == ALIGN_LEFT)         			//如果字符数据格式为左对齐(一般都为左对齐)
	{
		 SSD1289_draw_font_left_align(pFont->fontWidth,  		//宽度
										pFont->fontHigh,     	//高度
										x, y,                   //坐标
										FontFormat.color, FontFormat.backColor,	//前景和背景色 
										pFont->pChar);        	//点阵位置
	}	
	else                                  //如果字符数据格式为右对齐
	{
		SSD1289_draw_font_right_align(pFont->fontWidth,  		//宽度
										pFont->fontHigh,    	//高度
										x, y,                   //坐标
										FontFormat.color, FontFormat.backColor,	//前景和背景色 
										pFont->pChar);
	}
         
	return -1;
	
}


/*
	输出一个字符串(可包含任何转义字符)
	只支持ANCI码
*/
void LCD_print_string(U16 xStart, U16 yStart, char *str, FONT_TYPE fontType)
{
	char c;
	int x = xStart;
	int y = yStart;
	FONT font;
	FONT_LIB fontLib;
	U8 is_variable_width = FONT_get_lib_info(fontType)->widthType == WIDTH_VARIABLE;
	
	//if(!is_variable_width)  						//如果是等宽字体
	{
		fontLib = *FONT_get_lib_info(fontType);		//获取该字符的信息
	    font.fontWidth = fontLib.fontWidth;
		font.fontHigh = fontLib.fontHigh;
	}
	
	while(0 != (c = *str))
	{
		if(c >= 127 || c <=7 )
			return;
		if(is_variable_width)		//如果是可变宽字符，每一次都要获取该字符的字体信息
			font = *FONT_get_font_info(c, fontType);     
		switch(LCD_print_char(x, y, c, fontType))
		{
			case -2:     	//x越界
				x = 0;
				y += (font.fontHigh + FontFormat.lineSpacing);
				break;
			case -3:		//y越界
				x = 0;
				y = 0;
				break;
			case -4:		//在库中未找到该点阵信息
				//while(1);
				break;
			case -1:		//正常显示
				x += (font.fontWidth + FontFormat.rowSpacing);
				str++;
				break;
			case '\n':      //换行符
				y += ((!is_variable_width)?font.fontHigh:fontLib.fontHigh + FontFormat.lineSpacing);
				x = 0;
				str++;
				break;
			case '\t':      //制表符
				x += (font.fontWidth + FontFormat.rowSpacing) * 3;
				str++;
				break;
			case '\v':      //垂直制表
				y += ((font.fontHigh + FontFormat.lineSpacing) * 3) % SCREEN_SIZE_Y;
				str++;
				break;
			case '\b':      //退格符
				if((x - ((int)font.fontWidth + FontFormat.rowSpacing)) >= 0)
					x -= (font.fontWidth + FontFormat.rowSpacing);
				str++;
				break;
			case '\0':     //空字符
				str++;	
				break;
			case '\r':     //回车符
				x = 0;
				str++;
				break;
			default:
				break;
		}
	}
}

/*
	使用默认的字库
	printf用法一样，但只支持ANCI字符集
*/

U16 preX;
U16 preY;
char buffer[128];
int LCD_printf(U16 x, U16 y, char *format, ...)
{
	int num;
	va_list list;
	va_start(list, format);
	num = vsprintf(buffer, format, list);
	va_end(list);
	
	LCD_print_string(x, y , buffer, FontFormat.fontType);
	//保留上一次的显示坐标,给LCD_clear_pre_print使用
	preX = x;
	preY = y;
	return num;
}


int CMD_printf(const char *format, ...)
{
	int num;
	int len;
	static int line = 0;
	const FONT_LIB* pFontLib =  FONT_get_lib_info((FontFormat.fontType));
	int ScreenLines = SCREEN_HIGH/(pFontLib->fontHigh + FontFormat.lineSpacing);
	
	va_list args;
	va_start(args, format);
	num = vsprintf(buffer, format, args);
	va_end(args);
	
	if(line + 1 > ScreenLines)
	{
		line = line % ScreenLines;
		LCD_clear_screen(ScreenState.backgroundColor);
	}
	
	FONT_printf(0, line, buffer);
	len = FONT_get_string_width(buffer, FontFormat.fontType);
	line = (line + (len / SCREEN_WIDTH) + 1 );
	
	return num;
}


//清除上一次的显示结果为背景色
void LCD_clear_pre_print()
{
	U32 preColor = LCD_set_font_color(BACKGROUND_COLOR);
	U32 preBackColor = LCD_set_font_backColor(BACKGROUND_COLOR);
	LCD_print_string(preX, preY, buffer, FontFormat.fontType);
	LCD_set_font_color(preColor);
	LCD_set_font_backColor(preBackColor);
}
