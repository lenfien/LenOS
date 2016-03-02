

#ifndef __BASE_DAC
#define __BASE_DAC

#include "core_map.h"
#include "com.h"

//***************************地址数值
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


//***************************转换为地址
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


//***************************取地址值
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

//引脚定义
#define CHANNAL1_PORT	GPIO_A
#define CHANNEL1_PIN	4

#define CHANNEL2_PORT	GPIO_A
#define CHANNEL2_PIN	5

typedef enum  
{
	ALIGN_RIGHT_12,	//12位的右对齐
	ALIGN_LEFT_12,	//12位的左对齐
	ALIGN_RIGHT_8	//8位的右对齐(左右都一样)
} DAC_DALIGN_MODE;

//DAC数据对其模式DALIM :data align mode
//这是我自己加的一个寄存器(变量), 存储了DAC数据对其模式
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
	此寄存器分为两个部分：
	0 - 12位为DAC1的配置
	16 - 28位为DAC2的配置
	需要配置的参数有:(DAC1和DAC2配置概念相同)
	见每一个功能位段的详细解释.	
*/

/*
Bits 31:29 Reserved.
*/

/*
DAC Channel2 DMA使能: 
使能后在发生DAC触发事件(软件触发也可以),会触发一次DMA请求.
Bit 28 DMAEN2: DAC channel2 DMA enable
This bit is set and cleared by software. 
0: DAC channel2 DMA mode disabled
1: DAC channel2 DMA mode enabled
*/
void DAC_set_DMAEN2(U8 e_d);

#define DAC_channel2_enable_DMA()	DAC_set_DMAEN2(1)
#define DAC_channel2_disable_DMA()	DAC_set_DMAEN2(0)

/*
DAC Channel2 屏蔽位和振幅选择:
	此位段的功能根据WAVE位段的选择而改变.
	选择非屏蔽位(WAVE=01):
		当开启[噪音]功能时，该位段用来选择噪音发生器所产生的噪音的有效位.
	振幅选择(WAVE=1x)	:
													设置WAVEx[1:0]位为’10’选择DAC
	的三角波生成功能。设置DAC_CR寄存器的MAMPx[3:0]位来选择三角波的幅度。内部的三角波
	计数器每次触发事件之后3个APB1时钟周期后累加1。计数器的值与DAC_DHRx寄存器的数值
	相加并丢弃溢出位后写入DAC_DORx寄存器。在传入DAC_DORx寄存器的数值小于MAMP[3:0]
	位定义的最大幅度时，三角波计数器逐步累加。一旦达到设置的最大幅度，则计数器开始递
	减，达到0后再开始累加，周而复始。
		
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
DAC Channel2波形功能选择:
	可选择:
	01:噪音波形产生功能
	1x:三角波产生功能
	00:禁用波形功能
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
DAC Channel2转换触发源选择
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
DAC Channel2 开启触发转换:
	当开启触发转换后，DAC的每一次转换都需要一个触发脉冲。
	触发脉冲源通过TSEL2选择.
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
DAC Channel2 输出缓冲器
DAC集成了2个输出缓存，可以用来减少输出阻抗，无需外部运放即可直接驱动外部负载。
Bit 17 BOFF2: DAC channel2 output buffer disable
This bit set and cleared by software to enable/disable DAC channel2 output buffer.
0: DAC channel2 output buffer enabled
1: DAC channel2 output buffer disabled
*/
void DAC_set_BOFF2(U8 e_d);

#define DAC_channel2_enable_output_buffer()		DAC_set_BOFF2(1)
#define DAC_channel2_disable_output_buffer()	DAC_set_BOFF2(0)

/*
使能DAC Channel2的转换
将DAC_CR寄存器的ENx位置’1’即可打开对DAC通道x的供电。经过一段启动时间tWAKEUP，
DAC通道x即被使能。
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
DAC Channel1 DMA使能: 
使能后在发生DAC触发事件(软件触发也可以),会触发一次DMA请求.
DAC的DMA请求不会累计，因此如果第2个外部触发发生在响应第1个外部触发之前，则不能处
理第2个DMA请求，也不会报告错误。 
Bit 12 DMAEN1: DAC channel1 DMA enable
This bit is set and cleared by software. 
0: DAC channel1 DMA mode disabled
1: DAC channel1 DMA mode enabled
*/
void DAC_set_DMAEN1(U8 e_d);

#define DAC_channel1_enable_DMA()	DAC_set_DMAEN1(1)
#define DAC_channel1_disable_DMA()	DAC_set_DMAEN1(0)


/*
DAC Channel1 屏蔽位和振幅选择:
	此位段的功能根据WAVE位段的选择而改变.
	选择非屏蔽位(WAVE=01):
		当开启[噪音]功能时，该位段用来选择噪音发生器所产生的噪音的有效位.
	振幅选择(WAVE=1x)	:
													设置WAVEx[1:0]位为’10’选择DAC
	的三角波生成功能。设置DAC_CR寄存器的MAMPx[3:0]位来选择三角波的幅度。内部的三角波
	计数器每次触发事件之后3个APB1时钟周期后累加1。计数器的值与DAC_DHRx寄存器的数值
	相加并丢弃溢出位后写入DAC_DORx寄存器。在传入DAC_DORx寄存器的数值小于MAMP[3:0]
	位定义的最大幅度时，三角波计数器逐步累加。一旦达到设置的最大幅度，则计数器开始递
	减，达到0后再开始累加，周而复始。
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
DAC Channel1波形功能选择:
	可选择:
	01:噪音波形产生功能
	1x:三角波产生功能
	00:禁用波形功能
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
DAC Channel1转换触发源选择
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
DAC Channel1 开启触发转换:
	当开启触发转换后，DAC的每一次转换都需要一个触发脉冲。
	触发脉冲源通过TSEL2选择.
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
DAC Channel1 输出缓冲器
DAC集成了2个输出缓存，可以用来减少输出阻抗，无需外部运放即可直接驱动外部负载。
Bit 1 BOFF1: DAC channel1 output buffer disable
This bit set and cleared by software to enable/disable DAC channel1 output buffer.
0: DAC channel1 output buffer enabled
1: DAC channel1 output buffer disabled
*/
void DAC_set_BOFF1(U8 e_d);

#define DAC_channel1_enable_output_buffer()		DAC_set_BOFF1(1)
#define DAC_channel1_disable_output_buffer()	DAC_set_BOFF1(0)

/*
使能DAC Channel1的转换
将DAC_CR寄存器的ENx位置’1’即可打开对DAC通道x的供电。经过一段启动时间tWAKEUP，
DAC通道x即被使能。
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
此寄存器用来产生DAC Channel1 和 Channel2 的软件触发脉冲
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
	此函数用来设置在不同对其模式下
	对不同的转换前数值寄存器的设置.
	align_mode:
			0:12位左对齐
			1:12位右对齐
			2:8位右对齐(8位没有左对齐)
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
	此函数用来设置在不同对其模式下
	对不同的转换前数值寄存器的设置.
	align_mode:
			0:12位左对齐
			1:12位右对齐
			2:8位右对齐(8位没有左对齐)
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
	在双DAC模式下，需要一起设置DHR1和DHR2寄存器，并且已经提供了附属寄存器（以上3个）
	对这三个寄存器的分别一次性写可以同时给DHR1和DHR2写。
	在触发模式下也可以用上面的方式进行写，但在非触发模式下想要同时启动Channel1和
	Channel2就必须使用这个函数
*/
void DAC_set_DHRxD(U32 dhrC1, U32 dhrC2);

#define DAC_dual_set_holding_data(hd1, hd2)	DAC_set_DHRxD(hd1, hd2)

U32 DAC_get_DHRxD(U32 dhrC1, U32 dhrC2);

#define DAC_dual_get_holding_data()			DAC_get_DHRxD()


//********************************************************//
//*******************DAC DAC_DALIM************************//
//********************************************************//
/*
	DAC数据对其模式设置
	并返回之前设置的值
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
	Channel2的转换结果输出值
	这个寄存器里放置着将要转换为模拟电压的值
	这个寄存器里的值来自DHRx寄存器，转移的过程时是可控制的。
	转移过程中可:
		噪音生成和过滤.
		三角波生成
		无改变
	转移可在未使能触发时自发进行，如果使能了触发转换则需要在每一次
	触发信号到来时进行。
	其中噪音生成和三角波生成必须在触发下进行。
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
	Channel1的转换结果输出值
	这个寄存器里放置着将要转换为模拟电压的值
	这个寄存器里的值来自DHRx寄存器，转移的过程时是可控制的。
	转移过程中可:
		噪音生成和过滤.
		三角波生成
		无改变
	转移可在未使能触发时自发进行，如果使能了触发转换则需要在每一次
	触发信号到来时进行。
	其中噪音生成和三角波生成必须在触发下进行。
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
