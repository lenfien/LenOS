#ifndef __TOUCHPAD__
#define __TOUCHPAD__

#include "com.h"
#include "graphic.h"
#include "pad.h"
#include "touchable.h"

#include "touchWidget.h"

/*
	TouchPad主要用来处理事件的分配
	TouchPad为在其上定义的touchWidget维护一个触摸向量表，
	并覆盖excute函数， 在excute函数中， 去扫描触摸向量表中的
	
	widgets
*/
/*
	别忘了！！！注意！！！！
	TouchPad的drag的实现不是预设要这么做的， 而只是你自己练习移动， 而真正的
	拖拽是给window提供的！
*/
//TouchPad的资源管理类
class TouchPad: public Pad, public Touchable
{
public:
	Vector<Touchable*>*  touchWidgets;		//所有可以被触摸的控件都放在这里
	Vector<Touchable*>*  systemTouchWidgets;

	static bool some_widget_down;
	
	bool drag;						//标志是否正在被拖拉
	bool pressed;					//当前是否被按下， 用于meet_condition中
	
public:
	TouchPad(U16 _sizeX = 50, U16 _sizeY = 50, 
				Color::ColorValue cv = Color::RGB_BLUE, 
			void (*_touchHandler)(const  Graphic::Point p, 		Touchable *self, Touchable *father) = 0,					//触摸事件
			void (*_holdHandler)(const  Graphic::Point p, 		Touchable *self, Touchable *father) = 0,						//保持事件
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father) = 0,				//长按事件
			void (*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, Touchable *father) = 0
	 );
	
	virtual ~TouchPad();
	
	virtual TouchPad& add_widget(Widget* tw, Point p);				//添加触摸控件到
	
	virtual bool meet_condition(Graphic::Point touchPoint);			
	
	virtual void touch_handler(const  Graphic::Point p, 		Touchable *self, 	Touchable *father);				//触摸事件
	virtual void hold_handler(const  Graphic::Point p, 			Touchable *self, 	Touchable *father);				//保持事件
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, 	Touchable *father);		//长按事件
	virtual void release_handler(const  Graphic::Point p, 	Touchable *self, 	Touchable *father);			//释放事件
	
	/*	
		覆盖了Touchable的execute， 
		覆盖的原因： Touchable中的execute只执行一些事件， 而
		TouchPad不但要执行自己的事件，而且还是执行其上的Widget
		的事件.
	*/
	virtual void 	execute(Touchable* ta, Touchable *source);
};



#endif
