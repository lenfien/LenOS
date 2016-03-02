

#ifndef __BASE_DAC
#define __BASE_DAC

#include "core_map.h"
#include "com.h"

//***************************��ַ��ֵ
//DAC control register
#define __DAC_CR		(DAC_BASE + 0x00)

//DAC software trigger register
#define __DAC_SWTRIGR	(DAC_BASE + 0x04)

//DAC channel1 12-bit/8-bit left/righ holding register
#define __DAC_DHR12R1	(DAC_BASE + 0x08)		//align right 
#define __DAC_DHR12L1	(DAC_BASE + 0x0C)		//align left
#define __DAC_DHR8R1	(DAC_BASE + 0x10)

//DAC channel2 12-bit/8-bit left/righ holding register
#define __DAC_DHR12R2	(DAC_BASE + 0x14)		//align right 
#define __DAC_DHR12L2	(DAC_BASE + 0x18)		//align right 
#define __DAC_DHR8R2	(DAC_BASE + 0x1C)

//DAC channel1+channel2 12-bit/8-bit left/righ holding register
#define __DAC_DHR12RD	(DAC_BASE + 0x20)		//align right 
#define __DAC_DHR12LD	(DAC_BASE + 0x24)		//align right 
#define __DAC_DHR8RD	(DAC_BASE + 0x28)

//DAC channel1 data output register
#define __DAC_DOR1		(DAC_BASE + 0x2C)

//DAC channel2 data output register
#define __DAC_DOR2		(DAC_BASE + 0x30)


//***************************ת��Ϊ��ַ
//DAC control register
#define _DAC_CR		ADR(__DAC_CR)

//DAC software trigger register
#define _DAC_SWTRIGR	ADR(__DAC_SWTRIGR)

//DAC channel1 12-bit/8-bit left/righ holding register
#define _DAC_DHR12R1	ADR(__DAC_DHR12R1)
#define _DAC_DHR12L1	ADR(__DAC_DHR12L1)
#define _DAC_DHR8R1		ADR(__DAC_DHR8R1)

//DAC channel2 12-bit/8-bit left/righ holding register
#define _DAC_DHR12R2	ADR(__DAC_DHR12R2)
#define _DAC_DHR12L2	ADR(__DAC_DHR12L2)
#define _DAC_DHR8R2		ADR(__DAC_DHR8R2)

//DAC channel1+channel2 12-bit/8-bit left/righ holding register
#define _DAC_DHR12RD	ADR(__DAC_DHR12RD)
#define _DAC_DHR12LD	ADR(__DAC_DHR12LD)
#define _DAC_DHR8RD		ADR(__DAC_DHR8RD)

//DAC channel1 data output register
#define _DAC_DOR1		ADR(__DAC_DOR1)

//DAC channel2 data output register
#define _DAC_DOR2		ADR(__DAC_DOR1)


//***************************ȡ��ֵַ
//DAC control register
#define DAC_CR			VAL(__DAC_CR)

//DAC software trigger register
#define DAC_SWTRIGR		VAL(__DAC_SWTRIGR)

//DAC channel1 12-bit/8-bit left/righ holding register
#define DAC_DHR12R1		VAL(__DAC_DHR12R1)
#define DAC_DHR12L1		VAL(__DAC_DHR12L1)
#define DAC_DHR8R1		VAL(__DAC_DHR8R1)

//DAC channel2 12-bit/8-bit left/righ holding register
#define DAC_DHR12R2		VAL(__DAC_DHR12R2)
#define DAC_DHR12L2		VAL(__DAC_DHR12L2)
#define DAC_DHR8R2		VAL(__DAC_DHR8R2)

//DAC channel1+channel2 12-bit/8-bit left/righ holding register
#define DAC_DHR12RD		VAL(__DAC_DHR12RD)
#define DAC_DHR12LD		VAL(__DAC_DHR12LD)
#define DAC_DHR8RD		VAL(__DAC_DHR8RD)

//DAC channel1 data output register
#define DAC_DOR1		VAL(__DAC_DOR1)

//DAC channel2 data output register
#define DAC_DOR2		VAL(__DAC_DOR1)

//���Ŷ���
#define CHANNAL1_PORT	GPIO_A
#define CHANNEL1_PIN	4

#define CHANNEL2_PORT	GPIO_A
#define CHANNEL2_PIN	5

typedef enum  
{
	ALIGN_RIGHT_12,	//12λ���Ҷ���
	ALIGN_LEFT_12,	//12λ�������
	ALIGN_RIGHT_8	//8λ���Ҷ���(���Ҷ�һ��)
} DAC_DALIGN_MODE;

//DAC���ݶ���ģʽDALIM :data align mode
//�������Լ��ӵ�һ���Ĵ���(����), �洢��DAC���ݶ���ģʽ
extern DAC_DALIGN_MODE	DAC_DALIM;



//********************************************************//
//***********DAC control register (DAC_CR)****************//
//********************************************************//
/*
	DAC control register (DAC_CR)
	Address offset: 0x00
	Reset value: 0x0000 0000
*/
/*
	�˼Ĵ�����Ϊ�������֣�
	0 - 12λΪDAC1������
	16 - 28λΪDAC2������
	��Ҫ���õĲ�����:(DAC1��DAC2���ø�����ͬ)
	��ÿһ������λ�ε���ϸ����.	
*/

/*
Bits 31:29 Reserved.
*/

/*
DAC Channel2 DMAʹ��: 
ʹ�ܺ��ڷ���DAC�����¼�(�������Ҳ����),�ᴥ��һ��DMA����.
Bit 28 DMAEN2: DAC channel2 DMA enable
This bit is set and cleared by software. 
0: DAC channel2 DMA mode disabled
1: DAC channel2 DMA mode enabled
*/
void DAC_set_DMAEN2(U8 e_d);

#define DAC_channel2_enable_DMA()	DAC_set_DMAEN2(1)
#define DAC_channel2_disable_DMA()	DAC_set_DMAEN2(0)

/*
DAC Channel2 ����λ�����ѡ��:
	��λ�εĹ��ܸ���WAVEλ�ε�ѡ����ı�.
	ѡ�������λ(WAVE=01):
		������[����]����ʱ����λ������ѡ����������������������������Чλ.
	���ѡ��(WAVE=1x)	:
													����WAVEx[1:0]λΪ��10��ѡ��DAC
	�����ǲ����ɹ��ܡ�����DAC_CR�Ĵ�����MAMPx[3:0]λ��ѡ�����ǲ��ķ��ȡ��ڲ������ǲ�
	������ÿ�δ����¼�֮��3��APB1ʱ�����ں��ۼ�1����������ֵ��DAC_DHRx�Ĵ�������ֵ
	��Ӳ��������λ��д��DAC_DORx�Ĵ������ڴ���DAC_DORx�Ĵ�������ֵС��MAMP[3:0]
	λ�����������ʱ�����ǲ����������ۼӡ�һ���ﵽ���õ������ȣ����������ʼ��
	�����ﵽ0���ٿ�ʼ�ۼӣ��ܶ���ʼ��
		
Bit 27:24 MAMP2[3:0]: DAC channel2 mask/amplitude selector
These bits are written by software to select mask in wave generation mode or amplitude in 
triangle generation mode.
0000: Unmask bit0 of LFSR/ Triangle Amplitude equal to 1
0001: Unmask bits[1:0] of LFSR/ Triangle Amplitude equal to 3
0010: Unmask bits[2:0] of LFSR/ Triangle Amplitude equal to 7
0011: Unmask bits[3:0] of LFSR/ Triangle Amplitude equal to 15
0100: Unmask bits[4:0] of LFSR/ Triangle Amplitude equal to 31
0101: Unmask bits[5:0] of LFSR/ Triangle Amplitude equal to 63
0110: Unmask bits[6:0] of LFSR/ Triangle Amplitude equal to 127
0111: Unmask bits[7:0] of LFSR/ Triangle Amplitude equal to 255
1000: Unmask bits[8:0] of LFSR/ Triangle Amplitude equal to 511
1001: Unmask bits[9:0] of LFSR/ Triangle Amplitude equal to 1023
1010: Unmask bits[10:0] of LFSR/ Triangle Amplitude equal to 2047
1011: Unmask bits[11:0] of LFSR/ Triangle Amplitude equal to 4095
*/
void DAC_set_MAMP2(U8 mamp);

#define DAC_channel2_set_unmask_bit_0_to_0()		DAC_set_MAMP2(0)
#define DAC_channel2_set_unmask_bits_0_to_1()		DAC_set_MAMP2(1)
#define DAC_channel2_set_unmask_bits_0_to_2()		DAC_set_MAMP2(2)
#define DAC_channel2_set_unmask_bits_0_to_3()		DAC_set_MAMP2(3)
#define DAC_channel2_set_unmask_bits_0_to_4()		DAC_set_MAMP2(4)
#define DAC_channel2_set_unmask_bits_0_to_5()		DAC_set_MAMP2(5)
#define DAC_channel2_set_unmask_bits_0_to_6()		DAC_set_MAMP2(6)
#define DAC_channel2_set_unmask_bits_0_to_7()		DAC_set_MAMP2(7)
#define DAC_channel2_set_unmask_bits_0_to_8()		DAC_set_MAMP2(8)
#define DAC_channel2_set_unmask_bits_0_to_9()		DAC_set_MAMP2(9)
#define DAC_channel2_set_unmask_bits_0_to_10()		DAC_set_MAMP2(10)
#define DAC_channel2_set_unmask_bits_0_to_11()		DAC_set_MAMP2(11)


#define DAC_channel2_set_triangle_amplitude_1()		DAC_set_MAMP2(0)
#define DAC_channel2_set_triangle_amplitude_3()		DAC_set_MAMP2(1)
#define DAC_channel2_set_triangle_amplitude_7()		DAC_set_MAMP2(2)
#define DAC_channel2_set_triangle_amplitude_15()	DAC_set_MAMP2(3)
#define DAC_channel2_set_triangle_amplitude_31()	DAC_set_MAMP2(4)
#define DAC_channel2_set_triangle_amplitude_63()	DAC_set_MAMP2(5)
#define DAC_channel2_set_triangle_amplitude_127()	DAC_set_MAMP2(6)
#define DAC_channel2_set_triangle_amplitude_255()	DAC_set_MAMP2(7)
#define DAC_channel2_set_triangle_amplitude_511()	DAC_set_MAMP2(8)
#define DAC_channel2_set_triangle_amplitude_1023()	DAC_set_MAMP2(9)
#define DAC_channel2_set_triangle_amplitude_2047()	DAC_set_MAMP2(10)
#define DAC_channel2_set_triangle_amplitude_4095()	DAC_set_MAMP2(11)


/*
DAC Channel2���ι���ѡ��:
	��ѡ��:
	01:�������β�������
	1x:���ǲ���������
	00:���ò��ι���
Bit 23:22 WAVE2[1:0]: DAC channel2 noise/triangle wave generation enable
These bits are set/reset by software.
00: wave generation disabled 
01: Noise wave generation enabled 
1x: Triangle wave generation enabled
Note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
*/
void DAC_set_WAVE2(U8 wave);

#define DAC_channel2_disable_wave_generator()			DAC_set_WAVE2(0)
#define DAC_channel2_enable_wave_noise_generator()		DAC_set_WAVE2(01)
#define DAC_channel2_enablee_wave_triangl_generator()	DAC_set_WAVE2(10)

/*
DAC Channel2ת������Դѡ��
Bits 21:19 TSEL2[2:0]: DAC channel2 trigger selection
These bits select the external event used to trigger DAC channel2
000: Timer 6 TRGO event
001: Timer 3 TRGO event in connectivity line devices, Timer 8 TRGO in high-density and XL-density devices
010: Timer 7 TRGO event
011: Timer 5 TRGO event
100: Timer 2 TRGO event
101: Timer 4 TRGO event
110: External line9 
111: Software trigger 
Note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
*/
void DAC_set_TSEL2(U8 tsel);

#define DAC_channel2_set_trigger_source_TIM6_TRGO()		DAC_set_TSEL2(0)
#define DAC_channel2_set_trigger_source_TIM3_TRGO()		DAC_set_TSEL2(1)
#define DAC_channel2_set_trigger_source_TIM7_TRGO()		DAC_set_TSEL2(2)
#define DAC_channel2_set_trigger_source_TIM5_TRGO()		DAC_set_TSEL2(3)
#define DAC_channel2_set_trigger_source_TIM2_TRGO()		DAC_set_TSEL2(4)
#define DAC_channel2_set_trigger_source_TIM4_TRGO()		DAC_set_TSEL2(5)
#define DAC_channel2_set_trigger_source_EXTI9()			DAC_set_TSEL2(6)
#define DAC_channel2_set_trigger_source_software()		DAC_set_TSEL2(7)


/*
DAC Channel2 ��������ת��:
	����������ת����DAC��ÿһ��ת������Ҫһ���������塣
	��������Դͨ��TSEL2ѡ��.
Bit 18 TEN2: DAC channel2 trigger enable
This bit set and cleared by software to enable/disable DAC channel2 trigger 
0: DAC channel2 trigger disabled and data written into DAC_DHRx register is transferred 
one APB1 clock cycle later to the DAC_DOR2 register.
1: DAC channel2 trigger enabled and data transfer from DAC_DHRx register is transferred 
three APB1 clock cycles later to the DAC_DOR2 register.
Note: When software trigger is selected, it takes only one APB1 clock cycle for DAC_DHRx to 
DAC_DOR2 register transfer.
*/
void DAC_set_TEN2(U8 e_d);

#define DAC_channel2_enable_trigger()	DAC_set_TEN2(1)
#define DAC_channel2_disable_trigger()	DAC_set_TEN2(0)


/*
DAC Channel2 ���������
DAC������2��������棬����������������迹�������ⲿ�˷ż���ֱ�������ⲿ���ء�
Bit 17 BOFF2: DAC channel2 output buffer disable
This bit set and cleared by software to enable/disable DAC channel2 output buffer.
0: DAC channel2 output buffer enabled
1: DAC channel2 output buffer disabled
*/
void DAC_set_BOFF2(U8 e_d);

#define DAC_channel2_enable_output_buffer()		DAC_set_BOFF2(1)
#define DAC_channel2_disable_output_buffer()	DAC_set_BOFF2(0)

/*
ʹ��DAC Channel2��ת��
��DAC_CR�Ĵ�����ENxλ�á�1�����ɴ򿪶�DACͨ��x�Ĺ��硣����һ������ʱ��tWAKEUP��
DACͨ��x����ʹ�ܡ�
Bit 16 EN2: DAC channel2 enable
This bit set and cleared by software to enable/disable DAC channel2.
0: DAC channel2 disabled 
1: DAC channel2 enabled
*/
void DAC_set_EN2(U8	e_d);

#define DAC_channel2_enable()	DAC_set_EN2(1)
#define DAC_channel2_disable()	DAC_set_EN2(0)

/*
Bits 15:13 Reserved.
*/

/*
DAC Channel1 DMAʹ��: 
ʹ�ܺ��ڷ���DAC�����¼�(�������Ҳ����),�ᴥ��һ��DMA����.
DAC��DMA���󲻻��ۼƣ���������2���ⲿ������������Ӧ��1���ⲿ����֮ǰ�����ܴ�
���2��DMA����Ҳ���ᱨ����� 
Bit 12 DMAEN1: DAC channel1 DMA enable
This bit is set and cleared by software. 
0: DAC channel1 DMA mode disabled
1: DAC channel1 DMA mode enabled
*/
void DAC_set_DMAEN1(U8 e_d);

#define DAC_channel1_enable_DMA()	DAC_set_DMAEN1(1)
#define DAC_channel1_disable_DMA()	DAC_set_DMAEN1(0)


/*
DAC Channel1 ����λ�����ѡ��:
	��λ�εĹ��ܸ���WAVEλ�ε�ѡ����ı�.
	ѡ�������λ(WAVE=01):
		������[����]����ʱ����λ������ѡ����������������������������Чλ.
	���ѡ��(WAVE=1x)	:
													����WAVEx[1:0]λΪ��10��ѡ��DAC
	�����ǲ����ɹ��ܡ�����DAC_CR�Ĵ�����MAMPx[3:0]λ��ѡ�����ǲ��ķ��ȡ��ڲ������ǲ�
	������ÿ�δ����¼�֮��3��APB1ʱ�����ں��ۼ�1����������ֵ��DAC_DHRx�Ĵ�������ֵ
	��Ӳ��������λ��д��DAC_DORx�Ĵ������ڴ���DAC_DORx�Ĵ�������ֵС��MAMP[3:0]
	λ�����������ʱ�����ǲ����������ۼӡ�һ���ﵽ���õ������ȣ����������ʼ��
	�����ﵽ0���ٿ�ʼ�ۼӣ��ܶ���ʼ��
Bits 11:8 MAMP1[3:0]: DAC channel1 mask/amplitude selector
These bits are written by software to select mask in wave generation mode or amplitude in 
triangle generation mode.
0000: Unmask bit0 of LFSR/ Triangle Amplitude equal to 1
0001: Unmask bits[1:0] of LFSR/ Triangle Amplitude equal to 3
0010: Unmask bits[2:0] of LFSR/ Triangle Amplitude equal to 7
0011: Unmask bits[3:0] of LFSR/ Triangle Amplitude equal to 15
0100: Unmask bits[4:0] of LFSR/ Triangle Amplitude equal to 31
0101: Unmask bits[5:0] of LFSR/ Triangle Amplitude equal to 63
0110: Unmask bits[6:0] of LFSR/ Triangle Amplitude equal to 127
0111: Unmask bits[7:0] of LFSR/ Triangle Amplitude equal to 255
1000: Unmask bits[8:0] of LFSR/ Triangle Amplitude equal to 511
1001: Unmask bits[9:0] of LFSR/ Triangle Amplitude equal to 1023
1010: Unmask bits[10:0] of LFSR/ Triangle Amplitude equal to 2047
1011: Unmask bits[11:0] of LFSR/ Triangle Amplitude equal to 4095
*/
void DAC_set_MAMP1(U8 mamp);

#define DAC_channel1_set_unmask_bit_0_to_0()		DAC_set_MAMP1(0)
#define DAC_channel1_set_unmask_bits_0_to_1()		DAC_set_MAMP1(1)
#define DAC_channel1_set_unmask_bits_0_to_2()		DAC_set_MAMP1(2)
#define DAC_channel1_set_unmask_bits_0_to_3()		DAC_set_MAMP1(3)
#define DAC_channel1_set_unmask_bits_0_to_4()		DAC_set_MAMP1(4)
#define DAC_channel1_set_unmask_bits_0_to_5()		DAC_set_MAMP1(5)
#define DAC_channel1_set_unmask_bits_0_to_6()		DAC_set_MAMP1(6)
#define DAC_channel1_set_unmask_bits_0_to_7()		DAC_set_MAMP1(7)
#define DAC_channel1_set_unmask_bits_0_to_8()		DAC_set_MAMP1(8)
#define DAC_channel1_set_unmask_bits_0_to_9()		DAC_set_MAMP1(9)
#define DAC_channel1_set_unmask_bits_0_to_10()		DAC_set_MAMP1(10)
#define DAC_channel1_set_unmask_bits_0_to_11()		DAC_set_MAMP1(11)


#define DAC_channel1_set_triangle_amplitude_1()		DAC_set_MAMP1(0)
#define DAC_channel1_set_triangle_amplitude_3()		DAC_set_MAMP1(1)
#define DAC_channel1_set_triangle_amplitude_7()		DAC_set_MAMP1(2)
#define DAC_channel1_set_triangle_amplitude_15()	DAC_set_MAMP1(3)
#define DAC_channel1_set_triangle_amplitude_31()	DAC_set_MAMP1(4)
#define DAC_channel1_set_triangle_amplitude_63()	DAC_set_MAMP1(5)
#define DAC_channel1_set_triangle_amplitude_127()	DAC_set_MAMP1(6)
#define DAC_channel1_set_triangle_amplitude_255()	DAC_set_MAMP1(7)
#define DAC_channel1_set_triangle_amplitude_511()	DAC_set_MAMP1(8)
#define DAC_channel1_set_triangle_amplitude_1023()	DAC_set_MAMP1(9)
#define DAC_channel1_set_triangle_amplitude_2047()	DAC_set_MAMP1(10)
#define DAC_channel1_set_triangle_amplitude_4095()	DAC_set_MAMP1(11)

/*
DAC Channel1���ι���ѡ��:
	��ѡ��:
	01:�������β�������
	1x:���ǲ���������
	00:���ò��ι���
Bits 7:6 WAVE1[1:0]: DAC channel1 noise/triangle wave generation enable
These bits are set/reset by software.
00: wave generation disabled 
01: Noise wave generation enabled 
1x: Triangle wave generation enabled
Note: only used if bit TEN1 = 1 (DAC channel1 trigger enabled)
*/
void DAC_set_WAVE1(U8 wave);

#define DAC_channel1_disable_wave_generator()			DAC_set_WAVE1(0)
#define DAC_channel1_enable_wave_noise_generator()		DAC_set_WAVE1(1)
#define DAC_channel1_enable_wave_triangle_generator()	DAC_set_WAVE1(2)


/*
DAC Channel1ת������Դѡ��
Bits 5:3 TSEL1[2:0]: DAC channel1 trigger selection
These bits select the external event used to trigger DAC channel1
000: Timer 6 TRGO event
001: Timer 3 TRGO event in connectivity line devices, Timer 8 TRGO in high-density and 
XL-density devices
010: Timer 7 TRGO event
011: Timer 5 TRGO event
100: Timer 2 TRGO event
101: Timer 4 TRGO event
110: External line9 
111: Software trigger 
Note: only used if bit TEN1 = 1 (DAC channel1 trigger enabled)
*/
void DAC_set_TSEL1(U8 sel);

#define DAC_channel1_set_trigger_source_TIM6_TRGO()		DAC_set_TSEL1(0)
#define DAC_channel1_set_trigger_source_TIM3_TRGO()		DAC_set_TSEL1(1)
#define DAC_channel1_set_trigger_source_TIM7_TRGO()		DAC_set_TSEL1(2)
#define DAC_channel1_set_trigger_source_TIM5_TRGO()		DAC_set_TSEL1(3)
#define DAC_channel1_set_trigger_source_TIM2_TRGO()		DAC_set_TSEL1(4)
#define DAC_channel1_set_trigger_source_TIM4_TRGO()		DAC_set_TSEL1(5)
#define DAC_channel1_set_trigger_source_EXTI9()			DAC_set_TSEL1(6)
#define DAC_channel1_set_trigger_source_software()		DAC_set_TSEL1(7)

/*
DAC Channel1 ��������ת��:
	����������ת����DAC��ÿһ��ת������Ҫһ���������塣
	��������Դͨ��TSEL2ѡ��.
Bit 2 TEN1: DAC channel1 trigger enable
This bit set and cleared by software to enable/disable DAC channel1 trigger 
0: DAC channel1 trigger disabled and data written into DAC_DHRx register is transferred 
one APB1 clock cycle later to the DAC_DOR1 register.
1: DAC channel1 trigger enabled and data transfer from DAC_DHRx register is transferred 
three APB1 clock cycles later to the DAC_DOR1 register.
Note: When software trigger is selected, it takes only one APB1 clock cycle for DAC_DHRx to 
DAC_DOR1 register transfer.
*/
void DAC_set_TEN1(U8 e_d);

#define DAC_channel1_enable_trigger()	DAC_set_TEN1(1)
#define DAC_channel1_disable_trigger()	DAC_set_TEN1(0)

/*
DAC Channel1 ���������
DAC������2��������棬����������������迹�������ⲿ�˷ż���ֱ�������ⲿ���ء�
Bit 1 BOFF1: DAC channel1 output buffer disable
This bit set and cleared by software to enable/disable DAC channel1 output buffer.
0: DAC channel1 output buffer enabled
1: DAC channel1 output buffer disabled
*/
void DAC_set_BOFF1(U8 e_d);

#define DAC_channel1_enable_output_buffer()		DAC_set_BOFF1(1)
#define DAC_channel1_disable_output_buffer()	DAC_set_BOFF1(0)

/*
ʹ��DAC Channel1��ת��
��DAC_CR�Ĵ�����ENxλ�á�1�����ɴ򿪶�DACͨ��x�Ĺ��硣����һ������ʱ��tWAKEUP��
DACͨ��x����ʹ�ܡ�
Bit 0 EN1: DAC channel1 enable
This bit set and cleared by software to enable/disable DAC channel1.
0: DAC channel1 disabled 
1: DAC channel1 enabled
*/
void DAC_set_EN1(U8 e_d);

#define DAC_channel1_enable()	DAC_set_EN1(1)
#define DAC_channel1_disable()	DAC_set_EN1(0)






//********************************************************//
//******DAC software trigger register (DAC_SWTRIGR)*******//
//********************************************************//
/*
DAC software trigger register (DAC_SWTRIGR)
Address offset: 0x04
Reset value: 0x0000 0000
*/
/*
�˼Ĵ�����������DAC Channel1 �� Channel2 �������������
*/
/*
Bits 31:2 Reserved.
*/
/*
Bit 1 SWTRIG2: DAC channel2 software trigger
This bit is set and cleared by software to enable/disable the software trigger.
0: Software trigger disabled
1: Software trigger enabled
Note: This bit is reset by hardware (one APB1 clock cycle later) once the DAC_DHR2 register 
value is loaded to the DAC_DOR2 register.
*/
void DAC_set_SWTRIG2(U8 e_d);

#define DAC_channel2_generate_trigger()	DAC_set_SWTRIG2(1)

/*
Bit 0 SWTRIG1: DAC channel1 software trigger
This bit is set and cleared by software to enable/disable the software trigger.
0: Software trigger disabled
1: Software trigger enabled
Note: This bit is reset by hardware (one APB1 clock cycle later) once the DAC_DHR1 register 
value is loaded to the DAC_DOR1 register.
*/
void DAC_set_SWTRIG1(U8 e_d);

#define DAC_channel1_generate_trigger()	DAC_set_SWTRIG1(1)






//*********************************************************************//
//DAC channel1 12-bit right-aligned data holding register (DAC_DHR12R1)
//DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1)
//DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1)
//*********************************************************************//
/*
	DAC Channel1:
	�˺������������ڲ�ͬ����ģʽ��
	�Բ�ͬ��ת��ǰ��ֵ�Ĵ���������.
	align_mode:
			0:12λ�����
			1:12λ�Ҷ���
			2:8λ�Ҷ���(8λû�������)
*/
void DAC_set_DHR1(U16 dhr);
#define DAC_channel1_set_holding_data(dh)	DAC_set_DHR1(dh)


U16 DAC_get_DHR1(void);
#define DAC_channel1_get_holding_data()		DAC_get_DHR1()







//***********************************************************************//
//DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2)**//
//DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2)***//
//DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2)****//
//***********************************************************************//

/*
	DAC Channel2:
	�˺������������ڲ�ͬ����ģʽ��
	�Բ�ͬ��ת��ǰ��ֵ�Ĵ���������.
	align_mode:
			0:12λ�����
			1:12λ�Ҷ���
			2:8λ�Ҷ���(8λû�������)
*/

void DAC_set_DHR2(U16 dhr);

#define DAC_channel2_set_holding_data(dh)	DAC_set_DHR2(dh)

U16 DAC_get_DHR2(void);

#define DAC_channel2_get_holding_data()	DAC_get_DHR2()








//********************************************************************//
//Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD)***//
//DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD)****//
//DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD)*****//
//********************************************************************//
/*
	��˫DACģʽ�£���Ҫһ������DHR1��DHR2�Ĵ����������Ѿ��ṩ�˸����Ĵ���������3����
	���������Ĵ����ķֱ�һ����д����ͬʱ��DHR1��DHR2д��
	�ڴ���ģʽ��Ҳ����������ķ�ʽ����д�����ڷǴ���ģʽ����Ҫͬʱ����Channel1��
	Channel2�ͱ���ʹ���������
*/
void DAC_set_DHRxD(U32 dhrC1, U32 dhrC2);

#define DAC_dual_set_holding_data(hd1, hd2)	DAC_set_DHRxD(hd1, hd2)

U32 DAC_get_DHRxD(U32 dhrC1, U32 dhrC2);

#define DAC_dual_get_holding_data()			DAC_get_DHRxD()


//********************************************************//
//*******************DAC DAC_DALIM************************//
//********************************************************//
/*
	DAC���ݶ���ģʽ����
	������֮ǰ���õ�ֵ
*/
DAC_DALIGN_MODE DAC_set_DALIM(DAC_DALIGN_MODE m);

#define DAC_set_data_align_12_left()	DAC_set_DALIM(ALIGN_LEFT_12)
#define DAC_set_data_align_12_right()	DAC_set_DALIM(ALIGN_RIGHT_12)
#define DAC_set_data_align_8_righ()		DAC_set_DALIM(ALIGN_RIGHT_8)
#define DAC_set_data_align_8()			DAC_set_DALIM(ALIGN_RIGHT_8)



//********************************************************//
//*****DAC channel2 data output register (DAC_DOR2)*******//
//********************************************************//
/*
	DAC channel2 data output register (DAC_DOR2)
	Address offset: 0x30
	Reset value: 0x0000 0000
*/
/*
	Channel2��ת��������ֵ
	����Ĵ���������Ž�Ҫת��Ϊģ���ѹ��ֵ
	����Ĵ������ֵ����DHRx�Ĵ�����ת�ƵĹ���ʱ�ǿɿ��Ƶġ�
	ת�ƹ����п�:
		�������ɺ͹���.
		���ǲ�����
		�޸ı�
	ת�ƿ���δʹ�ܴ���ʱ�Է����У����ʹ���˴���ת������Ҫ��ÿһ��
	�����źŵ���ʱ���С�
	�����������ɺ����ǲ����ɱ����ڴ����½��С�
*/
/*
Bits 31:12 Reserved.
*/

/*
Bit 11:0 DACC2DOR[11:0]: DAC channel2 data output 
These bits are read only, they contain data output for DAC channel2.
*/
U16 DAC_get_DOR2(void);


#define DAC_channel2_get_output_data()	DAC_get_DOR2()








//********************************************************//
//*****DAC channel1 data output register (DAC_DOR1)*******//
//********************************************************//
/*
	DAC channel1 data output register (DAC_DOR1)
	Address offset: 0x30
	Reset value: 0x0000 0000
*/
/*
	Channel1��ת��������ֵ
	����Ĵ���������Ž�Ҫת��Ϊģ���ѹ��ֵ
	����Ĵ������ֵ����DHRx�Ĵ�����ת�ƵĹ���ʱ�ǿɿ��Ƶġ�
	ת�ƹ����п�:
		�������ɺ͹���.
		���ǲ�����
		�޸ı�
	ת�ƿ���δʹ�ܴ���ʱ�Է����У����ʹ���˴���ת������Ҫ��ÿһ��
	�����źŵ���ʱ���С�
	�����������ɺ����ǲ����ɱ����ڴ����½��С�
*/
/*
Bits 31:12 Reserved.
*/

/*
Bit 11:0 DACC2DOR[11:0]: DAC channel2 data output 
These bits are read only, they contain data output for DAC channel2.
*/
U16 DAC_get_DOR1(void);

#define DAC_channel1_get_output_data()	DAC_get_DOR1()

#endif
