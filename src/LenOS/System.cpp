
#include "system.h"
#include "vector.h"
#include "touchable.h"
#include "touch.h"
#include "out.h"
#include "led.h"
#include "process.h"
#include "window.h"
#include "UserMain.h"

Vector<Touchable*> 		System::systemTouches;
Queue<System::Event>	System::eventQueue;
//Vector<Process*>  		System::proces;	//所有的进程

Vector<Proc*> 			System::processes;

/*
	中断函数中会执行该函数
	该函数扫描所有的touchable成员是否满足条件, 
	如果满足条件, 
*/
void System::touch_process()
{

	if(systemTouches.empty())
		return;
	
	if(-1 == Touch::update_state())
		return ;
	
	Vector<Touchable*>::iterator it;
	Vector<Touchable*>::iterator beg =  systemTouches.begin();
	it = beg;
	
	while(it != systemTouches.end())
	{
		int osize = systemTouches.size();
		
		if((*it)->meet_condition(Touch::touch_state().touchPoint))
			(*it)->execute(*it, *it);
		
		it++;
		
		if(systemTouches.pDatas != beg)
		{
			beg = systemTouches.begin();
			it = beg;
		}
		
		if(systemTouches.size() < osize)
		{
			it = beg;
		}
	}
}

//zai
void System::event_process()
{
	if(eventQueue.empty())
		return;
	
	while(eventQueue.empty() == false)
	{
		Event e = eventQueue.pop();
		
		switch(e.eventType)
		{
			case WindowDistroy:
				delete (Window*)e.pTarget;
				break;
			
			case ButtonEvent:
				
				break;
			case SystemEvent:
				break;
			
			case WindowEvent:
				break;
		}
	}
	
}

void System::process_process()
{
	Vector<Proc*>::iterator it = processes.begin();
	
	while(it != processes.end() )
	{
		if((*it)->state)
			(*it)->do_once();
		it++;
	}
}



void System::system_loop()
{
	bool a = true;
	user_init();
	while(1)
	{
		LED(a);
		a = !a;
		
		touch_process();
		event_process();
		process_process();
		user_loop();
	}
}

void System::system_init()
{
	Screen s(Color::RGB262K(0, 0, 0));
	Touch::init();
	LED_init();
}

/*
	系统System_init执行完成后会执行该函数， 在这个函数中用户可以
	配置自己的应用程序
*/
#include "UserMain.h"
void System::user_init()
{
	setup();
}

/*
	user_loop
	用户代码会加入到system_loop中执行
*/

void System::user_loop()
{
	static int i = 0;
	update(i++);
}


/*
	系统等待
	等待过程中依旧扫描屏幕
	等待过程中依旧进程执行
	...
*/
void System::system_wait()
{
	touch_process();
	process_process();
}

