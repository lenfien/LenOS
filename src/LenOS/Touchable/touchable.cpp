#include "com.h"
#include "touch.h"
#include "out.h"
#include "vector.h"
#include "touchable.h"
#include "system.h"
#include "Graphic.h"


using namespace std;

U32 Touchable::holdTime = 0;
bool Touchable::something_being_dragged = false;

Touchable::Touchable(
			Vector<Touchable*>* _pTouches,
			void (*_touchHandler)(const Graphic::Point p, Touchable *self, Touchable* father),				//�����¼�
			void (*_holdHandler)(const Graphic::Point p, Touchable *self, Touchable* father),					//�����¼�
			void (*_longHoldHandler)(const Graphic::Point p, Touchable *self, Touchable* father),			//�����¼�
			void (*_releaseHandler)(const Graphic::Point p, Touchable *self, Touchable* father)				//�ͷ��¼�
	):pTouches(_pTouches), _longHoldTime(200), touchHandler(_touchHandler),
				holdHandler(_holdHandler),longHoldHandler(_longHoldHandler),	releaseHandler(_releaseHandler)	
{
	if(pTouches && pTouches->find(this) == pTouches->end())
		pTouches->push_back(this);
}

Touchable::~Touchable()
{
	if(!pTouches)
		return ;
	
	Touchable** p = pTouches->find(this);
	if(p != pTouches->end())
		pTouches->erase(p);
}
	

//�Ƿ����������������¼�
bool Touchable::meet_condition(Graphic::Point p)
{
	return true;
}


/*
	����Լ��Ƿ����㴥������, ���������ִ����Ӧ�ĺ���
	��һ��������ʾta�Ĵ����ؼ�, source��ʾ����ؼ����ĸ�pad��
*/
#include "window.h"

void Touchable::execute(Touchable* ta, Touchable* source = 0)
{
	static bool preTouched = 0;
	static bool isExecuteLongHandler = false;	//���������Ƿ�ִ�й���
	static bool isExecuteTouchHandler = false;
	
	if(Touch::touch_state().isTouch && !isExecuteTouchHandler)
	{
		ta->touch_handler(touch_state().touchPoint, ta, source);
		if(ta->touchHandler)
		{
			ta->touchHandler(ta->touch_state().touchPoint, ta, source);
		}
		
		preTouched = true;
		isExecuteTouchHandler = true;
	}
	else if(preTouched && !touch_state().isTouch)
	{
		ta->release_handler(touch_state().touchPoint, ta, source);
		if(ta->releaseHandler)
			ta->releaseHandler(touch_state().touchPoint, ta, source);
		
		preTouched = 0;
		holdTime = 0;
		
		isExecuteLongHandler = false;
		isExecuteTouchHandler = false;
	}
	
	if(Touch::touch_state().isHold)
	{
		ta->hold_handler(touch_state().touchPoint, ta, source);
		
		if(ta->holdHandler)
			ta->holdHandler(touch_state().touchPoint, ta, source );
		
		holdTime ++;
	}
	
	if(holdTime >= ta->_longHoldTime && !isExecuteLongHandler)
	{
		ta->long_hold_handler(touch_state().touchPoint, ta, source);
		holdTime = 0;
		isExecuteLongHandler = false;
		if(ta->longHoldHandler)
			ta->longHoldHandler(touch_state().touchPoint, ta, source);
		
		isExecuteLongHandler = true;
	}
}

Vector<Touchable*>* Touchable::set_touch_vector(Vector<Touchable*>* newV)
{
	Vector<Touchable*>* o = pTouches;
	if(pTouches != newV)
	{
		if(pTouches)
			pTouches->erase(pTouches->find(this));
		pTouches = newV;
		newV->push_back(this);
	}
	return o;
}


unsigned int Touchable::long_hold_time()	{ return _longHoldTime;};
unsigned int Touchable::long_hold_time(unsigned nl)
{
	unsigned o = _longHoldTime;
	_longHoldTime = nl;
	return o;
}

void (*Touchable::set_touch_handler(void (*_touchHandler)(const Graphic::Point p, Touchable *self, Touchable* father)))(const Graphic::Point, Touchable *self, Touchable* father)
{
	void (*preTouchHandler)(const Graphic::Point p, Touchable *self, Touchable* father) = touchHandler;
	touchHandler = _touchHandler;
	return preTouchHandler;
}

void  (*Touchable::set_hold_handler(void (*_holdHandler)(const Graphic::Point p, Touchable *self, Touchable* father)))(const Graphic::Point, Touchable *self, Touchable* father)
{
	void (*preHoldHandler)(const Graphic::Point p, Touchable *, Touchable* ) = holdHandler;
	holdHandler = _holdHandler;
	return preHoldHandler;
}

void  (*Touchable::set_long_hold_handler(void (*_longHoldHandler)(const Graphic::Point p, Touchable *self, Touchable* father)))(const Graphic::Point, Touchable *self, Touchable* father)
{
	void (*preLongHoldHandler)(const Graphic::Point p, Touchable *, Touchable* ) = touchHandler;
	longHoldHandler = _longHoldHandler;
	return preLongHoldHandler;
}

void  (*Touchable::set_release_handler(void (*_releaseHandler)(const Graphic::Point p, Touchable *self, Touchable* father)))(const Graphic::Point, Touchable *self, Touchable* father)
{
	void (*preReleaseHandler)(const Graphic::Point p, Touchable *, Touchable* ) = releaseHandler;
	releaseHandler = _releaseHandler;
	return preReleaseHandler;
}

void Touchable::touch_handler(const Graphic::Point p, Touchable *self, Touchable* father)
{
	static int time = 1;
	Out::printl(0, 6, "Touch:%3d %3d %d", p.x, p.y, time++ );
}

void Touchable::hold_handler(const Graphic::Point p, Touchable *self, Touchable* father)
{
//	static int time = 1;
//	Out::printl(1, 2, "Hold:%d", time++);
}

void Touchable::long_hold_handler(const Graphic::Point p, Touchable *self, Touchable* father)
{
//	static int time = 1;
//	Out::printl(1, 3, "Long Hold:%d", time++);
}

void Touchable::release_handler(const Graphic::Point p, Touchable *self, Touchable* father)
{
	static int time = 1;
	Out::printl(1, 7, "Release:%d", time++);
}

