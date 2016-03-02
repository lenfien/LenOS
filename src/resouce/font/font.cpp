#include "_font.h"
#include "Color.h"

/************静态成员定义*********************/
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
	{Font::VARIABLE, 	24, 21, Font::ALIGN_LEFT, 	(const unsigned char*)Font::ascii_YAHEI}					//微软雅黑. 高度一定, 24为最大宽度
};

const Font::FontType Font::ASCII_8x16;
const Font::FontType Font::ASCII_10x19;
const Font::FontType Font::ASCII_YAHEI;

const Font::FontInfo& Font::ascii_8x16_char_info(char c)
{
	static FontInfo fi;
	//如果不在可视范围内，返回0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;	
		fi.fontHigh = 0;     //字符高度
		fi.fontWidth = 0;		//指向点阵的指针
	}
	else
	{
		//初始化font
		fi.pPixel = ascii_8x16[c - 0x20];			//指向点阵的指针
	    fi.fontHigh = libInfos[Ascii_8x16].fontHigh;     //字符高度
		fi.fontWidth = libInfos[Ascii_8x16].fontWidth;   //字符宽度
		fi.pLib = libInfos + Ascii_8x16;
	}
	return fi;
}

const Font::FontInfo&  Font::ascii_10x19_char_info(char c)
{
	static FontInfo fi;
	//如果不在可视范围内，返回0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;				//指向点阵的指针
		fi.fontHigh = 0;     //字符高度
		fi.fontWidth = 0;   	//字符宽度
	}
	else
	{
		fi.pPixel = ascii_10x19[c - 0x20];			//指向点阵的指针
		fi.fontHigh = libInfos[Ascii_10x19].fontHigh;     //字符高度
		fi.fontWidth = libInfos[Ascii_10x19].fontWidth;   //字符宽度
		fi.pLib = libInfos + Ascii_10x19;
	}
	
	return fi;
}

const Font::FontInfo& Font::ascii_YAHEI_char_info(char c)
{
	static FontInfo fi;
	//如果不在可视范围内，返回0
	if(c < 0x20 || c > 126)
	{
		fi.pPixel = 0;			//指向点阵的指针
		fi.fontWidth = 0;
		fi.fontHigh = 0;     	//字符高度
	}
	else
	{
		//初始化font
		fi.pPixel = ascii_YAHEI[c - 0x20];			//指向点阵的指针
		fi.fontWidth = (c == ' ')? 8 :font_width(fi.pPixel, 42, 21);
		fi.fontHigh = libInfos[Ascii_YAHEI].fontHigh;     				//字符高度
		fi.pLib = libInfos + Ascii_YAHEI;
	}
	
	return fi;
}


/*
	计算出给定的一个字体的宽度(对于可变宽字体有效)
	只适用于左对齐的字符数据数据
	pFont:指向字符数据的指针
	charAmount: 这个点阵信息中的字符总数
	fontHigh:		字符的高度
*/
U32 Font::font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh)
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

//根据字体的类型得到一个字符的宽度
U32 Font::char_width(char c, FontType fontType)
{
	return font_info(c, fontType).fontWidth + fontFormat.rowSpacing;
}

//根据
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





