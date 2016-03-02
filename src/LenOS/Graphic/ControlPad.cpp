#include "controlPad.h"
#include "window.h"


ControlPad::ControlPad(int size, Color::ColorValue frontColor, Color::ColorValue backColor):
	TouchWidget(size, size), radius(size/2), controlRadius(radius/2), controlPos(centre_of_circle()), 
	frontColor(frontColor), backColor(backColor)
{
	leftEvent = rightEvent = downEvent = upEvent = idleEvent = 0;
}
void (*ControlPad::set_leftEvent(void (*e)()))()
{
	void (*old)() = leftEvent;
	leftEvent = e;
	return old;
}

void (*ControlPad::set_rightEvent(void (*e)()))()
{
	void (*old)() = rightEvent;
	rightEvent = e;
	return old;
}

void (*ControlPad::set_downEvent(void (*e)()))()
{
	void (*old)() = downEvent;
	downEvent = e;
	return old;
}

void (*ControlPad::set_upEvent(void (*e)()))()
{
	void (*old)() = upEvent;
	upEvent = e;
	return old;
}

void (*ControlPad::set_idleEvent(void (*e)()))()
{
	void (*old)() = idleEvent;
	idleEvent = e;
	return old;
}

int ControlPad::draw(Point p)
{
	drawed = true;
	controlPos = centre_of_circle();
	update();
	
	return 0;
}


int ControlPad::update(void *p)
{
	RectType rec = set_father_window(1);
	
	Graphic::draw_circle(centre_of_circle(), radius, backColor);
	Graphic::draw_circle(controlPos, controlRadius, frontColor);
	
	release_father_window(rec);
	return 0;
}


void ControlPad::touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father)				//触摸事件
{
	
}

int preExcute = -1;
void ControlPad::hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father)				//保持事件
{
	RectType rec = set_father_window(1);
	
	if(Graphic::distance(p, centre_of_circle()) < radius - controlRadius)
	{
		Graphic::draw_circle(controlPos, controlRadius, backColor);
		Graphic::draw_circle(p, controlRadius, frontColor);
		controlPos = p;
	}
	
  if(controlPos.x < centre_of_circle().x - controlRadius/2)
	{
		if(preExcute != 1 && leftEvent)
		{
			leftEvent();
			//Window *p = static_cast<Window*>(father);
			//p->iprintf(Point(0, 0), "Left");
			preExcute = 1;
		}
	}
	
	else if(controlPos.x > centre_of_circle().x + controlRadius/2)
	{
		if(preExcute != 2 && rightEvent)
		{
			rightEvent();
			//Window *p = static_cast<Window*>(father);
			//p->iprintf(Point(0, 0), "Right");
			preExcute = 2;
		}
	}
	
	else if(controlPos.y < centre_of_circle().y - controlRadius/2)
	{
		if(preExcute != 3 && upEvent)
		{
			upEvent();
			//Window *p = static_cast<Window*>(father);
			//p->iprintf(Point(0, 0), "Up");
			preExcute = 3;
		}
	}
	
	else if(controlPos.y > centre_of_circle().y + controlRadius/2)
	{
		if(preExcute != 4 && downEvent)
		{
			downEvent();
		//	Window *p = static_cast<Window*>(father);
		//	p->iprintf(Point(0, 0), "Down");
			preExcute = 4;
		}
	}
	else
	{
		if(preExcute != 5 && idleEvent)
		{
			idleEvent();
		
			preExcute = 5;
		}
	}
	

	release_father_window(rec);
}

void ControlPad::long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father)		//长按事件
{
	
}

void ControlPad::release_handler(const  Graphic::Point p, Touchable *self, Touchable* father)			//释放事件
{
	RectType rec = set_father_window(1);
	preExcute = -1;
	
	//controlPos = p;
	
	Graphic::draw_circle(controlPos, controlRadius, backColor);
	Graphic::draw_circle(centre_of_circle(), controlRadius, frontColor);
	
	controlPos = centre_of_circle();
	
	if(idleEvent)
 		idleEvent();
		
	release_father_window(rec);
	
 
}
	
