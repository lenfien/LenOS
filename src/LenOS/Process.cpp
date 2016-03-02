#include "vector.h"
#include "process.h"
#include "system.h"


Proc::Proc()
{
		(System::processes).push_back(this);
		state = false;
}

Proc::~Proc()
{
	(System::processes).erase(System::processes.find(this));
}

void Proc::add_thread(void (*thread)())
{
	threads.push_back(thread);
}

void Proc::delete_thread(void (*thread)())
{
	threads.erase(threads.find(thread));
}

void Proc::do_once()
{
	Vector<ThreadType>::iterator it;

	for(it = threads.begin(); it != threads.end(); it++)
		(*it)();
}
