
#ifndef __WIDGET_TEXTBOX__
#define __WIDGET_TEXTBOX__

#include "graphic.h"
#include "touchwidget.h"
#include "string.h"
#include "out.h"
#include "font.h"
#include "pad.h"
#include "slider.h"
#include "color.h"

class TextBox: public TouchWidget
{
	private:
		String text;
		Slider *slider;
		
		Color::ColorValue  backColor;
		Color::ColorValue  fontColor;
		
	public:
		bool sliderEnable;	//是否显示Slider, 当为true时程序自动判断是否显示
		
	public:
		TextBox(String text,  U16 _sizeX, U16 _sizeY, Color::ColorValue fontColor= Color::RGB_WHITE, Color::ColorValue backColor = Color::RGB_BLACK);
		String set_text(String& _text);
		
		virtual ~TextBox();
		
		virtual int  draw(Point p);
		
		virtual int  dedraw()	{return 0;}
		virtual int  update(void* p = 0);
		
		virtual bool meet_condition(Graphic::Point touchPoint);				//是否满足激活条件
		
		virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//触摸事件
		virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);					//保持事件
		virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//长按事件
		virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//释放事件
		
		virtual void		set_father(Pad* f);
};


#endif
