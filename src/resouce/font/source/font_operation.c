
#include <stdio.h>
#include <stdarg.h>

#include "font_lib.h"
#include "font_operation.h"
#include "com.h"

#include "ssd1289_font.h"
#include "ssd1289_base.h"

//******************�����ຯ��**************************//

//�����������ͣ�����c��Ӧ��������Ϣ
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


//���ݿ�����(������FONT_LIB_TYPE��),�ҵ��ÿ����ϸ��Ϣ
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
	�����������һ������Ŀ��(���ڿɱ��������Ч)
	ֻ�������������ַ���������
	pFont:ָ���ַ����ݵ�ָ��
	charAmount: ���������Ϣ�е��ַ�����
	fontHigh:		�ַ��ĸ߶�
*/
U32 FONT_get_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh)
{
	int width = 0;
	int widthTemp = 0;
	int indexChar;
	int indexLine;
	int charNumPerLine = 1;

	
	//����ÿһ��ʹ�õ��ֽ���
	/*
		�㷨�Ƚϸ���:
			��fontHigh=21Ϊ��, ���ܵ����ַ��У�ÿ21��������ʾһ��С�ַ���
			����С�ַ�����ƴ��һ�����ַ������ַ�����Ҫ21*2���ֽڡ�
			һ����������n����Ч�ֽڣ�������ַ�����Ҫ21*n���ֽڡ�
			���ԣ�ÿ21���ַ�һ���(����Ƿ��е���),���֪��ÿһ����
			���ٸ��ַ���.
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

	//����һ���ַ��Ŀ��
	/*
		�㷨:
			�����������Ľ������ÿһ���е����ұ߿�ʼɨ�裬�ҵ���ͻ���ĺ��С�
			Ҳ������������еĸ�����Ϊ�ַ��Ŀ��.	
			 ��:
				0011000000
				0011100100
				0100001100
				0000010010
				0000100100
			����ַ��Ŀ��:9(��������ɨ�裬��ͻ���ĵط���)
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


//���һ���ַ����Ŀ�ȣ������ȣ�������strlen�Ŀ�ȣ�
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

//������������͵õ�һ���ַ��Ŀ��
U32 FONT_get_char_width(char c, FONT_TYPE fontType)
{
	return FONT_get_font_info(c, fontType)->fontWidth + FontFormat.rowSpacing;
}

//����
U32 FONT_get_char_high(char c, FONT_TYPE fontType)
{
	return FONT_get_font_info(c, fontType)->fontHigh + FontFormat.lineSpacing;
}


//**********************�����غ���**********************//
/*
�������ܺ�LCD_printfһ������������к����ǰ����ֵĿ�Ⱥ͸߶����ֵ�
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

//*********************8����ĺ�����Ҫ��������
#include "SSD1289_base.h"
extern const unsigned char ansi_YAHEI_font_variable[][42] ;
void FONT_test()
{
	FONT_printf(5, 3, "hello");
}






