
#include <stdio.h>
#include <stdarg.h>

#include "font_lib.h"
#include "font_operation.h"
#include "com.h"

#include "ssd1289_font.h"
#include "ssd1289_base.h"

//******************辅助类函数**************************//

//根据字体类型，返回c对应的字体信息
PFONT FONT_get_font_info(char c, FONT_TYPE fontType)
{
	switch(fontType)
	{
		case FONT_ASCII_8x16:
			return FONT_interface_ascii_8x16_get_font(c);
		case FONT_ASCII_10x19:
			return FONT_interface_ascii_10x19_get_font(c);
		case FONT_ASCII_YAHEI:
			return FONT_interface_ascii_YAHEI_get_font(c);
		default:
			return 0;	
	}
}


//根据库名称(定义在FONT_LIB_TYPE中),找到该库的详细信息
const FONT_LIB* FONT_get_lib_info(FONT_TYPE fontLibType)
{
	switch(fontLibType)
	{
		case FONT_ASCII_8x16:
			return FONT_interface_ascii_8x16_get_lib();
		case FONT_ASCII_10x19:
			return FONT_interface_ascii_10x19_get_lib();
		case FONT_ASCII_YAHEI:
			return FONT_interface_ascii_YAHEI_get_lib();
		default:
			return 0;
	}
}


/*
	计算出给定的一个字体的宽度(对于可变宽字体有效)
	只适用于左对齐的字符数据数据
	pFont:指向字符数据的指针
	charAmount: 这个点阵信息中的字符总数
	fontHigh:		字符的高度
*/
U32 FONT_get_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh)
{
	int width = 0;
	int widthTemp = 0;
	int indexChar;
	int indexLine;
	int charNumPerLine = 1;

	
	//计算每一行使用的字节数
	/*
		算法比较复杂:
			以fontHigh=21为例, 在总点阵字符中，每21个可以显示一个小字符，
			两个小字符可以拼成一个大字符，大字符则需要21*2个字节。
			一个横行上有n个有效字节，则这个字符就需要21*n个字节。
			所以，每21个字符一检测(检测是否有点阵),则就知道每一行有
			多少个字符了.
	*/
	for(indexChar = fontHigh; indexChar < charAmount; indexChar++)
	{
		if(pFont[indexChar] != 0)
		{
			charNumPerLine ++;
			indexChar += fontHigh - (indexChar%fontHigh);
		}
		
		if(indexChar != fontHigh && (indexChar%fontHigh == fontHigh - 1))
			break;
	}

	//计算一个字符的宽度
	/*
		算法:
			根据上面计算的结果，从每一横行的最右边开始扫描，找到最突出的横行。
			也就是最大点阵横行的个数即为字符的宽度.	
			 如:
				0011000000
				0011100100
				0100001100
				0000010010
				0000100100
			这个字符的宽度:9(从右向左扫描，最突出的地方。)
	*/
	for(indexLine = 1; indexLine <= fontHigh; indexLine++)
	{
		widthTemp = charNumPerLine*8;
		for(indexChar = charNumPerLine; indexChar >= 1; indexChar --)
		{
			U32 indexBit = 8;
			U8 charTemp = *(pFont + indexChar - 1);
			if(charTemp == 0)
			{
				widthTemp-=8;
				continue;
			}
				
			while(indexBit--)
			{
				if((charTemp & 0x1) == 0)
					widthTemp--;
				else
				{
					indexChar = 0;
					break;
				}	
				charTemp>>=1;
			}
		}
		if(width < widthTemp)
			width = widthTemp;
		pFont += charNumPerLine;
	}
	
	return width;
}


//获得一个字符串的宽度（点阵宽度，而不是strlen的宽度）
U32 FONT_get_string_width(char *str, FONT_TYPE fontType)
{
	char c;
	U32 width = 0;
	do
	{
		c= *str++;
		width += FONT_get_font_info(c, fontType)->fontWidth + FontFormat.rowSpacing;
	}
	while(c);
	
	return width;
}

//根据字体的类型得到一个字符的宽度
U32 FONT_get_char_width(char c, FONT_TYPE fontType)
{
	return FONT_get_font_info(c, fontType)->fontWidth + FontFormat.rowSpacing;
}

//根据
U32 FONT_get_char_high(char c, FONT_TYPE fontType)
{
	return FONT_get_font_info(c, fontType)->fontHigh + FontFormat.lineSpacing;
}


//**********************输出相关函数**********************//
/*
基本功能和LCD_printf一样，但这里的行和列是按照字的宽度和高度来分的
line >= 0
cur >= 0
*/
int FONT_printf(U16 x, U16 y, char* format, ...)
{
	int r;
	char buffer[128];
	const FONT_LIB* pFontLib =  FONT_get_lib_info((FontFormat.fontType)); 
	va_list argList;
	va_start(argList, format);
	
	x = x  * (pFontLib->fontWidth + FontFormat.rowSpacing);
	y = y  * (pFontLib->fontHigh + FontFormat.lineSpacing);
	
	if(x > SCREEN_SIZE_X || y > SCREEN_SIZE_Y)
		return -1;
	
	r = vsprintf(buffer, format, argList);
	LCD_print_string(x, y, buffer,  FontFormat.fontType);
	
	va_end(argList);
	return r;
}

//*********************8下面的函数主要用来测试
#include "SSD1289_base.h"
extern const unsigned char ansi_YAHEI_font_variable[][42] ;
void FONT_test()
{
	FONT_printf(5, 3, "hello");
}






