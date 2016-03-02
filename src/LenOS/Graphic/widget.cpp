#include "widget.h"
#include "pad.h"

Widget::Widget(
				U16 	_sizeX, 
				U16 	_sizeY
		): relaPosition(0, 0), area(Point(0, 0), _sizeX, _sizeY), father(0), dignity(0)
{
	
}

Graphic::Point Widget::set_relataive_position(Point p)
{
	Point old = relaPosition;
	relaPosition = p;
	return old;
}

/*
	v = false 全部区域
	v= 	true	valid 区域
  x, y 为偏移量
*/
Graphic::RectType 	Widget::set_father_window(bool v, int x, int y)
{
	Graphic::RectType rec;
	if(father)
		rec = Screen::set_vwindow(v ? father->valid_area(): father->all_area());
	return rec;
}

void	Widget::release_father_window(Graphic::RectType rec)
{
	if(father)
		Screen::restore_vwindow(rec);
}
