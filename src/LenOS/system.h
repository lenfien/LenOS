

/*
	System
	System是整个LenOS的核心处理部分, 所有的事件, 都将加入到系统的队列中, 被系统调度, 
	进程是循环进程, 将由
*/

#ifndef __SYSTEM__
#define __SYSTEM__


#include "vector.h"
#include "string.h"
#include "queue.h"
#include "process.h"


class Touchable;
class System
{
public:
		//事件类型定义
		typedef enum
		{
			WindowEvent,		//窗体事件
			SystemEvent,		//
			WindowDistroy,	//
			ButtonEvent,
		}EventType;
		
		typedef struct
		{
			EventType 	eventType;
			void* 		 	pTarget;
		}Event;
		
		//进程定义
		typedef struct
		{
			String* name;
			void (*handler)();
		}Process;
		
private:
		static Queue<Event> eventQueue;	//事件队列
		
public:	
		static Vector<Touchable*> systemTouches;
		static Vector<Proc*> processes;
		
		static void touch_process();			//检测所有Touch对象, 选择是否处理之
		static void event_process();			//事件队列
		static void push_event(Event e) {eventQueue.push(e);}
		static void process_process();
		
		static void system_loop();
		static void system_init();
		static void user_init();
		static void user_loop();
		
		static void system_wait();
private:
		System(){}
};




#endif
