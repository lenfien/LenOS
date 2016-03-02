
#ifndef __LCD_TYPE_SSD1289
#define __LCD_TYPE_SSD1289

#include "com.h"
#include "font_operation.h"


typedef struct
{
	int x;
	int y;
}POINT;


typedef struct
{
	S32 lineSpacing;   	//行距
	S32 rowSpacing;    	//列距
	U32 color;     			//文字颜色
	U32 backColor;     	//背景颜色
	FONT_TYPE fontType;
}LCD_FONT_FORMAT;


//RGB 颜色值定义
typedef struct
{
	U8 R;
	U8 G;
	U8 B;
}RGB_COLOR;


//LCD SSD1289屏幕方向定义
typedef enum
{
	ORITATION_320_240,     //320 * 240（板子端子朝向自己，屏幕的左上角为0, 0）
	ORITATION_240_320      //240 * 320 (板子串口朝向自己，屏幕的左上角为0, 0）
}SSD1289_ORITATION;


//LCD SSd1289颜色定义
typedef enum
{
	COLOR_65K,
	COLOR_262K
}SSD1289_COLOR;


//SSD1289 初始化结构体
typedef struct
{
	SSD1289_ORITATION oritation;          //屏幕的方向
	SSD1289_COLOR			color;              //颜色质量
	U32								backgroundColor;    //背景颜色
	U8								backLight;					//背景灯状态(1:打开 0:关闭)
	U8 								isInit;
}SSD1289_INITIAL_STRUCT;


#endif
