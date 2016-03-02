

#ifndef __LCD_SSD1289
#define __LCD_SSD1289

#include "com.h"

#include "ssd1289_type.h"

#define RGB_262K(R, G, B)	((R << 12) | (G << 6) | B)			
#define RGB_65K(R, G, B)    ((R << 11) | (G << 5) | B)

#define RGB(R, G, B)	((ScreenState.color==COLOR_262K)?RGB_262K(R, G, B):RGB_65K(R, G, B))

//在不同方向下屏幕的横纵最大值
#define SCREEN_SIZE_X			((ScreenState.oritation == ORITATION_320_240) ? 319 : 239)
#define SCREEN_SIZE_Y			((ScreenState.oritation == ORITATION_320_240) ? 239 : 319)

#define SCREEN_WIDTH			SCREEN_SIZE_X
#define SCREEN_HIGH				SCREEN_SIZE_Y

#define SCREEN_SIZE_HALF_X      (SCREEN_SIZE_X/2)
#define SCREEN_SIZE_HALF_Y		(SCREEN_SIZE_Y/2)

//262K颜色定义
#define RGB_262K_RED      RGB_262K(0x3F, 0, 0)
#define RGB_262K_GREEN    RGB_262K(0, 0x3F, 0)
#define RGB_262K_BLUE     RGB_262K(0, 0, 0x3F)
#define RGB_262K_BLACK    RGB_262K(0, 0, 0)
#define RGB_262K_WHITE    RGB_262K(0x3F, 0x3F, 0x3F)

//65K颜色定义
#define RGB_65K_RED		  RGB_65K(0x1F, 0, 0) 
#define RGB_65K_GREEN     RGB_65K(0, 0x3F, 0) 
#define RGB_65K_BLUE      RGB_65K(0, 0, 0x1F) 
#define RGB_65K_BLACK     RGB_65K(0, 0, 0) 
#define RGB_65K_WHITE     RGB_65K(0x1F, 0x3F, 0x1F)

#define RGB_RED      	((ScreenState.color == COLOR_262K) ? RGB_262K_RED : RGB_65K_RED)
#define RGB_GREEN   	((ScreenState.color == COLOR_262K) ? RGB_262K_GREEN : RGB_65K_GREEN)
#define RGB_BLUE     	((ScreenState.color == COLOR_262K) ? RGB_262K_BLUE : RGB_65K_BLUE)
#define RGB_BLACK   	((ScreenState.color == COLOR_262K) ? RGB_262K_BLACK : RGB_65K_BLACK)
#define RGB_WHITE   	((ScreenState.color == COLOR_262K) ? RGB_262K_WHITE : RGB_65K_WHITE)

#define BACKGROUND_COLOR	ScreenState.backgroundColor

/*
	LCD状态:
*/
extern SSD1289_INITIAL_STRUCT ScreenState;


//SSD1289内部初始化 配置240 * 320模式还是 320 * 240模式见参数
//oritation = 1 240 * 320
//oritation = 0 320 * 240
void	SSD1289_internal_init(SSD1289_INITIAL_STRUCT initialState);




//SSD1289初始化 配置240 * 320模式还是 320 * 240模式见参数
//oritation = 1 240 * 320
//oritation = 0 320 * 240
void 	SSD1289_init(SSD1289_INITIAL_STRUCT initialState);




//给LCD发送数据
void 	SSD1289_send_data(U16 regIndex, U16 regValue);





//设置GDDRAM将要访问的地址 240 * 320（板子串口朝向自己，屏幕的左上角为0, 0）
void 	SSD1289_set_GDDRAM_position(U16 x, U16 y);




/*
在AC所指GDDRAM处绘制颜色
	可在COLOR_262K模式下
	可在COLOR_65K模式下
	262K颜色需要18位:R,G,B各6位
	65K颜色需要16位:R5 G6 B5 
*/
void 	SSD1289_set_point(U32 RGB_color);

/*
获得AC所指GDDRAM处的颜色
	可在COLOR_262K模式下
	可在COLOR_65K模式下
*/
U32 	SSD1289_get_point(void);


//设置窗口
void 	SSD1289_set_window(U16 hStart, U16 vStart, U16 hEnd, U16 vEnd);


//用color清除LCD
void 	SSD1289_clear_screen(U32 color);

#define	LCD_clear_screen	SSD1289_clear_screen

/*
	函数功能:根据参数在屏幕上绘制一个262K颜色的图片
	bitMapWidth和bitMapHigh根据xStar,yStart的不同有不同的范围，不要超过该范围，否则图片会重叠显示
*/
void 	SSD1289_draw_bitmap_262K(U16 bitMapWidth, U16 bitMapHigh, U16 xStart, U16 yStart, const unsigned char *pPic);

/*
//恢复全屏窗口
//恢复后的窗口将为全屏
//并且绘制的第一点将在窗口的左上角位置
*/
void 	SSD1289_set_full_window(void);


/*
	显示数据以左对齐方式排列的字符
		右对齐如: 	0011 1111 1111 1111 
		左对齐如:   1111 1111 1111 1100
	fontWidth指定字体大小:
		适用于所有大小的字体
	指定显示位置:
		xStart，yStart 范围应该在相应屏幕方向的对应的x，y内
	前景色
		color
	背景色
		backColor
	指向字符地址
*/
void 	SSD1289_draw_font_left_align(
							U16 fontWidth,   //字符宽度
							U16 fontHigh,    //字符高度
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont
							);
							
/*
	显示数据以右对齐方式排列的字符
		右对齐如: 	0011 1111 1111 1111 
		左对齐如:   1111 1111 1111 1100
	fontWidth指定字体大小:
		适用于所有大小的字体
	指定显示位置:
		xStart，yStart 范围应该在相应屏幕方向的对应的x，y内
	前景色
		color
	背景色
		backColor
	指向字符地址
*/
void 	SSD1289_draw_font_right_align(
							U16 fontWidth,   //字符宽度
							U16 fontHigh,    //字符高度
							U16 xStart,      //起始x位置
							U16 yStart,      //起始y位置
							U32	color,		 //颜色
							U32 backColor,   //背景色
							const unsigned char *pFont
							);
					

#endif
