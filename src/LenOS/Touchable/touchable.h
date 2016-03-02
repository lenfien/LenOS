
/*
	Touchable
	概念: 所有继承Touchable的类, 都可以在满足条件时触发触摸事件
	Touchable类默认向系统提供的触摸控件向量表中添加控件, 并且从底层维护这些控件的触摸事件, 
	
	你也可以自己提供的一个向量表, 那么你必须自己维护自己所提供的向量表中的控件的触摸事件.
	似乎自己无法提供维护这些控件的触摸事件, 因为你不能向系统中断中添加函数, 概念上是不允许的. 
	但你可以这么想, 你提供一个TouchPad给系统, 系统会维护执行TouchPad触摸事件, 
	而TouchPad会维护一个自己的触摸控件向量,  TouchPad上的控件将自己的触摸向量设置为TouchPad所维护的触摸向量,  
	所以,你就可以在系统处理TouchPad的触摸事件时去处理Pad上所建立的控件的事件. 
	
	这就形成了一个层次系统, System ---> TouchPad --->Widget.
	
	细节: 当你向TouchPad添加控件时, TouchPad会调用Widget的set_touch_vector函数将Widget的触摸向量设置为自己的.
	
	问题: 在TouchPad的什么事件中去处理Widget的事件.
	
	解决方案: touch事件中处理所有控件的touch事件, 在释放事件中处理所有控件的释放事件, 等等, 
	但对于长按事件, 长按事件应该是系统全局的还是控件特有的呢, 更灵活的方式应该是控件特有的, 
	那该怎么实现呢?  所以, 上面的解决方案应该重新制定为: 在Pad的touch release 事件时, 
	检测控件并执行touch release事件, 在touchPad的hold事件中, 你不但得执行所有控件的 hold 事件,
	还得计数, 等等, 这个计数不是在touchable中已经记过了吗, 能不能从那里得到? 好吧, 
	Touchable应该在hold的同时给外界提供一个用户hold住屏幕的时间, 这个倒是合理的, 那就这么做.
	
	----------------------------------------------------------------------------------------------------
	Touchable类说明
	继承: Touch类
	功能:	继承Touchable的类都具有可触摸功能
	说明:	
	关于触摸:
		所有继承Touchable的类, 都会继承
		virtual void touch_handler(const Point p);				//在用户触摸屏幕时会激活此函数
		virtual void hold_handler(const Point p);				//在用户保持触摸屏幕一段时间内, 会重复执行该函数
		virtual void long_hold_handler(const Point p);		//在用户触摸屏幕一段可设置的时间后, 执行该函数, 并只执行一次
		virtual void release_handler(const Point p);			//在用户释放了触摸后执行该函数
		四个虚函数, 在你的类中, 你应该重新实现这四个函数.
		
	--------------------------------------------------------
	关于触摸条件:
		以上所有事件只在
		virtual bool meet_condition();		//是否满足激活条件
		返回真时执行函数
		此函数默认返回真, 所以你应该自己定义这个函数, 让在你想要的条件下才执行
		上面的函数
		
	---------------------------------------------------------
	关于长按事件的时间设置
		要使long_hold_handler执行一次, 用户按住屏幕的时间必须达到longHoldTime所设置的
		时间, 分辨率约为1ms, 你可可以手动调用:
		longHoldTime();
		来获得该值, 也可以调用
		longHoldTime(U32)
		来设置该值
	
	something_being_dragged:
	此变量被用来标志是否有东西正在被拖拽，为什么要设置这个变量呢， 因为如果一旦有东西
	被拖拽， 那么如果触摸点进入了另一个没有被拖拽的东西内， 那个物体的触摸事件也不会发生
	这个变量一般被用在 meet_condition函数中。
	这个变量只会在释放事件中， 而释放事件有时候会因为特殊情况而没有被执行，这会导致一个BUG
	（暂未解决）
	
	关于Touchable向量表的说明:
		Touchable会将自己添加到一个向量表中，这个向量表是用来在触摸发生时被主调函数扫描的，扫描
	的过程中会根据meet_contidition来判断是否执行《事件》， 所以， 必须让Touchable知道自己应该向
	哪一个向量表添加， 有两种途径可以指定Touchable的向量表：
		1.构造时，构造时将vector<Touchable*>* pTouches初始化为向量表的地址
		2.调用set_touch_vector设定Touchable的向量表， 该函数会将this从旧的向量表中取出， 然后再添加
		到新的向量表中
*/

#ifndef __TOUCHABLE__
#define __TOUCHABLE__

#include "touch.h"
#include "ads7843.h"
#include "vector.h"
#include "system.h"
#include "graphic.h"

class Touchable: public Touch
{
public:
	int					touchTimes;												//此数值在touch事件中增加一， 在release事件中减去1，所以如果进入touch事件中，此值为非0，则表示release没有被执行到， 则希望在touch事件中显执行release事件
	static bool something_being_dragged;					//往上看
	static U32 	holdTime;													//在hold时, touchable会向外界提供一个hold的时间积累量(用户自己维护触摸向量表时会用到)
	virtual void execute(Touchable* ta, Touchable* source);					//
	
public:
	/*
			因为不同的控件将使用不同空间向量表, 
			如button的控件向量表可能在Pad中, 
			而Pad的控件向量表在window中, window的控件向量在system中, 
			而所有的可触摸控件都继承touchable,
			所以这里指真实使用的touches向量的引用
	*/
	Vector<Touchable*>* pTouches;														//
	virtual Vector<Touchable*>* set_touch_vector(Vector<Touchable*>* );
	
	unsigned int _longHoldTime;															//激活长按状态时间
	void (*touchHandler)(const Graphic::Point p, Touchable *self, Touchable* father);					//触摸事件
	void (*holdHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);					//保持事件
  void (*longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);			//长按事件
	void (*releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);				//释放事件
	
public:
	virtual bool meet_condition(Graphic::Point touchPoint);				//是否满足激活条件
	
public:
	Touchable(
			Vector<Touchable*>* _pTouches = &System::systemTouches,
			
			void (*_touchHandler)(const  Graphic::Point p, 		Touchable *self, 	Touchable* father) = 0,					//触摸事件
			void (*_holdHandler)(const  Graphic::Point p, 		Touchable *self, 	Touchable* father) = 0,						//保持事件
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, 	Touchable* father) = 0,				//长按事件
			void (*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, 	Touchable* father) = 0					//释放事件				//释放事件
	);
	
	virtual ~Touchable();
	
public:
	unsigned int long_hold_time();						//获取long_hold_time的时间
	unsigned int long_hold_time(unsigned nl);	//设置long_hold_time的时间
	
	void (*set_touch_handler(void 	(*_touchHandler)(const 	Graphic::Point p, Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		//
	void (*set_hold_handler(void 	(*_holdHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		//
	void (*set_long_hold_handler(void 	(*_longHoldHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		
	void (*set_release_handler(void 	(*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		
	
protected:
	virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//触摸事件
	virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//保持事件
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//长按事件
	virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//释放事件
	
public:
	
};


#endif
