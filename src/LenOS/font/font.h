


#ifndef __FONT__
#define __FONT__

#include "com.h"
#include "screen.h"
#include "color.h"
#include "graphic.h"

/*
定义Font相关的信息
	可通过Font, 根据不同的字符, 不同的字体, 获取到该字符的size 和 点阵信息
*/
/*
如果你想加入10x19的字体和yahei字体, 将注销去掉, 然后就可以使用set_font_type来将系统字体
设置为这两个中的一个了
*/
#define  __ASCII_10x19
#define	 __ASCII_YAHEI


class Font
{
/************************类型定义部分开始*****************/
public:
	//字体类型
	typedef enum {
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
	
	//是否为可变宽度字体
	typedef enum
	{
		VARIABLE,			//字符集为可变宽字体
		FIXED     		//字符集为固定宽度字体
	}WidthType;
	
	//字符集信息
	typedef struct
	{
		WidthType 					widthType;   		//字符集是否为可变宽字符集
		U32  								fontWidth;      //如果是可变宽字体，该项无意义
		U32 		 						fontHigh;				//字符高度
		FontAlign 					align;       		//数据的对齐模式
		const unsigned char *pLibPixel;			//指向字符点阵信息
	}LibInfo;
	
	//字体信息定义
	typedef struct
	{
		U32 								fontWidth;			//文字宽度
		U32 								fontHigh;				//文字高度
		const unsigned char *pPixel;    		//指向字符点阵信息的指针
		const								LibInfo* pLib;	//指向该字体所在字符集信息的指针
	}FontInfo;

	typedef struct
	{
		U32 fontWidth;
		U32 fontHigh;
	}FontSize;
	
	typedef struct
	{
		S32 							lineSpacing;   		//行距
		S32 							rowSpacing;    		//列距
		Color::ColorValue fontColor;    		//文字颜色
		Color::ColorValue fontBackColor; 		//背景颜色
		FontType 					fontType;					//字体类型
	}FontFormat;													//字体格式
/************************类型定义部分结束********************/
	
	
/***********************数据定义部分开始*************************/
public:
	static FontFormat 					fontFormat;						//定义当前文字显示格式
	
private:	
	static const LibInfo 				libInfos[3];					//存储三种字体的信息
	static const unsigned char ascii_8x16[][16];			//点阵指针信息
	static const unsigned char ascii_10x19[][38];			//点阵指针信息
	static const unsigned char ascii_YAHEI[][42];			//点阵指针信息

private:
	static const FontInfo& ascii_8x16_char_info(const char c);		//获取8x16字符的信息
	static const FontInfo& ascii_10x19_char_info(const char c);		//获取10x16字符的信息
	static const FontInfo& ascii_YAHEI_char_info(const char c);		//获取YAHEI可变字符的信息
	
public:
	static const FontInfo& char_info(const char c);

/***********************数据定义部分结束*************************/


/***********************方法开始************************************/
public:
	static const FontInfo& 	font_info(const char c, const FontType& type = fontFormat.fontType);	//根据字符和字体类型,返回对应的字体信息
	static const LibInfo&		lib_info(const FontType &type = fontFormat.fontType );

private:
	static U32 	 font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh);

public:	
	static U32 	 string_width(const char* str, FontType fontType = fontFormat.fontType);
	static U32 	 char_width(const char c, FontType fontType = fontFormat.fontType);
	static U32 	 char_high(const char c, FontType fontType = fontFormat.fontType);
	static U32 	 font_width() {return char_width('C');}
	static U32 	 font_high()	{return char_high('C'); }
/***********************方法结束************************************/	

/*************************字体信息设置开始****************************/
public:
	static S32 								set_line_spacing(S32);									//设置行距
	static S32 								set_row_spacing(S32);										//设置列距离
	static Color::ColorValue 	set_font_color(Color::ColorValue);			//设置字体颜色
	static Color::ColorValue 	set_font_back_color(Color::ColorValue);	//设置文字的背景色
	static FontType 					set_font_type(FontType);								//设置字体类型

	static  Graphic::RectType window;

	static  Graphic::RectType set_window(Graphic::RectType r);				//设置文字窗口
	static 	Graphic::RectType set_full_window();											//设置文字窗口为全屏
/*************************字体信息设置结束****************************/
};

#endif
