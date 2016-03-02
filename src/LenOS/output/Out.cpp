#include <cstdio>
//#include <cstdarg>
#include <stdarg.h>
#include "com.h"
#include "out.h"
#include "screen.h"
#include "touch.h"

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
S8	Out::_print(S16 x, S16 y, char c, Font::FontType fontType)
{
	//������ԶԿɱ��͹̶�����ַ���ȡ��Ϣ
	Font::FontInfo fontInfo = Font::font_info(c, fontType);      	//����fontType��ȡ����ַ�����Ϣ
	
	if(fontInfo.pPixel == 0)									//����ַ����ڿ����ַ���Χ�ڸ��ַ�
		return c;
	
	if(x + fontInfo.fontWidth > Font::window.xSize + Font::window.position.x || x < Font::window.position.x)   			//�����ʾ������ᳬ����Ļ�߽� ����ʾ ������-2,-3
		return -2;
	
	if(y < 0 || y + fontInfo.fontHigh > Font::window.ySize + Font::window.position.y || y < Font::window.position.y)
		return -3;
	
	if(fontInfo.pLib->align == Font::ALIGN_LEFT)         			//����ַ����ݸ�ʽΪ�����(һ�㶼Ϊ�����)
	{
		 draw_font_left_align(fontInfo.fontWidth,  		//���
										fontInfo.fontHigh,     	//�߶�
										x, y,                   //����
										Font::fontFormat.fontColor, Font::fontFormat.fontBackColor,	//ǰ���ͱ���ɫ 
										fontInfo.pPixel);        	//����λ��
	}
	else                                  	//����ַ����ݸ�ʽΪ�Ҷ���
	{
		draw_font_right_align(fontInfo.fontWidth,  //���
										fontInfo.fontHigh,     		//�߶�
										x, y,                   	//����
										Font::fontFormat.fontColor, Font::fontFormat.fontBackColor,	//ǰ���ͱ���ɫ 
										fontInfo.pPixel); 
	}
	return -1;
	
}


/*
	���һ���ַ���(�ɰ����κ�ת���ַ�)
	ֻ֧��ANCI��
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
		
		if(is_variable_width)		//����ǿɱ���ַ���ÿһ�ζ�Ҫ��ȡ���ַ���������Ϣ
			font = Font::font_info(c, fontType); 
    
		switch(_print(x, y, c, fontType))
		{
			case -2:     	//xԽ��
				x = Font::window.position.x;
				y += Font::font_high();
				break;
			
			case -3:		//yԽ��
				//x = Font::window.position.x;
				//y = Font::window.position.y;
				return str;
				
			case -4:		//�ڿ���δ�ҵ��õ�����Ϣ
				//while(1);
				break;
			case -1:		//������ʾ
				x += (font.fontWidth + Font::fontFormat.rowSpacing);
				str++;
				break;
			case '\n':      //���з�
				y += ((!is_variable_width)?font.fontHigh:fontLib.fontHigh + Font::fontFormat.lineSpacing);
				x = 0;
				str++;
				break;
			case '\t':      //�Ʊ��
				x += (font.fontWidth + Font::fontFormat.rowSpacing) * 3;
				str++;
				break;
			case '\v':      //��ֱ�Ʊ�
				y += ((font.fontHigh + Font::fontFormat.lineSpacing) * 3) % Screen::width();
				str++;
				break;
			case '\b':      //�˸��
				if((x - ((int)font.fontWidth + Font::fontFormat.rowSpacing)) >= 0)
					x -= (font.fontWidth + Font::fontFormat.rowSpacing);
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
				
				return 0;
		}
	}
	return str;
}

/*
	ʹ��Ĭ�ϵ��ֿ�
	printf�÷�һ������ֻ֧��ANCI�ַ���
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
�������ܺ�LCD_printfһ������������к����ǰ����ֵĿ�Ⱥ͸߶����ֵ�
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
//�����һ�ε���ʾ���Ϊ����ɫ
void LCD_clear_pre_print()
{
	U32 preColor = LCD_set_font_color(BACKGROUND_COLOR);
	U32 preBackColor = LCD_set_font_backColor(BACKGROUND_COLOR);
	LCD_print_string(preX, preY, buffer, FontFormat.fontType);
	LCD_set_font_color(preColor);
	LCD_set_font_backColor(preBackColor);
}
*/
