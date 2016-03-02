



#ifndef __SSD1289_FONT
#define __SSD1289_FONT

#include "ssd1289_type.h"

extern LCD_FONT_FORMAT FontFormat;

#define FONT_HIGH					FONT_get_char_high('C', FontFormat.fontType)	//获得一个当前设置字体的字的高度
#define FONT_WIDTH(c)			FONT_get_char_width(c, FontFormat.fontType)		//获得宽度
#define FONTS_WIDTH(str)	FONT_get_string_width(str, FontFormat.fontType)	//获得一个字符串的宽度

//************************************文字相关_开始************************************//					  
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
S8	LCD_print_char(S16 x, S16 y, char c, FONT_TYPE fontType);


/*
	输出一个字符串(可包含任何转义字符)
	只支持ANCI码
*/

void LCD_print_string(U16 xStart, U16 yStart, char *str, FONT_TYPE fontLibType);

/*
	使用默认的字库
	printf用法一样，但只支持ANCI字符集
*/
int LCD_printf(U16 x, U16 y, char *format, ...);

//********************************************//
//**********按DOS方式输出文字*****************//
//第一次调用的时候, 会在屏幕的左上角开始一行,
//第二次调用会在上一次显示的下一行显示,如果屏幕
//满了会自动清屏
//********************************************/
int CMD_printf(const char *format, ...);


//清除上一次的显示结果为背景色
void LCD_clear_pre_print(void);


//************************************文字相关_结束************************************//

#endif

