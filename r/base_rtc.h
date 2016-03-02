
/*
	此文档定义了stm32f103中与RTC相关的所有寄存器，和这些寄存器相关的操作。
	具体RTC配置原理请参考芯片手册16.

		
	必须设置RTC_CRL寄存器中的CNF位，使RTC进入配置模式后，才能写入RTC_PRL、
	RTC_CNT、RTC_ALR寄存器。 
	另外，对RTC任何寄存器的写操作，都必须在前一次写操作结束后进行。可以通过查询
	RTC_CR寄存器中的RTOFF状态位，判断RTC寄存器是否处于更新中。仅当RTOFF状态位是’1’
	时，才可以写入RTC寄存器。。

	软件通过APB1接口访问RTC的预分频值、计数器值和闹钟值。但是，相关的可读寄存器只在与
	RTC APB1时钟进行重新同步的RTC时钟的上升沿被更新。RTC标志也是如此的。 
	这意味着，如果APB1接口曾经被关闭，而读操作又是在刚刚重新开启APB1之后，则在第一次
	的内部寄存器更新之前，从APB1上读出的RTC寄存器数值可能被破坏了(通常读到0)。

Reading RTC registers
	The RTC core is completely independent from the RTC APB1 interface.
	Software accesses the RTC prescaler, counter and alarm values through the APB1 interface 
	but the associated readable registers are internally updated at each rising edge of the RTC 
	clock resynchronized by the RTC APB1 clock. This is also true for the RTC flags.
	This means that the first read to the RTC APB1 registers may be corrupted (generally read 
	as 0) if the APB1 interface has previously been disabled and the read occurs immediately 
	after the APB1 interface is enabled but before the first internal update of the registers. This 
	can occur if:
	●A system reset or power reset has occurred
	●The MCU has just woken up from Standby mode (see Section 4.3: Low-power modes)
	●The MCU has just woken up from Stop mode (see Section 4.3: Low-power modes)
	In all the above cases, the RTC core has been kept running while the APB1 interface was 
	disabled (reset, not clocked or unpowered).
	Consequently when reading the RTC registers, after having disabled the RTC APB1 
	interface, the software must first wait for the RSF bit (Register Synchronized Flag) in the 
	RTC_CRL register to be set by hardware. 
	Note that the RTC APB1 interface is not affected by WFI and WFE low-power modes.
	
	
Configuring RTC registers
	To write in the RTC_PRL(预分频器), RTC_CNT(计数器), RTC_ALR(闹钟) registers, 
	the peripheral must enter 
	Configuration Mode. This is done by setting the CNF bit in the RTC_CRL register.
	In addition, writing to any RTC register is only enabled if the previous write operation is 
	finished. To enable the software to detect this situation, the RTOFF status bit is provided in 
	the RTC_CR register to indicate that an update of the registers is in progress. A new value 
	can be written to the RTC registers only when the RTOFF status bit value is ’1’.
	Configuration procedure:
	1.Poll RTOFF, wait until its value goes to ‘1’
	2. Set the CNF bit to enter configuration mode
	3. Write to one or more RTC registers
	4. Clear the CNF bit to exit configuration mode
	5. Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
	The write operation only executes when the CNF bit is cleared; it takes at least three 
	RTCCLK cycles to complete.
*/

#ifndef __RTC
#define __RTC

#include "core_map.h"
#include "com.h"

#define __RTC_CRH	(RTC_BASE + 0x00000000)
#define __RTC_CRL	(RTC_BASE + 0x00000004)
#define __RTC_PRLH	(RTC_BASE + 0x00000008)
#define __RTC_PRLL	(RTC_BASE + 0x0000000C)
#define __RTC_DIVH	(RTC_BASE + 0x00000010)
#define __RTC_DIVL	(RTC_BASE + 0x00000014)
#define __RTC_CNTH	(RTC_BASE + 0x00000018)
#define __RTC_CNTL	(RTC_BASE + 0x0000001C)
#define __RTC_ALRH	(RTC_BASE + 0x00000020)
#define __RTC_ALRL	(RTC_BASE + 0x00000024)

#define _RTC_CRH	ADR(__RTC_CRH)	
#define _RTC_CRL	ADR(__RTC_CRL)	
#define _RTC_PRLH	ADR(__RTC_PRLH)	
#define _RTC_PRLL	ADR(__RTC_PRLL)	
#define _RTC_DIVH	ADR(__RTC_DIVH)	
#define _RTC_DIVL	ADR(__RTC_DIVL)	
#define _RTC_CNTH	ADR(__RTC_CNTH)
#define _RTC_CNTL	ADR(__RTC_CNTL)	
#define _RTC_ALRH	ADR(__RTC_ALRH)	
#define _RTC_ALRL	ADR(__RTC_ALRL)	

#define RTC_CRH		VAL(__RTC_CRH)	
#define RTC_CRL		VAL(__RTC_CRL)	
#define RTC_PRLH	VAL(__RTC_PRLH)	
#define RTC_PRLL	VAL(__RTC_PRLL)	
#define RTC_DIVH	VAL(__RTC_DIVH)	
#define RTC_DIVL	VAL(__RTC_DIVL)	
#define RTC_CNTH	VAL(__RTC_CNTH)
#define RTC_CNTL	VAL(__RTC_CNTL)	
#define RTC_ALRH	VAL(__RTC_ALRH)	
#define RTC_ALRL	VAL(__RTC_ALRL)


//*************************RTC_CRH***********************//
//注意:对该寄存器的写必须要在TROFF位为1时，此位定义在RTC_CRL寄存器中
/*
	OWIE：允许溢出中断位 (Overflow interrupt enable) 
	位2 
	0：屏蔽(不允许)溢出中断 
	1：允许溢出中断
*/
void RTC_set_OWIE(U8 enable_disable);

#define RTC_enable_interrupt_at_overflow()	RTC_set_OWIE(1)
#define RTC_disable_interrupt_at_overflow()	 RTC_set_OWIE(0)


/*
	ALRIE：允许闹钟中断 (Alarm interrupt enable) 
	位1 
	0：屏蔽(不允许)闹钟中断 
	1：允许闹钟中断 
*/
void RTC_set_ALRIE(U8 enable_disable);

#define RTC_enable_interrupt_at_alarm()		RTC_set_ALRIE(1)
#define RTC_disable_interrupt_at_alarm()	RTC_set_ALRIE(0)

/*
	SECIE：允许秒中断 (Second interrupt enable) 
	位0 
	0：屏蔽(不允许)秒中断 
	1：允许秒中断
*/
void RTC_set_SECIE(U8 enable_disable) ;

#define RTC_enable_interrupt_at_second() RTC_set_SECIE(1)
#define RTC_disable_interrupt_at_second() RTC_set_SECIE(0)

//*************************RTC_CRL*******************************//
/*
	RTOFF：RTC操作关闭 (RTC operation OFF) 
	位5 
	RTC模块利用这位来指示对其寄存器进行的最后一次操作的状态，指示操作是否完成。若此位
	为’0’，则表示无法对任何的RTC寄存器进行写操作。此位为只读位。 
	0：上一次对RTC寄存器的写操作仍在进行; 
	1：上一次对RTC寄存器的写操作已经完成。
*/
#define RTC_get_RTOFF()				(__get_bit(RTC_CRL, 5))

#define RTC_is_operation_done()		RTC_get_RTOFF()	//是否上一次的操作完成

#define RTC_wait_operation_done() 	while(!RTC_is_operation_done()) 

/*
	CNF：配置标志 (Configuration flag) 
	位4 
	此位必须由软件置’1’以进入配置模式，从而允许向RTC_CNT、RTC_ALR或RTC_PRL寄存器
	写入数据。只有当此位在被置’1’并重新由软件清’0’后，才会执行写操作。 
	0：退出配置模式(开始更新RTC寄存器)； 
	1：进入配置模式。
*/
void RTC_set_CNF(U8 conf);

#define RTC_enter_configure_mode()	RTC_set_CNF(1)
#define RTC_exit_configure_mode()	RTC_set_CNF(0)


/*
	RSF：寄存器同步标志 (Registers synchronized flag) 
	位3 
	每当RTC_CNT寄存器和RTC_DIV寄存器由软件更新或清’0’时，此位由硬件置’1’。在APB1复位
	后，或APB1时钟停止后，此位必须由软件清’0’。要进行任何的读操作之前，用户程序必须等待
	这位被硬件置’1’，以确保RTC_CNT、RTC_ALR或RTC_PRL已经被同步。 
	0：寄存器尚未被同步； 
	1：寄存器已经被同步。
*/	
#define RTC_get_RSF()	(__get_bit(RTC_CRL, 3))
#define RTC_clear_RSF(conf)	(__clear_bit(_RTC_CRL,  3))

#define RTC_is_sync()		RTC_get_RSF()	//RTC内寄存器是否已经和APB1总线时钟同步

#define RTC_wait_sync()		while(!RTC_is_sync())
/*
	OWF：溢出标志 (Overflow flag) 
	位2 
	当32位可编程计数器溢出时，此位由硬件置’1’。如果RTC_CRH寄存器中OWIE=1，则产生中
	断。此位只能由软件清’0’。对此位写’1’是无效的。 
	0：无溢出； 
	1：32位可编程计数器溢出。 
*/
#define RTC_get_OWF()	(__get_bit(RTC_CRL, 2))
#define RTC_clear_OWF()	(__clear_bit(_RTC_CRL,  2))

#define RTC_is_overflow()	RTC_get_OWF()	//RTC是否溢出
#define RTC_clear_overflow_flag()	RTC_clear_OWF()


/*
	ALRF：闹钟标志 (Alarm flag) 
	位1 
	当32位可编程计数器达到RTC_ALR寄存器所设置的预定值，此位由硬件置’1’。如果RTC_CRH
	寄存器中ALRIE=1，则产生中断。此位只能由软件清’0’。对此位写’1’是无效的。 
	0：无闹钟； 
	1：有闹钟。
*/
#define RTC_get_ALRF() 			(__get_bit(RTC_CRL, 1))
#define RTC_clear_ALRF()			(__clear_bit(_RTC_CRL, 1))

#define RTC_is_alarm()			RTC_get_ALRF()
#define RTC_clear_alarm_flag()	RTC_clear_ALRF()


/*
	SECF：秒标志 (Second flag) 
	位0 
	当32位可编程预分频器溢出时，此位由硬件置’1’同时RTC计数器加1。因此，此标志为分辨率可
	编程的RTC计数器提供一个周期性的信号(通常为1秒)。如果RTC_CRH寄存器中SECIE=1，则
	产生中断。此位只能由软件清除。对此位写’1’是无效的。 
	0：秒标志条件不成立； 
	1：秒标志条件成立。
*/
#define RTC_get_SECF()		(__get_bit(RTC_CRL, 0))
#define RTC_clear_SECF()	(__clear_bit(_RTC_CRL, 0))

#define RTC_is_second()			RTC_get_SECF()		//是否有秒
#define RTC_clear_second_flag()		RTC_clear_SECF()	//清除秒标志



//**************************RTC预分频装载寄存器(RTC_PRLH/RTC_PRLL)****************************//
/*
	PRL[19:16]：RTC预分频装载值高位 (RTC prescaler reload value high) 
	位3:0 
	根据以下公式，这些位用来定义计数器的时钟频率： 
	fTR_CLK = fRTCCLK/(PRL[19:0]+1) 
	注：不推荐使用0值，否则无法正确的产生RTC中断和标志位。

	PRL[15:0]：RTC预分频装载值低位 
	位15:0 
	根据以下公式，这些位用来定义计数器的时钟频率： 
	fTR_CLK = fRTCCLK/(PRL[19:0]+1)
*/
void RTC_set_PRL(U32 div);

#define RTC_set_prescaler(div) RTC_set_PRL(div)


//*****************RTC预分频器余数寄存器(RTC_DIVH / RTC_DIVL)*************************//
/*
	寄存器介绍:
	在TR_CLK的每个周期里，RTC预分频器中计数器的值都会被重新设置为RTC_PRL寄存器的
	值。用户可通过读取RTC_DIV寄存器，以获得预分频计数器的当前值，而不停止分频计数器的
	工作，从而获得精确的时间测量。此寄存器是只读寄存器，其值在RTC_PRL或RTC_CNT寄存
	器中的值发生改变后，由硬件重新装载。
*/
U32	RTC_get_DIV(void);


//**************RTC计数器寄存器 (RTC_CNTH / RTC_CNTL) ****************************////
/*
	寄存器介绍:
	RTC核有一个32位可编程的计数器，可通过两个16位的寄存器访问。计数器以预分频器产生的
	TR_CLK时间基准为参考进行计数。RTC_CNT寄存器用来存放计数器的计数值。他们受
	RTC_CR的位RTOFF写保护，仅当RTOFF值为’1’时，允许写操作。在高或低寄存器
	(RTC_CNTH或RTC_CNTL)上的写操作，能够直接装载到相应的可编程计数器，并且重新装载
	RTC预分频器。当进行读操作时，直接返回计数器内的计数值(系统时间)。
*/
/*
	RTC_CNT[31:16]：RTC计数器高位 (RTC counter high) 
	位15:0 
	可通过读RTC_CNTH寄存器来获得RTC计数器当前值的高位部分。要对此寄存器进行写操作
	前，必须先进入配置模式(参见16.3.4节)。

	位15:0 
	可通过读RTC_CNTL寄存器来获得RTC计数器当前值的低位部分。要对此寄存器进行写操作，
	必须先进入配置模式(参见16.3.4节)
*/
#define	RTC_get_CNT() (((RTC_CNTH&0xFFFF)<<16) | (RTC_CNTL&0xFFFF))

//设置CNT
void RTC_set_CNT(U32 time);


#define RTC_get_system_time()		RTC_get_CNT()			//获得系统时间
#define RTC_set_system_time(time)	RTC_set_CNT(time)	//设置系统时间

//******************RTC闹钟寄存器(RTC_ALRH/RTC_ALRL) *****************************//

/*
	当可编程计数器的值与RTC_ALR中的32位值相等时，即触发一个闹钟事件，并且产生RTC闹钟
	中断。此寄存器受RTC_CR寄存器里的RTOFF位写保护，仅当RTOFF值为’1’时，允许写操作。
*/
/*
	RTC_ALR[31:16]：RTC闹钟值高位 (RTC alarm high) 
	位15:0 
	此寄存器用来保存由软件写入的闹钟时间的高位部分。要对此寄存器进行写操作，必须先进入
	配置模式(参见16.3.4节)
	RTC_ALR[15:0]：RTC闹钟值低位 (RTC alarm low) 
	位15:0 
	此寄存器用来保存由软件写入的闹钟时间的低位部分。要对此寄存器进行写操作，必须先进入
	配置模式(参见16.3.4节)。 
*/
void 	RTC_set_ALR(U32 alarm);
#define RTC_set_alarm_time(alarm) RTC_set_ALR(alarm)


#endif
