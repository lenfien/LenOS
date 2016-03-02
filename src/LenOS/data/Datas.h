/*
	给Datas里面存数据的同时, 会压缩数据, 可对用户是透明的
	
	对Datas类的详细说明:
		Datas类是一个用来存储并压缩数据的类, 你可以通过push_back来向
		Datas对象中存入"任意类型"的数据, 并且在存入的同时, Datas类会根据
		相应的算法压缩你存入的数据, 具体的压缩算法后面会讲到.
		除了会对数据压缩以外, Datas类大致上是和Vector类相似, 因为你可以
		push_back, 也可以通过[]操作符随机访问存入的数据, 你不用担心使用[]操作符
		时会不会需要注意什么, 因为当你使用[]操作符时, Datas类会
		使用逆运算将压缩的数据适度的全局还原, 并返回给你想得到的数据.
		注意: 如果你想使用快速的访问, 并且只限制于顺序访问, 那你最好使用:next(), 并且
		在next之前, 应该先使用set_current_position来设置next的起始位置.next的解压缩
		是局部的, 所以速度很快, 只需要若干个指令即可, 但你注意, 你只能顺序的访问, 如果想
		随机访问请使用[]操作符.
		
	对压缩算法的详细说明:
		看程序
	对解压缩算法的详细说明:
		看程序
*/

#ifndef __DATAS__
#define __DATAS__

#include "vector.h"
#include "color.h"
#include "assert.h"

template <typename T>
class Datas
{
	friend int main(void);
public:
	typedef struct
	{
		T data;
		U16 amount;							//到目前为止的数据的个数
	}DataNode;								//数据节点
	
	Vector<DataNode> datas;		//用此来存储数据
	
public:
	Datas();
	Datas(unsigned);
	Datas& push_back(T& d);	//向datas中存储数据, 并压缩
	~Datas();

public:
	unsigned amount;					//存储数据的个数
	unsigned realAmount;			//占用内存的实际数量

/*******************方法************************/
public:
	DataNode&	lastNode();						//返回最后一个节点
	DataNode* find(unsigned index);	//根据index的索引找到实际的数据节点指针, 如果没找到返回0	
	void clear();

/********************操作符*********************/
public:
	T& operator[](unsigned index);
	
/*****************提供快速访问************/
private:
	DataNode* pPos;														//当前的位置数据指针
	unsigned curPos;													//当前的位置
public:
	DataNode* set_current_position(unsigned p);	//设置当前的位置
	T next();			//从set_current_position设置的位置处开始往下走, 调用一次
	
/******************Next开始***************/
};

template <typename T>
Datas<T>::Datas():amount(0), realAmount(0), pPos(0)
{
	
}

template <typename T>
Datas<T>::Datas(unsigned size):datas(Vector<DataNode>(size)), amount(0), realAmount(0), pPos(0)
{
}

template <typename T>
inline Datas<T>& Datas<T>::push_back(T& d)
{
	
	if(datas.size() && lastNode().data == d)	//如果新进来的元素和之前的元素相同, 则什么也不做
	{
		
	}
	else																			//否则新建一个元素, 并将当前的数据个数赋值给它
	{
		DataNode dn = {d, amount};
		datas.push_back(dn);
		realAmount += 1;
	}
	amount ++;
	return *this;
}




template <typename T>
Datas<T>::~Datas()
{
	datas.~Vector();
}

template <typename T>
inline Datas<T>::DataNode& Datas<T>::lastNode()
{
	assert(realAmount);
	return datas[realAmount - 1];
}

static int start = 0;
static int end = 0;
static int iCount = 0;

template <typename T>
inline Datas<T>::DataNode* Datas<T>::find(unsigned index)
{
	assert(index < amount);
	
	start = 0;
	end = realAmount - 1;
	
	if(realAmount > 1 && index < datas[1].amount)
		return &datas[0];
	
	if(index > datas[realAmount - 1].amount)
		return  &datas[realAmount - 1];
	
	do
	{
	iCount = (start + end) >> 1;	//右移一位, 相当于除以2
		
	if(datas[iCount].amount <= index && datas[iCount + 1].amount > index)	
		break;
	
	if(iCount == realAmount - 1)
		break;
	
	if(datas[iCount].amount > index)
		end = iCount - 1;
	else
		start = iCount + 1;
	
	}
	while(iCount != 0);
	
	return &datas[iCount];
}

//清除Data中已存的数据, 并将计数器清零
template <typename T>
void Datas<T>::clear()
{
	datas.clear();
	realAmount = amount = 0;
}


template <typename T>
inline T& Datas<T>::operator[](unsigned index)
{
	return find(index)->data;
}

template <typename T>
inline Datas<T>::DataNode* Datas<T>::set_current_position(unsigned p)
{
	DataNode* pre = pPos;
	pPos = find(p);
	curPos = p;
	return pre;
}

template <typename T>
inline T Datas<T>::next()
{
	if(pPos == null)
		set_current_position(0);
	
	if((pPos + 1)->amount <= curPos && curPos <= datas[realAmount - 1].amount && pPos != datas.end() - 1)
		pPos ++;
	
	curPos ++;
	return pPos->data;
}

#endif
