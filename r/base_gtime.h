

/*
	base_gtime.h文档说明:
		此文档定义了对计数器2到计数器5的寄存器的定义
		以及对这些寄存器配置的所有动作
*/

#ifndef __GTIME
#define __GTIME

#include "com.h"
#include "core_map.h"
/*
	寄存器地址定义
	__TIMx_BASE(x)注解:
		定义了TIM2-TIM5的基地址索引器
		x = 2 - 5
		可得到TIM2-5的基地址
*/
#define __TIMx_BASE(x)		(TIM2_BASE + 0x400 * (x - 2))

#define __TIMx_CR1(x)		(__TIMx_BASE(x) + 0x00)
#define __TIMx_CR2(x)		(__TIMx_BASE(x) + 0x04)
#define __TIMx_SMCR(x)		(__TIMx_BASE(x) + 0x08)
#define __TIMx_DIER(x)		(__TIMx_BASE(x) + 0x0C)
#define __TIMx_SR(x)		(__TIMx_BASE(x) + 0x10)
#define __TIMx_EGR(x)		(__TIMx_BASE(x) + 0x14)
#define __TIMx_CCMR1(x)		(__TIMx_BASE(x) + 0x18)
#define __TIMx_CCMR2(x)		(__TIMx_BASE(x) + 0x1C)
#define __TIMx_CCER(x)		(__TIMx_BASE(x) + 0x20)
#define __TIMx_CNT(x)		(__TIMx_BASE(x) + 0x24)
#define __TIMx_PSC(x)		(__TIMx_BASE(x) + 0x28)
#define __TIMx_ARR(x)		(__TIMx_BASE(x) + 0x2C)
#define __TIMx_CCR1(x)		(__TIMx_BASE(x) + 0x34)
#define __TIMx_CCR2(x)		(__TIMx_BASE(x) + 0x38)
#define __TIMx_CCR3(x)		(__TIMx_BASE(x) + 0x3C)
#define __TIMx_CCR4(x)		(__TIMx_BASE(x) + 0x40)
#define __TIMx_DCR(x)		(__TIMx_BASE(x) + 0x48)
#define __TIMx_DMAR(x)		(__TIMx_BASE(x) + 0x4C)

//将地址转换为指向地址的指针
#define _TIMx_CR1(x)		ADR(__TIMx_CR1(x))
#define _TIMx_CR2(x)		ADR(__TIMx_CR2(x))
#define _TIMx_SMCR(x)		ADR(__TIMx_SMCR(x))
#define _TIMx_DIER(x)		ADR(__TIMx_DIER(x))
#define _TIMx_SR(x)			ADR(__TIMx_SR(x))
#define _TIMx_EGR(x)		ADR(__TIMx_EGR(x))
#define _TIMx_CCMR1(x)		ADR(__TIMx_CCMR1(x))	
#define _TIMx_CCMR2(x)		ADR(__TIMx_CCMR2(x))	
#define _TIMx_CCER(x)		ADR(__TIMx_CCER(x))	
#define _TIMx_CNT(x)		ADR(__TIMx_CNT(x))
#define _TIMx_PSC(x)		ADR(__TIMx_PSC(x))
#define _TIMx_ARR(x)		ADR(__TIMx_ARR(x))	
#define _TIMx_CCR1(x)		ADR(__TIMx_CCR1(x))
#define _TIMx_CCR2(x)		ADR(__TIMx_CCR2(x))	
#define _TIMx_CCR3(x)		ADR(__TIMx_CCR3(x))	
#define _TIMx_CCR4(x)		ADR(__TIMx_CCR4(x))
#define _TIMx_DCR(x)		ADR(__TIMx_DCR(x))	
#define _TIMx_DMAR(x)		ADR(__TIMx_DMAR(x))

//将地址转换为取该地址的值
#define TIMx_CR1(x)			VAL(__TIMx_CR1(x))
#define TIMx_CR2(x)			VAL(__TIMx_CR2(x))
#define TIMx_SMCR(x)		VAL(__TIMx_SMCR(x))
#define TIMx_DIER(x)		VAL(__TIMx_DIER(x))
#define TIMx_SR(x)			VAL(__TIMx_SR(x))
#define TIMx_EGR(x)			VAL(__TIMx_EGR(x))
#define TIMx_CCMR1(x)		VAL(__TIMx_CCMR1(x))	
#define TIMx_CCMR2(x)		VAL(__TIMx_CCMR2(x))	
#define TIMx_CCER(x)		VAL(__TIMx_CCER(x))	
#define TIMx_CNT(x)			VAL(__TIMx_CNT(x))
#define TIMx_PSC(x)			VAL(__TIMx_PSC(x))
#define TIMx_ARR(x)			VAL(__TIMx_ARR(x))	
#define TIMx_CCR1(x)		VAL(__TIMx_CCR1(x))
#define TIMx_CCR2(x)		VAL(__TIMx_CCR2(x))	
#define TIMx_CCR3(x)		VAL(__TIMx_CCR3(x))	
#define TIMx_CCR4(x)		VAL(__TIMx_CCR4(x))
#define TIMx_DCR(x)			VAL(__TIMx_DCR(x))	
#define TIMx_DMAR(x)		VAL(__TIMx_DMAR(x))


#endif



