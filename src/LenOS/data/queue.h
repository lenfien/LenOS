#ifndef __QUEUE__
#define __QUEUE__

#include "com.h"
#include "vector.h"

template <typename T>
class Queue
{
	//���ݶ���
	public:
		Vector<T>* datas;
		int head;
		int tail;
		
	//����
	public:
		Queue();
		Queue(Queue&);
		Queue& operator=(Queue&);
		~Queue();
		
	//����
	private:
		/*
			�����������е��ڴ���,
				1. ��tail == 0 && head = datas->cpacityʱ, ��Ҫ�Ӵ�datas������, ��ʱ�Ĳ���ֻ�Ǽ򵥵���datas�м������(vector���Զ�����)
				2. ��������ʱ, ���tail������0, ����head == datas->capacity, �����е�������ǰ��, ʹtail = 0
				3. ���head��capacity��Զ, ��head֮���Ԫ��ɾ����
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
	if(tail > 10)	//�������ƫ��vͷ10����λ	. �������ƶ���0��λ��
	{
		datas->copy(datas->begin() + tail, datas->begin() + head + 1, datas->begin());
		head = head - tail;
		tail = 0;
	}
	
	if( head < datas->size() - 10)	//���v�����˷ѵ�10��, ��v�ĺ���
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
