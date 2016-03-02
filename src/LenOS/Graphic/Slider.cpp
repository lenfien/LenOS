
#include <cmath>
#include <cstdlib>

#include "Slider.h"
#include "button.h"
#include "out.h"
#include "screen.h"
#include "com.h"
#include "touchPad.h"

Slider::Slider(int _range,  int _page, DIR dir, int bold, int length, 
							 Color::ColorValue backColor, 
										Color::ColorValue controlColor):
TouchWidget(dir == VERTICAL ? bold :length, dir == VERTICAL ? length : bold),  
curPos(0), range(_range), page(_page), direction(dir), 
backColor(backColor), controlColor(controlColor), controlObj(0) 
{
	int len = direction == VERTICAL ? area.ySize : area.xSize;
	controlLength = page * len / range ;	//控制条的长度
	perRange = double(len - controlLength) / double(range);
}


Graphic* Slider::set_controlObj(Graphic* g)
{
	Graphic* old = controlObj;
	controlObj = g;
	return old;
}

void Slider::set_range(int range, int page)
{
	this->range = range;
	this->page = page;
	
	if(drawed)
		update();
}

int	Slider::get_pos()
{
	return curPos;
}

int Slider::draw(Graphic::Point p)
{
	drawed = true;
	area.position = p;
	update();
	
	return 0;
}

int Slider::update(void *p)
{
	int len = direction == VERTICAL ? area.ySize : area.xSize;
	
	if(range < page)
		controlLength = len;
	else
		controlLength = page* len/range ;	//控制条的长度
	
	Graphic::draw_rectangle(real_position(), area.xSize, area.ySize, backColor, ~backColor, 1);
	
	if(direction == VERTICAL)
	{
		int pos = real_position().y + curPos * (area.ySize - controlLength)/range;
		Graphic::draw_rectangle(Graphic::Point(real_position().x, pos), area.xSize, controlLength, controlColor);
	}
	else
	{
		int pos = real_position().x + double(curPos) * perRange;
		Graphic::draw_rectangle(Graphic::Point(pos,  real_position().y), controlLength, area.ySize, controlColor);
	}
	return 1;
}

void Slider::touch_handler(Graphic::Point p, Touchable *self, Touchable* father)				//触摸事件
{
	TouchPad::some_widget_down = true;
	pressed = true;
}

void Slider::hold_handler(Graphic::Point p, Touchable *self, Touchable* father)					//保持事件
{
	if(range <= page)
	{
		curPos = 0;
	}
	else if(direction == VERTICAL)
	{
		if(p.y < real_position().y + controlLength/2)
			curPos = 0;
		else if(p.y > real_position().y + area.ySize - controlLength/2)
			curPos = range - 1;
		else
			curPos = (p.y - controlLength/2 - real_position().y) * range / (area.ySize - controlLength);
	}
	else
	{
		if(p.x < real_position().x + controlLength/2)
			curPos = 0;
		else if(p.x > real_position().x + area.xSize - controlLength/2)
			curPos = range - 1;
		else
			curPos = (p.x - controlLength/2 - real_position().x) * range / (area.xSize - controlLength);
	}
	
	static int prePos = 0;
	
	if(controlObj && std::abs(prePos - curPos) > 5)
	{
		controlObj->update(&curPos);
		prePos = curPos;
	}
	
	update();
}

void Slider::long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father)		//长按事件
{
	
}

void Slider::release_handler(const  Graphic::Point p, Touchable *self, Touchable* father)			//释放事件
{
	TouchPad::some_widget_down = false;
	pressed = false;
}
