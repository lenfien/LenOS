#include "touchPad.h"
#include "vector.h"
#include "graphic.h"
#include "out.h"


bool	TouchPad::some_widget_down = false;

TouchPad::TouchPad(U16 _sizeX, U16 _sizeY, 
				Color::ColorValue cv, 
				void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) ,					//触摸事件
				void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),						//保持事件
				void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),				//长按事件
				void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father )):
				Pad(_sizeX, _sizeY, cv),
				touchWidgets(new Vector<Touchable*>()), systemTouchWidgets(new Vector<Touchable*>()),
				drag(false), pressed(false)					
{
	
}

TouchPad::~TouchPad()
{
	dedraw();
	delete touchWidgets;
}


Graphic::Point _div;
bool TouchPad::meet_condition(Graphic::Point touchPoint)
{
	if(something_being_dragged && drag)
			return true;
	
	if(touchPoint.x > area.position.x && touchPoint.x < area.position.x + area.xSize && 
				touchPoint.y > area.position.y && touchPoint.y < area.position.y + area.ySize)
			return true && !if_covered(touchPoint);
	
	return false;
}


void TouchPad::touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	pressed = true;
	active();
}

Graphic::Point pMove;
void TouchPad::hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	if(drag)
	{
		pMove.x = p.x + _div.x;
		pMove.y = p.y + _div.y;
		move(pMove);
	}
}


void TouchPad::long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	something_being_dragged = true;
	drag = 1;
	_div = area.position - p;
}


void TouchPad::release_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	touchTimes = 0;
	
	something_being_dragged = false;
	drag = false;
	pressed = false;
}


TouchPad& TouchPad::add_widget(Widget* tw, Graphic::Point p)
{
	Pad::add_widget(tw, p);
	if(tw->is_touch_widget())
	{
		TouchWidget* tow = dynamic_cast<TouchWidget*>(tw);
		tow->set_touch_vector(touchWidgets);
		touchWidgets->push_back(tow);
	}
	return *this;
}

void TouchPad::execute(Touchable* ta, Touchable *source)
{
	pressed = Touch::touch_state().isTouch;
	
	bool isBiteByWidget = false;
	
	Vector<Touchable*>::iterator it = touchWidgets->begin();
	
	//RectType r1 = Screen::set_vwindow(valid_area());
	
	while(it != touchWidgets->end() && layer == 0)
	{
		TouchWidget* tw = static_cast<TouchWidget*>(*it);
		
		if((tw)->meet_condition(Touch::touch_point()))
		{
			isBiteByWidget = true;
			Touchable::execute(*it, ta);
		}
		it++;
	}
	
	//Screen::restore_vwindow(r1);
/*	
	RectType r2 = Screen::set_vwindow(area);
	
	it = systemTouchWidgets->begin();
	
	while(it != systemTouchWidgets->end() && layer == 0)
	{
		TouchWidget* tw = static_cast<TouchWidget*>(*it);
		
		if((tw)->meet_condition(Touch::touch_point()))
		{
			isBiteByWidget = true;
			Touchable::execute(*it, ta);
		}
		it++;
	}
	
	Screen::restore_vwindow(r2);
*/
	if(isBiteByWidget)
		return;
	
	Touchable::execute(this, this);
}



