

/*
	System
	System������LenOS�ĺ��Ĵ�����, ���е��¼�, �������뵽ϵͳ�Ķ�����, ��ϵͳ����, 
	������ѭ������, ����
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
		//�¼����Ͷ���
		typedef enum
		{
			WindowEvent,		//�����¼�
			SystemEvent,		//
			WindowDistroy,	//
			ButtonEvent,
		}EventType;
		
		typedef struct
		{
			EventType 	eventType;
			void* 		 	pTarget;
		}Event;
		
		//���̶���
		typedef struct
		{
			String* name;
			void (*handler)();
		}Process;
		
private:
		static Queue<Event> eventQueue;	//�¼�����
		
public:	
		static Vector<Touchable*> systemTouches;
		static Vector<Proc*> processes;
		
		static void touch_process();			//�������Touch����, ѡ���Ƿ���֮
		static void event_process();			//�¼�����
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
