#ifndef __TOUCHPAD__
#define __TOUCHPAD__

#include "com.h"
#include "graphic.h"
#include "pad.h"
#include "touchable.h"

#include "touchWidget.h"

/*
	TouchPad��Ҫ���������¼��ķ���
	TouchPadΪ�����϶����touchWidgetά��һ������������
	������excute������ ��excute�����У� ȥɨ�败���������е�
	
	widgets
*/
/*
	�����ˣ�����ע�⣡������
	TouchPad��drag��ʵ�ֲ���Ԥ��Ҫ��ô���ģ� ��ֻ�����Լ���ϰ�ƶ��� ��������
	��ק�Ǹ�window�ṩ�ģ�
*/
//TouchPad����Դ������
class TouchPad: public Pad, public Touchable
{
public:
	Vector<Touchable*>*  touchWidgets;		//���п��Ա������Ŀؼ�����������
	Vector<Touchable*>*  systemTouchWidgets;

	static bool some_widget_down;
	
	bool drag;						//��־�Ƿ����ڱ�����
	bool pressed;					//��ǰ�Ƿ񱻰��£� ����meet_condition��
	
public:
	TouchPad(U16 _sizeX = 50, U16 _sizeY = 50, 
				Color::ColorValue cv = Color::RGB_BLUE, 
			void (*_touchHandler)(const  Graphic::Point p, 		Touchable *self, Touchable *father) = 0,					//�����¼�
			void (*_holdHandler)(const  Graphic::Point p, 		Touchable *self, Touchable *father) = 0,						//�����¼�
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father) = 0,				//�����¼�
			void (*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, Touchable *father) = 0
	 );
	
	virtual ~TouchPad();
	
	virtual TouchPad& add_widget(Widget* tw, Point p);				//��Ӵ����ؼ���
	
	virtual bool meet_condition(Graphic::Point touchPoint);			
	
	virtual void touch_handler(const  Graphic::Point p, 		Touchable *self, 	Touchable *father);				//�����¼�
	virtual void hold_handler(const  Graphic::Point p, 			Touchable *self, 	Touchable *father);				//�����¼�
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, 	Touchable *father);		//�����¼�
	virtual void release_handler(const  Graphic::Point p, 	Touchable *self, 	Touchable *father);			//�ͷ��¼�
	
	/*	
		������Touchable��execute�� 
		���ǵ�ԭ�� Touchable�е�executeִֻ��һЩ�¼��� ��
		TouchPad����Ҫִ���Լ����¼������һ���ִ�����ϵ�Widget
		���¼�.
	*/
	virtual void 	execute(Touchable* ta, Touchable *source);
};



#endif
