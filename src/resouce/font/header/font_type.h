


#ifndef __FONT_TYPE
#define __FONT_TYPE

#include "com.h"
typedef enum
{
	FONT_ASCII_8x16,
	FONT_ASCII_10x19,
	FONT_ASCII_YAHEI,
	//待添加
	FONT_Other
}FONT_TYPE;


//字体数据对齐
typedef enum
{
	ALIGN_LEFT,
	ALIGN_RIGH
}FONT_ALIGN;

typedef enum
{
	WIDTH_VARIABLE,			//字符集为可变宽字体
	WIDTH_FIXED     		//字符集为固定宽度字体
}WIDTH_TYPE;


//字符集信息
typedef struct
{
	WIDTH_TYPE widthType;   		//字符集是否为可变宽字符集
	U32  fontWidth;         		//如果是可变宽字体，该项无意义
	U32  fontHigh;							//字符高度
	FONT_ALIGN align;       		//数据的对齐模式
}FONT_LIB;

typedef FONT_LIB* PFONT_LIB;

//字体信息定义
typedef struct
{
	FONT_LIB* pLib;					//指向该字体所在字符集信息的指针
	U32 fontWidth;
	U32 fontHigh;
	const unsigned char *pChar;     //指向字符点阵信息的指针
}FONT;

typedef FONT* PFONT;

typedef struct
{
	U32 fontWidth;
	U32 fontHigh;
}FONT_SIZE;


#endif

