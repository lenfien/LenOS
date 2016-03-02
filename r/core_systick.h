

#ifndef __SYSTICK
#define __SYSTICK


#include "com.h"


//值地址
#define __SYSTICK_CSR		0xE000E010	//Systick控制及状态寄存器
#define __SYSTICK_RLR		0xE000E014	//systick重装载数值寄存器
#define __SYSTICK_CUR		0xE000E018	//Systick当前数值寄存器
#define __SYSTICK_CAR		0xE000E01C	//Systick校准数值寄存器

//地址
#define _SYSTICK_CSR		ADR(__SYSTICK_CSR)	//Systick控制及状态寄存器
#define _SYSTICK_RLR		ADR(__SYSTICK_RLR)	//systick重装载数值寄存器
#define _SYSTICK_CUR		ADR(__SYSTICK_CUR)	//Systick当前数值寄存器
#define _SYSTICK_CAR		ADR(__SYSTICK_CAR)	//Systick校准数值寄存器


//值
#define SYSTICK_CSR			VAL(__SYSTICK_CSR)	//Systick控制及状态寄存器
#define SYSTICK_RLR			VAL(__SYSTICK_RLR)	//systick重装载数值寄存器
#define SYSTICK_CUR			VAL(__SYSTICK_CUR)	//Systick当前数值寄存器
#define SYSTICK_CAR			VAL(__SYSTICK_CAR)	//Systick校准数值寄存器





/********************SYSTICK_CSR _ Systick控制及状态寄存器**************/

/*
Bit 16:
CONTFLAG:
计数器的计数状态
只读
0:	本次读取前计数器的值没有达到0;
1:	本次读取前计数器的值达到过0；
清零:通过读取该位将自动清0
*/
U8 SYSTICK_get_CONTFLAG(void);

#define SYSTICK_get_count_flag()	SYSTICK_get_CONTFLAG()


/*
Bit 2: CLKSOURCE:
Systick的时钟源设置:
0: 外部时钟源 STCLK
1: 内核时钟 FCLK
*/
void SYSTICK_set_CLKSOURCE(U8 s_f);

#define SYSTICK_set_clock_source(s_f)	SYSTICK_set_CLKSOURCE(s_f)

#define SYSTICK_set_clock_source_is_STCLK()	SYSTICK_set_CLKSOURCE(0)
#define SYSTICK_set_clock_source_is_FCLK()	SYSTICK_set_CLKSOURCE(1)
	
U8 SYSTICK_get_CLKSOURCE(void);

#define SYSTICK_get_clock_source()	SYSTICK_get_CLKSOURCE()

/*
Bit 1: TICKINT:
当计数器计数到0时，是否产生SysTick异常
1: 	Systick倒计数到1时产生Systick异常请求
0:	不产生请求
*/
void SYSTICK_set_TICKINT(U8 e_d);

#define SYSTICK_enable_interrupt()	SYSTICK_set_TICKINT(1)
#define SYSTICK_disable_interrupt()	SYSTICK_set_TICKINT(0)


/*
Bit 0: ENABLE
Systick使能位
1: 	使能Systick
0:	除能Systick
*/
void SYSTICK_set_ENABLE(U8 e_d);

#define SYSTICK_enable_systick()	SYSTICK_set_ENABLE(1)
#define SYSTICK_disable_systick()	SYSTICK_set_ENABLE(0)


/***************************SYSTICK_RLR(systick重装载数值寄存器)**************/
/*
Bit [23:0]:RELOAD
当计数器计数到0时重新装载的值
*/
void SYSTICK_set_RELOAD(U32 re);
U32 SYSTICK_get_RELOAD(void);

#define SYSTICK_set_reload(re)	SYSTICK_set_RELOAD(re)
#define SYSTICK_get_reload()	SYSTICK_get_RELOAD()


/***************************SYSTICK_CUR(Systick当前数值寄存器)***************/
/*
Bit [23:0]: CURRENT
计数器当前的值
*/
void SYSTICK_set_CURRENT(U32 cu);
U32 SYSTICK_get_CURRENT(void);

#define SYSTICK_set_counter(cu)		SYSTICK_set_CURRENT(cu)
#define SYSTICK_get_counter()		SYSTICK_get_CURRENT()

/***************************SYSTICK_CAR(Systick校准数值寄存器)**************/
/*
Bit 31: NOREF只读
是否外部参考时钟可用
1:  外部参考时钟不可用 
0： 外部参考时钟可用
*/
U8	SYSTICK_get_NOREF(void);

#define SYSTICK_is_reference_clock_available() (!SYSTICK_get_NOREF())


/*
Bit 30: SKEW:只读
校准值是否为精确的10MS
1:	校准值不是精确的10MS
0:	校准值是精确的10MS
*/
U8 SYSTICK_get_SKEW(void);

#define SYSTICK_is_calibration_value_precision()	(!(SYSTICK_get_SKEW()))


/*
Bit [23:0] TENMS:只读
10MS倒计时的格数
0: 无法使用校准功能
*/
U32 SYSTICK_get_TENMS(void);

#define SYSTICK_get_10MS_calibration_value()	SYSTICK_get_TENMS()

#endif
