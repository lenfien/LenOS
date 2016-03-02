


#ifndef __FONT_OPERATION
#define __FONT_OPERATION

#include "com.h"
#include "font_type.h"

 //************类型定义部分


//************功能定义部分***********//
/*
	根据字库信息，返回c对应到字库中的字体信息
	因为存在可变宽字体
	相同的字库，可能有不同的字体信息
*/
PFONT FONT_get_font_info(char c, FONT_TYPE fontType);



//根据库名称(定义在FONT_LIB_TYPE中),找到该库的详细信息
const FONT_LIB* FONT_get_lib_info(FONT_TYPE fontLibType);


/*
	计算出给定的一个字体的宽度(对于可变宽字体有效)
	只适用于左对齐的字符数据数据
	pFont:指向字符数据的指针
	charAmount: 每一行占用的字符数
	fontHigh:	字符的高度
*/
U32 FONT_get_width(const unsigned char *pFont, U32 charNumPerLine, U32 fontHigh);


//获得一个字符串中可视字符的宽度（点阵宽度，而不是strlen的宽度）
U32 FONT_get_string_width(char *str, FONT_TYPE fontType);


//根据字体的类型得到一个字符的宽度
U32 FONT_get_char_width(char c, FONT_TYPE fontType);


//根据字符的类型获得一个字符的高度
U32 FONT_get_char_high(char c, FONT_TYPE fontType);


/*
基本功能和LCD_printf一样，但这里的行和列是按照字的宽度和高度来分的
line >= 0
cur >= 0
*/


int FONT_printf(U16 x, U16 y, char* format, ...);

PFONT FONT_interface_ascii_8x16_get_font(char c);

#endif
