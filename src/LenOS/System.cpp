
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
//Vector<Process*>  		System::proces;	//���еĽ���

Vector<Proc*> 			System::processes;

/*
	�жϺ����л�ִ�иú���
	�ú���ɨ�����е�touchable��Ա�Ƿ���������, 
	�����������, 
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
	ϵͳSystem_initִ����ɺ��ִ�иú����� ������������û�����
	�����Լ���Ӧ�ó���
*/
#include "UserMain.h"
void System::user_init()
{
	setup();
}

/*
	user_loop
	�û��������뵽system_loop��ִ��
*/

void System::user_loop()
{
	static int i = 0;
	update(i++);
}


/*
	ϵͳ�ȴ�
	�ȴ�����������ɨ����Ļ
	�ȴ����������ɽ���ִ��
	...
*/
void System::system_wait()
{
	touch_process();
	process_process();
}

