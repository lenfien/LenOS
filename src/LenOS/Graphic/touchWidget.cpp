#include "widget.h"
#include "vector.h"
#include "touchWidget.h"
#include "touchpad.h"

TouchWidget::TouchWidget(
						U16 	_sizeX, 
						U16 	_sizeY, 
						Vector<Touchable*>* touches,
						void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father),					//�����¼�
						void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father),						//�����¼�
						void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father) ,				//�����¼�
						void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father)	
			):Widget(_sizeX, _sizeY), Touchable(touches, _touchHandler, _holdHandler, _longHoldHandler, _releaseHandler)
{
	
}

bool TouchWidget::meet_condition(Graphic::Point p)
{
	return Graphic::is_in_rectangle(p, real_area()) && drawed;
}
