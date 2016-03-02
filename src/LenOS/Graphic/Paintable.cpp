
#include "Paintable.h"
#include "cmath"
#include "vector.h"
#include "out.h"
#include <cstdarg>

//boldÊÇ°ë¿í¶È
void 
Paintable::idraw_line(Graphic::Point pStart, Graphic::Point pEnd, Color::ColorValue cv, U8 bold)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_line(pStart + pArea->position,  pEnd + pArea->position, cv, bold);
	Screen::restore_vwindow(r);
}

void 
Paintable::idraw_lines(Graphic::Point* pBeg, Graphic::Point* pEnd, Color::ColorValue v, U16 bold)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Vector<Graphic::Point> points;
	
	for(Graphic::Point *it = pBeg; it != pEnd; it ++)
		points.push_back(*it + pArea->position);
	Graphic::draw_lines(points.begin(), points.end(),  v, bold);
	Screen::restore_vwindow(r);
}


void Paintable::idraw_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue c, Color::ColorValue cl, U16 bold)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_rectangle(leftTop+ pArea->position, xLen, yLen, c, cl, bold);
	Screen::restore_vwindow(r);
}

void Paintable::idraw_empty_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_empty_rectangle(leftTop+ pArea->position, xLen, yLen, cv, bold);
	Screen::restore_vwindow(r);
}

void Paintable::idraw_circle(Graphic::Point oc, U16 r, Color::ColorValue cv)
{
	Graphic::RectType ra = Screen::set_vwindow(*pArea);
	Graphic::draw_circle(oc+ pArea->position, r, cv);
	Screen::restore_vwindow(ra);
}

void Paintable::idraw_empty_circle(Graphic::Point oc, U16 r, Color::ColorValue lv)
{
	Graphic::RectType ra = Screen::set_vwindow(*pArea);
	Graphic::draw_empty_circle(oc + pArea->position, r, lv);
	Screen::restore_vwindow(ra);
}


void Paintable::idraw_oval(U16 a, U16 b, Graphic::Point o, 	Color::ColorValue p)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_oval(a, b, o + pArea->position, 	p);
	Screen::restore_vwindow(r);
}


void Paintable::idraw_point(Graphic::Point p, Color::ColorValue color)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_point(p + pArea->position, color);
	Screen::restore_vwindow(r);
}

void Paintable::idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_bitmap(leftTop + pArea->position, bitMapWidth, bitMapHigh, pPic);
	Screen::restore_vwindow(r);
}

void Paintable::idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>& pic)
{
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	Graphic::draw_bitmap(leftTop + pArea->position, bitMapWidth, bitMapHigh, pic);
	Screen::restore_vwindow(r);
}

char _buffer[128];
char*	 Paintable::iprintf(Graphic::Point p,  char *format, ...)
{
	p = p + pArea->position;
	Graphic::RectType r = Screen::set_vwindow(*pArea);
	
	std::va_list list;
	va_start(list, format);
	std::vsprintf(_buffer, format, list);
	va_end(list);

	char *re = Out::print(p.x, p.y , _buffer);
	
	Screen::restore_vwindow(r);
	return re;
}
