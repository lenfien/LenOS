/*

*/
#ifndef __TOUCHWIDGET__
#define __TOUCHWIDGET__

#include "com.h"
#include "vector.h"
#include "widget.h"
#include "graphic.h"
#include "touchable.h"

#include "system.h"
class TouchPad;

class TouchWidget: public Widget, public Touchable
{
	public:
		TouchWidget(
			U16 _sizeX = 100, 
			U16 _sizeY = 50, 
			Vector<Touchable*>* touches = 0,
			void (*_touchHandler)(const  Graphic::Point p, 		Touchable* self, Touchable* father) = 0,					//触摸事件
			void (*_holdHandler)(const  Graphic::Point p, 		Touchable* self, Touchable* father) = 0,					//保持事件
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable* self, Touchable* father) = 0,					//长按事件
			void (*_releaseHandler)(const  Graphic::Point p, 	Touchable* self, Touchable* father)	= 0
			);
		
		TouchPad* 			touchFather;
		
		virtual bool		meet_condition(Graphic::Point p);
		virtual bool 		is_touch_widget() {return true;}
		
		bool pressed;
};


#endif
