/*
	��Datas��������ݵ�ͬʱ, ��ѹ������, �ɶ��û���͸����
	
	��Datas�����ϸ˵��:
		Datas����һ�������洢��ѹ�����ݵ���, �����ͨ��push_back����
		Datas�����д���"��������"������, �����ڴ����ͬʱ, Datas������
		��Ӧ���㷨ѹ������������, �����ѹ���㷨����ὲ��.
		���˻������ѹ������, Datas��������Ǻ�Vector������, ��Ϊ�����
		push_back, Ҳ����ͨ��[]������������ʴ��������, �㲻�õ���ʹ��[]������
		ʱ�᲻����Ҫע��ʲô, ��Ϊ����ʹ��[]������ʱ, Datas���
		ʹ�������㽫ѹ���������ʶȵ�ȫ�ֻ�ԭ, �����ظ�����õ�������.
		ע��: �������ʹ�ÿ��ٵķ���, ����ֻ������˳�����, �������ʹ��:next(), ����
		��next֮ǰ, Ӧ����ʹ��set_current_position������next����ʼλ��.next�Ľ�ѹ��
		�Ǿֲ���, �����ٶȺܿ�, ֻ��Ҫ���ɸ�ָ���, ����ע��, ��ֻ��˳��ķ���, �����
		���������ʹ��[]������.
		
	��ѹ���㷨����ϸ˵��:
		������
	�Խ�ѹ���㷨����ϸ˵��:
		������
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
		U16 amount;							//��ĿǰΪֹ�����ݵĸ���
	}DataNode;								//���ݽڵ�
	
	Vector<DataNode> datas;		//�ô����洢����
	
public:
	Datas();
	Datas(unsigned);
	Datas& push_back(T& d);	//��datas�д洢����, ��ѹ��
	~Datas();

public:
	unsigned amount;					//�洢���ݵĸ���
	unsigned realAmount;			//ռ���ڴ��ʵ������

/*******************����************************/
public:
	DataNode&	lastNode();						//�������һ���ڵ�
	DataNode* find(unsigned index);	//����index�������ҵ�ʵ�ʵ����ݽڵ�ָ��, ���û�ҵ�����0	
	void clear();

/********************������*********************/
public:
	T& operator[](unsigned index);
	
/*****************�ṩ���ٷ���************/
private:
	DataNode* pPos;														//��ǰ��λ������ָ��
	unsigned curPos;													//��ǰ��λ��
public:
	DataNode* set_current_position(unsigned p);	//���õ�ǰ��λ��
	T next();			//��set_current_position���õ�λ�ô���ʼ������, ����һ��
	
/******************Next��ʼ***************/
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
	
	if(datas.size() && lastNode().data == d)	//����½�����Ԫ�غ�֮ǰ��Ԫ����ͬ, ��ʲôҲ����
	{
		
	}
	else																			//�����½�һ��Ԫ��, ������ǰ�����ݸ�����ֵ����
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
	iCount = (start + end) >> 1;	//����һλ, �൱�ڳ���2
		
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

//���Data���Ѵ������, ��������������
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
