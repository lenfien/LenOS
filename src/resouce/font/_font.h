


#ifndef __FONT__
#define __FONT__

/*
	Font类: 
		Font类继承Screen类. 它从Screen 类获取两个函数, 在x, y点, 绘制一个点.
*/

#define __CPlusPlus
#include "com.h"
#include "_SSD1289.h"
#include "color.h"
/*
定义Font相关的信息
	可通过Font, 根据不同的字符, 不同的字体, 获取到该字符的size 和 点阵信息
*/
class Font
{
/****************类型定义部分*************/
public:
	typedef enum
	{
		Ascii_8x16,
		Ascii_10x19,
		Ascii_YAHEI
	}FontType;
	
	//字体数据对齐
	typedef enum
	{
		ALIGN_LEFT,
		ALIGN_RIGH
	}FontAlign;
	
	typedef enum
	{
		VARIABLE,			//字符集为可变宽字体
		FIXED     		//字符集为固定宽度字体
	}WidthType;
	
	//字符集信息
	typedef struct
	{
		WidthType widthType;   		//字符集是否为可变宽字符集
		U32  			fontWidth;      //如果是可变宽字体，该项无意义
		U32 		 	fontHigh;				//字符高度
		FontAlign align;       		//数据的对齐模式
		const unsigned char *pLibPixel;	
	}LibInfo;
	
	//字体信息定义
	typedef struct
	{
	
		U32 fontWidth;
		U32 fontHigh;
		const unsigned char *pPixel;    		//指向字符点阵信息的指针
		const	LibInfo* pLib;								//指向该字体所在字符集信息的指针
	}FontInfo;

	typedef struct
	{
		U32 fontWidth;
		U32 fontHigh;
	}FontSize;
	
	typedef struct
	{
		S32 lineSpacing;   		//行距
		S32 rowSpacing;    		//列距
		Color::ColorValue fontColor;    	//文字颜色
		Color::ColorValue fontBackColor; //背景颜色
		FontType fontType;		//字体类型
	}FontFormat;						//字体格式

/***********************数据定义部分*************************/
private:
	static const unsigned char ascii_8x16[][16];			//点阵指针信息
	static const unsigned char ascii_10x19[][38];		//点阵指针信息
	static const unsigned char ascii_YAHEI[][42];		//点阵指针信息
												//定义当前文字显示格式

public:
	static FontFormat fontFormat;
	static const FontType ASCII_8x16 = Ascii_8x16;
	static const FontType ASCII_10x19 = Ascii_10x19;
	static const FontType ASCII_YAHEI = Ascii_YAHEI;

private:
	static const FontInfo& ascii_8x16_char_info(char c);
	static const FontInfo& ascii_10x19_char_info(char c);
	static const FontInfo& ascii_YAHEI_char_info(char c);
	
public:
	static const LibInfo libInfos[3];											//存储三种字体的信息
	static const FontInfo& 	font_info(const char c, const FontType& type);	//根据字符和字体类型,返回对应的字体信息
	static const LibInfo&		lib_info(const FontType &type);
	static U32 	 font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh);
	static U32 	 string_width(char *str, FontType fontType);
	static U32 	 char_width(char c, FontType fontType);
	static U32 	char_high(char c, FontType fontType);
	
public:
	//设置
	static S32 set_line_spacing(S32);
	static S32 set_row_spacing(S32);
	static Color::ColorValue set_font_color(Color::ColorValue);
	static Color::ColorValue set_font_back_color(Color::ColorValue);
	static FontType set_font_type(FontType);
};

#endif
