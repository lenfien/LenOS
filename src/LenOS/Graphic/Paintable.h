#ifndef __PAINTER__
#define __PAINTER__

/*
	Paintable是一个属性类，
	继承该类的类就具有了在屏幕上绘制图形的功能。
	Paintable 有两个参数， 想对位置的指针和范围的指针, 接下来对屏幕的绘制将成为以相对位置为0，0点并且在范围内的绘图.
	这里为什么要用指针？因为相对位置和范围可能会发生变化, 而Paintable需要时刻知道这个信息。
*/

#include "graphic.h"
#include "screen.h"

class Paintable
{
protected:
		Graphic::RectType* pArea;	//定义绘图的区域
		Paintable(Graphic::RectType* r):pArea(r)	{}
		
public:		virtual void 	idraw_line(Graphic::Point pStart, Graphic::Point pEnd, Color::ColorValue cv, U8 bold = 1);
		virtual void 	idraw_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue c, Color::ColorValue cl =Color::InvalidColor, U16 bold = 1);
		virtual void 	idraw_lines(Graphic::Point* pBeg, Graphic::Point* pEnd, Color::ColorValue cv, U16 bold);
		virtual void 	idraw_empty_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold = 1);
		virtual void 	idraw_circle(Graphic::Point oc, U16 r, Color::ColorValue cv);
		virtual void 	idraw_empty_circle(Graphic::Point oc, U16 r, Color::ColorValue lv);
		virtual void 	idraw_oval(U16 a, U16 b, Graphic::Point o, 	Color::ColorValue p);
		virtual void 	idraw_point(Graphic::Point p, Color::ColorValue color);
		virtual void 	idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic);
		virtual void 	idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>& pic);	
		virtual char*	iprintf(Graphic::Point p, char *format, ...);
};


#endif
