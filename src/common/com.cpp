#include "com.h"


/******************************************************************/
/*************************位操作***********************************/	
/******************************************************************/


__asm void __set_bit(U32* disAdd, U8 pos)
{
	//R0: 	被操作的数的地址
	//R1:	被设置的位置
	PUSH 	{R2, LR}
	MOV 	R2, #0x01
	LSL		R2, R1
	LDR		R1, [R0]
	ORR		R1, R2
	STR		R1, [R0]
	POP 	{R2, PC}
}

__asm void __clear_bit(U32* disAdd, U8 pos)
{
	//R0: 	被操作的数的地址
	//R1:	被设置的位置
	PUSH	{R2, LR}
	MOV		R2, #0x01
	LSL		R2, R1
	EOR		R2 ,R2, #0xFFFFFFFF	
	LDR		R1, [R0]
	AND		R1, R2
	STR		R1, [R0]
	POP		{R2, PC}
}

void __clear_bits(U32* disAdd, U8 start, U8 amount)
{
	U32 temp = *disAdd;
	__set_bits(&temp, 0x00, start, amount);
	*disAdd = temp;	
}


void __set_bits(U32* disAdd, U32 data, U8 start, U8 amount)
{
	U8 index;
	U32 temp = *disAdd;
	for(index = 0; index < amount; index ++, data >>= 1)
		(data & 0x01) ? __set_bit(&temp, start + index) : __clear_bit(&temp, start + index);
	*disAdd = temp;
}

__asm U32 __get_bit(U32 dis, U8 pos)
{
	//R0: 	被操作的数
	//R1:	被设置的位置
	PUSH 	{R2, LR}
	LSR		R0, R1
	AND		R0, #0x01
	POP		{R2, PC}
}


U32 __get_bits(U32 dis, U8 start ,U8 amount)
{
	U32 result = 0;
	S8 index = start + amount - 1;
	for(; index >= start; index --)
	{
		result |= __get_bit(dis, index);
		if(!(result & 0x80000000))
			result <<= 1;
	}
	if(!(result & 0x01))
		result >>= 1;
	return result;
}

void __write_bit(U32* disAdd, U8 data, U8 pos)
{
	(data&1) ? __set_bit(disAdd, pos) : __clear_bit(disAdd, pos); 
}

#include <cmath>

void delay(U32 time)
{
	int temp = 100;
	while(time--)
	{
		while(temp--);
		temp = 100;
	}
}

void delay_us(U32 us)
{
	//int i = 6;
	while(us--)
	{
	//	while(i--);
		//i = 6;
	}
}

void delay_ms(U32 ms)
{
	delay_us(ms * 1000);
}

bool is_in_range(U32 x, U32 y, U32 xStart, U32 yStart, U32 xEnd, U32 yEnd)
{
	if(x > xStart && x < xEnd && y > yStart && y < yEnd)
		return true;
	return false;
}

//是否在原型区域内
bool is_in_range_circle(S32 x, S32 y, S32 oX, S32 oY, S32 oR)
{
	return (std::sqrt((double)((x-oX)*(x-oX) + (y-oY)*(y-oY))) < oR);
}




 

