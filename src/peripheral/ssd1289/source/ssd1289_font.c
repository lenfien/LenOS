
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
	5, 			//�о�
	2,  		//�о�
	0xFFFF, //��ɫǰ��(Ĭ��)
	0,      //��ɫ����
	FONT_ASCII_8x16
};

//******************************����ĺ��������������********************************/

/*
����fontType���������������x,y����ʾ����ַ�c
	��ʾ�ַ�
	�����ʾ������ᳬ����Ļ�߽� ����ʾ ������0
	����ֵ:
		-2:	��ʾʧ��,xԽ��
		-3: ��ʾʧ��,yԽ��
		-1: ��ʾ�ɹ�
		c:	��ʾ�ɹ���ת���ַ�
*/
S8	LCD_print_char(S16 x, S16 y, char c, FONT_TYPE fontType)
{
	
	
	//	������ԶԿɱ��͹̶�����ַ���ȡ��Ϣ
	
	PFONT pFont = FONT_get_font_info(c, fontType);      	//����fontType��ȡ����ַ�����Ϣ
	
	if(x < 0)
		x = 0;
	
	if(y < 0)
		y = 0;
	
	if(pFont->pChar == 0)									//����ַ����ڿ����ַ���Χ�ڸ��ַ�
		return c;
	
	if((x + pFont->fontWidth > SCREEN_SIZE_X))   			//�����ʾ������ᳬ����Ļ�߽� ����ʾ ������-2,-3
		return -2;
	
	if((y + pFont->fontHigh) > SCREEN_SIZE_Y)
		return -3;
	
	
	if(pFont->pLib->align == ALIGN_LEFT)         			//����ַ����ݸ�ʽΪ�����(һ�㶼Ϊ�����)
	{
		 SSD1289_draw_font_left_align(pFont->fontWidth,  		//���
										pFont->fontHigh,     	//�߶�
										x, y,                   //����
										FontFormat.color, FontFormat.backColor,	//ǰ���ͱ���ɫ 
										pFont->pChar);        	//����λ��
	}	
	else                                  //����ַ����ݸ�ʽΪ�Ҷ���
	{
		SSD1289_draw_font_right_align(pFont->fontWidth,  		//���
										pFont->fontHigh,    	//�߶�
										x, y,                   //����
										FontFormat.color, FontFormat.backColor,	//ǰ���ͱ���ɫ 
										pFont->pChar);
	}
         
	return -1;
	
}


/*
	���һ���ַ���(�ɰ����κ�ת���ַ�)
	ֻ֧��ANCI��
*/
void LCD_print_string(U16 xStart, U16 yStart, char *str, FONT_TYPE fontType)
{
	char c;
	int x = xStart;
	int y = yStart;
	FONT font;
	FONT_LIB fontLib;
	U8 is_variable_width = FONT_get_lib_info(fontType)->widthType == WIDTH_VARIABLE;
	
	//if(!is_variable_width)  						//����ǵȿ�����
	{
		fontLib = *FONT_get_lib_info(fontType);		//��ȡ���ַ�����Ϣ
	    font.fontWidth = fontLib.fontWidth;
		font.fontHigh = fontLib.fontHigh;
	}
	
	while(0 != (c = *str))
	{
		if(c >= 127 || c <=7 )
			return;
		if(is_variable_width)		//����ǿɱ���ַ���ÿһ�ζ�Ҫ��ȡ���ַ���������Ϣ
			font = *FONT_get_font_info(c, fontType);     
		switch(LCD_print_char(x, y, c, fontType))
		{
			case -2:     	//xԽ��
				x = 0;
				y += (font.fontHigh + FontFormat.lineSpacing);
				break;
			case -3:		//yԽ��
				x = 0;
				y = 0;
				break;
			case -4:		//�ڿ���δ�ҵ��õ�����Ϣ
				//while(1);
				break;
			case -1:		//������ʾ
				x += (font.fontWidth + FontFormat.rowSpacing);
				str++;
				break;
			case '\n':      //���з�
				y += ((!is_variable_width)?font.fontHigh:fontLib.fontHigh + FontFormat.lineSpacing);
				x = 0;
				str++;
				break;
			case '\t':      //�Ʊ��
				x += (font.fontWidth + FontFormat.rowSpacing) * 3;
				str++;
				break;
			case '\v':      //��ֱ�Ʊ�
				y += ((font.fontHigh + FontFormat.lineSpacing) * 3) % SCREEN_SIZE_Y;
				str++;
				break;
			case '\b':      //�˸��
				if((x - ((int)font.fontWidth + FontFormat.rowSpacing)) >= 0)
					x -= (font.fontWidth + FontFormat.rowSpacing);
				str++;
				break;
			case '\0':     //���ַ�
				str++;	
				break;
			case '\r':     //�س���
				x = 0;
				str++;
				break;
			default:
				break;
		}
	}
}

/*
	ʹ��Ĭ�ϵ��ֿ�
	printf�÷�һ������ֻ֧��ANCI�ַ���
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
	//������һ�ε���ʾ����,��LCD_clear_pre_printʹ��
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


//�����һ�ε���ʾ���Ϊ����ɫ
void LCD_clear_pre_print()
{
	U32 preColor = LCD_set_font_color(BACKGROUND_COLOR);
	U32 preBackColor = LCD_set_font_backColor(BACKGROUND_COLOR);
	LCD_print_string(preX, preY, buffer, FontFormat.fontType);
	LCD_set_font_color(preColor);
	LCD_set_font_backColor(preBackColor);
}
