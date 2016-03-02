
/*
	显示屏驱动和外部用户之间的接口, 当前显示屏使用的是SSD1289
	Screen只图提供与驱动连接的函数, 这些绘图函数直接调用驱动
	Screen类内提供的绘图和文字函数都是和驱动最优化的
	包括绘制矩形 和 bitmap, 还有文字.
	Screen类还提供了硬件相关的信息, 如width()表示屏幕高度
	Screen类还将可能以后会用到的驱动函数提供给外部, 作为驱动的接口, 但没有提供的函数你将
	不应该访问, 因为它们对你没有用
														2013.3.30 lenfien
*/
#ifndef __SCREEN__
#define __SCREEN__

#define __CPlusPlus

#include "com.h"
#include "color.h"
#include "ssd1289.h"
#include "datas.h"

class Screen: public SSD1289
{
public:
		class  Point
		{
			public:
				Point() {}
				S16 x,y;
				Point(S16 _x, S16 _y):x(_x), y(_y)	{}
				bool operator==(const Point& p) {return x == p.x && y == p.y;}
				
				Point operator+(const Point& p) 
				{
					Point tp(x + p.x,  y + p.y); 
					return tp;
				}
				
				Point operator-(const Point& p) 
				{
					Point tp(x - p.x,  y - p.y); 
					return tp;
				}
		};
		
		class RectType
		{
			public:
			RectType(){}
			RectType(Point p, int _xSize, int _ySize):position(p), xSize(_xSize), ySize(_ySize){}
			Point position;
			int xSize;
			int ySize;
			
			bool operator==(const RectType & r)
			{
				return (position == r.position) && (xSize == r.xSize) && (ySize == r.ySize);
			}
		};	//矩形区域
		
public:
		
/**********************构造********************************/
		Screen();		
		Screen(
				Color::ColorValue 	backColor, 
				Oritation 					oritation  		= ORITATION_320_240, 
				Color::ColorQuality colorQuality 	= Color::COLOR_262K, 
				bool 								light 				= 1);

/************************显示屏状态************************/
public:
		using SSD1289::width;
		using SSD1289::high;	
		
		static 	Oritation 					oritation();
		static  Color::ColorQuality color_quality();
		static  U8 									back_light();
		static  Color::ColorValue 	background_color();

/************************窗口******************************/
		static RectType 						window;
		static RectType							set_vwindow(RectType window);
		static RectType							reset_vwindow(RectType window);
		
		static RectType							set_full_vwindow();
		static RectType							get_vwindow()	{return window;}
		static void 								restore_vwindow(RectType w);
/************************图形处理************************/
//绘图
protected:
		static void 	draw_bitmap(S16 xStart, 	S16 yStart, S16 bitMapWidth, S16 bitMapHigh,   const unsigned char *pPic);
		static void 	draw_bitmap(S16 xStart, 	S16 yStart, S16 bitMapWidth, S16 bitMapHigh,   Datas<Color::ColorType>&);
		
		static Color::ColorValue 	
									draw_point(Point p, Color::ColorValue color);					//画点
		static void 	draw_line(S16 xStart, S16 yStart, S16 xEnd, S16 yEnd, Color::ColorValue color);		//画线
		static void 	draw_rectangle(S16 xStart, S16 yStart, S16 xLen, S16 yLen, Color::ColorValue color);							//画实心矩形
		
private:
		static void 	draw_bitmap_262K(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh,   const unsigned char *pPic);
		static void 	draw_bitmap_262K(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType >&);
		static void 	draw_bitmap_65K(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>&);
		static void 	draw_bitmap_65K(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh,  const unsigned char *pPic);	

/**************************文字处理***********************/
protected:
		static void 	draw_font(U16 fontWidth, U16 fontHigh, 
														U16 xStart, U16 yStart, U32	color, 
														U32 backColor, const unsigned char *pFont);

protected:
		static void 	draw_font_left_align(U16 fontWidth, U16 fontHigh, U16 xStart, U16 yStart, 
																				U32	color, U32 backColor, const unsigned char *pFont);
		static void 	draw_font_right_align(U16 fontWidth,U16 fontHigh, U16 xStart, U16 yStart, 
																				U32	color, U32 backColor, const unsigned char *pFont);
									
/***********************底层相关**************************/
public:
		static void 	set_point(U32 color);
		static Color::ColorValue get_point(U16 x, U16 y);
		static U32		get_points(S16 xStart, S16 yStart, S16 xLen, S16 yLen, Datas<Color::ColorType>&);
		static U32		get_points(S16 xStart, S16 yStart, S16 xLen, S16 yLen, unsigned char*);
		static void 	clear_screen(U32 color);
		
		using SSD1289::set_window;
		using SSD1289::set_full_window;
};

#endif


