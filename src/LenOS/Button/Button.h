
#ifndef __BUTTON__
#define __BUTTON__

#include "vector.h"
#include "graphic.h"
#include "widget.h"
#include "touchWidget.h"
#include "system.h"
#include "string.h"
#include "color.h"


class Button: public TouchWidget
{
public:
	typedef struct
	{
		Color::ColorValue contentColor;
		Color::ColorValue backColor;
		Color::ColorValue frameColor;
	}ButtonColor;
	String 			content;	//文字内容
	
private:
	bool				pressed;	//表示button是否当前被按下
	
public:
	String			get_content();
	String 			set_content(String newContent);
	
	ButtonColor buttonColor;
	
	Button(	
					String _content,  
					U16 _sizeX = 50,
					U16 _sizeY = 20,
					void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,					//触摸事件
					void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,						//保持事件
					void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//长按事件
					void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//释放事件
					Vector<Touchable*>* touches = &System::systemTouches					//
		);
	
	virtual ~Button() 
	{
		drawed = false; 
	}
	
	
	bool  				draw_myself();										//仅仅是按照当前的参数绘制自己
	virtual int   dedraw();
	virtual int  	draw(Graphic::Point p = Graphic::Point(-1, -1));
	
	virtual void* get_info();
	virtual int 	update(void* p = 0);

private:
	virtual void 	touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//触摸事件
	virtual void 	hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//保持事件
	virtual void 	long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );		//长按事件
	virtual void 	release_handler(const  Graphic::Point p, Touchable *self, Touchable *father );			//释放事件
};


#endif
