/*
WindowResources
维护所有创建的窗口资源， 使window的概念只局限于单个窗口（Window类的对象只代表一个窗口，如果Window内却去定义其它的window资源， 概念上不允许）

Window
功能：1.可以在其上放置TouchWidget或Widget
	它们的维护方式都不同，Pad维护Widget和TouchWidget， 而TouchPad维护TouchWidget，
		前者的维护工作只是图形上的， TouchPad维护的是TouchWidget的事件。
		2.加入层的概念
			第0层的是激活的窗口，每次激活一个窗口，要做以下的工作：
			1.先将激活的窗口还原
			2.将给所有其它窗口的层加上1
			3.对窗口向量表根据层数从大到小重新进行排序
			4.按照排序的结果重新分配层，最小从1开始
			5.按照层从大到小重新绘制所有窗口
			6.绘制当前激活的窗口
		3.对界面的重新调整。
		加入标题栏，加宽边框， 当激活时，更改边框颜色，不引入新坐标， 只是你在向window添加控件时，将在你设置的坐标上加上一个边框的宽度就行了。
		4.对激活的处理
		当你触摸在两个窗口共享的区域的里时，应该根据层的概念，那个层小，就激活哪个。 其实可以利用窗口向量表中的顺序进行扫描，
		扫描到有一个可以执行了，就不去继续扫描了， 所以， Window应该重新定义execute函数。
		5，进程函数， 将自己加入进程（之后添加）
并可对Widget的事件进行管理
UI：具有两个TouchPad， 一个为标题， 一个
实现方法：
继承： Graphic
数据：Vector<Pad*>
*/

#ifndef __WINDOW__
#define __WINDOW__

#include "touchpad.h"
#include "string.h"
#include "Graphic.h"
#include "font.h"
#include "color.h"
#include "system.h"
#include "button.h"
#include "slider.h"
#include "paintable.h"

class Window: public TouchPad, public Paintable
{
	private:
			static void shutdown_handler(Point p, Touchable *self, Touchable *father );
			
	private:
			String name;
			
			Button *distroyButton;		//用来摧毁整个window的button
			
			Slider *horizonSlider;		//水平滚动条
			Slider *verticalSlider;		//垂直滚动条
			
			Color::ColorValue titleColor;
			Proc 	process;			//窗口进程
			Point vPosition;		//窗口的虚拟起始位置， 所有的控件都遵循这个虚拟的起始位置开始显示
			void 	(*userUI)(Window*);					//用户的UI定义在这个函数里
	
	public:
			void 	(*set_UI(void (*)(Window*)))(Window*);	
	
	/*
			配置窗口的显示
	*/
	public:
			bool 	sliderEnable;	//是否显示Slider
			bool 	closeEnable;	//是否显示关闭按钮
			bool 	titleEnable;	//是否显示标题栏
	
	public:	
/*数据提取与设置*/
	
			int 	high_of_title() 	{return distroyButton->area.ySize;	}															//
			Point valid_position()	{return area.position + Point(1, high_of_title() + 1);}		//可用的绘图地方
			
			virtual Point widget_off_position() {return Point(1, high_of_title()) - vPosition; }
			
			//Color::ColorValue set_color(Color::ColorValue cv) { this-> }
			void 	(*close_handler)(Window* w);
			void (*set_close_handler(void (*h)(Window*)))(Window* w);
			
			/*
				获取可由用户配置的矩形区域
			*/
			virtual RectType& valid_area(int i = 0);
			
/*构造与析构函数*/			
	public:
			Window(String name = "No name", 
			U16 _sizeX = 50, U16 _sizeY = 50,
			Color::ColorValue cv = Color::RGB_BLUE, 
			void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,					//触摸事件
			void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,						//保持事件
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//长按事件
			void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0
			);
			
			virtual ~Window();
			
/*功能模块*/
			void 					update_slider();
			
			virtual Window& add_widget(Widget* tw, Point p);				//添加触摸控件到
			virtual int 	update(void*);
			virtual int 	draw(Point p = Point(-1, -1));
			virtual void 	touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//触摸事件
			virtual void 	hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );					//保持事件
			virtual void 	long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );		//长按事件
			virtual void 	release_handler(const  Graphic::Point p, Touchable *self, Touchable *father );			//释放事件
			
			void add_thread(void (*)());			//添加线程
			void delete_thread(void (*)());		//取消线程
			void run_process();
			
			void dispose();
			
};




#endif
