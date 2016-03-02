

/*
	���ĵ��ﶨ���˸߼���ʱ��TIM1��8��ʹ�õ������мĴ������Ͷ���Щ�Ĵ����Ļ���������
	TIM1_8��оƬ�ֲ��13������ϸ������
*/

#ifndef __TIM18
#define __TIM18

#include "com.h"
#include "core_map.h"

//*********************************************TIM1�Ĵ�������**********************************************//
//TIM1�Ĵ�������ַ����
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


//TIM1�Ĵ���ת��Ϊ��ַ
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


//TIM1�Ĵ���ת��Ϊֵ
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

//*********************************************TIM8�Ĵ�������************************************//
//TIM8�Ĵ����Ķ���
//����ַ
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


//TIM8�Ĵ���ת��Ϊ��ַ
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


//TIM8�Ĵ���ת��Ϊֵ
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
/*TIM1&TIM8 ���ƼĴ���1
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

/*�Զ���װԤװ��ʹ��λ
	���ø�λ�ᵼ�¼��������Զ���װ����������һ�������¼�����ʱװ������Ӱ�ӼĴ���
Bit 7 ARPE: Auto-reload preload enable
0: TIMx_ARR register is not buffered
1: TIMx_ARR register is buffered
*/
void TIM1_set_ARPE(U8 e_d);
void TIM8_set_ARPE(U8 e_d);

#define TIM1_enable_ARR_preload()	TIM1_set_ARPE(1)	//TIM1���������Զ���װ��ʹ��Ԥװ�ع���
#define TIM1_disable_ARR_preload()	TIM1_set_ARPE(0)	//TIM1���������Զ���װ�س���Ԥװ�ع���

#define TIM8_enable_ARR_preload()	TIM8_set_ARPE(1)	//TIM8���������Զ���װ��ʹ��Ԥװ�ع���
#define TIM8_disable_ARR_preload()	TIM8_set_ARPE(0)	//TIM8���������Զ���װ�س���Ԥװ�ع���


/*�������������Ķ���ģʽѡ��
	���ø�λ����ѡ��������ļ�������
	����λ��ȫΪ00ʱ���������ļ���������DIRλ����
	���򣬼������ļ��������Ķ����
	��������Ϊ���Ķ������ʱ������Ƚ��¼��ں�ʱ������01, 10, 11ѡ��
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

#define TIM1_set_edge_align_mode()		TIM1_set_CMS(0)		//���ü������ڱ��ؼ���ģʽ�¹���
#define TIM1_set_center_align_mode1()	TIM1_set_CMS(1)		//���ü����������Ķ���ģʽ1�¹���(�Ƚ��жϷ��������¼���ʱ)
#define TIM1_set_center_align_mode2()	TIM1_set_CMS(2)		//���ü����������Ķ���ģʽ2�¹���(�Ƚ��жϷ��������ϼ���ʱ)
#define TIM1_set_center_align_mode3()	TIM1_set_CMS(3)		//���ü����������Ķ���ģʽ1�¹���(�Ƚ��жϷ��������¼���ʱ)

#define TIM8_set_edge_align_mode()		TIM8_set_CMS(0)		//���ü������ڱ��ؼ���ģʽ�¹���
#define TIM8_set_center_align_mode1()	TIM8_set_CMS(1)		//���ü����������Ķ���ģʽ1�¹���(�Ƚ��жϷ��������¼���ʱ)
#define TIM8_set_center_align_mode2()	TIM8_set_CMS(2)		//���ü����������Ķ���ģʽ2�¹���(�Ƚ��жϷ��������ϼ���ʱ)
#define TIM8_set_center_align_mode3()	TIM8_set_CMS(3)		//���ü����������Ķ���ģʽ1�¹���(�Ƚ��жϷ��������¼���ʱ)


/*������������������
	��������Ϊ���ض���ģʽ����ʱ(CMS=00)��DIRλ�ſ��Ա�д��
	���������Ӳ�����ã����ֻ���Զ���
Bit 4 DIR: Direction
0: Counter used as upcounter
1: Counter used as downcounter
Note: This bit is read only when the timer is configured in Center-aligned mode or Encoder 
mode.
*/
void TIM1_set_DIR(U8 dir);
void TIM8_set_DIR(U8 dir);

#define TIM1_set_counter_direction_up()		TIM1_set_DIR(0)		//TIM1�����ڱ���ģʽʱΪ���ϼ���
#define TIM1_set_counter_direction_down()	TIM1_set_DIR(1)		//TIM1�����ڱ���ģʽʱΪ���¼���

#define TIM8_set_counter_direction_up()		TIM8_set_DIR(0)		//TIM8�����ڱ���ģʽʱΪ���ϼ���
#define TIM8_set_counter_direction_down()	TIM8_set_DIR(1)		//TIM8�����ڱ���ģʽʱΪ���¼���

/*������ģʽ
	�������˸�λ�󣬼������ڲ���һ����������¼���ֹͣ����(CENλ��Ӳ������)
Bit 3 OPM: One pulse mode
0: Counter is not stopped at update event
1: Counter stops counting at the next update event (clearing the bit CEN)
*/
void TIM1_set_OPM(U8 opm);
void TIM8_set_OPM(U8 opm);

#define TIM1_enable_one_pulse_mode()	TIM1_set_OPM(1)		//�����������ڵ�����ģʽ��
#define TIM1_disalbe_one_pulse_mode()	TIM1_set_OPM(0)		//����������������ģʽ��

#define TIM8_enable_one_pulse_mode()	TIM8_set_OPM(1)		//�����������ڵ�����ģʽ��
#define TIM8_disalbe_one_pulse_mode()	TIM8_set_OPM(0)		//����������������ģʽ��


/*�����¼�����Դѡ��
	��λ����ѡ������¼��Ĵ���Դ
	����Դ��:
		�������������
		����UGλ
		��ģʽ����������
Bit 2 URS: Update request source
This bit is set and cleared by software to select the UEV event sources.
0: Any of the following events generate an update interrupt or DMA request if enabled. 
These events can be: 
�CCounter overflow/underflow
�CSetting the UG bit
�CUpdate generation through the slave mode controller
1: Only counter overflow/underflow generates an update interrupt or DMA request if 
enabled.
*/
void TIM1_set_URS(U8 urs);
void TIM8_set_URS(U8 urs);

#define TIM1_set_update_source_any()		TIM1_set_URS(0)	//����TIM1�ĸ����¼�ԴΪ ��λ��˵��
#define TIM1_set_update_source_overflow()	TIM1_set_URS(1)	//����TIM1�ĸ����¼�ԴΪ �������

#define TIM8_set_update_source_any()		TIM8_set_URS(0)	//����TIM8�ĸ����¼�ԴΪ ��λ��˵��
#define TIM8_set_update_source_overflow()	TIM8_set_URS(1)	//����TIM8�ĸ����¼�ԴΪ �������

/*��ֹ�����¼�����
	��ֹ�����¼���ARR,PSC,CCRx��Ԥװ��װ�ؼĴ�����ֵ�����ܽ�����Ӱ�ӼĴ���
	����ARR��ֻ��������Ԥװ��ʱ�������¼��ŻὫԤװ�ص�ֵװ��Ӱ�ӼĴ�������ʱ
	��λ�Ż����á�����ARR��ֵ���ڸ�һ������Ԥװ�ؼĴ����������Ӱ�ӼĴ�������ʱ
	��λ���á�
Bit 1 UDIS: Update disable
This bit is set and cleared by software to enable/disable UEV event generation.
0: UEV enabled. The Update (UEV) event is generated by one of the following events:
�CCounter overflow/underflow
�CSetting the UG bit
�CUpdate generation through the slave mode controller
Buffered registers are then loaded with their preload values.
1: UEV disabled. The Update event is not generated, shadow registers keep their value 
(ARR, PSC, CCRx). However the counter and the prescaler are reinitialized if the UG bit is 
set or if a hardware reset is received from the slave mode controller.
*/
void TIM1_set_UDIS(U8 udis);
void TIM8_set_UDIS(U8 udis);

#define TIM1_enable_update_event()	TIM1_set_UDIS(0)	//TIM1��������¼�����
#define TIM1_disable_update_event()	TIM1_set_UDIS(1)	//TIM1��ֹ�����¼�����

#define TIM8_enable_update_event()	TIM8_set_UDIS(0)	//TIM8��������¼�����
#define TIM8_disable_update_event()	TIM8_set_UDIS(1)	//TIM8��ֹ�����¼�����

/*������ʹ��λ
	ʹ�ܼ������󣬼������Ὺʼ�������ڼ��������п��ܻᷢ��:
		����¼�(��������ֵ�������)
		�����¼�(���ⲿ����һ������)
		�Ƚ��¼�(CCRx��ֵ��COUNTER��ֵ���ʱ)
Bit 0 CEN: Counter enable
0: Counter disabled
1: Counter enabled
Note: External clock, gated mode and encoder mode can work only if the CEN bit has been 
previously set by software. However trigger mode can set the CEN bit automatically by 
hardware.
*/
void TIM1_set_CEN(U8 cen);
void TIM8_set_CEN(U8 cen);

#define TIM1_enable_counter()	TIM1_set_CEN(1)		//ʹ�ܼ�����,��������ʼ����
#define TIM1_disable_counter()	TIM1_set_CEN(0)		//���ܼ�����,������ֹͣ����

#define TIM8_enable_counter()	TIM8_set_CEN(1)		//ʹ�ܼ�����,��������ʼ����
#define TIM8_disable_counter()	TIM8_set_CEN(0)		//���ܼ�����,������ֹͣ����


//*********************************************************************//
//**************TIM1&TIM8 control register 2 (TIMx_CR2)****************//
//*********************************************************************//
/*TIM1&TIM8���ƼĴ���2
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

/*ͨ��1����ѡ��
	1ͨ�����������������
		������Channel1����
		CH1 ��CH2��CH3�������
Bit 7 TI1S: TI1 selection
0: The TIMx_CH1 pin is connected to TI1 input
1: The TIMx_CH1, CH2 and CH3 pins are connected to the TI1 input (XOR combination)
*/
void TIM1_set_TI1S(U8 ti1s);
void TIM8_set_TI1S(U8 ti1s);

#define TIM1_set_TI1_input_CH1()	TIM1_set_TI1S(0)		//TIM1��CHANNEL1���뵽TI1		
#define TIM1_set_TI1_input_XOR()	TIM1_set_TI1S(1)		//TIM1��CHANNEL1 XOR CH2 XOR CH3���뵽 TI1

#define TIM8_set_TI1_input_CH1()	TIM8_set_TI1S(0)		//TIM8��CHANNEL1���뵽TI1		
#define TIM8_set_TI1_input_XOR()	TIM8_set_TI1S(1)		//TIM8��CHANNEL1 XOR CH2 XOR CH3���뵽 TI1


/*��ģʽѡ��
	��ǰ������������TRGO���Դ�������ģ��
	TRGO��������TIM�Ķ���ط�
	�⼸λ��������ѡ��TRGO����Դ
		UGλΪTRGO�����
		CNT_ENλΪTRGO�����
		Update�¼�����һ��TRGO���
		Compare��:
			OC1REF
			OC2REF
			OC3REF
			OC4REF
		��ΪTRGO�����
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

#define TIM1_set_TRGO_as_UG()				TIM1_set_MMS(0)		//TRGO����ΪUGλ�����
#define TIM1_set_TRGO_as_EN()				TIM1_set_MMS(1)		//TRGO����ΪCNT_ENλ�����
#define TIM1_set_TRGO_as_update()			TIM1_set_MMS(2)		//TRGO����Ϊupdate�¼������(��һ�������)
#define TIM1_set_TRGO_as_compare_pulse()	TIM1_set_MMS(3)		//�Ƚ�/�����¼�����ʱ����һ�����������TRGO
#define TIM1_set_TRGO_as_compare_OC1REF()	TIM1_set_MMS(4)		//�Ƚ�ͨ����OC1REF��ΪTRGO�����
#define TIM1_set_TRGO_as_compare_OC2REF()	TIM1_set_MMS(5)		//�Ƚ�ͨ����OC2REF��ΪTRGO�����
#define TIM1_set_TRGO_as_compare_OC3REF()	TIM1_set_MMS(6)		//�Ƚ�ͨ����OC3REF��ΪTRGO�����
#define TIM1_set_TRGO_as_compare_OC4REF()	TIM1_set_MMS(7)		//�Ƚ�ͨ����OC4REF��ΪTRGO�����

#define TIM8_set_TRGO_as_UG()				TIM8_set_MMS(0)		//TRGO����ΪUGλ�����
#define TIM8_set_TRGO_as_EN()				TIM8_set_MMS(1)		//TRGO����ΪCNT_ENλ�����
#define TIM8_set_TRGO_as_update()			TIM8_set_MMS(2)		//TRGO����Ϊupdate�¼������(��һ�������)
#define TIM8_set_TRGO_as_compare_pulse()	TIM8_set_MMS(3)		//�Ƚ�/�����¼�����ʱ����һ�����������TRGO
#define TIM8_set_TRGO_as_compare_OC1REF()	TIM8_set_MMS(4)		//�Ƚ�ͨ����OC1REF��ΪTRGO�����
#define TIM8_set_TRGO_as_compare_OC2REF()	TIM8_set_MMS(5)		//�Ƚ�ͨ����OC2REF��ΪTRGO�����
#define TIM8_set_TRGO_as_compare_OC3REF()	TIM8_set_MMS(6)		//�Ƚ�ͨ����OC3REF��ΪTRGO�����
#define TIM8_set_TRGO_as_compare_OC4REF()	TIM8_set_MMS(7)		//�Ƚ�ͨ����OC4REF��ΪTRGO�����


/*��ʲôʱ����DMA����
	����update�¼�ʱ����DMA����
	�������벶���Ƚ��¼�����DMA����
Bit 3 CCDS: Capture/compare DMA selection
0: CCx DMA request sent when CCx event occurs
1: CCx DMA requests sent when update event occurs
*/
void TIM1_set_CCDS(U8 ccds);
void TIM8_set_CCDS(U8 ccds);

#define TIM1_DMA_request_send_when_cc_event()		TIM1_set_CCDS(0)	//�������Ƚϲ���ʱ��ʱ����DMA����
#define TIM1_DMA_request_send_when_update_event()	TIM1_set_CCDS(1)	//�����������¼�ʱ����DMA����

#define TIM8_DMA_request_send_when_cc_event()		TIM8_set_CCDS(0)	//�������Ƚϲ���ʱ��ʱ����DMA����
#define TIM8_DMA_request_send_when_update_event()	TIM8_set_CCDS(1)	//�����������¼�ʱ����DMA����

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
/*TIM1&TIM8��ģʽ���ƼĴ���
TIM1&TIM8 slave mode control register (TIMx_SMCR)
Address offset: 0x08
Reset value: 0x0000
*/

/*�ⲿ�ź�EXR���뼫��ѡ��
	����ģʽ��������ʱ��Դѡ��ΪEXR(ECE = 1),COUNTER��ʱ����
	EXR��������
	��λ����ѡ��EXR�����뼫�ԣ���ȷ��COUNTER�ں�ʱ����
Bit 15 ETP: External trigger polarity
This bit selects whether ETR or ETR is used for trigger operations
0: ETR is non-inverted, active at high level or rising edge.
1: ETR is inverted, active at low level or falling edge.
*/
void TIM1_set_ETP(U8 etp);
void TIM8_set_ETP(U8 etp);

#define TIM1_set_EXR_polarity_high()	TIM1_set_ETP(0)		//�ⲿ�������ŵļ���Ϊ��(����ת)
#define TIM1_set_EXR_polarity_low()		TIM1_set_ETP(1)		//�ⲿ�������ŵļ���Ϊ��(��ת)

#define TIM8_set_EXR_polarity_high()	TIM8_set_ETP(0)		//�ⲿ�������ŵļ���Ϊ��(����ת)
#define TIM8_set_EXR_polarity_low()		TIM8_set_ETP(1)		//�ⲿ�������ŵļ���Ϊ��(��ת)

/*�ⲿʱ��ģʽ2ʹ��
�ⲿʱ��EXR����ʹ��λ
	�������˸�λ����������ʱ����EXR�ⲿ��������.
	EXR�����Ⱦ�������ѡ���پ�����Ƶ�����پ����˲�����Ȼ��Ŵ���COUNTER���м���.
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

#define TIM1_enable_external_clock_mode_2()		TIM1_set_ECE(1)	//�ⲿETR����Filter������Counter
#define TIM1_disable_external_clock_mode_2()	TIM1_set_ECE(0)	//��ֹETR����Counter

#define TIM8_enable_external_clock_mode_2()		TIM8_set_ECE(1)	//�ⲿETR����Filter������Counter
#define TIM8_disable_external_clock_mode_2()	TIM8_set_ECE(0)	//��ֹETR����Counter


/*�ⲿEXR�����Ƶ
	��������ECEλ����������ʱ����EXR�ⲿ��������.
	EXR�����Ⱦ�������ѡ���پ�����Ƶ�����پ����˲�����Ȼ��Ŵ���COUNTER���м���.
	��λ���������÷�Ƶ���ķ�Ƶ
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

#define TIM1_set_ETR_prescaler_1()	TIM1_set_ETPS(0)	//�ⲿETR���벻��Ƶ
#define TIM1_set_ETR_prescaler_2()	TIM1_set_ETPS(1)	//�ⲿETR����2��Ƶ
#define TIM1_set_ETR_prescaler_4()	TIM1_set_ETPS(2)	//�ⲿETR����4��Ƶ
#define TIM1_set_ETR_prescaler_8()	TIM1_set_ETPS(3)	//�ⲿETR����8��Ƶ

#define TIM8_set_ETR_prescaler_1()	TIM8_set_ETPS(0)	//�ⲿETR���벻��Ƶ
#define TIM8_set_ETR_prescaler_2()	TIM8_set_ETPS(1)	//�ⲿETR����2��Ƶ
#define TIM8_set_ETR_prescaler_4()	TIM8_set_ETPS(2)	//�ⲿETR����4��Ƶ
#define TIM8_set_ETR_prescaler_8()	TIM8_set_ETPS(3)	//�ⲿETR����8��Ƶ


/*�ⲿETR�����˲�
	��������ECEλ����������ʱ����EXR�ⲿ��������.
	EXR�����Ⱦ�������ѡ���پ�����Ƶ�����پ����˲�����Ȼ��Ŵ���COUNTER���м���.
	��λ�����������˲������˲�ϵ��
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


/*��/��ģʽ
	����λ�����ú󣬵�ǰ�ļ������ڻ�ȡ��һ��TRGI����ʱ�Ӻ���һ���ӳ٣������������ñ�����TRGO
	�����Ĵ�TIMER����ͬ����

Bit 7 MSM: Master/slave mode
0: No action
1: The effect of an event on the trigger input (TRGI) is delayed to allow a perfect 
synchronization between the current timer and its slaves (through TRGO). It is useful if we 
want to synchronize several timers on a single external event.
*/
void TIM1_set_MSM(void);
void TIM8_set_MSM(void);

/*����Դѡ��
	��λ������ѡ�����뵽��ģʽ������TRGI�˵��ź�Դ
	����Դ������źŻ����뵽��ģʽ��������TRGI�����Դ�ģʽ���������뱻���ó��ⲿʱ��ģʽ1�ſ���
	���յ�������
	��ѡ���� 000 - 011ʱ��TRGI�ź������ڲ�����ʱ�ӵ�TRGO,��Ӧ��ϵ����:
	SlaveTim | ITR0 | ITR1 |	ITR2 | ITR3 |
	TIM1	 | TIM5 | TIM2 |	TIM3 | TIM4 |
	TIM8	 | TIM1 | TIM2 |	TIM4 | TIM5 |

Bits 6:4 TS[2:0]: Trigger selection
This bit-field selects the trigger input to be used to synchronize the counter.
000: Internal Trigger 0 (ITR0) 
001: Internal Trigger 1 (ITR1)
010: Internal Trigger 2 (ITR2)
011: Internal Trigger 3 (ITR3)
100: TI1 Edge Detector 	(TI1F_ED)		//TI1F_Rising��TI1F_Falling���߼���(Ӧ��ʼ��Ϊ1)
101: Filtered Timer Input 1 (TI1FP1)	
110: Filtered Timer Input 2 (TI2FP2)
111: External Trigger input (ETRF)		//�ⲿ����
See Table 80: TIMx Internal trigger connection on page 315 for more details on ITRx meaning 
for each Timer.
Note: These bits must be changed only when they are not used (e.g. when SMS=000) to 
avoid wrong edge detections at the transition.
*/
void TIM1_set_TS(U8 ts);
void TIM8_set_TS(U8 ts);

#define TIM1_set_trigger_source_ITR0()		TIM1_set_TS(0)	//��������ԴΪ�ڲ�TIM5��TRGO
#define TIM1_set_trigger_source_ITR1()		TIM1_set_TS(1)	//��������ԴΪ�ڲ�TIM2��TRGO
#define TIM1_set_trigger_source_ITR2()		TIM1_set_TS(2)	//��������ԴΪ�ڲ�TIM3��TRGO
#define TIM1_set_trigger_source_ITR3()		TIM1_set_TS(3)	//��������ԴΪ�ڲ�TIM4��TRGO
#define TIM1_set_trigger_source_TI1()		TIM1_set_TS(4)	//��������ԴΪͨ��1�������ػ��½���(�����м��Լ��)
#define TIM1_set_trigger_source_TI1FP1()	TIM1_set_TS(5)	//��������ԴΪ����ͨ��1�����˲����Լ�����ź�
#define TIM1_set_trigger_source_TI1FP2()	TIM1_set_TS(6)	//��������ԴΪ����ͨ��2�����˲����Լ�����ź�
#define TIM1_set_trigger_source_ETRF()		TIM1_set_TS(7)	//��������ԴΪ�ⲿ���뾭���˲��ͷ�Ƶ�ͼ���ѡ����ֵ


#define TIM8_set_trigger_source_ITR0()		TIM8_set_TS(0)	//��������ԴΪ�ڲ�TIM5��TRGO
#define TIM8_set_trigger_source_ITR1()		TIM8_set_TS(1)	//��������ԴΪ�ڲ�TIM2��TRGO
#define TIM8_set_trigger_source_ITR2()		TIM8_set_TS(2)	//��������ԴΪ�ڲ�TIM3��TRGO
#define TIM8_set_trigger_source_ITR3()		TIM8_set_TS(3)	//��������ԴΪ�ڲ�TIM4��TRGO
#define TIM8_set_trigger_source_TI1()		TIM8_set_TS(4)	//��������ԴΪͨ��1�������ػ��½���(�����м��Լ��)
#define TIM8_set_trigger_source_TI1FP1()	TIM8_set_TS(5)	//��������ԴΪ����ͨ��1�����˲����Լ�����ź�
#define TIM8_set_trigger_source_TI1FP2()	TIM8_set_TS(6)	//��������ԴΪ����ͨ��2�����˲����Լ�����ź�
#define TIM8_set_trigger_source_ETRF()		TIM8_set_TS(7)	//��������ԴΪ�ⲿ���뾭���˲��ͷ�Ƶ�ͼ���ѡ����ֵ


/*
Bit 3 Reserved, always read as 0.
*/

/*��ģʽѡ��(����)
	�Դ�ģʽ�������Ĺ���ģʽ����ѡ��
		����
		������ģʽ1
		������ģʽ2
		������ģʽ3
		��λģʽ
			�ڸ�λģʽ�£�ÿһ��TRGI�����뽫����:
				�������ͷ�Ƶ����ֵ������װ��,
				һ�������¼��Ĳ���(���URSλ�����ģʽ���Ʋ��������¼��Ļ�)
		�ſ�ģʽ
			�ſ�ģʽ�£���������ʱ������CENλ��TGRI��ͬ����,��CENΪ1ʱ��TRGI
			�����˼������ļ�������ʱ�������ļ���ʱ����CNT_CLK�ṩ��
		����ģʽ
			��TRGI����һ�������壬��������ʼ����,����CENλ��Ӳ����1��
		�ⲿʱ��ģʽ1
			�ڸ�ģʽ�£��������ļ���ʱ����TRGI����������.
				
Bits 2:0 SMS: Slave mode selection
When external signals are selected the active edge of the trigger signal (TRGI) is linked to 
the polarity selected on the external input (see Input Control register and Control Register 
description.
000: Slave mode disabled - if CEN = ��1�� then the prescaler is clocked directly by the internal 
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
(TS=��100��). Indeed, TI1F_ED outputs 1 pulse for each transition on TI1F, whereas the 
gated mode checks the level of the trigger signal.
*/
void TIM1_set_SMS(U8 sms);
void TIM8_set_SMS(U8 sms);

#define TIM1_disable_slave_mode()				TIM1_set_SMS(0)		//�رմ�ģʽ����������������ʱ�����ڲ�ʱ���ṩ
#define TIM1_set_slave_inside_clock()			TIM1_disable_slave_mode()
#define TIM1_set_slave_encoder_mode_1()			TIM1_set_SMS(1)		//��ģʽ����������Ϊ������ģʽ1
#define TIM1_set_slave_encoder_mode_2()			TIM1_set_SMS(2)		//��ģʽ����������Ϊ������ģʽ2
#define TIM1_set_slave_encoder_mode_3()			TIM1_set_SMS(3)		//��ģʽ����������Ϊ������ģʽ3
#define TIM1_set_slave_reset_mode()				TIM1_set_SMS(4)		//��ģʽ����������Ϊ��λģʽ(ÿ����һ�����帴λһ��)
#define TIM1_set_slave_gated_mode()				TIM1_set_SMS(5)		//��ģʽ����������Ϊ�ſ�ģʽ(������ֻ���ſ��ź���Чʱ���ڲ�ʱ�Ӽ���),ע��:CNT_CENһ��ҪΪ1
#define TIM1_set_slave_trigger_mode()			TIM1_set_SMS(6)		//��ģʽ����������Ϊ����ģʽ(�������Ŀ�ʼʱ���ⲿEXR������)��ע��:CNT_CEN����ҪΪ1
#define TIM1_set_slave_external_clock_mode_1() 	TIM1_set_SMS(7)		////��ģʽ����������Ϊ�ⲿʱ��ģʽ1

#define TIM8_disable_slave_mode()				TIM8_set_SMS(0)		//�رմ�ģʽ����������������ʱ�����ڲ�ʱ���ṩ
#define TIM8_set_slave_encoder_mode_1()			TIM8_set_SMS(1)		//��ģʽ����������Ϊ������ģʽ1
#define TIM8_set_slave_encoder_mode_2()			TIM8_set_SMS(2)		//��ģʽ����������Ϊ������ģʽ2
#define TIM8_set_slave_encoder_mode_3()			TIM8_set_SMS(3)		//��ģʽ����������Ϊ������ģʽ3
#define TIM8_set_slave_reset_mode()				TIM8_set_SMS(4)		//��ģʽ����������Ϊ��λģʽ(ÿ����һ�����帴λһ��)
#define TIM8_set_slave_gated_mode()				TIM8_set_SMS(5)		//��ģʽ����������Ϊ�ſ�ģʽ(������ֻ���ſ��ź���Чʱ���ڲ�ʱ�Ӽ���),ע��:CNT_CENһ��ҪΪ1
#define TIM8_set_slave_trigger_mode()			TIM8_set_SMS(6)		//��ģʽ����������Ϊ����ģʽ(�������Ŀ�ʼʱ���ⲿEXR������)��ע��:CNT_CEN����ҪΪ1
#define TIM8_set_slave_external_clock_mode_1() 	TIM8_set_SMS(7)		////��ģʽ����������Ϊ�ⲿʱ��ģʽ1



//*******************************************************//
//**TIM1&TIM8 DMA/interrupt enable register (TIMx_DIER)**//
//*******************************************************//
/*TIM1&TIM8 DMA/�ж�ʹ�ܼĴ���
TIM1&TIM8 DMA/interrupt enable register (TIMx_DIER)
Address offset: 0x0C
Reset value: 0x0000
*/
/*
Bit 15 Reserved, always read as 0.
*/

/*����DMA����ʹ��
	��TRGI����һ����Ч����ʱ����DMA����
	����ģʽ�����������ó��ſ�ģʽʱ��ʱ�ӵ�������ض������һ��DMA����
	��λֻ���ڴ�ģʽδ������ʱ������
Bit 14 TDE: Trigger DMA request enable
0: Trigger DMA request disabled
1: Trigger DMA request enabled
*/
void TIM1_set_TDE(U8 tde);
void TIM8_set_TDE(U8 tde);

#define TIM1_enable_DMA_request_at_trigger()	TIM1_set_TDE(1)		//��TRGI����һ������ʱ,����һ��DMA����
#define TIM1_disable_DMA_request_at_trigger()	TIM1_set_TDE(0)		//TRGI����һ����Ч����ʱ,DMA���󲻻ᷢ��

#define TIM8_enable_DMA_request_at_trigger()	TIM8_set_TDE(1)		//��TRGI����һ������ʱ,����һ��DMA����
#define TIM8_disable_DMA_request_at_trigger()	TIM8_set_TDE(0)		//TRGI����һ����Ч����ʱ,DMA���󲻻ᷢ��


/*Bit 13 COMDE: COM DMA request enable
0: COM DMA request disabled
1: COM DMA request enabled
*/
//to do

/*����Ƚ�ͨ��4DMA����ʹ��
	��ͨ��4����������߱Ƚ��¼�ʱ������һ��DMA����
Bit 12 CC4DE: Capture/Compare 4 DMA request enable
0: CC4 DMA request disabled
1: CC4 DMA request enabled
*/
void TIM1_set_CC4DE(U8 cc4de);
void TIM8_set_CC4DE(U8 cc4de);


#define TIM1_enable_DMA_request_at_CC4_event()	TIM1_set_CC4DE(1)	//ͨ��4�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM1_disable_DMA_request_at_CC4_event()	TIM1_set_CC4DE(0)	//ͨ��4�ڷ����Ƚ�/�����¼�ʱ������DMA����

#define TIM8_enable_DMA_request_at_CC4_event()	TIM8_set_CC4DE(1)	//ͨ��4�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM8_disable_DMA_request_at_CC4_event()	TIM8_set_CC4DE(0)	//ͨ��4�ڷ����Ƚ�/�����¼�ʱ������DMA����


/*����Ƚ�ͨ��3DMA����ʹ��
Bit 11 CC3DE: Capture/Compare 3 DMA request enable
0: CC3 DMA request disabled
1: CC3 DMA request enabled
*/
void TIM1_set_CC3DE(U8 cc3de);
void TIM8_set_CC3DE(U8 cc3de);

#define TIM1_enable_DMA_request_at_CC3_event()	TIM1_set_CC3DE(1)	//ͨ��3�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM1_disable_DMA_request_at_CC3_event()	TIM1_set_CC3DE(0)	//ͨ��3�ڷ����Ƚ�/�����¼�ʱ������DMA����

#define TIM8_enable_DMA_request_at_CC3_event()	TIM8_set_CC3DE(1)	//ͨ��3�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM8_disable_DMA_request_at_CC3_event()	TIM8_set_CC3DE(0)	//ͨ��3�ڷ����Ƚ�/�����¼�ʱ������DMA����


/*����Ƚ�ͨ��2DMA����ʹ�� 
Bit 10 CC2DE: Capture/Compare 2 DMA request enable
0: CC2 DMA request disabled
1: CC2 DMA request enabled
*/
void TIM1_set_CC2DE(U8 cc2de);
void TIM8_set_CC2DE(U8 cc2de);

#define TIM1_enable_DMA_request_at_CC2_event()	TIM1_set_CC2DE(1)	//ͨ��2�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM1_disable_DMA_request_at_CC2_event()	TIM1_set_CC2DE(0)	//ͨ��2�ڷ����Ƚ�/�����¼�ʱ������DMA����

#define TIM8_enable_DMA_request_at_CC2_event()	TIM8_set_CC2DE(1)	//ͨ��2�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM8_disable_DMA_request_at_CC2_event()	TIM8_set_CC2DE(0)	//ͨ��2�ڷ����Ƚ�/�����¼�ʱ������DMA����


/*����Ƚ�ͨ��1DMA����ʹ��
Bit 9 CC1DE: Capture/Compare 1 DMA request enable
0: CC1 DMA request disabled
1: CC1 DMA request enabled
*/
void TIM1_set_CC1DE(U8 cc1de);
void TIM8_set_CC1DE(U8 cc1de);

#define TIM1_enable_DMA_request_at_CC1_event()	TIM1_set_CC1DE(1)	//ͨ��1�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM1_disable_DMA_request_at_CC1_event()	TIM1_set_CC1DE(0)	//ͨ��1�ڷ����Ƚ�/�����¼�ʱ������DMA����

#define TIM8_enable_DMA_request_at_CC1_event()	TIM8_set_CC1DE(1)	//ͨ��1�ڷ����Ƚ�/�����¼�ʱ����DMA����
#define TIM8_disable_DMA_request_at_CC1_event()	TIM8_set_CC1DE(0)	//ͨ��1�ڷ����Ƚ�/�����¼�ʱ������DMA����


/*�����¼�DMA����ʹ��
	�����������¼�ʱ����DMA����
Bit 8 UDE: Update DMA request enable
0: Update DMA request disabled
1: Update DMA request enabled
*/
void TIM1_set_UDE(U8 ude);
void TIM8_set_UDE(U8 ude);

#define TIM1_enable_DMA_request_at_update_event()	TIM1_set_UDE(1)		//TIM1�ڷ��������¼�ʱ����DMA����
#define TIM1_disable_DMA_request_at_update_event()	TIM1_set_UDE(0)		//TIM1�������¼�ʱ������DMA����

#define TIM8_enable_DMA_request_at_update_event()	TIM8_set_UDE(1)		//TIM8�ڷ��������¼�ʱ����DMA����
#define TIM8_disable_DMA_request_at_update_event()	TIM8_set_UDE(0)		//TIM8�ڷ��������¼�ʱ������DMA����

/*
Bit 7 BIE: Break interrupt enable
0: Break interrupt disabled
1: Break interrupt enabled
*/
//to do

/*�����ж�ʹ��
	������һ����Ч��������һ���ж�
	��λֻ�ڴ�ģʽģʽû�б�����ʱ������
Bit 6 TIE: Trigger interrupt enable
0: Trigger interrupt disabled
1: Trigger interrupt enabled
*/
void TIM1_set_TIE(U8 tie);
void TIM8_set_TIE(U8 tie);

#define TIM1_enable_interrupt_at_trigger()		TIM1_set_TIE(1)		//����һ����ЧTRGI������һ���ж�
#define TIM1_disable_interrupt_at_trigger()		TIM1_set_TIE(0)		//����һ����ЧTRGI���������ж�

#define TIM8_enable_interrupt_at_trigger()		TIM8_set_TIE(1)		//����һ����ЧTRGI������һ���ж�
#define TIM8_disable_interrupt_at_trigger()		TIM8_set_TIE(0)		//����һ����ЧTRGI���������ж�

/*
Bit 5 COMIE: COM interrupt enable
0: COM interrupt disabled
1: COM interrupt enabled
*/
//to do

/*����Ƚ�ͨ��4�ж�ʹ��
	������������߱Ƚ��¼�ʱ�������ж�
Bit 4 CC4IE: Capture/Compare 4 interrupt enable
0: CC4 interrupt disabled
1: CC4 interrupt enabled
*/
void TIM1_set_CC4IE(U8 cc4ie);
void TIM8_set_CC4IE(U8 cc4ie);

#define TIM1_enable_interrupt_at_CC4_event()	TIM1_set_CC4IE(1)	//�Ƚϲ���ͨ��4��������/�Ƚ��¼�ʱ�����ж�	
#define TIM1_disable_interrupt_at_CC4_event()	TIM1_set_CC4IE(0)	//�Ƚϲ���ͨ��4��������/�Ƚ��¼�ʱ�������ж�

#define TIM8_enable_interrupt_at_CC4_event()	TIM8_set_CC4IE(1)	//�Ƚϲ���ͨ��4��������/�Ƚ��¼�ʱ�����ж�	
#define TIM8_disable_interrupt_at_CC4_event()	TIM8_set_CC4IE(0)	//�Ƚϲ���ͨ��4��������/�Ƚ��¼�ʱ�������ж�

/*����Ƚ�ͨ��3�ж�ʹ��
Bit 3 CC3IE: Capture/Compare 3 interrupt enable
0: CC3 interrupt disabled
1: CC3 interrupt enabled
*/
void TIM1_set_CC3IE(U8 cc3ie);
void TIM8_set_CC3IE(U8 cc3ie);

#define TIM1_enable_interrupt_at_CC3_event()	TIM1_set_CC3IE(1)	//�Ƚϲ���ͨ��3��������/�Ƚ��¼�ʱ�����ж�	
#define TIM1_disable_interrupt_at_CC3_event()	TIM1_set_CC3IE(0)	//�Ƚϲ���ͨ��3��������/�Ƚ��¼�ʱ�������ж�

#define TIM8_enable_interrupt_at_CC3_event()	TIM8_set_CC3IE(1)	//�Ƚϲ���ͨ��3��������/�Ƚ��¼�ʱ�����ж�	
#define TIM8_disable_interrupt_at_CC3_event()	TIM8_set_CC3IE(0)	//�Ƚϲ���ͨ��3��������/�Ƚ��¼�ʱ�������ж�


/*����Ƚ�ͨ��2�ж�ʹ��
	������������߱Ƚ��¼�ʱ�������ж�
Bit 2 CC2IE: Capture/Compare 2 interrupt enable
0: CC2 interrupt disabled
1: CC2 interrupt enabled
*/
void TIM1_set_CC2IE(U8 cc2ie);
void TIM8_set_CC2IE(U8 cc2ie);

#define TIM1_enable_interrupt_at_CC2_event()	TIM1_set_CC2IE(1)	//�Ƚϲ���ͨ��2��������/�Ƚ��¼�ʱ�����ж�	
#define TIM1_disable_interrupt_at_CC2_event()	TIM1_set_CC2IE(0)	//�Ƚϲ���ͨ��2��������/�Ƚ��¼�ʱ�������ж�

#define TIM8_enable_interrupt_at_CC2_event()	TIM8_set_CC2IE(1)	//�Ƚϲ���ͨ��2��������/�Ƚ��¼�ʱ�����ж�	
#define TIM8_disable_interrupt_at_CC2_event()	TIM8_set_CC2IE(0)	//�Ƚϲ���ͨ��2��������/�Ƚ��¼�ʱ�������ж�


/*����Ƚ�ͨ��1�ж�ʹ��
	������������߱Ƚ��¼�ʱ�������ж�
Bit 1 CC1IE: Capture/Compare 1 interrupt enable
0: CC1 interrupt disabled
1: CC1 interrupt enabled
*/
void TIM1_set_CC1IE(U8 cc1ie);
void TIM8_set_CC1IE(U8 cc1ie);

#define TIM1_enable_interrupt_at_CC1_event()	TIM1_set_CC1IE(1)	//�Ƚϲ���ͨ��1��������/�Ƚ��¼�ʱ�����ж�	
#define TIM1_disable_interrupt_at_CC1_event()	TIM1_set_CC1IE(0)	//�Ƚϲ���ͨ��1��������/�Ƚ��¼�ʱ�������ж�

#define TIM8_enable_interrupt_at_CC1_event()	TIM8_set_CC1IE(1)	//�Ƚϲ���ͨ��1��������/�Ƚ��¼�ʱ�����ж�	
#define TIM8_disable_interrupt_at_CC1_event()	TIM8_set_CC1IE(0)	//�Ƚϲ���ͨ��1��������/�Ƚ��¼�ʱ�������ж�


/*�����¼��ж�ʹ��
	�����������¼�ʱ�����ж�
Bit 0 UIE: Update interrupt enable
0: Update interrupt disabled
1: Update interrupt enabled
*/
void TIM1_set_UIE(U8 uie);
void TIM8_set_UIE(U8 uie);

#define TIM1_enable_interrupt_at_update_event()		TIM1_set_UIE(1)		//TIM1�ڷ��������¼�ʱ�����ж�����
#define TIM1_disable_interrupt_at_update_event()	TIM1_set_UIE(0)		//TIM1�������¼�ʱ�������ж�����

#define TIM8_enable_interrupt_at_update_event()		TIM8_set_UIE(1)		//TIM8�ڷ��������¼�ʱ�����ж�����
#define TIM8_disable_interrupt_at_update_event()	TIM8_set_UIE(0)		//TIM8�ڷ��������¼�ʱ�������ж�����


//**************************************************************//
//************TIM1&TIM8 status register (TIMx_SR)***************//
//**************************************************************//
/*TIM1&TIM8״̬�Ĵ���
TIM1&TIM8 status register (TIMx_SR)
Address offset: 0x10
Reset value: 0x0000
*/
/*
Bits 15:13 Reserved, always read as 0.
*/

/*����Ƚ�ͨ��4�ظ������־
	�����������¼�ʱ��ǰһ�εĲ����¼���־(CCxIF = 1)û�����
	���ظ������־������
	�Ƚ�ģʽ�¸�λ����
Bit 12 CC4OF: Capture/Compare 4 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC4OF(void);
void TIM1_clear_CC4OF(void);

U8 TIM8_get_CC4OF(void);
void TIM8_clear_CC4OF(void);

#define	TIM1_get_channel4_overcapture_flag()		TIM1_get_CC4OF()		//��ȡͨ��4���ز����־
#define TIM1_clear_channel4_overcapture_flag()		TIM1_clear_CC4OF()		//���ͨ��4���ز����־

#define	TIM8_get_channel4_overcapture_flag()		TIM8_get_CC4OF()		//��ȡͨ��4���ز����־
#define TIM8_clear_channel4_overcapture_flag()		TIM8_clear_CC4OF()		//���ͨ��4���ز����־

/*����Ƚ�ͨ��3�ظ������־
	�����������¼�ʱ��ǰһ�εĲ����¼���־(CCxIF = 1)û�����
	���ظ������־������
Bit 11 CC3OF: Capture/Compare 3 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC3OF(void);
void TIM1_clear_CC3OF(void);

U8 TIM8_get_CC3OF(void);
void TIM8_clear_CC3OF(void);


#define	TIM1_get_channel3_overcapture_flag()		TIM1_get_CC3OF()		//��ȡͨ��3���ز����־
#define TIM1_clear_channel3_overcapture_flag()		TIM1_clear_CC3OF()		//���ͨ��3���ز����־

#define	TIM8_get_channel3_overcapture_flag()		TIM8_get_CC3OF()		//��ȡͨ��3���ز����־
#define TIM8_clear_channel3_overcapture_flag()		TIM8_clear_CC3OF()		//���ͨ��3���ز����־


/*����Ƚ�ͨ��2�ظ������־
	�����������¼�ʱ��ǰһ�εĲ����¼���־(CCxIF = 1)û�����
	���ظ������־������
Bit 10 CC2OF: Capture/Compare 2 overcapture flag
refer to CC1OF description
*/
U8 TIM1_get_CC2OF(void);
void TIM1_clear_CC2OF(void);

U8 TIM8_get_CC2OF(void);
void TIM8_clear_CC2OF(void);

#define	TIM1_get_channel2_overcapture_flag()		TIM1_get_CC2OF()		//��ȡͨ��2���ز����־
#define TIM1_clear_channel2_overcapture_flag()		TIM1_clear_CC2OF()		//���ͨ��2���ز����־

#define	TIM8_get_channel2_overcapture_flag()		TIM8_get_CC2OF()		//��ȡͨ��2���ز����־
#define TIM8_clear_channel2_overcapture_flag()		TIM8_clear_CC2OF()		//���ͨ��2���ز����־

/*����Ƚ�1�ظ������־
	�����������¼�ʱ��ǰһ�εĲ����¼���־(CCxIF = 1)û�����
	���ظ������־������
Bit 9 CC1OF: Capture/Compare 1 overcapture flag
This flag is set by hardware only when the corresponding channel is configured in input 
capture mode. It is cleared by software by writing it to ��0��.
0: No overcapture has been detected.
1: The counter value has been captured in TIMx_CCR1 register while CC1IF flag was 
already set
*/
U8 TIM1_get_CC1OF(void);
void TIM1_clear_CC1OF(void);

U8 TIM8_get_CC1OF(void);
void TIM8_clear_CC1OF(void);

#define	TIM1_get_channel1_overcapture_flag()		TIM1_get_CC1OF()		//��ȡͨ��1���ز����־
#define TIM1_clear_channel1_overcapture_flag()		TIM1_clear_CC1OF()		//���ͨ��1���ز����־

#define	TIM8_get_channel1_overcapture_flag()		TIM8_get_CC1OF()		//��ȡͨ��1���ز����־
#define TIM8_clear_channel1_overcapture_flag()		TIM8_clear_CC1OF()		//���ͨ��1���ز����־


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

/*�����жϱ�־
	�����������¼�ʱ����λ������
	Slave���óɷ��ſ�ģʽʱ��TRGI����Ч�����ø�λ��
	���ſ�ģʽ�£������ض����ø�λ
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

#define TIM1_get_trigger_interrupt_flag()	TIM1_get_TIF()		//��ȡTRGI�жϱ�־ 
#define TIM1_clear_trigger_interrupt_flag()	TIM1_clear_TIF()	//���TRGI�жϱ�־
	
#define TIM1_is_interrupted_by_trigger()	TIM1_get_trigger_interrupt_flag()	//��TRGI�������ж���


#define TIM8_get_trigger_interrupt_flag()	TIM8_get_TIF()		//��ȡTRGI�жϱ�־ 
#define TIM8_clear_trigger_interrupt_flag()	TIM8_clear_TIF()	//���TRGI�жϱ�־
	
#define TIM8_is_interrupted_by_trigger()	TIM8_get_trigger_interrupt_flag()	//��TRGI�������ж���


/*
Bit 5 COMIF: COM interrupt flag
This flag is set by hardware on COM event (when Capture/compare Control bits - CCxE, 
CCxNE, OCxM - have been updated). It is cleared by software.
0: No COM event occurred.
1: COM interrupt pending.
*/
//to do 

/*����Ƚ�ͨ��4�жϱ�־
	�Ƚ�ģʽ:
		 ��TIMx_CNT��ֵ��CCRx��ֵ���ʱ�����жϣ�������Ϊ���ض���ģʽ������
		 �������������Ķ���ģʽ����ʱ�������жϸ���CMS��������:
				���ϼ���ʱ
				���¼���ʱ
				���Ϻ����¼���ʱ
	����ģʽ�ж�:
		��ICxΪ��Ч����ʱ����һ�β��񣬴�ʱCCRx��ֵΪTIMx_CNT��ֵ��ͬʱ�����ж�
����Ƚ�ͨ��4�жϱ�־
	������������߱Ƚ��¼�ʱ����λ����־
Bit 4 CC4IF: Capture/Compare 4 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC4F(void);
void TIM1_clear_CC4F(void);

U8 TIM8_get_CC4F(void);
void TIM8_clear_CC4F(void);

#define TIM1_get_CC4_interrupt_flag()		TIM1_get_CC4F()					//��ȡͨ��4����/�Ƚ��¼��жϱ�־
#define TIM1_clear_CC4_interrupt_flag()		TIM1_clear_CC4F()				//���ͨ��4����/�Ƚ��¼��жϱ�־
#define TIm1_is_interrupted_by_CC4_event()	TIM1_get_CC4_interrupt_flag()	//�ж�����ͨ��4�Ĳ���Ƚ��¼���������


#define TIM8_get_CC4_interrupt_flag()		TIM8_get_CC4F()					//��ȡͨ��4����/�Ƚ��¼��жϱ�־
#define TIM8_clear_CC4_interrupt_flag()		TIM8_clear_CC4F()				//���ͨ��4����/�Ƚ��¼��жϱ�־
#define TIM8_is_interrupted_by_CC4_event()	TIM8_get_CC4_interrupt_flag()	//�ж�����ͨ��4�Ĳ���Ƚ��¼���������


/*����Ƚ�ͨ��3�жϱ�־
	�Ƚ�ģʽ:
		 ��TIMx_CNT��ֵ��CCRx��ֵ���ʱ�����жϣ�������Ϊ���ض���ģʽ������
		 �������������Ķ���ģʽ����ʱ�������жϸ���CMS��������:
				���ϼ���ʱ
				���¼���ʱ
				���Ϻ����¼���ʱ
	����ģʽ�ж�:
		��ICxΪ��Ч����ʱ����һ�β��񣬴�ʱCCRx��ֵΪTIMx_CNT��ֵ��ͬʱ�����ж�
Bit 3 CC3IF: Capture/Compare 3 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC3F(void);
void TIM1_clear_CC3F(void);

U8 TIM8_get_CC3F(void);
void TIM8_clear_CC3F(void);

#define TIM1_get_CC3_interrupt_flag()		TIM1_get_CC3F()					//��ȡͨ��3����/�Ƚ��¼��жϱ�־
#define TIM1_clear_CC3_interrupt_flag()		TIM1_clear_CC3F()				//���ͨ��3����/�Ƚ��¼��жϱ�־
#define TIm1_is_interrupted_by_CC3_event()	TIM1_get_CC3_interrupt_flag()	//�ж�����ͨ��3�Ĳ���Ƚ��¼���������


#define TIM8_get_CC3_interrupt_flag()		TIM8_get_CC3F()					//��ȡͨ��3����/�Ƚ��¼��жϱ�־
#define TIM8_clear_CC3_interrupt_flag()		TIM8_clear_CC3F()				//���ͨ��3����/�Ƚ��¼��жϱ�־
#define TIM8_is_interrupted_by_CC3_event()	TIM8_get_CC3_interrupt_flag()	//�ж�����ͨ��3�Ĳ���Ƚ��¼���������


/*����Ƚ�ͨ��2�жϱ�־
	�Ƚ�ģʽ:
		 ��TIMx_CNT��ֵ��CCRx��ֵ���ʱ�����жϣ�������Ϊ���ض���ģʽ������
		 �������������Ķ���ģʽ����ʱ�������жϸ���CMS��������:
				���ϼ���ʱ
				���¼���ʱ
				���Ϻ����¼���ʱ
	����ģʽ�ж�:
		��ICxΪ��Ч����ʱ����һ�β��񣬴�ʱCCRx��ֵΪTIMx_CNT��ֵ��ͬʱ�����ж�
Bit 2 CC2IF: Capture/Compare 2 interrupt flag
refer to CC1IF description
*/
U8 TIM1_get_CC2F(void);
void TIM1_clear_CC2F(void);

U8 TIM8_get_CC2F(void);
void TIM8_clear_CC2F(void);

#define TIM1_get_CC2_interrupt_flag()		TIM1_get_CC2F()					//��ȡͨ��2����/�Ƚ��¼��жϱ�־
#define TIM1_clear_CC2_interrupt_flag()		TIM1_clear_CC2F()				//���ͨ��2����/�Ƚ��¼��жϱ�־
#define TIm1_is_interrupted_by_CC2_event()	TIM1_get_CC2_interrupt_flag()	//�ж�����ͨ��2�Ĳ���Ƚ��¼���������

#define TIM8_get_CC2_interrupt_flag()		TIM8_get_CC2F()					//��ȡͨ��2����/�Ƚ��¼��жϱ�־
#define TIM8_clear_CC2_interrupt_flag()		TIM8_clear_CC2F()				//���ͨ��2����/�Ƚ��¼��жϱ�־
#define TIM8_is_interrupted_by_CC2_event()	TIM8_get_CC2_interrupt_flag()	//�ж�����ͨ��2�Ĳ���Ƚ��¼���������

/*����Ƚ�ͨ��1�жϱ�־
	�Ƚ�ģʽ:
		 ��TIMx_CNT��ֵ��CCRx��ֵ���ʱ�����жϣ�������Ϊ���ض���ģʽ������
		 �������������Ķ���ģʽ����ʱ�������жϸ���CMS��������:
				���ϼ���ʱ
				���¼���ʱ
				���Ϻ����¼���ʱ
	����ģʽ�ж�:
		��ICxΪ��Ч����ʱ����һ�β��񣬴�ʱCCRx��ֵΪTIMx_CNT��ֵ��ͬʱ�����ж�
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

#define TIM1_get_CC1_interrupt_flag()		TIM1_get_CC1F()					//��ȡͨ��1����/�Ƚ��¼��жϱ�־
#define TIM1_clear_CC1_interrupt_flag()		TIM1_clear_CC1F()				//���ͨ��1����/�Ƚ��¼��жϱ�־
#define TIm1_is_interrupted_by_CC1_event()	TIM1_get_CC1_interrupt_flag()	//�ж�����ͨ��1�Ĳ���Ƚ��¼���������

#define TIM8_get_CC1_interrupt_flag()		TIM8_get_CC1F()					//��ȡͨ��1����/�Ƚ��¼��жϱ�־
#define TIM8_clear_CC1_interrupt_flag()		TIM8_clear_CC1F()				//���ͨ��1����/�Ƚ��¼��жϱ�־
#define TIM8_is_interrupted_by_CC1_event()	TIM8_get_CC1_interrupt_flag()	//�ж�����ͨ��1�Ĳ���Ƚ��¼���������


/*�����¼��жϱ�־
	�����������¼�ʱ����λ����λ��������:
		���������ʱ
		������UGλʱ
		�ڴ�ģʽ����������һ��TRGIʱ
	���������¼�
Bit 0 UIF: Update interrupt flag
This bit is set by hardware on an update event. It is cleared by software.
0: No update occurred.
1: Update interrupt pending. 
This bit is set by hardware when the registers are updated:
�CAt overflow or underflow regarding the repetition counter value (update if repetition 
counter = 0) and if the UDIS=0 in the TIMx_CR1 register.
�CWhen CNT is reinitialized by software using the UG bit in TIMx_EGR register, if URS=0 
and UDIS=0 in the TIMx_CR1 register.
�CWhen CNT is reinitialized by a trigger event (refer to Section 13.4.3: TIM1&TIM8 slave 
mode control register (TIMx_SMCR)), if URS=0 and UDIS=0 in the TIMx_CR1 register.
*/
U8 TIM1_get_UIF(void);
void TIM1_clear_UIF(void);

U8 TIM8_get_UIF(void);
void TIM8_clear_UIF(void);

#define TIM1_get_update_event_flag()	TIM1_get_UIF()		//��ȡ�����¼��жϱ�־ 
#define TIM1_clear_update_event_flag()	TIM1_clear_UIF()	//��������¼��жϱ�־
#define TIM1_is_interrupted_by_update_event()	TIM1_get_update_event_flag()	//�Ǹ����¼����µ��ж���

#define TIM8_get_update_event_flag()	TIM8_get_UIF()		//��ȡ�����¼��жϱ�־ 
#define TIM8_clear_update_event_flag()	TIM8_clear_UIF()	//��������¼��жϱ�־
#define TIM8_is_interrupted_by_update_event()	TIM8_get_update_event_flag()	//�Ǹ����¼����µ��ж���

//***************************************************************//
//*******TIM1&TIM8 event generation register (TIMx_EGR)**********//
//***************************************************************//

/*TIM1&TIM8�¼����ɼĴ���
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

/*�����¼�����
	���ø�λ���Բ���һ�������¼���Ч����TRGI��Чһ��,ֻ�ǲ�����������TRGI����
		Ч�����ݴ�ģʽ��ģʽѡ���в�ͬ������
	����֮����Ӳ������
Bit 6 TG: Trigger generation
This bit is set by software in order to generate an event, it is automatically cleared by 
hardware.
0: No action
1: The TIF flag is set in TIMx_SR register. Related interrupt or DMA transfer can occur if 
enabled.
*/
void TIM1_set_TG(void);
void TIM8_set_TG(void);

//���ﲢ������������һ��TRGI��Ч���룬ֻ��������TIMx_SR�Ĵ������TIF��־, �Բ����жϣ���DMA����
#define TIM1_generate_trigger_event()	TIM1_set_TG()	//����һ��TRGI�¼�

//���ﲢ������������һ��TRGI��Ч���룬ֻ��������TIMx_SR�Ĵ������TIF��־, �Բ����жϣ���DMA����
#define TIM8_generate_trigger_event()	TIM8_set_TG()	//����һ��TRGI�¼�


/*
Bit 5 COMG: Capture/Compare control update generation
This bit can be set by software, it is automatically cleared by hardware
0: No action
1: When CCPC bit is set, it allows to update CCxE, CCxNE and OCxM bits
Note: This bit acts only on channels having a complementary output.
*/
//to do

/*CHANNEL4��������/�Ƚ��¼�
	���CC1Gλ����
Bit 4 CC4G: Capture/Compare 4 generation
refer to CC1G description
*/
void TIM1_set_CC4G(void);
void TIM8_set_CC4G(void);

#define TIM1_generate_CC4_event()	TIM1_set_CC4G()	//ͨ��4��������/�Ƚ��¼�

#define TIM8_generate_CC4_event()	TIM8_set_CC4G()	//ͨ��4��������/�Ƚ��¼�

/*CHANNEL3��������/�Ƚ��¼�
	���CC1Gλ����
Bit 3 CC3G: Capture/Compare 3 generation
refer to CC1G description
*/
void TIM1_set_CC3G(void);
void TIM8_set_CC3G(void);

#define TIM1_generate_CC3_event()	TIM1_set_CC3G()	//ͨ��3��������/�Ƚ��¼�

#define TIM8_generate_CC3_event()	TIM8_set_CC3G()	//ͨ��3��������/�Ƚ��¼�


/*CHANNEL2��������/�Ƚ��¼�
	���CC1Gλ����
Bit 2 CC2G: Capture/Compare 2 generation
refer to CC1G description
*/
void TIM1_set_CC2G(void);
void TIM8_set_CC2G(void);

#define TIM1_generate_CC2_event()	TIM1_set_CC2G()	//ͨ��2��������/�Ƚ��¼�

#define TIM8_generate_CC2_event()	TIM8_set_CC2G()	//ͨ��2��������/�Ƚ��¼�

/*CHANNEL1��������/�Ƚ��¼�
	���ø�λ�����һ������/�Ƚ��¼�
	�����¼�:
		��Channelx�����ó�����ʱ�����������¼� �����¼������¼�������ֵ����׽��CCRx��
		���ʹ�����жϻ�DMA������������Ӧ������
	�Ƚ��¼�:
		��Channelx�����ó����ʱ�������Ƚ��¼�
		���ʹ�����жϻ�DMA������������Ӧ������
		������źŸ������ģʽ�Ĳ�ͬ���в�ͬ��Ч��
	��������ø�λʱ����λ�Ѿ�Ϊ1����CC1OF������
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

#define TIM1_generate_CC1_event()	TIM1_set_CC1G()	//ͨ��1��������/�Ƚ��¼�
#define TIM8_generate_CC1_event()	TIM8_set_CC1G()	//ͨ��1��������/�Ƚ��¼�


/*�����¼�����
	���ø�λ��:
		��������ֵ������(��������Ķ���ģʽ��װ�ص�ֵ����ǰ�ļ��������й�)
		����Ӱ�ӼĴ�����װװ���Ӧ��Ԥװ�ؼĴ�����ֵ
		Ԥ��Ƶ����ֵҲ�����㣬����Ƶ�ʲ���
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

#define TIM1_generate_update_event()	TIM1_set_UG()	//TIM1����һ�������¼�
#define TIM8_generate_update_event()	TIM8_set_UG()	//TIM8����һ�������¼�


//*********************************************************************//
//********TIM1&TIM8 capture/compare mode register 1 (TIMx_CCMR1)*******//
//********TIM1&TIM8 capture/compare mode register 2 (TIMx_CCMR2)*******//
//*********************************************************************//

/*����/�Ƚ�ģʽ�Ĵ���1,2
TIM1&TIM8 capture/compare mode register 1 (TIMx_CCMR1)
Address offset: 0x18
Reset value: 0x0000
The channels can be used in input (capture mode) or in output (compare mode). The 
direction of a channel is defined by configuring the corresponding CCxS bits. All the other 
bits of this register have a different function in input and in output mode. For a given bit, 
OCxx describes its function when the channel is configured in output, ICxx describes its 
function when the channel is configured in input. So you must take care that the same bit 
can have a different meaning for the input stage and for the output stage.
����: ͨ�����Ա����ó�����(����ģʽ)�����(�Ƚ�ģʽ).ͨ���ķ���ͨ����Ӧ��CCxSλ������.��������
��λ����ͨ���ķ���Ĳ�ͬ�в�ͬ�Ĺ���.����һ��������λ��OCxx�����˵�ͨ�������ó����ģʽʱ�Ĺ��ܣ�
ICxx�����˵�ͨ�������ó�����ģʽʱ�Ĺ���.���������С������ͬ��λ�����ó���������ʱ�в�ͬ��ͬ�ܡ�
*/



//**********************����/�ȽϹ���ѡ��*******************************//

//************TIMx_CCMR1****************//
/*����/�Ƚ�ͨ��2����ѡ��
	��ѡ��Ϊ���벶��ģʽ
		ͨ������ʵ��������ж��ӳ��
	��ѡ��Ϊ����Ƚ�ģʽ
Bits 9:8 CC2S[1:0]: Capture/Compare 2 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC2 channel is configured as output
01: CC2 channel is configured as input, IC2 is mapped on TI2
10: CC2 channel is configured as input, IC2 is mapped on TI1
11: CC2 channel is configured as input, IC2 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through the TS bit (TIMx_SMCR register)
Note: CC2S bits are writable only when the channel is OFF (CC2E = ��0�� in TIMx_CCER).
*/
void TIM1_set_CC2S(U8 cc2s);
void TIM8_set_CC2S(U8 cc2s);

#define TIM1_set_channel2_output()			TIM1_set_CC2S(0)		//ͨ��2����Ϊ�Ƚ����
#define TIM1_set_channel2_input()			TIM1_set_CC2S(1)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TI2
#define TIM1_set_channel2_input_map_TI2()	TIM1_set_channel2_input()	//ͬ��
#define TIM1_set_channel2_input_map_TI1()	TIM1_set_CC2S(2)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TI1
#define TIM1_set_channel2_input_map_TRC()	TIM1_set_CC2S(3)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TRC

#define TIM8_set_channel2_output()			TIM8_set_CC2S(0)		//ͨ��2����Ϊ�Ƚ����
#define TIM8_set_channel2_input()			TIM8_set_CC2S(1)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TI2
#define TIM8_set_channel2_input_map_TI2()	TIM8_set_channel2_input()	//ͬ��
#define TIM8_set_channel2_input_map_TI1()	TIM8_set_CC2S(2)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TI1
#define TIM8_set_channel2_input_map_TRC()	TIM8_set_CC2S(3)		//ͨ��2����Ϊ���벶��,IC2ӳ�䵽TRC

/*����/�Ƚ�ͨ��1����ѡ��
	��ѡ��Ϊ���벶��ģʽ
		ͨ������ʵ��������ж��ӳ��
	��ѡ��Ϊ����Ƚ�ģʽ
Bits 1:0 CC1S: Capture/Compare 1 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC1 channel is configured as output
01: CC1 channel is configured as input, IC1 is mapped on TI1
10: CC1 channel is configured as input, IC1 is mapped on TI2
11: CC1 channel is configured as input, IC1 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC1S bits are writable only when the channel is OFF (CC1E = ��0�� in TIMx_CCER).
*/
void TIM1_set_CC1S(U8 cc1s);
void TIM8_set_CC1S(U8 cc1s);

#define TIM1_set_channel1_output()			TIM1_set_CC1S(0)		//ͨ��1����Ϊ�Ƚ����
#define TIM1_set_channel1_input()			TIM1_set_CC1S(1)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TI1
#define TIM1_set_channel1_input_map_TI1()	TIM1_set_channel1_input()	//ͬ��
#define TIM1_set_channel1_input_map_TI2()	TIM1_set_CC1S(2)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TI2
#define TIM1_set_channel1_input_map_TRC()	TIM1_set_CC1S(3)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TRC

#define TIM8_set_channel1_output()			TIM8_set_CC1S(0)		//ͨ��1����Ϊ�Ƚ����
#define TIM8_set_channel1_input()			TIM8_set_CC1S(1)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TI1
#define TIM8_set_channel1_input_map_TI1()	TIM8_set_channel1_input()	//ͬ��
#define TIM8_set_channel1_input_map_TI2()	TIM8_set_CC1S(2)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TI2
#define TIM8_set_channel1_input_map_TRC()	TIM8_set_CC1S(3)		//ͨ��1����Ϊ���벶��,IC1ӳ�䵽TRC


//************TIMx_CCMR2**************//
/*����/�Ƚ�ͨ��4����ѡ��
	��ѡ��Ϊ���벶��ģʽ
		ͨ������ʵ��������ж��ӳ��
	��ѡ��Ϊ����Ƚ�ģʽ
Bits 9:8 CC4S: Capture/Compare 4 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC4 channel is configured as output
01: CC4 channel is configured as input, IC4 is mapped on TI4
10: CC4 channel is configured as input, IC4 is mapped on TI3
11: CC4 channel is configured as input, IC4 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC4S bits are writable only when the channel is OFF (CC4E = ��0�� in TIMx_CCER).
*/
void TIM1_set_CC4S(U8 cc4s);
void TIM8_set_CC4S(U8 cc4s);


#define TIM1_set_channel4_output()			TIM1_set_CC4S(0)		//ͨ��4����Ϊ�Ƚ����
#define TIM1_set_channel4_input()			TIM1_set_CC4S(1)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TI4
#define TIM1_set_channel4_input_map_TI4()	TIM1_set_channel4_input()	//ͬ��
#define TIM1_set_channel4_input_map_TI3()	TIM1_set_CC4S(2)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TI3
#define TIM1_set_channel4_input_map_TRC()	TIM1_set_CC4S(3)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TRC

#define TIM8_set_channel4_output()			TIM8_set_CC4S(0)		//ͨ��4����Ϊ�Ƚ����
#define TIM8_set_channel4_input()			TIM8_set_CC4S(1)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TI4
#define TIM8_set_channel4_input_map_TI4()	TIM8_set_channel4_input()	//ͬ��
#define TIM8_set_channel4_input_map_TI3()	TIM8_set_CC4S(2)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TI3
#define TIM8_set_channel4_input_map_TRC()	TIM8_set_CC4S(3)		//ͨ��4����Ϊ���벶��,IC4ӳ�䵽TRC


/*����/�Ƚ�ͨ��3����ѡ��
	��ѡ��Ϊ���벶��ģʽ
		ͨ������ʵ��������ж��ӳ��
	��ѡ��Ϊ����Ƚ�ģʽ
Bits 1:0 CC3S: Capture/Compare 3 selection
This bit-field defines the direction of the channel (input/output) as well as the used input. 
00: CC3 channel is configured as output
01: CC3 channel is configured as input, IC3 is mapped on TI3
10: CC3 channel is configured as input, IC3 is mapped on TI4
11: CC3 channel is configured as input, IC3 is mapped on TRC. This mode is working only if 
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: CC3S bits are writable only when the channel is OFF (CC3E = ��0�� in TIMx_CCER).
*/
void TIM1_set_CC3S(U8 cc3s);
void TIM8_set_CC3S(U8 cc3s);

#define TIM1_set_channel3_output()			TIM1_set_CC3S(0)		//ͨ��3����Ϊ�Ƚ����
#define TIM1_set_channel3_input()			TIM1_set_CC3S(1)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TI3
#define TIM1_set_channel3_input_map_TI3()	TIM1_set_channel3_input()	//ͬ��
#define TIM1_set_channel3_input_map_TI4()	TIM1_set_CC3S(2)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TI4
#define TIM1_set_channel3_input_map_TRC()	TIM1_set_CC3S(3)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TRC

#define TIM8_set_channel3_output()			TIM8_set_CC3S(0)		//ͨ��3����Ϊ�Ƚ����
#define TIM8_set_channel3_input()			TIM8_set_CC3S(1)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TI3
#define TIM8_set_channel3_input_map_TI3()	TIM8_set_channel3_input()	//ͬ��
#define TIM8_set_channel3_input_map_TI4()	TIM8_set_CC3S(2)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TI4
#define TIM8_set_channel3_input_map_TRC()	TIM8_set_CC3S(3)		//ͨ��3����Ϊ���벶��,IC3ӳ�䵽TRC


//**********************��ͨ�������óɱȽ����ʱ*****************************//

//************TIMx_CCMR1****************//
/*����Ƚ�ͨ��2���ģʽʹ��
	���ø�λ�����ⲿETR��������һ��������ʱ��OCxRef��λ
Bit 15 OC2CE: Output Compare 2 clear enable
*/
void TIM1_set_OC2CE(U8 oc2ce);
void TIM8_set_OC2CE(U8 oc2ce);

#define TIM1_enable_OC2_clear()		TIM1_set_OC2CE(2)		//ͨ��2���ⲿETRFΪ��ʱOCxRef��λ
#define TIM1_disable_OC2_clear()	TIM1_set_OC2CE(0)		//ͨ��2���ⲿETRFΪ��ʱOCxRef����λ

#define TIM8_enable_OC2_clear()		TIM8_set_OC2CE(2)		//ͨ��2���ⲿETRFΪ��ʱOCxRef��λ
#define TIM8_disable_OC2_clear()	TIM8_set_OC2CE(0)		//ͨ��2���ⲿETRFΪ��ʱOCxRef����λ

/*����Ƚ�ͨ��2ģʽѡ��
	��λ�ζ������ڱȽ����ģʽ�µĹ���ģʽ
		����ģʽ 	�ȽϽ����Ӱ�����
		�ø�ģʽ	�ȽϷ�������ø�
		�õ�ģʽ	�ȽϷ��������λ
		ǿ�Ƹ�		����ߣ����ȽϽ���޹�
		ǿ�Ƶ�		����ͣ����ȽϽ���޹�
		PWMģʽ1	CNT<CCRxΪ��
		PWMģʽ2	CNT<CCRxΪ��
	����������OCxREF��ƽ�ĸı䣬��OCxREF����OCx��OCxN�Ǽ�ӵ�ͨ������CCxP��CCxNPλ�����Ƶ�
Bits 14:12 OC2M[2:0]: Output Compare 2 mode
*/
void TIM1_set_OC2M(U8 oc2m);
void TIM8_set_OC2M(U8 oc2m);


#define TIM1_set_OC2_frozen_mode()			TIM1_set_OC2M(0)	//ͨ��2�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM1_set_OC2_active_mode()			TIM1_set_OC2M(1)	//ͨ��2�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM1_set_OC2_inactive_mode()		TIM1_set_OC2M(2)	//ͨ��2�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM1_set_OC2_toggle_mode()			TIM1_set_OC2M(3)	//ͨ��2�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM1_set_OC2_force_inactive_mode()	TIM1_set_OC2M(4)	//ͨ��2�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM1_set_OC2_force_active_mode()	TIM1_set_OC2M(5)	//ͨ��2�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM1_set_OC2_PWM1_mode()			TIM1_set_OC2M(6)	//ͨ��2�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM1_set_OC2_PWM2_mode()			TIM1_set_OC2M(7)	//ͨ��2�Ƚ����ģʽ����ΪPWM2ģʽ

#define TIM8_set_OC2_frozen_mode()			TIM8_set_OC2M(0)	//ͨ��2�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM8_set_OC2_active_mode()			TIM8_set_OC2M(1)	//ͨ��2�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM8_set_OC2_inactive_mode()		TIM8_set_OC2M(2)	//ͨ��2�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM8_set_OC2_toggle_mode()			TIM8_set_OC2M(3)	//ͨ��2�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM8_set_OC2_force_inactive_mode()	TIM8_set_OC2M(4)	//ͨ��2�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM8_set_OC2_force_active_mode()	TIM8_set_OC2M(5)	//ͨ��2�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM8_set_OC2_PWM1_mode()			TIM8_set_OC2M(6)	//ͨ��2�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM8_set_OC2_PWM2_mode()			TIM8_set_OC2M(7)	//ͨ��2�Ƚ����ģʽ����ΪPWM2ģʽ


/*����Ƚ�ͨ��2����װ�ؼĴ���ʹ��
	���ø�λ������װ�ؼĴ�����ֵ�ڷ��������¼�ʱ�Ž�����Ӱ�ӼĴ���
Bit 11 OC2PE: Output Compare 2 preload enable
*/
void TIM1_set_OC2PE(U8 oc2pe);
void TIM8_set_OC2PE(U8 oc2pe);

#define TIM1_enable_CCR2_preload()	TIM1_set_OC2PE(1)	//ͨ��2ʹ��CCR2�Ĵ�������
#define TIM1_disable_CCR2_preload()	TIM1_set_OC2PE(0)	//ͨ��2����CCR2�Ĵ�������

#define TIM8_enable_CCR2_preload()	TIM8_set_OC2PE(1)	//ͨ��2ʹ��CCR2�Ĵ�������
#define TIM8_disable_CCR2_preload()	TIM8_set_OC2PE(0)	//ͨ��2����CCR2�Ĵ�������

/*
Bit 10 OC2FE: Output Compare 2 fast enable
*/
//to do

/*����Ƚ�ͨ��1���ģʽʹ��
	���ø�λ�����ⲿETR��������һ��������ʱ��OCxRef��λ
Bit 7 OC1CE: Output Compare 1 clear enable
OC1CE: Output Compare 1 Clear Enable
0: OC1Ref is not affected by the ETRF Input
1: OC1Ref is cleared as soon as a High level is detected on ETRF input
*/
void TIM1_set_OC1CE(U8 oc1ce);
void TIM8_set_OC1CE(U8 oc1ce);

#define TIM1_enable_OC1_clear()		TIM1_set_OC1CE(1)		//ͨ��1���ⲿETRFΪ��ʱOCxRef��λ
#define TIM1_disable_OC1_clear()	TIM1_set_OC1CE(0)		//ͨ��1���ⲿETRFΪ��ʱOCxRef����λ

#define TIM8_enable_OC1_clear()		TIM8_set_OC1CE(1)		//ͨ��1���ⲿETRFΪ��ʱOCxRef��λ
#define TIM8_disable_OC1_clear()	TIM8_set_OC1CE(0)		//ͨ��1���ⲿETRFΪ��ʱOCxRef����λ

/*����Ƚ�ͨ��1ģʽѡ��
	��λ�ζ������ڱȽ����ģʽ�µĹ���ģʽ
		����ģʽ 	�ȽϽ����Ӱ�����
		�ø�ģʽ	�ȽϷ�������ø�
		�õ�ģʽ	�ȽϷ��������λ
		ǿ�Ƹ�		����ߣ����ȽϽ���޹�
		ǿ�Ƶ�		����ͣ����ȽϽ���޹�
		PWMģʽ1	CNT<CCRxΪ��
		PWMģʽ2	CNT<CCRxΪ��
	����������OCxREF��ƽ�ĸı䣬��OCxREF����OCx��OCxN�Ǽ�ӵ�ͨ������CCxP��CCxNPλ�����Ƶ�
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
else inactive. In downcounting, channel 1 is inactive (OC1REF=��0��) as long as 
TIMx_CNT>TIMx_CCR1 else active (OC1REF=��1��).
111: PWM mode 2 - In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1 
else active. In downcounting, channel 1 is active as long as TIMx_CNT>TIMx_CCR1 else 
inactive.
Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed 
(LOCK bits in TIMx_BDTR register) and CC1S=��00�� (the channel is configured in 
output).
2: In PWM mode 1 or 2, the OCREF level changes only when the result of the 
comparison changes or when the output compare mode switches from ��frozen�� mode 
to ��PWM�� mode.
*/
void TIM1_set_OC1M(U8 oc1m);
void TIM8_set_OC1M(U8 oc1m);

#define TIM1_set_OC1_frozen_mode()			TIM1_set_OC1M(0)	//ͨ��1�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM1_set_OC1_active_mode()			TIM1_set_OC1M(1)	//ͨ��1�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM1_set_OC1_inactive_mode()		TIM1_set_OC1M(2)	//ͨ��1�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM1_set_OC1_toggle_mode()			TIM1_set_OC1M(3)	//ͨ��1�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM1_set_OC1_force_inactive_mode()	TIM1_set_OC1M(4)	//ͨ��1�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM1_set_OC1_force_active_mode()	TIM1_set_OC1M(5)	//ͨ��1�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM1_set_OC1_PWM1_mode()			TIM1_set_OC1M(6)	//ͨ��1�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM1_set_OC1_PWM2_mode()			TIM1_set_OC1M(7)	//ͨ��1�Ƚ����ģʽ����ΪPWM2ģʽ

#define TIM8_set_OC1_frozen_mode()			TIM8_set_OC1M(0)	//ͨ��1�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM8_set_OC1_active_mode()			TIM8_set_OC1M(1)	//ͨ��1�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM8_set_OC1_inactive_mode()		TIM8_set_OC1M(2)	//ͨ��1�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM8_set_OC1_toggle_mode()			TIM8_set_OC1M(3)	//ͨ��1�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM8_set_OC1_force_inactive_mode()	TIM8_set_OC1M(4)	//ͨ��1�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM8_set_OC1_force_active_mode()	TIM8_set_OC1M(5)	//ͨ��1�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM8_set_OC1_PWM1_mode()			TIM8_set_OC1M(6)	//ͨ��1�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM8_set_OC1_PWM2_mode()			TIM8_set_OC1M(7)	//ͨ��1�Ƚ����ģʽ����ΪPWM2ģʽ


/*����Ƚ�ͨ��1����װ�ؼĴ���ʹ��
	���ø�λ������װ�ؼĴ�����ֵ�ڷ��������¼�ʱ�Ž�����Ӱ�ӼĴ���
Bit 3 OC1PE: Output Compare 1 preload enable
0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the 
new value is taken in account immediately.
1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload 
register. TIMx_CCR1 preload value is loaded in the active register at each update event.
Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed 
(LOCK bits in TIMx_BDTR register) and CC1S=��00�� (the channel is configured in 
output).
2: The PWM mode can be used without validating the preload register only in one 
pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
*/
void TIM1_set_OC1PE(U8 oc1pe);
void TIM8_set_OC1PE(U8 oc1pe);

#define TIM1_enable_CCR1_preload()	TIM1_set_OC1PE(1)	//ͨ��1ʹ��CCR1�Ĵ�������
#define TIM1_disable_CCR1_preload()	TIM1_set_OC1PE(0)	//ͨ��1����CCR1�Ĵ�������

#define TIM8_enable_CCR1_preload()	TIM8_set_OC1PE(1)	//ͨ��1ʹ��CCR1�Ĵ�������
#define TIM8_disable_CCR1_preload()	TIM8_set_OC1PE(0)	//ͨ��1����CCR1�Ĵ�������

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
/*����Ƚ�ͨ��4���ģʽʹ��
	���ø�λ�����ⲿETR��������һ��������ʱ��OCxRef��λ
Bit 15 OC4CE: Output compare 4 clear enable
*/
void TIM1_set_OC4CE(U8 oc4ce);
void TIM8_set_OC4CE(U8 oc4ce);

#define TIM1_enable_OC4_clear()		TIM1_set_OC4CE(1)		//ͨ��4���ⲿETRFΪ��ʱOCxRef��λ
#define TIM1_disable_OC4_clear()	TIM1_set_OC4CE(0)		//ͨ��4���ⲿETRFΪ��ʱOCxRef����λ

#define TIM8_enable_OC4_clear()		TIM8_set_OC4CE(1)		//ͨ��4���ⲿETRFΪ��ʱOCxRef��λ
#define TIM8_disable_OC4_clear()	TIM8_set_OC4CE(0)		//ͨ��4���ⲿETRFΪ��ʱOCxRef����λ


/*����Ƚ�ͨ��4ģʽѡ��
	��λ�ζ������ڱȽ����ģʽ�µĹ���ģʽ
		����ģʽ 	�ȽϽ����Ӱ�����
		�ø�ģʽ	�ȽϷ�������ø�
		�õ�ģʽ	�ȽϷ��������λ
		ǿ�Ƹ�		����ߣ����ȽϽ���޹�
		ǿ�Ƶ�		����ͣ����ȽϽ���޹�
		PWMģʽ1	CNT<CCRxΪ��
		PWMģʽ2	CNT<CCRxΪ��
	����������OCxREF��ƽ�ĸı䣬��OCxREF����OCx��OCxN�Ǽ�ӵ�ͨ������CCxP��CCxNPλ�����Ƶ�
Bits 14:12 OC4M: Output compare 4 mode
*/
void TIM1_set_OC4M(U8 oc4m);
void TIM8_set_OC4M(U8 oc4m);

#define TIM1_set_OC4_frozen_mode()			TIM1_set_OC4M(0)	//ͨ��4�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM1_set_OC4_active_mode()			TIM1_set_OC4M(1)	//ͨ��4�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM1_set_OC4_inactive_mode()		TIM1_set_OC4M(2)	//ͨ��4�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM1_set_OC4_toggle_mode()			TIM1_set_OC4M(3)	//ͨ��4�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM1_set_OC4_force_inactive_mode()	TIM1_set_OC4M(4)	//ͨ��4�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM1_set_OC4_force_active_mode()	TIM1_set_OC4M(5)	//ͨ��4�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM1_set_OC4_PWM1_mode()			TIM1_set_OC4M(6)	//ͨ��4�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM1_set_OC4_PWM2_mode()			TIM1_set_OC4M(7)	//ͨ��4�Ƚ����ģʽ����ΪPWM2ģʽ

#define TIM8_set_OC4_frozen_mode()			TIM8_set_OC4M(0)	//ͨ��4�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM8_set_OC4_active_mode()			TIM8_set_OC4M(1)	//ͨ��4�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM8_set_OC4_inactive_mode()		TIM8_set_OC4M(2)	//ͨ��4�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM8_set_OC4_toggle_mode()			TIM8_set_OC4M(3)	//ͨ��4�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM8_set_OC4_force_inactive_mode()	TIM8_set_OC4M(4)	//ͨ��4�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM8_set_OC4_force_active_mode()	TIM8_set_OC4M(5)	//ͨ��4�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM8_set_OC4_PWM1_mode()			TIM8_set_OC4M(6)	//ͨ��4�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM8_set_OC4_PWM2_mode()			TIM8_set_OC4M(7)	//ͨ��4�Ƚ����ģʽ����ΪPWM2ģʽ


/*����Ƚ�ͨ��4����װ�ؼĴ���ʹ��
	���ø�λ������װ�ؼĴ�����ֵ�ڷ��������¼�ʱ�Ž�����Ӱ�ӼĴ���
Bit 11 OC4PE: Output compare 4 preload enable
*/
void TIM1_set_OC4PE(U8 oc4pe);
void TIM8_set_OC4PE(U8 oc4pe);

#define TIM1_enable_CCR4_preload()	TIM1_set_OC4PE(1)	//ͨ��4ʹ��CCR4�Ĵ�������
#define TIM1_disable_CCR4_preload()	TIM1_set_OC4PE(0)	//ͨ��4����CCR4�Ĵ�������

#define TIM8_enable_CCR4_preload()	TIM8_set_OC4PE(1)	//ͨ��4ʹ��CCR4�Ĵ�������
#define TIM8_disable_CCR4_preload()	TIM8_set_OC4PE(0)	//ͨ��4����CCR4�Ĵ�������

/*
Bit 10 OC4FE: Output compare 4 fast enable
*/
//to do

/*����Ƚ�ͨ��3���ģʽʹ��
	���ø�λ�����ⲿETR��������һ��������ʱ��OCxRef��λ
Bit 7 OC3CE: Output compare 3 clear enable
*/
void TIM1_set_OC3CE(U8 oc3ce);
void TIM8_set_OC3CE(U8 oc3ce);

#define TIM1_enable_OC3_clear()		TIM1_set_OC3CE(1)		//ͨ��3���ⲿETRFΪ��ʱOCxRef��λ
#define TIM1_disable_OC3_clear()	TIM1_set_OC3CE(0)		//ͨ��3���ⲿETRFΪ��ʱOCxRef����λ

#define TIM8_enable_OC3_clear()		TIM8_set_OC3CE(1)		//ͨ��3���ⲿETRFΪ��ʱOCxRef��λ
#define TIM8_disable_OC3_clear()	TIM8_set_OC3CE(0)		//ͨ��3���ⲿETRFΪ��ʱOCxRef����λ

/*
����Ƚ�ͨ��3ģʽѡ��
	��λ�ζ������ڱȽ����ģʽ�µĹ���ģʽ
		����ģʽ 	�ȽϽ����Ӱ�����
		�ø�ģʽ	�ȽϷ�������ø�
		�õ�ģʽ	�ȽϷ��������λ
		ǿ�Ƹ�		����ߣ����ȽϽ���޹�
		ǿ�Ƶ�		����ͣ����ȽϽ���޹�
		PWMģʽ1	CNT<CCRxΪ��
		PWMģʽ2	CNT<CCRxΪ��
	����������OCxREF��ƽ�ĸı䣬��OCxREF����OCx��OCxN�Ǽ�ӵ�ͨ������CCxP��CCxNPλ�����Ƶ�
Bits 6:4 OC3M: Output compare 3 mode
*/
void TIM1_set_OC3M(U8 oc3m);
void TIM8_set_OC3M(U8 oc3m);

#define TIM1_set_OC3_frozen_mode()			TIM1_set_OC3M(0)	//ͨ��3�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM1_set_OC3_active_mode()			TIM1_set_OC3M(1)	//ͨ��3�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM1_set_OC3_inactive_mode()		TIM1_set_OC3M(2)	//ͨ��3�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM1_set_OC3_toggle_mode()			TIM1_set_OC3M(3)	//ͨ��3�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM1_set_OC3_force_inactive_mode()	TIM1_set_OC3M(4)	//ͨ��3�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM1_set_OC3_force_active_mode()	TIM1_set_OC3M(5)	//ͨ��3�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM1_set_OC3_PWM1_mode()			TIM1_set_OC3M(6)	//ͨ��3�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM1_set_OC3_PWM2_mode()			TIM1_set_OC3M(7)	//ͨ��3�Ƚ����ģʽ����ΪPWM2ģʽ

#define TIM8_set_OC3_frozen_mode()			TIM8_set_OC3M(0)	//ͨ��3�Ƚ����ģʽ����Ϊ����ģʽ
#define TIM8_set_OC3_active_mode()			TIM8_set_OC3M(1)	//ͨ��3�Ƚ����ģʽ����Ϊ�ø�ģʽ
#define TIM8_set_OC3_inactive_mode()		TIM8_set_OC3M(2)	//ͨ��3�Ƚ����ģʽ����Ϊ�õ�ģʽ
#define TIM8_set_OC3_toggle_mode()			TIM8_set_OC3M(3)	//ͨ��3�Ƚ����ģʽ����Ϊ��תģʽ
#define TIM8_set_OC3_force_inactive_mode()	TIM8_set_OC3M(4)	//ͨ��3�Ƚ����ģʽ����Ϊǿ�Ƶ�
#define TIM8_set_OC3_force_active_mode()	TIM8_set_OC3M(5)	//ͨ��3�Ƚ����ģʽ����Ϊǿ�Ƹ�
#define TIM8_set_OC3_PWM1_mode()			TIM8_set_OC3M(6)	//ͨ��3�Ƚ����ģʽ����ΪPWM1ģʽ
#define TIM8_set_OC3_PWM2_mode()			TIM8_set_OC3M(7)	//ͨ��3�Ƚ����ģʽ����ΪPWM2ģʽ


/*����Ƚ�ͨ��3����װ�ؼĴ���ʹ��
	���ø�λ������װ�ؼĴ�����ֵ�ڷ��������¼�ʱ�Ž�����Ӱ�ӼĴ���
Bit 3 OC3PE: Output compare 3 preload enable
*/
void TIM1_set_OC3PE(U8 oc3pe);
void TIM8_set_OC3PE(U8 oc3pe);

#define TIM1_enable_CCR3_preload()	TIM1_set_OC3PE(1)	//ͨ��3ʹ��CCR3�Ĵ�������
#define TIM1_disable_CCR3_preload()	TIM1_set_OC3PE(0)	//ͨ��3����CCR3�Ĵ�������

#define TIM8_enable_CCR3_preload()	TIM8_set_OC3PE(1)	//ͨ��3ʹ��CCR3�Ĵ�������
#define TIM8_disable_CCR3_preload()	TIM8_set_OC3PE(0)	//ͨ��3����CCR3�Ĵ�������

/*
Bit 2 OC3FE: Output compare 3 fast enable
*/
//to do 


//*********************��ͨ�������ó����벶��ģʽʱ**************************//
//************TIMx_CCMR1****************//
/*���벶��2�˲�������
Bits 15:12 IC2F: Input capture 2 filter
*/
void TIM1_set_IC2F(U8 ic2f);
void TIM8_set_IC2F(U8 ic2f);

/*���벶��2Ԥ��Ƶϵ��ѡ��
	��λ����������CHANNEL1��Ϊ���벶��ʱ�ķ�Ƶϵ��
Bits 11:10 IC2PSC[1:0]: Input capture 2 prescaler
*/
void TIM1_set_IC2PSC(U8 tc2psc);
void TIM8_set_IC2PSC(U8 tc2psc);

#define TIM1_set_IC2_prescaler_1()	TIM1_set_IC2PSC(0)	//ͨ��2�������벻��Ƶ
#define TIM1_set_IC2_prescaler_2()	TIM1_set_IC2PSC(1)	//ͨ��2���������Ƶ2
#define TIM1_set_IC2_prescaler_4()	TIM1_set_IC2PSC(2)	//ͨ��2���������Ƶ4
#define TIM1_set_IC2_prescaler_8()	TIM1_set_IC2PSC(3)	//ͨ��2���������Ƶ8

#define TIM8_set_IC2_prescaler_1()	TIM8_set_IC2PSC(0)	//ͨ��2�������벻��Ƶ
#define TIM8_set_IC2_prescaler_2()	TIM8_set_IC2PSC(1)	//ͨ��2���������Ƶ2
#define TIM8_set_IC2_prescaler_4()	TIM8_set_IC2PSC(2)	//ͨ��2���������Ƶ4
#define TIM8_set_IC2_prescaler_8()	TIM8_set_IC2PSC(3)	//ͨ��2���������Ƶ8


/*���벶��1�˲�������
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


/*���벶��1Ԥ��Ƶϵ��ѡ��
	��λ����������CHANNEL1��Ϊ���벶��ʱ�ķ�Ƶϵ��
Bits 3:2 IC1PSC: Input capture 1 prescaler
This bit-field defines the ratio of the prescaler acting on CC1 input (IC1).
The prescaler is reset as soon as CC1E=��0�� (TIMx_CCER register).
00: no prescaler, capture is done each time an edge is detected on the capture input
01: capture is done once every 2 events
10: capture is done once every 4 events
11: capture is done once every 8 events
*/
void TIM1_set_IC1PSC(U8 tc1psc);
void TIM8_set_IC1PSC(U8 tc1psc);

#define TIM1_set_IC1_prescaler_1()	TIM1_set_IC1PSC(0)	//ͨ��1�������벻��Ƶ
#define TIM1_set_IC1_prescaler_2()	TIM1_set_IC1PSC(1)	//ͨ��1���������Ƶ2
#define TIM1_set_IC1_prescaler_4()	TIM1_set_IC1PSC(2)	//ͨ��1���������Ƶ4
#define TIM1_set_IC1_prescaler_8()	TIM1_set_IC1PSC(3)	//ͨ��1���������Ƶ8

#define TIM8_set_IC1_prescaler_1()	TIM8_set_IC1PSC(0)	//ͨ��1�������벻��Ƶ
#define TIM8_set_IC1_prescaler_2()	TIM8_set_IC1PSC(1)	//ͨ��1���������Ƶ2
#define TIM8_set_IC1_prescaler_4()	TIM8_set_IC1PSC(2)	//ͨ��1���������Ƶ4
#define TIM8_set_IC1_prescaler_8()	TIM8_set_IC1PSC(3)	//ͨ��1���������Ƶ8


//************TIMx_CCMR2****************//
/*���벶��4�˲�������
Bits 15:12 IC4F: Input capture 4 filter
*/
void TIM1_set_IC4F(U8 ic4f);
void TIM8_set_IC4F(U8 ic4f);

/*���벶��4Ԥ��Ƶϵ��ѡ��
Bits 11:10 IC4PSC: Input capture 4 prescaler
*/
void TIM1_set_IC4PSC(U8 tc4psc);
void TIM8_set_IC4PSC(U8 tc4psc);

#define TIM1_set_IC4_prescaler_1()	TIM1_set_IC4PSC(0)	//ͨ��4�������벻��Ƶ
#define TIM1_set_IC4_prescaler_2()	TIM1_set_IC4PSC(1)	//ͨ��4���������Ƶ2
#define TIM1_set_IC4_prescaler_4()	TIM1_set_IC4PSC(2)	//ͨ��4���������Ƶ4
#define TIM1_set_IC4_prescaler_8()	TIM1_set_IC4PSC(3)	//ͨ��4���������Ƶ8

#define TIM8_set_IC4_prescaler_1()	TIM8_set_IC4PSC(0)	//ͨ��4�������벻��Ƶ
#define TIM8_set_IC4_prescaler_2()	TIM8_set_IC4PSC(1)	//ͨ��4���������Ƶ2
#define TIM8_set_IC4_prescaler_4()	TIM8_set_IC4PSC(2)	//ͨ��4���������Ƶ4
#define TIM8_set_IC4_prescaler_8()	TIM8_set_IC4PSC(3)	//ͨ��4���������Ƶ8


/*���벶��3�˲�������
Bits 7:4 IC3F: Input capture 3 filter
*/
void TIM1_set_IC3F(U8 ic3f);
void TIM8_set_IC3F(U8 ic3f);


/*���벶��3�˲�������
Bits 3:2 IC3PSC: Input capture 3 prescaler
*/
void TIM1_set_IC3PSC(U8 tc3psc);
void TIM8_set_IC3PSC(U8 tc3psc);

#define TIM1_set_IC3_prescaler_1()	TIM1_set_IC3PSC(0)	//ͨ��3�������벻��Ƶ
#define TIM1_set_IC3_prescaler_2()	TIM1_set_IC3PSC(1)	//ͨ��3���������Ƶ2
#define TIM1_set_IC3_prescaler_4()	TIM1_set_IC3PSC(2)	//ͨ��3���������Ƶ4
#define TIM1_set_IC3_prescaler_8()	TIM1_set_IC3PSC(3)	//ͨ��3���������Ƶ8

#define TIM8_set_IC3_prescaler_1()	TIM8_set_IC3PSC(0)	//ͨ��3�������벻��Ƶ
#define TIM8_set_IC3_prescaler_2()	TIM8_set_IC3PSC(1)	//ͨ��3���������Ƶ2
#define TIM8_set_IC3_prescaler_4()	TIM8_set_IC3PSC(2)	//ͨ��3���������Ƶ4
#define TIM8_set_IC3_prescaler_8()	TIM8_set_IC3PSC(3)	//ͨ��3���������Ƶ8


//****************************************************************//
//*****TIM1&TIM8 capture/compare enable register (TIMx_CCER)******//
//****************************************************************//
/*
����/�Ƚ�ʹ�ܼĴ���
TIM1&TIM8 capture/compare enable register (TIMx_CCER)
Address offset: 0x20
Reset value: 0x0000
*/
/*
Bits 15:14 Reserved, always read as 0.
*/

/*ͨ��4�������뼫��/�Ƚ��������
	��λ����ѡ����
	����Ƚ�ʱ
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	���벶��ʱ
		ѡ��ICx�����뼫��
Bit 13 CC4P: Capture/Compare 4 output polarity
refer to CC1P description
*/
void TIM1_set_CC4P(U8 cc4p);
void TIM8_set_CC4P(U8 cc4p);

#define TIM1_set_CC4_polarity_high()	TIM1_set_CC4P(0)	//����ͨ��4����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC4_polarity_low()		TIM1_set_CC4P(1)	//����ͨ��4����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC4_polarity_high()	TIM8_set_CC4P(0)	//����ͨ��4����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC4_polarity_low()		TIM8_set_CC4P(1)	//����ͨ��4����(TIx)����/���(OxREF)���Ե���Ч

/*ͨ��4�Ĳ���ʹ�ܺͱȽ�ʹ��
	����ģʽ
		����ʹ��
			��λ�������Ʋ��񵽵��ź��Ƿ��͵�����/�ȽϼĴ���
	�Ƚ�ģʽ
		�Ƚ����ʹ��
	��λ�����ø���CCxS(ͨ������ѡ��)λ�ξ���
Bit 12 CC4E: Capture/Compare 4 output enable
refer to CC1E description
*/
void TIM1_set_CC4E(U8 cc4e);
void TIM8_set_CC4E(U8 cc4e);

#define TIM1_enable_CC4()	TIM1_set_CC4E(1)	//ͨ��4�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC4()	TIM1_set_CC4E(0)	//ͨ��4�Ƚ��������/������� 

#define TIM8_enable_CC4()	TIM8_set_CC4E(1)	//ͨ��4�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC4()	TIM8_set_CC4E(0)	//ͨ��4�Ƚ��������/������� 

/*ͨ��3�Ƚϻ����������
	��λ����ѡ����
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	��λֻ��������Ƚ�ģʽ
Bit 11 CC3NP: Capture/Compare 3 complementary output polarity
refer to CC1NP description
*/
void TIM1_set_CC3NP(U8 cc3np);
void TIM8_set_CC3NP(U8 cc3np);

#define TIM1_set_CC3N_polarity_high()	TIM1_set_CC3NP(0)	//����ͨ��3����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC3N_polarity_low()	TIM1_set_CC3NP(1)	//����ͨ��3����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC3N_polarity_high()	TIM8_set_CC3NP(0)	//����ͨ��3����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC3N_polarity_low()	TIM8_set_CC3NP(1)	//����ͨ��3����(TIx)����/���(OxREF)���Ե���Ч

/*ͨ��3�Ƚϻ������ʹ��
	��λֻ���ڱȽ�ģʽ
		0:����Ƚϵ�OCx����Ϊ��
		1:����Ƚϵ�OCx����Ϊ��
Bit 10 CC3NE: Capture/Compare 3 complementary output enable
refer to CC1NE description
*/
void TIM1_set_CC3NE(U8 cc3ne);
void TIM8_set_CC3NE(U8 cc3ne);

#define TIM1_enable_CC3N()	TIM1_set_CC3NE(1)	//ͨ��3�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC3N()	TIM1_set_CC3NE(0)	//ͨ��3�Ƚ��������/������� 

#define TIM8_enable_CC3N()	TIM8_set_CC3NE(1)	//ͨ��3�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC3N()	TIM8_set_CC3NE(0)	//ͨ��3�Ƚ��������/������� 


/*ͨ��3�������뼫��/�Ƚ��������
	��λ����ѡ����
	����Ƚ�ʱ
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	���벶��ʱ
		ѡ��ICx�����뼫��
Bit 9 CC3P: Capture/Compare 3 output polarity
refer to CC1P description
*/
void TIM1_set_CC3P(U8 cc3p);
void TIM8_set_CC3P(U8 cc3p);

#define TIM1_set_CC3_polarity_high()	TIM1_set_CC3P(0)	//����ͨ��3����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC3_polarity_low()		TIM1_set_CC3P(1)	//����ͨ��3����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC3_polarity_high()	TIM8_set_CC3P(0)	//����ͨ��3����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC3_polarity_low()		TIM8_set_CC3P(1)	//����ͨ��3����(TIx)����/���(OxREF)���Ե���Ч


/*ͨ��3�Ĳ���ʹ�ܺͱȽ�ʹ��
	����ģʽ
		����ʹ��
		�Ƚ�ʹ��
	�Ƚ�ģʽ
		//to do
	��λ�����ø���CCxS(ͨ������ѡ��)λ�ξ���
Bit 8 CC3E: Capture/Compare 3 output enable
refer to CC1E description
*/
void TIM1_set_CC3E(U8 cc3e);
void TIM8_set_CC3E(U8 cc3e);

#define TIM1_enable_CC3()	TIM1_set_CC3E(1)	//ͨ��3�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC3()	TIM1_set_CC3E(0)	//ͨ��3�Ƚ��������/������� 

#define TIM8_enable_CC3()	TIM8_set_CC3E(1)	//ͨ��3�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC3()	TIM8_set_CC3E(0)	//ͨ��3�Ƚ��������/������� 


/*ͨ��2�Ƚϻ����������
	��λ����ѡ����
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	��λֻ��������Ƚ�ģʽ
Bit 7 CC2NP: Capture/Compare 2 complementary output polarity
refer to CC1NP description
*/
void TIM1_set_CC2NP(U8 cc2np);
void TIM8_set_CC2NP(U8 cc2np);

#define TIM1_set_CC2N_polarity_high()	TIM1_set_CC2NP(0)	//����ͨ��2����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC2N_polarity_low()	TIM1_set_CC2NP(1)	//����ͨ��2����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC2N_polarity_high()	TIM8_set_CC2NP(0)	//����ͨ��2����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC2N_polarity_low()	TIM8_set_CC2NP(1)	//����ͨ��2����(TIx)����/���(OxREF)���Ե���Ч

/*ͨ��2�Ƚϻ������ʹ��
	��λֻ���ڱȽ�ģʽ
		0:����Ƚϵ�OCx����Ϊ��
		1:����Ƚϵ�OCx����Ϊ��
Bit 6 CC2NE: Capture/Compare 2 complementary output enable
refer to CC1NE description
*/
void TIM1_set_CC2NE(U8 cc2ne);
void TIM8_set_CC2NE(U8 cc2ne);

#define TIM1_enable_CC2N()	TIM1_set_CC2NE(1)	//ͨ��2�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC2N()	TIM1_set_CC2NE(0)	//ͨ��2�Ƚ��������/������� 

#define TIM8_enable_CC2N()	TIM8_set_CC2NE(1)	//ͨ��2�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC2N()	TIM8_set_CC2NE(0)	//ͨ��2�Ƚ��������/������� 

/*ͨ��2�������뼫��/�Ƚ��������
	��λ����ѡ����
	����Ƚ�ʱ
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	���벶��ʱ
		ѡ��ICx�����뼫��
Bit 5 CC2P: Capture/Compare 2 output polarity
refer to CC1P description
*/
void TIM1_set_CC2P(U8 cc2p);
void TIM8_set_CC2P(U8 cc2p);

#define TIM1_set_CC2_polarity_high()	TIM1_set_CC2P(0)	//����ͨ��2����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC2_polarity_low()		TIM1_set_CC2P(1)	//����ͨ��2����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC2_polarity_high()	TIM8_set_CC2P(0)	//����ͨ��2����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC2_polarity_low()		TIM8_set_CC2P(1)	//����ͨ��2����(TIx)����/���(OxREF)���Ե���Ч


/*ͨ��2�Ĳ���ʹ�ܺͱȽ�ʹ��
	����ģʽ
		����ʹ��
		�Ƚ�ʹ��
	�Ƚ�ģʽ
		//to do
	��λ�����ø���CCxS(ͨ������ѡ��)λ�ξ���
Bit 4 CC2E: Capture/Compare 2 output enable
refer to CC1E description
*/
void TIM1_set_CC2E(U8 cc2e);
void TIM8_set_CC2E(U8 cc2e);

#define TIM1_enable_CC2()	TIM1_set_CC2E(1)	//ͨ��2�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC2()	TIM1_set_CC2E(0)	//ͨ��2�Ƚ��������/������� 

#define TIM8_enable_CC2()	TIM8_set_CC2E(1)	//ͨ��2�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC2()	TIM8_set_CC2E(0)	//ͨ��2�Ƚ��������/������� 


/*ͨ��1�Ƚϻ����������
	��λ����ѡ����
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	��λֻ��������Ƚ�ģʽ
Bit 3 CC1NP: Capture/Compare 1 complementary output polarity
0: OC1N active high.
1: OC1N active low.
Note: This bit is not writable as soon as LOCK level 2 or 3 has been programmed (LOCK bits 
in TIMx_BDTR register) and CC1S=��00�� (the channel is configured in output).
*/
void TIM1_set_CC1NP(U8 cc1np);
void TIM8_set_CC1NP(U8 cc1np);

#define TIM1_set_CC1N_polarity_high()	TIM1_set_CC1NP(0)	//����ͨ��1����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC1N_polarity_low()	TIM1_set_CC1NP(1)	//����ͨ��1����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC1N_polarity_high()	TIM8_set_CC1NP(0)	//����ͨ��1����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC1N_polarity_low()	TIM8_set_CC1NP(1)	//����ͨ��1����(TIx)����/���(OxREF)���Ե���Ч


/*ͨ��1�Ƚϻ������ʹ��
	��λֻ���ڱȽ�ģʽ
		0:����Ƚϵ�OCx����Ϊ��
		1:����Ƚϵ�OCx����Ϊ��
Bit 2 CC1NE: Capture/Compare 1 complementary output enable
0: Off - OC1N is not active. OC1N level is then function of MOE, OSSI, OSSR, OIS1, OIS1N 
and CC1E bits.
1: On - OC1N signal is output on the corresponding output pin depending on MOE, OSSI, 
OSSR, OIS1, OIS1N and CC1E bits.
*/
void TIM1_set_CC1NE(U8 cc1ne);
void TIM8_set_CC1NE(U8 cc1ne);

#define TIM1_enable_CC1N()	TIM1_set_CC1NE(1)	//ͨ��1�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC1N()	TIM1_set_CC1NE(0)	//ͨ��1�Ƚ��������/������� 

#define TIM8_enable_CC1N()	TIM8_set_CC1NE(1)	//ͨ��1�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC1N()	TIM8_set_CC1NE(0)	//ͨ��1�Ƚ��������/������� 

/*ͨ��1�������뼫��/�Ƚ��������
	��λ����ѡ����
	����Ƚ�ʱ
		ѡ��OCxREF���������
			0�������OCxREF��ͬ
			1: �����OCxREF�෴
	���벶��ʱ
		ѡ��ICx�����뼫��
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

#define TIM1_set_CC1_polarity_high()	TIM1_set_CC1P(0)	//����ͨ��1����(TIx)����/���(OxREF)���Ը���Ч
#define TIM1_set_CC1_polarity_low()		TIM1_set_CC1P(1)	//����ͨ��1����(TIx)����/���(OxREF)���Ե���Ч

#define TIM8_set_CC1_polarity_high()	TIM8_set_CC1P(0)	//����ͨ��1����(TIx)����/���(OxREF)���Ը���Ч
#define TIM8_set_CC1_polarity_low()		TIM8_set_CC1P(1)	//����ͨ��1����(TIx)����/���(OxREF)���Ե���Ч

/*ͨ��1�Ĳ���ʹ�ܺͱȽ�ʹ��
	����ģʽ
		����ʹ��
	�Ƚ�ģʽ
		�Ƚ����ʹ��
	��λ�����ø���CCxS(ͨ������ѡ��)λ�ξ���
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

#define TIM1_enable_CC1()	TIM1_set_CC1E(1)	//ͨ��1�Ƚ����ʹ��/����ʹ��
#define TIM1_disable_CC1()	TIM1_set_CC1E(0)	//ͨ��1�Ƚ��������/������� 

#define TIM8_enable_CC1()	TIM8_set_CC1E(1)	//ͨ��1�Ƚ����ʹ��/����ʹ��
#define TIM8_disable_CC1()	TIM8_set_CC1E(0)	//ͨ��1�Ƚ��������/������� 

/*******************************************************************/
/******************TIM1&TIM8 counter (TIMx_CNT)*********************/
/*******************************************************************/

/*TIM1&TIM8��������ǰֵ
TIM1&TIM8 counter (TIMx_CNT)
Address offset: 0x24
Reset value: 0x0000
*/

/*��������ֵ��16λ
Bits 15:0
CNT[15:0]: Counter value
*/
void TIM1_set_CNT(U16 cnt);
U16 TIM1_get_CNT(void);

void TIM8_set_CNT(U16 cnt);
U16 TIM8_get_CNT(void);

#define TIM1_set_counter(counter)	TIM1_set_CNT(counter)		//���õ�ǰ��������ֵ
#define TIM1_get_counter()			TIM1_get_CNT()						//��ȡ��ǰ��������ֵ


#define TIM8_set_counter(counter)	TIM8_set_CNT(counter)		//���õ�ǰ��������ֵ
#define TIM8_get_counter()			TIM8_get_CNT()						//��ȡ��ǰ��������ֵ

/*******************************************************************/
/****************TIM1&TIM8 prescaler (TIMx_PSC)*********************/
/*******************************************************************/

/*TIM1&TIM8��Ƶ����
TIM1&TIM8 prescaler (TIMx_PSC)
Address offset: 0x28
Reset value: 0x0000
��Ƶ����һ��16λ�ļ�����������һ��װ�ؼĴ�����ÿ����Ƶ���ļ�����������װ
�ؼ�����ʱ���һ��CLK��COUNTER�����ҷ�Ƶ���ļ����������㡣
װ�ؼĴ�����һ��Ԥװ�ؼĴ���, �Է�Ƶ���ķ��ʶ��Ƿ���Ԥװ�ؼĴ�����
ֻ���ڸ����¼�ʱԤװ�ؼĴ�����ֵ�Ž���װ�ؼĴ���(Ӱ�ӼĴ���).
*/

/*��Ƶ����Ԥװ��ֵ
	���ô�λ���������ü������ķ�Ƶ����Ԥװ��ֵ
	�ڷ��������¼�ʱ,Ԥװ�ص�ֵ����Ӱ�ӼĴ���
Bits 15:0 PSC[15:0]: Prescaler value
The counter clock frequency (CK_CNT) is equal to fCK_PSC / (PSC[15:0] + 1).
PSC contains the value to be loaded in the active prescaler register at each update event 
(including when the counter is cleared through UG bit of TIMx_EGR register or through trigger 
controller when configured in ��reset mode��).
*/
void TIM1_set_PSC(U16 psc);
U16 TIM1_get_PSC(void);

void TIM8_set_PSC(U16 psc);
U16 TIM8_get_PSC(void);

#define TIM1_set_counter_prescaler(p)	TIM1_set_PSC(p)	//���ü������ķ�Ƶ����Ԥװ��ֵ
#define TIM1_get_counter_prescaler()	TIM1_get_PSC()	//��ȡ�������ķ�Ƶ������װ��ֵ

#define TIM8_set_counter_prescaler(p)	TIM8_set_PSC(p)	//���ü������ķ�Ƶ����Ԥװ��ֵ
#define TIM8_get_counter_prescaler()	TIM8_get_PSC()	//��ȡ�������ķ�Ƶ������װ��ֵ

//****************************************************************//
//*******TIM1&TIM8 auto-reload register (TIMx_ARR)****************//
//****************************************************************//

/*TIM1&TIM8 �Զ���װ�ؼĴ���
	����������ֵ�������˼Ĵ������趨��ֵʱ��������¼�(�ڱ������ϼ���ģʽ��)
		Ȼ���������ֵ����
	����������ֵ��Ϊ0ʱ���˼Ĵ�����ֵ��װ�ص���������(�ڱ������¼���ģʽ��)
	����������ֵ�������˼�������ֵ��1ʱ����������¼�(�����ĶԳ�ģʽ�¼���)
		Ȼ���������ֵ��װ��Ϊ�üĴ�����ֵ,�����¼�����1�����������¼���Ȼ��
		��������ֵ������,Ȼ�������ϼ���
	
TIM1&TIM8 auto-reload register (TIMx_ARR)
Address offset: 0x2C
Reset value: 0x0000
*/
/* �Զ���װ�ؼĴ���
	�˼Ĵ������������������ļĴ�������ֻ�����������ļĴ�������Ĵ�����ֻ�е�
	������Ԥװ�ع���ʱ����ü�������д�Ż�������Ч(�������͵������ڹ�����Ӱ��
	�Ĵ�����),����ֻ���ڷ��������¼�ʱ�Ż���������¼�.
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

#define TIM1_set_counter_auto_reload(r)	TIM1_set_ARR(r)		//�����Զ���װ�ؼĴ���
#define TIM1_get_counter_auto_reload()	TIM1_get_ARR()		//��ȡ�Զ���װ�ؼĴ���

#define TIM8_set_counter_auto_reload(r)	TIM8_set_ARR(r)		//�����Զ���װ�ؼĴ���
#define TIM8_get_counter_auto_reload()	TIM8_get_ARR()		//��ȡ�Զ���װ�ؼĴ���


//*******************************************************************//
//*********TIM1&TIM8 repetition counter register (TIMx_RCR)**********//
//*******************************************************************//

/*�ظ��������Ĵ���
	�ü�����Ϊ�ݼ�������
	����������ÿһ�����ʱ���üĴ������Լ�һ�Σ����üĴ����Լ�Ϊ0ʱ���ٷ���һ��
	������������������һ�������¼������ҸüĴ�����ֵ�����Ϊ����Ԥװ�ؼĴ�����
TIM1&TIM8 repetition counter register (TIMx_RCR)
Address offset: 0x30
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved, always read as 0.
*/

/*�ظ�������ֵ
Bits 7:0 REP[7:0]: Repetition counter value
These bits allow the user to set-up the update rate of the compare registers (i.e. periodic 
transfers from preload to active registers) when preload registers are enable, as well as the 
update interrupt generation rate, if this interrupt is enable.
Each time the REP_CNT related downcounter reaches zero, an update event is generated and 
it restarts counting from REP value. As REP_CNT is reloaded with REP value only at the 
repetition update event U_RC, any write to the TIMx_RCR register is not taken in account until 
the next repetition update event.
It means in PWM mode (REP+1) corresponds to:
�C the number of PWM periods in edge-aligned mode
�C the number of half PWM period in center-aligned mode.
*/
void TIM1_set_REP(U8 rep);
U8	TIM1_get_REP(void);

void TIM8_set_REP(U8 rep);
U8	TIM8_get_REP(void);

#define TIM1_set_repetition_counter(r)	TIM1_set_REP(r)	//�����ظ���������Ԥװ��ֵ
#define TIM1_get_repetition_counter()	TIM1_get_REP()	//��ȡ�ظ���������Ԥװ��ֵ

#define TIM8_set_repetition_counter(r)	TIM8_set_REP(r)	//�����ظ���������Ԥװ��ֵ
#define TIM8_get_repetition_counter()	TIM8_get_REP()	//��ȡ�ظ���������Ԥװ��ֵ



//*******************************************************************//
//*********TIM1&TIM8 capture/compare register 1 (TIMx_CCR1)**********//
//*********TIM1&TIM8 capture/compare register 2 (TIMx_CCR2)**********//
//*********TIM1&TIM8 capture/compare register 3 (TIMx_CCR3)**********//
//*********TIM1&TIM8 capture/compare register 4 (TIMx_CCR4)**********//
//*******************************************************************//
/*
TIM1&TIM8 ����/�ȽϼĴ���1 - 4(TIMx_CCR1-4)
TIM1&TIM8 capture/compare register 1 (TIMx_CCR1)
Address offset: 0x34, 0x38, 3C, 40
Reset value: 0x0000
*/
/*����/�Ƚ�ֵ
	����ģʽʱ:
		�����������¼�����������ֵ�����񵽸üĴ�����(ֱ�Ӵ���Ӱ�ӼĴ������͵�����)
	�Ƚ�ģʽʱ:
		�����洢���ᴫ�䵽��Ӱ�ӼĴ�������ֵ����OC1PE���õĻ���ֻ���ڷ��������¼�ʱ,
		�üĴ�����ֵ�Żᴫ�͵�Ӱ�ӼĴ�����(Active CCR1).

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
TIM1&TIM8 ɲ���������Ĵ���
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
�����ʹ��
	��λ��������TIMx�����ʹ��
	������break�¼�ʱ����λ�����㣬�������ֹͣ
	��λ���ڵ��������ڿ���ͨ���ⲿ�ź�ֹͣ���(ɲ���Ƶ�)
	��λֻ��ͨ�������ó����ģʽʱ��Ч
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

