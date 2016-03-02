
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
	String 			content;	//��������
	
private:
	bool				pressed;	//��ʾbutton�Ƿ�ǰ������
	
public:
	String			get_content();
	String 			set_content(String newContent);
	
	ButtonColor buttonColor;
	
	Button(	
					String _content,  
					U16 _sizeX = 50,
					U16 _sizeY = 20,
					void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,					//�����¼�
					void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,						//�����¼�
					void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//�����¼�
					void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//�ͷ��¼�
					Vector<Touchable*>* touches = &System::systemTouches					//
		);
	
	virtual ~Button() 
	{
		drawed = false; 
	}
	
	
	bool  				draw_myself();										//�����ǰ��յ�ǰ�Ĳ��������Լ�
	virtual int   dedraw();
	virtual int  	draw(Graphic::Point p = Graphic::Point(-1, -1));
	
	virtual void* get_info();
	virtual int 	update(void* p = 0);

private:
	virtual void 	touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//�����¼�
	virtual void 	hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//�����¼�
	virtual void 	long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );		//�����¼�
	virtual void 	release_handler(const  Graphic::Point p, Touchable *self, Touchable *father );			//�ͷ��¼�
};


#endif
