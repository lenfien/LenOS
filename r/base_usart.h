


#ifndef __USART1
#define __USART1
#include "com.h"
#include "core_map.h"


//*****************USART1寄存器定义**********************//
#define __USART1_SR		(USART1_BASE + 0x00000000)
#define __USART1_DR		(USART1_BASE + 0x00000004)
#define __USART1_BRR	(USART1_BASE + 0x00000008)
#define __USART1_CR1	(USART1_BASE + 0x0000000C)
#define __USART1_CR2 	(USART1_BASE + 0x00000010)
#define __USART1_CR3	(USART1_BASE + 0x00000014)
#define __USART1_GTPR 	(USART1_BASE + 0x00000018)

#define _USART1_SR		ADR(__USART1_SR)
#define _USART1_DR		ADR(__USART1_DR)
#define _USART1_BRR		ADR(__USART1_BRR)
#define _USART1_CR1		ADR(__USART1_CR1)		
#define _USART1_CR2 	ADR(__USART1_CR2)
#define _USART1_CR3		ADR(__USART1_CR3)
#define _USART1_GTPR 	ADR(__USART1_GTPR)


#define USART1_SR		VAL(__USART1_SR)
#define USART1_DR		VAL(__USART1_DR)
#define USART1_BRR		VAL(__USART1_BRR)
#define USART1_CR1		VAL(__USART1_CR1)		
#define USART1_CR2 		VAL(__USART1_CR2)
#define USART1_CR3		VAL(__USART1_CR3)
#define USART1_GTPR 	VAL(__USART1_GTPR)

//***************USART2寄存器定义***********************//
#define __USART2_SR		(USART2_BASE + 0x00000000)
#define __USART2_DR		(USART2_BASE + 0x00000004)
#define __USART2_BRR	(USART2_BASE + 0x00000008)
#define __USART2_CR1	(USART2_BASE + 0x0000000C)
#define __USART2_CR2 	(USART2_BASE + 0x00000010)
#define __USART2_CR3	(USART2_BASE + 0x00000014)
#define __USART2_GTPR 	(USART2_BASE + 0x00000018)


#define _USART2_SR		ADR(__USART2_SR)
#define _USART2_DR		ADR(__USART2_DR)
#define _USART2_BRR		ADR(__USART2_BRR)
#define _USART2_CR1		ADR(__USART2_CR1)		
#define _USART2_CR2 	ADR(__USART2_CR2)
#define _USART2_CR3		ADR(__USART2_CR3)
#define _USART2_GTPR 	ADR(__USART2_GTPR)

#define USART2_SR		VAL(__USART2_SR)
#define USART2_DR		VAL(__USART2_DR)
#define USART2_BRR		VAL(__USART2_BRR)
#define USART2_CR1		VAL(__USART2_CR1)		
#define USART2_CR2 		VAL(__USART2_CR2)
#define USART2_CR3		VAL(__USART2_CR3)
#define USART2_GTPR 	VAL(__USART2_GTPR)

//*******************USART3寄存器定义*****************//
#define __USART3_SR		(USART3_BASE + 0x00000000)
#define __USART3_DR		(USART3_BASE + 0x00000004)
#define __USART3_BRR	(USART3_BASE + 0x00000008)
#define __USART3_CR1	(USART3_BASE + 0x0000000C)
#define __USART3_CR2 	(USART3_BASE + 0x00000010)
#define __USART3_CR3	(USART3_BASE + 0x00000014)
#define __USART3_GTPR 	(USART3_BASE + 0x00000018)

#define _USART3_SR		ADR(__USART3_SR)
#define _USART3_DR		ADR(__USART3_DR)
#define _USART3_BRR		ADR(__USART3_BRR)
#define _USART3_CR1		ADR(__USART3_CR1)		
#define _USART3_CR2 	ADR(__USART3_CR2)
#define _USART3_CR3		ADR(__USART3_CR3)
#define _USART3_GTPR 	ADR(__USART3_GTPR)

#define USART3_SR		VAL(__USART3_SR)
#define USART3_DR		VAL(__USART3_DR)
#define USART3_BRR		VAL(__USART3_BRR)
#define USART3_CR1		VAL(__USART3_CR1)		
#define USART3_CR2 		VAL(__USART3_CR2)
#define USART3_CR3		VAL(__USART3_CR3)
#define USART3_GTPR 	VAL(__USART3_GTPR)



///****************************UASRT1_SR(状态寄存器)××××××××××××××××//
/*				  	对方是否准备好接收数据
说明: 在硬件流控制被启动后,该位的状态用来获取对方的RTS的状态(对方的RTS连接到本地的CTS引脚上)
当CTS线上的值翻转时,该位被设置.即,当对方的准备状态变换时,该位被置起.
			 
	CTS: CTS flag
	This bit is set by hardware when the nCTS input toggles,
	if the CTSE bit is set. It is cleared 
	by software (by writing it to 0). 
	An interrupt is generated if CTSIE=1 
	in the USART_CR3 register.
	0: No change occurred on the nCTS status line
	1: A change occurred on the nCTS status line
	This bit is not available for UART4 & UART5.
*/
U8 USART1_get_CTS(void);
void USART1_clear_CTS(void);

U8 USART2_get_CTS(void);
void USART2_clear_CTS(void);

U8 USART3_get_CTS(void);
void USART3_clear_CTS(void);



/*			     LIN网络break帧检测到
说明:在LIN(Local international network)模式下, 断开帧检测电路被打开, 并与USART的TX引脚独立工作,
当断开帧检测电路检测到TX引脚上连续输入低电平达到提前配置好的位数时,直到遇到下一个
定界符(高电平), USART才继续工作, 否则在检测到断开帧后USART停止接收数据,并且LBD位的设置只在定界符被检测
到后设置.
相关的文档说明:
If the LIN mode is enabled (LINEN=1), as soon as a framing error occurs (i.e. stop bit 
detected at ‘0’, which will be the case for any break frame), the receiver stops until the break 
detection circuit receives either a ‘1’, if the break word was not complete, or a delimiter 
character if a break has been detected.

	Bit 8 LBD: LIN break detection flag
	This bit is set by hardware when the LIN break is detected. It is cleared by software (by 
	writing it to 0). An interrupt is generated if LBDIE = 1 in the USART_CR2 register.
	0: LIN Break not detected
	1: LIN break detected
	Note: An interrupt is generated when LBD=1 if LBDIE=1
*/
U8 USART1_get_LBD(void);
void USART1_clear_LBD(void);

#define USART1_is_detect_break()	USART1_get_LBD()		//是否检测到断开帧
#define USART1_clear_break_flag()	USART1_clear_LBD()		//清除断开帧检测标志位

U8 USART2_get_LBD(void);
void USART2_clear_LBD(void);

#define USART2_is_detect_break()	USART2_get_LBD()
#define USART2_clear_break_flag()	USART2_clear_LBD()

U8 USART3_get_LBD(void);
void USART3_clear_LBD(void);

#define USART3_is_detect_break()	USART3_get_LBD()
#define USART3_clear_break_flag()	USART3_clear_LBD()


/*				   		发送寄存器状态(是否传送到移位寄存器上)
	Bit 7 TXE: Transmit data register empty
	This bit is set by hardware when the content of the TDR register has been transferred into 
	the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It 
	is cleared by a write to the USART_DR register.
	0: Data is not transferred to the shift register
	1: Data is transferred to the shift register)
	Note: This bit is used during single buffer transmission.
*/
U8 USART1_get_TXE(void) ;
void USART1_clear_TXE(void);

#define USART1_is_transmit_register_empty()	 				USART1_get_TXE()	//是否发送数据寄存器空
#define USART1_clear_transmit_register_empty_flag()			USART1_clear_TXE()	//清除发送寄存器空标志

#define USART1_is_interrupted_by_transmit_register_empty()	USART1_get_TXE()

U8 USART2_get_TXE(void) ;
void USART2_clear_TXE(void);

#define USART2_is_transmit_register_empty()	 				USART2_get_TXE()
#define USART2_clear_transmit_register_empty_flag()			USART2_clear_TXE()

#define USART2_is_interrupted_by_transmit_register_empty()	USART2_get_TXE()

U8 USART3_get_TXE(void) ;
void USART3_clear_TXE(void);

#define USART3_is_transmit_register_empty()	 USART3_get_TXE()
#define USART3_clear_transmit_register_empty_flag()	USART3_clear_TXE()

#define USART3_is_interrupted_by_transmit_register_empty()	USART3_get_TXE()

/*				  传送完毕标志
	Bit 6 TC: Transmission complete
	This bit is set by hardware if the transmission of a frame containing data is complete and if 
	TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a 
	software sequence (a read from the USART_SR register followed by a write to the 
	USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing 
	sequence is recommended only for multibuffer communication.
	0: Transmission is not complete
	1: Transmission is complete
*/

U8 USART1_get_TC(void);
void USART1_clear_TC(void);

#define USART1_is_transmit_complete()	USART1_get_TC()
#define USART1_is_interrupted_by_transmit_complete()	USART1_get_TC()
#define USART1_clear_transmit_complete_flag() USART1_clear_TC()

U8 USART2_get_TC(void);
void USART2_clear_TC(void);

#define USART2_is_transmit_complete()	USART2_get_TC()
#define USART2_is_interrupted_by_transmit_complete()	USART2_get_TC()
#define USART2_clear_transmit_complete_flag() USART2_clear_TC()


U8 USART3_get_TC(void);
void USART3_clear_TC(void);

#define USART3_is_transmit_complete()	USART3_get_TC()
#define USART3_is_interrupted_by_transmit_complete()	USART3_get_TC()
#define USART3_clear_transmit_complete_flag() USART3_clear_TC()


/*接收到数据标志
	Bit 5 RXNE: Read data register not empty
	This bit is set by hardware when the content of the RDR shift register has been transferred to 
	the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register. 
	It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by 
	writing a zero to it. This clearing sequence is recommended only for multibuffer 
	communication.
	0: Data is not received
	1: Received data is ready to be read.
*/
U8	USART1_get_RXNE(void);
void USART1_clear_RXNE(void);

#define USART1_is_received_data()						USART1_get_RXNE()
#define USART1_is_interrupted_by_received_data()		USART1_get_RXNE()

#define USART1_clear_received_data_flag()				USART1_clear_RXNE()

U8	USART2_get_RXNE(void);
void USART2_clear_RXNE(void);

#define USART2_is_received_data()						USART2_get_RXNE()
#define USART2_is_interrupted_by_received_data()		USART2_get_RXNE()

#define USART2_clear_received_data_flag()				USART2_clear_RXNE()


U8	USART3_get_RXNE(void);
void USART3_clear_RXNE(void);

#define USART3_is_received_data()						USART3_get_RXNE()
#define USART3_is_interrupted_by_received_data()		USART3_get_RXNE()

#define USART3_clear_received_data_flag()				USART3_clear_RXNE()

/*					空闲帧检测标志
	Bit 4 IDLE: IDLE line detected
	This bit is set by hardware when an Idle Line is detected. An interrupt is generated if the 
	IDLEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the 
	USART_SR register followed by a read to the USART_DR register). 
	0: No Idle Line is detected
	1: Idle Line is detected
	Note: The IDLE bit will not be set again until the RXNE bit has been set itself (i.e. a new idle 
	line occurs).
*/
U8	USART1_get_IDLE(void);
void USART1_clear_IDLE(void);
#define USART1_is_received_idle()	USART1_get_IDLE()
#define USART1_is_detected_idle()	USART1_get_IDLE()
#define USART1_clear_idle_flag() 	USART1_clear_IDLE()

U8	USART2_get_IDLE(void);
void USART2_clear_IDLE(void);
#define USART2_is_received_idle()	USART2_get_IDLE()
#define USART2_is_detected_idle()	USART2_get_IDLE()
#define USART2_clear_idle_flag() 	USART2_clear_IDLE()

U8	USART3_get_IDLE(void);
void USART3_clear_IDLE(void);
#define USART3_is_received_idle()	USART3_get_IDLE()
#define USART3_is_detected_idle()	USART3_get_IDLE()
#define USART3_clear_idle_flag() 	USART3_clear_IDLE()

/*					发送重叠错误标志
	Bit 3 ORE: Overrun error
	This bit is set by hardware when the word currently being received in the shift register is 
	ready to be transferred into the RDR register while RXNE=1. An interrupt is generated if 
	RXNEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the 
	USART_SR register followed by a read to the USART_DR register).
	0: No Overrun error
	1: Overrun error is detected
	Note: When this bit is set, the RDR register content will not be lost but the shift register will be 
	overwritten. An interrupt is generated on ORE flag in case of Multi Buffer 
	communication if the EIE bit is set.
*/
U8		USART1_get_ORE(void);
void 	USART1_clear_ORE(void); //通过读取SR和DR寄存器可清除

#define USART1_is_overrun_error_occured()		USART1_get_ORE()
#define USART1_clear_overrun_error()			USART1_clear_ORE()

U8		USART2_get_ORE(void);
void 	USART2_clear_ORE(void); //通过读取SR和DR寄存器可清除

#define USART2_is_overrun_error_occured()		USART2_get_ORE()
#define USART2_clear_overrun_error()			USART2_clear_ORE()

U8		USART3_get_ORE(void);
void 	USART3_clear_ORE(void); //通过读取SR和DR寄存器可清除

#define USART3_is_overrun_error_occured()		USART3_get_ORE()
#define USART3_clear_overrun_error()			USART3_clear_ORE()


/*				 噪音错误检测标志
	Bit 2 NE: Noise error flag
	This bit is set by hardware when noise is detected on a received frame. It is cleared by a 
	software sequence (an read to the USART_SR register followed by a read to the 
	USART_DR register).
	0: No noise is detected
	1: Noise is detected
	Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit 
	which itself generates an interrupting interrupt is generated on NE flag in case of Multi 
	Buffer communication if the EIE bit is set.
*/
U8 USART1_get_NE(void);
#define USART1_is_noise_error_occured()	USART1_get_NE()

U8 USART2_get_NE(void);
#define USART2_is_noise_error_occured()	USART2_get_NE()

U8 USART3_get_NE(void);
#define USART3_is_noise_error_occured()	USART3_get_NE()


/*				  传输中的帧错误检测标志
	Bit 1 FE: Framing error
	This bit is set by hardware when a de-synchronization, excessive noise or a break character 
	is detected. It is cleared by a software sequence (an read to the USART_SR register 
	followed by a read to the USART_DR register).
	0: No Framing error is detected
	1: Framing error or break character is detected
	Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit 
	which itself generates an interrupt. If the word currently being transferred causes both 
	frame error and overrun error, it will be transferred and only the ORE bit will be set.
	An interrupt is generated on FE flag in case of Multi Buffer communication if the EIE bit 
	is set.
*/

U8 USART1_get_FE(void);	
#define USART1_is_frame_error_occured()	USART1_get_FE()

U8 USART2_get_FE(void);	
#define USART2_is_frame_error_occured()	USART2_get_FE()

U8 USART3_get_FE(void);	
#define USART3_is_frame_error_occured()	USART3_get_FE()

/*		   		奇偶检测检测到错误 标志
	Bit 0 PE: Parity error
	This bit is set by hardware when a parity error occurs in receiver mode. It is cleared by a 
	software sequence (a read to the status register followed by a read to the USART_DR data 
	register). The software must wait for the RXNE flag to be set before clearing the PE bit.
	An interrupt is generated if PEIE = 1 in the USART_CR1 register.
	0: No parity error
	1: Parity error
*/
U8 USART1_get_PE(void);										
#define USART1_is_parity_error_occured()	USART1_get_PE()		//是否是奇偶性检测错误

U8 USART2_get_PE(void);										
#define USART2_is_parity_error_occured()	USART2_get_PE()		//是否是奇偶性检测错误

U8 USART3_get_PE(void);										
#define USART3_is_parity_error_occured()	USART3_get_PE()		//是否是奇偶性检测错误


//***************************Data register (USART_DR)****************************//


/*				 数据寄存器
	Bits 8:0 DR[8:0]: Data value
	Contains the Received or Transmitted data character, depending on whether it is read from 
	or written to.
	The Data register performs a double function (read and write) since it is composed of two 
	registers, one for transmission (TDR) and one for reception (RDR)
	The TDR register provides the parallel interface between the internal bus and the output 
	shift register (see Figure 1).
	The RDR register provides the parallel interface between the input shift register and the 
	internal bus.
	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register), the 
	value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect because 
	it is replaced by the parity.
	When receiving with the parity enabled, the value read in the MSB bit is the received parity 
	bit.
*/
U8		USART1_get_DR(void);
void	USART1_set_DR(U8 data);

#define USART1_read_data()		USART1_get_DR()
#define USART1_send_data(data)	USART1_set_DR(data)

U8		USART2_get_DR(void);
void	USART2_set_DR(U8 data);

#define USART2_read_data()		USART2_get_DR()
#define USART2_send_data(data)	USART2_set_DR(data)

U8		USART3_get_DR(void);
void	USART3_set_DR(U8 data);

#define USART3_read_data()		USART3_get_DR()
#define USART3_send_data(data)	USART3_set_DR(data)


//***********************USART_BRR(Baud rate Register)******************************//			

/*		  分频设置
	Bits 15:4 DIV_Mantissa[11:0]: mantissa of USARTDIV
	These 12 bits define the mantissa of the USART Divider (USARTDIV)
	Bits 3:0 DIV_Fraction[3:0]: fraction of USARTDIV
	These 4 bits define the fraction of the USART Divider (USARTDIV)
*/

void USART1_set_BRR(U16 mantissa, U16 fraction);
void USART1_set_div(float div);			//设置分频
float USART1_get_div(void);		

void USART2_set_BRR(U16 mantissa, U16 fraction);
void USART2_set_div(float div);			//设置分频
float USART2_get_div(void);		

void USART3_set_BRR(U16 mantissa, U16 fraction);
void USART3_set_div(float div);			//设置分频
float USART3_get_div(void);		

//****************************************8Control register 1 (USART_CR1)***************************//
/*
Bit 13 UE: USART enable		    通信模块使能
When this bit is cleared the USART prescalers and outputs are stopped and the end of the 
current
byte transfer in order to reduce power consumption. This bit is set and cleared by software.
0: USART prescaler and outputs disabled
1: USART enabled
*/
void USART1_set_enable(U8 e_d);

#define USART1_enable()		USART1_set_enable(1)
#define USART1_disable()	USART1_set_enable(0)

void USART2_set_enable(U8 e_d);

#define USART2_enable()		USART2_set_enable(1)
#define USART2_disable()	USART2_set_enable(0)

void USART3_set_enable(U8 e_d);

#define USART3_enable()		USART3_set_enable(1)
#define USART3_disable()	USART3_set_enable(0)


/*
Bit 12 M: Word length			 传送字长
This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit
Note: The M bit must not be modified during a data transfer (both transmission and reception)
*/
void USART1_set_M(U8 l);

#define USART1_set_word_length(mode) 	USART1_set_M(mode)
#define USART1_set_word_length_8_bit()	USART1_set_M(0)
#define USART1_set_word_length_9_bit()	USART1_set_M(1)

void USART2_set_M(U8 l);

#define USART2_set_word_length(mode) 	USART2_set_M(mode)
#define USART2_set_word_length_8_bit()	USART2_set_M(0)
#define USART2_set_word_length_9_bit()	USART2_set_M(1)

void USART3_set_M(U8 l);

#define USART3_set_word_length(mode) 	USART3_set_M(mode)
#define USART3_set_word_length_8_bit()	USART3_set_M(0)
#define USART3_set_word_length_9_bit()	USART3_set_M(1)


/*
Bit 11 WAKE: Wakeup method		   	唤醒条件选择
This bit determines the USART wakeup method, it is set or cleared by software.
0: Idle Line
1: Address Mark
*/
void USART1_set_WAKE(U8 w);

#define USART1_set_wakeup_method( w) 			USART1_set_WAKE(w)
#define USART1_set_wakeup_method_idle_line()	USART1_set_WAKE(0)
#define USART1_set_wakeup_method_address_mark()	USART1_set_WAKE(1)

void USART2_set_WAKE(U8 w);

#define USART2_set_wakeup_method( w) 			USART2_set_WAKE(w)
#define USART2_set_wakeup_method_idle_line()	USART2_set_WAKE(0)
#define USART2_set_wakeup_method_address_mark()	USART2_set_WAKE(1)

void USART3_set_WAKE(U8 w);

#define USART3_set_wakeup_method( w) 			USART3_set_WAKE(w)
#define USART3_set_wakeup_method_idle_line()	USART3_set_WAKE(0)
#define USART3_set_wakeup_method_address_mark()	USART3_set_WAKE(1)


/*
Bit 10 PCE: Parity control enable	 奇偶检测使能
This bit selects the hardware parity control (generation and detection). When the parity 
control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit 
if M=0) and parity is checked on the received data. This bit is set and cleared by software. 
Once it is set, PCE is active after the current byte (in reception and in transmission).
0: Parity control disabled
1: Parity control enabled
*/
void USART1_set_PCE(U8 p);
#define USART1_enable_parity_check()	USART1_set_PCE(1)	//使能奇偶检测
#define USART1_disable_parity_check()	USART1_set_PCE(0)	//除能奇偶检测

void USART2_set_PCE(U8 p);
#define USART2_enable_parity_check()	USART2_set_PCE(1)	//使能奇偶检测
#define USART2_disable_parity_check()	USART2_set_PCE(0)	//除能奇偶检测

void USART3_set_PCE(U8 p);
#define USART3_enable_parity_check()	USART3_set_PCE(1)	//使能奇偶检测
#define USART3_disable_parity_check()	USART3_set_PCE(0)	//除能奇偶检测

/*
Bit 9 PS: Parity selection			奇偶性选择
This bit selects the odd or even parity when the parity generation/detection is enabled (PCE 
bit set). It is set and cleared by software. The parity will be selected after the current byte.
0: Even parity
1: Odd parity
*/
void USART1_set_PS(U8 p);

#define USART1_set_parity_even()	USART1_set_PS(0)	 //选择偶检验
#define USART1_set_parity_odd()	USART1_set_PS(1)	 //选择奇检验

void USART2_set_PS(U8 p);

#define USART2_set_parity_even()	USART2_set_PS(0)	 //选择偶检验
#define USART2_set_parity_odd()	USART2_set_PS(1)	 //选择奇检验

void USART3_set_PS(U8 p);

#define USART3_set_parity_even()	USART3_set_PS(0)	 //选择偶检验
#define USART3_set_parity_odd()	USART3_set_PS(1)	 //选择奇检验

/*
Bit 8 PEIE: PE interrupt enable		奇偶检测中断使能
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever PE=1 in the USART_SR register
*/
void USART1_set_PEIE(U8 e_d);

#define USART1_enable_interrupt_at_parity_error()	USART1_set_PEIE(1)
#define USART1_disable_interrupt_at_parity_error()	USART1_set_PEIE(0)	

void USART2_set_PEIE(U8 e_d);

#define USART2_enable_interrupt_at_parity_error()	USART2_set_PEIE(1)
#define USART2_disable_interrupt_at_parity_error()	USART2_set_PEIE(0)	

void USART3_set_PEIE(U8 e_d);

#define USART3_enable_interrupt_at_parity_error()	USART3_set_PEIE(1)
#define USART3_disable_interrupt_at_parity_error()	USART3_set_PEIE(0)	

/*						当发送寄存器变空时(从发送寄存器到移位寄存器，还未到发送线上哦。。。)中断 使能
Bit 7 TXEIE: TXE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
*/
void USART1_set_TXEIE(U8 e_d);

#define USART1_enable_interrupt_at_transmit_register_empty()	USART1_set_TXEIE(1)
#define USART1_disable_interrupt_at_transmit_register_empty()	USART1_set_TXEIE(0)

void USART2_set_TXEIE(U8 e_d);

#define USART2_enable_interrupt_at_transmit_register_empty()	USART2_set_TXEIE(1)
#define USART2_disable_interrupt_at_transmit_register_empty()	USART2_set_TXEIE(0)

void USART3_set_TXEIE(U8 e_d);

#define USART3_enable_interrupt_at_transmit_register_empty()	USART3_set_TXEIE(1)
#define USART3_disable_interrupt_at_transmit_register_empty()	USART3_set_TXEIE(0)


/*						 发送完毕中断使能
Bit 6 TCIE: Transmission complete interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever TC=1 in the USART_SR register
*/

void USART1_set_TCIE(U8 e_d);

#define USART1_enable_interrupt_at_transmit_complete()	USART1_set_TCIE(1)
#define USART1_disable_interrupt_at_transmit_complete()	USART1_set_TCIE(0)

void USART2_set_TCIE(U8 e_d);

#define USART2_enable_interrupt_at_transmit_complete()	USART2_set_TCIE(1)
#define USART2_disable_interrupt_at_transmit_complete()	USART2_set_TCIE(0)

void USART3_set_TCIE(U8 e_d);

#define USART3_enable_interrupt_at_transmit_complete()	USART3_set_TCIE(1)
#define USART3_disable_interrupt_at_transmit_complete()	USART3_set_TCIE(0)


/*						接收到数据中断 使能
Bit 5 RXNEIE: RXNE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR 
register
*/
void USART1_set_RXNEIE(U8 e_d);

#define USART1_enable_interrupt_at_receive_data()	USART1_set_RXNEIE(1)
#define USART1_disable_interrupt_at_receive_data()	USART1_set_RXNEIE(0)

void USART2_set_RXNEIE(U8 e_d);

#define USART2_enable_interrupt_at_receive_data()	USART2_set_RXNEIE(1)
#define USART2_disable_interrupt_at_receive_data()	USART2_set_RXNEIE(0)

void USART3_set_RXNEIE(U8 e_d);

#define USART3_enable_interrupt_at_receive_data()	USART3_set_RXNEIE(1)
#define USART3_disable_interrupt_at_receive_data()	USART3_set_RXNEIE(0)

/*						接收到空闲帧中断 使能
Bit 4 IDLEIE: IDLE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever IDLE=1 in the USART_SR register
*/

void USART1_set_IDLEIE(U8 e_d) ;

#define USART1_enable_interrupt_at_receive_idle()	USART1_set_IDLEIE(1)
#define USART1_disable_interrupt_at_receive_idle()	USART1_set_IDLEIE(0)

void USART2_set_IDLEIE(U8 e_d) ;

#define USART2_enable_interrupt_at_receive_idle()	USART2_set_IDLEIE(1)
#define USART2_disable_interrupt_at_receive_idle()	USART2_set_IDLEIE(0)

void USART3_set_IDLEIE(U8 e_d) ;

#define USART3_enable_interrupt_at_receive_idle()	USART3_set_IDLEIE(1)
#define USART3_disable_interrupt_at_receive_idle()	USART3_set_IDLEIE(0)


/*
Bit 3 TE: Transmitter enable		发送使能
This bit enables the transmitter. It is set and cleared by software. 
0: Transmitter is disabled
1: Transmitter is enabled
Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble 
(idle line) after the current word, except in smartcard mode.
2: When TE is set there is a 1 bit-time delay before the transmission starts.
*/
void USART1_set_TE(U8 e_d);

#define USART1_enable_transmit()	USART1_set_TE(1)
#define USART1_disable_transmit()	USART1_set_TE(0)

void USART2_set_TE(U8 e_d);

#define USART2_enable_transmit()	USART2_set_TE(1)
#define USART2_disable_transmit()	USART2_set_TE(0)

void USART3_set_TE(U8 e_d);

#define USART3_enable_transmit()	USART3_set_TE(1)
#define USART3_disable_transmit()	USART3_set_TE(0)


/*
Bit 2 RE: Receiver enable		接收使能
This bit enables the receiver. It is set and cleared by software. 
0: Receiver is disabled
1: Receiver is enabled and begins searching for a start bit
*/
void USART1_set_RE(U8 e_d);

#define USART1_enable_receive()		USART1_set_RE(1)
#define USART1_disable_receive()	USART1_set_RE(0)

void USART2_set_RE(U8 e_d);

#define USART2_enable_receive()		USART2_set_RE(1)
#define USART2_disable_receive()	USART2_set_RE(0)

void USART3_set_RE(U8 e_d);

#define USART3_enable_receive()		USART3_set_RE(1)
#define USART3_disable_receive()	USART3_set_RE(0)

/*
Bit 1 RWU: Receiver wakeup	 静默模式使能
This bit determines if the USART is in mute mode or not. It is set and cleared by software and 
can be cleared by hardware when a wakeup sequence is recognized. 
0: Receiver in active mode
1: Receiver in mute mode
Note: 1: Before selecting Mute mode (by setting the RWU bit) the USART must first receive a 
data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection.
2: In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot 
be modified by software while the RXNE bit is set.
*/
void USART1_set_RWU(U8 e_d);

#define USART1_enter_mude_mode()	USART1_set_RWU(1)
#define	USART1_enter_active_mode()	USART1_set_RWU(0) 

void USART2_set_RWU(U8 e_d);

#define USART2_enter_mude_mode()	USART2_set_RWU(1)
#define	USART2_enter_active_mode()	USART2_set_RWU(0) 

void USART3_set_RWU(U8 e_d);

#define USART3_enter_mude_mode()	USART3_set_RWU(1)
#define	USART3_enter_active_mode()	USART3_set_RWU(0) 

/*
Bit 0 SBK: Send break		发送break帧
This bit set is used to send break characters. It can be set and cleared by software. It should 
be set by software, and will be reset by hardware during the stop bit of break.
0: No break character is transmitted
1: Break character will be transmitted
*/
void USART1_set_SBK(void);

#define USART1_send_break()	USART1_set_SBK()

void USART2_set_SBK(void);

#define USART2_send_break()	USART2_set_SBK()

void USART3_set_SBK(void);

#define USART3_send_break()	USART3_set_SBK()

//***********************************Control register 2 (USART_CR2)*********************//

/*
Bit 14 LINEN: LIN mode enable		  使能LIN模式
This bit is set and cleared by software.
0: LIN mode disabled
1: LIN mode enabled
The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK 
bit in the USART_CR1 register, and to detect LIN Sync breaks.
*/
void USART1_set_LINEN(U8 e_d) ;

#define USART1_enable_LIN()		USART1_set_LINEN(1)
#define USART1_disable_LIN()	USART1_set_LINEN(0)

void USART2_set_LINEN(U8 e_d) ;

#define USART2_enable_LIN()		USART2_set_LINEN(1)
#define USART2_disable_LIN()	USART2_set_LINEN(0)

void USART3_set_LINEN(U8 e_d) ;

#define USART3_enable_LIN()		USART3_set_LINEN(1)
#define USART3_disable_LIN()	USART3_set_LINEN(0)


/*
Bits 13:12 STOP: STOP bits			设置停止位
These bits are used for programming the stop bits.
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit
The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
*/
void USART1_set_STOP(U8 s);

#define USART1_set_stop_length(s)		USART1_set_STOP(s)
#define USART1_set_stop_length_1() 		USART1_set_STOP(0)	 	//1位停止位
#define USART1_set_stop_length_0_5()	USART1_set_STOP(1)	//0.5位停止位
#define USART1_set_stop_length_2()		USART1_set_STOP(2)	//2位
#define USART1_set_stop_length_1_5()	USART1_set_STOP(3)	//1.5位

void USART2_set_STOP(U8 s);

#define USART2_set_stop_length(s)		USART2_set_STOP(s)
#define USART2_set_stop_length_1() 		USART2_set_STOP(0)	 	//1位停止位
#define USART2_set_stop_length_0_5()	USART2_set_STOP(1)	//0.5位停止位
#define USART2_set_stop_length_2()		USART2_set_STOP(2)	//2位
#define USART2_set_stop_length_1_5()	USART2_set_STOP(3)	//1.5位

void USART3_set_STOP(U8 s);

#define USART3_set_stop_length(s)		USART3_set_STOP(s)
#define USART3_set_stop_length_1() 		USART3_set_STOP(0)	 	//1位停止位
#define USART3_set_stop_length_0_5()	USART3_set_STOP(1)	//0.5位停止位
#define USART3_set_stop_length_2()		USART3_set_STOP(2)	//2位
#define USART3_set_stop_length_1_5()	USART3_set_STOP(3)	//1.5位

								 	
/*
Bit 11 CLKEN: Clock enable		 使能时钟输出 在同步模式下使用
This bit allows the user to enable the CK pin.
0: CK pin disabled
1: CK pin enabled
This bit is not available for UART4 & UART5
*/
void USART1_set_CLKEN(U8 c) ;
#define USART1_enable_clock()	USART1_set_CLKEN(1)
#define USART1_disable_clock()	USART1_set_CLKEN(0)

void USART2_set_CLKEN(U8 c) ;
#define USART2_enable_clock()	USART2_set_CLKEN(1)
#define USART2_disable_clock()	USART2_set_CLKEN(0)

void USART3_set_CLKEN(U8 c) ;
#define USART3_enable_clock()	USART3_set_CLKEN(1)
#define USART3_disable_clock()	USART3_set_CLKEN(0)


/*
Bit 10 CPOL: Clock polarity	  输出时钟保持设置(高， 低)
This bit allows the user to select the polarity of the clock output on the CK pin in synchronous 
mode. It works in conjunction with the CPHA bit to produce the desired clock/data 
relationship 
0: Steady low value on CK pin outside transmission window.
1: Steady high value on CK pin outside transmission window.
This bit is not available for UART4 & UART5.
*/
void USART1_set_CPOL(U8 c);

#define USART1_set_clock_steady_low()	USART1_set_CPOL(0)
#define USART1_set_clock_steady_high()	USART1_set_CPOL(1)

void USART2_set_CPOL(U8 c);

#define USART2_set_clock_steady_low()	USART2_set_CPOL(0)
#define USART2_set_clock_steady_high()	USART2_set_CPOL(1)

void USART3_set_CPOL(U8 c);

#define USART3_set_clock_steady_low()	USART3_set_CPOL(0)
#define USART3_set_clock_steady_high()	USART3_set_CPOL(1)


/*
Bit 9 CPHA: Clock phase	  设置在第几个沿开始传送
This bit allows the user to select the phase of the clock output on the CK pin in synchronous 
mode. It works in conjunction with the CPOL bit to produce the desired clock/data 
relationship (see figures 289 to 290)
0: The first clock transition is the first data capture edge.
1: The second clock transition is the first data capture edge.
This bit is not available for UART4 & UART5.
*/
void USART1_set_CPHA(U8 c);

#define USART1_set_clock_transmit_at_first_edge()	USART1_set_CPHA(0);	
#define USART1_set_clock_transmit_at_second_edge()	USART1_set_CPHA(1);	

void USART2_set_CPHA(U8 c);

#define USART2_set_clock_transmit_at_first_edge()	USART2_set_CPHA(0);	
#define USART2_set_clock_transmit_at_second_edge()	USART2_set_CPHA(1);	

void USART3_set_CPHA(U8 c);

#define USART3_set_clock_transmit_at_first_edge()	USART3_set_CPHA(0);	
#define USART3_set_clock_transmit_at_second_edge()	USART3_set_CPHA(1);	


/*
Bit 8 LBCL: Last bit clock pulse		 MSB是否有脉冲支持
This bit allows the user to select whether the clock pulse associated with the last data bit 
transmitted (MSB) has to be output on the CK pin in synchronous mode. 
0: The clock pulse of the last data bit is not output to the CK pin
1: The clock pulse of the last data bit is output to the CK pin
The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected 
by the M bit in the USART_CR1 register.
This bit is not available for UART4 & UART5
*/
void USART1_set_LBCL(U8 l);

#define USART1_enable_clock_pulse_at_msb()	USART1_set_LBCL(1)
#define USART1_disable_clock_pulse_at_msb()	USART1_set_LBCL(0)

void USART2_set_LBCL(U8 l);

#define USART2_enable_clock_pulse_at_msb()	USART2_set_LBCL(1)
#define USART2_disable_clock_pulse_at_msb()	USART2_set_LBCL(0)

void USART3_set_LBCL(U8 l);

#define USART3_enable_clock_pulse_at_msb()	USART3_set_LBCL(1)
#define USART3_disable_clock_pulse_at_msb()	USART3_set_LBCL(0)


/*
Bit 6 LBDIE: LIN break detection interrupt enable 接收到Break是否帧产生中断
Break interrupt mask (break detection using break delimiter).
0: Interrupt is inhibited
1: An interrupt is generated whenever LBD=1 in the USART_SR registe
*/
void USART1_set_LBDIE(U8 e_d);

#define USART1_enable_interrupt_at_break()	USART1_set_LBDIE(1)
#define USART1_disable_interrupt_at_break()	USART1_set_LBDIE(0)

void USART2_set_LBDIE(U8 e_d);

#define USART2_enable_interrupt_at_break()	USART2_set_LBDIE(1)
#define USART2_disable_interrupt_at_break()	USART2_set_LBDIE(0)

void USART3_set_LBDIE(U8 e_d);

#define USART3_enable_interrupt_at_break()	USART3_set_LBDIE(1)
#define USART3_disable_interrupt_at_break()	USART3_set_LBDIE(0)


/*
Bit 5 LBDL: lin break detection length	Break帧的长度
This bit is for selection between 11 bit or 10 bit break detection.
0: 10 bit break detection
1: 11 bit break detection
*/
void USART1_set_LBDL(U8 l);

#define USART1_set_break_length(l) 		USART1_set_LBDL(l)
#define USART1_set_break_length_10()	USART1_set_LBDL(0)
#define USART1_set_break_length_11()	USART1_set_LBDL(1)

void USART2_set_LBDL(U8 l);

#define USART2_set_break_length(l) 		USART2_set_LBDL(l)
#define USART2_set_break_length_10()	USART2_set_LBDL(0)
#define USART2_set_break_length_11()	USART2_set_LBDL(1)


void USART3_set_LBDL(U8 l);

#define USART3_set_break_length(l) 		USART3_set_LBDL(l)
#define USART3_set_break_length_10()	USART3_set_LBDL(0)
#define USART3_set_break_length_11()	USART3_set_LBDL(1)


/*
Bits 3:0 ADD[3:0]: Address of the USART node	在互联模式下的地址
This bit-field gives the address of the USART node.
This is used in multiprocessor communication during mute mode, for wake up with address 
mark detection.
*/
void 	USART1_set_ADD(U8 add);
U8 		USART1_get_ADD(void) ;
#define USART1_set_address(add) 	USART1_set_ADD(add)
#define USART1_get_address()		USART1_get_ADD()

void 	USART2_set_ADD(U8 add);
U8 		USART2_get_ADD(void) ;
#define USART2_set_address(add) 	USART2_set_ADD(add)
#define USART2_get_address()		USART2_get_ADD()

void 	USART3_set_ADD(U8 add);
U8 		USART3_get_ADD(void) ;
#define USART3_set_address(add) 	USART3_set_ADD(add)
#define USART3_get_address()		USART3_get_ADD()

/*These 3 bits (CPOL, CPHA, LBCL) should not be written while the transmitter is enabled.*/


/*********************************Control register 3 (USART_CR3)*****************************/

/*
Bit 10 CTSIE: CTS interrupt enable	  CTS中断使能
0: Interrupt is inhibited
1: An interrupt is generated whenever CTS=1 in the USART_SR register
This bit is not available for UART4 & UART5.
*/
void USART1_set_CTSIE(U8 e_d);

#define USART1_enable_interrupt_at_CTS_toggle()	USART1_set_CTSIE(1)		//当CTS信号翻转时产生中断	
#define USART1_disable_interrupt_at_CTS_toggle()	USART1_set_CTSIE(0)	//当CTS信号翻转时不产生中断

void USART2_set_CTSIE(U8 e_d);

#define USART2_enable_interrupt_at_CTS_toggle()	USART2_set_CTSIE(1)		//当CTS信号翻转时产生中断	
#define USART2_disable_interrupt_at_CTS_toggle()	USART2_set_CTSIE(0)	//当CTS信号翻转时不产生中断

void USART3_set_CTSIE(U8 e_d);

#define USART3_enable_interrupt_at_CTS_toggle()	USART3_set_CTSIE(1)		//当CTS信号翻转时产生中断	
#define USART3_disable_interrupt_at_CTS_toggle()	USART3_set_CTSIE(0)	//当CTS信号翻转时不产生中断

/*
Bit 9 CTSE: CTS enable	   Clear To Send  获取到可否发送数据的信息
0: CTS hardware flow control disabled
1: CTS mode enabled, data is only transmitted when the nCTS input is asserted (tied to 0). If 
the nCTS input is deasserted while a data is being transmitted, then the transmission is 
completed before stopping. If a data is written into the data register while nCTS is deasserted, 
the transmission is postponed until nCTS is asserted.
This bit is not available for UART4 & UART5.
*/
void USART1_set_CTSE(U8 e_d);

#define USART1_enable_CTS()		USART1_set_CTSE(1)
#define USART1_disable_CTS()	USART1_set_CTSE(0)

void USART2_set_CTSE(U8 e_d);

#define USART2_enable_CTS()		USART2_set_CTSE(1)
#define USART2_disable_CTS()	USART2_set_CTSE(0)


void USART3_set_CTSE(U8 e_d);

#define USART3_enable_CTS()		USART3_set_CTSE(1)
#define USART3_disable_CTS()	USART3_set_CTSE(0)


/*
BIT 8 RTSE: RTS enable	   Request To Send 	请求发送使能
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer. 
The transmission of data is expected to cease after the current character has been 
transmitted. The nRTS output is asserted (tied to 0) when a data can be received.
This bit is not available for UART4 & UART5.
*/
void USART1_set_RTSE(U8 e_d);

#define USART1_enable_RTS()		USART1_set_RTSE(1)
#define USART1_disable_RTS()	USART1_set_RTSE(0)

void USART2_set_RTSE(U8 e_d);

#define USART2_enable_RTS()		USART2_set_RTSE(1)
#define USART2_disable_RTS()	USART2_set_RTSE(0)

void USART3_set_RTSE(U8 e_d);

#define USART3_enable_RTS()		USART3_set_RTSE(1)
#define USART3_disable_RTS()	USART3_set_RTSE(0)

/*
Bit 7 DMAT: DMA enable transmitter	DMA发送允许
This bit is set/reset by software
1: DMA mode is enabled for transmission
0: DMA mode is disabled for transmission
This bit is not available for UART5.
*/
void USART1_set_DMAT(U8 e_d);

#define USART1_enable_DMA_transmit()	USART1_set_DMAT(1)
#define USART1_disable_DMA_transmit()	USART1_set_DMAT(0)

void USART2_set_DMAT(U8 e_d);

#define USART2_enable_DMA_transmit()	USART2_set_DMAT(1)
#define USART2_disable_DMA_transmit()	USART2_set_DMAT(0)

void USART3_set_DMAT(U8 e_d);

#define USART3_enable_DMA_transmit()	USART3_set_DMAT(1)
#define USART3_disable_DMA_transmit()	USART3_set_DMAT(0)

/*
Bit 6 DMAR: DMA enable receiver		DMA接收允许
This bit is set/reset by software
1: DMA mode is enabled for reception
0: DMA mode is disabled for reception
This bit is not available for UART5.
*/
void USART1_set_DMAR(U8 e_d);

#define USART1_enable_DMA_receive()		USART1_set_DMAR(1)
#define USART1_disable_DMA_receive()	USART1_set_DMAR(0)

void USART2_set_DMAR(U8 e_d);

#define USART2_enable_DMA_receive()		USART2_set_DMAR(1)
#define USART2_disable_DMA_receive()	USART2_set_DMAR(0)

void USART3_set_DMAR(U8 e_d);

#define USART3_enable_DMA_receive()		USART3_set_DMAR(1)
#define USART3_disable_DMA_receive()	USART3_set_DMAR(0)


/*
Bit 5 SCEN: Smartcard mode enable	   使能Smartcard
This bit is used for enabling Smartcard mode.
0: Smartcard Mode disabled
1: Smartcard Mode enabled
This bit is not available for UART4 & UART5.
*/
void USART1_set_SCEN(U8 e_d);

#define USART1_enable_smartcard()	USART1_set_SCEN(1)
#define USART1_disable_smartcard()	USART1_set_SCEN(0)

void USART2_set_SCEN(U8 e_d);

#define USART2_enable_smartcard()	USART2_set_SCEN(1)
#define USART2_disable_smartcard()	USART2_set_SCEN(0)

void USART3_set_SCEN(U8 e_d);

#define USART3_enable_smartcard()	USART3_set_SCEN(1)
#define USART3_disable_smartcard()	USART3_set_SCEN(0)

/*
Bit 4 NACK: Smartcard NACK enable
0: NACK transmission in case of parity error is disabled
1: NACK transmission during parity error is enabled
This bit is not available for UART4 & UART5.

说明:使能该位会在Smartcard接收器接收到一个奇偶检测错误的帧在停止位时拉低总线一个位周期作为NACK信号
*/
void USART1_set_NACK(U8 e_d);
#define USART1_enable_NACK()	USART1_set_NACK(1)
#define USART1_disable_NACK()	USART1_set_NACK(0)

void USART2_set_NACK(U8 e_d);
#define USART2_enable_NACK()	USART2_set_NACK(1)
#define USART2_disable_NACK()	USART2_set_NACK(0)

void USART3_set_NACK(U8 e_d);
#define USART3_enable_NACK()	USART3_set_NACK(1)
#define USART3_disable_NACK()	USART3_set_NACK(0)


/*
Bit 3 HDSEL: Half-duplex selection
Selection of Single-wire Half-duplex mode 
0: Half duplex mode is not selected
1: Half duplex mode is selected 
半双工选择
*/

void USART1_set_HDSEL(U8 e_d);
#define USART1_enable_half_duplex()		USART1_set_HDSEL(1)
#define USART1_disable_half_duplex()	USART1_set_HDSEL(0)

void USART2_set_HDSEL(U8 e_d);
#define USART2_enable_half_duplex()		USART2_set_HDSEL(1)
#define USART2_disable_half_duplex()	USART2_set_HDSEL(0)

void USART3_set_HDSEL(U8 e_d);
#define USART3_enable_half_duplex()		USART3_set_HDSEL(1)
#define USART3_disable_half_duplex()	USART3_set_HDSEL(0)


/*
Bit 2 IRLP: IrDA low-power
This bit is used for selecting between normal and low-power IrDA modes
0: Normal mode
1: Low-power mode
红外传输的低电压模式使能
*/
void USART1_set_IRLP(U8 e_d);
#define USART1_enable_IrDA_low_power()		USART1_set_IRLP(1)
#define USART1_disalbe_IrDA_low_power()		USART1_set_LRLP(0)

void USART2_set_IRLP(U8 e_d);
#define USART2_enable_IrDA_low_power()		USART2_set_IRLP(1)
#define USART2_disalbe_IrDA_low_power()		USART2_set_LRLP(0)

void USART3_set_IRLP(U8 e_d);
#define USART3_enable_IrDA_low_power()		USART3_set_IRLP(1)
#define USART3_disalbe_IrDA_low_power()		USART3_set_LRLP(0)


/*
Bit 1 IREN: IrDA mode enable
This bit is set and cleared by software.
0: IrDA disabled
1: IrDA enabled
红外线通信模式使能
*/
void USART1_set_IREN(U8 e_d);
#define USART1_enable_IrDA()	USART1_set_IREN(1)
#define USART1_disable_IrDA()	USART1_set_IREN(0)

void USART2_set_IREN(U8 e_d);
#define USART2_enable_IrDA()	USART2_set_IREN(1)
#define USART2_disable_IrDA()	USART2_set_IREN(0)

void USART3_set_IREN(U8 e_d);
#define USART3_enable_IrDA()	USART3_set_IREN(1)
#define USART3_disable_IrDA()	USART3_set_IREN(0)
 

/*
Bit 0 EIE: Error interrupt enable
Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, 
overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of 
Multi Buffer Communication (DMAR=1 in the USART_CR3 register).
0: Interrupt is inhibited
1: An interrupt is generated whenever DMAR=1 in the USART_CR3 register and FE=1 or 
ORE=1 or NE=1 in the USART_SR register.
说明:在DMA连续通信模式下,帧错误,溢出错误,噪音错误会独立的导致中断,该位使能它.
*/
void USART1_set_EIE(U8 e_d);
#define USART1_enable_interrupt_at_DMA_error()	USART1_set_EIE(1)
#define USART1_disable_interrupt_at_DMA_error()	USART1_set_EIE(0)

void USART2_set_EIE(U8 e_d);
#define USART2_enable_interrupt_at_DMA_error()	USART2_set_EIE(1)
#define USART2_disable_interrupt_at_DMA_error()	USART2_set_EIE(0)

void USART3_set_EIE(U8 e_d);
#define USART3_enable_interrupt_at_DMA_error()	USART3_set_EIE(1)
#define USART3_disable_interrupt_at_DMA_error()	USART3_set_EIE(0)

//Guard time and prescaler register (USART_GTPR)


/*
Guard time and prescaler register (USART_GTPR)
Address offset: 0x18
Reset value: 0x0000
*/

/*
Bits 31:16 Reserved, forced by hardware to 0.
*/

/*
Bits 15:8 GT[7:0]: Guard time value
This bit-field gives the Guard time value in terms of number of baud clocks.
This is used in Smartcard mode. The Transmission Complete flag is set after this guard time 
value.
This bit is not available for UART4 & UART5.
说明:在Smartcard模式中,数据被发送完毕后,要等待Guardtime这个计数器计数到该位段设置的值才设置TC位.
*/
void USART1_set_GT(U8 gt);

void USART2_set_GT(U8 gt);

void USART3_set_GT(U8 gt);
/*
Bits 7:0 PSC[7:0]: Prescaler value
– In IrDA Low-power mode: 
PSC[7:0] = IrDA Low-Power Baud Rate
Used for programming the prescaler for dividing the system clock to achieve the low-power 
frequency:
The source clock is divided by the value given in the register (8 significant bits):
00000000: Reserved - do not program this value
00000001: divides the source clock by 1
00000010: divides the source clock by 2
... 
– In normal IrDA mode: PSC must be set to 00000001.
– In smartcard mode:
PSC[4:0]: Prescaler value
Used for programming the prescaler for dividing the system clock to provide the smartcard 
clock.
The value given in the register (5 significant bits) is multiplied by 2 to give the division factor 
of the source clock frequency:
00000: Reserved - do not program this value
00001: divides the source clock by 2
00010: divides the source clock by 4
00011: divides the source clock by 6
... 
Bits [7:5] have no effect if Smartcard mode is used.
This bit is not available for UART4 & UART5.
*/
void USART1_set_PSC(U8 psc);

void USART2_set_PSC(U8 psc);

void USART3_set_PSC(U8 psc);

#endif
