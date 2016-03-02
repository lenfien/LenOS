

/*
	此文档里定义了高级定时器TIM1和8所使用到的所有寄存器，和对这些寄存器的基础操作。
	TIM1_8在芯片手册的13章有详细讲述。
*/

#ifndef __TIM18
#define __TIM18

#include "com.h"
#include "core_map.h"

//*********************************************TIM1寄存器定义**********************************************//
//TIM1寄存器纯地址定义
#define	__TIM1_CR1		(TIM1_BASE + 0x00000000)
#define	__TIM1_CR2 		(TIM1_BASE + 0x00000004)
#define __TIM1_SMCR		(TIM1_BASE + 0x00000008)
#define __TIM1_DIER		(TIM1_BASE + 0x0000000C)
#define __TIM1_SR		(TIM1_BASE + 0x00000010)
#define __TIM1_EGR		(TIM1_BASE + 0x00000014)
#define __TIM1_CCMR1	(TIM1_BASE + 0x00000018)
#define __TIM1_CCMR2	(TIM1_BASE + 0x0000001C)
#define __TIM1_CCER		(TIM1_BASE + 0x00000020)
#define __TIM1_CNT		(TIM1_BASE + 0x00000024)
#define __TIM1_PSC		(TIM1_BASE + 0x00000028)
#define __TIM1_ARR		(TIM1_BASE + 0x0000002C)
#define __TIM1_RCR		(TIM1_BASE + 0x00000030)
#define __TIM1_CCR1		(TIM1_BASE + 0x00000034)
#define __TIM1_CCR2		(TIM1_BASE + 0x00000038)
#define __TIM1_CCR3		(TIM1_BASE + 0x0000003C)
#define __TIM1_CCR4		(TIM1_BASE + 0x00000040)
#define __TIM1_BDTR		(TIM1_BASE + 0x00000044)
#define __TIM1_DCR		(TIM1_BASE + 0x00000048)
#define __TIM1_DMAR		(TIM1_BASE + 0x0000004C)


//TIM1寄存器转化为地址
#define	_TIM1_CR1		ADR(__TIM1_CR1)		
#define	_TIM1_CR2		ADR(__TIM1_CR2) 		
#define _TIM1_SMCR		ADR(__TIM1_SMCR)	
#define _TIM1_DIER		ADR(__TIM1_DIER)		
#define _TIM1_SR		ADR(__TIM1_SR)	
#define _TIM1_EGR		ADR(__TIM1_EGR)	
#define _TIM1_CCMR1		ADR(__TIM1_CCMR1)	
#define _TIM1_CCMR2		ADR(__TIM1_CCMR2)	
#define _TIM1_CCER		ADR(__TIM1_CCER)		
#define _TIM1_CNT		ADR(__TIM1_CNT)		
#define _TIM1_PSC		ADR(__TIM1_PSC)		
#define _TIM1_ARR		ADR(__TIM1_ARR)		
#define _TIM1_RCR		ADR(__TIM1_RCR)		
#define _TIM1_CCR1		ADR(__TIM1_CCR1)		
#define	_TIM1_CCR2		ADR(__TIM1_CCR2)		
#define _TIM1_CCR3		ADR(__TIM1_CCR3)	
#define _TIM1_CCR4		ADR(__TIM1_CCR4)		
#define _TIM1_BDTR		ADR(__TIM1_BDTR)		
#define _TIM1_DCR		ADR(__TIM1_DCR)		
#define _TIM1_DMAR		ADR(__TIM1_DMAR)	


//TIM1寄存器转化为值
#define	TIM1_CR1		VAL(__TIM1_CR1)		
#define	TIM1_CR2		VAL(__TIM1_CR2) 		
#define TIM1_SMCR		VAL(__TIM1_SMCR)	
#define TIM1_DIER		VAL(__TIM1_DIER)		
#define TIM1_SR			VAL(__TIM1_SR)	
#define TIM1_EGR		VAL(__TIM1_EGR)	
#define TIM1_CCMR1		VAL(__TIM1_CCMR1)	
#define TIM1_CCMR2		VAL(__TIM1_CCMR2)	
#define TIM1_CCER		VAL(__TIM1_CCER)		
#define TIM1_CNT		VAL(__TIM1_CNT)		
#define TIM1_PSC		VAL(__TIM1_PSC)		
#define TIM1_ARR		VAL(__TIM1_ARR)		
#define TIM1_RCR		VAL(__TIM1_RCR)		
#define TIM1_CCR1		VAL(__TIM1_CCR1)		
#define	TIM1_CCR2		VAL(__TIM1_CCR2)		
#define TIM1_CCR3		VAL(__TIM1_CCR3)	
#define TIM1_CCR4		VAL(__TIM1_CCR4)		
#define TIM1_BDTR		VAL(__TIM1_BDTR)		
#define TIM1_DCR		VAL(__TIM1_DCR)		
#define TIM1_DMAR		VAL(__TIM1_DMAR)	

//*********************************************TIM8寄存器定义************************************//
//TIM8寄存器的定义
//纯地址
#define	__TIM8_CR1		(TIM8_BASE + 0x00000000)
#define	__TIM8_CR2 		(TIM8_BASE + 0x00000004)
#define __TIM8_SMCR		(TIM8_BASE + 0x00000008)
#define __TIM8_DIER		(TIM8_BASE + 0x0000000C)
#define __TIM8_SR		(TIM8_BASE + 0x00000010)
#define __TIM8_EGR		(TIM8_BASE + 0x00000014)
#define __TIM8_CCMR1	(TIM8_BASE + 0x00000018)
#define __TIM8_CCMR2	(TIM8_BASE + 0x0000001C)
#define __TIM8_CCER		(TIM8_BASE + 0x00000020)
#define __TIM8_CNT		(TIM8_BASE + 0x00000024)
#define __TIM8_PSC		(TIM8_BASE + 0x00000028)
#define __TIM8_ARR		(TIM8_BASE + 0x0000002C)
#define __TIM8_RCR		(TIM8_BASE + 0x00000030)
#define __TIM8_CCR1		(TIM8_BASE + 0x00000034)
#define __TIM8_CCR2		(TIM8_BASE + 0x00000038)
#define __TIM8_CCR3		(TIM8_BASE + 0x0000003C)
#define __TIM8_CCR4		(TIM8_BASE + 0x00000040)
#define __TIM8_BDTR		(TIM8_BASE + 0x00000044)
#define __TIM8_DCR		(TIM8_BASE + 0x00000048)
#define __TIM8_DMAR		(TIM2_BASE + 0x0000004C)


//TIM8寄存器转化为地址
#define	_TIM8_CR1		ADR(__TIM8_CR1)		
#define	_TIM8_CR2		ADR(__TIM8_CR2) 		
#define _TIM8_SMCR		ADR(__TIM8_SMCR)	
#define _TIM8_DIER		ADR(__TIM8_DIER)		
#define _TIM8_SR		ADR(__TIM8_SR)	
#define _TIM8_EGR		ADR(__TIM8_EGR)	
#define _TIM8_CCMR1		ADR(__TIM8_CCMR1)	
#define _TIM8_CCMR2		ADR(__TIM8_CCMR2)	
#define _TIM8_CCER		ADR(__TIM8_CCER)		
#define _TIM8_CNT		ADR(__TIM8_CNT)		
#define _TIM8_PSC		ADR(__TIM8_PSC)		
#define _TIM8_ARR		ADR(__TIM8_ARR)		
#define _TIM8_RCR		ADR(__TIM8_RCR)		
#define _TIM8_CCR1		ADR(__TIM8_CCR1)		
#define	_TIM8_CCR2		ADR(__TIM8_CCR2)		
#define _TIM8_CCR3		ADR(__TIM8_CCR3)	
#define _TIM8_CCR4		ADR(__TIM8_CCR4)		
#define _TIM8_BDTR		ADR(__TIM8_BDTR)		
#define _TIM8_DCR		ADR(__TIM8_DCR)		
#define _TIM8_DMAR		ADR(__TIM8_DMAR)	


//TIM8寄存器转化为值
#define	TIM8_CR1		VAL(__TIM8_CR1)		
#define	TIM8_CR2		VAL(__TIM8_CR2) 		
#define TIM8_SMCR		VAL(__TIM8_SMCR)	
#define TIM8_DIER		VAL(__TIM8_DIER)		
#define TIM8_SR			VAL(__TIM8_SR)	
#define TIM8_EGR		VAL(__TIM8_EGR)	
#define TIM8_CCMR1		VAL(__TIM8_CCMR1)	
#define TIM8_CCMR2		VAL(__TIM8_CCMR2)	
#define TIM8_CCER		VAL(__TIM8_CCER)		
#define TIM8_CNT		VAL(__TIM8_CNT)		
#define TIM8_PSC		VAL(__TIM8_PSC)		
#define TIM8_ARR		VAL(__TIM8_ARR)		
#define TIM8_RCR		VAL(__TIM8_RCR)		
#define TIM8_CCR1		VAL(__TIM8_CCR1)		
#define	TIM8_CCR2		VAL(__TIM8_CCR2)		
#define TIM8_CCR3		VAL(__TIM8_CCR3)	
#define TIM8_CCR4		VAL(__TIM8_CCR4)		
#define TIM8_BDTR		VAL(__TIM8_BDTR)		
#define TIM8_DCR		VAL(__TIM8_DCR)		
#define TIM8_DMAR		VAL(__TIM1_DMAR)

#include "base_atime.h"
#include "com.h"


//**************************************************//
//***********************TIMx_CR1*******************//
//**************************************************//
/*TIM1&TIM8 控制寄存器1
TIM1&TIM8 control register 1 (TIMx_CR1)
Address offset: 0x00
Reset value: 0x0000
*/


/*Bits 15:10 Reserved, always read as 0
*/

/*Bits 9:8 CKD[1:0]: Clock division
This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and the 
dead-time and sampling clock (tDTS)used by the dead-time generators and the digital filters 
(ETR, TIx),
00: tDTS=tCK_INT
01: tDTS=2*tCK_INT
10: tDTS=4*tCK_INT
11: Reserved, do not program this value
*/

//to do

/*自动重装预装载使能位
	设置该位会导致计数器的自动重装计数器在下一个更新事件发生时装入它的影子寄存器
Bit 7 ARPE: Auto-reload preload enable
0: TIMx_ARR register is not buffered
1: TIMx_ARR register is buffered
*/
void TIM1_set_ARPE(U8 e_d);
void TIM8_set_ARPE(U8 e_d);

#define TIM1_enable_ARR_preload()	TIM1_set_ARPE(1)	//TIM1计数器的自动重装载使能预装载功能
#define TIM1_disable_ARR_preload()	TIM1_set_ARPE(0)	//TIM1计数器的自动重装载除能预装载功能

#define TIM8_enable_ARR_preload()	TIM8_set_ARPE(1)	//TIM8计数器的自动重装载使能预装载功能
#define TIM8_disable_ARR_preload()	TIM8_set_ARPE(0)	//TIM8计数器的自动重装载除能预装载功能


/*计数器计数中心对其模式选择
	设置该位用来选择计数器的计数方向
	当该位段全为00时，计数器的计数方向由DIR位控制
	否则，计数器的计数是中心对其的
	当计数器为中心对其计数时，输出比较事件在何时产生由01, 10, 11选择。
Bits 6:5 CMS[1:0]: Center-aligned mode selection
00: Edge-aligned mode. The counter counts up or down depending on the direction bit 
(DIR).
01: Center-aligned mode 1. The counter counts up and down alternatively. Output compare 
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set 
only when the counter is counting down.
10: Center-aligned mode 2. The counter counts up and down alternatively. Output compare 
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set 
only when the counter is counting up.
11: Center-aligned mode 3. The counter counts up and down alternatively. Output compare 
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set 
both when the counter is counting up or down.
Note: It is not allowed to switch from edge-aligned mode to center-aligned mode as long as 
the counter is enabled (CEN=1)
*/
void TIM1_set_CMS(U8 cms);
void TIM8_set_CMS(U8 cms);

#define TIM1_set_edge_align_mode()		TIM1_set_CMS(0)		//设置计数器在边沿计数模式下工作
#define TIM1_set_center_align_mode1()	TIM1_set_CMS(1)		//设置计数器在中心对其模式1下工作(比较中断发生在向下计数时)
#define TIM1_set_center_align_mode2()	TIM1_set_CMS(2)		//设置计数器在中心对其模式2下工作(比较中断发生在向上计数时)
#define TIM1_set_center_align_mode3()	TIM1_set_CMS(3)		//设置计数器在中心对其模式1下工作(比较中断发生在上下计数时)

#define TIM8_set_edge_align_mode()		TIM8_set_CMS(0)		//设置计数器在边沿计数模式下工作
#define TIM8_set_center_align_mode1()	TIM8_set_CMS(1)		//设置计数器在中心对其模式1下工作(比较中断发生在向下计数时)
#define TIM8_set_center_align_mode2()	TIM8_set_CMS(2)		//设置计数器在中心对其模式2下工作(比较中断发生在向上计数时)
#define TIM8_set_center_align_mode3()	TIM8_set_CMS(3)		//设置计数器在中心对其模式1下工作(比较中断发生在上下计数时)


/*计数器计数方向设置
	当计数器为边沿对其模式计数时(CMS=00)，DIR位才可以被写。
	其它情况由硬件设置，软件只可以读。
Bit 4 DIR: Direction
0: Counter used as upcounter
1: Counter used as downcounter
Note: This bit is read only when the timer is configured in Center-aligned mode or Encoder 
mode.
*/
void TIM1_set_DIR(U8 dir);
void TIM8_set_DIR(U8 dir);

#define TIM1_set_counter_direction_up()		TIM1_set_DIR(0)		//TIM1计数在边沿模式时为向上计数
#define TIM1_set_counter_direction_down()	TIM1_set_DIR(1)		//TIM1计数在边沿模式时为向下计数

#define TIM8_set_counter_direction_up()		TIM8_set_DIR(0)		//TIM8计数在边沿模式时为向上计数
#define TIM8_set_counter_direction_down()	TIM8_set_DIR(1)		//TIM8计数在边沿模式时为向下计数

/*单脉冲模式
	当设置了该位后，计数器在产生一次溢出更新事件后停止计数(CEN位被硬件清零)
Bit 3 OPM: One pulse mode
0: Counter is not stopped at update event
1: Counter stops counting at the next update event (clearing the bit CEN)
*/
void TIM1_set_OPM(U8 opm);
void TIM8_set_OPM(U8 opm);

#define TIM1_enable_one_pulse_mode()	TIM1_set_OPM(1)		//计数器工作在单脉冲模式下
#define TIM1_disalbe_one_pulse_mode()	TIM1_set_OPM(0)		//计数器工作在连续模式下

#define TIM8_enable_one_pulse_mode()	TIM8_set_OPM(1)		//计数器工作在单脉冲模式下
#define TIM8_disalbe_one_pulse_mode()	TIM8_set_OPM(0)		//计数器工作在连续模式下


/*更新事件请求源选择
	该位用来选择更新事件的触发源
	触发源有:
		计数器上下溢出
		设置UG位
		从模式控制器产生
Bit 2 URS: Update request source
This bit is set and cleared by software to select the UEV event sources.
0: Any of the following events generate an update interrupt or DMA request if enabled. 
These events can be: 
–Counter overflow/underflow
–Setting the UG bit
–Update generation through the slave mode controller
1: Only counter overflow/underflow generates an update interrupt or DMA request if 
enabled.
*/
void TIM1_set_URS(U8 urs);
void TIM8_set_URS(U8 urs);

#define TIM1_set_update_source_any()		TIM1_set_URS(0)	//设置TIM1的更新事件源为 见位段说明
#define TIM1_set_update_source_overflow()	TIM1_set_URS(1)	//设置TIM1的更新事件源为 计数溢出

#define TIM8_set_update_source_any()		TIM8_set_URS(0)	//设置TIM8的更新事件源为 见位段说明
#define TIM8_set_update_source_overflow()	TIM8_set_URS(1)	//设置TIM8的更新事件源为 计数溢出

/*禁止更新事件产生
	禁止更新事件后，ARR,PSC,CCRx的预装载装载寄存器的值将不能进入其影子寄存器
	对于ARR，只有在允许预装载时，更新事件才会将预装载的值装入影子寄存器，此时
	该位才会有用。否则ARR的值会在刚一设置其预装载寄存器便进入其影子寄存器，此时
	该位无用。
Bit 1 UDIS: Update disable
This bit is set and cleared by software to enable/disable UEV event generation.
0: UEV enabled. The Update (UEV) event is generated by one of the following events:
–Counter overflow/underflow
–Setting the UG bit
–Update generation through the slave mode controller
Buffered registers are then loaded with their preload values.
1: UEV disabled. The Update event is not generated, shadow registers keep their value 
(ARR, PSC, CCRx). However the counter and the prescaler are reinitialized if the UG bit is 
set or if a hardware reset is received from the slave mode controller.
*/
void TIM1_set_UDIS(U8 udis);
void TIM8_set_UDIS(U8 udis);

#define TIM1_enable_update_event()	TIM1_set_UDIS(0)	//TIM1允许更新事件发生
#define TIM1_disable_update_event()	TIM1_set_UDIS(1)	//TIM1禁止更新事件发生

#define TIM8_enable_update_event()	TIM8_set_UDIS(0)	//TIM8允许更新事件发生
#define TIM8_disable_update_event()	TIM8_set_UDIS(1)	//TIM8禁止更新事件发生

/*计数器使能位
	使能计数器后，计数器会开始计数，在计数过程中可能会发生:
		溢出事件(计数器的值上下溢出)
		捕获事件(从外部输入一个脉冲)
		比较事件(CCRx的值和COUNTER的值相等时)
Bit 0 CEN: Counter enable
0: Counter disabled
1: Counter enabled
Note: External clock, gated mode and encoder mode can work only if the CEN bit has been 
previously set by software. However trigger mode can set the CEN bit automatically by 
hardware.
*/
void TIM1_set_CEN(U8 cen);
void TIM8_set_CEN(U8 cen);

#define TIM1_enable_counter()	TIM1_set_CEN(1)		//使能计数器,计数器开始计数
#define TIM1_disable_counter()	TIM1_set_CEN(0)		//除能计数器,计数器停止计数

#define TIM8_enable_counter()	TIM8_set_CEN(1)		//使能计数器,计数器开始计数
#define TIM8_disable_counter()	TIM8_set_CEN(0)		//除能计数器,计数器停止计数


//*********************************************************************//
//**************TIM1&TIM8 control register 2 (TIMx_CR2)****************//
//*********************************************************************//
/*TIM1&TIM8控制寄存器2
TIM1&TIM8 control register 2 (TIMx_CR2)
Address offset: 0x04
Reset value: 0x0000
*/
/*Bit 15 Reserved, always read as 0
*/

/*Bit 14 OIS4: Output Idle state 4 (OC4 output)
refer to OIS1 bit
*/
//to do
/*Bit 13 OIS3N: Output Idle state 3 (OC3N output)
refer to OIS1N bit
*/
//to do
/*Bit 12 OIS3: Output Idle state 3 (OC3 output)
refer to OIS1 bit
*/
//to do
/*Bit 11 OIS2N: Output Idle state 2 (OC2N output)
refer to OIS1N bit
*/
//to do
/*Bit 10 OIS2: Output Idle state 2 (OC2 output)
refer to OIS1 bit
*/
//to do
/*Bit 9 OIS1N: Output Idle state 1 (OC1N output)
0: OC1N=0 after a dead-time when MOE=0
1: OC1N=1 after a dead-time when MOE=0
Note: This bit can not be modified as long as LOCK level 1, 2 or 3 has been programmed 
(LOCK bits in TIMx_BDTR register).
*/
//to do
/*Bit 8 OIS1: Output Idle state 1 (OC1 output)
0: OC1=0 (after a dead-time if OC1N is implemented) when MOE=0
1: OC1=1 (after a dead-time if OC1N is implemented) when MOE=0
Note: This bit can not be modified as long as LOCK level 1, 2 or 3 has been programmed 
(LOCK bits in TIMx_BDTR register).
*/
//to do

/*通道1输入选择
	1通道的输入可以是两种
		正常的Channel1输入
		CH1 和CH2和CH3异或输入
Bit 7 TI1S: TI1 selection
0: The TIMx_CH1 pin is connected to TI1 input
1: The TIMx_CH1, CH2 and CH3 pins are connected to the TI1 input (XOR combination)
*/
void TIM1_set_TI1S(U8 ti1s);
void TIM8_set_TI1S(U8 ti1s);

#define TIM1_set_TI1_input_CH1()	TIM1_set_TI1S(0)		//TIM1的CHANNEL1输入到TI1		
#define TIM1_set_TI1_input_XOR()	TIM1_set_TI1S(1)		//TIM1的CHANNEL1 XOR CH2 XOR CH3输入到 TI1

#define TIM8_set_TI1_input_CH1()	TIM8_set_TI1S(0)		//TIM8的CHANNEL1输入到TI1		
#define TIM8_set_TI1_input_XOR()	TIM8_set_TI1S(1)		//TIM8的CHANNEL1 XOR CH2 XOR CH3输入到 TI1


/*主模式选择
	当前计数器引出的TRGO可以触发其它模块
	TRGO可以来自TIM的多个地方
	这几位就是用来选择TRGO的来源
		UG位为TRGO的输出
		CNT_EN位为TRGO的输出
		Update事件产生一个TRGO输出
		Compare中:
			OC1REF
			OC2REF
			OC3REF
			OC4REF
		作为TRGO的输出
Bits 6:4 MMS[1:0]: Master mode selection
These bits allow to select the information to be sent in master mode to slave timers for 
synchronization (TRGO). The combination is as follows:

000: Reset - the UG bit from the TIMx_EGR register is used as trigger output (TRGO). If the 
reset is generated by the trigger input (slave mode controller configured in reset mode) then 
the signal on TRGO is delayed compared to the actual reset.

001: Enable - the Counter Enable signal CNT_EN is used as trigger output (TRGO). It is 
useful to start several timers at the same time or to control a window in which a slave timer is 
enable. The Counter Enable signal is generated by a logic OR between CEN control bit and 
the trigger input when configured in gated mode. When the Counter Enable signal is 
controlled by the trigger input, there is a delay on TRGO, except if the master/slave mode is 
selected (see the MSM bit description in TIMx_SMCR register).

010: Update - The update event is selected as trigger output (TRGO). For instance a master 
timer can then be used as a prescaler for a slave timer.
011: Compare Pulse - The trigger output send a positive pulse when the CC1IF flag is to be 
set (even if it was already high), as soon as a capture or a compare match occurred. 
(TRGO).

100: Compare - OC1REF signal is used as trigger output (TRGO)
101: Compare - OC2REF signal is used as trigger output (TRGO)
110: Compare - OC3REF signal is used as trigger output (TRGO)
111: Compare - OC4REF signal is used as trigger output (TRGO)
*/
void TIM1_set_MMS(U8 mms);
void TIM8_set_MMS(U8 mms);

#define TIM1_set_TRGO_as_UG()				TIM1_set_MMS(0)		//TRGO被作为UG位的输出
#define TIM1_set_TRGO_as_EN()				TIM1_set_MMS(1)		//TRGO被作为CNT_EN位的输出
#define TIM1_set_TRGO_as_update()			TIM1_set_MMS(2)		//TRGO被作为update事件的输出(单一脉冲输出)
#define TIM1_set_TRGO_as_compare_pulse()	TIM1_set_MMS(3)		//比较/捕获事件发生时产生一个脉冲输出到TRGO
#define TIM1_set_TRGO_as_compare_OC1REF()	TIM1_set_MMS(4)		//比较通道的OC1REF作为TRGO的输出
#define TIM1_set_TRGO_as_compare_OC2REF()	TIM1_set_MMS(5)		//比较通道的OC2REF作为TRGO的输出
#define TIM1_set_TRGO_as_compare_OC3REF()	TIM1_set_MMS(6)		//比较通道的OC3REF作为TRGO的输出
#define TIM1_set_TRGO_as_compare_OC4REF()	TIM1_set_MMS(7)		//比较通道的OC4REF作为TRGO的输出

#define TIM8_set_TRGO_as_UG()				TIM8_set_MMS(0)		//TRGO被作为UG位的输出
#define TIM8_set_TRGO_as_EN()				TIM8_set_MMS(1)		//TRGO被作为CNT_EN位的输出
#define TIM8_set_TRGO_as_update()			TIM8_set_MMS(2)		//TRGO被作为update事件的输出(单一脉冲输出)
#define TIM8_set_TRGO_as_compare_pulse()	TIM8_set_MMS(3)		//比较/捕获事件发生时产生一个脉冲输出到TRGO
#define TIM8_set_TRGO_as_compare_OC1REF()	TIM8_set_MMS(4)		//比较通道的OC1REF作为TRGO的输出
#define TIM8_set_TRGO_as_compare_OC2REF()	TIM8_set_MMS(5)		//比较通道的OC2REF作为TRGO的输出
#define TIM8_set_TRGO_as_compare_OC3REF()	TIM8_set_MMS(6)		//比较通道的OC3REF作为TRGO的输出
#define TIM8_set_TRGO_as_compare_OC4REF()	TIM8_set_MMS(7)		//比较通道的OC4REF作为TRGO的输出


/*在什么时候发送DMA请求
	发生update事件时产生DMA请求
	发生输入捕获或比较事件产生DMA请求
Bit 3 CCDS: Capture/compare DMA selection
0: CCx DMA request sent when CCx event occurs
1: CCx DMA requests sent when update event occurs
*/
void TIM1_set_CCDS(U8 ccds);
void TIM8_set_CCDS(U8 ccds);

#define TIM1_DMA_request_send_when_cc_event()		TIM1_set_CCDS(0)	//当发生比较捕获时间时产生DMA请求
#define TIM1_DMA_request_send_when_update_event()	TIM1_set_CCDS(1)	//当发生更新事件时产生DMA请求

#define TIM8_DMA_request_send_when_cc_event()		TIM8_set_CCDS(0)	//当发生比较捕获时间时产生DMA请求
#define TIM8_DMA_request_send_when_update_event()	TIM8_set_CCDS(1)	//当发生更新事件时产生DMA请求

/*Bit 2 CCUS: Capture/compare control update selection
0: When capture/compare control bits are preloaded (CCPC=1), they are updated by setting 
the COMG bit only
1: When capture/compare control bits are preloaded (CCPC=1), they are updated by setting 
the COMG bit or when an rising edge occurs on TRGI
Note: This bit acts only on channels that have a complementary output.
*/
//to do

/*Bit 1 Reserved, always read as 0
*/

/*Bit 0 CCPC: Capture/compare preloaded control
0: CCxE, CCxNE and OCxM bits are not preloaded
1: CCxE, CCxNE and OCxM bits are preloaded, after having been written, they are updated 
only when COM bit is set.
Note: This bit acts only on channels that have a complementary output.
*/
//to do

//*************************************************************//
//*******TIM1&TIM8 slave mode control register (TIMx_SMCR)*****//
//*************************************************************//
/*TIM1&TIM8从模式控制寄存器
TIM1&TIM8 slave mode control register (TIMx_SMCR)
Address offset: 0x08
Reset value: 0x0000
*/

/*外部信号EXR输入极性选择
	当从模式控制器将时钟源选择为EXR(ECE = 1),COUNTER的时钟由
	EXR引脚输入
	此位用来选择EXR的输入极性，以确定COUNTER在何时计数
Bit 15 ETP: External trigger polarity
This bit selects whether ETR or ETR is used for trigger operations
0: ETR is non-inverted, active at high level or rising edge.
1: ETR is inverted, active at low level or falling edge.
*/
void TIM1_set_ETP(U8 etp);
void TIM8_set_ETP(U8 etp);

#define TIM1_set_EXR_polarity_high()	TIM1_set_ETP(0)		//外部输入引脚的极性为高(不翻转)
#define TIM1_set_EXR_polarity_low()		TIM1_set_ETP(1)		//外部输入引脚的极性为低(翻转)

#define TIM8_set_EXR_polarity_high()	TIM8_set_ETP(0)		//外部输入引脚的极性为高(不翻转)
#define TIM8_set_EXR_polarity_low()		TIM8_set_ETP(1)		//外部输入引脚的极性为低(翻转)

/*外部时钟模式2使能
外部时钟EXR输入使能位
	当设置了该位，计数器的时钟由EXR外部输入驱动.
	EXR引脚先经过极性选择，再经过分频器，再经过滤波器，然后才传入COUNTER进行计数.
Bit 14 ECE: External clock enable
This bit enables External clock mode 2.
0: External clock mode 2 disabled
1: External clock mode 2 enabled. The counter is clocked by any active edge on the ETRF 
signal.
Note: 1: Setting the ECE bit has the same effect as selecting external clock mode 1 with 
TRGI connected to ETRF (SMS=111 and TS=111).
2: It is possible to simultaneously use external clock mode 2 with the following slave 
modes: reset mode, gated mode and trigger mode. Nevertheless, TRGI must not be 
connected to ETRF in this case (TS bits must not be 111).
3: If external clock mode 1 and external clock mode 2 are enabled at the same time, 
the external clock input is ETRF.
*/
void TIM1_set_ECE(U8 ece);
void TIM8_set_ECE(U8 ece);

#define TIM1_enable_external_clock_mode_2()		TIM1_set_ECE(1)	//外部ETR经过Filter后驱动Counter
#define TIM1_disable_external_clock_mode_2()	TIM1_set_ECE(0)	//禁止ETR驱动Counter

#define TIM8_enable_external_clock_mode_2()		TIM8_set_ECE(1)	//外部ETR经过Filter后驱动Counter
#define TIM8_disable_external_clock_mode_2()	TIM8_set_ECE(0)	//禁止ETR驱动Counter


/*外部EXR输入分频
	当设置了ECE位，计数器的时钟由EXR外部输入驱动.
	EXR引脚先经过极性选择，再经过分频器，再经过滤波器，然后才传入COUNTER进行计数.
	此位段用来设置分频器的分频
Bits 13:12 ETPS[1:0]: External trigger prescaler
External trigger signal ETRP frequency must be at most 1/4 of TIMxCLK frequency. A 
prescaler can be enabled to reduce ETRP frequency. It is useful when inputting fast external 
clocks.
00: Prescaler OFF
01: ETRP frequency divided by 2
10: ETRP frequency divided by 4
11: ETRP frequency divided by 8
*/
void TIM1_set_ETPS(U8 etps);
void TIM8_set_ETPS(U8 etps);

#define TIM1_set_ETR_prescaler_1()	TIM1_set_ETPS(0)	//外部ETR输入不分频
#define TIM1_set_ETR_prescaler_2()	TIM1_set_ETPS(1)	//外部ETR输入2分频
#define TIM1_set_ETR_prescaler_4()	TIM1_set_ETPS(2)	//外部ETR输入4分频
#define TIM1_set_ETR_prescaler_8()	TIM1_set_ETPS(3)	//外部ETR输入8分频

#define TIM8_set_ETR_prescaler_1()	TIM8_set_ETPS(0)	//外部ETR输入不分频
#define TIM8_set_ETR_prescaler_2()	TIM8_set_ETPS(1)	//外部ETR输入2分频
#define TIM8_set_ETR_prescaler_4()	TIM8_set_ETPS(2)	//外部ETR输入4分频
#define TIM8_set_ETR_prescaler_8()	TIM8_set_ETPS(3)	//外部ETR输入8分频


/*外部ETR输入滤波
	当设置了ECE位，计数器的时钟由EXR外部输入驱动.
	EXR引脚先经过极性选择，再经过分频器，再经过滤波器，然后才传入COUNTER进行计数.
	此位段用来设置滤波器的滤波系数
Bits 11:8 ETF[3:0]: External trigger filter
This bit-field then defines the frequency used to sample ETRP signal and the length of the 
digital filter applied to ETRP. The digital filter is made of an event counter in which N events 
are needed to validate a transition on the output:
0000: No filter, sampling is done at fDTS
0001: fSAMPLING=fCK_INT, N=2
0010: fSAMPLING=fCK_INT, N=4
0011: fSAMPLING=fCK_INT, N=8
0100: fSAMPLING=fDTS/2, N=6
0101: fSAMPLING=fDTS/2, N=8
0110: fSAMPLING=fDTS/4, N=6
0111: fSAMPLING=fDTS/4, N=8
1000: fSAMPLING=fDTS/8, N=6
1001: fSAMPLING=fDTS/8, N=8
1010: fSAMPLING=fDTS/16, N=5
1011: fSAMPLING=fDTS/16, N=6
1100: fSAMPLING=fDTS/16, N=8
1101: fSAMPLING=fDTS/32, N=5
1110: fSAMPLING=fDTS/32, N=6
1111: fSAMPLING=fDTS/32, N=8
*/
void TIM1_set_ETF(U8 etf);
void TIM8_set_ETF(U8 etf);


/*主/从模式
	当该位被设置后，当前的计数器在获取到一个TRGI输入时钟后有一个延迟，这样做可以让被它的TRGO
	驱动的从TIMER与它同步。

Bit 7 MSM: Master/slave mode
0: No action
1: The effect of an event on the trigger input (TRGI) is delayed to allow a perfect 
synchronization between the current timer and its slaves (through TRGO). It is useful if we 
want to synchronize several timers on a single external event.
*/
void TIM1_set_MSM(void);
void TIM8_set_MSM(void);

/*触发源选择
	该位段用来选择输入到从模式控制器TRGI端的信号源
	触发源输入的信号会输入到从模式控制器的TRGI，所以从模式控制器必须被配置成外部时钟模式1才可以
	接收到此输入
	当选择在 000 - 011时，TRGI信号来自内部其它时钟的TRGO,对应关系如下:
	SlaveTim | ITR0 | ITR1 |	ITR2 | ITR3 |
	TIM1	 | TIM5 | TIM2 |	TIM3 | TIM4 |
	TIM8	 | TIM1 | TIM2 |	TIM4 | TIM5 |

Bits 6:4 TS[2:0]: Trigger selection
This bit-field selects the trigger input to be used to synchronize the counter.
000: Internal Trigger 0 (ITR0) 
001: Internal Trigger 1 (ITR1)
010: Internal Trigger 2 (ITR2)
011: Internal Trigger 3 (ITR3)
100: TI1 Edge Detector 	(TI1F_ED)		//TI1F_Rising和TI1F_Falling的逻辑或(应该始终为1)
101: Filtered Timer Input 1 (TI1FP1)	
110: Filtered Timer Input 2 (TI2FP2)
111: External Trigger input (ETRF)		//外部输入
See Table 80: TIMx Internal trigger connection on page 315 for more details on ITRx meaning 
for each Timer.
Note: These bits must be changed only when they are not used (e.g. when SMS=000) to 
avoid wrong edge detections at the transition.
*/
void TIM1_set_TS(U8 ts);
void TIM8_set_TS(U8 ts);

#define TIM1_set_trigger_source_ITR0()		TIM1_set_TS(0)	//触发输入源为内部TIM5的TRGO
#define TIM1_set_trigger_source_ITR1()		TIM1_set_TS(1)	//触发输入源为内部TIM2的TRGO
#define TIM1_set_trigger_source_ITR2()		TIM1_set_TS(2)	//触发输入源为内部TIM3的TRGO
#define TIM1_set_trigger_source_ITR3()		TIM1_set_TS(3)	//触发输入源为内部TIM4的TRGO
#define TIM1_set_trigger_source_TI1()		TIM1_set_TS(4)	//触发输入源为通道1的上升沿或下降沿(不进行极性检测)
#define TIM1_set_trigger_source_TI1FP1()	TIM1_set_TS(5)	//触发输入源为输入通道1经过滤波极性检测后的信号
#define TIM1_set_trigger_source_TI1FP2()	TIM1_set_TS(6)	//触发输入源为输入通道2经过滤波极性检测后的信号
#define TIM1_set_trigger_source_ETRF()		TIM1_set_TS(7)	//触发输入源为外部输入经过滤波和分频和极性选择后的值


#define TIM8_set_trigger_source_ITR0()		TIM8_set_TS(0)	//触发输入源为内部TIM5的TRGO
#define TIM8_set_trigger_source_ITR1()		TIM8_set_TS(1)	//触发输入源为内部TIM2的TRGO
#define TIM8_set_trigger_source_ITR2()		TIM8_set_TS(2)	//触发输入源为内部TIM3的TRGO
#define TIM8_set_trigger_source_ITR3()		TIM8_set_TS(3)	//触发输入源为内部TIM4的TRGO
#define TIM8_set_trigger_source_TI1()		TIM8_set_TS(4)	//触发输入源为通道1的上升沿或下降沿(不进行极性检测)
#define TIM8_set_trigger_source_TI1FP1()	TIM8_set_TS(5)	//触发输入源为输入通道1经过滤波极性检测后的信号
#define TIM8_set_trigger_source_TI1FP2()	TIM8_set_TS(6)	//触发输入源为输入通道2经过滤波极性检测后的信号
#define TIM8_set_trigger_source_ETRF()		TIM8_set_TS(7)	//触发输入源为外部输入经过滤波和分频和极性选择后的值


/*
Bit 3 Reserved, always read as 0.
*/

/*从模式选择(主干)
	对从模式控制器的工作模式进行选择
		禁用
		编码器模式1
		编码器模式2
		编码器模式3
		复位模式
			在复位模式下，每一个TRGI的输入将导致:
				计数器和分频器的值被重新装载,
				一个更新事件的产生(如果URS位允许从模式控制产生更新事件的话)
		门控模式
			门控模式下，计数器何时计数由CEN位和TGRI共同决定,当CEN为1时，TRGI
			控制了计数器的计数。此时计数器的计数时钟由CNT_CLK提供。
		触发模式
			当TRGI进来一个高脉冲，计数器开始计数,并且CEN位被硬件置1。
		外部时钟模式1
			在该模式下，计数器的计数时钟由TRGI输入来驱动.
				
Bits 2:0 SMS: Slave mode selection
When external signals are selected the active edge of the trigger signal (TRGI) is linked to 
the polarity selected on the external input (see Input Control register and Control Register 
description.
000: Slave mode disabled - if CEN = ‘1’ then the prescaler is clocked directly by the internal 
clock.
001: Encoder mode 1 - Counter counts up/down on TI2FP2 edge depending on TI1FP1 
level.
010: Encoder mode 2 - Counter counts up/down on TI1FP1 edge depending on TI2FP2 
level.
011: Encoder mode 3 - Counter counts up/down on both TI1FP1 and TI2FP2 edges 
depending on the level of the other input.
100: Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes the counter 
and generates an update of the registers.
101: Gated Mode - The counter clock is enabled when the trigger input (TRGI) is high. The 
counter stops (but is not reset) as soon as the trigger becomes low. Both start and stop of 
the counter are controlled.
110: Trigger Mode - The counter starts at a rising edge of the trigger TRGI (but it is not 
reset). Only the start of the counter is controlled.
111: External Clock Mode 1 - Rising edges of the selected trigger (TRGI) clock the counter.
Note: The gated mode must not be used if TI1F_ED is selected as the trigger input 
(TS=’100’). Indeed, TI1F_ED outputs 1 pulse for each transition on TI1F, whereas the 
gated mode checks the level of the trigger signal.
*/
void TIM1_set_SMS(U8 sms);
void TIM8_set_SMS(U8 sms);

#define TIM1_disable_slave_mode()				TIM1_set_SMS(0)		//关闭从模式控制器，计数器的时钟由内部时钟提供
#define TIM1_set_slave_inside_clock()			TIM1_disable_slave_mode()
#define TIM1_set_slave_encoder_mode_1()			TIM1_set_SMS(1)		//从模式控制器配置为编码器模式1
#define TIM1_set_slave_encoder_mode_2()			TIM1_set_SMS(2)		//从模式控制器配置为编码器模式2
#define TIM1_set_slave_encoder_mode_3()			TIM1_set_SMS(3)		//从模式控制器配置为编码器模式3
#define TIM1_set_slave_reset_mode()				TIM1_set_SMS(4)		//从模式控制器配置为复位模式(每进来一个脉冲复位一次)
#define TIM1_set_slave_gated_mode()				TIM1_set_SMS(5)		//从模式控制器配置为门控模式(计数器只在门口信号有效时以内部时钟计数),注意:CNT_CEN一定要为1
#define TIM1_set_slave_trigger_mode()			TIM1_set_SMS(6)		//从模式控制器配置为触发模式(计数器的开始时由外部EXR启动的)，注意:CNT_CEN不需要为1
#define TIM1_set_slave_external_clock_mode_1() 	TIM1_set_SMS(7)		////从模式控制器配置为外部时钟模式1

#define TIM8_disable_slave_mode()				TIM8_set_SMS(0)		//关闭从模式控制器，计数器的时钟由内部时钟提供
#define TIM8_set_slave_encoder_mode_1()			TIM8_set_SMS(1)		//从模式控制器配置为编码器模式1
#define TIM8_set_slave_encoder_mode_2()			TIM8_set_SMS(2)		//从模式控制器配置为编码器模式2
#define TIM8_set_slave_encoder_mode_3()			TIM8_set_SMS(3)		//从模式控制器配置为编码器模式3
#define TIM8_set_slave_reset_mode()				TIM8_set_SMS(4)		//从模式控制器配置为复位模式(每进来一个脉冲复位一次)
#define TIM8_set_slave_gated_mode()				TIM8_set_SMS(5)		//从模式控制器配置为门控模式(计数器只在门口信号有效时以内部时钟计数),注意:CNT_CEN一定要为1
#define TIM8_set_slave_trigger_mode()			TIM8_set_SMS(6)		//从模式控制器配置为触发模式(计数器的开始时由外部EXR启动的)，注意:CNT_CEN不需要为1
#define TIM8_set_slave_external_clock_mode_1() 	TIM8_set_SMS(7)		////从模式控制器配置为外部时钟模式1



//*******************************************************//
//**TIM1&TIM8 DMA/interrupt enable register (TIMx_DIER)**//
//*******************************************************//
/*TIM1&TIM8 DMA/中断使能寄存器
TIM1&TIM8 DMA/interrupt enable register (TIMx_DIER)
Address offset: 0x0C
Reset value: 0x0000
*/
/*
Bit 15 Reserved, always read as 0.
*/

/*触发DMA请求使能
	当TRGI进来一个有效脉冲时产生DMA请求
	当从模式控制器被配置成门控模式时，时钟的任意边沿都会产生一个DMA请求
	此位只会在从模式未被禁用时起作用
Bit 14 TDE: Trigger DMA request enable
0: Trigger DMA request disabled
1: Trigger DMA request enabled
*/
void TIM1_set_TDE(U8 tde);
void TIM8_set_TDE(U8 tde);

#define TIM1_enable_DMA_request_at_trigger()	TIM1_set_TDE(1)		//当TRGI进来一个脉冲时,产生一个DMA请求
#define TIM1_disable_DMA_request_at_trigger()	TIM1_set_TDE(0)		//TRGI进来一个有效脉冲时,DMA请求不会发出

#define TIM8_enable_DMA_request_at_trigger()	TIM8_set_TDE(1)		//当TRGI进来一个脉冲时,产生一个DMA请求
#define TIM8_disable_DMA_request_at_trigger()	TIM8_set_TDE(0)		//TRGI进来一个有效脉冲时,DMA请求不会发出


/*Bit 13 COMDE: COM DMA request enable
0: COM DMA request disabled
1: COM DMA request enabled
*/
//to do

/*捕获比较通道4DMA请求使能
	在通道4发生捕获或者比较事件时，发送一个DMA请求
Bit 12 CC4DE: Capture/Compare 4 DMA request enable
0: CC4 DMA request disabled
1: CC4 DMA request enabled
*/
void TIM1_set_CC4DE(U8 cc4de);
void TIM8_set_CC4DE(U8 cc4de);


#define TIM1_enable_DMA_request_at_CC4_event()	TIM1_set_CC4DE(1)	//通道4在发生比较/捕获事件时产生DMA请求
#define TIM1_disable_DMA_request_at_CC4_event()	TIM1_set_CC4DE(0)	//通道4在发生比较/捕获事件时不产生DMA请求

#define TIM8_enable_DMA_request_at_CC4_event()	TIM8_set_CC4DE(1)	//通道4在发生比较/捕获事件时产生DMA请求
#define TIM8_disable_DMA_request_at_CC4_event()	TIM8_set_CC4DE(0)	//通道4在发生比较/捕获事件时不产生DMA请求


/*捕获比较通道3DMA请求使能
Bit 11 CC3DE: Capture/Compare 3 DMA request enable
0: CC3 DMA request disabled
1: CC3 DMA request enabled
*/
void TIM1_set_CC3DE(U8 cc3de);
void TIM8_set_CC3DE(U8 cc3de);

#define TIM1_enable_DMA_request_at_CC3_event()	TIM1_set_CC3DE(1)	//通道3在发生比较/捕获事件时产生DMA请求
#define TIM1_disable_DMA_request_at_CC3_event()	TIM1_set_CC3DE(0)	//通道3在发生比较/捕获事件时不产生DMA请求

#define TIM8_enable_DMA_request_at_CC3_event()	TIM8_set_CC3DE(1)	//通道3在发生比较/捕获事件时产生DMA请求
#define TIM8_disable_DMA_request_at_CC3_event()	TIM8_set_CC3DE(0)	//通道3在发生比较/捕获事件时不产生DMA请求


/*捕获比较通道2DMA请求使能 
Bit 10 CC2DE: Capture/Compare 2 DMA request enable
0: CC2 DMA request disabled
1: CC2 DMA request enabled
*/
void TIM1_set_CC2DE(U8 cc2de);
void TIM8_set_CC2DE(U8 cc2de);

#define TIM1_enable_DMA_request_at_CC2_event()	TIM1_set_CC2DE(1)	//通道2在发生比较/捕获事件时产生DMA请求
#define TIM1_disable_DMA_request_at_CC2_event()	TIM1_set_CC2DE(0)	//通道2在发生比较/捕获事件时不产生DMA请求

#define TIM8_enable_DMA_request_at_CC2_event()	TIM8_set_CC2DE(1)	//通道2在发生比较/捕获事件时产生DMA请求
#define TIM8_disable_DMA_request_at_CC2_event()	TIM8_set_CC2DE(0)	//通道2在发生比较/捕获事件时不产生DMA请求


/*捕获比较通道1DMA请求使能
Bit 9 CC1DE: Capture/Compare 1 DMA request enable
0: CC1 DMA request disabled
1: CC1 DMA request enabled
*/
void TIM1_set_CC1DE(U8 cc1de);
void TIM8_set_CC1DE(U8 cc1de);

#define TIM1_enable_DMA_request_at_CC1_event()	TIM1_set_CC1DE(1)	//通道1在发生比较/捕获事件时产生DMA请求
#define TIM1_disable_DMA_request_at_CC1_event()	TIM1_set_CC1DE(0)	//通道1在发生比较/捕获事件时不产生DMA请求

#define TIM8_enable_DMA_request_at_CC1_event()	TIM8_set_CC1DE(1)	//通道1在发生比较/捕获事件时产生DMA请求
#define TIM8_disable_DMA_request_at_CC1_event()	TIM8_set_CC1DE(0)	//通道1在发生比较/捕获事件时不产生DMA请求


/*更新事件DMA请求使能
	当发生更新事件时产生DMA请求
Bit 8 UDE: Update DMA request enable
0: Update DMA request disabled
1: Update DMA request enabled
*/
void TIM1_set_UDE(U8 ude);
void TIM8_set_UDE(U8 ude);

#define TIM1_enable_DMA_request_at_update_event()	TIM1_set_UDE(1)		//TIM1在发生更新事件时产生DMA请求
#define TIM1_disable_DMA_request_at_update_event()	TIM1_set_UDE(0)		//TIM1生更新事件时不产生DMA请求

#define TIM8_enable_DMA_request_at_update_event()	TIM8_set_UDE(1)		//TIM8在发生更新事件时产生DMA请求
#define TIM8_disable_DMA_request_at_update_event()	TIM8_set_UDE(0)		//TIM8在发生更新事件时不产生DMA请求

/*
Bit 7 BIE: Break interrupt enable
0: Break interrupt disabled
1: Break interrupt enabled
*/
//to do

/*触发中断使能
	当进来一个有效触发产生一个中断
	此位只在从模式模式没有被禁用时起作用
Bit 6 TIE: Trigger interrupt enable
0: Trigger interrupt disabled
1: Trigger interrupt enabled
*/
void TIM1_set_TIE(U8 tie);
void TIM8_set_TIE(U8 tie);

#define TIM1_enable_interrupt_at_trigger()		TIM1_set_TIE(1)		//进来一个有效TRGI，产生一次中断
#define TIM1_disable_interrupt_at_trigger()		TIM1_set_TIE(0)		//进来一个有效TRGI，不产生中断

#define TIM8_enable_interrupt_at_trigger()		TIM8_set_TIE(1)		//进来一个有效TRGI，产生一次中断
#define TIM8_disable_interrupt_at_trigger()		TIM8_set_TIE(0)		//进来一个有效TRGI，不产生中断

/*
Bit 5 COMIE: COM interrupt enable
0: COM interrupt disabled
1: COM interrupt enabled
*/
//to do

/*捕获比较通道4中断使能
	当发生捕获或者比较事件时，产生中断
Bit 4 CC4IE: Capture/Compare 4 interrupt enable
0: CC4 interrupt disabled
1: CC4 interrupt enabled
*/
void TIM1_set_CC4IE(U8 cc4ie);
void TIM8_set_CC4IE(U8 cc4ie);

#define TIM1_enable_interrupt_at_CC4_event()	TIM1_set_CC4IE(1)	//比较捕获通道4发生捕获/比较事件时发生中断	
#define TIM1_disable_interrupt_at_CC4_event()	TIM1_set_CC4IE(0)	//比较捕获通道4发生捕获/比较事件时不发生中断

#define TIM8_enable_interrupt_at_CC4_event()	TIM8_set_CC4IE(1)	//比较捕获通道4发生捕获/比较事件时发生中断	
#define TIM8_disable_interrupt_at_CC4_event()	TIM8_set_CC4IE(0)	//比较捕获通道4发生捕获/比较事件时不发生中断

/*捕获比较通道3中断使能
Bit 3 CC3IE: Capture/Compare 3 interrupt enable
0: CC3 interrupt disabled
1: CC3 interrupt enabled
*/
void TIM1_set_CC3IE(U8 cc3ie);
void TIM8_set_CC3IE(U8 cc3ie);

#define TIM1_enable_interrupt_at_CC3_event()	TIM1_set_CC3IE(1)	//比较捕获通道3发生捕获/比较事件时发生中断	
#define TIM1_disable_interrupt_at_CC3_event()	TIM1_set_CC3IE(0)	//比较捕获通道3发生捕获/比较事件时不发生中断

#define TIM8_enable_interrupt_at_CC3_event()	TIM8_set_CC3IE(1)	//比较捕获通道3发生捕获/比较事件时发生中断	
#define TIM8_disable_interrupt_at_CC3_event()	TIM8_set_CC3IE(0)	//比较捕获通道3发生捕获/比较事件时不发生中断


/*捕获比较通道2中断使能
	当发生捕获或者比较事件时，产生中断
Bit 2 CC2IE: Capture/Compare 2 interrupt enable
0: CC2 interrupt disabled
1: CC2 interrupt enabled
*/
void TIM1_set_CC2IE(U8 cc2ie);
void TIM8_set_CC2IE(U8 cc2ie);

#define TIM1_enable_interrupt_at_CC2_event()	TIM1_set_CC2IE(1)	//比较捕获通道2发生捕获/比较事件时发生中断	
#define TIM1_disable_interrupt_at_CC2_event()	TIM1_set_CC2IE(0)	//比较捕获通道2发生捕获/比较事件时不发生中断

#define TIM8_enable_interrupt_at_CC2_event()	TIM8_set_CC2IE(1)	//比较捕获通道2发生捕获/比较事件时发生中断	
#define TIM8_disable_interrupt_at_CC2_event()	TIM8_set_CC2IE(0)	//比较捕获通道2发生捕获/比较事件时不发生中断


/*捕获比较通道1中断使能
	当发生捕获或者比较事件时，产生中断
Bit 1 CC1IE: Capture/Compare 1 interrupt enable
0: CC1 interrupt disabled
1: CC1 interrupt enabled
*/
void TIM1_set_CC1IE(U8 cc1ie);
void TIM8_set_CC1IE(U8 cc1ie);

#define TIM1_enable_interrupt_at_CC1_event()	TIM1_set_CC1IE(1)	//比较捕获通道1发生捕获/比较事件时发生中断	
#define TIM1_disable_interrupt_at_CC1_event()	TIM1_set_CC1IE(0)	//比较捕获通道1发生捕获/比较事件时不发生中断

#define TIM8_enable_interrupt_at_CC1_event()	TIM8_set_CC1IE(1)	//比较捕获通道1发生捕获/比较事件时发生中断	
#define TIM8_disable_interrupt_at_CC1_event()	TIM8_set_CC1IE(0)	//比较捕获通道1发生捕获/比较事件时不发生中断


/*更新事件中断使能
	当发生更新事件时产生中断
Bit 0 UIE: Update interrupt enable
0: Update interrupt disabled
1: Update interrupt enabled
*/
void TIM1_set_UIE(U8 uie);
void TIM8_set_UIE(U8 uie);

#define TIM1_enable_interrupt_at_update_event()		TIM1_set_UIE(1)		//TIM1在发生更新事件时产生中断请求
#define TIM1_disable_interrupt_at_update_event()	TIM1_set_UIE(0)		//TIM1生更新事件时不产生中断请求

#define TIM8_enable_interrupt_at_update_event()		TIM8_set_UIE(1)		//TIM8在发生更新事件时产生中断请求
#define TIM8_disable_interrupt_at_update_event()	TIM8_set_UIE(0)		//TIM8在发生更新事件时不产生中断请求


//**************************************************************//
//************TIM1&TIM8 status register (TIMx_SR)***************//
//**************************************************************//
/*TIM1&TIM8状态寄存器
TIM1&TIM8 status register (TIMx_SR)
Address offset: 0x10
Reset value: 0x0000
*/
/*
Bits 15:13 Reserved, always read as 0.
*/

/*捕获比较通道4重复捕获标志
	当发生捕获事件时，前一次的捕获事件标志(CCxIF = 1)没有清除
	则重复捕获标志被设置
	比较模式下该位无用
Bit 12 CC4OF: Capture/Compare 4 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC4OF(void);
void TIM1_clear_CC4OF(void);

U8 TIM8_get_CC4OF(void);
void TIM8_clear_CC4OF(void);

#define	TIM1_get_channel4_overcapture_flag()		TIM1_get_CC4OF()		//获取通道4的重捕获标志
#define TIM1_clear_channel4_overcapture_flag()		TIM1_clear_CC4OF()		//清除通道4的重捕获标志

#define	TIM8_get_channel4_overcapture_flag()		TIM8_get_CC4OF()		//获取通道4的重捕获标志
#define TIM8_clear_channel4_overcapture_flag()		TIM8_clear_CC4OF()		//清除通道4的重捕获标志

/*捕获比较通道3重复捕获标志
	当发生捕获事件时，前一次的捕获事件标志(CCxIF = 1)没有清除
	则重复捕获标志被设置
Bit 11 CC3OF: Capture/Compare 3 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC3OF(void);
void TIM1_clear_CC3OF(void);

U8 TIM8_get_CC3OF(void);
void TIM8_clear_CC3OF(void);


#define	TIM1_get_channel3_overcapture_flag()		TIM1_get_CC3OF()		//获取通道3的重捕获标志
#define TIM1_clear_channel3_overcapture_flag()		TIM1_clear_CC3OF()		//清除通道3的重捕获标志

#define	TIM8_get_channel3_overcapture_flag()		TIM8_get_CC3OF()		//获取通道3的重捕获标志
#define TIM8_clear_channel3_overcapture_flag()		TIM8_clear_CC3OF()		//清除通道3的重捕获标志


/*捕获比较通道2重复捕获标志
	当发生捕获事件时，前一次的捕获事件标志(CCxIF = 1)没有清除
	则重复捕获标志被设置
Bit 10 CC2OF: Capture/Compare 2 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC2OF(void);
void TIM1_clear_CC2OF(void);

U8 TIM8_get_CC2OF(void);
void TIM8_clear_CC2OF(void);

#define	TIM1_get_channel2_overcapture_flag()		TIM1_get_CC2OF()		//获取通道2的重捕获标志
#define TIM1_clear_channel2_overcapture_flag()		TIM1_clear_CC2OF()		//清除通道2的重捕获标志

#define	TIM8_get_channel2_overcapture_flag()		TIM8_get_CC2OF()		//获取通道2的重捕获标志
#define TIM8_clear_channel2_overcapture_flag()		TIM8_clear_CC2OF()		//清除通道2的重捕获标志

/*捕获比较1重复捕获标志
	当发生捕获事件时，前一次的捕获事件标志(CCxIF = 1)没有清除
	则重复捕获标志被设置
Bit 9 CC1OF: Capture/Compare 1 overcapture flag
This flag is set by hardware only when the corresponding channel is configured in input 
capture mode. It is cleared by software by writing it to ‘0’.
0: No overcapture has been detected.
1: The counter value has been captured in TIMx_CCR1 register while CC1IF flag was 
already set
*/
U8 TIM1_get_CC1OF(void);
void TIM1_clear_CC1OF(void);

U8 TIM8_get_CC1OF(void);
void TIM8_clear_CC1OF(void);

#define	TIM1_get_channel1_overcapture_flag()		TIM1_get_CC1OF()		//获取通道1的重捕获标志
#define TIM1_clear_channel1_overcapture_flag()		TIM1_clear_CC1OF()		//清除通道1的重捕获标志

#define	TIM8_get_channel1_overcapture_flag()		TIM8_get_CC1OF()		//获取通道1的重捕获标志
#define TIM8_clear_channel1_overcapture_flag()		TIM8_clear_CC1OF()		//清除通道1的重捕获标志


/*
Bit 8 Reserved, always read as 0.
*/

/*
Bit 7 BIF: Break interrupt flag
This flag is set by hardware as soon as the break input goes active. It can be cleared by 
software if the break input is not active.
0: No break event occurred.
1: An active level has been detected on the break input.
*/
//to do

/*触发中断标志
	当发生触发事件时，该位被设置
	Slave配置成非门控模式时，TRGI的有效沿设置该位。
	在门控模式下，上下沿都设置该位
Bit 6 TIF: Trigger interrupt flag
This flag is set by hardware on trigger event (active edge detected on TRGI input when the 
slave mode controller is enabled in all modes but gated mode, both edges in case gated 
mode is selected). It is cleared by software.
0: No trigger event occurred.
1: Trigger interrupt pending.
*/
U8 TIM1_get_TIF(void);
void TIM1_clear_TIF(void);

U8 TIM8_get_TIF(void);
void TIM8_clear_TIF(void);

#define TIM1_get_trigger_interrupt_flag()	TIM1_get_TIF()		//获取TRGI中断标志 
#define TIM1_clear_trigger_interrupt_flag()	TIM1_clear_TIF()	//清除TRGI中断标志
	
#define TIM1_is_interrupted_by_trigger()	TIM1_get_trigger_interrupt_flag()	//是TRGI产生的中断吗


#define TIM8_get_trigger_interrupt_flag()	TIM8_get_TIF()		//获取TRGI中断标志 
#define TIM8_clear_trigger_interrupt_flag()	TIM8_clear_TIF()	//清除TRGI中断标志
	
#define TIM8_is_interrupted_by_trigger()	TIM8_get_trigger_interrupt_flag()	//是TRGI产生的中断吗


/*
Bit 5 COMIF: COM interrupt flag
This flag is set by hardware on COM event (when Capture/compare Control bits - CCxE, 
CCxNE, OCxM - have been updated). It is cleared by software.
0: No COM event occurred.
1: COM interrupt pending.
*/
//to do 

/*捕获比较通道4中断标志
	比较模式:
		 当TIMx_CNT的值与CCRx的值相等时产生中断（计数器为边沿对其模式计数）
		 当计数器以中心对其模式计数时，产生中断根据CMS的设置在:
				向上计数时
				向下计数时
				向上和向下计数时
	捕获模式中断:
		当ICx为有效脉冲时产生一次捕获，此时CCRx的值为TIMx_CNT的值，同时产生中断
捕获比较通道4中断标志
	当发生捕获或者比较事件时，该位被标志
Bit 4 CC4IF: Capture/Compare 4 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC4F(void);
void TIM1_clear_CC4F(void);

U8 TIM8_get_CC4F(void);
void TIM8_clear_CC4F(void);

#define TIM1_get_CC4_interrupt_flag()		TIM1_get_CC4F()					//获取通道4捕获/比较事件中断标志
#define TIM1_clear_CC4_interrupt_flag()		TIM1_clear_CC4F()				//清除通道4捕获/比较事件中断标志
#define TIm1_is_interrupted_by_CC4_event()	TIM1_get_CC4_interrupt_flag()	//中断是由通道4的捕获比较事件产生的吗


#define TIM8_get_CC4_interrupt_flag()		TIM8_get_CC4F()					//获取通道4捕获/比较事件中断标志
#define TIM8_clear_CC4_interrupt_flag()		TIM8_clear_CC4F()				//清除通道4捕获/比较事件中断标志
#define TIM8_is_interrupted_by_CC4_event()	TIM8_get_CC4_interrupt_flag()	//中断是由通道4的捕获比较事件产生的吗


/*捕获比较通道3中断标志
	比较模式:
		 当TIMx_CNT的值与CCRx的值相等时产生中断（计数器为边沿对其模式计数）
		 当计数器以中心对其模式计数时，产生中断根据CMS的设置在:
				向上计数时
				向下计数时
				向上和向下计数时
	捕获模式中断:
		当ICx为有效脉冲时产生一次捕获，此时CCRx的值为TIMx_CNT的值，同时产生中断
Bit 3 CC3IF: Capture/Compare 3 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC3F(void);
void TIM1_clear_CC3F(void);

U8 TIM8_get_CC3F(void);
void TIM8_clear_CC3F(void);

#define TIM1_get_CC3_interrupt_flag()		TIM1_get_CC3F()					//获取通道3捕获/比较事件中断标志
#define TIM1_clear_CC3_interrupt_flag()		TIM1_clear_CC3F()				//清除通道3捕获/比较事件中断标志
#define TIm1_is_interrupted_by_CC3_event()	TIM1_get_CC3_interrupt_flag()	//中断是由通道3的捕获比较事件产生的吗


#define TIM8_get_CC3_interrupt_flag()		TIM8_get_CC3F()					//获取通道3捕获/比较事件中断标志
#define TIM8_clear_CC3_interrupt_flag()		TIM8_clear_CC3F()				//清除通道3捕获/比较事件中断标志
#define TIM8_is_interrupted_by_CC3_event()	TIM8_get_CC3_interrupt_flag()	//中断是由通道3的捕获比较事件产生的吗


/*捕获比较通道2中断标志
	比较模式:
		 当TIMx_CNT的值与CCRx的值相等时产生中断（计数器为边沿对其模式计数）
		 当计数器以中心对其模式计数时，产生中断根据CMS的设置在:
				向上计数时
				向下计数时
				向上和向下计数时
	捕获模式中断:
		当ICx为有效脉冲时产生一次捕获，此时CCRx的值为TIMx_CNT的值，同时产生中断
Bit 2 CC2IF: Capture/Compare 2 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC2F(void);
void TIM1_clear_CC2F(void);

U8 TIM8_get_CC2F(void);
void TIM8_clear_CC2F(void);

#define TIM1_get_CC2_interrupt_flag()		TIM1_get_CC2F()					//获取通道2捕获/比较事件中断标志
#define TIM1_clear_CC2_interrupt_flag()		TIM1_clear_CC2F()				//清除通道2捕获/比较事件中断标志
#define TIm1_is_interrupted_by_CC2_event()	TIM1_get_CC2_interrupt_flag()	//中断是由通道2的捕获比较事件产生的吗

#define TIM8_get_CC2_interrupt_flag()		TIM8_get_CC2F()					//获取通道2捕获/比较事件中断标志
#define TIM8_clear_CC2_interrupt_flag()		TIM8_clear_CC2F()				//清除通道2捕获/比较事件中断标志
#define TIM8_is_interrupted_by_CC2_event()	TIM8_get_CC2_interrupt_flag()	//中断是由通道2的捕获比较事件产生的吗

/*捕获比较通道1中断标志
	比较模式:
		 当TIMx_CNT的值与CCRx的值相等时产生中断（计数器为边沿对其模式计数）
		 当计数器以中心对其模式计数时，产生中断根据CMS的设置在:
				向上计数时
				向下计数时
				向上和向下计数时
	捕获模式中断:
		当ICx为有效脉冲时产生一次捕获，此时CCRx的值为TIMx_CNT的值，同时产生中断
Bit 1 CC1IF: Capture/Compare 1 interrupt flag
If channel CC1 is configured as output:
This flag is set by hardware when the counter matches the compare value, with some 
exception in center-aligned mode (refer to the CMS bits in the TIMx_CR1 register 
description). It is cleared by software.
0: No match.
1: The content of the counter TIMx_CNT matches the content of the TIMx_CCR1 register. 
When the contents of TIMx_CCR1 are greater than the contents of TIMx_ARR, the CC1IF 
bit goes high on the counter overflow (in upcounting and up/down-counting modes) or 
underflow (in downcounting mode)
If channel CC1 is configured as input:
This bit is set by hardware on a capture. It is cleared by software or by reading the 
TIMx_CCR1 register.
0: No input capture occurred
1: The counter value has been captured in TIMx_CCR1 register (An edge has been 
detected on IC1 which matches the selected polarity)
*/
U8 TIM1_get_CC1F(void);
void TIM1_clear_CC1F(void);

U8 TIM8_get_CC1F(void);
void TIM8_clear_CC1F(void);

#define TIM1_get_CC1_interrupt_flag()		TIM1_get_CC1F()					//获取通道1捕获/比较事件中断标志
#define TIM1_clear_CC1_interrupt_flag()		TIM1_clear_CC1F()				//清除通道1捕获/比较事件中断标志
#define TIm1_is_interrupted_by_CC1_event()	TIM1_get_CC1_interrupt_flag()	//中断是由通道1的捕获比较事件产生的吗

#define TIM8_get_CC1_interrupt_flag()		TIM8_get_CC1F()					//获取通道1捕获/比较事件中断标志
#define TIM8_clear_CC1_interrupt_flag()		TIM8_clear_CC1F()				//清除通道1捕获/比较事件中断标志
#define TIM8_is_interrupted_by_CC1_event()	TIM8_get_CC1_interrupt_flag()	//中断是由通道1的捕获比较事件产生的吗


/*更新事件中断标志
	当发生更新事件时，该位被置位。可能在:
		在上下溢出时
		在设置UG位时
		在从模式控制器进来一个TRGI时
	产生更新事件
Bit 0 UIF: Update interrupt flag
This bit is set by hardware on an update event. It is cleared by software.
0: No update occurred.
1: Update interrupt pending. 
This bit is set by hardware when the registers are updated:
–At overflow or underflow regarding the repetition counter value (update if repetition 
counter = 0) and if the UDIS=0 in the TIMx_CR1 register.
–When CNT is reinitialized by software using the UG bit in TIMx_EGR register, if URS=0 
and UDIS=0 in the TIMx_CR1 register.
–When CNT is reinitialized by a trigger event (refer to Section 13.4.3: TIM1&TIM8 slave 
mode control register (TIMx_SMCR)), if URS=0 and UDIS=0 in the TIMx_CR1 register.
*/
U8 TIM1_get_UIF(void);
void TIM1_clear_UIF(void);

U8 TIM8_get_UIF(void);
void TIM8_clear_UIF(void);

#define TIM1_get_update_event_flag()	TIM1_get_UIF()		//获取更新事件中断标志 
#define TIM1_clear_update_event_flag()	TIM1_clear_UIF()	//清除更新事件中断标志
#define TIM1_is_interrupted_by_update_event()	TIM1_get_update_event_flag()	//是更新事件导致的中断吗

#define TIM8_get_update_event_flag()	TIM8_get_UIF()		//获取更新事件中断标志 
#define TIM8_clear_update_event_flag()	TIM8_clear_UIF()	//清除更新事件中断标志
#define TIM8_is_interrupted_by_update_event()	TIM8_get_update_event_flag()	//是更新事件导致的中断吗

//***************************************************************//
//*******TIM1&TIM8 event generation register (TIMx_EGR)**********//
//***************************************************************//

/*TIM1&TIM8事件生成寄存器
TIM1&TIM8 event generation register (TIMx_EGR)
Address offset: 0x14
Reset value: 0x0000
*/


/*
Bits 15:8 Reserved, always read as 0.
*/

/*
Bit 7 BG: Break generation
This bit is set by software in order to generate an event, it is automatically cleared by 
hardware.
0: No action
1: A break event is generated. MOE bit is cleared and BIF flag is set. Related interrupt or 
DMA transfer can occur if enabled.
*/
//to do

/*触发事件生成
	设置该位可以产生一个触发事件，效果和TRGI有效一样,只是并不是真正的TRGI输入
		效果根据从模式的模式选择有不同的作用
	设置之后由硬件清零
Bit 6 TG: Trigger generation
This bit is set by software in order to generate an event, it is automatically cleared by 
hardware.
0: No action
1: The TIF flag is set in TIMx_SR register. Related interrupt or DMA transfer can occur if 
enabled.
*/
void TIM1_set_TG(void);
void TIM8_set_TG(void);

//这里并不是真正产生一个TRGI有效输入，只是设置了TIMx_SR寄存器里的TIF标志, 以产生中断，或DMA请求
#define TIM1_generate_trigger_event()	TIM1_set_TG()	//产生一个TRGI事件

//这里并不是真正产生一个TRGI有效输入，只是设置了TIMx_SR寄存器里的TIF标志, 以产生中断，或DMA请求
#define TIM8_generate_trigger_event()	TIM8_set_TG()	//产生一个TRGI事件


/*
Bit 5 COMG: Capture/Compare control update generation
This bit can be set by software, it is automatically cleared by hardware
0: No action
1: When CCPC bit is set, it allows to update CCxE, CCxNE and OCxM bits
Note: This bit acts only on channels having a complementary output.
*/
//to do

/*CHANNEL4产生捕获/比较事件
	详见CC1G位描述
Bit 4 CC4G: Capture/Compare 4 generation
refer to CC1G description
*/
void TIM1_set_CC4G(void);
void TIM8_set_CC4G(void);

#define TIM1_generate_CC4_event()	TIM1_set_CC4G()	//通道4产生捕获/比较事件

#define TIM8_generate_CC4_event()	TIM8_set_CC4G()	//通道4产生捕获/比较事件

/*CHANNEL3产生捕获/比较事件
	详见CC1G位描述
Bit 3 CC3G: Capture/Compare 3 generation
refer to CC1G description
*/
void TIM1_set_CC3G(void);
void TIM8_set_CC3G(void);

#define TIM1_generate_CC3_event()	TIM1_set_CC3G()	//通道3产生捕获/比较事件

#define TIM8_generate_CC3_event()	TIM8_set_CC3G()	//通道3产生捕获/比较事件


/*CHANNEL2产生捕获/比较事件
	详见CC1G位描述
Bit 2 CC2G: Capture/Compare 2 generation
refer to CC1G description
*/
void TIM1_set_CC2G(void);
void TIM8_set_CC2G(void);

#define TIM1_generate_CC2_event()	TIM1_set_CC2G()	//通道2产生捕获/比较事件

#define TIM8_generate_CC2_event()	TIM8_set_CC2G()	//通道2产生捕获/比较事件

/*CHANNEL1产生捕获/比较事件
	设置该位会产生一个捕获/比较事件
	捕获事件:
		当Channelx被配置成输入时，产生捕获事件 捕获事件将导致计数器的值被捕捉到CCRx中
		如果使能了中断或DMA请求，则会产生响应的请求
	比较事件:
		当Channelx被配置成输出时，产生比较事件
		如果使能了中断或DMA请求，则会产生响应的请求
		输出的信号根据输出模式的不同而有不同的效果
	如果在设置该位时，该位已经为1，则CC1OF被设置
Bit 1 CC1G: Capture/Compare 1 generation
This bit is set by software in order to generate an event, it is automatically cleared by 
hardware.
0: No action
1: A capture/compare event is generated on channel 1:
If channel CC1 is configured as output:
CC1IF flag is set, Corresponding interrupt or DMA request is sent if enabled.
If channel CC1 is configured as input:
The current value of the counter is captured in TIMx_CCR1 register. The CC1IF flag is set, 
the corresponding interrupt or DMA request is sent if enabled. The CC1OF flag is set if the 
CC1IF flag was already high.
*/
void TIM1_set_CC1G(void);
void TIM8_set_CC1G(void);

#define TIM1_generate_CC1_event()	TIM1_set_CC1G()	//通道1产生捕获/比较事件
#define TIM8_generate_CC1_event()	TIM8_set_CC1G()	//通道1产生捕获/比较事件


/*更新事件产生
	设置该位后:
		计数器的值被清零(如果是中心对其模式，装载的值跟当前的计数方向有关)
		各个影子寄存器被装装入对应的预装载寄存器的值
		预分频器的值也被清零，但分频率不变
Bit 0 UG: Update generation
This bit can be set by software, it is automatically cleared by hardware.
0: No action
1: Reinitialize the counter and generates an update of the registers. Note that the prescaler 
counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if 
the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload 
value (TIMx_ARR) if DIR=1 (downcounting).
*/
void TIM1_set_UG(void);
void TIM8_set_UG(void);

#define TIM1_generate_update_event()	TIM1_set_UG()	//TIM1产生一个更新事件
#define TIM8_generate_update_event()	TIM8_set_UG()	//TIM8产生一个更新事件


//*********************************************************************//
//********TIM1&TIM8 capture/compare mode register 1 (TIMx_CCMR1)*******//
//********TIM1&TIM8 capture/compare mode register 2 (TIMx_CCMR2)*******//
//*********************************************************************//

/*捕获/比较模式寄存器1,2
TIM1&TIM8 capture/compare mode register 1 (TIMx_CCMR1)
Address offset: 0x18
Reset value: 0x0000
The channels can be used in input (capture mode) or in output (compare mode). The 
direction of a channel is defined by configuring the corresponding CCxS bits. All the other 
bits of this register have a different function in input and in output mode. For a given bit, 
OCxx describes its function when the channel is configured in output, ICxx describes its 
function when the channel is configured in input. So you must take care that the same bit 
can have a different meaning for the input stage and for the output stage.
翻译: 通道可以被配置成输入(捕获模式)和输出(比较模式).通道的方向通过对应的CCxS位来配置.所有其他
的位根据通道的方向的不同有不同的功能.对于一个给定的位，OCxx描述了当通道被配置成输出模式时的功能，
ICxx描述了当通道被配置成输入模式时的功能.所以你必须小心这相同的位在配置成输入和输出时有不同的同能。
*/



//**********************捕获/比较功能选择*******************************//

//************TIMx_CCMR1****************//
/*捕获/比较通道2功能选择
	可选择为输入捕获模式
		通道的真实输入可以有多个映射
	可选择为输出比较模式
Bits 9:8 CC2S[1:0]: Capture/Compare 2 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC2 channel is configured as output
01: CC2 channel is configured as input, IC2 is mapped on TI2
10: CC2 channel is configured as input, IC2 is mapped on TI1
11: CC2 channel is configured as input, IC2 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through the TS bit (TIMx_SMCR register)
Note: CC2S bits are writable only when the channel is OFF (CC2E = ‘0’ in TIMx_CCER).
*/
void TIM1_set_CC2S(U8 cc2s);
void TIM8_set_CC2S(U8 cc2s);

#define TIM1_set_channel2_output()			TIM1_set_CC2S(0)		//通道2配置为比较输出
#define TIM1_set_channel2_input()			TIM1_set_CC2S(1)		//通道2配置为输入捕获,IC2映射到TI2
#define TIM1_set_channel2_input_map_TI2()	TIM1_set_channel2_input()	//同上
#define TIM1_set_channel2_input_map_TI1()	TIM1_set_CC2S(2)		//通道2配置为输入捕获,IC2映射到TI1
#define TIM1_set_channel2_input_map_TRC()	TIM1_set_CC2S(3)		//通道2配置为输入捕获,IC2映射到TRC

#define TIM8_set_channel2_output()			TIM8_set_CC2S(0)		//通道2配置为比较输出
#define TIM8_set_channel2_input()			TIM8_set_CC2S(1)		//通道2配置为输入捕获,IC2映射到TI2
#define TIM8_set_channel2_input_map_TI2()	TIM8_set_channel2_input()	//同上
#define TIM8_set_channel2_input_map_TI1()	TIM8_set_CC2S(2)		//通道2配置为输入捕获,IC2映射到TI1
#define TIM8_set_channel2_input_map_TRC()	TIM8_set_CC2S(3)		//通道2配置为输入捕获,IC2映射到TRC

/*捕获/比较通道1功能选择
	可选择为输入捕获模式
		通道的真实输入可以有多个映射
	可选择为输出比较模式
Bits 1:0 CC1S: Capture/Compare 1 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC1 channel is configured as output
01: CC1 channel is configured as input, IC1 is mapped on TI1
10: CC1 channel is configured as input, IC1 is mapped on TI2
11: CC1 channel is configured as input, IC1 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC1S bits are writable only when the channel is OFF (CC1E = ‘0’ in TIMx_CCER).
*/
void TIM1_set_CC1S(U8 cc1s);
void TIM8_set_CC1S(U8 cc1s);

#define TIM1_set_channel1_output()			TIM1_set_CC1S(0)		//通道1配置为比较输出
#define TIM1_set_channel1_input()			TIM1_set_CC1S(1)		//通道1配置为输入捕获,IC1映射到TI1
#define TIM1_set_channel1_input_map_TI1()	TIM1_set_channel1_input()	//同上
#define TIM1_set_channel1_input_map_TI2()	TIM1_set_CC1S(2)		//通道1配置为输入捕获,IC1映射到TI2
#define TIM1_set_channel1_input_map_TRC()	TIM1_set_CC1S(3)		//通道1配置为输入捕获,IC1映射到TRC

#define TIM8_set_channel1_output()			TIM8_set_CC1S(0)		//通道1配置为比较输出
#define TIM8_set_channel1_input()			TIM8_set_CC1S(1)		//通道1配置为输入捕获,IC1映射到TI1
#define TIM8_set_channel1_input_map_TI1()	TIM8_set_channel1_input()	//同上
#define TIM8_set_channel1_input_map_TI2()	TIM8_set_CC1S(2)		//通道1配置为输入捕获,IC1映射到TI2
#define TIM8_set_channel1_input_map_TRC()	TIM8_set_CC1S(3)		//通道1配置为输入捕获,IC1映射到TRC


//************TIMx_CCMR2**************//
/*捕获/比较通道4功能选择
	可选择为输入捕获模式
		通道的真实输入可以有多个映射
	可选择为输出比较模式
Bits 9:8 CC4S: Capture/Compare 4 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC4 channel is configured as output
01: CC4 channel is configured as input, IC4 is mapped on TI4
10: CC4 channel is configured as input, IC4 is mapped on TI3
11: CC4 channel is configured as input, IC4 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC4S bits are writable only when the channel is OFF (CC4E = ‘0’ in TIMx_CCER).
*/
void TIM1_set_CC4S(U8 cc4s);
void TIM8_set_CC4S(U8 cc4s);


#define TIM1_set_channel4_output()			TIM1_set_CC4S(0)		//通道4配置为比较输出
#define TIM1_set_channel4_input()			TIM1_set_CC4S(1)		//通道4配置为输入捕获,IC4映射到TI4
#define TIM1_set_channel4_input_map_TI4()	TIM1_set_channel4_input()	//同上
#define TIM1_set_channel4_input_map_TI3()	TIM1_set_CC4S(2)		//通道4配置为输入捕获,IC4映射到TI3
#define TIM1_set_channel4_input_map_TRC()	TIM1_set_CC4S(3)		//通道4配置为输入捕获,IC4映射到TRC

#define TIM8_set_channel4_output()			TIM8_set_CC4S(0)		//通道4配置为比较输出
#define TIM8_set_channel4_input()			TIM8_set_CC4S(1)		//通道4配置为输入捕获,IC4映射到TI4
#define TIM8_set_channel4_input_map_TI4()	TIM8_set_channel4_input()	//同上
#define TIM8_set_channel4_input_map_TI3()	TIM8_set_CC4S(2)		//通道4配置为输入捕获,IC4映射到TI3
#define TIM8_set_channel4_input_map_TRC()	TIM8_set_CC4S(3)		//通道4配置为输入捕获,IC4映射到TRC


/*捕获/比较通道3功能选择
	可选择为输入捕获模式
		通道的真实输入可以有多个映射
	可选择为输出比较模式
Bits 1:0 CC3S: Capture/Compare 3 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC3 channel is configured as output
01: CC3 channel is configured as input, IC3 is mapped on TI3
10: CC3 channel is configured as input, IC3 is mapped on TI4
11: CC3 channel is configured as input, IC3 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC3S bits are writable only when the channel is OFF (CC3E = ‘0’ in TIMx_CCER).
*/
void TIM1_set_CC3S(U8 cc3s);
void TIM8_set_CC3S(U8 cc3s);

#define TIM1_set_channel3_output()			TIM1_set_CC3S(0)		//通道3配置为比较输出
#define TIM1_set_channel3_input()			TIM1_set_CC3S(1)		//通道3配置为输入捕获,IC3映射到TI3
#define TIM1_set_channel3_input_map_TI3()	TIM1_set_channel3_input()	//同上
#define TIM1_set_channel3_input_map_TI4()	TIM1_set_CC3S(2)		//通道3配置为输入捕获,IC3映射到TI4
#define TIM1_set_channel3_input_map_TRC()	TIM1_set_CC3S(3)		//通道3配置为输入捕获,IC3映射到TRC

#define TIM8_set_channel3_output()			TIM8_set_CC3S(0)		//通道3配置为比较输出
#define TIM8_set_channel3_input()			TIM8_set_CC3S(1)		//通道3配置为输入捕获,IC3映射到TI3
#define TIM8_set_channel3_input_map_TI3()	TIM8_set_channel3_input()	//同上
#define TIM8_set_channel3_input_map_TI4()	TIM8_set_CC3S(2)		//通道3配置为输入捕获,IC3映射到TI4
#define TIM8_set_channel3_input_map_TRC()	TIM8_set_CC3S(3)		//通道3配置为输入捕获,IC3映射到TRC


//**********************当通道被配置成比较输出时*****************************//

//************TIMx_CCMR1****************//
/*输出比较通道2清除模式使能
	设置该位，当外部ETR引脚输入一个高脉冲时，OCxRef复位
Bit 15 OC2CE: Output Compare 2 clear enable
*/
void TIM1_set_OC2CE(U8 oc2ce);
void TIM8_set_OC2CE(U8 oc2ce);

#define TIM1_enable_OC2_clear()		TIM1_set_OC2CE(2)		//通道2当外部ETRF为高时OCxRef复位
#define TIM1_disable_OC2_clear()	TIM1_set_OC2CE(0)		//通道2当外部ETRF为高时OCxRef不复位

#define TIM8_enable_OC2_clear()		TIM8_set_OC2CE(2)		//通道2当外部ETRF为高时OCxRef复位
#define TIM8_disable_OC2_clear()	TIM8_set_OC2CE(0)		//通道2当外部ETRF为高时OCxRef不复位

/*输出比较通道2模式选择
	此位段定义了在比较输出模式下的工作模式
		冻结模式 	比较结果不影响输出
		置高模式	比较发生输出置高
		置低模式	比较发生输出复位
		强制高		输出高，跟比较结果无关
		强制低		输出低，跟比较结果无关
		PWM模式1	CNT<CCRx为高
		PWM模式2	CNT<CCRx为低
	这里的输出是OCxREF电平的改变，而OCxREF控制OCx和OCxN是间接的通过设置CCxP和CCxNP位来控制的
Bits 14:12 OC2M[2:0]: Output Compare 2 mode
*/
void TIM1_set_OC2M(U8 oc2m);
void TIM8_set_OC2M(U8 oc2m);


#define TIM1_set_OC2_frozen_mode()			TIM1_set_OC2M(0)	//通道2比较输出模式配置为冻结模式
#define TIM1_set_OC2_active_mode()			TIM1_set_OC2M(1)	//通道2比较输出模式配置为置高模式
#define TIM1_set_OC2_inactive_mode()		TIM1_set_OC2M(2)	//通道2比较输出模式配置为置低模式
#define TIM1_set_OC2_toggle_mode()			TIM1_set_OC2M(3)	//通道2比较输出模式配置为翻转模式
#define TIM1_set_OC2_force_inactive_mode()	TIM1_set_OC2M(4)	//通道2比较输出模式配置为强制低
#define TIM1_set_OC2_force_active_mode()	TIM1_set_OC2M(5)	//通道2比较输出模式配置为强制高
#define TIM1_set_OC2_PWM1_mode()			TIM1_set_OC2M(6)	//通道2比较输出模式配置为PWM1模式
#define TIM1_set_OC2_PWM2_mode()			TIM1_set_OC2M(7)	//通道2比较输出模式配置为PWM2模式

#define TIM8_set_OC2_frozen_mode()			TIM8_set_OC2M(0)	//通道2比较输出模式配置为冻结模式
#define TIM8_set_OC2_active_mode()			TIM8_set_OC2M(1)	//通道2比较输出模式配置为置高模式
#define TIM8_set_OC2_inactive_mode()		TIM8_set_OC2M(2)	//通道2比较输出模式配置为置低模式
#define TIM8_set_OC2_toggle_mode()			TIM8_set_OC2M(3)	//通道2比较输出模式配置为翻转模式
#define TIM8_set_OC2_force_inactive_mode()	TIM8_set_OC2M(4)	//通道2比较输出模式配置为强制低
#define TIM8_set_OC2_force_active_mode()	TIM8_set_OC2M(5)	//通道2比较输出模式配置为强制高
#define TIM8_set_OC2_PWM1_mode()			TIM8_set_OC2M(6)	//通道2比较输出模式配置为PWM1模式
#define TIM8_set_OC2_PWM2_mode()			TIM8_set_OC2M(7)	//通道2比较输出模式配置为PWM2模式


/*输出比较通道2重新装载寄存器使能
	设置该位，重新装载寄存器的值在发生更新事件时才进入其影子寄存器
Bit 11 OC2PE: Output Compare 2 preload enable
*/
void TIM1_set_OC2PE(U8 oc2pe);
void TIM8_set_OC2PE(U8 oc2pe);

#define TIM1_enable_CCR2_preload()	TIM1_set_OC2PE(1)	//通道2使能CCR2寄存器缓冲
#define TIM1_disable_CCR2_preload()	TIM1_set_OC2PE(0)	//通道2除能CCR2寄存器缓冲

#define TIM8_enable_CCR2_preload()	TIM8_set_OC2PE(1)	//通道2使能CCR2寄存器缓冲
#define TIM8_disable_CCR2_preload()	TIM8_set_OC2PE(0)	//通道2除能CCR2寄存器缓冲

/*
Bit 10 OC2FE: Output Compare 2 fast enable
*/
//to do

/*输出比较通道1清除模式使能
	设置该位，当外部ETR引脚输入一个高脉冲时，OCxRef复位
Bit 7 OC1CE: Output Compare 1 clear enable
OC1CE: Output Compare 1 Clear Enable
0: OC1Ref is not affected by the ETRF Input
1: OC1Ref is cleared as soon as a High level is detected on ETRF input
*/
void TIM1_set_OC1CE(U8 oc1ce);
void TIM8_set_OC1CE(U8 oc1ce);

#define TIM1_enable_OC1_clear()		TIM1_set_OC1CE(1)		//通道1当外部ETRF为高时OCxRef复位
#define TIM1_disable_OC1_clear()	TIM1_set_OC1CE(0)		//通道1当外部ETRF为高时OCxRef不复位

#define TIM8_enable_OC1_clear()		TIM8_set_OC1CE(1)		//通道1当外部ETRF为高时OCxRef复位
#define TIM8_disable_OC1_clear()	TIM8_set_OC1CE(0)		//通道1当外部ETRF为高时OCxRef不复位

/*输出比较通道1模式选择
	此位段定义了在比较输出模式下的工作模式
		冻结模式 	比较结果不影响输出
		置高模式	比较发生输出置高
		置低模式	比较发生输出复位
		强制高		输出高，跟比较结果无关
		强制低		输出低，跟比较结果无关
		PWM模式1	CNT<CCRx为高
		PWM模式2	CNT<CCRx为低
	这里的输出是OCxREF电平的改变，而OCxREF控制OCx和OCxN是间接的通过设置CCxP和CCxNP位来控制的
Bits 6:4 OC1M: Output Compare 1 mode
These bits define the behavior of the output reference signal OC1REF from which OC1 and 
OC1N are derived. OC1REF is active high whereas OC1 and OC1N active level depends on 
CC1P and CC1NP bits.
000: Frozen - The comparison between the output compare register TIMx_CCR1 and the 
counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing 
base).
001: Set channel 1 to active level on match. OC1REF signal is forced high when the counter 
TIMx_CNT matches the capture/compare register 1 (TIMx_CCR1).
010: Set channel 1 to inactive level on match. OC1REF signal is forced low when the 
counter TIMx_CNT matches the capture/compare register 1 (TIMx_CCR1).
011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR1.
100: Force inactive level - OC1REF is forced low.
101: Force active level - OC1REF is forced high.
110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 
else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0’) as long as 
TIMx_CNT>TIMx_CCR1 else active (OC1REF=’1’).
111: PWM mode 2 - In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1 
else active. In downcounting, channel 1 is active as long as TIMx_CNT>TIMx_CCR1 else 
inactive.
Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed 
(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in 
output).
2: In PWM mode 1 or 2, the OCREF level changes only when the result of the 
comparison changes or when the output compare mode switches from “frozen” mode 
to “PWM” mode.
*/
void TIM1_set_OC1M(U8 oc1m);
void TIM8_set_OC1M(U8 oc1m);

#define TIM1_set_OC1_frozen_mode()			TIM1_set_OC1M(0)	//通道1比较输出模式配置为冻结模式
#define TIM1_set_OC1_active_mode()			TIM1_set_OC1M(1)	//通道1比较输出模式配置为置高模式
#define TIM1_set_OC1_inactive_mode()		TIM1_set_OC1M(2)	//通道1比较输出模式配置为置低模式
#define TIM1_set_OC1_toggle_mode()			TIM1_set_OC1M(3)	//通道1比较输出模式配置为翻转模式
#define TIM1_set_OC1_force_inactive_mode()	TIM1_set_OC1M(4)	//通道1比较输出模式配置为强制低
#define TIM1_set_OC1_force_active_mode()	TIM1_set_OC1M(5)	//通道1比较输出模式配置为强制高
#define TIM1_set_OC1_PWM1_mode()			TIM1_set_OC1M(6)	//通道1比较输出模式配置为PWM1模式
#define TIM1_set_OC1_PWM2_mode()			TIM1_set_OC1M(7)	//通道1比较输出模式配置为PWM2模式

#define TIM8_set_OC1_frozen_mode()			TIM8_set_OC1M(0)	//通道1比较输出模式配置为冻结模式
#define TIM8_set_OC1_active_mode()			TIM8_set_OC1M(1)	//通道1比较输出模式配置为置高模式
#define TIM8_set_OC1_inactive_mode()		TIM8_set_OC1M(2)	//通道1比较输出模式配置为置低模式
#define TIM8_set_OC1_toggle_mode()			TIM8_set_OC1M(3)	//通道1比较输出模式配置为翻转模式
#define TIM8_set_OC1_force_inactive_mode()	TIM8_set_OC1M(4)	//通道1比较输出模式配置为强制低
#define TIM8_set_OC1_force_active_mode()	TIM8_set_OC1M(5)	//通道1比较输出模式配置为强制高
#define TIM8_set_OC1_PWM1_mode()			TIM8_set_OC1M(6)	//通道1比较输出模式配置为PWM1模式
#define TIM8_set_OC1_PWM2_mode()			TIM8_set_OC1M(7)	//通道1比较输出模式配置为PWM2模式


/*输出比较通道1重新装载寄存器使能
	设置该位，重新装载寄存器的值在发生更新事件时才进入其影子寄存器
Bit 3 OC1PE: Output Compare 1 preload enable
0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the 
new value is taken in account immediately.
1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload 
register. TIMx_CCR1 preload value is loaded in the active register at each update event.
Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed 
(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in 
output).
2: The PWM mode can be used without validating the preload register only in one 
pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
*/
void TIM1_set_OC1PE(U8 oc1pe);
void TIM8_set_OC1PE(U8 oc1pe);

#define TIM1_enable_CCR1_preload()	TIM1_set_OC1PE(1)	//通道1使能CCR1寄存器缓冲
#define TIM1_disable_CCR1_preload()	TIM1_set_OC1PE(0)	//通道1除能CCR1寄存器缓冲

#define TIM8_enable_CCR1_preload()	TIM8_set_OC1PE(1)	//通道1使能CCR1寄存器缓冲
#define TIM8_disable_CCR1_preload()	TIM8_set_OC1PE(0)	//通道1除能CCR1寄存器缓冲

/*
Bit 2 OC1FE: Output Compare 1 fast enable
This bit is used to accelerate the effect of an event on the trigger in input on the CC output.
0: CC1 behaves normally depending on counter and CCR1 values even when the trigger is 
ON. The minimum delay to activate CC1 output when an edge occurs on the trigger input is 
5 clock cycles.
1: An active edge on the trigger input acts like a compare match on CC1 output. Then, OC is 
set to the compare level independently from the result of the comparison. Delay to sample 
the trigger input and to activate CC1 output is reduced to 3 clock cycles. OCFE acts only if 
the channel is configured in PWM1 or PWM2 mode.
*/
//to do

//************TIMx_CCMR2****************//
/*输出比较通道4清除模式使能
	设置该位，当外部ETR引脚输入一个高脉冲时，OCxRef复位
Bit 15 OC4CE: Output compare 4 clear enable
*/
void TIM1_set_OC4CE(U8 oc4ce);
void TIM8_set_OC4CE(U8 oc4ce);

#define TIM1_enable_OC4_clear()		TIM1_set_OC4CE(1)		//通道4当外部ETRF为高时OCxRef复位
#define TIM1_disable_OC4_clear()	TIM1_set_OC4CE(0)		//通道4当外部ETRF为高时OCxRef不复位

#define TIM8_enable_OC4_clear()		TIM8_set_OC4CE(1)		//通道4当外部ETRF为高时OCxRef复位
#define TIM8_disable_OC4_clear()	TIM8_set_OC4CE(0)		//通道4当外部ETRF为高时OCxRef不复位


/*输出比较通道4模式选择
	此位段定义了在比较输出模式下的工作模式
		冻结模式 	比较结果不影响输出
		置高模式	比较发生输出置高
		置低模式	比较发生输出复位
		强制高		输出高，跟比较结果无关
		强制低		输出低，跟比较结果无关
		PWM模式1	CNT<CCRx为高
		PWM模式2	CNT<CCRx为低
	这里的输出是OCxREF电平的改变，而OCxREF控制OCx和OCxN是间接的通过设置CCxP和CCxNP位来控制的
Bits 14:12 OC4M: Output compare 4 mode
*/
void TIM1_set_OC4M(U8 oc4m);
void TIM8_set_OC4M(U8 oc4m);

#define TIM1_set_OC4_frozen_mode()			TIM1_set_OC4M(0)	//通道4比较输出模式配置为冻结模式
#define TIM1_set_OC4_active_mode()			TIM1_set_OC4M(1)	//通道4比较输出模式配置为置高模式
#define TIM1_set_OC4_inactive_mode()		TIM1_set_OC4M(2)	//通道4比较输出模式配置为置低模式
#define TIM1_set_OC4_toggle_mode()			TIM1_set_OC4M(3)	//通道4比较输出模式配置为翻转模式
#define TIM1_set_OC4_force_inactive_mode()	TIM1_set_OC4M(4)	//通道4比较输出模式配置为强制低
#define TIM1_set_OC4_force_active_mode()	TIM1_set_OC4M(5)	//通道4比较输出模式配置为强制高
#define TIM1_set_OC4_PWM1_mode()			TIM1_set_OC4M(6)	//通道4比较输出模式配置为PWM1模式
#define TIM1_set_OC4_PWM2_mode()			TIM1_set_OC4M(7)	//通道4比较输出模式配置为PWM2模式

#define TIM8_set_OC4_frozen_mode()			TIM8_set_OC4M(0)	//通道4比较输出模式配置为冻结模式
#define TIM8_set_OC4_active_mode()			TIM8_set_OC4M(1)	//通道4比较输出模式配置为置高模式
#define TIM8_set_OC4_inactive_mode()		TIM8_set_OC4M(2)	//通道4比较输出模式配置为置低模式
#define TIM8_set_OC4_toggle_mode()			TIM8_set_OC4M(3)	//通道4比较输出模式配置为翻转模式
#define TIM8_set_OC4_force_inactive_mode()	TIM8_set_OC4M(4)	//通道4比较输出模式配置为强制低
#define TIM8_set_OC4_force_active_mode()	TIM8_set_OC4M(5)	//通道4比较输出模式配置为强制高
#define TIM8_set_OC4_PWM1_mode()			TIM8_set_OC4M(6)	//通道4比较输出模式配置为PWM1模式
#define TIM8_set_OC4_PWM2_mode()			TIM8_set_OC4M(7)	//通道4比较输出模式配置为PWM2模式


/*输出比较通道4重新装载寄存器使能
	设置该位，重新装载寄存器的值在发生更新事件时才进入其影子寄存器
Bit 11 OC4PE: Output compare 4 preload enable
*/
void TIM1_set_OC4PE(U8 oc4pe);
void TIM8_set_OC4PE(U8 oc4pe);

#define TIM1_enable_CCR4_preload()	TIM1_set_OC4PE(1)	//通道4使能CCR4寄存器缓冲
#define TIM1_disable_CCR4_preload()	TIM1_set_OC4PE(0)	//通道4除能CCR4寄存器缓冲

#define TIM8_enable_CCR4_preload()	TIM8_set_OC4PE(1)	//通道4使能CCR4寄存器缓冲
#define TIM8_disable_CCR4_preload()	TIM8_set_OC4PE(0)	//通道4除能CCR4寄存器缓冲

/*
Bit 10 OC4FE: Output compare 4 fast enable
*/
//to do

/*输出比较通道3清除模式使能
	设置该位，当外部ETR引脚输入一个高脉冲时，OCxRef复位
Bit 7 OC3CE: Output compare 3 clear enable
*/
void TIM1_set_OC3CE(U8 oc3ce);
void TIM8_set_OC3CE(U8 oc3ce);

#define TIM1_enable_OC3_clear()		TIM1_set_OC3CE(1)		//通道3当外部ETRF为高时OCxRef复位
#define TIM1_disable_OC3_clear()	TIM1_set_OC3CE(0)		//通道3当外部ETRF为高时OCxRef不复位

#define TIM8_enable_OC3_clear()		TIM8_set_OC3CE(1)		//通道3当外部ETRF为高时OCxRef复位
#define TIM8_disable_OC3_clear()	TIM8_set_OC3CE(0)		//通道3当外部ETRF为高时OCxRef不复位

/*
输出比较通道3模式选择
	此位段定义了在比较输出模式下的工作模式
		冻结模式 	比较结果不影响输出
		置高模式	比较发生输出置高
		置低模式	比较发生输出复位
		强制高		输出高，跟比较结果无关
		强制低		输出低，跟比较结果无关
		PWM模式1	CNT<CCRx为高
		PWM模式2	CNT<CCRx为低
	这里的输出是OCxREF电平的改变，而OCxREF控制OCx和OCxN是间接的通过设置CCxP和CCxNP位来控制的
Bits 6:4 OC3M: Output compare 3 mode
*/
void TIM1_set_OC3M(U8 oc3m);
void TIM8_set_OC3M(U8 oc3m);

#define TIM1_set_OC3_frozen_mode()			TIM1_set_OC3M(0)	//通道3比较输出模式配置为冻结模式
#define TIM1_set_OC3_active_mode()			TIM1_set_OC3M(1)	//通道3比较输出模式配置为置高模式
#define TIM1_set_OC3_inactive_mode()		TIM1_set_OC3M(2)	//通道3比较输出模式配置为置低模式
#define TIM1_set_OC3_toggle_mode()			TIM1_set_OC3M(3)	//通道3比较输出模式配置为翻转模式
#define TIM1_set_OC3_force_inactive_mode()	TIM1_set_OC3M(4)	//通道3比较输出模式配置为强制低
#define TIM1_set_OC3_force_active_mode()	TIM1_set_OC3M(5)	//通道3比较输出模式配置为强制高
#define TIM1_set_OC3_PWM1_mode()			TIM1_set_OC3M(6)	//通道3比较输出模式配置为PWM1模式
#define TIM1_set_OC3_PWM2_mode()			TIM1_set_OC3M(7)	//通道3比较输出模式配置为PWM2模式

#define TIM8_set_OC3_frozen_mode()			TIM8_set_OC3M(0)	//通道3比较输出模式配置为冻结模式
#define TIM8_set_OC3_active_mode()			TIM8_set_OC3M(1)	//通道3比较输出模式配置为置高模式
#define TIM8_set_OC3_inactive_mode()		TIM8_set_OC3M(2)	//通道3比较输出模式配置为置低模式
#define TIM8_set_OC3_toggle_mode()			TIM8_set_OC3M(3)	//通道3比较输出模式配置为翻转模式
#define TIM8_set_OC3_force_inactive_mode()	TIM8_set_OC3M(4)	//通道3比较输出模式配置为强制低
#define TIM8_set_OC3_force_active_mode()	TIM8_set_OC3M(5)	//通道3比较输出模式配置为强制高
#define TIM8_set_OC3_PWM1_mode()			TIM8_set_OC3M(6)	//通道3比较输出模式配置为PWM1模式
#define TIM8_set_OC3_PWM2_mode()			TIM8_set_OC3M(7)	//通道3比较输出模式配置为PWM2模式


/*输出比较通道3重新装载寄存器使能
	设置该位，重新装载寄存器的值在发生更新事件时才进入其影子寄存器
Bit 3 OC3PE: Output compare 3 preload enable
*/
void TIM1_set_OC3PE(U8 oc3pe);
void TIM8_set_OC3PE(U8 oc3pe);

#define TIM1_enable_CCR3_preload()	TIM1_set_OC3PE(1)	//通道3使能CCR3寄存器缓冲
#define TIM1_disable_CCR3_preload()	TIM1_set_OC3PE(0)	//通道3除能CCR3寄存器缓冲

#define TIM8_enable_CCR3_preload()	TIM8_set_OC3PE(1)	//通道3使能CCR3寄存器缓冲
#define TIM8_disable_CCR3_preload()	TIM8_set_OC3PE(0)	//通道3除能CCR3寄存器缓冲

/*
Bit 2 OC3FE: Output compare 3 fast enable
*/
//to do 


//*********************当通道被配置成输入捕获模式时**************************//
//************TIMx_CCMR1****************//
/*输入捕获2滤波器设置
Bits 15:12 IC2F: Input capture 2 filter
*/
void TIM1_set_IC2F(U8 ic2f);
void TIM8_set_IC2F(U8 ic2f);

/*输入捕获2预分频系数选择
	此位段用来设置CHANNEL1做为输入捕获时的分频系数
Bits 11:10 IC2PSC[1:0]: Input capture 2 prescaler
*/
void TIM1_set_IC2PSC(U8 tc2psc);
void TIM8_set_IC2PSC(U8 tc2psc);

#define TIM1_set_IC2_prescaler_1()	TIM1_set_IC2PSC(0)	//通道2捕获输入不分频
#define TIM1_set_IC2_prescaler_2()	TIM1_set_IC2PSC(1)	//通道2捕获输入分频2
#define TIM1_set_IC2_prescaler_4()	TIM1_set_IC2PSC(2)	//通道2捕获输入分频4
#define TIM1_set_IC2_prescaler_8()	TIM1_set_IC2PSC(3)	//通道2捕获输入分频8

#define TIM8_set_IC2_prescaler_1()	TIM8_set_IC2PSC(0)	//通道2捕获输入不分频
#define TIM8_set_IC2_prescaler_2()	TIM8_set_IC2PSC(1)	//通道2捕获输入分频2
#define TIM8_set_IC2_prescaler_4()	TIM8_set_IC2PSC(2)	//通道2捕获输入分频4
#define TIM8_set_IC2_prescaler_8()	TIM8_set_IC2PSC(3)	//通道2捕获输入分频8


/*输入捕获1滤波器设置
to do	
Bits 7:4 IC1F[3:0]: Input capture 1 filter
This bit-field defines the frequency used to sample TI1 input and the length of the digital filter applied 
to TI1. The digital filter is made of an event counter in which N events are needed to validate a 
transition on the output:
0000: No filter, sampling is done at fDTS
0001: fSAMPLING=fCK_INT, N=2
0010: fSAMPLING=fCK_INT, N=4
0011: fSAMPLING=fCK_INT, N=8
0100: fSAMPLING=fDTS/2, N=6
0101: fSAMPLING=fDTS/2, N=8
0110: fSAMPLING=fDTS/4, N=6
0111: fSAMPLING=fDTS/4, N=8
1000: fSAMPLING=fDTS/8, N=6
1001: fSAMPLING=fDTS/8, N=8
1010: fSAMPLING=fDTS/16, N=5
1011: fSAMPLING=fDTS/16, N=6
1100: fSAMPLING=fDTS/16, N=8
1101: fSAMPLING=fDTS/32, N=5
1110: fSAMPLING=fDTS/32, N=6
1111: fSAMPLING=fDTS/32, N=8
*/
void TIM1_set_IC1F(U8 ic1f);
void TIM8_set_IC1F(U8 ic1f);


/*输入捕获1预分频系数选择
	此位段用来设置CHANNEL1做为输入捕获时的分频系数
Bits 3:2 IC1PSC: Input capture 1 prescaler
This bit-field defines the ratio of the prescaler acting on CC1 input (IC1).
The prescaler is reset as soon as CC1E=’0’ (TIMx_CCER register).
00: no prescaler, capture is done each time an edge is detected on the capture input
01: capture is done once every 2 events
10: capture is done once every 4 events
11: capture is done once every 8 events
*/
void TIM1_set_IC1PSC(U8 tc1psc);
void TIM8_set_IC1PSC(U8 tc1psc);

#define TIM1_set_IC1_prescaler_1()	TIM1_set_IC1PSC(0)	//通道1捕获输入不分频
#define TIM1_set_IC1_prescaler_2()	TIM1_set_IC1PSC(1)	//通道1捕获输入分频2
#define TIM1_set_IC1_prescaler_4()	TIM1_set_IC1PSC(2)	//通道1捕获输入分频4
#define TIM1_set_IC1_prescaler_8()	TIM1_set_IC1PSC(3)	//通道1捕获输入分频8

#define TIM8_set_IC1_prescaler_1()	TIM8_set_IC1PSC(0)	//通道1捕获输入不分频
#define TIM8_set_IC1_prescaler_2()	TIM8_set_IC1PSC(1)	//通道1捕获输入分频2
#define TIM8_set_IC1_prescaler_4()	TIM8_set_IC1PSC(2)	//通道1捕获输入分频4
#define TIM8_set_IC1_prescaler_8()	TIM8_set_IC1PSC(3)	//通道1捕获输入分频8


//************TIMx_CCMR2****************//
/*输入捕获4滤波器设置
Bits 15:12 IC4F: Input capture 4 filter
*/
void TIM1_set_IC4F(U8 ic4f);
void TIM8_set_IC4F(U8 ic4f);

/*输入捕获4预分频系数选择
Bits 11:10 IC4PSC: Input capture 4 prescaler
*/
void TIM1_set_IC4PSC(U8 tc4psc);
void TIM8_set_IC4PSC(U8 tc4psc);

#define TIM1_set_IC4_prescaler_1()	TIM1_set_IC4PSC(0)	//通道4捕获输入不分频
#define TIM1_set_IC4_prescaler_2()	TIM1_set_IC4PSC(1)	//通道4捕获输入分频2
#define TIM1_set_IC4_prescaler_4()	TIM1_set_IC4PSC(2)	//通道4捕获输入分频4
#define TIM1_set_IC4_prescaler_8()	TIM1_set_IC4PSC(3)	//通道4捕获输入分频8

#define TIM8_set_IC4_prescaler_1()	TIM8_set_IC4PSC(0)	//通道4捕获输入不分频
#define TIM8_set_IC4_prescaler_2()	TIM8_set_IC4PSC(1)	//通道4捕获输入分频2
#define TIM8_set_IC4_prescaler_4()	TIM8_set_IC4PSC(2)	//通道4捕获输入分频4
#define TIM8_set_IC4_prescaler_8()	TIM8_set_IC4PSC(3)	//通道4捕获输入分频8


/*输入捕获3滤波器设置
Bits 7:4 IC3F: Input capture 3 filter
*/
void TIM1_set_IC3F(U8 ic3f);
void TIM8_set_IC3F(U8 ic3f);


/*输入捕获3滤波器设置
Bits 3:2 IC3PSC: Input capture 3 prescaler
*/
void TIM1_set_IC3PSC(U8 tc3psc);
void TIM8_set_IC3PSC(U8 tc3psc);

#define TIM1_set_IC3_prescaler_1()	TIM1_set_IC3PSC(0)	//通道3捕获输入不分频
#define TIM1_set_IC3_prescaler_2()	TIM1_set_IC3PSC(1)	//通道3捕获输入分频2
#define TIM1_set_IC3_prescaler_4()	TIM1_set_IC3PSC(2)	//通道3捕获输入分频4
#define TIM1_set_IC3_prescaler_8()	TIM1_set_IC3PSC(3)	//通道3捕获输入分频8

#define TIM8_set_IC3_prescaler_1()	TIM8_set_IC3PSC(0)	//通道3捕获输入不分频
#define TIM8_set_IC3_prescaler_2()	TIM8_set_IC3PSC(1)	//通道3捕获输入分频2
#define TIM8_set_IC3_prescaler_4()	TIM8_set_IC3PSC(2)	//通道3捕获输入分频4
#define TIM8_set_IC3_prescaler_8()	TIM8_set_IC3PSC(3)	//通道3捕获输入分频8


//****************************************************************//
//*****TIM1&TIM8 capture/compare enable register (TIMx_CCER)******//
//****************************************************************//
/*
捕获/比较使能寄存器
TIM1&TIM8 capture/compare enable register (TIMx_CCER)
Address offset: 0x20
Reset value: 0x0000
*/
/*
Bits 15:14 Reserved, always read as 0.
*/

/*通道4捕获输入极性/比较输出极性
	该位用来选择极性
	输出比较时
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	输入捕获时
		选择ICx的输入极性
Bit 13 CC4P: Capture/Compare 4 output polarity
refer to CC1P description
*/
void TIM1_set_CC4P(U8 cc4p);
void TIM8_set_CC4P(U8 cc4p);

#define TIM1_set_CC4_polarity_high()	TIM1_set_CC4P(0)	//设置通道4输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC4_polarity_low()		TIM1_set_CC4P(1)	//设置通道4输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC4_polarity_high()	TIM8_set_CC4P(0)	//设置通道4输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC4_polarity_low()		TIM8_set_CC4P(1)	//设置通道4输入(TIx)极性/输出(OxREF)极性低有效

/*通道4的捕获使能和比较使能
	捕获模式
		捕获使能
			该位用来控制捕获到的信号是否传送到捕获/比较寄存器
	比较模式
		比较输出使能
	该位的作用根据CCxS(通道功能选择)位段决定
Bit 12 CC4E: Capture/Compare 4 output enable
refer to CC1E description
*/
void TIM1_set_CC4E(U8 cc4e);
void TIM8_set_CC4E(U8 cc4e);

#define TIM1_enable_CC4()	TIM1_set_CC4E(1)	//通道4比较输出使能/捕获使能
#define TIM1_disable_CC4()	TIM1_set_CC4E(0)	//通道4比较输出除能/捕获除能 

#define TIM8_enable_CC4()	TIM8_set_CC4E(1)	//通道4比较输出使能/捕获使能
#define TIM8_disable_CC4()	TIM8_set_CC4E(0)	//通道4比较输出除能/捕获除能 

/*通道3比较互补输出极性
	该位用来选择极性
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	该位只用于输出比较模式
Bit 11 CC3NP: Capture/Compare 3 complementary output polarity
refer to CC1NP description
*/
void TIM1_set_CC3NP(U8 cc3np);
void TIM8_set_CC3NP(U8 cc3np);

#define TIM1_set_CC3N_polarity_high()	TIM1_set_CC3NP(0)	//设置通道3输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC3N_polarity_low()	TIM1_set_CC3NP(1)	//设置通道3输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC3N_polarity_high()	TIM8_set_CC3NP(0)	//设置通道3输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC3N_polarity_low()	TIM8_set_CC3NP(1)	//设置通道3输入(TIx)极性/输出(OxREF)极性低有效

/*通道3比较互补输出使能
	该位只用于比较模式
		0:输出比较的OCx极性为高
		1:输出比较的OCx极性为低
Bit 10 CC3NE: Capture/Compare 3 complementary output enable
refer to CC1NE description
*/
void TIM1_set_CC3NE(U8 cc3ne);
void TIM8_set_CC3NE(U8 cc3ne);

#define TIM1_enable_CC3N()	TIM1_set_CC3NE(1)	//通道3比较输出使能/捕获使能
#define TIM1_disable_CC3N()	TIM1_set_CC3NE(0)	//通道3比较输出除能/捕获除能 

#define TIM8_enable_CC3N()	TIM8_set_CC3NE(1)	//通道3比较输出使能/捕获使能
#define TIM8_disable_CC3N()	TIM8_set_CC3NE(0)	//通道3比较输出除能/捕获除能 


/*通道3捕获输入极性/比较输出极性
	该位用来选择极性
	输出比较时
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	输入捕获时
		选择ICx的输入极性
Bit 9 CC3P: Capture/Compare 3 output polarity
refer to CC1P description
*/
void TIM1_set_CC3P(U8 cc3p);
void TIM8_set_CC3P(U8 cc3p);

#define TIM1_set_CC3_polarity_high()	TIM1_set_CC3P(0)	//设置通道3输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC3_polarity_low()		TIM1_set_CC3P(1)	//设置通道3输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC3_polarity_high()	TIM8_set_CC3P(0)	//设置通道3输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC3_polarity_low()		TIM8_set_CC3P(1)	//设置通道3输入(TIx)极性/输出(OxREF)极性低有效


/*通道3的捕获使能和比较使能
	捕获模式
		捕获使能
		比较使能
	比较模式
		//to do
	该位的作用根据CCxS(通道功能选择)位段决定
Bit 8 CC3E: Capture/Compare 3 output enable
refer to CC1E description
*/
void TIM1_set_CC3E(U8 cc3e);
void TIM8_set_CC3E(U8 cc3e);

#define TIM1_enable_CC3()	TIM1_set_CC3E(1)	//通道3比较输出使能/捕获使能
#define TIM1_disable_CC3()	TIM1_set_CC3E(0)	//通道3比较输出除能/捕获除能 

#define TIM8_enable_CC3()	TIM8_set_CC3E(1)	//通道3比较输出使能/捕获使能
#define TIM8_disable_CC3()	TIM8_set_CC3E(0)	//通道3比较输出除能/捕获除能 


/*通道2比较互补输出极性
	该位用来选择极性
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	该位只用于输出比较模式
Bit 7 CC2NP: Capture/Compare 2 complementary output polarity
refer to CC1NP description
*/
void TIM1_set_CC2NP(U8 cc2np);
void TIM8_set_CC2NP(U8 cc2np);

#define TIM1_set_CC2N_polarity_high()	TIM1_set_CC2NP(0)	//设置通道2输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC2N_polarity_low()	TIM1_set_CC2NP(1)	//设置通道2输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC2N_polarity_high()	TIM8_set_CC2NP(0)	//设置通道2输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC2N_polarity_low()	TIM8_set_CC2NP(1)	//设置通道2输入(TIx)极性/输出(OxREF)极性低有效

/*通道2比较互补输出使能
	该位只用于比较模式
		0:输出比较的OCx极性为高
		1:输出比较的OCx极性为低
Bit 6 CC2NE: Capture/Compare 2 complementary output enable
refer to CC1NE description
*/
void TIM1_set_CC2NE(U8 cc2ne);
void TIM8_set_CC2NE(U8 cc2ne);

#define TIM1_enable_CC2N()	TIM1_set_CC2NE(1)	//通道2比较输出使能/捕获使能
#define TIM1_disable_CC2N()	TIM1_set_CC2NE(0)	//通道2比较输出除能/捕获除能 

#define TIM8_enable_CC2N()	TIM8_set_CC2NE(1)	//通道2比较输出使能/捕获使能
#define TIM8_disable_CC2N()	TIM8_set_CC2NE(0)	//通道2比较输出除能/捕获除能 

/*通道2捕获输入极性/比较输出极性
	该位用来选择极性
	输出比较时
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	输入捕获时
		选择ICx的输入极性
Bit 5 CC2P: Capture/Compare 2 output polarity
refer to CC1P description
*/
void TIM1_set_CC2P(U8 cc2p);
void TIM8_set_CC2P(U8 cc2p);

#define TIM1_set_CC2_polarity_high()	TIM1_set_CC2P(0)	//设置通道2输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC2_polarity_low()		TIM1_set_CC2P(1)	//设置通道2输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC2_polarity_high()	TIM8_set_CC2P(0)	//设置通道2输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC2_polarity_low()		TIM8_set_CC2P(1)	//设置通道2输入(TIx)极性/输出(OxREF)极性低有效


/*通道2的捕获使能和比较使能
	捕获模式
		捕获使能
		比较使能
	比较模式
		//to do
	该位的作用根据CCxS(通道功能选择)位段决定
Bit 4 CC2E: Capture/Compare 2 output enable
refer to CC1E description
*/
void TIM1_set_CC2E(U8 cc2e);
void TIM8_set_CC2E(U8 cc2e);

#define TIM1_enable_CC2()	TIM1_set_CC2E(1)	//通道2比较输出使能/捕获使能
#define TIM1_disable_CC2()	TIM1_set_CC2E(0)	//通道2比较输出除能/捕获除能 

#define TIM8_enable_CC2()	TIM8_set_CC2E(1)	//通道2比较输出使能/捕获使能
#define TIM8_disable_CC2()	TIM8_set_CC2E(0)	//通道2比较输出除能/捕获除能 


/*通道1比较互补输出极性
	该位用来选择极性
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	该位只用于输出比较模式
Bit 3 CC1NP: Capture/Compare 1 complementary output polarity
0: OC1N active high.
1: OC1N active low.
Note: This bit is not writable as soon as LOCK level 2 or 3 has been programmed (LOCK bits 
in TIMx_BDTR register) and CC1S=”00” (the channel is configured in output).
*/
void TIM1_set_CC1NP(U8 cc1np);
void TIM8_set_CC1NP(U8 cc1np);

#define TIM1_set_CC1N_polarity_high()	TIM1_set_CC1NP(0)	//设置通道1输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC1N_polarity_low()	TIM1_set_CC1NP(1)	//设置通道1输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC1N_polarity_high()	TIM8_set_CC1NP(0)	//设置通道1输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC1N_polarity_low()	TIM8_set_CC1NP(1)	//设置通道1输入(TIx)极性/输出(OxREF)极性低有效


/*通道1比较互补输出使能
	该位只用于比较模式
		0:输出比较的OCx极性为高
		1:输出比较的OCx极性为低
Bit 2 CC1NE: Capture/Compare 1 complementary output enable
0: Off - OC1N is not active. OC1N level is then function of MOE, OSSI, OSSR, OIS1, OIS1N 
and CC1E bits.
1: On - OC1N signal is output on the corresponding output pin depending on MOE, OSSI, 
OSSR, OIS1, OIS1N and CC1E bits.
*/
void TIM1_set_CC1NE(U8 cc1ne);
void TIM8_set_CC1NE(U8 cc1ne);

#define TIM1_enable_CC1N()	TIM1_set_CC1NE(1)	//通道1比较输出使能/捕获使能
#define TIM1_disable_CC1N()	TIM1_set_CC1NE(0)	//通道1比较输出除能/捕获除能 

#define TIM8_enable_CC1N()	TIM8_set_CC1NE(1)	//通道1比较输出使能/捕获使能
#define TIM8_disable_CC1N()	TIM8_set_CC1NE(0)	//通道1比较输出除能/捕获除能 

/*通道1捕获输入极性/比较输出极性
	该位用来选择极性
	输出比较时
		选择OCxREF的输出极性
			0：输出与OCxREF相同
			1: 输出与OCxREF相反
	输入捕获时
		选择ICx的输入极性
Bit 1 CC1P: Capture/Compare 1 output polarity
CC1 channel configured as output:
0: OC1 active high
1: OC1 active low
CC1 channel configured as input:
This bit selects whether IC1 or IC1 is used for trigger or capture operations.
0: non-inverted: capture is done on a rising edge of IC1. When used as external trigger, IC1 
is non-inverted.
1: inverted: capture is done on a falling edge of IC1. When used as external trigger, IC1 is 
inverted.
Note: This bit is not writable as soon as LOCK level 2 or 3 has been programmed (LOCK bits 
in TIMx_BDTR register).
*/
void TIM1_set_CC1P(U8 cc1p);
void TIM8_set_CC1P(U8 cc1p);

#define TIM1_set_CC1_polarity_high()	TIM1_set_CC1P(0)	//设置通道1输入(TIx)极性/输出(OxREF)极性高有效
#define TIM1_set_CC1_polarity_low()		TIM1_set_CC1P(1)	//设置通道1输入(TIx)极性/输出(OxREF)极性低有效

#define TIM8_set_CC1_polarity_high()	TIM8_set_CC1P(0)	//设置通道1输入(TIx)极性/输出(OxREF)极性高有效
#define TIM8_set_CC1_polarity_low()		TIM8_set_CC1P(1)	//设置通道1输入(TIx)极性/输出(OxREF)极性低有效

/*通道1的捕获使能和比较使能
	捕获模式
		捕获使能
	比较模式
		比较输出使能
	该位的作用根据CCxS(通道功能选择)位段决定
Bit 0 CC1E: Capture/Compare 1 output enable
CC1 channel configured as output:
0: Off - OC1 is not active. OC1 level is then function of MOE, OSSI, OSSR, OIS1, OIS1N 
and CC1NE bits.
1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI, 
OSSR, OIS1, OIS1N and CC1NE bits.
CC1 channel configured as input:
This bit determines if a capture of the counter value can actually be done into the input 
capture/compare register 1 (TIMx_CCR1) or not.
0: Capture disabled.
1: Capture enabled.
*/
void TIM1_set_CC1E(U8 cc1e);
void TIM8_set_CC1E(U8 cc1e);

#define TIM1_enable_CC1()	TIM1_set_CC1E(1)	//通道1比较输出使能/捕获使能
#define TIM1_disable_CC1()	TIM1_set_CC1E(0)	//通道1比较输出除能/捕获除能 

#define TIM8_enable_CC1()	TIM8_set_CC1E(1)	//通道1比较输出使能/捕获使能
#define TIM8_disable_CC1()	TIM8_set_CC1E(0)	//通道1比较输出除能/捕获除能 

/*******************************************************************/
/******************TIM1&TIM8 counter (TIMx_CNT)*********************/
/*******************************************************************/

/*TIM1&TIM8计数器当前值
TIM1&TIM8 counter (TIMx_CNT)
Address offset: 0x24
Reset value: 0x0000
*/

/*计数器的值有16位
Bits 15:0
CNT[15:0]: Counter value
*/
void TIM1_set_CNT(U16 cnt);
U16 TIM1_get_CNT(void);

void TIM8_set_CNT(U16 cnt);
U16 TIM8_get_CNT(void);

#define TIM1_set_counter(counter)	TIM1_set_CNT(counter)		//设置当前计数器的值
#define TIM1_get_counter()			TIM1_get_CNT()						//获取当前计数器的值


#define TIM8_set_counter(counter)	TIM8_set_CNT(counter)		//设置当前计数器的值
#define TIM8_get_counter()			TIM8_get_CNT()						//获取当前计数器的值

/*******************************************************************/
/****************TIM1&TIM8 prescaler (TIMx_PSC)*********************/
/*******************************************************************/

/*TIM1&TIM8分频配置
TIM1&TIM8 prescaler (TIMx_PSC)
Address offset: 0x28
Reset value: 0x0000
分频器是一个16位的计数器，其有一个装载寄存器，每当分频器的计数器计数到装
载计数器时输出一个CLK给COUNTER，并且分频器的计数器被清零。
装载寄存器有一个预装载寄存器, 对分频器的访问都是访问预装载寄存器，
只有在更新事件时预装载寄存器的值才进入装载寄存器(影子寄存器).
*/

/*分频器的预装载值
	设置此位段用来设置计数器的分频器的预装载值
	在发生更新事件时,预装载的值进入影子寄存器
Bits 15:0 PSC[15:0]: Prescaler value
The counter clock frequency (CK_CNT) is equal to fCK_PSC / (PSC[15:0] + 1).
PSC contains the value to be loaded in the active prescaler register at each update event 
(including when the counter is cleared through UG bit of TIMx_EGR register or through trigger 
controller when configured in “reset mode”).
*/
void TIM1_set_PSC(U16 psc);
U16 TIM1_get_PSC(void);

void TIM8_set_PSC(U16 psc);
U16 TIM8_get_PSC(void);

#define TIM1_set_counter_prescaler(p)	TIM1_set_PSC(p)	//设置计数器的分频器的预装载值
#define TIM1_get_counter_prescaler()	TIM1_get_PSC()	//获取计数器的分频器的与装载值

#define TIM8_set_counter_prescaler(p)	TIM8_set_PSC(p)	//设置计数器的分频器的预装载值
#define TIM8_get_counter_prescaler()	TIM8_get_PSC()	//获取计数器的分频器的与装载值

//****************************************************************//
//*******TIM1&TIM8 auto-reload register (TIMx_ARR)****************//
//****************************************************************//

/*TIM1&TIM8 自动重装载寄存器
	当计数器的值计数到此寄存器所设定的值时发生溢出事件(在边沿向上计数模式下)
		然后计数器的值清零
	当计数器的值变为0时，此寄存器的值被装载到计数器中(在边沿向下计数模式下)
	当计数器的值技术到此急促器的值减1时，发生溢出事件(在中心对称模式下计数)
		然后计数器的值被装载为该寄存器的值,并向下计数到1，产生下溢事件，然后
		计数器的值被清零,然后再向上计数
	
TIM1&TIM8 auto-reload register (TIMx_ARR)
Address offset: 0x2C
Reset value: 0x0000
*/
/* 自动重装载寄存器
	此寄存器器并非真正工作的寄存器，而只是真正工作的寄存器缓存寄存器。只有当
	除能了预装载功能时，向该计数器的写才会立即生效(立即传送到其正在工作的影子
	寄存器中),否则只有在发生更新事件时才会产生更新事件.
Bits 15:0 ARR[15:0]: auto-reload value
ARR is the value to be loaded in the actual auto-reload register.
Refer to the Section 13.3.1: Time-base unit on page 272 for more details about ARR update 
and behavior.
The counter is blocked while the auto-reload value is null.
*/
void TIM1_set_ARR(U16 arr);
U16 TIM1_get_ARR(void);

void TIM8_set_ARR(U16 arr);
U16 TIM8_get_ARR(void);

#define TIM1_set_counter_auto_reload(r)	TIM1_set_ARR(r)		//设置自动重装载寄存器
#define TIM1_get_counter_auto_reload()	TIM1_get_ARR()		//获取自动重装载寄存器

#define TIM8_set_counter_auto_reload(r)	TIM8_set_ARR(r)		//设置自动重装载寄存器
#define TIM8_get_counter_auto_reload()	TIM8_get_ARR()		//获取自动重装载寄存器


//*******************************************************************//
//*********TIM1&TIM8 repetition counter register (TIMx_RCR)**********//
//*******************************************************************//

/*重复计数器寄存器
	该计数器为递减计数器
	在主计数器每一次溢出时，该寄存器会自减一次，当该寄存器自减为0时，再发生一个
	主计数器溢出，则产生一个更新事件，并且该寄存器的值被填充为它的预装载寄存器。
TIM1&TIM8 repetition counter register (TIMx_RCR)
Address offset: 0x30
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved, always read as 0.
*/

/*重复计数器值
Bits 7:0 REP[7:0]: Repetition counter value
These bits allow the user to set-up the update rate of the compare registers (i.e. periodic 
transfers from preload to active registers) when preload registers are enable, as well as the 
update interrupt generation rate, if this interrupt is enable.
Each time the REP_CNT related downcounter reaches zero, an update event is generated and 
it restarts counting from REP value. As REP_CNT is reloaded with REP value only at the 
repetition update event U_RC, any write to the TIMx_RCR register is not taken in account until 
the next repetition update event.
It means in PWM mode (REP+1) corresponds to:
– the number of PWM periods in edge-aligned mode
– the number of half PWM period in center-aligned mode.
*/
void TIM1_set_REP(U8 rep);
U8	TIM1_get_REP(void);

void TIM8_set_REP(U8 rep);
U8	TIM8_get_REP(void);

#define TIM1_set_repetition_counter(r)	TIM1_set_REP(r)	//设置重复计数器的预装载值
#define TIM1_get_repetition_counter()	TIM1_get_REP()	//获取重复计数器的预装载值

#define TIM8_set_repetition_counter(r)	TIM8_set_REP(r)	//设置重复计数器的预装载值
#define TIM8_get_repetition_counter()	TIM8_get_REP()	//获取重复计数器的预装载值



//*******************************************************************//
//*********TIM1&TIM8 capture/compare register 1 (TIMx_CCR1)**********//
//*********TIM1&TIM8 capture/compare register 2 (TIMx_CCR2)**********//
//*********TIM1&TIM8 capture/compare register 3 (TIMx_CCR3)**********//
//*********TIM1&TIM8 capture/compare register 4 (TIMx_CCR4)**********//
//*******************************************************************//
/*
TIM1&TIM8 捕获/比较寄存器1 - 4(TIMx_CCR1-4)
TIM1&TIM8 capture/compare register 1 (TIMx_CCR1)
Address offset: 0x34, 0x38, 3C, 40
Reset value: 0x0000
*/
/*捕获/比较值
	捕获模式时:
		当发生捕获事件，计数器的值被捕获到该寄存器中(直接从其影子寄存器传送到这里)
	比较模式时:
		用来存储将会传输到其影子寄存器的数值。当OC1PE设置的话，只有在发生更新事件时,
		该寄存器的值才会传送到影子寄存器中(Active CCR1).

(x = 1-4])
Bits 15:0 CCRx[15:0]: Capture/Compare x value
If channel CCx is configured as output:
CCRx is the value to be loaded in the actual capture/compare x register (preload value).
It is loaded permanently if the preload feature is not selected in the TIMx_CCMRx register (bit 
OC1PE). Else the preload value is copied in the active capture/compare x register when an 
update event occurs.
The active capture/compare register contains the value to be compared to the counter 
TIMx_CNT and signaled on OC1 output.
If channel CCx is configured as input:
CCR1 is the counter value transferred by the last input capture 1 event (IC1).
*/

//TIMx_CCR1
void TIM1_set_CCR1(U16 ccr1);
U16 TIM1_get_CCR1(void);

void TIM8_set_CCR1(U16 ccr1);
U16 TIM8_get_CCR1(void);

//TIMx_CCR2
void TIM1_set_CCR2(U16 ccr2);
U16 TIM1_get_CCR2(void);

void TIM8_set_CCR2(U16 ccr2);
U16 TIM8_get_CCR2(void);

//TIMx_CCR3
void TIM1_set_CCR3(U16 ccr3);
U16 TIM1_get_CCR3(void);

void TIM8_set_CCR3(U16 ccr3);
U16 TIM8_get_CCR3(void);

//TIMx_CCR4
void TIM1_set_CCR4(U16 ccr4);
U16 TIM1_get_CCR4(void);

void TIM8_set_CCR4(U16 ccr4);
U16 TIM8_get_CCR4(void);


//***************************************************************//
//*******TIM1&TIM8 break and dead-time register (TIMx_BDTR)******//
//***************************************************************//
/*
TIM1&TIM8 刹车和死区寄存器
TIM1&TIM8 break and dead-time register (TIMx_BDTR)
Address offset: 0x44
Reset value: 0x0000
*/

/*
As the bits AOE, BKP, BKE, OSSI, OSSR and DTG[7:0] can be write-locked depending on 
the LOCK configuration, it can be necessary to configure all of them during the first write 
access to the TIMx_BDTR register.
*/

/*
主输出使能
	此位用来控制TIMx的输出使能
	当发生break事件时，此位被清零，输出立马停止
	此位存在的意义在于可以通过外部信号停止输出(刹车似地)
	此位只在通道被配置成输出模式时有效
Bit 15 MOE: Main output enable
This bit is cleared asynchronously by hardware as soon as the break input is active. It is set 
by software or automatically depending on the AOE bit. It is acting only on the channels 
which are configured in output.
0: OC and OCN outputs are disabled or forced to idle state.
1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in 
TIMx_CCER register).
See OC/OCN enable description for more details (Section 13.4.9: TIM1&TIM8 
capture/compare enable register (TIMx_CCER) on page 324).
*/
void TIM1_set_MOE(U8 moe);
void TIM8_set_MOE(U8 moe);

#define TIM1_enable_main_output()	TIM1_set_MOE(1)
#define TIM1_disable_main_output()	TIM1_set_MOE(0)

#define TIM8_enable_main_output()	TIM8_set_MOE(1)
#define TIM8_disable_main_output()	TIM8_set_MOE(0)


/*
Bit 14 AOE: Automatic output enable
0: MOE can be set only by software
1: MOE can be set by software or automatically at the next update event (if the break input is 
not be active)
Note: This bit can not be modified as long as LOCK level 1 has been programmed (LOCK bits 
in TIMx_BDTR register).
*/

/*
Bit 13 BKP: Break polarity
0: Break input BRK is active low
1: Break input BRK is active high
Note: This bit can not be modified as long as LOCK level 1 has been programmed (LOCK bits 
in TIMx_BDTR register).
Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective.
*/

/*
Bit 12 BKE: Break enable
0: Break inputs (BRK and CCS clock failure event) disabled
1; Break inputs (BRK and CCS clock failure event) enabled
Note: This bit cannot be modified when LOCK level 1 has been programmed (LOCK bits in 
TIMx_BDTR register).
Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective.
*/

/*
Bit 11 OSSR: Off-state selection for Run mode
This bit is used when MOE=1 on channels having a complementary output which are 
configured as outputs. OSSR is not implemented if no complementary output is implemented 
in the timer.
See OC/OCN enable description for more details (Section 13.4.9: TIM1&TIM8 
capture/compare enable register (TIMx_CCER) on page 324).
0: When inactive, OC/OCN outputs are disabled (OC/OCN enable output signal=0).
1: When inactive, OC/OCN outputs are enabled with their inactive level as soon as CCxE=1 
or CCxNE=1. Then, OC/OCN enable output signal=1
Note: This bit can not be modified as soon as the LOCK level 2 has been programmed (LOCK 
bits in TIMx_BDTR register).
*/

/*
Bit 10 OSSI: Off-state selection for Idle mode
This bit is used when MOE=0 on channels configured as outputs.
See OC/OCN enable description for more details (Section 13.4.9: TIM1&TIM8 
capture/compare enable register (TIMx_CCER) on page 324).
0: When inactive, OC/OCN outputs are disabled (OC/OCN enable output signal=0).
1: When inactive, OC/OCN outputs are forced first with their idle level as soon as CCxE=1 or 
CCxNE=1. OC/OCN enable output signal=1)
Note: This bit can not be modified as soon as the LOCK level 2 has been programmed (LOCK 
bits in TIMx_BDTR register).
*/

/*
Bits 9:8 LOCK[1:0]: Lock configuration
These bits offer a write protection against software errors.
00: LOCK OFF - No bit is write protected.
01: LOCK Level 1 = DTG bits in TIMx_BDTR register, OISx and OISxN bits in TIMx_CR2 
register and BKE/BKP/AOE bits in TIMx_BDTR register can no longer be written.
10: LOCK Level 2 = LOCK Level 1 + CC Polarity bits (CCxP/CCxNP bits in TIMx_CCER 
register, as long as the related channel is configured in output through the CCxS bits) as well 
as OSSR and OSSI bits can no longer be written.
11: LOCK Level 3 = LOCK Level 2 + CC Control bits (OCxM and OCxPE bits in 
TIMx_CCMRx registers, as long as the related channel is configured in output through the 
CCxS bits) can no longer be written.
Note: The LOCK bits can be written only once after the reset. Once the TIMx_BDTR register 
has been written, their content is frozen until the next reset.
*/

/*
Bits 7:0 DTG[7:0]: Dead-time generator setup
This bit-field defines the duration of the dead-time inserted between the complementary 
outputs. DT correspond to this duration.
DTG[7:5]=0xx => DT=DTG[7:0]x tdtg with tdtg=tDTS.
DTG[7:5]=10x => DT=(64+DTG[5:0])xtdtg with Tdtg=2xtDTS.
DTG[7:5]=110 => DT=(32+DTG[4:0])xtdtg with Tdtg=8xtDTS.
DTG[7:5]=111 => DT=(32+DTG[4:0])xtdtg with Tdtg=16xtDTS.
Example if TDTS=125ns (8MHz), dead-time possible values are:
0 to 15875 ns by 125 ns steps,
16 us to 31750 ns by 250 ns steps,
32 us to 63us by 1 us steps,
64 us to 126 us by 2 us steps
Note: This bit-field can not be modified as long as LOCK level 1, 2 or 3 has been programmed 
(LOCK bits in TIMx_BDTR register).
*/

//**************************************************************//
//**********TIM1&TIM8 DMA control register (TIMx_DCR)***********//
//**************************************************************//
//to do

//**************************************************************//
//***TIM1&TIM8 DMA address for full transfer (TIMx_DMAR)********//
//**************************************************************//
//to do

#endif 

