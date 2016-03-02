
#ifndef __COM__
#define __COM__


	typedef  unsigned char 	U8;
	typedef  unsigned short U16;
	typedef  unsigned int 	U32;
	
	typedef	 signed char    S8;
	typedef  signed short   S16;
	typedef  signed int     S32;

	#define ADR(address)  ((unsigned int *)(address))
	#define VAL(address)   (*(ADR(address)))

	#define NULL	0
	#define null	0

	#define bool U8
	#define false 0
	#define true 1
	
	#define max(a, b) ((a>b) ? a : b)
	#define min(a, b)	((a>b) ? b : a)
	
	
	void delay(U32 time);
	void delay_us(U32 us);
	void delay_ms(U32 ms);
	void _NOP(void);

	bool is_in_range(U32 x, U32 y, U32 xStart, U32 yStart, U32 xEnd, U32 yEnd);
	//是否在原型区域内
	bool is_in_range_circle(S32 x, S32 y, S32 oX, S32 oY, S32 oR);

	void DEBUG_color_init(void);
	
	template <typename TYPE>
	bool sort(TYPE* beg, TYPE* end, bool (*is_smaller)(TYPE, TYPE));
	
	template <typename TYPE>
	bool sort(TYPE* beg, TYPE* end, bool (*is_smaller)(TYPE, TYPE))
	{
		if(beg >= end)
			return false;
		
		if(beg == 0 || end == 0)
			return false;
		
		for(int i = end - beg - 1; i > 0; i -- )
		{
			for(int ii = 0; ii < i; ii ++)
			{
				if(is_smaller(beg[ii],  beg[ii+1]))
				{
					TYPE t = beg[ii];
					beg[ii] = beg[ii + 1];
					beg[ii + 1] = t;
				}
			}
		}
		return true;
	}


	/****************************************************************/
	/********************位操作**************************************/
	/****************************************************************/

	void __set_bit(U32* disAdd, U8 pos);
	void __set_bits(U32* disAdd, U32 data, U8 start, U8 amount);
	void __write_bit(U32* disAdd, U8 data, U8 pos);
	void __clear_bit(U32* disAdd, U8 pos);
	void __clear_bits(U32* disAdd, U8 start, U8 amount);
	U32  __get_bit(U32 dis, U8 pos);
	U32  __get_bits(U32 dis, U8 start ,U8 amount);

	
	#define _TEXT(str)	(char*)(str)
	
#endif

