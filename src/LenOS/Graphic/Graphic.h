
#ifndef __GRAPHIC__
#define __GRAPHIC__

#include "vector.h"
#include "screen.h"

/*
	Graphic类旨在提供基本的绘图函数, 
	并且作为所有图形对象的基类, 并为它的子类们提供虚函数, 
	如draw, 并且为图形化元素
	提供唯一标识符.
*/

class Graphic: public Screen
{
	public:
		static U32 hashCodeCounter;
	
	public:
		bool 							drawed; 					//是否已经绘制到屏幕上
		
	public:
		using Screen::draw_bitmap;
		//using Screen::draw_line;
		using Screen::draw_point;
		using Screen::draw_rectangle;
		
/*********************绘图函数***********************/	
	public:
		using Screen::Point;
		static void draw_line(Point pStart, Point pEnd, Color::ColorValue cv, U8 bold = 1);
		static void draw_rectangle(Point leftTop, U16 xLen, U16 yLen, 
																Color::ColorValue c, Color::ColorValue cl =Color::InvalidColor, 
																	U16 bold = 1);
		
		static void draw_lines(Point* pBeg, Point* pEnd, Color::ColorValue cv, U16 bold);
		static void draw_empty_rectangle(Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold = 1);
		static void draw_circle(Point oc, U16 r, Color::ColorValue cv);
		static void draw_empty_circle(Point oc, U16 r, Color::ColorValue lv);
		static void draw_oval(U16 a, U16 b, Point o, 	Color::ColorValue p);
		
		static void draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic);
		static void draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>&);
		
		//修正矩形的位置， 使其不超过屏幕范围
		static void revise_rectangle_position(Point& p, S16 sizeX, S16 sizeY);
		
		//计算两个矩形的交叉矩形，返回false表示没有交叉，否则将交叉结果保存在dis内
		static bool mix_rectangle(RectType r1, RectType r2, RectType& dis);
		
		//点p是否在矩形r内
		inline static bool	is_in_rectangle(Point p, RectType r)
		{
			if(p.x >= r.position.x && p.y >= r.position.y && p.x < r.position.x + r.xSize && p.y < r.position.y + r.ySize)
				return true;
			
			return false;
		}
		
		static int distance(Point p1, Point p2);
		
/********************作为基类的内容***************************/	
	protected:
		const U32 hashCode;
		virtual ~Graphic(){}
		
	public:	
		virtual int 	draw(Graphic::Point p) = 0;
		virtual int 	dedraw() = 0;
		/*
				在更新的时候总希望按参数指定的方式更新, 所以p指向参数
		*/
		virtual int 	update(void *p = 0) = 0;
		virtual int 	hash_code()	{return hashCode;}
		
	protected:
		Graphic():drawed(false), hashCode(hashCodeCounter++) {}
			
};


#endif
