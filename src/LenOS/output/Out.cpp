#include <cstdio>
//#include <cstdarg>
#include <stdarg.h>
#include "com.h"
#include "out.h"
#include "screen.h"
#include "touch.h"

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
S8	Out::_print(S16 x, S16 y, char c, Font::FontType fontType)
{
	//这里可以对可变宽和固定宽度字符获取信息
	Font::FontInfo fontInfo = Font::font_info(c, fontType);      	//根据fontType获取这个字符的信息
	
	if(fontInfo.pPixel == 0)									//如果字符不在可视字符范围内该字符
		return c;
	
	if(x + fontInfo.fontWidth > Font::window.xSize + Font::window.position.x || x < Font::window.position.x)   			//如果显示的字体会超过屏幕边界 则不显示 并返回-2,-3
		return -2;
	
	if(y < 0 || y + fontInfo.fontHigh > Font::window.ySize + Font::window.position.y || y < Font::window.position.y)
		return -3;
	
	if(fontInfo.pLib->align == Font::ALIGN_LEFT)         			//如果字符数据格式为左对齐(一般都为左对齐)
	{
		 draw_font_left_align(fontInfo.fontWidth,  		//宽度
										fontInfo.fontHigh,     	//高度
										x, y,                   //坐标
										Font::fontFormat.fontColor, Font::fontFormat.fontBackColor,	//前景和背景色 
										fontInfo.pPixel);        	//点阵位置
	}
	else                                  	//如果字符数据格式为右对齐
	{
		draw_font_right_align(fontInfo.fontWidth,  //宽度
										fontInfo.fontHigh,     		//高度
										x, y,                   	//坐标
										Font::fontFormat.fontColor, Font::fontFormat.fontBackColor,	//前景和背景色 
										fontInfo.pPixel); 
	}
	return -1;
	
}


/*
	输出一个字符串(可包含任何转义字符)
	只支持ANCI码
*/
char* Out::_print(S16 xStart, S16 yStart, char *str, Font::FontType fontType)
{
	char c;
	
	int x = Font::window.position == Graphic::Point(0, 0) ? xStart : Font::window.position.x;
	int y = Font::window.position == Graphic::Point(0, 0) ? yStart : Font::window.position.y;
	
	Font::FontInfo font;
	
	Font::LibInfo fontLib;
	bool is_variable_width = Font::lib_info(fontType).widthType == Font::VARIABLE;
	
	fontLib = Font::lib_info(fontType);
	font.fontWidth = fontLib.fontWidth;
	font.fontHigh = fontLib.fontHigh;
	
	while(0 != (c = *str))
	{
		if(c >= 127 || c <= 7 )
		{
			return 0;
		}
		
		if(is_variable_width)		//如果是可变宽字符，每一次都要获取该字符的字体信息
			font = Font::font_info(c, fontType); 
    
		switch(_print(x, y, c, fontType))
		{
			case -2:     	//x越界
				x = Font::window.position.x;
				y += Font::font_high();
				break;
			
			case -3:		//y越界
				//x = Font::window.position.x;
				//y = Font::window.position.y;
				return str;
				
			case -4:		//在库中未找到该点阵信息
				//while(1);
				break;
			case -1:		//正常显示
				x += (font.fontWidth + Font::fontFormat.rowSpacing);
				str++;
				break;
			case '\n':      //换行符
				y += ((!is_variable_width)?font.fontHigh:fontLib.fontHigh + Font::fontFormat.lineSpacing);
				x = 0;
				str++;
				break;
			case '\t':      //制表符
				x += (font.fontWidth + Font::fontFormat.rowSpacing) * 3;
				str++;
				break;
			case '\v':      //垂直制表
				y += ((font.fontHigh + Font::fontFormat.lineSpacing) * 3) % Screen::width();
				str++;
				break;
			case '\b':      //退格符
				if((x - ((int)font.fontWidth + Font::fontFormat.rowSpacing)) >= 0)
					x -= (font.fontWidth + Font::fontFormat.rowSpacing);
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
				
				return 0;
		}
	}
	return str;
}

/*
	使用默认的字库
	printf用法一样，但只支持ANCI字符集
*/


U16 Out::preX = 0;
U16 Out::preY = 0;
char Out::buffer[512];

char* Out::print(S16 x, S16 y, const char *format, ...)
{
	std::va_list list;
	va_start(list, format);
	std::vsprintf(buffer, format, list);
	va_end(list);

	char *re = _print(x, y , Out::buffer, Font::fontFormat.fontType);

	return re;
}


char* Out::print(const char *format, ...)
{
	int len;
	static int line = 0;
	const Font::LibInfo libInfo =  Font::lib_info((Font::fontFormat.fontType));
	int ScreenLines = Screen::high() /(libInfo.fontHigh + Font::fontFormat.lineSpacing);
	
	std::va_list args;
	va_start(args, format);
	std::vsprintf(buffer, format, args);
	va_end(args);
	
	if(line + 1 > ScreenLines)
	{
		line = line % ScreenLines;
		Screen::clear_screen(Screen::background_color());
	}
	
	char* re = printl(0, line, buffer);
	len = Font::string_width(buffer, Font::fontFormat.fontType);
	line = (line + (len / Screen::width() ) + 1 );
	
	return re;
}


/*
基本功能和LCD_printf一样，但这里的行和列是按照字的宽度和高度来分的
line >= 0
cur >= 0
*/
char* Out::printl(S16 x, S16 y, const char* format, ...)
{
	const Font::LibInfo libInfo =  Font::lib_info((Font::fontFormat.fontType)); 
	va_list argList;
	va_start(argList, format);
	
	x = x  * (libInfo.fontWidth + Font::fontFormat.rowSpacing);
	y = y  * (libInfo.fontHigh + Font::fontFormat.lineSpacing);
	
	if(x > Screen::width() || y > Screen::high())
		return 0;
	
	std::vsprintf(buffer, format, argList);
	char *re = _print(x, y, buffer,  Font::fontFormat.fontType);
	
	va_end(argList);
	return re;
}


/*
//清除上一次的显示结果为背景色
void LCD_clear_pre_print()
{
	U32 preColor = LCD_set_font_color(BACKGROUND_COLOR);
	U32 preBackColor = LCD_set_font_backColor(BACKGROUND_COLOR);
	LCD_print_string(preX, preY, buffer, FontFormat.fontType);
	LCD_set_font_color(preColor);
	LCD_set_font_backColor(preBackColor);
}
*/
