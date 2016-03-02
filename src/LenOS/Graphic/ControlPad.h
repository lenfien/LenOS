#ifndef __WIDGET_CONTROLPAD__
#define __WIDGET_CONTROLPAD__

#include "touchWIdget.h"
#include "color.h"


class ControlPad: public TouchWidget
{
	typedef enum
	{
		Left, Right, Down, Up, Idle
	}Dir;
	
	int	radius;
	int controlRadius;
	Point controlPos;
	
	void (*leftEvent)();
	void (*rightEvent)();
	void (*downEvent)();
	void (*upEvent)();
	void (*idleEvent)();
	
	Color::ColorValue frontColor;
	Color::ColorValue backColor;
	
	public:
	ControlPad(int size, Color::ColorValue frontColor = Color::RGB_RED, Color::ColorValue backColor = Color::RGB_GREEN);
	
	Point centre_of_circle() 
	{ 
		Point p = real_position();
		p.x += area.xSize/2;
		p.y += area.ySize/2;
		return p; 
	}
	
	virtual int draw(Screen::Point p);
	virtual int dedraw(){drawed = false; return 0;}
	virtual int update(void * = 0);
	
	virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//触摸事件
	virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//保持事件
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//长按事件
	virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//释放事件
	
	void (*set_leftEvent(void (*)()))();
	void (*set_rightEvent(void (*)()))();
	void (*set_downEvent(void (*)()))();
	void (*set_upEvent(void (*)()))();
	
	void (*set_idleEvent(void (*)()))();
};




#endif
