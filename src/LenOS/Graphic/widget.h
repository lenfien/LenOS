/*
Widget
	是一个虚基类, 这个徐虚基类主要给Pad的Vector<Widget&>做铺垫, 
	而Pad类主要只调用Widget的大小, 相对位置, 尺寸信息, 
	可能还会调用一些获取此widget的其它信息的函数, 在此定义为get_info, 
	当然, update是更新控件的函数, 此函数会被Pad在被激活, 并且空闲时执行
	~Widget析构函数也是被pad调用的.
	每一个Widget都有一个相对于Pad左上角的坐标, 而只有在draw时, 
	才能知道这个坐标, draw会传给Widget这个坐标, 而这个draw一般
	是被pad调用的.
*/
#ifndef __WIDGET__
#define __WIDGET__
#include "com.h"
#include "graphic.h"
#include "touchable.h"

class Pad;

class Widget: public Graphic
{
	protected:
		Widget(
				U16 _sizeX = 100, 
				U16 _sizeY = 50 
		);
	
	public:
		virtual ~Widget() {}
		
	public:
		Point 						relaPosition;						//定义空间的相对位置
		Graphic::RectType area;				
		Pad*							father;									//Widget在哪个Pad上
		bool							dignity;								//一个控件的dignity标志了控件是系统控件还是普通控件
		
	public:
		virtual bool 		is_touch_widget()	{return false;}					//是否为TouchWidget
		
		virtual void 		set_position(Graphic::Point p)	{area.position = p;}
		
		virtual Point 	set_relataive_position(Point p);
		
		virtual Point 	real_position()	{ return area.position + relaPosition;}
		
		virtual RectType 
										real_area()		
		{
			RectType r = area;
			r.position = real_position();
			return r;
		}
		
		virtual void		set_father(Pad* f) {father = f; }
		
		/*
			v = false 全部区域
			v= true		valid 区域
			x, y 为偏移量
		*/
		virtual RectType 	set_father_window(bool v = 0, int x = 0, int y = 0);
		virtual void		release_father_window(Graphic::RectType);
		
	public:
		virtual int draw(Point p = Point(0, 0)) = 0;
		virtual int update(void *p = 0) = 0;		//有的控件可能会更新自己， 可以在这个函数里写
};


#endif
