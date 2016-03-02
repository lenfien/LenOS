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
		T* 			pDatas; 				//Vector�������ݵ�ͷ��ַ
		bool 		isResized;

private:
		
		size_t _capacity;				//������
		size_t _size;						//��ǰռ��
		bool		dynamicAdjust; 	//�Ƿ�̬�����ڴ�(�������ڴ��ʱ, �Ƿ��ջ�)
private:
		/*
			��beg��end��PType��ָ���ڴ�ռ�, 
			ע��: �˺��������ͷŵ�ǰ�ڴ�
		*/
		size_t copy(const_iterator beg, const_iterator end, PType dis);	
		
		/*
				ɾ��
		*/
		bool remove(PType);
		size_t resize();
		
public:
		Vector();							//Ĭ�Ϲ���
		Vector(Vector& v);		//���ƹ��캯��
		Vector(unsigned);			//���ճߴ��С����
		Vector(const_iterator beg, const_iterator end);
		~Vector();
		
		Vector<T>& clear();						//�����������,ʹvector��һ���ս����Ŀ�vectorһ��
		Vector<T>& clear(PType p);		//�����p֮�������Ԫ�� 
		bool empty() const {return _size == 0;}
		
		T& operator[](unsigned index);
		S8 operator==(const Vector<T>& v);
		
		Vector& push_back(const Type&);	//�Ӻ������ ... а��
		Vector& erase(PType);						//ɾ��
		PType		find(const Type&);			//�ҵ�
		
		size_t capacity() const;				//������
		size_t size() const;						//��ǰ�ߴ�
		size_t remain() const;					//ʣ��
		
		iterator begin() const;
		iterator end() const;
		iterator rbegin()	const;
		iterator rend() const;
};

/***********************************���캯����ʼ******************************************/

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

/************************���캯������ ***************************/

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

//ɾ��p��ָԪ�غ��������Ԫ��, ����p��ָ
template<typename T> 
Vector<T>& Vector<T>::clear(PType p)
{
	if(p < begin() || p >= end())
		return *this;
	
	_size -= (end() - p);
	resize();
	
	return *this;
}


//��begin��end֮������ݴ洢��dis��ָ����
//���ظ��Ƶ�Ԫ�صĸ���
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
	���·����ڴ�
	�������:
		����capacity�Ĵ�С�� size + 5 �� size + 15֮��
	����������������(capacity < size + 5) ���� capacity > _size + 15
	�ͽ�capacity��λ size + 10
	�������ĺô���, �ڴ���Զ�̬�ĵ���, ��������ڴ�й¶, �������
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
inline Vector<T>::size_t Vector<T>::capacity()	  const			//������
{
	return _capacity;
}

template<typename T> 
inline Vector<T>::size_t Vector<T>::size()	  const			//������
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
