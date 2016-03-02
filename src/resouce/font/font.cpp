#include "_font.h"
#include "Color.h"

/************��̬��Ա����*********************/
Font::FontFormat Font::fontFormat = 
{
	2, 
	1,
	0xFFFF, 
	0,
	Font::Ascii_8x16
};

const Font::LibInfo Font::libInfos[3] = 
{
	{Font::FIXED,			8,  16, Font::ALIGN_LEFT, 	(const unsigned char*)Font::ascii_8x16},	//8 * 16
	{Font::FIXED, 		10, 19, Font::ALIGN_LEFT,  	(const unsigned char*)Font::ascii_10x19},	//10 * 19
	{Font::VARIABLE, 	24, 21, Font::ALIGN_LEFT, 	(const unsigned char*)Font::ascii_YAHEI}					//΢���ź�. �߶�һ��, 24Ϊ�����
};

const Font::FontType Font::ASCII_8x16;
const Font::FontType Font::ASCII_10x19;
const Font::FontType Font::ASCII_YAHEI;

const Font::FontInfo& Font::ascii_8x16_char_info(char c)
{
	static FontInfo fi;
	//������ڿ��ӷ�Χ�ڣ�����0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;	
		fi.fontHigh = 0;     //�ַ��߶�
		fi.fontWidth = 0;		//ָ������ָ��
	}
	else
	{
		//��ʼ��font
		fi.pPixel = ascii_8x16[c - 0x20];			//ָ������ָ��
	    fi.fontHigh = libInfos[Ascii_8x16].fontHigh;     //�ַ��߶�
		fi.fontWidth = libInfos[Ascii_8x16].fontWidth;   //�ַ����
		fi.pLib = libInfos + Ascii_8x16;
	}
	return fi;
}

const Font::FontInfo&  Font::ascii_10x19_char_info(char c)
{
	static FontInfo fi;
	//������ڿ��ӷ�Χ�ڣ�����0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;				//ָ������ָ��
		fi.fontHigh = 0;     //�ַ��߶�
		fi.fontWidth = 0;   	//�ַ����
	}
	else
	{
		fi.pPixel = ascii_10x19[c - 0x20];			//ָ������ָ��
		fi.fontHigh = libInfos[Ascii_10x19].fontHigh;     //�ַ��߶�
		fi.fontWidth = libInfos[Ascii_10x19].fontWidth;   //�ַ����
		fi.pLib = libInfos + Ascii_10x19;
	}
	
	return fi;
}

const Font::FontInfo& Font::ascii_YAHEI_char_info(char c)
{
	static FontInfo fi;
	//������ڿ��ӷ�Χ�ڣ�����0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;			//ָ������ָ��
		fi.fontWidth = 0;
		fi.fontHigh = 0;     	//�ַ��߶�
	}
	else
	{
		//��ʼ��font
		fi.pPixel = ascii_YAHEI[c - 0x20];			//ָ������ָ��
		fi.fontWidth = (c == ' ')? 8 :font_width(fi.pPixel, 42, 21);
		fi.fontHigh = libInfos[Ascii_YAHEI].fontHigh;     				//�ַ��߶�
		fi.pLib = libInfos + Ascii_YAHEI;
	}
	
	return fi;
}


/*
	�����������һ������Ŀ��(���ڿɱ��������Ч)
	ֻ�������������ַ���������
	pFont:ָ���ַ����ݵ�ָ��
	charAmount: ���������Ϣ�е��ַ�����
	fontHigh:		�ַ��ĸ߶�
*/
U32 Font::font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh)
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
U32 Font::string_width(char *str, FontType fontType)
{
	char c;
	U32 width = 0;
	do
	{
		c= *str++;
		width += font_info(c, fontType).fontWidth + fontFormat.rowSpacing;
	}
	while(c);
	
	return width;
}

//������������͵õ�һ���ַ��Ŀ��
U32 Font::char_width(char c, FontType fontType)
{
	return font_info(c, fontType).fontWidth + fontFormat.rowSpacing;
}

//����
U32 Font::char_high(char c, FontType fontType)
{
	return font_info(c, fontType).fontHigh + fontFormat.lineSpacing;
}


const Font::FontInfo& Font::font_info(char c, const FontType& type)
{
	switch(type)
	{
		case Ascii_8x16:
			return ascii_8x16_char_info(c);
		case Ascii_10x19:
			return ascii_10x19_char_info(c);
		case Ascii_YAHEI:
			return ascii_YAHEI_char_info(c);
	}
	return ascii_8x16_char_info(c);
}

const Font::LibInfo&	Font::lib_info(const FontType &type)
{
	return libInfos[type];
}


S32 Font::set_line_spacing(S32 l)
{
	int re = fontFormat.lineSpacing;
	fontFormat.lineSpacing = l;
	return re;
}

S32 Font::set_row_spacing(S32 r)
{
	int re = fontFormat.rowSpacing;
	fontFormat.rowSpacing = r;
	return re;
}

Color::ColorValue Font::set_font_color(Color::ColorValue c)
{
	Color::ColorValue re = fontFormat.fontColor;
	fontFormat.fontColor = c;
	return re;
}
Color::ColorValue Font::set_font_back_color(Color::ColorValue c)
{
	Color::ColorValue re = fontFormat.fontBackColor;
	fontFormat.fontBackColor = c;
	return re;
}
Font::FontType Font::set_font_type(FontType t)
{
	FontType re = fontFormat.fontType;
	fontFormat.fontType = t;
	return re;
}





