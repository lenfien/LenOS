

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
	
	if((pPos + 1)->amount <= curPos && curPos <= datas[realAmount - 1].amount)
		pPos ++;
	
	curPos ++;
	return pPos->data;
}
