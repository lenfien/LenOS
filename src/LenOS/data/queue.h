#ifndef __QUEUE__
#define __QUEUE__

#include "com.h"
#include "vector.h"

template <typename T>
class Queue
{
	//数据定义
	public:
		Vector<T>* datas;
		int head;
		int tail;
		
	//构造
	public:
		Queue();
		Queue(Queue&);
		Queue& operator=(Queue&);
		~Queue();
		
	//操作
	private:
		/*
			整顿整个队列的内存区,
				1. 当tail == 0 && head = datas->cpacity时, 需要加大datas的容量, 此时的操作只是简单的向datas中继续添加(vector会自动增长)
				2. 插入数据时, 如果tail不等于0, 并且head == datas->capacity, 则将所有的数据往前动, 使tail = 0
				3. 如果head离capacity很远, 则将head之后的元素删除掉
		*/
		
	public:
		void 		arrange();
		Queue& 	push(T);
		T 			pop();
		bool 		empty();
};


template <typename T>
Queue<T>::Queue():datas(new Vector<T>()), head(-1), tail(0)	{}

template <typename T>
Queue<T>::Queue(Queue& q):datas(new Vector<T>(q)), head(q.head ), tail(q.tail)	{}
	
template <typename T>
void Queue<T>::arrange()
{
	if(tail > 10)	//如果数据偏离v头10个单位	. 则将它们移动到0的位置
	{
		datas->copy(datas->begin() + tail, datas->begin() + head + 1, datas->begin());
		head = head - tail;
		tail = 0;
	}
	
	if( head < datas->size() - 10)	//如果v中有浪费的10个, 在v的后面
		datas->clear(datas->begin() + head + 1);
	
	datas->resize();
}


template <typename T>
Queue<T>::
~Queue()
{
	delete datas;
}


template <typename T>
inline Queue<T>& Queue<T>::
push(T t)
{
	datas->push_back(t);
	head ++;
	arrange();
	return *this;
}


template <typename T>
inline T Queue<T>::
pop()
{
	T t;
	t = (*datas)[tail++];
	arrange();
	return t;
}


template <typename T>
bool Queue<T>::
empty()
{
	return tail > head;
}



#endif
