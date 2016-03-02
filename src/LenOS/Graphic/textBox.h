
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
		bool sliderEnable;	//�Ƿ���ʾSlider, ��Ϊtrueʱ�����Զ��ж��Ƿ���ʾ
		
	public:
		TextBox(String text,  U16 _sizeX, U16 _sizeY, Color::ColorValue fontColor= Color::RGB_WHITE, Color::ColorValue backColor = Color::RGB_BLACK);
		String set_text(String& _text);
		
		virtual ~TextBox();
		
		virtual int  draw(Point p);
		
		virtual int  dedraw()	{return 0;}
		virtual int  update(void* p = 0);
		
		virtual bool meet_condition(Graphic::Point touchPoint);				//�Ƿ����㼤������
		
		virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//�����¼�
		virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);					//�����¼�
		virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//�����¼�
		virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//�ͷ��¼�
		
		virtual void		set_father(Pad* f);
};


#endif
