/*
	该文档定义了stm32f103zet6中EXIT的相关寄存器和对这些寄存器的操作函数。
*/

#ifndef __EXTI
#define __EXTI
#include "core_map.h"

#include "com.h"

#define __EXTI_IMR			(EXTI_BASE + 0x00000000) 	//中断屏蔽寄存器 interrupt mask register
#define __EXTI_EMR			(EXTI_BASE + 0x00000004)	//事件屏蔽寄存器 event mask register
#define __EXTI_RTSR			(EXTI_BASE + 0x00000008)	//上升沿触发选择寄存器 rise edge triger select register
#define __EXTI_FTSR			(EXTI_BASE + 0x0000000C)	//下降沿触发选择寄存器 fall edge triger select register
#define __EXTI_SWIER		(EXTI_BASE + 0x00000010)	//软件中断事件寄存器
#define __EXTI_PR			(EXTI_BASE + 0x00000014)	//挂起寄存器
	

#define _EXTI_IMR			ADR(__EXTI_IMR) 			//中断屏蔽寄存器 interrupt mask register
#define _EXTI_EMR			ADR(__EXTI_EMR)				//事件屏蔽寄存器 event mask register
#define _EXTI_RTSR			ADR(__EXTI_RTSR)			//上升沿触发选择寄存器 rise edge triger select register
#define _EXTI_FTSR			ADR(__EXTI_FTSR)			//下降沿触发选择寄存器 fall edge triger select register
#define _EXTI_SWIER 		ADR(__EXTI_SWIER)			//软件中断事件寄存器
#define _EXTI_PR			ADR(__EXTI_PR)				//挂起寄存器


#define EXTI_IMR			VAL(__EXTI_IMR) 			//中断屏蔽寄存器 interrupt mask register
#define EXTI_EMR			VAL(__EXTI_EMR)				//事件屏蔽寄存器 event mask register
#define EXTI_RTSR			VAL(__EXTI_RTSR)			//上升沿触发选择寄存器 rise edge triger select register
#define EXTI_FTSR			VAL(__EXTI_FTSR)			//下降沿触发选择寄存器 fall edge triger select register
#define EXTI_SWIER 			VAL(__EXTI_SWIER)				//软件中断事件寄存器
#define EXTI_PR				VAL(__EXTI_PR)		//0x40010414			//挂起寄存器
//*****Interrupt mask register (EXTI_IMR)***********//

/*
中断屏蔽寄存器
Interrupt mask register (EXTI_IMR)
Address offset: 0x00
Reset value: 0x0000 0000
*/
/*
Bits 31:20 Reserved, must be kept at reset value (0).
*/

/*
外部中断使能/屏蔽(当对应位为1时开启中断)
Bits 19:0 MRx: Interrupt Mask on line x
0: Interrupt request from Line x is masked
1: Interrupt request from Line x is not masked
Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
*/
//外部中断使能lineNum(0-19)的中断事件
//e_d: enable(1) diable(0)
void EXTI_set_IMRx(U8 lineNum, U8 e_d);


#define EXTI_enable_interrupt_at_line_x(lineNum)	EXTI_set_IMRx(lineNum, 1)
#define EXTI_disable_interrupt_at_line_x(lineNum)	EXTI_set_IMRx(lineNum, 0)

#define EXTI_enable_interrupt_at_line_0()			EXTI_set_IMRx(0, 1)
#define EXTI_enable_interrupt_at_line_1()			EXTI_set_IMRx(1, 1)
#define EXTI_enable_interrupt_at_line_2()			EXTI_set_IMRx(2, 1)
#define EXTI_enable_interrupt_at_line_3()			EXTI_set_IMRx(3, 1)
#define EXTI_enable_interrupt_at_line_4()			EXTI_set_IMRx(4, 1)
#define EXTI_enable_interrupt_at_line_5()			EXTI_set_IMRx(5, 1)
#define EXTI_enable_interrupt_at_line_6()			EXTI_set_IMRx(6, 1)
#define EXTI_enable_interrupt_at_line_7()			EXTI_set_IMRx(7, 1)
#define EXTI_enable_interrupt_at_line_8()			EXTI_set_IMRx(8, 1)
#define EXTI_enable_interrupt_at_line_9()			EXTI_set_IMRx(9, 1)
#define EXTI_enable_interrupt_at_line_10()			EXTI_set_IMRx(10, 1)
#define EXTI_enable_interrupt_at_line_11()			EXTI_set_IMRx(11, 1)
#define EXTI_enable_interrupt_at_line_12()			EXTI_set_IMRx(12, 1)
#define EXTI_enable_interrupt_at_line_13()			EXTI_set_IMRx(13, 1)
#define EXTI_enable_interrupt_at_line_14()			EXTI_set_IMRx(14, 1)
#define EXTI_enable_interrupt_at_line_15()			EXTI_set_IMRx(15, 1)
#define EXTI_enable_interrupt_at_line_16()			EXTI_set_IMRx(16, 1)
#define EXTI_enable_interrupt_at_line_17()			EXTI_set_IMRx(17, 1)
#define EXTI_enable_interrupt_at_line_18()			EXTI_set_IMRx(18, 1)
#define EXTI_enable_interrupt_at_line_19()			EXTI_set_IMRx(19, 1)

#define EXTI_disable_interrupt_at_line_0()			EXTI_set_IMRx(0, 0)
#define EXTI_disable_interrupt_at_line_1()			EXTI_set_IMRx(1, 0)
#define EXTI_disable_interrupt_at_line_2()			EXTI_set_IMRx(2, 0)
#define EXTI_disable_interrupt_at_line_3()			EXTI_set_IMRx(3, 0)
#define EXTI_disable_interrupt_at_line_4()			EXTI_set_IMRx(4, 0)
#define EXTI_disable_interrupt_at_line_5()			EXTI_set_IMRx(5, 0)
#define EXTI_disable_interrupt_at_line_6()			EXTI_set_IMRx(6, 0)
#define EXTI_disable_interrupt_at_line_7()			EXTI_set_IMRx(7, 0)
#define EXTI_disable_interrupt_at_line_8()			EXTI_set_IMRx(8, 0)
#define EXTI_disable_interrupt_at_line_9()			EXTI_set_IMRx(9, 0)
#define EXTI_disable_interrupt_at_line_10()			EXTI_set_IMRx(10, 0)
#define EXTI_disable_interrupt_at_line_11()			EXTI_set_IMRx(11, 0)
#define EXTI_disable_interrupt_at_line_12()			EXTI_set_IMRx(12, 0)
#define EXTI_disable_interrupt_at_line_13()			EXTI_set_IMRx(13, 0)
#define EXTI_disable_interrupt_at_line_14()			EXTI_set_IMRx(14, 0)
#define EXTI_disable_interrupt_at_line_15()			EXTI_set_IMRx(15, 0)
#define EXTI_disable_interrupt_at_line_16()			EXTI_set_IMRx(16, 0)
#define EXTI_disable_interrupt_at_line_17()			EXTI_set_IMRx(17, 0)
#define EXTI_disable_interrupt_at_line_18()			EXTI_set_IMRx(18, 0)
#define EXTI_disable_interrupt_at_line_19()			EXTI_set_IMRx(19, 0)


/**********Event mask register (EXTI_EMR)**************/

/*
Event mask register (EXTI_EMR)
Address offset: 0x04
Reset value: 0x0000 0000
*/

/*
Bits 31:20 Reserved, must be kept at reset value (0).
Bits 19:0 MRx: Event mask on line x
0: Event request from Line x is masked
1: Event request from Line x is not masked
Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
*/
//外部事件使能lineNum(0-19)的中断事件
//e_d: enable(1) diable(0)
void EXTI_set_EMRx(U8 lineNum, U8 e_d);

#define EXTI_enable_event_at_line_x(lineNum)	EXTI_set_EMRx(lineNum, 1)
#define EXTI_disable_event_at_line_x(lineNum)	EXTI_set_EMRx(lineNum, 0)


#define EXTI_enable_event_at_line_0()			EXTI_set_EMRx(0, 1)
#define EXTI_enable_event_at_line_1()			EXTI_set_EMRx(1, 1)
#define EXTI_enable_event_at_line_2()			EXTI_set_EMRx(2, 1)
#define EXTI_enable_event_at_line_3()			EXTI_set_EMRx(3, 1)
#define EXTI_enable_event_at_line_4()			EXTI_set_EMRx(4, 1)
#define EXTI_enable_event_at_line_5()			EXTI_set_EMRx(5, 1)
#define EXTI_enable_event_at_line_6()			EXTI_set_EMRx(6, 1)
#define EXTI_enable_event_at_line_7()			EXTI_set_EMRx(7, 1)
#define EXTI_enable_event_at_line_8()			EXTI_set_EMRx(8, 1)
#define EXTI_enable_event_at_line_9()			EXTI_set_EMRx(9, 1)
#define EXTI_enable_event_at_line_10()			EXTI_set_EMRx(10, 1)
#define EXTI_enable_event_at_line_11()			EXTI_set_EMRx(11, 1)
#define EXTI_enable_event_at_line_12()			EXTI_set_EMRx(12, 1)
#define EXTI_enable_event_at_line_13()			EXTI_set_EMRx(13, 1)
#define EXTI_enable_event_at_line_14()			EXTI_set_EMRx(14, 1)
#define EXTI_enable_event_at_line_15()			EXTI_set_EMRx(15, 1)
#define EXTI_enable_event_at_line_16()			EXTI_set_EMRx(16, 1)
#define EXTI_enable_event_at_line_17()			EXTI_set_EMRx(17, 1)
#define EXTI_enable_event_at_line_18()			EXTI_set_EMRx(18, 1)
#define EXTI_enable_event_at_line_19()			EXTI_set_EMRx(19, 1)

#define EXTI_disable_event_at_line_0()			EXTI_set_EMRx(0, 0)
#define EXTI_disable_event_at_line_1()			EXTI_set_EMRx(1, 0)
#define EXTI_disable_event_at_line_2()			EXTI_set_EMRx(2, 0)
#define EXTI_disable_event_at_line_3()			EXTI_set_EMRx(3, 0)
#define EXTI_disable_event_at_line_4()			EXTI_set_EMRx(4, 0)
#define EXTI_disable_event_at_line_5()			EXTI_set_EMRx(5, 0)
#define EXTI_disable_event_at_line_6()			EXTI_set_EMRx(6, 0)
#define EXTI_disable_event_at_line_7()			EXTI_set_EMRx(7, 0)
#define EXTI_disable_event_at_line_8()			EXTI_set_EMRx(8, 0)
#define EXTI_disable_event_at_line_9()			EXTI_set_EMRx(9, 0)
#define EXTI_disable_event_at_line_10()			EXTI_set_EMRx(10, 0)
#define EXTI_disable_event_at_line_11()			EXTI_set_EMRx(11, 0)
#define EXTI_disable_event_at_line_12()			EXTI_set_EMRx(12, 0)
#define EXTI_disable_event_at_line_13()			EXTI_set_EMRx(13, 0)
#define EXTI_disable_event_at_line_14()			EXTI_set_EMRx(14, 0)
#define EXTI_disable_event_at_line_15()			EXTI_set_EMRx(15, 0)
#define EXTI_disable_event_at_line_16()			EXTI_set_EMRx(16, 0)
#define EXTI_disable_event_at_line_17()			EXTI_set_EMRx(17, 0)
#define EXTI_disable_event_at_line_18()			EXTI_set_EMRx(18, 0)
#define EXTI_disable_event_at_line_19()			EXTI_set_EMRx(19, 0)

/************Rising trigger selection register (EXTI_RTSR)*********/

/*
Rising trigger selection register (EXTI_RTSR)
Address offset: 0x08
Reset value: 0x0000 0000
*/

/*
Bits 31:20
Reserved, must be kept at reset value (0).
*/

/*
Bits 19:0 TRx: Rising trigger event configuration bit of line x
0: Rising trigger disabled (for Event and Interrupt) for input line
1: Rising trigger enabled (for Event and Interrupt) for input line.
Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.

Note:
The external wakeup lines are edge triggered, no glitches must be generated on these lines.
If a rising edge on external interrupt line occurs during writing of EXTI_RTSR register, the 
pending bit will not be set.
Rising and Falling edge triggers can be set for the same interrupt line. In this configuration, 
both generate a trigger condition.
*/
/*
激活上升沿事件/中断
lineNUm(0-19)
e_d: enable(1) disable(0)
*/
void EXTI_set_RTRx(U8 lineNum, U8 e_d);

#define EXTI_enable_rising_trigger_at_line_x(lineNum)		EXTI_set_RTRx(lineNum, 1)
#define EXTI_disable_rising_trigger_at_line_x(lineNum)   	EXTI_set_RTRx(lineNum, 0)

#define EXTI_enable_rising_trigger_at_line_0()			EXTI_set_RTRx(0, 1)
#define EXTI_enable_rising_trigger_at_line_1()			EXTI_set_RTRx(1, 1)
#define EXTI_enable_rising_trigger_at_line_2()			EXTI_set_RTRx(2, 1)
#define EXTI_enable_rising_trigger_at_line_3()			EXTI_set_RTRx(3, 1)
#define EXTI_enable_rising_trigger_at_line_4()			EXTI_set_RTRx(4, 1)
#define EXTI_enable_rising_trigger_at_line_5()			EXTI_set_RTRx(5, 1)
#define EXTI_enable_rising_trigger_at_line_6()			EXTI_set_RTRx(6, 1)
#define EXTI_enable_rising_trigger_at_line_7()			EXTI_set_RTRx(7, 1)
#define EXTI_enable_rising_trigger_at_line_8()			EXTI_set_RTRx(8, 1)
#define EXTI_enable_rising_trigger_at_line_9()			EXTI_set_RTRx(9, 1)
#define EXTI_enable_rising_trigger_at_line_10()			EXTI_set_RTRx(10, 1)
#define EXTI_enable_rising_trigger_at_line_11()			EXTI_set_RTRx(11, 1)
#define EXTI_enable_rising_trigger_at_line_12()			EXTI_set_RTRx(12, 1)
#define EXTI_enable_rising_trigger_at_line_13()			EXTI_set_RTRx(13, 1)
#define EXTI_enable_rising_trigger_at_line_14()			EXTI_set_RTRx(14, 1)
#define EXTI_enable_rising_trigger_at_line_15()			EXTI_set_RTRx(15, 1)
#define EXTI_enable_rising_trigger_at_line_16()			EXTI_set_RTRx(16, 1)
#define EXTI_enable_rising_trigger_at_line_17()			EXTI_set_RTRx(17, 1)
#define EXTI_enable_rising_trigger_at_line_18()			EXTI_set_RTRx(18, 1)
#define EXTI_enable_rising_trigger_at_line_19()			EXTI_set_RTRx(19, 1)

#define EXTI_disable_rising_trigger_at_line_0()			EXTI_set_RTRx(0, 0)
#define EXTI_disable_rising_trigger_at_line_1()			EXTI_set_RTRx(1, 0)
#define EXTI_disable_rising_trigger_at_line_2()			EXTI_set_RTRx(2, 0)
#define EXTI_disable_rising_trigger_at_line_3()			EXTI_set_RTRx(3, 0)
#define EXTI_disable_rising_trigger_at_line_4()			EXTI_set_RTRx(4, 0)
#define EXTI_disable_rising_trigger_at_line_5()			EXTI_set_RTRx(5, 0)
#define EXTI_disable_rising_trigger_at_line_6()			EXTI_set_RTRx(6, 0)
#define EXTI_disable_rising_trigger_at_line_7()			EXTI_set_RTRx(7, 0)
#define EXTI_disable_rising_trigger_at_line_8()			EXTI_set_RTRx(8, 0)
#define EXTI_disable_rising_trigger_at_line_9()			EXTI_set_RTRx(9, 0)
#define EXTI_disable_rising_trigger_at_line_10()		EXTI_set_RTRx(10, 0)
#define EXTI_disable_rising_trigger_at_line_11()		EXTI_set_RTRx(11, 0)
#define EXTI_disable_rising_trigger_at_line_12()		EXTI_set_RTRx(12, 0)
#define EXTI_disable_rising_trigger_at_line_13()		EXTI_set_RTRx(13, 0)
#define EXTI_disable_rising_trigger_at_line_14()		EXTI_set_RTRx(14, 0)
#define EXTI_disable_rising_trigger_at_line_15()		EXTI_set_RTRx(15, 0)
#define EXTI_disable_rising_trigger_at_line_16()		EXTI_set_RTRx(16, 0)
#define EXTI_disable_rising_trigger_at_line_17()		EXTI_set_RTRx(17, 0)
#define EXTI_disable_rising_trigger_at_line_18()		EXTI_set_RTRx(18, 0)
#define EXTI_disable_rising_trigger_at_line_19()		EXTI_set_RTRx(19, 0)


//************Falling trigger selection register (EXTI_FTSR)***************//
/*
下降沿事件选择
Falling trigger selection register (EXTI_FTSR)
Address offset: 0x0C
Reset value: 0x0000 0000
*/
/*
Bits 31:20
Reserved, must be kept at reset value (0).
*/

/*
Bits 19:0 TRx: Falling trigger event configuration bit of line x
0: Falling trigger disabled (for Event and Interrupt) for input line
1: Falling trigger enabled (for Event and Interrupt) for input line.
Note: Bit 19 used in connectivity line devices and is reserved otherwise.

Note:
The external wakeup lines are edge triggered, no glitches must be generated on these lines.
If a falling edge on external interrupt line occurs during writing of EXTI_FTSR register, the 
pending bit will not be set.
Rising and Falling edge triggers can be set for the same interrupt line. In this configuration, 
both generate a trigger condition.
*/
/*
激活上升沿事件/中断
lineNUm(0-19)
e_d: enable(1) disable(0)
*/
void EXTI_set_FTRx(U8 lineNum, U8 e_d);

#define EXTI_enable_falling_trigger_at_line_x(lineNum)	EXTI_set_FTRx(lineNum, 1)
#define EXTI_disable_falling_trigger_at_line_x(lineNum)	EXTI_set_FTRx(lineNum, 0)

#define EXTI_enable_falling_trigger_at_line_0()			EXTI_set_FTRx(0, 1)
#define EXTI_enable_falling_trigger_at_line_1()			EXTI_set_FTRx(1, 1)
#define EXTI_enable_falling_trigger_at_line_2()			EXTI_set_FTRx(2, 1)
#define EXTI_enable_falling_trigger_at_line_3()			EXTI_set_FTRx(3, 1)
#define EXTI_enable_falling_trigger_at_line_4()			EXTI_set_FTRx(4, 1)
#define EXTI_enable_falling_trigger_at_line_5()			EXTI_set_FTRx(5, 1)
#define EXTI_enable_falling_trigger_at_line_6()			EXTI_set_FTRx(6, 1)
#define EXTI_enable_falling_trigger_at_line_7()			EXTI_set_FTRx(7, 1)
#define EXTI_enable_falling_trigger_at_line_8()			EXTI_set_FTRx(8, 1)
#define EXTI_enable_falling_trigger_at_line_9()			EXTI_set_FTRx(9, 1)
#define EXTI_enable_falling_trigger_at_line_10()		EXTI_set_FTRx(10, 1)
#define EXTI_enable_falling_trigger_at_line_11()		EXTI_set_FTRx(11, 1)
#define EXTI_enable_falling_trigger_at_line_12()		EXTI_set_FTRx(12, 1)
#define EXTI_enable_falling_trigger_at_line_13()		EXTI_set_FTRx(13, 1)
#define EXTI_enable_falling_trigger_at_line_14()		EXTI_set_FTRx(14, 1)
#define EXTI_enable_falling_trigger_at_line_15()		EXTI_set_FTRx(15, 1)
#define EXTI_enable_falling_trigger_at_line_16()		EXTI_set_FTRx(16, 1)
#define EXTI_enable_falling_trigger_at_line_17()		EXTI_set_FTRx(17, 1)
#define EXTI_enable_falling_trigger_at_line_18()		EXTI_set_FTRx(18, 1)
#define EXTI_enable_falling_trigger_at_line_19()		EXTI_set_FTRx(19, 1)

#define EXTI_disable_falling_trigger_at_line_0()		EXTI_set_FTRx(0, 0)
#define EXTI_disable_falling_trigger_at_line_1()		EXTI_set_FTRx(1, 0)
#define EXTI_disable_falling_trigger_at_line_2()		EXTI_set_FTRx(2, 0)
#define EXTI_disable_falling_trigger_at_line_3()		EXTI_set_FTRx(3, 0)
#define EXTI_disable_falling_trigger_at_line_4()		EXTI_set_FTRx(4, 0)
#define EXTI_disable_falling_trigger_at_line_5()		EXTI_set_FTRx(5, 0)
#define EXTI_disable_falling_trigger_at_line_6()		EXTI_set_FTRx(6, 0)
#define EXTI_disable_falling_trigger_at_line_7()		EXTI_set_FTRx(7, 0)
#define EXTI_disable_falling_trigger_at_line_8()		EXTI_set_FTRx(8, 0)
#define EXTI_disable_falling_trigger_at_line_9()		EXTI_set_FTRx(9, 0)
#define EXTI_disable_falling_trigger_at_line_10()		EXTI_set_FTRx(10, 0)
#define EXTI_disable_falling_trigger_at_line_11()		EXTI_set_FTRx(11, 0)
#define EXTI_disable_falling_trigger_at_line_12()		EXTI_set_FTRx(12, 0)
#define EXTI_disable_falling_trigger_at_line_13()		EXTI_set_FTRx(13, 0)
#define EXTI_disable_falling_trigger_at_line_14()		EXTI_set_FTRx(14, 0)
#define EXTI_disable_falling_trigger_at_line_15()		EXTI_set_FTRx(15, 0)
#define EXTI_disable_falling_trigger_at_line_16()		EXTI_set_FTRx(16, 0)
#define EXTI_disable_falling_trigger_at_line_17()		EXTI_set_FTRx(17, 0)
#define EXTI_disable_falling_trigger_at_line_18()		EXTI_set_FTRx(18, 0)
#define EXTI_disable_falling_trigger_at_line_19()		EXTI_set_FTRx(19, 0)


//*****************************Software interrupt event register (EXTI_SWIER)*******************//
/*
软件触发中断/事件寄存器
Software interrupt event register (EXTI_SWIER)
Address offset: 0x10
Reset value: 0x0000 0000
*/

/*
Bits 31:20
Reserved, must be kept at reset value (0).
*/

/*
Bits 19:0 SWIERx: Software interrupt on line x
Writing a 1 to this bit when it is at 0 sets the corresponding pending bit in EXTI_PR. If the 
interrupt is enabled on this line on the EXTI_IMR and EXTI_EMR, an interrupt request is 
generated.
This bit is cleared by clearing the corresponding bit of EXTI_PR (by writing a 1 into the bit).
Note: Bit 19 used in connectivity line devices and is reserved otherwise.
*/
//在lineNum(0-19)上产生一个软件中断
void EXTI_set_SWIERx(U8 lineNum);


#define EXTI_generate_interrupt_request_at_line_x(lineNum)	EXTI_set_SWIER(lineNum)
#define EXTI_generate_event_request_at_line_x(lineNum)		EXTI_set_SWEER(lineNum)

#define EXTI_generate_interrupt_request_at_line_0()			EXTI_set_SWIERx(0)
#define EXTI_generate_interrupt_request_at_line_1()			EXTI_set_SWIERx(1)
#define EXTI_generate_interrupt_request_at_line_2()			EXTI_set_SWIERx(2)
#define EXTI_generate_interrupt_request_at_line_3()			EXTI_set_SWIERx(3)
#define EXTI_generate_interrupt_request_at_line_4()			EXTI_set_SWIERx(4)
#define EXTI_generate_interrupt_request_at_line_5()			EXTI_set_SWIERx(5)
#define EXTI_generate_interrupt_request_at_line_6()			EXTI_set_SWIERx(6)
#define EXTI_generate_interrupt_request_at_line_7()			EXTI_set_SWIERx(7)
#define EXTI_generate_interrupt_request_at_line_8()			EXTI_set_SWIERx(8)
#define EXTI_generate_interrupt_request_at_line_9()			EXTI_set_SWIERx(9)
#define EXTI_generate_interrupt_request_at_line_10()		EXTI_set_SWIERx(10)
#define EXTI_generate_interrupt_request_at_line_11()		EXTI_set_SWIERx(11)
#define EXTI_generate_interrupt_request_at_line_12()		EXTI_set_SWIERx(12)
#define EXTI_generate_interrupt_request_at_line_13()		EXTI_set_SWIERx(13)
#define EXTI_generate_interrupt_request_at_line_14()		EXTI_set_SWIERx(14)
#define EXTI_generate_interrupt_request_at_line_15()		EXTI_set_SWIERx(15)
#define EXTI_generate_interrupt_request_at_line_16()		EXTI_set_SWIERx(16)
#define EXTI_generate_interrupt_request_at_line_17()		EXTI_set_SWIERx(17)
#define EXTI_generate_interrupt_request_at_line_18()		EXTI_set_SWIERx(18)
#define EXTI_generate_interrupt_request_at_line_19()		EXTI_set_SWIERx(19)

#define EXTI_generate_event_request_at_line_0()				EXTI_set_SWIERx(0)
#define EXTI_generate_event_request_at_line_1()				EXTI_set_SWIERx(1)
#define EXTI_generate_event_request_at_line_2()				EXTI_set_SWIERx(2)
#define EXTI_generate_event_request_at_line_3()				EXTI_set_SWIERx(3)
#define EXTI_generate_event_request_at_line_4()				EXTI_set_SWIERx(4)
#define EXTI_generate_event_request_at_line_5()				EXTI_set_SWIERx(5)
#define EXTI_generate_event_request_at_line_6()				EXTI_set_SWIERx(6)
#define EXTI_generate_event_request_at_line_7()				EXTI_set_SWIERx(7)
#define EXTI_generate_event_request_at_line_8()				EXTI_set_SWIERx(8)
#define EXTI_generate_event_request_at_line_9()				EXTI_set_SWIERx(9)
#define EXTI_generate_event_request_at_line_10()			EXTI_set_SWIERx(10)
#define EXTI_generate_event_request_at_line_11()			EXTI_set_SWIERx(11)
#define EXTI_generate_event_request_at_line_12()			EXTI_set_SWIERx(12)
#define EXTI_generate_event_request_at_line_13()			EXTI_set_SWIERx(13)
#define EXTI_generate_event_request_at_line_14()			EXTI_set_SWIERx(14)
#define EXTI_generate_event_request_at_line_15()			EXTI_set_SWIERx(15)
#define EXTI_generate_event_request_at_line_16()			EXTI_set_SWIERx(16)
#define EXTI_generate_event_request_at_line_17()			EXTI_set_SWIERx(17)
#define EXTI_generate_event_request_at_line_18()			EXTI_set_SWIERx(18)
#define EXTI_generate_event_request_at_line_19()			EXTI_set_SWIERx(19)





//*********************Pending register (EXTI_PR)********************//
/*
挂起控制清除寄存器
Pending register (EXTI_PR)
Address offset: 0x14
Reset value: undefined
*/

/*
Bits 31:20
Reserved, must be kept at reset value (0).
*/

/*
Bits 19:0 PRx: Pending bit 
0: No trigger request occurred
1: selected trigger request occurred
This bit is set when the selected edge event arrives on the external interrupt line. This bit is 
cleared by writing a 1 into the bit or by changing the sensitivity of the edge detector. 
Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
*/
//获取lineNum上的挂起信息
U8 EXTI_get_PRx(U8 lineNum);


#define EXTI_is_interrupted_by_line_x(lineNum)	EXTI_get_PRx(lineNum)
#define EXTI_is_pending_at_line_x(lineNum)				EXTI_get_PRx(lineNum)

#define EXTI_is_interrupted_by_line_0()				EXTI_get_PRx(0)
#define EXTI_is_interrupted_by_line_1()				EXTI_get_PRx(1)
#define EXTI_is_interrupted_by_line_2()				EXTI_get_PRx(2)
#define EXTI_is_interrupted_by_line_3()				EXTI_get_PRx(3)
#define EXTI_is_interrupted_by_line_4()				EXTI_get_PRx(4)
#define EXTI_is_interrupted_by_line_5()				EXTI_get_PRx(5)
#define EXTI_is_interrupted_by_line_6()				EXTI_get_PRx(6)
#define EXTI_is_interrupted_by_line_7()				EXTI_get_PRx(7)
#define EXTI_is_interrupted_by_line_8()				EXTI_get_PRx(8)
#define EXTI_is_interrupted_by_line_9()				EXTI_get_PRx(9)
#define EXTI_is_interrupted_by_line_10()			EXTI_get_PRx(10)
#define EXTI_is_interrupted_by_line_11()			EXTI_get_PRx(11)
#define EXTI_is_interrupted_by_line_12()			EXTI_get_PRx(12)
#define EXTI_is_interrupted_by_line_13()			EXTI_get_PRx(13)
#define EXTI_is_interrupted_by_line_14()			EXTI_get_PRx(14)
#define EXTI_is_interrupted_by_line_15()			EXTI_get_PRx(15)
#define EXTI_is_interrupted_by_line_16()			EXTI_get_PRx(16)
#define EXTI_is_interrupted_by_line_17()			EXTI_get_PRx(17)
#define EXTI_is_interrupted_by_line_18()			EXTI_get_PRx(18)
#define EXTI_is_interrupted_by_line_19()			EXTI_get_PRx(19)


#define EXTI_is_pending_at_line_0()			EXTI_get_PRx(0)
#define EXTI_is_pending_at_line_1()			EXTI_get_PRx(1)
#define EXTI_is_pending_at_line_2()			EXTI_get_PRx(2)
#define EXTI_is_pending_at_line_3()			EXTI_get_PRx(3)
#define EXTI_is_pending_at_line_4()			EXTI_get_PRx(4)
#define EXTI_is_pending_at_line_5()			EXTI_get_PRx(5)
#define EXTI_is_pending_at_line_6()			EXTI_get_PRx(6)
#define EXTI_is_pending_at_line_7()			EXTI_get_PRx(7)
#define EXTI_is_pending_at_line_8()			EXTI_get_PRx(8)
#define EXTI_is_pending_at_line_9()			EXTI_get_PRx(9)
#define EXTI_is_pending_at_line_10()		EXTI_get_PRx(10)
#define EXTI_is_pending_at_line_11()		EXTI_get_PRx(11)
#define EXTI_is_pending_at_line_12()		EXTI_get_PRx(12)
#define EXTI_is_pending_at_line_13()		EXTI_get_PRx(13)
#define EXTI_is_pending_at_line_14()		EXTI_get_PRx(14)
#define EXTI_is_pending_at_line_15()		EXTI_get_PRx(15)
#define EXTI_is_pending_at_line_16()		EXTI_get_PRx(16)
#define EXTI_is_pending_at_line_17()		EXTI_get_PRx(17)
#define EXTI_is_pending_at_line_18()		EXTI_get_PRx(18)
#define EXTI_is_pending_at_line_19()		EXTI_get_PRx(19)


//清除lineNum上的挂起位
void EXTI_clear_PRx(U8 lineNum);

#define EXTI_clear_interrupt_flag_at_line_x(lineNum)	EXTI_clear_PRx(lineNum)
#define EXTI_clear_pending_flag_at_line_x(lineNum)		EXTI_clear_PRx(lineNum)

#define EXTI_clear_interrupt_flag_at_line_0()			EXTI_clear_PRx(0)
#define EXTI_clear_interrupt_flag_at_line_1()			EXTI_clear_PRx(1)
#define EXTI_clear_interrupt_flag_at_line_2()			EXTI_clear_PRx(2)
#define EXTI_clear_interrupt_flag_at_line_3()			EXTI_clear_PRx(3)
#define EXTI_clear_interrupt_flag_at_line_4()			EXTI_clear_PRx(4)
#define EXTI_clear_interrupt_flag_at_line_5()			EXTI_clear_PRx(5)
#define EXTI_clear_interrupt_flag_at_line_6()			EXTI_clear_PRx(6)
#define EXTI_clear_interrupt_flag_at_line_7()			EXTI_clear_PRx(7)
#define EXTI_clear_interrupt_flag_at_line_8()			EXTI_clear_PRx(8)
#define EXTI_clear_interrupt_flag_at_line_9()			EXTI_clear_PRx(9)
#define EXTI_clear_interrupt_flag_at_line_10()			EXTI_clear_PRx(10)
#define EXTI_clear_interrupt_flag_at_line_11()			EXTI_clear_PRx(11)
#define EXTI_clear_interrupt_flag_at_line_12()			EXTI_clear_PRx(12)
#define EXTI_clear_interrupt_flag_at_line_13()			EXTI_clear_PRx(13)
#define EXTI_clear_interrupt_flag_at_line_14()			EXTI_clear_PRx(14)
#define EXTI_clear_interrupt_flag_at_line_15()			EXTI_clear_PRx(15)
#define EXTI_clear_interrupt_flag_at_line_16()			EXTI_clear_PRx(16)
#define EXTI_clear_interrupt_flag_at_line_17()			EXTI_clear_PRx(17)
#define EXTI_clear_interrupt_flag_at_line_18()			EXTI_clear_PRx(18)
#define EXTI_clear_interrupt_flag_at_line_19()			EXTI_clear_PRx(19)


#define EXTI_clear_pending_flag_at_line_0()			EXTI_clear_PRx(0)
#define EXTI_clear_pending_flag_at_line_1()			EXTI_clear_PRx(1)
#define EXTI_clear_pending_flag_at_line_2()			EXTI_clear_PRx(2)
#define EXTI_clear_pending_flag_at_line_3()			EXTI_clear_PRx(3)
#define EXTI_clear_pending_flag_at_line_4()			EXTI_clear_PRx(4)
#define EXTI_clear_pending_flag_at_line_5()			EXTI_clear_PRx(5)
#define EXTI_clear_pending_flag_at_line_6()			EXTI_clear_PRx(6)
#define EXTI_clear_pending_flag_at_line_7()			EXTI_clear_PRx(7)
#define EXTI_clear_pending_flag_at_line_8()			EXTI_clear_PRx(8)
#define EXTI_clear_pending_flag_at_line_9()			EXTI_clear_PRx(9)
#define EXTI_clear_pending_flag_at_line_10()		EXTI_clear_PRx(10)
#define EXTI_clear_pending_flag_at_line_11()		EXTI_clear_PRx(11)
#define EXTI_clear_pending_flag_at_line_12()		EXTI_clear_PRx(12)
#define EXTI_clear_pending_flag_at_line_13()		EXTI_clear_PRx(13)
#define EXTI_clear_pending_flag_at_line_14()		EXTI_clear_PRx(14)
#define EXTI_clear_pending_flag_at_line_15()		EXTI_clear_PRx(15)
#define EXTI_clear_pending_flag_at_line_16()		EXTI_clear_PRx(16)
#define EXTI_clear_pending_flag_at_line_17()		EXTI_clear_PRx(17)
#define EXTI_clear_pending_flag_at_line_18()		EXTI_clear_PRx(18)
#define EXTI_clear_pending_flag_at_line_19()		EXTI_clear_PRx(19)

#endif	
