#ifndef __SLIDER__
#define __SLIDER__
#include "button.h"
#include "touchWidget.h"
#include "graphic.h"
#include "touchpad.h"
#include "color.h"
/*
	Slider是一个控件， 这个控件包含一个控子，这个控子可以被拖动， 并且有两种显示方式，横向和竖向
	拖动Slider中的控子时， Slider随时更新控子的值.
	控子的值在一个范围内，这个范围由用户指定。
	Slider包含两个按钮， 一个增加控子的位置，另一个减小。
*/

class Slider: public TouchWidget
{
	public:
	typedef enum
	{
		VERTICAL,
		HORIZON
	}DIR;
	
private:
	int 		curPos;					//当前位置
	int 		range;					//Slider所表示的总范围
	int 		page;						//一页所占的范围, 可以计算控子的长度(控子的长度在size中占的比例跟page在range中占的比例相同)
	DIR 		direction;			//方向
	int 		controlLength;	//控制条的长度
	double 	perRange;				//每一个range代表多少个像素
	
	Color::ColorValue backColor;
	Color::ColorValue controlColor;
	
	/*
		被控子控制的对象， 拖动条会调用controlObj中的update函数来实时的更新controlObj的显示
	*/
	Graphic* controlObj;
	
public:
	
	Slider(int range,  int _page, DIR dir, int bold, int length, 
						Color::ColorValue backColor = Color::RGB_RED, Color::ColorValue controlColor = Color::RGB_BLUE);
	
	virtual 	~Slider()	{	drawed = false;	}
	
	int 			get_pos();
	Graphic*	set_controlObj(Graphic* g);
	void			set_range(int range, int page);
	
	virtual int 	draw(Point p);
	virtual int 	dedraw() {return 0;}
	virtual int 	update(void *p = 0);
	
	virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//触摸事件
	virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);					//保持事件
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//长按事件
	virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//释放事件
};



#endif
