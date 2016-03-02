#ifndef __PROCESS__
#define __PROCESS__


#include "vector.h"


class Proc
{
	friend class System;
	private:
		typedef void (*ThreadType)();
		Vector<ThreadType> threads;
		bool 	state;
		
		
	public:
		Proc();
		~Proc();
		
		void add_thread(void (*thread)());
		void delete_thread(void (*thread)());
		
		void run()  {state = true;}
		void stop() {state = false;}
			
		void do_once();
};

#endif
