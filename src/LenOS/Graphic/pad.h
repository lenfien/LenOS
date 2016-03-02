
/*
Pad的概念
		是一个控件容器, 并且可以无损移动, 和 TouchPad不同的是, PAD
		主要用来维护图形方面的事情, 而touchpad主要用来维护事件方面的
		事情.
		
应该实现的功能:
		建立一个vector, 这个vector内存的是widget&类型的控件, 
		应该有一个起始坐标和尺寸大小, 之后所有的控件的现实将按照起始坐标的相对位置显示.
		可以实现无损移动, 应该有一个Datas<Color::ColorType>数据类型,
		并有一个move函数, 这个move函数应该会调用recover 和 record的函数.
		当然, draw函数不能忘, 因为draw是c纯虚函数来着.
		是否需要COlor? 背景色嘛, 要上吧
	如果可以的话, 添加布局属性
		中间, 左对齐, 右对齐, 上对齐, 下对齐.
	当Pad被激活时, Pad应该循环的执行一个函数, 这个函数可以循环的调用每一个空间的
	更新函数(update).
*/

#ifndef __PAD__
#define __PAD__

#include "vector.h"

#include "color.h"
#include "graphic.h"

class Pad;

/*
	所有创建的Pad都在这里
*/
class PadSources
{
public:
	static Vector<Pad*>		pads;
};

class Widget;

class Pad: public Graphic
{
	friend class PadSources;
	
protected:
			
/***********************数据成员**************************/
//-------------空间相关--------------------//
			Vector<Widget*> 				widgets; 
			
//-------------无损移动相关----------------//
			Datas<Color::ColorType> backUp;
			//Datas<Color::ColorType> backUpFront;		//对前景色的备份， 主要用于active的无损还原和move的无损移动
			
			Datas<Color::ColorType> backUpFrame[4];		//用来存储Pad的边框， 移动pad时使用
			
//-------------尺寸相关-------------------//
public:
			RectType area;
			RectType validArea;
			
			virtual RectType& valid_area(int i = 0)	{return area;}
			virtual RectType& all_area()							{return area;}
			Color::ColorValue				backColor;
			
			int layer;
			void draw_frame(Point p);		
			
/***********************函数成员****************************/
//-------------构造函数---------------//
public:
			Pad(U16 _sizeX = 100, U16 _sizeY = 50, 
			Color::ColorValue cv = Color::RGB_BLUE);
			
			virtual ~Pad();
			
public:
			/*
				存储和恢复	
			*/
			virtual void record(bool front = false);
			virtual void recover(bool front = false);
			virtual void record_frame(Point p);
			virtual void recover_frame();
			/*
					更新所有控件的相对位置， 
					此函数被用在position被改变之后
			*/
			void 		
			update_widgets_rela_position();	//当移动Pad时, 所有的空间的相对位置都会变化, 所以, 必须更新所有widgets的相对位置
			
public:
			/*
					从旧位置移动到新位置， 并且激活
			*/
			bool 		
			move(Point newLeftTop);
			
			/*
					向控件向量表中添加Widget
			*/
			virtual Pad& 
			add_widget(Widget* w, Point p);
			
			/*
					定义控件相对于Pad左上角的偏移位置
			*/
			inline virtual Point 
			widget_off_position() {return Point(1, 1);}
			
public:			
			virtual int  active();												//将自己放在最高曾, 并修复其它被覆盖的层
			bool if_covered(RectType r);									//
			bool if_coverd();															//
			bool if_covered(Point p);											//点p处是否有层高于自己的其它pad,在判断点击事件时使用
			bool if_in(Point p, RectType& r);							//点p是否在Pad内
			void draw_bitmap(Graphic::RectType newArea, Graphic::RectType& oldArea,  
					Datas<Color::ColorType >& pic);
			
public:
			virtual int 	draw(Graphic::Point p);	
			virtual int 	dedraw();								//除去显示
			virtual int 	update(void* p = 0);	// {draw_myself();}	
			
			void redraw_all();

};

#endif
