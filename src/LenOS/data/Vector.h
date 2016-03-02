#ifndef __VECTOR__
#define __VECTOR__
#include <cstdio>
#include <cstdlib>

#include "com.h"

template <typename T> class Queue;

template <typename T>
class Vector
{	
		friend class Queue<T>;
	
public:
		typedef T Type;
		typedef Type* PType;
		typedef T* iterator;
		typedef const Type* const_iterator;
		typedef U32 size_t;
		T* 			pDatas; 				//Vector所存数据的头地址
		bool 		isResized;

private:
		
		size_t _capacity;				//总容量
		size_t _size;						//当前占用
		bool		dynamicAdjust; 	//是否动态调整内存(即无用内存多时, 是否收回)
private:
		/*
			将beg到end到PType所指的内存空间, 
			注意: 此函数不会释放当前内存
		*/
		size_t copy(const_iterator beg, const_iterator end, PType dis);	
		
		/*
				删除
		*/
		bool remove(PType);
		size_t resize();
		
public:
		Vector();							//默认构造
		Vector(Vector& v);		//复制构造函数
		Vector(unsigned);			//按照尺寸大小创建
		Vector(const_iterator beg, const_iterator end);
		~Vector();
		
		Vector<T>& clear();						//清除所有内容,使vector像一个刚建立的空vector一样
		Vector<T>& clear(PType p);		//清除掉p之后的所有元素 
		bool empty() const {return _size == 0;}
		
		T& operator[](unsigned index);
		S8 operator==(const Vector<T>& v);
		
		Vector& push_back(const Type&);	//从后面插入 ... 邪恶
		Vector& erase(PType);						//删除
		PType		find(const Type&);			//找到
		
		size_t capacity() const;				//总容量
		size_t size() const;						//当前尺寸
		size_t remain() const;					//剩余
		
		iterator begin() const;
		iterator end() const;
		iterator rbegin()	const;
		iterator rend() const;
};

/***********************************构造函数开始******************************************/

template<typename T> 
Vector<T>::Vector():pDatas(0), _capacity(0), _size(0), dynamicAdjust(true)
{
	
}

template<typename T> 
Vector<T>::Vector(Vector& v):_capacity(v._capacity), _size(v._size), dynamicAdjust(true)
{
	if(v.pDatas == null)
	{
		pDatas = null;
		return;
	}

	pDatas = new T[v._capacity];
	
	copy(v.begin(), v.end(), pDatas);
}

template<typename T> 
Vector<T>::Vector(size_t size):_capacity(size), _size(0), dynamicAdjust(false)
{
	pDatas = new T[_capacity];
}

template<typename T> 
Vector<T>::Vector(const_iterator beg, const_iterator end)
{
	if(beg > end || beg || end)
	{
		pDatas = 0;
		_capacity = _size = 0;
	}
	
	_size = end - beg;
	_capacity = _size + 10;
	
	pDatas = new T[_capacity];
	
	copy(beg, end, pDatas);
}

template<typename T> 
Vector<T>::~Vector()
{
	if(pDatas)
		delete pDatas;
}

/************************构造函数结束 ***************************/

template<typename T> 
Vector<T>& Vector<T>::clear()
{
	if(dynamicAdjust && pDatas)
	{
		delete [] pDatas;
		pDatas = 0;
		_capacity = 0;
	}
	_size = 0;
	return *this;
}

//删除p所指元素后面的所有元素, 包括p所指
template<typename T> 
Vector<T>& Vector<T>::clear(PType p)
{
	if(p < begin() || p >= end())
		return *this;
	
	_size -= (end() - p);
	resize();
	
	return *this;
}


//将begin到end之间的内容存储傲dis所指区域
//返回复制的元素的个数
template<typename T> 
Vector<T>::size_t Vector<T>::copy(const_iterator beg, const_iterator end, PType dis)
{
	if(beg == null || end == null || end < beg || dis == null)
		return 0;
	
	for(const_iterator it = beg; it != end; it++, dis++)
			*dis = *it;
	
	return end - beg;
}


/*
	重新分配内存
	分配策略:
		保持capacity的大小在 size + 5 到 size + 15之间
	如果超过了这个返回(capacity < size + 5) 或者 capacity > _size + 15
	就将capacity置位 size + 10
	这样做的好处是, 内存可以动态的调整, 不会造成内存泄露, 或者溢出
*/
template<typename T> 
Vector<T>::size_t Vector<T>::resize()
{
	size_t newCapacity;
	PType pt;
	
	if(_size + 5 < _capacity && _capacity < _size + 15)
		return _capacity;
	
	isResized = true;
	
	newCapacity = _size + 10;
	
	pt = new T[newCapacity];
	
	if(pDatas)
	{
		copy(begin(), end(), pt);
		delete [] pDatas;
	}
	
	pDatas = pt;
	
	_capacity = newCapacity;
	return _capacity;
}


template<typename T> 
bool Vector<T>::remove(PType p)
{
	if(p < begin() || p >= end())
		return false;
	
	copy(p + 1, end(), p);
	
	_size--;
	
	resize();
	return true;
}


template<typename T> 
Vector<T>& Vector<T>::push_back(const Type& t)
{
	if(dynamicAdjust)
		resize();
	
	pDatas[_size] = t;
	_size ++;
	return *this;
}

template<typename T> 
Vector<T>& Vector<T>::erase(PType t)
{
	if(t < end() && t >= begin())
		remove(t);
	return *this;
}


template<typename T> 
Vector<T>::PType Vector<T>::find(const Type& t)
{
	iterator it = 0;
	for(it = begin(); it != end(); it ++)
			if(*it == t)
				break;
	return it;
}

template<typename T> 
inline Vector<T>::size_t Vector<T>::capacity()	  const			//总容量
{
	return _capacity;
}

template<typename T> 
inline Vector<T>::size_t Vector<T>::size()	  const			//总容量
{
	return _size;
}

template<typename T> 
inline Vector<T>::size_t Vector<T>::remain()  const
{
	return _capacity - _size;
}

template<typename T> 
inline Vector<T>::iterator Vector<T>::begin() const
{
	return pDatas;
}

template<typename T> 
inline Vector<T>::iterator Vector<T>::end() const
{
	if(_size == 0)
		return pDatas;
	return pDatas + _size;
}

template<typename T> 
inline Vector<T>::iterator Vector<T>::rbegin() const
{
	if(_size == 0)
		return pDatas;
	return pDatas + _size - 1;
}

template<typename T> 
inline Vector<T>::iterator Vector<T>::rend() const
{
	if(_size == 0)
		return pDatas;
	return pDatas - 1;
}

template<typename T>
inline T& Vector<T>::operator[](unsigned int index)
{
	return pDatas[index];
}

template<typename T>
inline S8 Vector<T>::operator==(const Vector<T>& v)
{
	const_iterator it = begin();
	
	Vector<T>::const_iterator _it = v.begin();
	
	for(; it != end() && _it != v.end(); it++, _it++ )
	{
		if(*it == *_it)
			continue;
		else
			return *it - *_it;
	}
	
	if(*it == *end() && *_it == *(v.end()))
		return 0;
	
	if(*it == *end())
		return -1;
	
	return 1;
	
}

#endif
