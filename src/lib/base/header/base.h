

#ifndef __BASE__
#define __BASE__



/*
此文档定义了ADC1（暂时）的所有寄存器和对这些寄存器操作的函数
这些函数的命名规则如下:
	对于规则通道一律不加以指出，注入通道则反之
	获取标志一般有两种函数形式get_xxx_flag和is_xxx_STAT
	也可以在中断里这么问is_interrupted_by_xxx
	其它的命名规则请自己观察
*/

#ifndef __ADC
#define __ADC

#include "com.h"


//纯地址定义
#define __ADC1_SR		ADC1_BASE + 0x00000000
#define __ADC1_CR1		ADC1_BASE + 0x00000004
#define __ADC1_CR2		ADC1_BASE + 0x00000008
#define __ADC1_SMPR1	ADC1_BASE + 0x0000000C
#define __ADC1_SMPR2	ADC1_BASE + 0x00000010
#define __ADC1_JOFR1	ADC1_BASE + 0x00000014
#define __ADC1_JOFR2	ADC1_BASE + 0x00000018
#define __ADC1_JOFR3	ADC1_BASE + 0x0000001C
#define __ADC1_JOFR4	ADC1_BASE + 0x00000020
#define __ADC1_HTR		ADC1_BASE + 0x00000024
#define __ADC1_LTR		ADC1_BASE + 0x00000028
#define __ADC1_SQR1		ADC1_BASE + 0x0000002C
#define __ADC1_SQR2		ADC1_BASE + 0x00000030
#define __ADC1_SQR3		ADC1_BASE + 0x00000034
#define __ADC1_JSQR		ADC1_BASE + 0x00000038
#define __ADC1_JDR1		ADC1_BASE + 0x0000003C
#define __ADC1_JDR2		ADC1_BASE + 0x00000040
#define __ADC1_JDR3		ADC1_BASE + 0x00000044
#define __ADC1_JDR4		ADC1_BASE + 0x00000048
#define __ADC1_DR		ADC1_BASE + 0x0000004C

//地址定义
#define _ADC1_SR		ADR(__ADC1_SR)		
#define _ADC1_CR1		ADR(__ADC1_CR1)
#define _ADC1_CR2		ADR(__ADC1_CR2)
#define _ADC1_SMPR1		ADR(__ADC1_SMPR1)
#define _ADC1_SMPR2		ADR(__ADC1_SMPR2)
#define _ADC1_JOFR1		ADR(__ADC1_JOFR1)
#define _ADC1_JOFR2		ADR(__ADC1_JOFR2)
#define _ADC1_JOFR3		ADR(__ADC1_JOFR3)
#define _ADC1_JOFR4		ADR(__ADC1_JOFR4)
#define _ADC1_HTR		ADR(__ADC1_HTR)
#define _ADC1_LTR		ADR(__ADC1_LTR)
#define _ADC1_SQR1		ADR(__ADC1_SQR1)
#define _ADC1_SQR2		ADR(__ADC1_SQR2)
#define _ADC1_SQR3		ADR(__ADC1_SQR3)
#define _ADC1_JSQR		ADR(__ADC1_JSQR)
#define _ADC1_JDR1		ADR(__ADC1_JDR1)
#define _ADC1_JDR2		ADR(__ADC1_JDR2)	
#define _ADC1_JDR3		ADR(__ADC1_JDR3)
#define _ADC1_JDR4		ADR(__ADC1_JDR4)
#define _ADC1_DR		ADR(__ADC1_DR)


//值定义
#define  ADC1_SR		VAL(__ADC1_SR)		
#define  ADC1_CR1		VAL(__ADC1_CR1)
#define  ADC1_CR2		VAL(__ADC1_CR2)
#define  ADC1_SMPR1		VAL(__ADC1_SMPR1)
#define  ADC1_SMPR2		VAL(__ADC1_SMPR2)
#define  ADC1_JOFR1		VAL(__ADC1_JOFR1)
#define  ADC1_JOFR2		VAL(__ADC1_JOFR2)
#define  ADC1_JOFR3		VAL(__ADC1_JOFR3)
#define  ADC1_JOFR4		VAL(__ADC1_JOFR4)
#define  ADC1_HTR		VAL(__ADC1_HTR)
#define  ADC1_LTR		VAL(__ADC1_LTR)
#define  ADC1_SQR1		VAL(__ADC1_SQR1)
#define  ADC1_SQR2		VAL(__ADC1_SQR2)
#define  ADC1_SQR3		VAL(__ADC1_SQR3)
#define  ADC1_JSQR		VAL(__ADC1_JSQR)
#define  ADC1_JDR1		VAL(__ADC1_JDR1)
#define  ADC1_JDR2		VAL(__ADC1_JDR2)	
#define  ADC1_JDR3		VAL(__ADC1_JDR3)
#define  ADC1_JDR4		VAL(__ADC1_JDR4)
#define  ADC1_DR		VAL(__ADC1_DR)







//*********************************ADC status register (ADC_SR)*****************//

/*
ADC状态寄存器
Address offset: 0x00
Reset value: 0x0000 0000
*/


/*
Bits 31:5
Reserved, must be kept cleared.
*/

/*
普通通道转换开始位
Bit 4 STRT: Regular channel Start flag 
This bit is set by hardware when regular channel conversion starts. It is cleared by software.
0: No regular channel conversion started
1: Regular channel conversion has started
*/
U8 	ADC1_get_STRT(void);
#define ADC1_get_convert_start_flag()	ADC1_get_STRT()
#define ADC1_is_convert_start()					ADC1_get_STRT()

void ADC1_clear_STRT(void);
#define ADC1_clear_convert_start_flag()	ADC1_clear_STRT()

/*
注入转换通道开始位
Bit 3 JSTRT: Injected channel Start flag
This bit is set by hardware when injected channel group conversion starts. It is cleared by 
software.
0: No injected group conversion started
1: Injected group conversion has started
*/
U8	ADC1_get_JSTRT(void);

#define ADC1_get_inject_convert_start_flag()	ADC1_get_JSTRT()
#define ADC1_is_inject_convert_start()			ADC1_get_JSTRT()

void ADC1_clear_JSTRT(void);

#define ADC1_clear_inject_convert_start_flag()	ADC1_clear_JSTRT()

/*
注入转换结束
Bit 2 JEOC: Injected channel end of conversion
This bit is set by hardware at the end of all injected group channel conversion. It is cleared by 
software. 
0: Conversion is not complete 
1: Conversion complete
*/
U8	ADC1_get_JEOC(void);

#define ADC1_get_inject_convert_end_flag()			ADC1_get_JEOC()
#define ADC1_is_inject_convert_end()				ADC1_get_JEOC()
#define ADC1_is_interrupted_by_inject_convert_end()	ADC1_get_JEOC()

void ADC1_clear_JEOC(void);
#define ADC1_clear_inject_convert_end_flag()		ADC1_clear_JEOC()

/*
普通转换结束
Bit 1 EOC: End of conversion
This bit is set by hardware at the end of a group channel conversion (regular or injected). It is 
cleared by software or by reading the ADC_DR. 
0: Conversion is not complete 
1: Conversion complete
*/
U8	ADC1_get_EOC(void);
#define ADC1_get_convert_end_flag()				ADC1_get_EOC()
#define ADC1_is_convert_end()					ADC1_get_EOC()
#define ADC1_is_interrupted_by_convert_end()	ADC1_get_EOC()

void ADC1_clear_EOC(void);
#define ADC1_clear_convert_end_flag()			ADC1_clear_EOC()

/*
模拟看门狗事件标志
Bit 0 AWD: Analog watchdog flag 
This bit is set by hardware when the converted voltage crosses the values programmed in 
the ADC_LTR and ADC_HTR registers. It is cleared by software.
0: No Analog watchdog event occurred
1: Analog watchdog event occurred
*/
U8	ADC1_get_AWD(void);
#define ADC1_get_watchdog_event_flag()			ADC1_get_AWD()
#define ADC1_is_watchdog_event_occured()		ADC1_get_AWD()
#define ADC1_is_interruped_by_watchdog_event()	ADC1_get_AWD()
void ADC1_clear_AWD(void);
#define ADC1_clear_watchdog_event_flag()		ADC1_clear_AWD()


//*****************************ADC control register 1 (ADC_CR1)****************************//

/*
ADC1控制寄存器1
ADC control register 1 (ADC_CR1)
Address offset: 0x04
Reset value: 0x0000 0000
*/
/*
Bits 31:24 Reserved, must be kept cleared.
*/

/*
为普通通道使能模拟看门狗
Bit 23 AWDEN: Analog watchdog enable on regular channels
This bit is set/reset by software.
0: Analog watchdog disabled on regular channels
1: Analog watchdog enabled on regular channels
*/
void ADC1_set_AWDEN(U8 e_d);

#define ADC1_enable_watchdog()	ADC1_set_AWDEN(1)
#define ADC1_disable_watchdog()	ADC1_set_AWDEN(0)

/*
为注入通道使能模拟看门狗
Bit 22 JAWDEN: Analog watchdog enable on injected channels
This bit is set/reset by software.
0: Analog watchdog disabled on injected channels
1: Analog watchdog enabled on injected channels
*/
void ADC1_set_JAWDEN(U8 e_d);

#define ADC1_enable_inject_watchdog()	ADC1_set_JAWDEN(1)
#define ADC1_disable_inject_watchdog()	ADC1_set_JAWDEN(0)

/*
Bits 21:20
Reserved, must be kept cleared.
*/

/*
双ADC工作模式选择
Bits 19:16 DUALMOD[3:0]: Dual mode selection
These bits are written by software to select the operating mode.
0000: Independent mode. 
0001: Combined regular simultaneous + injected simultaneous mode 
0010: Combined regular simultaneous + alternate trigger mode
0011: Combined injected simultaneous + fast interleaved mode 
0100: Combined injected simultaneous + slow Interleaved mode 
0101: Injected simultaneous mode only
0110: Regular simultaneous mode only
0111: Fast interleaved mode only
1000: Slow interleaved mode only
1001: Alternate trigger mode only
Note: These bits are reserved in ADC2 and ADC3.
In dual mode, a change of channel configuration generates a restart that can produce a 
loss of synchronization. It is recommended to disable dual mode before any 
configuration change.
*/
void ADC1_set_DUALMOD(U8 mod);
U8	ADC1_get_DUALMOD(void);



/*
间断模式每一次触发转换的单位数目
Bits 15:13 DISCNUM[2:0]: Discontinuous mode channel count
These bits are written by software to define the number of regular channels to be converted 
in discontinuous mode, after receiving an external trigger.
000: 1 channel
001: 2 channels
.......
111: 8 channels
*/
void ADC1_set_DISCNUM(U8 num);
#define ADC1_set_discontinuous_number(num)	ADC1_set_DISCNUM(num)
#define ADC1_set_discontinuous_mode_number(num)	ADC1_set_DISCNUM(num)

U8	ADC1_get_DISNUM(void);

#define ADC1_get_discontinuous_number()		ADC1_get_DISNUM()
#define ADC1_get_discontinuous_mode_number()		ADC1_get_DISNUM()

/*
使能注入通道的间断模式 （不能和规则通道的间断模式一起使用）
Bit 12 JDISCEN: Discontinuous mode on injected channels
This bit set and cleared by software to enable/disable discontinuous mode on injected group 
channels
0: Discontinuous mode on injected channels disabled
1: Discontinuous mode on injected channels enabled
*/
void ADC1_set_JDISCEN(U8 e_d);

#define ADC1_enable_inject_discontinuous()			ADC1_set_JDISCEN(1)
#define ADC1_enable_inject_discontinuous_mode()		ADC1_set_JDISCEN(1)
#define ADC1_disable_inject_discontinuous()			ADC1_set_JDISCEN(0)
#define ADC1_disable_inject_discontinuous_mode()	ADC1_set_JDISCEN(0)


/*
使能规则通道的间断模式  （不能和注入通道的间断模式一起使用）
Bit 11 DISCEN: Discontinuous mode on regular channels
This bit set and cleared by software to enable/disable Discontinuous mode on regular 
channels.
0: Discontinuous mode on regular channels disabled
1: Discontinuous mode on regular channels enabled
*/
void ADC1_set_DISCEN(U8 e_d);

#define ADC1_enable_discontinuous()			ADC1_set_DISCEN(1)
#define ADC1_enable_discontinuous_mode()	ADC1_set_DISCEN(1)

#define ADC1_disable_discontinuous()			ADC1_set_DISCEN(0)
#define ADC1_disable_discontinuous_mode()	ADC1_set_DISCEN(0)

/*
注入通道的自动切换使能 (规则通道的SCAN完成后，
自动进入注入通道的SCAN，完成后再回到规则通道的SCAN(如果CONT使能的话))
Bit 10 JAUTO: Automatic Injected Group conversion 
This bit set and cleared by software to enable/disable automatic injected group conversion 
after regular group conversion.
0: Automatic injected group conversion disabled 
1: Automatic injected group conversion enabled
*/
void ADC1_set_JAUTO(U8 e_d);

#define ADC1_enable_inject_auto()		ADC1_set_JAUTO(1)
#define ADC1_enable_inject_auto_mode()	ADC1_set_JAUTO(1)

#define ADC1_disable_inject_auto()		ADC1_set_JAUTO(0)
#define ADC1_disable_inject_auto_mode()	ADC1_set_JAUTO(0)


/*
将模拟看门狗使用在单一通道上还是所有的通道,具体那一个单一通道选择在AWDCH位段
Bit 9 AWDSGL: Enable the watchdog on a single channel in scan mode
This bit set and cleared by software to enable/disable the analog watchdog on the channel 
identified by the AWDCH[4:0] bits.
0: Analog watchdog enabled on all channels
1: Analog watchdog enabled on a single channel 
*/
void ADC1_set_AWDSGL(U8 single_or_all);
#define ADC1_use_watchdog_at_where(s_a)			ADC1_set_AWDSGL(s_a)

#define ADC1_use_watchdog_at_all_channels()		ADC1_set_AWDSGL(0)
#define ADC1_use_watchdog_at_single_channel()	ADC1_set_AWDSGL(1)

/*
使能SCAN模式
注:	SCAN所有的通道后才会产生中断，而DR中只存储了最后一个通道的结果，
	所以中间必须使用DMA将每个通道的转换结果存贮到指定的位置
Bit 8 SCAN: Scan mode 
This bit is set and cleared by software to enable/disable Scan mode. In Scan mode, the 
inputs selected through the ADC_SQRx or ADC_JSQRx registers are converted. 
0: Scan mode disabled
1: Scan mode enabled
Note: An EOC or JEOC interrupt is generated only on the end of conversion of the last 
channel if the corresponding EOCIE or JEOCIE bit is set
*/
void ADC1_set_SCAN(U8 e_d);

#define ADC1_enable_scan_mode()		ADC1_set_SCAN(1)
#define ADC1_disable_scan_mode()	ADC1_set_SCAN(0)

/*
使能在注入通道转换完成后的中断
Bit 7 JEOCIE: Interrupt enable for injected channels
This bit is set and cleared by software to enable/disable the end of conversion interrupt for 
injected channels. 
0: JEOC interrupt disabled
1: JEOC interrupt enabled. An interrupt is generated when the JEOC bit is set.
*/
void ADC1_set_JEOIE(U8 e_d);

#define ADC1_enable_interrupt_at_inject_convert_end()	ADC1_set_JEOIE(1)
#define ADC1_disable_interrupt_at_inject_convert_end()	ADC1_set_JEOIE(0)

/*
使能模拟看门狗事件中断(如果电压超过阈值，看门狗会叫)
Bit 6 AWDIE: Analog watchdog interrupt enable 
This bit is set and cleared by software to enable/disable the analog watchdog interrupt. In 
Scan mode if the watchdog thresholds are crossed, scan is aborted only if this bit is enabled.
0: Analog watchdog interrupt disabled 
1: Analog watchdog interrupt enabled
*/
void ADC1_set_AWDIE(U8 e_d);

#define ADC1_enable_interrupt_at_watchdog_event()	ADC1_set_AWDIE(1)
#define ADC1_disable_interrupt_at_watchdog_event()	ADC1_set_AWDIE(0)

/*
使能规则通道的转换事件中断
Bit 5 EOCIE: Interrupt enable for EOC 
This bit is set and cleared by software to enable/disable the End of Conversion interrupt. 
0: EOC interrupt disabled
1: EOC interrupt enabled. An interrupt is generated when the EOC bit is set.
*/
void ADC1_set_EOCIE(U8 e_d);

#define ADC1_enable_interrupt_at_convert_end()	ADC1_set_EOCIE(1)
#define ADC1_disable_interrupt_at_convert_end()	ADC1_set_EOCIE(0)


/*
选择模拟看门狗在为一个通道工作时的通道
Bits 4:0 AWDCH[4:0]: Analog watchdog channel select bits 
These bits are set and cleared by software. They select the input channel to be guarded by 
the Analog watchdog. 
00000: ADC analog Channel0 
00001: ADC analog Channel1
....
01111: ADC analog Channel15
10000: ADC analog Channel16
10001: ADC analog Channel17
Other values reserved.
*/
void ADC1_set_AWDCH(U8 channelNum);

#define ADC1_select_watchdog_channel(cN)		ADC1_set_AWDCH(cN)

/*
Note: ADC1 analog Channel16 and Channel17 are internally connected to the temperature 
sensor and to VREFINT, respectively.
ADC2 analog inputs Channel16 and Channel17 are internally connected to VSS.
ADC3 analog inputs Channel9, Channel14, Channel15, Channel16 and Channel17 are 
connected to VSS.
*/

//***********************ADC control register 2 (ADC_CR2)*************************//
/*
ADC control register 2 (ADC_CR2)
Address offset: 0x08
Reset value: 0x0000 0000
*/

/*
Bits 31:24
Reserved, must be kept cleared.
*/

/*
内部温度传感和参考电压VREF使能,如果要是用内部温度，则需要使能该位
Bit 23 TSVREFE: Temperature sensor and VREFINT enable
This bit is set and cleared by software to enable/disable the temperature sensor and VREFINT 
channel. In devices with dual ADCs this bit is present only in ADC1.
0: Temperature sensor and VREFINT channel disabled
1: Temperature sensor and VREFINT channel enabled
*/
void ADC1_set_TSVREFE(U8 e_d);

#define ADC1_enable_temperature()	ADC1_set_TSVREFE(1)
#define ADC1_disable_temperature()	ADC1_set_TSVREFE(0)

/*
规则通道的外部触发模式软件模拟触发
Bit 22 SWSTART: Start conversion of regular channels
This bit is set by software to start conversion and cleared by hardware as soon as conversion 
starts. It starts a conversion of a group of regular channels if SWSTART is selected as trigger 
event by the EXTSEL[2:0] bits. 
0: Reset state
1: Starts conversion of regular channels
*/
void ADC1_set_SWSTART(void);

#define ADC1_generate_trigger()		ADC1_set_SWSTART()	//生成规则通道的外部触发信号


/*
注入通道的外部触发模式软件模拟触发
Bit 21 JSWSTART: Start conversion of injected channels
This bit is set by software and cleared by software or by hardware as soon as the conversion 
starts. It starts a conversion of a group of injected channels (if JSWSTART is selected as 
trigger event by the JEXTSEL[2:0] bits. 
0: Reset state
1: Starts conversion of injected channels
*/
void ADC1_set_JSWSTART(void);

#define ADC1_generate_inject_trigger()	ADC1_set_JSWSTART()  //生成注入通道的外部触发信号


/*
规则通道的外部触发模式使能
Bit 20 EXTTRIG: External trigger conversion mode for regular channels
This bit is set and cleared by software to enable/disable the external trigger used to start 
conversion of a regular channel group.
0: Conversion on external event disabled
1: Conversion on external event enabled
*/
void ADC1_set_EXTTRIG(U8 e_d);

#define ADC1_enable_external_trigger()		ADC1_set_EXTTRIG(1)		//使能规则通道的外部触发模式
#define ADC1_disable_external_trigger()    ADC1_set_EXTTRIG(0)     //除能规则通道的外部触发模式


/*
规则通道外部触发源选择
Bits 19:17 EXTSEL[2:0]: External event select for regular group
These bits select the external event used to trigger the start of conversion of a regular group:
For ADC1 and ADC2, the assigned triggers are:
000: Timer 1 CC1 event
001: Timer 1 CC2 event
010: Timer 1 CC3 event
011: Timer 2 CC2 event
100: Timer 3 TRGO event
101: Timer 4 CC4 event
110: EXTI line11/TIM8_TRGO event (TIM8_TRGO is available only in high-density and XL-
density devices) 可以分别通过设置ADC1和ADC2的ADC1_ETRGREG_REMAP位和ADC2_ETRGREG_REMAP位实现。
111: SWSTART
For ADC3, the assigned triggers are:
000: Timer 3 CC1 event
001: Timer 2 CC3 event
010: Timer 1 CC3 event
011: Timer 8 CC1 event
100: Timer 8 TRGO event
101: Timer 5 CC1 event
110: Timer 5 CC3 event
111: SWSTART
*/
void ADC1_set_EXTSEL(U8 sel);

#define ADC1_set_trigger_source(sel)	ADC1_set_EXTSEL(sel)	//设置规则通道外部触发的触发源

#define ADC1_set_trigger_source_TIM1_CC1()	ADC1_set_EXTSEL(0)  //TIM1的捕获比较通道1触发
#define ADC1_set_trigger_source_TIM1_CC2()	ADC1_set_EXTSEL(1)  //TIM1的捕获比较通道2触发
#define ADC1_set_trigger_source_TIM1_CC3()	ADC1_set_EXTSEL(2)  //TIM1的捕获比较通道3触发
#define ADC1_set_trigger_source_TIM2_CC2()	ADC1_set_EXTSEL(3)  //TIM2的捕获比较通道2触发
#define ADC1_set_trigger_source_TIM3_TRGO()	ADC1_set_EXTSEL(4)  //TIM3的外部时钟触发
#define ADC1_set_trigger_source_TIM4_CC4()	ADC1_set_EXTSEL(5)  //TIM4的捕获比较通道4触发
#define ADC1_set_trigger_source_EXTI1_or_TIM8_TRGO()	ADC1_set_EXTSEL(6)	//可以分别通过设置ADC1和ADC2的ADC1_ETRGREG_REMAP位和ADC2_ETRGREG_REMAP位实现。
#define ADC1_set_trigger_source_software()	ADC1_set_EXTSEL(7)	//软件触发

/*
Bit 16
Reserved, must be kept cleared.
*/

/*
注入通道外部触发使能
Bit 15 JEXTTRIG: External trigger conversion mode for injected channels
This bit is set and cleared by software to enable/disable the external trigger used to start 
conversion of an injected channel group.
0: Conversion on external event disabled
1: Conversion on external event enabled
*/
void ADC1_set_JEXTTRIG(U8 e_d);

#define ADC1_enable_inject_trigger()   ADC1_set_JEXTTRIG(1)	//使能注入通道的外部触发
#define ADC1_disable_inject_trigger()	ADC1_set_JEXTTRIG(0)	//除能注入通道的外部触发


/*
注入通道外部触发源选择
Bits 14:12 JEXTSEL[2:0]: External event select for injected group
These bits select the external event used to trigger the start of conversion of an injected 
group:
For ADC1 and ADC2 the assigned triggers are:
000: Timer 1 TRGO event
001: Timer 1 CC4 event
010: Timer 2 TRGO event
011: Timer 2 CC1 event
100: Timer 3 CC4 event
101: Timer 4 TRGO event
110: EXTI line15/TIM8_CC4 event (TIM8_CC4 is available only in high-density and XL-
density devices)
111: JSWSTART
For ADC3 the assigned triggers are:
000: Timer 1 TRGO event
001: Timer 1 CC4 event
010: Timer 4 CC3 event
011: Timer 8 CC2 event
100: Timer 8 CC4 event
101: Timer 5 TRGO event
110: Timer 5 CC4 event
111: JSWSTART
*/
void ADC1_set_JEXTSEL(U8 sel);

#define ADC1_set_inject_trigger_source(sel)		ADC1_set_JEXTSEL(sel)	//设置规则通道外部触发的触发源

#define ADC1_set_inject_trigger_source_TIM1_CC1()			ADC1_set_JEXTSEL(0)  	//TIM1的捕获比较通道1触发
#define ADC1_set_inject_trigger_source_TIM1_CC2()			ADC1_set_JEXTSEL(1)  	//TIM1的捕获比较通道2触发
#define ADC1_set_inject_trigger_source_TIM1_CC3()			ADC1_set_JEXTSEL(2)  	//TIM1的捕获比较通道3触发
#define ADC1_set_inject_trigger_source_TIM2_CC2()			ADC1_set_JEXTSEL(3)  	//TIM2的捕获比较通道2触发
#define ADC1_set_inject_trigger_source_TIM3_TRGO()			ADC1_set_JEXTSEL(4)  	//TIM3的外部时钟触发
#define ADC1_set_inject_trigger_source_TIM4_CC4()			ADC1_set_JEXTSEL(5) 	//TIM4的捕获比较通道4触发
#define ADC1_set_inject_trigger_source_EXTI1_or_TIM8_TRGO()	ADC1_set_JEXTSEL(6)		//可以分别通过设置ADC1和ADC2的ADC1_ETRGREG_REMAP位和ADC2_ETRGREG_REMAP位实现。
#define ADC1_set_inject_trigger_source_software()			ADC1_set_JEXTSEL(7)		//软件触发

/*
转换后数据对其方式
Bit 11 ALIGN: Data alignment
This bit is set and cleared by software. Refer to Figure 31.and Figure 32.
0: Right Alignment 
1:Left Alignment
*/
void ADC1_set_ALIGN(U8 a);

#define ADC1_set_data_align_left()	ADC1_set_ALIGN(1)
#define ADC1_set_data_align_right()	ADC1_set_ALIGN(0)

/*
Bits 10:9
Reserved, must be kept cleared.
*/

/*
DMA使能
Bit 8 DMA: Direct memory access mode
This bit is set and cleared by software. Refer to the DMA controller chapter for more details.
0: DMA mode disabled
1: DMA mode enabled
Only ADC1 and ADC3 can generate a DMA request.
*/
void ADC1_set_DMA(U8 e_d);

#define ADC1_enable_DMA()	ADC1_set_DMA(1)
#define ADC1_disable_DMA()	ADC1_set_DMA(0)

/*
Bits 7:4
Reserved, must be kept cleared.
*/

/*
初始化校准， 软件设置之后，由硬件在初始化寄存器后置零
Bit 3 RSTCAL: Reset calibration
This bit is set by software and cleared by hardware. It is cleared after the calibration registers 
are initialized.
0: Calibration register initialized. 
1: Initialize calibration register.
Note: If RSTCAL is set when conversion is ongoing, additional cycles are required to clear the 
calibration registers.
*/
void ADC1_set_RSTCAL(void);
U8	ADC1_get_RSTCAL(void);

#define ADC1_reset_calibration()			ADC1_set_RSTCAL()	//复位校准
#define	ADC1_is_reset_calibration_done()	(!ADC1_get_RSTCAL())	//复位是否完成

/*
开始校准
Bit 2 CAL: A/D Calibration
This bit is set by software to start the calibration. It is reset by hardware after calibration is 
complete. 
0: Calibration completed 
1: Enable calibration
*/
void ADC1_set_CAL(void);  //开始校准
U8	ADC1_get_CAL(void);	//获得校准的状态

#define ADC1_start_calibration()	ADC1_set_CAL()
#define ADC1_is_calibration_done()	(!ADC1_get_CAL())


/*
连续转换还是单次转换模式
Bit 1 CONT: Continuous conversion
This bit is set and cleared by software. If set conversion takes place continuously till this bit is 
reset. 
0: Single conversion mode 
1: Continuous conversion mode 
*/
void ADC1_set_CONT(U8	c);

//命名1
#define ADC1_enable_continuous_mode()		ADC1_set_CONT(1)
#define ADC1_disable_continuous_mode()		ADC1_set_CONT(0)

//命名2
#define ADC1_set_conversion_in_continuous_mode()		ADC1_set_CONT(1)
#define ADC1_set_conversion_in_single_mode()			ADC1_set_CONT(0)

/*
使能ADC
Bit 0 ADON: A/D converter ON / OFF
This bit is set and cleared by software. If this bit holds a value of zero and a 1 is written to it 
then it wakes up the ADC from Power Down state.
Conversion starts when this bit holds a value of 1 and a 1 is written to it. The application 
should allow a delay of tSTAB between power up and start of conversion. Refer to Figure 27.
0: Disable ADC conversion/calibration and go to power down mode.
1: Enable ADC and to start conversion
*/
void ADC1_set_ADON(U8 e_d);

#define ADC1_enable_ADC()	ADC1_set_ADON(1)
#define ADC1_wake_up_ADC()	ADC1_set_ADON(1)
#define ADC1_disable_ADC()  ADC1_set_ADON(0)
#define ADC1_sleep_ADC()	ADC1_set_ADON(0)


/*
Note: If any other bit in this register apart from ADON is changed at the same time, then 
conversion is not triggered. This is to prevent triggering an erroneous conversion.
*/


//****ADC sample time register 1 (ADC_SMPR1) + ADC sample time register 2 (ADC_SMPR2)*****//

/*
选择通道的采样时间, SMPR1 和 SMPR2两个寄存器
Bits 23:0 SMPx[2:0]: Channel x Sample time selection   (17-10)
These bits are written by software to select the sample time individually for each channel. 
During sample cycles channel selection bits must remain unchanged.
000: 1.5 cycles
001: 7.5 cycles
010: 13.5 cycles
011: 28.5 cycles
100: 41.5 cycles
101: 55.5 cycles
110: 71.5 cycles
111: 239.5 cycles
Note: ADC1 analog Channel16 and Channel 17 are internally connected to the temperature 
sensor and to VREFINT, respectively.
ADC2 analog input Channel16 and Channel17 are internally connected to VSS.
ADC3 analog inputs Channel14, Channel15, Channel16 and Channel17 are connected 
to VSS.

Bits 29:0 SMPx[2:0]: Channel x Sample time selection   (9 - 0)
These bits are written by software to select the sample time individually for each channel. 
During sample cycles channel selection bits must remain unchanged.
000: 1.5 cycles
001: 7.5 cycles
010: 13.5 cycles
011: 28.5 cycles
100: 41.5 cycles
101: 55.5 cycles
110: 71.5 cycles
111: 239.5 cycles
Note: ADC3 analog input Channel9 is connected to VSS.
*/
//channel = 0 - 17, cycle = 000 - 111
void ADC1_set_SMPx(U8 channel, U8 cycle);

#define ADC1_set_sample_time(channel, cycle)	ADC1_set_SMPx(channel, cycle)

#define ADC1_set_sample_time_1_5(channel)		ADC1_set_SMPx(channel, 0)    //1.5
#define ADC1_set_sample_time_7_5(channel)		ADC1_set_SMPx(channel, 1)    //7.5
#define ADC1_set_sample_time_13_5(channel)		ADC1_set_SMPx(channel, 2)    //13.5
#define ADC1_set_sample_time_28_5(channel)		ADC1_set_SMPx(channel, 3)    //28.5
#define ADC1_set_sample_time_41_5(channel)		ADC1_set_SMPx(channel, 4)    //41.5
#define ADC1_set_sample_time_55_5(channel)		ADC1_set_SMPx(channel, 5)    //55.5
#define ADC1_set_sample_time_71_5(channel)		ADC1_set_SMPx(channel, 6)    //71.5
#define ADC1_set_sample_time_239_5(channel)		ADC1_set_SMPx(channel, 7)    //239.5



//************ADC injected channel data offset register x (ADC_JOFRx)(x=1..4)*******//
/*
ADC injected channel data offset register x (ADC_JOFRx)(x=1..4)
Address offset: 0x14-0x20
Reset value: 0x0000 0000
*/
/*
Bits 31:12
 Reserved, must be kept cleared.
*/

/*
注入通道转换数据偏移量设定（注入通道转换的数据将减去这个值存储在JDRx中）
Bits 11:0 JOFFSETx[11:0]: Data offset for injected channel x
These bits are written by software to define the offset to be subtracted from the raw 
converted data when converting injected channels. The conversion result can be read from 
in the ADC_JDRx registers.
*/
//channel = 1 - 4
void ADC1_set_JPFFSETx(U8 channel, U16 offset);

#define ADC1_set_inject_channel1_offset(offset) ADC1_set_JPFFSETx(1, offset)
#define ADC1_set_inject_channel2_offset(offset) ADC1_set_JPFFSETx(2, offset)
#define ADC1_set_inject_channel3_offset(offset) ADC1_set_JPFFSETx(3, offset)
#define ADC1_set_inject_channel4_offset(offset) ADC1_set_JPFFSETx(4, offset)

//*******ADC watchdog high threshold register (ADC_HTR)*********//
/*
ADC watchdog high threshold register (ADC_HTR)
Address offset: 0x24
Reset value: 0x0000 0FFF
*/

/*
Bits 31:12
Reserved, must be kept cleared.
*/

/*
模拟看门狗的警告上界
Bits 11:0 HT[11:0]: Analog watchdog high threshold 
These bits are written by software to define the high threshold for the analog watchdog.
*/
void ADC1_set_HT(U16 ht);
U16	ADC1_get_HT(void);

#define ADC1_set_watchdog_high_threshold(ht)	 ADC1_set_HT(ht)
#define ADC1_get_watchdog_high_threshold()		 ADC1_get_HT()

//***********ADC watchdog low threshold register (ADC_LTR)***********//
/*
ADC watchdog low threshold register (ADC_LTR)
Address offset: 0x28
Reset value: 0x0000 0000
*/
/*
Bits 31:12
Reserved, must be kept cleared.
*/

/*
模拟看门狗警告下界
Bits 11:0 LT[11:0]: Analog watchdog low threshold 
These bits are written by software to define the low threshold for the analog watchdog.
*/
void ADC1_set_LT(U16 lt);
U16	ADC1_get_LT(void);

#define ADC1_set_watchdog_low_threshold(lt)	ADC1_set_LT(lt)
#define ADC1_get_watchdog_low_threshold()	ADC1_get_LT()

//规则通道转换序列寄存器(在此合并)
//*********ADC regular sequence register 1 (ADC_SQR1)**************//
//*********ADC regular sequence register 2 (ADC_SQR2)**************//
//*********ADC regular sequence register 3 (ADC_SQR3)**************//

/*
扫描转换的通道数
Bits 23:20 L[3:0]: Regular channel sequence length
These bits are written by software to define the total number of conversions in the regular 
channel conversion sequence.
0000: 1 conversion
0001: 2 conversions 
.....
1111: 16 conversions
*/
void ADC1_set_L(U8 l);

#define ADC1_set_sequence_length(l)	ADC1_set_L((l)-1)


//命名1
#define ADC1_set_sequence_length_1()	ADC1_set_L(0)
#define ADC1_set_sequence_length_2()	ADC1_set_L(1)
#define ADC1_set_sequence_length_3()	ADC1_set_L(2)
#define ADC1_set_sequence_length_4()	ADC1_set_L(3)
#define ADC1_set_sequence_length_5()	ADC1_set_L(4)
#define ADC1_set_sequence_length_6()	ADC1_set_L(5)
#define ADC1_set_sequence_length_7()	ADC1_set_L(6)
#define ADC1_set_sequence_length_8()	ADC1_set_L(7)
#define ADC1_set_sequence_length_9()	ADC1_set_L(8)
#define ADC1_set_sequence_length_10()	ADC1_set_L(9)
#define ADC1_set_sequence_length_11()	ADC1_set_L(10)
#define ADC1_set_sequence_length_12()	ADC1_set_L(11)
#define ADC1_set_sequence_length_13()	ADC1_set_L(12)
#define ADC1_set_sequence_length_14()	ADC1_set_L(13)
#define ADC1_set_sequence_length_15()	ADC1_set_L(14)
#define ADC1_set_sequence_length_16()	ADC1_set_L(15)

//命名2
#define ADC1_set_scan_length(l)	ADC1_set_L((l)-1)

#define ADC1_set_scan_length_1()	ADC1_set_L(0)
#define ADC1_set_scan_length_2()	ADC1_set_L(1)
#define ADC1_set_scan_length_3()	ADC1_set_L(2)
#define ADC1_set_scan_length_4()	ADC1_set_L(3)
#define ADC1_set_scan_length_5()	ADC1_set_L(4)
#define ADC1_set_scan_length_6()	ADC1_set_L(5)
#define ADC1_set_scan_length_7()	ADC1_set_L(6)
#define ADC1_set_scan_length_8()	ADC1_set_L(7)
#define ADC1_set_scan_length_9()	ADC1_set_L(8)
#define ADC1_set_scan_length_10()	ADC1_set_L(9)
#define ADC1_set_scan_length_11()	ADC1_set_L(10)
#define ADC1_set_scan_length_12()	ADC1_set_L(11)
#define ADC1_set_scan_length_13()	ADC1_set_L(12)
#define ADC1_set_scan_length_14()	ADC1_set_L(13)
#define ADC1_set_scan_length_15()	ADC1_set_L(14)
#define ADC1_set_scan_length_16()	ADC1_set_L(15)


/*
规则通道在扫描模式下的序列
ADC_SQR1
Bits 19:15 	SQ16[4:0]: 16th conversion in regular sequence
These bits are written by software with the channel number (0..17) assigned as the 16th in 
the conversion sequence.
Bits 14:10 	SQ15[4:0]: 15th conversion in regular sequence
Bits 9:5 	SQ14[4:0]: 14th conversion in regular sequence
Bits 4:0 	SQ13[4:0]: 13th conversion in regular sequence
ADC_SQR2
Bits 29:26 	SQ12[4:0]: 12th conversion in regular sequence
Bits 24:20 	SQ11[4:0]: 11th conversion in regular sequence
Bits 19:15 	SQ10[4:0]: 10th conversion in regular sequence
Bits 14:10 	SQ9[4:0]: 9th conversion in regular sequence
Bits 9:5 	SQ8[4:0]: 8th conversion in regular sequence
Bits 4:0 	SQ7[4:0]: 7th conversion in regular sequence
ADC_SQR3
Bits 29:25 	SQ6[4:0]: 6th conversion in regular sequence
Bits 24:20 	SQ5[4:0]: 5th conversion in regular sequence
Bits 19:15 	SQ4[4:0]: 4th conversion in regular sequence
Bits 14:10 	SQ3[4:0]: 3rd conversion in regular sequence
Bits 9:5 	SQ2[4:0]: 2nd conversion in regular sequence
Bits 4:0 	SQ1[4:0]: 1st conversion in regular sequence
*/
/*
	将第sqrNum个序列设置为channelNum通道
	sqrNum: 1 - 16
	channelNum: 0 - 17
*/
void ADC1_set_SQRx(U8 sqrNum, U8 channelNum);

#define ADC1_set_sequnce(sqrNum, channelNum)	ADC1_set_SQRx(sqrNum, channelNum)

#define ADC1_set_sequence1(channel)		ADC1_set_SQRx(1, channel)    //设置规则通道扫描模式的序列1
#define ADC1_set_sequence2(channel)		ADC1_set_SQRx(2, channel)    //设置规则通道扫描模式的序列2
#define ADC1_set_sequence3(channel)		ADC1_set_SQRx(3, channel)    //设置规则通道扫描模式的序列3
#define ADC1_set_sequence4(channel)		ADC1_set_SQRx(4, channel)    //设置规则通道扫描模式的序列4
#define ADC1_set_sequence5(channel)		ADC1_set_SQRx(5, channel)    //设置规则通道扫描模式的序列5
#define ADC1_set_sequence6(channel)		ADC1_set_SQRx(6, channel)    //设置规则通道扫描模式的序列6
#define ADC1_set_sequence7(channel)		ADC1_set_SQRx(7, channel)    //设置规则通道扫描模式的序列7
#define ADC1_set_sequence8(channel)		ADC1_set_SQRx(8, channel)    //设置规则通道扫描模式的序列8
#define ADC1_set_sequence9(channel)		ADC1_set_SQRx(9, channel)    //设置规则通道扫描模式的序列9
#define ADC1_set_sequence10(channel)	ADC1_set_SQRx(10, channel)   //设置规则通道扫描模式的序列10
#define ADC1_set_sequence11(channel)	ADC1_set_SQRx(11, channel)   //设置规则通道扫描模式的序列11
#define ADC1_set_sequence12(channel)	ADC1_set_SQRx(12, channel)   //设置规则通道扫描模式的序列12
#define ADC1_set_sequence13(channel)	ADC1_set_SQRx(13, channel)   //设置规则通道扫描模式的序列13
#define ADC1_set_sequence14(channel)	ADC1_set_SQRx(14, channel)   //设置规则通道扫描模式的序列14
#define ADC1_set_sequence15(channel)	ADC1_set_SQRx(15, channel)   //设置规则通道扫描模式的序列15
#define ADC1_set_sequence16(channel)	ADC1_set_SQRx(16, channel)   //设置规则通道扫描模式的序列16


//******ADC injected sequence register (ADC_JSQR)*******************//
/*
ADC injected sequence register (ADC_JSQR)
Address offset: 0x38
Reset value: 0x0000 0000
*/

/*
Bits 31:22
 Reserved, must be kept cleared.
*/

/*
扫面模式下注入通道的数量
Bits 21:20 JL[1:0]: Injected sequence length
These bits are written by software to define the total number of conversions in the injected 
channel conversion sequence.
00: 1 conversion
01: 2 conversions
10: 3 conversions
11: 4 conversions
*/
void ADC1_set_JL(U8 l);

#define ADC1_set_inject_sequence_length(l)	ADC1_set_JL(l - 1)

#define ADC1_set_inject_sequence_length_1()	ADC1_set_JL(0)	//设置注入扫描模式的length为1
#define ADC1_set_inject_sequence_length_2()	ADC1_set_JL(1)  //设置注入扫描模式的length为2
#define ADC1_set_inject_sequence_length_3()	ADC1_set_JL(2)  //设置注入扫描模式的length为3
#define ADC1_set_inject_sequence_length_4()	ADC1_set_JL(3)  //设置注入扫描模式的length为4



/*
注入通道在扫描模式下的序列
Bits 19:15 JSQ4[4:0]: 4th conversion in injected sequence
These bits are written by software with the channel number (0..17) assigned as the 4th in 
the sequence to be converted.
Note: Unlike a regular conversion sequence, if JL[1:0] length is less than four, the channels 
are converted in a sequence starting from (4-JL). Example: ADC_JSQR[21:0] = 10 
00011 00011 00111 00010 means that a scan conversion will convert the following 
channel sequence: 7, 3, 3. (not 2, 7, 3) 
Bits 14:10 JSQ3[4:0]: 3rd conversion in injected sequence
Bits 9:5 JSQ2[4:0]: 2nd conversion in injected sequence
Bits 4:0 JSQ1[4:0]: 1st conversion in injected sequence
*/
void ADC1_set_JSQx(U8 sqrNum, U8 channelNum);

#define ADC1_set_inject_sequence(sqrNum, channelNum)	ADC1_set_JSQx(sqrNum, channelNum)

#define ADC1_set_inject_sequence1(channel)	ADC1_set_JSQx(1, channel)
#define ADC1_set_inject_sequence2(channel)	ADC1_set_JSQx(2, channel)
#define ADC1_set_inject_sequence3(channel)	ADC1_set_JSQx(3, channel)
#define ADC1_set_inject_sequence4(channel)	ADC1_set_JSQx(4, channel)




//******ADC injected data register x (ADC_JDRx) (x= 1..4)**********//
/*
ADC injected data register x (ADC_JDRx) (x= 1..4)
Address offset: 0x3C - 0x48
Reset value: 0x0000 0000
*/

/*
Bits 31:16
Reserved, must be kept cleared.
*/

/*
Bits 15:0 JDATA[15:0]: Injected data 
These bits are read only. They contain the conversion result from injected channel x. The 
data is left or right-aligned as shown in Figure 31 and Figure 32.
*/
//jChannelNum = 1 - 4
U16 ADC1_get_JDATAx(U8 jChannelNum);

#define ADC1_get_inject_convert_data(channel)	ADC1_get_JDATAx(channel)

#define ADC1_get_inject_convert_data_channel1()	ADC1_get_JDATAx(1)
#define ADC1_get_inject_convert_data_channel3()	ADC1_get_JDATAx(2)
#define ADC1_get_inject_convert_data_channel2()	ADC1_get_JDATAx(3)
#define ADC1_get_inject_convert_data_channel4()	ADC1_get_JDATAx(4)

#define ADC1_get_inject_result(channel)	ADC1_get_Jresultx(channel)

#define ADC1_get_inject_convert_result_channel1()	ADC1_get_Jresultx(1)
#define ADC1_get_inject_convert_result_channel3()	ADC1_get_Jresultx(2)
#define ADC1_get_inject_convert_result_channel2()	ADC1_get_Jresultx(3)
#define ADC1_get_inject_convert_result_channel4()	ADC1_get_Jresultx(4)

//******ADC regular data register (ADC_DR)***********************//
/*
ADC regular data register (ADC_DR)
Address offset: 0x4C
Reset value: 0x0000 0000
*/

/*
在双重模式下ADC2的转换结果
Bits 31:16 ADC2DATA[15:0]: ADC2 data
In ADC1: In dual mode, these bits contain the regular data of ADC2. Refer to Section 11.9: 
Dual ADC mode.
In ADC2 and ADC3: these bits are not used.
*/
U16 ADC1_get_ADC2DATA(void);

#define ADC1_get_ADC2_data()	ADC1_get_ADC2DATA()

/*
规则通道的转换结果
Bits 15:0 DATA[15:0]: Regular data
These bits are read only. They contain the conversion result from the regular channels. The 
data is left or right-aligned as shown in Figure 31 and Figure 32.
*/
U16 ADC1_get_DATA(void);

#define ADC1_get_convert_data()	ADC1_get_DATA()

#define ADC1_get_convert_result()	ADC1_get_DATA()




#endif




/*
	此文档里定义了高级定时器TIM1和8所使用到的所有寄存器，和对这些寄存器的基础操作。
	TIM1_8在芯片手册的13章有详细讲述。
*/

#ifndef __TIM18
#define __TIM18

#include "com.h"


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


#ifndef __BASE_BKP
#define __BASE_BKP


#include "com.h"

#define __BKP_DRx(x)	(BKP_BASE + ((x <= 10) ? (0x04 * x) : (0x40 + (x - 11) * 0x04))) 
#define __BKP_RTCCR		(BKP_BASE + 0x2C)
#define __BKP_CR		(BKP_BASE + 0x30)
#define __BKP_CSR		(BKP_BASE + 0x34)

#define _BKP_DRx(x)		ADR(__BKP_DRx(x))	
#define _BKP_RTCCR		ADR(__BKP_RTCCR)		
#define _BKP_CR			ADR(__BKP_CR)
#define _BKP_CSR		ADR(__BKP_CSR)		

#define BKP_DRx(x)		VAL(__BKP_DRx(x))	
#define BKP_RTCCR		VAL(__BKP_RTCCR)		
#define BKP_CR			VAL(__BKP_CR)
#define BKP_CSR		VAL(__BKP_CSR)		





//********************************************************//
//*****Backup data register x (BKP_DRx) (x = 1 ..42)******//
//********************************************************//

/*
After reset, access to the Backup registers and RTC is disabled and the Backup domain 
(BKP) is protected against possible parasitic write access. To enable access to the Backup 
registers and the RTC, proceed as follows:
●enable the power and backup interface clocks by setting the PWREN and BKPEN bits 
in the RCC_APB1ENR register
●set the DBP bit the Power Control Register (PWR_CR) to enable access to the Backup 
registers and RTC.
//翻译:
在复位之后，对后备域寄存器和RTC的访问是禁止的，后备域被保护以防止对后备域的意外写操作。可以按照
下述来使能后备域寄存器的访问:
1:通过设置RCC_APB1ENR寄存器的PWREN位和BKPEN位来使能电源和备份域接口时钟。
2:设置PWR_CR寄存器中的DBP位来禁止对后备域的保护。
*/

/*
Backup data register x (BKP_DRx) (x = 1 ..42)
Address offset: 0x04 to 0x28, 0x40 to 0xBC
Reset value: 0x0000 0000
*/
/*
Bits 15:0 D[15:0] Backup data
These bits can be written with user data. 
Note: The BKP_DRx registers are not reset by a System reset or Power reset or when the 
device wakes up from Standby mode.
They are reset by a Backup Domain reset or by a TAMPER pin event (if the TAMPER 
pin function is activated).
*/

void BKP_set_DRx(U16 data, U8 x);

//设置备份域寄存器编号为x的寄存器的值
//x = 1 - 42
#define BKP_set_data(data, x)	BKP_set_DRx(data, x)

U16 BKP_get_DRx(U8 x);

//获取备份域寄存器编号为x的寄存器的值
//x = 1 - 42
#define BKP_get_data(x)		BKP_get_DRx(x)

//********************************************************//
//********RTC clock calibration register (BKP_RTCCR)******//
//********************************************************//

/*
RTC clock calibration register (BKP_RTCCR)
Address offset: 0x2C
Reset value: 0x0000 0000
*/

/*
Bits 15:10 Reserved, always read as 0.
*/

/*
从TAMPER引脚输出RTC的秒脉冲还是闹钟脉冲(每到达一个脉冲事件输出一个)
Bit 9 ASOS: Alarm or second output selection
When the ASOE bit is set, the ASOS bit can be used to select whether the signal output on 
the TAMPER pin is the RTC Second pulse signal or the Alarm pulse signal:
0: RTC Alarm pulse output selected
1: RTC Second pulse output selected
Note: This bit is reset only by a Backup domain reset.
*/
void BKP_set_ASOS(U8 s);

#define BKP_set_tamper_pin_output_alarm()	BKP_set_ASOS(0)	//TAMPER引脚输出闹钟脉冲
#define BKP_set_tamper_pin_output_second()	BKP_set_ASOS(1)	//TAMPER引脚输出秒脉冲

/*
RTC alarm 和 second事件脉冲输出使能
	秒脉冲还是输出时钟脉冲的选择见上函数
Bit 8 ASOE: Alarm or second output enable
Setting this bit outputs either the RTC Alarm pulse signal or the Second pulse signal on the 
TAMPER pin depending on the ASOS bit.
The output pulse duration is one RTC clock period. The TAMPER pin must not be enabled 
while the ASOE bit is set.
Note: This bit is reset only by a Backup domain reset.
*/
void BKP_set_ASOE(U8 e_d);

//使能TAMPER引脚秒脉冲或闹钟脉冲的输出
#define BKP_enable_tamper_output()	BKP_set_ASOE(1)	

//禁止TAMPER引脚秒脉冲或闹钟脉冲的输出
#define BKP_disable_tamper_output()	BKP_set_ASOE(0)


/*
RTC时钟(64分频后)内部传输到TAMPER引脚并输出(在外部校准RTC的脉冲)
Bit 7 CCO: Calibration clock output 
0: No effect
1: Setting this bit outputs the RTC clock with a frequency divided by 64 on the TAMPER pin. 
The TAMPER pin must not be enabled while the CCO bit is set in order to avoid unwanted 
Tamper detection.
Note: This bit is reset when the VDD supply is powered off.
*/
void BKP_set_CCO(U8 e_d);

#define BKP_enable_rtc_clock_calibration()	BKP_set_CCO(1)
#define BKP_disable_rtc_clock_calibration()	BKP_set_CCO(0)


/*
精度调整
每2^20个RTC时钟忽略掉CAL个，这样可以达到校准RTC时钟的目的
Bit 6:0 CAL[6:0]: Calibration value
This value indicates the number of clock pulses that will be ignored every 2^20 clock pulses. 
This allows the calibration of the RTC, slowing down the clock by steps of 1000000/2^20 
PPM. 
The clock of the RTC can be slowed down from 0 to 121PPM.
*/
void BKP_set_CAL(U8 c);

//设置RTC时钟的校准数(参看位段说明)
#define BKP_set_rtc_calibration_value(c)	BKP_set_CAL(c)

U8 BKP_get_CAL(void);
//获取RTC时钟的校准数(参看位段说明)
#define BKP_get_rtc_calibration_value()		BKP_get_CAL()


//***********************************************************//
//***********Backup control register (BKP_CR)****************//
//***********************************************************//
/*
Backup control register (BKP_CR) 
Address offset: 0x30
Reset value: 0x0000 0000
*/

/*
Bits 15:2 Reserved, always read as 0.
*/
/*
TAMPER检测信号极性选择
检测到一个TAMPER信号会导致备份域复位一次
如果是能中断，会产生中断，否则只会激发事件(设置事件位)
Bit 1 TPAL: TAMPER pin active level
0: A high level on the TAMPER pin resets all data backup registers (if TPE bit is set).
1: A low level on the TAMPER pin resets all data backup registers (if TPE bit is set).
*/
void BKP_set_TPAL(U8 s);

//将TAMPER引脚的输入配置为高电平激发TAMPER事件
#define BKP_set_tamper_polarity_high()	BKP_set_TPAL(0)
//将TAMPER引脚的输入配置为低电平激发TAMPER事件
#define BKP_set_tamper_polarity_low()	BKP_set_TPAL(1)

/*
使能TAMPER功能 
Bit 0 TPE: TAMPER pin enable
0: The TAMPER pin is free for general purpose I/O
1: Tamper alternate I/O function is activated.
*/
void BKP_set_TAMPER(U8 e_d);

//使能TAMPER功能
#define BKP_enable_tamper()		BKP_set_TAMPER(1)
//禁用TAMPER功能
#define BKP_disable_tamper()	BKP_set_TAMPER(0)

/*
Note:
Setting the TPAL and TPE bits at the same time is always safe, however resetting both at 
the same time can generate a spurious Tamper event. For this reason it is recommended to 
change the TPAL bit only when the TPE bit is reset.
*/

//**********************************************************//
//*********Backup control/status register (BKP_CSR)*********//
//**********************************************************//


/*
Backup control/status register (BKP_CSR) 
Address offset: 0x34
Reset value: 0x0000 0000
*/

/*
Bits 15:10 Reserved, always read as 0.
*/

/*
当发生Tamper中断时此位被标志
Bit 9 TIF: Tamper interrupt flag 
This bit is set by hardware when a Tamper event is detected and the TPIE bit is set. It is 
cleared by writing 1 to the CTI bit (also clears the interrupt). It is also cleared if the TPIE bit is 
reset. 
0: No Tamper interrupt
1: A Tamper interrupt occurred
Note: This bit is reset only by a system reset and wakeup from Standby mode.
*/
U8 BKP_get_TIF(void);

#define BKP_get_tamper_interrupt_flag()	BKP_get_TIF()
#define BKP_is_interrupted_by_tamper()	BKP_get_TIF()	

/*
当发生Tamper事件时此位被标志
Bit 8 TEF: Tamper event flag 
This bit is set by hardware when a Tamper event is detected. It is cleared by writing 1 to the 
CTE bit.
0: No Tamper event
1: A Tamper event occurred
Note: A Tamper event resets all the BKP_DRx registers. They are held in reset as long as the 
TEF bit is set. If a write to the BKP_DRx registers is performed while this bit is set, the 
value will not be stored.
*/
U8 BKP_get_TEF(void);

#define BKP_get_tamper_event_flag()		BKP_get_TEF()
#define BKP_is_tamper_event_occured()	BKP_get_TEF()

/*
Bits 7:3 Reserved, always read as 0.
*/

/*
使能Tamper事件产生中断
Bit 2 TPIE: TAMPER pin interrupt enable
0: Tamper interrupt disabled
1: Tamper interrupt enabled (the TPE bit must also be set in the BKP_CR register
Note: 
1: A Tamper interrupt does not wake up the core from low-power modes.
2: This bit is reset only by a system reset and wakeup from Standby mode.
*/
void BKP_set_TPIE(U8 e_d);

#define BKP_enable_interrupt_at_tamper()	BKP_set_TPIE(1)	
#define BKP_disable_interrupt_at_tamper()	BKP_set_TPIE(0)

/*
Bit 1 CTI: Clear tamper interrupt
This bit is write only, and is always read as 0.
0: No effect
1: Clear the Tamper interrupt and the TIF Tamper interrupt flag. 
*/
void BKP_set_CTI(void);

#define BKP_clear_tamper_interrupt_flag()	BKP_set_CTI()

/*
Bit 0 CTE: Clear tamper event
This bit is write only, and is always read as 0.
0: No effect
1: Reset the TEF Tamper event flag (and the Tamper detector) 
*/
void BKP_set_CTE(void);

#define BKP_clear_tamper_event_interrupt_flag()	BKP_set_CTE()


#endif


#ifndef __BASE_DAC
#define __BASE_DAC


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



/*
此文档定义了DMA寄存器和其相关操作，现在只有DMA1和它的7个小通道，凑合着用吧

Channel configuration procedure
The following sequence should be followed to configure a DMA channelx (where x is the 
channel number).
1.
Set the peripheral register address in the DMA_CPARx register. The data will be 
moved from/ to this address to/ from the memory after the peripheral event.
2. 
Set the memory address in the DMA_CMARx register. The data will be written to or 
read from this memory after the peripheral event.
3. 
Configure the total number of data to be transferred in the DMA_CNDTRx register. 
After each peripheral event, this value will be decremented.
4. 
Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
5. 
Configure data transfer direction, circular mode, peripheral & memory incremented 
mode, peripheral & memory data size, and interrupt after half and/or full transfer in the 
DMA_CCRx register
6. 
Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
*/

#ifndef __DMA
#define __DMA


#include "com.h"


//**********************DMA1************************//
#define __DMA1_ISR		(DMA1_BASE + 0x00000000)
#define __DMA1_IFCR		(DMA1_BASE + 0x00000004)

//DMA1 	Channel1
#define __DMA1_CCR1		(DMA1_Channel1_BASE + 0x00000000)
#define __DMA1_CNDTR1	(DMA1_Channel1_BASE + 0x00000004)
#define __DMA1_CPAR1	(DMA1_Channel1_BASE + 0x00000008)
#define __DMA1_CMAR1	(DMA1_Channel1_BASE + 0x0000000C)

//DMA1	Channel2
#define __DMA1_CCR2		(DMA1_Channel2_BASE + 0x00000000)
#define __DMA1_CNDTR2	(DMA1_Channel2_BASE + 0x00000004)
#define __DMA1_CPAR2	(DMA1_Channel2_BASE + 0x00000008)
#define __DMA1_CMAR2	(DMA1_Channel2_BASE + 0x0000000C)

//DMA1	Channel3
#define __DMA1_CCR3		(DMA1_Channel3_BASE + 0x00000000)
#define __DMA1_CNDTR3	(DMA1_Channel3_BASE + 0x00000004)
#define __DMA1_CPAR3	(DMA1_Channel3_BASE + 0x00000008)
#define __DMA1_CMAR3	(DMA1_Channel3_BASE + 0x0000000C)

//DMA1	Channel4
#define __DMA1_CCR4		(DMA1_Channel4_BASE + 0x00000000)
#define __DMA1_CNDTR4	(DMA1_Channel4_BASE + 0x00000004)
#define __DMA1_CPAR4	(DMA1_Channel4_BASE + 0x00000008)
#define __DMA1_CMAR4	(DMA1_Channel4_BASE + 0x0000000C)

//DMA1	Channel5
#define __DMA1_CCR5		(DMA1_Channel5_BASE + 0x00000000)
#define __DMA1_CNDTR5	(DMA1_Channel5_BASE + 0x00000004)
#define __DMA1_CPAR5	(DMA1_Channel5_BASE + 0x00000008)
#define __DMA1_CMAR5	(DMA1_Channel5_BASE + 0x0000000C)

//DMA1	Channel6
#define __DMA1_CCR6		(DMA1_Channel6_BASE + 0x00000000)
#define __DMA1_CNDTR6	(DMA1_Channel6_BASE + 0x00000004)
#define __DMA1_CPAR6	(DMA1_Channel6_BASE + 0x00000008)
#define __DMA1_CMAR6	(DMA1_Channel6_BASE + 0x0000000C)

//DMA1	Channel7
#define __DMA1_CCR7		(DMA1_Channel7_BASE + 0x00000000)
#define __DMA1_CNDTR7	(DMA1_Channel7_BASE + 0x00000004)
#define __DMA1_CPAR7	(DMA1_Channel7_BASE + 0x00000008)
#define __DMA1_CMAR7	(DMA1_Channel7_BASE + 0x0000000C)

//DMA1	Channelx(1 - 7)
#define __DMA1_CCRx(channel)	(__DMA1_CCR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CNDTRx(channel)	(__DMA1_CNDTR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CPARx(channel)	(__DMA1_CPAR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CMARx(channel)	(__DMA1_CMAR1 + (0x14 * ((channel%8) - 1)))

//********************DMA2***********************//
#define __DMA2_ISR		(DMA2_BASE + 0x00000000)
#define __DMA2_IFCR		(DMA2_BASE + 0x00000004)

//DMA2 	Channel1
#define __DMA2_CCR1		(DMA2_Channel1_BASE + 0x00000000)
#define __DMA2_CNDTR1	(DMA2_Channel1_BASE + 0x00000004)
#define __DMA2_CPAR1	(DMA2_Channel1_BASE + 0x00000008)
#define __DMA2_CMAR1	(DMA2_Channel1_BASE + 0x0000000C)

//DMA2	Channel2
#define __DMA2_CCR2		(DMA2_Channel2_BASE + 0x00000000)
#define __DMA2_CNDTR2	(DMA2_Channel2_BASE + 0x00000004)
#define __DMA2_CPAR2	(DMA2_Channel2_BASE + 0x00000008)
#define __DMA2_CMAR2	(DMA2_Channel2_BASE + 0x0000000C)

//DMA2	Channel3
#define __DMA2_CCR3		(DMA2_Channel3_BASE + 0x00000000)
#define __DMA2_CNDTR3	(DMA2_Channel3_BASE + 0x00000004)
#define __DMA2_CPAR3	(DMA2_Channel3_BASE + 0x00000008)
#define __DMA2_CMAR3	(DMA2_Channel3_BASE + 0x0000000C)

//DMA2	Channel4
#define __DMA2_CCR4		(DMA2_Channel4_BASE + 0x00000000)
#define __DMA2_CNDTR4	(DMA2_Channel4_BASE + 0x00000004)
#define __DMA2_CPAR4	(DMA2_Channel4_BASE + 0x00000008)
#define __DMA2_CMAR4	(DMA2_Channel4_BASE + 0x0000000C)

//DMA2	Channel5
#define __DMA2_CCR5		(DMA2_Channel5_BASE + 0x00000000)
#define __DMA2_CNDTR5	(DMA2_Channel5_BASE + 0x00000004)
#define __DMA2_CPAR5	(DMA2_Channel5_BASE + 0x00000008)
#define __DMA2_CMAR5	(DMA2_Channel5_BASE + 0x0000000C)

//DMA2	Channelx(1 - 5)
#define __DMA2_CCRx(channel)	(__DMA2_CCR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CNDTRx(channel)	(__DMA2_CNDTR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CPARx(channel)	(__DMA2_CPAR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CMARx(channel)	(__DMA2_CMAR1 + (0x14 * ((channel%6) - 1)))


/*Adress*/
//**********************DMA1************************//
#define _DMA1_ISR		ADR(__DMA1_ISR)		
#define _DMA1_IFCR		ADR(__DMA1_IFCR)		

//DMA1 	Channel1
#define _DMA1_CCR1		ADR(__DMA1_CCR1)		
#define _DMA1_CNDTR1	ADR(__DMA1_CNDTR1)	
#define _DMA1_CPAR1		ADR(__DMA1_CPAR1)	
#define _DMA1_CMAR1		ADR(__DMA1_CMAR1)	

//DMA1	Channel2
#define _DMA1_CCR2		ADR(__DMA1_CCR2)
#define _DMA1_CNDTR2	ADR(__DMA1_CNDTR2)	
#define _DMA1_CPAR2		ADR(__DMA1_CPAR2)	
#define _DMA1_CMAR2		ADR(__DMA1_CMAR2)	

//DMA1	Channel3
#define _DMA1_CCR3		ADR(__DMA1_CCR3)	
#define _DMA1_CNDTR3	ADR(__DMA1_CNDTR3)	
#define _DMA1_CPAR3		ADR(__DMA1_CPAR3)	
#define _DMA1_CMAR3		ADR(__DMA1_CMAR3)	

//DMA1	Channel4
#define _DMA1_CCR4		ADR(__DMA1_CCR4)		
#define _DMA1_CNDTR4	ADR(__DMA1_CNDTR4)	
#define _DMA1_CPAR4		ADR(__DMA1_CPAR4)	
#define _DMA1_CMAR4		ADR(__DMA1_CMAR4)	

//DMA1	Channel5
#define _DMA1_CCR5		ADR(__DMA1_CCR5)		
#define _DMA1_CNDTR5	ADR(__DMA1_CNDTR5)	
#define _DMA1_CPAR5		ADR(__DMA1_CPAR5)	
#define _DMA1_CMAR5		ADR(__DMA1_CMAR5)	

//DMA1	Channel6
#define _DMA1_CCR6		ADR(__DMA1_CCR6)		
#define _DMA1_CNDTR6	ADR(__DMA1_CNDTR6)	
#define _DMA1_CPAR6		ADR(__DMA1_CPAR6)	
#define _DMA1_CMAR6		ADR(__DMA1_CMAR6)	

//DMA1	Channel7
#define _DMA1_CCR7		ADR(__DMA1_CCR7)	
#define _DMA1_CNDTR7	ADR(__DMA1_CNDTR7)	
#define _DMA1_CPAR7		ADR(__DMA1_CPAR7)	
#define _DMA1_CMAR7		ADR(__DMA1_CMAR7)

//DMA1	Channelx(1 - 7)
#define _DMA1_CCRx(channel)		ADR(__DMA1_CCRx(channel))	
#define _DMA1_CNDTRx(channel)	ADR(__DMA1_CNDTRx(channel))	
#define _DMA1_CPARx(channel)	ADR(__DMA1_CPARx(channel))	
#define _DMA1_CMARx(channel)	ADR(__DMA1_CMARx(channel))	

//********************DMA2***********************//
#define _DMA2_ISR		ADR(__DMA2_ISR)		
#define _DMA2_IFCR		ADR(__DMA2_IFCR)		

//DMA2 	Channel1
#define _DMA2_CCR1		ADR(__DMA2_CCR1)		
#define _DMA2_CNDTR1	ADR(__DMA2_CNDTR1)	
#define _DMA2_CPAR1		ADR(__DMA2_CPAR1)	
#define _DMA2_CMAR1		ADR(__DMA2_CMAR1)	

//DMA2	Channel2
#define _DMA2_CCR2		ADR(__DMA2_CCR2)	
#define _DMA2_CNDTR2	ADR(__DMA2_CNDTR2)	
#define _DMA2_CPAR2		ADR(__DMA2_CPAR2)	
#define _DMA2_CMAR2		ADR(__DMA2_CMAR2)	

//DMA2	Channel3
#define _DMA2_CCR3		ADR(__DMA2_CCR3)	
#define _DMA2_CNDTR3	ADR(__DMA2_CNDTR3)	
#define _DMA2_CPAR3		ADR(__DMA2_CPAR3)	
#define _DMA2_CMAR3		ADR(__DMA2_CMAR3)
	
//DMA2	Channel4
#define _DMA2_CCR4		ADR(__DMA2_CCR4)
#define _DMA2_CNDTR4	ADR(__DMA2_CNDTR4	
#define _DMA2_CPAR4		ADR(__DMA2_CPAR4)	
#define _DMA2_CMAR4		ADR(__DMA2_CMAR4)	

//DMA2	Channel5
#define _DMA2_CCR5		ADR(__DMA2_CCR5)	
#define _DMA2_CNDTR5	ADR(__DMA2_CNDTR5)	
#define _DMA2_CPAR5		ADR(__DMA2_CPAR5)	
#define _DMA2_CMAR5		ADR(__DMA2_CMAR5)	

//DMA2	Channelx(1 - 5)
#define _DMA2_CCRx(channel)		ADR(__DMA2_CCRx(channel))	
#define _DMA2_CNDTRx(channel)	ADR(__DMA2_CNDTRx(channel))	
#define _DMA2_CPARx(channel)	ADR(__DMA2_CPARx(channel))	
#define _DMA2_CMARx(channel)	ADR(__DMA2_CMARx(channel))	


/*Value*/
//**********************DMA1************************//
#define DMA1_ISR		VAL(__DMA1_ISR)		
#define DMA1_IFCR		VAL(__DMA1_IFCR)		

//DMA1 	Channel1
#define DMA1_CCR1		VAL(__DMA1_CCR1)		
#define DMA1_CNDTR1		VAL(__DMA1_CNDTR1)	
#define DMA1_CPAR1		VAL(__DMA1_CPAR1)	
#define DMA1_CMAR1		VAL(__DMA1_CMAR1)	

//DMA1	Channel2
#define DMA1_CCR2		VAL(__DMA1_CCR2)
#define DMA1_CNDTR2		VAL(__DMA1_CNDTR2)	
#define DMA1_CPAR2		VAL(__DMA1_CPAR2)	
#define DMA1_CMAR2		VAL(__DMA1_CMAR2)	

//DMA1	Channel3
#define DMA1_CCR3		VAL(__DMA1_CCR3)	
#define DMA1_CNDTR3		VAL(__DMA1_CNDTR3)	
#define DMA1_CPAR3		VAL(__DMA1_CPAR3)	
#define DMA1_CMAR3		VAL(__DMA1_CMAR3)	

//DMA1	Channel4
#define DMA1_CCR4		VAL(__DMA1_CCR4)		
#define DMA1_CNDTR4		VAL(__DMA1_CNDTR4)	
#define DMA1_CPAR4		VAL(__DMA1_CPAR4)	
#define DMA1_CMAR4		VAL(__DMA1_CMAR4)	

//DMA1	Channel5
#define DMA1_CCR5		VAL(__DMA1_CCR5)		
#define DMA1_CNDTR5		VAL(__DMA1_CNDTR5)	
#define DMA1_CPAR5		VAL(__DMA1_CPAR5)	
#define DMA1_CMAR5		VAL(__DMA1_CMAR5)	

//DMA1	Channel6
#define DMA1_CCR6		VAL(__DMA1_CCR6)		
#define DMA1_CNDTR6		VAL(__DMA1_CNDTR6)	
#define DMA1_CPAR6		VAL(__DMA1_CPAR6)	
#define DMA1_CMAR6		VAL(__DMA1_CMAR6)	

//DMA1	Channel7
#define DMA1_CCR7		VAL(__DMA1_CCR7)	
#define DMA1_CNDTR7		VAL(__DMA1_CNDTR7)	
#define DMA1_CPAR7		VAL(__DMA1_CPAR7)	
#define DMA1_CMAR7		VAL(__DMA1_CMAR7)	

//DMA1	Channelx(1 - 7)
#define DMA1_CCRx(channel)		VAL(__DMA1_CCRx(channel))	
#define DMA1_CNDTRx(channel)	VAL(__DMA1_CNDTRx(channel))	
#define DMA1_CPARx(channel)		VAL(__DMA1_CPARx(channel))	
#define DMA1_CMARx(channel)		VAL(__DMA1_CMARx(channel))

//********************DMA2***********************//
#define DMA2_ISR		VAL(__DMA2_ISR)		
#define DMA2_IFCR		VAL(__DMA2_IFCR)		

//DMA2 	Channel1
#define DMA2_CCR1		VAL(__DMA2_CCR1)		
#define DMA2_CNDTR1		VAL(__DMA2_CNDTR1)	
#define DMA2_CPAR1		VAL(__DMA2_CPAR1)	
#define DMA2_CMAR1		VAL(__DMA2_CMAR1)	

//DMA2	Channel2
#define DMA2_CCR2		VAL(__DMA2_CCR2)	
#define DMA2_CNDTR2		VAL(__DMA2_CNDTR2)	
#define DMA2_CPAR2		VAL(__DMA2_CPAR2)	
#define DMA2_CMAR2		VAL(__DMA2_CMAR2)	

//DMA2	Channel3
#define DMA2_CCR3		VAL(__DMA2_CCR3)	
#define DMA2_CNDTR3		VAL(__DMA2_CNDTR3)	
#define DMA2_CPAR3		VAL(__DMA2_CPAR3)	
#define DMA2_CMAR3		VAL(__DMA2_CMAR3)
	
//DMA2	Channel4
#define DMA2_CCR4		VAL(__DMA2_CCR4)
#define DMA2_CNDTR4		VAL(__DMA2_CNDTR4	
#define DMA2_CPAR4		VAL(__DMA2_CPAR4)	
#define DMA2_CMAR4		VAL(__DMA2_CMAR4)	

//DMA2	Channel5
#define DMA2_CCR5		VAL(__DMA2_CCR5)	
#define DMA2_CNDTR5		VAL(__DMA2_CNDTR5)	
#define DMA2_CPAR5		VAL(__DMA2_CPAR5)	
#define DMA2_CMAR5		VAL(__DMA2_CMAR5)

//DMA2	Channelx(1 - 5)
#define DMA2_CCRx(channel)		VAL(__DMA2_CCRx(channel))	
#define DMA2_CNDTRx(channel)	VAL(__DMA2_CNDTRx(channel))	
#define DMA2_CPARx(channel)		VAL(__DMA2_CPARx(channel))	
#define DMA2_CMARx(channel)		VAL(__DMA2_CMARx(channel))



//***********************************************************************************************//
//**************************************DMA1部分*************************************************//
//***********************************************************************************************//
 
//************************DMA interrupt status register (DMA_ISR)*****************//
//DMA中断状态寄存器: 关于获取DMA中断

/*
Bits 31:28
Reserved, always read as 0.
*/

/*
通道传输错误中断标志
Bits 27, 23, 19, 15,                      
11, 7, 3
TEIFx: Channel x transfer error flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No transfer error (TE) on channel x
1: A transfer error (TE) occurred on channel x
*/
U8	DMA1_get_TEIFx(U8 channel);

//命名1
#define DAM1_is_transfer_error_occured(channel)	DMA1_get_TEIFx(channel)	//通道x错误标志

#define DMA1_CH1_is_transfer_error_occured()	DMA1_get_TEIFx(1)	//通道1错误事件标志
#define DMA1_CH2_is_transfer_error_occured()	DMA1_get_TEIFx(2)   //通道2错误事件标志
#define DMA1_CH3_is_transfer_error_occured()	DMA1_get_TEIFx(3)   //通道3错误事件标志
#define DMA1_CH4_is_transfer_error_occured()	DMA1_get_TEIFx(4)   //通道4错误事件标志
#define DMA1_CH5_is_transfer_error_occured()	DMA1_get_TEIFx(5)   //通道5错误事件标志
#define DMA1_CH6_is_transfer_error_occured()	DMA1_get_TEIFx(6)   //通道6错误事件标志
#define DMA1_CH7_is_transfer_error_occured()	DMA1_get_TEIFx(7)   //通道7错误事件标志


//命名2
#define DAM1_is_interrupted_by_transfer_error(channel)	DMA1_get_TEIFx(channel)	//通道x错误中断标志

#define DMA1_CH1_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(1)	//通道1错误中断标志
#define DMA1_CH2_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(2)   //通道2错误中断标志
#define DMA1_CH3_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(3)   //通道3错误中断标志
#define DMA1_CH4_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(4)   //通道4错误中断标志
#define DMA1_CH5_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(5)   //通道5错误中断标志
#define DMA1_CH6_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(6)   //通道6错误中断标志
#define DMA1_CH7_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(7)   //通道7错误中断标志


/*
通道传输过半中断标志
Bits 26, 22, 18, 14,                     
10, 6, 2
HTIFx: Channel x half transfer flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No half transfer (HT) event on channel x
1: A half transfer (HT) event occurred on channel x
*/
U8	DMA1_get_HTIFx(U8 channel);

//命名1
#define DMA1_is_transfer_half_occured(channel)  DMA1_get_HTIFx(channel)   //传输过半事件标志

#define DMA1_CH1_is_transfer_half_occured()  DMA1_get_HTIFx(1)   //通道1传输过半事件标志
#define DMA1_CH2_is_transfer_half_occured()  DMA1_get_HTIFx(2)   //通道2传输过半事件标志
#define DMA1_CH3_is_transfer_half_occured()  DMA1_get_HTIFx(3)   //通道3传输过半事件标志
#define DMA1_CH4_is_transfer_half_occured()  DMA1_get_HTIFx(4)   //通道4传输过半事件标志
#define DMA1_CH5_is_transfer_half_occured()  DMA1_get_HTIFx(5)   //通道5传输过半事件标志
#define DMA1_CH6_is_transfer_half_occured()  DMA1_get_HTIFx(6)   //通道6传输过半事件标志
#define DMA1_CH7_is_transfer_half_occured()  DMA1_get_HTIFx(7)   //通道7传输过半事件标志

//命名2
#define DMA1_is_interrupted_by_transfer_half(channel)  DMA1_get_HTIFx(channel)

#define DMA1_CH1_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(1)  	//通道1传输过半中断标志
#define DMA1_CH2_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(2)   //通道2传输过半中断标志
#define DMA1_CH3_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(3)   //通道3传输过半中断标志
#define DMA1_CH4_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(4)   //通道4传输过半中断标志
#define DMA1_CH5_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(5)   //通道5传输过半中断标志
#define DMA1_CH6_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(6)   //通道6传输过半中断标志
#define DMA1_CH7_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(7)   //通道7传输过半中断标志

/*
通道传输完成中断标志
Bits 25, 21, 17, 13,					  
9, 5, 1
TCIFx: Channel x transfer complete flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No transfer complete (TC) event on channel x
1: A transfer complete (TC) event occurred on channel x
*/

U8	DMA1_get_TCIFx(U8 channel);

//命名1
#define DMA1_is_transfer_complete_occured(channel)  DMA1_get_TCIFx(channel)   //传输完成事件

#define DMA1_CH1_is_transfer_complete_occured()  DMA1_get_TCIFx(1)   //通道1传输完成事件标志
#define DMA1_CH2_is_transfer_complete_occured()  DMA1_get_TCIFx(2)   //通道2传输完成事件标志
#define DMA1_CH3_is_transfer_complete_occured()  DMA1_get_TCIFx(3)   //通道3传输完成事件标志
#define DMA1_CH4_is_transfer_complete_occured()  DMA1_get_TCIFx(4)   //通道4传输完成事件标志
#define DMA1_CH5_is_transfer_complete_occured()  DMA1_get_TCIFx(5)   //通道5传输完成事件标志
#define DMA1_CH6_is_transfer_complete_occured()  DMA1_get_TCIFx(6)   //通道6传输完成事件标志
#define DMA1_CH7_is_transfer_complete_occured()  DMA1_get_TCIFx(7)   //通道7传输完成事件标志

//命名2
#define DMA1_is_interrupted_by_transfer_complete(channel)  DMA1_get_TCIFx(channel)

#define DMA1_CH1_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(1)  	//通道1传输完成中断标志 
#define DMA1_CH2_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(2)   //通道2传输完成中断标志 
#define DMA1_CH3_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(3)   //通道3传输完成中断标志 
#define DMA1_CH4_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(4)   //通道4传输完成中断标志 
#define DMA1_CH5_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(5)   //通道5传输完成中断标志 
#define DMA1_CH6_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(6)   //通道6传输完成中断标志 
#define DMA1_CH7_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(7)   //通道7传输完成中断标志 

/*
通道全局中断标志
Bits 24, 20, 16, 12,                      
8, 4, 0
GIFx: Channel x global interrupt flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No TE, HT or TC event on channel x
1: A TE, HT or TC event occurred on channel x
*/
U8	DMA1_get_GIFx(U8 channel);

#define DMA1_is_event_occured(channel)	DMA1_get_GIFx(channel)    //是否有事件发生

#define DMA1_CH1_is_event_occured()		DMA1_get_GIFx(1)    //通道1是否有事件发生
#define DMA1_CH2_is_event_occured()		DMA1_get_GIFx(2)    //通道2是否有事件发生
#define DMA1_CH3_is_event_occured()		DMA1_get_GIFx(3)    //通道3是否有事件发生
#define DMA1_CH4_is_event_occured()		DMA1_get_GIFx(4)    //通道4是否有事件发生
#define DMA1_CH5_is_event_occured()		DMA1_get_GIFx(5)    //通道5是否有事件发生
#define DMA1_CH6_is_event_occured()		DMA1_get_GIFx(6)    //通道6是否有事件发生
#define DMA1_CH7_is_event_occured()		DMA1_get_GIFx(7)    //通道7是否有事件发生


#define DMA1_is_interrupted_by_event(channel)	DMA1_get_GIFx(channel)

#define DMA1_CH1_is_interrupted_by_event()	DMA1_get_GIFx(1)    //通道1是否有中断发生
#define DMA1_CH2_is_interrupted_by_event()	DMA1_get_GIFx(2)    //通道1是否有中断发生
#define DMA1_CH3_is_interrupted_by_event()	DMA1_get_GIFx(3)    //通道1是否有中断发生
#define DMA1_CH4_is_interrupted_by_event()	DMA1_get_GIFx(4)    //通道1是否有中断发生
#define DMA1_CH5_is_interrupted_by_event()	DMA1_get_GIFx(5)    //通道1是否有中断发生
#define DMA1_CH6_is_interrupted_by_event()	DMA1_get_GIFx(6)    //通道1是否有中断发生
#define DMA1_CH7_is_interrupted_by_event()	DMA1_get_GIFx(7)    //通道1是否有中断发生


//*********************DMA interrupt flag clear register (DMA_IFCR)**************//
//DMA中断标志清除寄存器:清除中断标志相关
/*
Address offset: 0x04
Reset value: 0x0000 0000
*/
/*
Bits 31:28
Reserved, always read as 0.
*/

/*
清除通道传输错误中断标志
Bits 27, 23, 19, 15,                      
11, 7, 3
CTEIFx: Channel x transfer error clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding TEIF flag in the DMA_ISR register 
*/
void DMA1_clear_CTEIFx(U8 channel);

//命名1
#define	DMA1_clear_transfer_error_flag(channel)	  DMA1_clear_CTEIFx(channel)   //清除错误传输标志

#define DMA1_CH1_clear_transfer_error_flag()	DMA1_clear_CTEIFx(1)    //通道1清除错误传输标志
#define DMA1_CH2_clear_transfer_error_flag()	DMA1_clear_CTEIFx(2)    //通道2清除错误传输标志
#define DMA1_CH3_clear_transfer_error_flag()	DMA1_clear_CTEIFx(3)    //通道3清除错误传输标志
#define DMA1_CH4_clear_transfer_error_flag()	DMA1_clear_CTEIFx(4)    //通道4清除错误传输标志
#define DMA1_CH5_clear_transfer_error_flag()	DMA1_clear_CTEIFx(5)    //通道5清除错误传输标志
#define DMA1_CH6_clear_transfer_error_flag()	DMA1_clear_CTEIFx(6)    //通道6清除错误传输标志
#define DMA1_CH7_clear_transfer_error_flag()	DMA1_clear_CTEIFx(7)    //通道7清除错误传输标志



/*
清除通道传输过半中断标志
Bits 26, 22, 18, 14,                      
10, 6, 2
CHTIFx: Channel x half transfer clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding HTIF flag in the DMA_ISR register
*/
void DMA1_clear_CHTIFx(U8 channel);

#define DMA1_clear_transfer_half_flag(channel)	DMA1_clear_CHTIFx(channel)

#define DMA1_CH1_clear_transfer_half_flag()		DMA1_clear_CHTIFx(1)
#define DMA1_CH2_clear_transfer_half_flag()		DMA1_clear_CHTIFx(2)
#define DMA1_CH3_clear_transfer_half_flag()		DMA1_clear_CHTIFx(3)
#define DMA1_CH4_clear_transfer_half_flag()		DMA1_clear_CHTIFx(4)
#define DMA1_CH5_clear_transfer_half_flag()		DMA1_clear_CHTIFx(5)
#define DMA1_CH6_clear_transfer_half_flag()		DMA1_clear_CHTIFx(6)
#define DMA1_CH7_clear_transfer_half_flag()		DMA1_clear_CHTIFx(7)

/*
清除通道传输完成中断标志
Bits 25, 21, 17, 13,                      
9, 5, 1
CTCIFx: Channel x transfer complete clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding TCIF flag in the DMA_ISR register
*/
void DMA1_clear_CTCIFx(U8 channel);

#define DMA1_clear_transfer_complete_flag(channel)	DMA1_clear_CTCIFx(channel)

#define DMA1_CH1_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(1)
#define DMA1_CH2_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(2)
#define DMA1_CH3_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(3)
#define DMA1_CH4_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(4)
#define DMA1_CH5_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(5)
#define DMA1_CH6_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(6)
#define DMA1_CH7_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(7)


/*
清除传输全局中断标志
Bits 24, 20, 16, 12,                      
8, 4, 0
CGIFx: Channel x global interrupt clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
*/
void DMA1_clear_CGIFx(U8 channel);

#define DMA1_clear_event_flag(channel)		DMA1_clear_CGIFx(channel)

#define DMA1_CH1_clear_event_flag()		DMA1_clear_CGIFx(1)
#define DMA1_CH2_clear_event_flag()		DMA1_clear_CGIFx(2)
#define DMA1_CH3_clear_event_flag()		DMA1_clear_CGIFx(3)
#define DMA1_CH4_clear_event_flag()		DMA1_clear_CGIFx(4)
#define DMA1_CH5_clear_event_flag()		DMA1_clear_CGIFx(5)
#define DMA1_CH6_clear_event_flag()		DMA1_clear_CGIFx(6)
#define DMA1_CH7_clear_event_flag()		DMA1_clear_CGIFx(7)


//***********DMA channel x configuration register (DMA_CCRx)**************//
/*
DMA channel x configuration register (DMA_CCRx) (x = 1..7,
where x = channel number)
Address offset: 0x08 + 0d20 × (channel number – 1)
Reset value: 0x0000 0000
*/

/*
Bits 31:15
Reserved, always read as 0.
*/

/*
存储器到存储器模式 使能
Bit 14 MEM2MEM: Memory to memory mode         
This bit is set and cleared by software.
0: Memory to memory mode disabled
1: Memory to memory mode enabled 
*/
void DMA1_set_MEM2MEM(U8 channel, U8 a_d);

#define DMA1_enable_MEM2MEM(channel)	DMA1_set_MEM2MEM(channel, 1)

#define DMA1_CH1_enable_MEM2MEM()	DMA1_set_MEM2MEM(1, 1)
#define DMA1_CH2_enable_MEM2MEM()	DMA1_set_MEM2MEM(2, 1)
#define DMA1_CH3_enable_MEM2MEM()	DMA1_set_MEM2MEM(3, 1)
#define DMA1_CH4_enable_MEM2MEM()	DMA1_set_MEM2MEM(4, 1)
#define DMA1_CH5_enable_MEM2MEM()	DMA1_set_MEM2MEM(5, 1)
#define DMA1_CH6_enable_MEM2MEM()	DMA1_set_MEM2MEM(6, 1)
#define DMA1_CH7_enable_MEM2MEM()	DMA1_set_MEM2MEM(7, 1)


#define DMA1_CH1_disable_MEM2MEM()	DMA1_set_MEM2MEM(1, 0)
#define DMA1_CH2_disable_MEM2MEM()	DMA1_set_MEM2MEM(2, 0)
#define DMA1_CH3_disable_MEM2MEM()	DMA1_set_MEM2MEM(3, 0)
#define DMA1_CH4_disable_MEM2MEM()	DMA1_set_MEM2MEM(4, 0)
#define DMA1_CH5_disable_MEM2MEM()	DMA1_set_MEM2MEM(5, 0)
#define DMA1_CH6_disable_MEM2MEM()	DMA1_set_MEM2MEM(6, 0)
#define DMA1_CH7_disable_MEM2MEM()	DMA1_set_MEM2MEM(7, 0)

/*
通道优先级
Bits 13:12 PL[1:0]: Channel priority level     
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
*/
void DMA1_set_PL(U8 channel, U8 p);

#define DMA1_set_priority(channel, p)	DMA1_set_PL(channel, p)

//Channel 1 - 7优先级配置
#define DMA1_CH1_set_priority(p)	DMA1_set_PL(1, p)
#define DMA1_CH2_set_priority(p)	DMA1_set_PL(2, p)
#define DMA1_CH3_set_priority(p)	DMA1_set_PL(3, p)
#define DMA1_CH4_set_priority(p)	DMA1_set_PL(4, p)
#define DMA1_CH5_set_priority(p)	DMA1_set_PL(5, p)
#define DMA1_CH6_set_priority(p)	DMA1_set_PL(6, p)
#define DMA1_CH7_set_priority(p)	DMA1_set_PL(7, p)

//Channel 1优先级配置
#define DMA1_CH1_set_priority_low()			DMA1_set_PL(1, 0)
#define DMA1_CH1_set_priority_medium()		DMA1_set_PL(1, 1)
#define DMA1_CH1_set_priority_high()		DMA1_set_PL(1, 2)
#define DMA1_CH1_set_priority_veryhigh()	DMA1_set_PL(1, 3)
//Channel 2优先级配置
#define DMA1_CH2_set_priority_low()			DMA1_set_PL(2, 0)
#define DMA1_CH2_set_priority_medium()		DMA1_set_PL(2, 1)
#define DMA1_CH2_set_priority_high()		DMA1_set_PL(2, 2)
#define DMA1_CH2_set_priority_veryhigh()	DMA1_set_PL(2, 3)
//Channel 3优先级配置
#define DMA1_CH3_set_priority_low()			DMA1_set_PL(3, 0)
#define DMA1_CH3_set_priority_medium()		DMA1_set_PL(3, 1)
#define DMA1_CH3_set_priority_high()		DMA1_set_PL(3, 2)
#define DMA1_CH3_set_priority_veryhigh()	DMA1_set_PL(3, 3)
//Channel 4优先级配置
#define DMA1_CH4_set_priority_low()			DMA1_set_PL(4, 0)
#define DMA1_CH4_set_priority_medium()		DMA1_set_PL(4, 1)
#define DMA1_CH4_set_priority_high()		DMA1_set_PL(4, 2)
#define DMA1_CH4_set_priority_veryhigh()	DMA1_set_PL(4, 3)
//Channel 5优先级配置
#define DMA1_CH5_set_priority_low()			DMA1_set_PL(5, 0)
#define DMA1_CH5_set_priority_medium()		DMA1_set_PL(5, 1)
#define DMA1_CH5_set_priority_high()		DMA1_set_PL(5, 2)
#define DMA1_CH5_set_priority_veryhigh()	DMA1_set_PL(5, 3)
//Channel 6优先级配置
#define DMA1_CH6_set_priority_low()			DMA1_set_PL(6, 0)
#define DMA1_CH6_set_priority_medium()		DMA1_set_PL(6, 1)
#define DMA1_CH6_set_priority_high()		DMA1_set_PL(6, 2)
#define DMA1_CH6_set_priority_veryhigh()	DMA1_set_PL(6, 3)
//Channel 7优先级配置
#define DMA1_CH7_set_priority_low()			DMA1_set_PL(7, 0)
#define DMA1_CH7_set_priority_medium()		DMA1_set_PL(7, 1)
#define DMA1_CH7_set_priority_high()		DMA1_set_PL(7, 2)
#define DMA1_CH7_set_priority_veryhigh()	DMA1_set_PL(7, 3)


/*
存储器传输单位尺寸
Bits 11:10 MSIZE[1:0]: Memory size        
These bits are set and cleared by software.
00: 8-bits
01: 16-bits
10: 32-bits
11: Reserved 
*/
void DMA1_set_MSIZE(U8 channel, U8 msz);

#define DMA1_set_memory_size(channel, size)	DMA1_set_MSIZE(channel, size)

//Channel1-7 存储器传送单位尺寸
#define DMA1_CH1_set_memory_size(size)	DMA1_set_MSIZE(1, size)
#define DMA1_CH2_set_memory_size(size)	DMA1_set_MSIZE(2, size)
#define DMA1_CH3_set_memory_size(size)	DMA1_set_MSIZE(3, size)
#define DMA1_CH4_set_memory_size(size)	DMA1_set_MSIZE(4, size)
#define DMA1_CH5_set_memory_size(size)	DMA1_set_MSIZE(5, size)
#define DMA1_CH6_set_memory_size(size)	DMA1_set_MSIZE(6, size)
#define DMA1_CH7_set_memory_size(size)	DMA1_set_MSIZE(7, size)

//Channel1 存储器传送单位尺寸
#define DMA1_CH1_set_memory_size_8()	DMA1_set_MSIZE(1, 0)
#define DMA1_CH1_set_memory_size_16()	DMA1_set_MSIZE(1, 1)
#define DMA1_CH1_set_memory_size_32()	DMA1_set_MSIZE(1, 2)
//Channel2 存储器传送单位尺寸
#define DMA1_CH2_set_memory_size_8()	DMA1_set_MSIZE(2, 0)
#define DMA1_CH2_set_memory_size_16()	DMA1_set_MSIZE(2, 1)
#define DMA1_CH2_set_memory_size_32()	DMA1_set_MSIZE(2, 2)
//Channel3 存储器传送单位尺寸
#define DMA1_CH3_set_memory_size_8()	DMA1_set_MSIZE(3, 0)
#define DMA1_CH3_set_memory_size_16()	DMA1_set_MSIZE(3, 1)
#define DMA1_CH3_set_memory_size_32()	DMA1_set_MSIZE(3, 2)
//Channel4 存储器传送单位尺寸
#define DMA1_CH4_set_memory_size_8()	DMA1_set_MSIZE(4, 0)
#define DMA1_CH4_set_memory_size_16()	DMA1_set_MSIZE(4, 1)
#define DMA1_CH4_set_memory_size_32()	DMA1_set_MSIZE(4, 2)
//Channel5 存储器传送单位尺寸
#define DMA1_CH5_set_memory_size_8()	DMA1_set_MSIZE(5, 0)
#define DMA1_CH5_set_memory_size_16()	DMA1_set_MSIZE(5, 1)
#define DMA1_CH5_set_memory_size_32()	DMA1_set_MSIZE(5, 2)
//Channel6 存储器传送单位尺寸
#define DMA1_CH6_set_memory_size_8()	DMA1_set_MSIZE(6, 0)
#define DMA1_CH6_set_memory_size_16()	DMA1_set_MSIZE(6, 1)
#define DMA1_CH6_set_memory_size_32()	DMA1_set_MSIZE(6, 2)
//Channel7 存储器传送单位尺寸
#define DMA1_CH7_set_memory_size_8()	DMA1_set_MSIZE(7, 0)
#define DMA1_CH7_set_memory_size_16()	DMA1_set_MSIZE(7, 1)
#define DMA1_CH7_set_memory_size_32()	DMA1_set_MSIZE(7, 2)


/*
外设传输单位尺寸
Bits 9:8 PSIZE[1:0]: Peripheral size       
These bits are set and cleared by software.
00: 8-bits
01: 16-bits
10: 32-bits
11: Reserved 
*/
void DMA1_set_PSIZE(U8 channel, U8 psz);

#define DMA1_set_peripheral_size(channel, size)	DMA1_set_PSIZE(channel, size)

//Channel1-7 外设传送单位尺寸
#define DMA1_CH1_set_peripheral_size(size)	DMA1_set_PSIZE(1, size)
#define DMA1_CH2_set_peripheral_size(size)	DMA1_set_PSIZE(2, size)
#define DMA1_CH3_set_peripheral_size(size)	DMA1_set_PSIZE(3, size)
#define DMA1_CH4_set_peripheral_size(size)	DMA1_set_PSIZE(4, size)
#define DMA1_CH5_set_peripheral_size(size)	DMA1_set_PSIZE(5, size)
#define DMA1_CH6_set_peripheral_size(size)	DMA1_set_PSIZE(6, size)
#define DMA1_CH7_set_peripheral_size(size)	DMA1_set_PSIZE(7, size)

//Channel1 外设传送单位尺寸
#define DMA1_CH1_set_peripheral_size_8()	DMA1_set_PSIZE(1, 0)
#define DMA1_CH1_set_peripheral_size_16()	DMA1_set_PSIZE(1, 1)
#define DMA1_CH1_set_peripheral_size_32()	DMA1_set_PSIZE(1, 2)
//Channel2 外设传送单位尺寸
#define DMA1_CH2_set_peripheral_size_8()	DMA1_set_PSIZE(2, 0)
#define DMA1_CH2_set_peripheral_size_16()	DMA1_set_PSIZE(2, 1)
#define DMA1_CH2_set_peripheral_size_32()	DMA1_set_PSIZE(2, 2)
//Channel3 外设传送单位尺寸
#define DMA1_CH3_set_peripheral_size_8()	DMA1_set_PSIZE(3, 0)
#define DMA1_CH3_set_peripheral_size_16()	DMA1_set_PSIZE(3, 1)
#define DMA1_CH3_set_peripheral_size_32()	DMA1_set_PSIZE(3, 2)
//Channel4 外设传送单位尺寸
#define DMA1_CH4_set_peripheral_size_8()	DMA1_set_PSIZE(4, 0)
#define DMA1_CH4_set_peripheral_size_16()	DMA1_set_PSIZE(4, 1)
#define DMA1_CH4_set_peripheral_size_32()	DMA1_set_PSIZE(4, 2)
//Channel5 外设传送单位尺寸
#define DMA1_CH5_set_peripheral_size_8()	DMA1_set_PSIZE(5, 0)
#define DMA1_CH5_set_peripheral_size_16()	DMA1_set_PSIZE(5, 1)
#define DMA1_CH5_set_peripheral_size_32()	DMA1_set_PSIZE(5, 2)
//Channel6 外设传送单位尺寸
#define DMA1_CH6_set_peripheral_size_8()	DMA1_set_PSIZE(6, 0)
#define DMA1_CH6_set_peripheral_size_16()	DMA1_set_PSIZE(6, 1)
#define DMA1_CH6_set_peripheral_size_32()	DMA1_set_PSIZE(6, 2)
//Channel7 外设传送单位尺寸
#define DMA1_CH7_set_peripheral_size_8()	DMA1_set_PSIZE(7, 0)
#define DMA1_CH7_set_peripheral_size_16()	DMA1_set_PSIZE(7, 1)
#define DMA1_CH7_set_peripheral_size_32()	DMA1_set_PSIZE(7, 2)





/*
存储器增量模式
Bit 7 MINC: Memory increment mode        
This bit is set and cleared by software.
0: Memory increment mode disabled
1: Memory increment mode enabled 
*/
void DMA1_set_MINC(U8 channel, U8 minc);

//使能存储器自增模式
#define DMA1_enable_memory_increment_mode(channel)	DMA1_set_MINC(channel, 1)

#define DMA1_CH1_enable_memory_increment_mode()	DMA1_set_MINC(1, 1)    	//通道1使能存储器自增模式
#define DMA1_CH2_enable_memory_increment_mode()	DMA1_set_MINC(2, 1)    	//通道2使能存储器自增模式
#define DMA1_CH3_enable_memory_increment_mode()	DMA1_set_MINC(3, 1)		//通道3使能存储器自增模式
#define DMA1_CH4_enable_memory_increment_mode()	DMA1_set_MINC(4, 1)     //通道4使能存储器自增模式
#define DMA1_CH5_enable_memory_increment_mode()	DMA1_set_MINC(5, 1)     //通道5使能存储器自增模式
#define DMA1_CH6_enable_memory_increment_mode()	DMA1_set_MINC(6, 1)     //通道6使能存储器自增模式
#define DMA1_CH7_enable_memory_increment_mode()	DMA1_set_MINC(7, 1)     //通道7使能存储器自增模式


//除能存储器自增模式
#define DMA1_disable_memory_increment_mode(channel)	DMA1_set_MINC(channel, 0)

#define DMA1_CH1_disable_memory_increment_mode()	DMA1_set_MINC(1, 0)  //通道1除能存储器自动模式
#define DMA1_CH2_disable_memory_increment_mode()	DMA1_set_MINC(2, 0)  //通道2除能存储器自动模式
#define DMA1_CH3_disable_memory_increment_mode()	DMA1_set_MINC(3, 0)  //通道3除能存储器自动模式
#define DMA1_CH4_disable_memory_increment_mode()	DMA1_set_MINC(4, 0)  //通道4除能存储器自动模式
#define DMA1_CH5_disable_memory_increment_mode()	DMA1_set_MINC(5, 0)  //通道5除能存储器自动模式
#define DMA1_CH6_disable_memory_increment_mode()	DMA1_set_MINC(6, 0)  //通道6除能存储器自动模式
#define DMA1_CH7_disable_memory_increment_mode()	DMA1_set_MINC(7, 0)  //通道7除能存储器自动模式




/*
外设增量模式
Bit 6 PINC: Peripheral increment mode     
This bit is set and cleared by software.
0: Peripheral increment mode disabled
1: Peripheral increment mode enabled 
*/
void DMA1_set_PINC(U8 channel, U8 pinc);

//使能外设自增模式
#define DMA1_enable_peripheral_increment_mode(channel)	DMA1_set_PINC(channel, 1)

#define DMA1_CH1_enable_peripheral_increment_mode()	DMA1_set_PINC(1, 1)    	//通道1使能外设自增模式
#define DMA1_CH2_enable_peripheral_increment_mode()	DMA1_set_PINC(2, 1)    	//通道2使能外设自增模式
#define DMA1_CH3_enable_peripheral_increment_mode()	DMA1_set_PINC(3, 1)		//通道3使能外设自增模式
#define DMA1_CH4_enable_peripheral_increment_mode()	DMA1_set_PINC(4, 1)     //通道4使能外设自增模式
#define DMA1_CH5_enable_peripheral_increment_mode()	DMA1_set_PINC(5, 1)     //通道5使能外设自增模式
#define DMA1_CH6_enable_peripheral_increment_mode()	DMA1_set_PINC(6, 1)     //通道6使能外设自增模式
#define DMA1_CH7_enable_peripheral_increment_mode()	DMA1_set_PINC(7, 1)     //通道7使能外设自增模式


//除能外设自增模式
#define DMA1_disable_peripheral_increment_mode(channel)	DMA1_set_PINC(channel, 0)

#define DMA1_CH1_disable_peripheral_increment_mode()	DMA1_set_PINC(1, 0)  //通道1除能外设自动模式
#define DMA1_CH2_disable_peripheral_increment_mode()	DMA1_set_PINC(2, 0)  //通道2除能外设自动模式
#define DMA1_CH3_disable_peripheral_increment_mode()	DMA1_set_PINC(3, 0)  //通道3除能外设自动模式
#define DMA1_CH4_disable_peripheral_increment_mode()	DMA1_set_PINC(4, 0)  //通道4除能外设自动模式
#define DMA1_CH5_disable_peripheral_increment_mode()	DMA1_set_PINC(5, 0)  //通道5除能外设自动模式
#define DMA1_CH6_disable_peripheral_increment_mode()	DMA1_set_PINC(6, 0)  //通道6除能外设自动模式
#define DMA1_CH7_disable_peripheral_increment_mode()	DMA1_set_PINC(7, 0)  //通道7除能外设自动模式



/*
循环模式 使能
Bit 5 CIRC: Circular mode                  
This bit is set and cleared by software.
0: Circular mode disabled
1: Circular mode enabled
*/
void DMA1_set_CIRC(U8 channel, U8 e_d);

//使能循环模式
#define DMA1_enable_circular_mode(channel)	DMA1_set_CIRC(channel, 1)

#define DMA1_CH1_enable_circular_mode()	DMA1_set_CIRC(1, 1)    		//通道1使能循环模式
#define DMA1_CH2_enable_circular_mode()	DMA1_set_CIRC(2, 1)    		//通道2使能循环模式
#define DMA1_CH3_enable_circular_mode()	DMA1_set_CIRC(3, 1)    		//通道3使能循环模式
#define DMA1_CH4_enable_circular_mode()	DMA1_set_CIRC(4, 1)    		//通道4使能循环模式
#define DMA1_CH5_enable_circular_mode()	DMA1_set_CIRC(5, 1)    		//通道5使能循环模式
#define DMA1_CH6_enable_circular_mode()	DMA1_set_CIRC(6, 1)    		//通道6使能循环模式
#define DMA1_CH7_enable_circular_mode()	DMA1_set_CIRC(7, 1)    		//通道7使能循环模式

//除能循环模式
#define DMA1_disable_circular_mode(channel)	DMA1_set_CIRC(channel, 0)

#define DMA1_CH1_disable_circular_mode()	DMA1_set_CIRC(1, 0)  	//通道1除能循环模式
#define DMA1_CH2_disable_circular_mode()	DMA1_set_CIRC(2, 0)  	//通道2除能循环模式
#define DMA1_CH3_disable_circular_mode()	DMA1_set_CIRC(3, 0)		//通道3除能循环模式
#define DMA1_CH4_disable_circular_mode()	DMA1_set_CIRC(4, 0)     //通道4除能循环模式
#define DMA1_CH5_disable_circular_mode()	DMA1_set_CIRC(5, 0)     //通道5除能循环模式
#define DMA1_CH6_disable_circular_mode()	DMA1_set_CIRC(6, 0)     //通道6除能循环模式
#define DMA1_CH7_disable_circular_mode()	DMA1_set_CIRC(7, 0)     //通道7除能循环模式


/*
数据传输方向
Bit 4 DIR: Data transfer direction
This bit is set and cleared by software.
0: Read from peripheral
1: Read from memory
*/
void DMA1_set_DIR(U8 channel, U8 dir);


//数据传输方向
#define DMA1_set_transfer_direction(channel, dir)	DMA1_set_DIR(channel, dir)

#define DMA1_CH1_set_transfer_direction(dir)		DMA1_set_DIR(1, dir)
#define DMA1_CH2_set_transfer_direction(dir)		DMA1_set_DIR(2, dir)
#define DMA1_CH3_set_transfer_direction(dir)		DMA1_set_DIR(3, dir)
#define DMA1_CH4_set_transfer_direction(dir)		DMA1_set_DIR(4, dir)
#define DMA1_CH5_set_transfer_direction(dir)		DMA1_set_DIR(5, dir)
#define DMA1_CH6_set_transfer_direction(dir)		DMA1_set_DIR(6, dir)
#define DMA1_CH7_set_transfer_direction(dir)		DMA1_set_DIR(7, dir)

//Channel 1 方向
#define DMA1_CH1_set_transfer_direction_from_peripheral()	DMA1_set_DIR(1, 0)   	//通道1 从外设读取
#define DMA1_CH1_set_transfer_direction_from_memory()		DMA1_set_DIR(1, 1)   	//通道1 从存储器读取

//Channel 2 方向
#define DMA1_CH2_set_transfer_direction_from_peripheral()	DMA1_set_DIR(2, 0)   	//通道2 从外设读取
#define DMA1_CH2_set_transfer_direction_from_memory()		DMA1_set_DIR(2, 1)   	//通道2 从存储器读取

//Channel 3 方向
#define DMA1_CH3_set_transfer_direction_from_peripheral()	DMA1_set_DIR(3, 0)    	//通道3 从外设读取
#define DMA1_CH3_set_transfer_direction_from_memory()		DMA1_set_DIR(3, 1)    	//通道3 从存储器读取

//Channel 4 方向
#define DMA1_CH4_set_transfer_direction_from_peripheral()	DMA1_set_DIR(4, 0)    	//通道4 从外设读取
#define DMA1_CH4_set_transfer_direction_from_memory()		DMA1_set_DIR(4, 1)    	//通道4 从存储器读取

//Channel 5 方向
#define DMA1_CH5_set_transfer_direction_from_peripheral()	DMA1_set_DIR(5, 0)    	//通道5 从外设读取
#define DMA1_CH5_set_transfer_direction_from_memory()		DMA1_set_DIR(5, 1)    	//通道5 从存储器读取

//Channel 6 方向
#define DMA1_CH6_set_transfer_direction_from_peripheral()	DMA1_set_DIR(6, 0)    	//通道6 从外设读取
#define DMA1_CH6_set_transfer_direction_from_memory()		DMA1_set_DIR(6, 1)    	//通道6 从存储器读取

//Channel 7 方向
#define DMA1_CH7_set_transfer_direction_from_peripheral()	DMA1_set_DIR(7, 0)     	//通道7 从外设读取
#define DMA1_CH7_set_transfer_direction_from_memory()		DMA1_set_DIR(7, 1)    	//通道7 从存储器读取


/*
传输错误中断使能
Bit 3 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
*/
void DMA1_set_TEIE(U8 channel, U8 e_d);

#define DMA1_enable_interrupt_at_transfer_error(channel)	DMA1_set_TEIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_error(channel)	DMA1_set_TEIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(7, 0)



/*
传输过半中断使能
Bit 2 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
*/
void DMA1_set_HTIE(U8 channel, U8 e_d);



#define DMA1_enable_interrupt_at_transfer_half(channel)	DMA1_set_HTIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_half(channel)	DMA1_set_HTIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(7, 0)


/*
传输完成中断使能
Bit 1 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
*/
void DMA1_set_TCIE(U8 channel, U8 e_d);


#define DMA1_enable_interrupt_at_transfer_complete(channel)	DMA1_set_TCIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_complete(channel)	DMA1_set_TCIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(7, 0)



/*
DMA通道使能
Bit 0 EN: Channel enable
This bit is set and cleared by software.
0: Channel disabled
1: Channel enabled
*/
void DMA1_set_EN(U8 channel, U8 e_d);

#define DMA1_enable_channel(channel)	DMA1_set_EN(channel, 1)

#define DMA1_CH1_enable_channel()		DMA1_set_EN(1, 1)
#define DMA1_CH2_enable_channel()		DMA1_set_EN(2, 1)
#define DMA1_CH3_enable_channel()		DMA1_set_EN(3, 1)
#define DMA1_CH4_enable_channel()		DMA1_set_EN(4, 1)
#define DMA1_CH5_enable_channel()		DMA1_set_EN(5, 1)
#define DMA1_CH6_enable_channel()		DMA1_set_EN(6, 1)
#define DMA1_CH7_enable_channel()		DMA1_set_EN(7, 1)

#define DMA1_disable_channel(channel)	DMA1_set_EN(channel, 0)

#define DMA1_CH1_disable_channel()		DMA1_set_EN(1, 0)
#define DMA1_CH2_disable_channel()		DMA1_set_EN(2, 0)
#define DMA1_CH3_disable_channel()		DMA1_set_EN(3, 0)
#define DMA1_CH4_disable_channel()		DMA1_set_EN(4, 0)
#define DMA1_CH5_disable_channel()		DMA1_set_EN(5, 0)
#define DMA1_CH6_disable_channel()		DMA1_set_EN(6, 0)
#define DMA1_CH7_disable_channel()		DMA1_set_EN(7, 0)


//***********DMA channel x number of data register (DMA_CNDTRx)***********//
//DMA通道x数据数量寄存器
/*
DMA channel x number of data register (DMA_CNDTRx) (x = 1..7),
where x = channel number)
Address offset: 0x0C + 0d20 × (channel number – 1)
Reset value: 0x0000 0000
*/
/*
Bits 31:16
Reserved, always read as 0.
*/

/*
传输数量
Bits 15:0 NDT[15:0]: Number of data to transfer
Number of data to be transferred (0 up to 65535). This register can only be written when the 
channel is disabled. Once the channel is enabled, this register is read-only, indicating the 
remaining bytes to be transmitted. This register decrements after each DMA transfer.
Once the transfer is completed, this register can either stay at zero or be reloaded 
automatically by the value previously programmed if the channel is configured in auto-reload 
mode.
If this register is zero, no transaction can be served whether the channel is enabled or not.
*/
//设置传输量
void DMA1_set_NDT(U8 channel, U16 num);


#define DMA1_set_transfer_number(channel, num)	DMA1_set_NDT(channel, num)

#define DMA1_CH1_set_transfer_number(num)	DMA1_set_NDT(1, num)
#define DMA1_CH2_set_transfer_number(num)	DMA1_set_NDT(2, num)
#define DMA1_CH3_set_transfer_number(num)	DMA1_set_NDT(3, num)
#define DMA1_CH4_set_transfer_number(num)	DMA1_set_NDT(4, num)
#define DMA1_CH5_set_transfer_number(num)	DMA1_set_NDT(5, num)
#define DMA1_CH6_set_transfer_number(num)	DMA1_set_NDT(6, num)
#define DMA1_CH7_set_transfer_number(num)	DMA1_set_NDT(7, num)



//获得当前剩余要传输的数据量
U16 DMA1_get_NDT(U8 channel);

#define DMA1_get_transfer_number(channel)	DMA1_get_NDT(channel)

#define DMA1_CH1_get_transfer_number()		DMA1_get_NDT(1)
#define DMA1_CH2_get_transfer_number()		DMA1_get_NDT(2)
#define DMA1_CH3_get_transfer_number()		DMA1_get_NDT(3)
#define DMA1_CH4_get_transfer_number()		DMA1_get_NDT(4)
#define DMA1_CH5_get_transfer_number()		DMA1_get_NDT(5)
#define DMA1_CH6_get_transfer_number()		DMA1_get_NDT(6)
#define DMA1_CH7_get_transfer_number()		DMA1_get_NDT(7)




//****************DMA channel x peripheral address register******************//
//外设起始地址寄存器

/*
DMA channel x peripheral address register (DMA_CPARx) (x = 1..7),
where x = channel number)
Address offset: 0x10 + 0d20 × (channel number – 1)
Reset value: 0x0000 0000
This register must not be written when the channel is enabled.
*/

/*
Bits 31:0 PA[31:0]: Peripheral address
Base address of the peripheral data register from/to which the data will be read/written.
When PSIZE is 01 (16-bit), the PA[0] bit is ignored. Access is automatically aligned to a half-
word address.
When PSIZE is 10 (32-bit), PA[1:0] are ignored. Access is automatically aligned to a word 
address.
*/
void DMA1_set_PA(U8 channel, U32 adr);


#define DMA1_set_peripheral_address(channel, adr)	DMA1_set_PA(channel, adr)

#define DMA1_CH1_set_peripheral_address(adr)		DMA1_set_PA(1, adr)
#define DMA1_CH2_set_peripheral_address(adr)		DMA1_set_PA(2, adr)
#define DMA1_CH3_set_peripheral_address(adr)		DMA1_set_PA(3, adr)
#define DMA1_CH4_set_peripheral_address(adr)		DMA1_set_PA(4, adr)
#define DMA1_CH5_set_peripheral_address(adr)		DMA1_set_PA(5, adr)
#define DMA1_CH6_set_peripheral_address(adr)		DMA1_set_PA(6, adr)
#define DMA1_CH7_set_peripheral_address(adr)		DMA1_set_PA(7, adr)


U32	DMA1_get_PA(U8 channel);

#define DMA1_get_peripheral_address(channel)	DMA1_get_PA(channel)

#define DMA1_CH1_get_peripheral_address(adr)		DMA1_get_PA(1)
#define DMA1_CH2_get_peripheral_address(adr)		DMA1_get_PA(2)
#define DMA1_CH3_get_peripheral_address(adr)		DMA1_get_PA(3)
#define DMA1_CH4_get_peripheral_address(adr)		DMA1_get_PA(4)
#define DMA1_CH5_get_peripheral_address(adr)		DMA1_get_PA(5)
#define DMA1_CH6_get_peripheral_address(adr)		DMA1_get_PA(6)
#define DMA1_CH7_get_peripheral_address(adr)		DMA1_get_PA(7)


//**************DMA channel x memory address register (DMA_CMARx) ***********//
//存储器起始地址寄存器

/*
DMA channel x memory address register (DMA_CMARx) (x = 1..7),
where x = channel number)
Address offset: 0x14 + 0d20 × (channel number – 1)
Reset value: 0x0000 0000
This register must not be written when the channel is enabled.
*/

/*
Bits 31:0 MA[31:0]: Memory address
Base address of the memory area from/to which the data will be read/written. 
When MSIZE is 01 (16-bit), the MA[0] bit is ignored. Access is automatically aligned to a 
half-word address.
When MSIZE is 10 (32-bit), MA[1:0] are ignored. Access is automatically aligned to a word 
address.
*/

void DMA1_set_MA(U8 channel, U32 adr);


#define DMA1_set_memory_address(channel, adr)	DMA1_set_MA(channel, adr)

#define DMA1_CH1_set_memory_address(adr)		DMA1_set_MA(1, adr)
#define DMA1_CH2_set_memory_address(adr)		DMA1_set_MA(2, adr)
#define DMA1_CH3_set_memory_address(adr)		DMA1_set_MA(3, adr)
#define DMA1_CH4_set_memory_address(adr)		DMA1_set_MA(4, adr)
#define DMA1_CH5_set_memory_address(adr)		DMA1_set_MA(5, adr)
#define DMA1_CH6_set_memory_address(adr)		DMA1_set_MA(6, adr)
#define DMA1_CH7_set_memory_address(adr)		DMA1_set_MA(7, adr)




U32	 DMA1_get_MA(U8 channel);


#define DMA1_get_memory_address(channel)	DMA1_get_MA(channel)

#define DMA1_CH1_get_memory_address(adr)		DMA1_get_MA(1)
#define DMA1_CH2_get_memory_address(adr)		DMA1_get_MA(2)
#define DMA1_CH3_get_memory_address(adr)		DMA1_get_MA(3)
#define DMA1_CH4_get_memory_address(adr)		DMA1_get_MA(4)
#define DMA1_CH5_get_memory_address(adr)		DMA1_get_MA(5)
#define DMA1_CH6_get_memory_address(adr)		DMA1_get_MA(6)
#define DMA1_CH7_get_memory_address(adr)		DMA1_get_MA(7)



#endif
/*
	该文档定义了stm32f103zet6中EXIT的相关寄存器和对这些寄存器的操作函数。
*/

#ifndef __EXTI
#define __EXTI


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

#ifndef __FSMC
#define __FSMC


#include "com.h"

//Nor/PSRAM控制寄存器
#define __FSMC_BCR1 	FSMC_Bank1_R_BASE + 0x00000000  	//块1 0xA0000000
#define __FSMC_BCR2 	FSMC_Bank1_R_BASE + 0x00000008  	//块2 0xA0000008
#define __FSMC_BCR3		FSMC_Bank1_R_BASE + 0x00000010  	//块3 0xA0000010
#define __FSMC_BCR4 	FSMC_Bank1_R_BASE + 0x00000018  	//块4 0xA0000018

//Nor/PSRAM读时序寄存器
#define __FSMC_BTR1		FSMC_Bank1_R_BASE + 0x00000004  	//块1 0xA0000004
#define __FSMC_BTR2		FSMC_Bank1_R_BASE + 0x0000000C  	//块2 0xA000000C
#define __FSMC_BTR3		FSMC_Bank1_R_BASE + 0x00000014 		//块3 0xA0000014
#define __FSMC_BTR4		FSMC_Bank1_R_BASE + 0x0000001C  	//块4 0xA000001C

//Nor/PSRAM写时序寄存器
#define __FSMC_BWTR1    FSMC_Bank1E_R_BASE + 0x00000000  	//块1 0xA0000104
#define __FSMC_BWTR2	FSMC_Bank1E_R_BASE + 0x00000008  	//块2 0xA000010C
#define __FSMC_BWTR3	FSMC_Bank1E_R_BASE + 0x00000010  	//块3 0xA0000114
#define __FSMC_BWTR4	FSMC_Bank1E_R_BASE + 0x00000018  	//块4 0xA000011C

//Nor/PSRAM控制寄存器
#define _FSMC_BCR1		ADR(__FSMC_BCR1) 	
#define _FSMC_BCR2 		ADR(__FSMC_BCR2)
#define _FSMC_BCR3		ADR(__FSMC_BCR3)
#define _FSMC_BCR4 		ADR(__FSMC_BCR4)

//Nor/PSRAM读时序寄存器
#define _FSMC_BTR1		ADR(__FSMC_BTR1)
#define _FSMC_BTR2		ADR(__FSMC_BTR2)
#define _FSMC_BTR3		ADR(__FSMC_BTR3)
#define _FSMC_BTR4		ADR(__FSMC_BTR4)

//Nor/PSRAM写时序寄存器
#define _FSMC_BWTR1		ADR(__FSMC_BWTR1)   
#define _FSMC_BWTR2		ADR(__FSMC_BWTR2)	
#define _FSMC_BWTR3		ADR(__FSMC_BWTR3)	
#define _FSMC_BWTR4		ADR(__FSMC_BWTR4)

//Nor/PSRAM控制寄存器
#define FSMC_BCR1		VAL(__FSMC_BCR1) 	
#define FSMC_BCR2 		VAL(__FSMC_BCR2)
#define FSMC_BCR3		VAL(__FSMC_BCR3)
#define FSMC_BCR4 		VAL(__FSMC_BCR4)

//Nor/PSRAM读时序寄存器
#define FSMC_BTR1		VAL(__FSMC_BTR1)
#define FSMC_BTR2		VAL(__FSMC_BTR2)
#define FSMC_BTR3		VAL(__FSMC_BTR3)
#define FSMC_BTR4		VAL(__FSMC_BTR4)

//Nor/PSRAM写时序寄存器
#define FSMC_BWTR1		VAL(__FSMC_BWTR1)   
#define FSMC_BWTR2		VAL(__FSMC_BWTR2)	
#define FSMC_BWTR3		VAL(__FSMC_BWTR3)	
#define FSMC_BWTR4		VAL(__FSMC_BWTR4)




//Bank1 NORPSRAM Address
#define __FSMC_NORPSRAM1_ADDRESS_START 		0x60000000
#define __FSMC_NORPSRAM1_ADDRESS_END	    0x60FFFFFF

#define __FSMC_NORPSRAM2_ADDRESS_START 		0x64000000
#define __FSMC_NORPSRAM2_ADDRESS_END		0x64FFFFFF

#define __FSMC_NORPSRAM3_ADDRESS_START 		0x68000000
#define __FSMC_NORPSRAM3_ADDRESS_END		0x68FFFFFF

#define __FSMC_NORPSRAM4_ADDRESS_START 		0x6C000000
#define __FSMC_NORPSRAM4_ADDRESS_END		0x6CFFFFFF

//Bank1 NORPSRAM Value
#define FSMC_NORPSRAM1_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM1_ADDRESS_START)))
#define FSMC_NORPSRAM1_ADDRESS_END	    	(*((U16*)(__FSMC_NORPSRAM1_ADDRESS_END)))

#define FSMC_NORPSRAM2_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM2_ADDRESS_START)))
#define FSMC_NORPSRAM2_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM2_ADDRESS_END)))

#define FSMC_NORPSRAM3_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM3_ADDRESS_START)))
#define FSMC_NORPSRAM3_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM3_ADDRESS_END)))

#define FSMC_NORPSRAM4_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_START)))
#define FSMC_NORPSRAM4_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_END)))

#define FSMC_NORPSRAM4_VALUE(ADD)			(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_START + ADD)))

 

//*************************************************************8NOR/PSRAM controller registers*****************************************//

//******************SRAM/NOR-Flash chip-select control registers 1..4 (FSMC_BCR1..4)*********//
/*
成组写模式使能
Bit 19 CBURSTRW: Write burst enable.
For Cellular RAM, the bit enables synchronous burst protocol during write operations. For Flash 
memory access in burst mode, this bit enables/disables the wait state insertion via the NWAIT 
signal. The enable bit for the synchronous burst protocol during read access is the BURSTEN bit in 
the FSMC_BCRx register.
0: Write operations are always performed in asynchronous mode
1: Write operations are performed in synchronous mode.
*/
void FSMC_NORPSRAM1_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM2_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM3_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM4_set_CBURSTRW(U8 e_d);

#define FSMC_NORPSRAM1_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM1_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM2_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM2_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM3_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM3_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM4_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM4_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

/*             
同步模式下等待信号是否可用
Bit 15 ASYNCWAIT: Wait signal during asynchronous transfers
This bit enables the FSMC to use the wait signal even during an asynchronous protocol.
0: NWAIT signal is not taken in to account when running an asynchronous protocol (default after 
reset)
1: NWAIT signal is taken in to account when running an asynchronous protocol
*/
void FSMC_NORPSRAM1_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM2_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM3_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM4_set_ASYNCWAIT(U8 e_d);

#define FSMC_NORPSRAM1_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM1_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM2_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM2_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM3_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM3_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM4_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM4_set_ASYNCWAIT(1)

#define FSMC_NORPSRAM1_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM1_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM2_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM2_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM3_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM3_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM4_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM4_set_ASYNCWAIT(0)

/*
扩展模式是否使用(也就是是否读和写的时序独立)
Bit 14 EXTMOD: Extended mode enable.
This bit enables the FSMC to program inside the FSMC_BWTR register, so it allows different 
timings for read and write.
0: values inside FSMC_BWTR register are not taken into account (default after reset)
1: values inside FSMC_BWTR register are taken into account
*/
void FSMC_NORPSRAM1_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM2_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM3_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM4_set_EXTMOD(U8 e_d);

#define FSMC_NORPSRAM1_enable_extended_mode()	FSMC_NORPSRAM1_set_EXTMOD(1)
#define FSMC_NORPSRAM2_enable_extended_mode()	FSMC_NORPSRAM2_set_EXTMOD(1)
#define FSMC_NORPSRAM3_enable_extended_mode()	FSMC_NORPSRAM3_set_EXTMOD(1)
#define FSMC_NORPSRAM4_enable_extended_mode()	FSMC_NORPSRAM4_set_EXTMOD(1)

#define FSMC_NORPSRAM1_disable_extended_mode()	FSMC_NORPSRAM1_set_EXTMOD(0)
#define FSMC_NORPSRAM2_disable_extended_mode()	FSMC_NORPSRAM2_set_EXTMOD(0)
#define FSMC_NORPSRAM3_disable_extended_mode()	FSMC_NORPSRAM3_set_EXTMOD(0)
#define FSMC_NORPSRAM4_disable_extended_mode()	FSMC_NORPSRAM4_set_EXTMOD(0)

/*
在成组模式下等待信号是否
Bit 13 WAITEN: Wait enable bit.
For Flash memory access in burst mode, this bit enables/disables wait-state insertion via the 
NWAIT signal:
0: NWAIT signal is disabled (its level not taken into account, no wait state inserted after the 
programmed Flash latency period)
1: NWAIT signal is enabled (its level is taken into account after the programmed Flash latency 
period to insert wait states if asserted) (default after reset)
*/
void FSMC_NORPSRAM1_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM2_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM3_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM4_set_WAITEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_wait_signal()	FSMC_NORPSRAM1_set_WAITEN(1)
#define FSMC_NORPSRAM2_enable_wait_signal()	FSMC_NORPSRAM2_set_WAITEN(1)
#define FSMC_NORPSRAM3_enable_wait_signal()	FSMC_NORPSRAM3_set_WAITEN(1)
#define FSMC_NORPSRAM4_enable_wait_signal()	FSMC_NORPSRAM4_set_WAITEN(1)

#define FSMC_NORPSRAM1_disable_wait_signal()	FSMC_NORPSRAM1_set_WAITEN(0)
#define FSMC_NORPSRAM2_disable_wait_signal()	FSMC_NORPSRAM2_set_WAITEN(0)
#define FSMC_NORPSRAM3_disable_wait_signal()	FSMC_NORPSRAM3_set_WAITEN(0)
#define FSMC_NORPSRAM4_disable_wait_signal()	FSMC_NORPSRAM4_set_WAITEN(0)

/*
写使能
Bit 12 WREN: Write enable bit.
This bit indicates whether write operations are enabled/disabled in the bank by the FSMC:
0: Write operations are disabled in the bank by the FSMC, an AHB error is reported,
1: Write operations are enabled for the bank by the FSMC (default after reset).
*/
void FSMC_NORPSRAM1_set_WREN(U8 e_d);
void FSMC_NORPSRAM2_set_WREN(U8 e_d);
void FSMC_NORPSRAM3_set_WREN(U8 e_d);
void FSMC_NORPSRAM4_set_WREN(U8 e_d);

#define FSMC_NORPSRAM1_enable_write_operation()	FSMC_NORPSRAM1_set_WREN(1)
#define FSMC_NORPSRAM2_enable_write_operation()	FSMC_NORPSRAM2_set_WREN(1)
#define FSMC_NORPSRAM3_enable_write_operation()	FSMC_NORPSRAM3_set_WREN(1)
#define FSMC_NORPSRAM4_enable_write_operation()	FSMC_NORPSRAM4_set_WREN(1)

#define FSMC_NORPSRAM1_disable_write_operation()	FSMC_NORPSRAM1_set_WREN(0)
#define FSMC_NORPSRAM2_disable_write_operation()	FSMC_NORPSRAM2_set_WREN(0)
#define FSMC_NORPSRAM3_disable_write_operation()	FSMC_NORPSRAM3_set_WREN(0)
#define FSMC_NORPSRAM4_disable_write_operation()	FSMC_NORPSRAM4_set_WREN(0)


/*
等待信号在等待之前插入还是在等待中插入
Bit 11 WAITCFG: Wait timing configuration.
For memory access in burst mode, the NWAIT signal indicates whether the data from the memory 
are valid or if a wait state must be inserted. This configuration bit determines if NWAIT is asserted 
by the memory one clock cycle before the wait state or during the wait state:
0: NWAIT signal is active one data cycle before wait state (default after reset),
1: NWAIT signal is active during wait state (not for Cellular RAM).
*/
void FSMC_NORPSRAM1_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM2_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM3_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM4_set_WAITCFG(U8 sel);

#define FSMC_NORPSRAM1_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(0)
#define FSMC_NORPSRAM2_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM2_set_WAITCFG(0)
#define FSMC_NORPSRAM3_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM3_set_WAITCFG(0)
#define FSMC_NORPSRAM4_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM4_set_WAITCFG(0)

#define FSMC_NORPSRAM1_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM2_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM3_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM4_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)


/*
是否允许非对其的成组模式 是否允许在组模式下将AHB的组拆封成两个线性的访问.
Bit 10 WRAPMOD: Wrapped burst mode support.
Defines whether the controller will or not split an AHB burst wrap access into two linear accesses. 
Valid only when accessing memories in burst mode
0: Direct wrapped burst is not enabled (default after reset),
1: Direct wrapped burst is enabled.
Note: This bit has no effect as the CPU and DMA cannot generate wrapping burst transfers.
*/
void FSMC_NORPSRAM1_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM2_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM3_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM4_set_WRAPMOD(U8 e_d);

#define FSMC_NORPSRAM1_enable_split()	FSMC_NORPSRAM1_set_WRAPMOD(1)
#define FSMC_NORPSRAM2_enable_split()	FSMC_NORPSRAM2_set_WRAPMOD(1)
#define FSMC_NORPSRAM3_enable_split()	FSMC_NORPSRAM3_set_WRAPMOD(1)
#define FSMC_NORPSRAM4_enable_split()	FSMC_NORPSRAM4_set_WRAPMOD(1)

#define FSMC_NORPSRAM1_disable_split()	FSMC_NORPSRAM1_set_WRAPMOD(0)
#define FSMC_NORPSRAM2_disable_split()	FSMC_NORPSRAM2_set_WRAPMOD(0)
#define FSMC_NORPSRAM3_disable_split()	FSMC_NORPSRAM3_set_WRAPMOD(0)
#define FSMC_NORPSRAM4_disable_split()	FSMC_NORPSRAM4_set_WRAPMOD(0)

/*
等待信号的极性
Bit 9 WAITPOL: Wait signal polarity bit.
Defines the polarity of the wait signal from memory. Valid only when accessing the memory in burst 
mode:
0: NWAIT active low (default after reset),
1: NWAIT active high.
*/
void FSMC_NORPSRAM1_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM2_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM3_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM4_set_WAITPOL(U8 sel);

#define FSMC_NORPSRAM1_NWAIT_active_low()	FSMC_NORPSRAM1_set_WAITPOL(0)
#define FSMC_NORPSRAM2_NWAIT_active_low()	FSMC_NORPSRAM2_set_WAITPOL(0)
#define FSMC_NORPSRAM3_NWAIT_active_low()	FSMC_NORPSRAM3_set_WAITPOL(0)
#define FSMC_NORPSRAM4_NWAIT_active_low()	FSMC_NORPSRAM4_set_WAITPOL(0)

#define FSMC_NORPSRAM1_NWAIT_active_high()	FSMC_NORPSRAM1_set_WAITPOL(1)
#define FSMC_NORPSRAM2_NWAIT_active_high()	FSMC_NORPSRAM2_set_WAITPOL(1)
#define FSMC_NORPSRAM3_NWAIT_active_high()	FSMC_NORPSRAM3_set_WAITPOL(1)
#define FSMC_NORPSRAM4_NWAIT_active_high()	FSMC_NORPSRAM4_set_WAITPOL(1)



/*
成组模式使能  只能和支持同步成组模式的存储器合作
Bit 8 BURSTEN: Burst enable bit.
Enables the burst access mode for the memory. Valid only with synchronous burst memories:
0: Burst access mode disabled (default after reset)
1: Burst access mode enable
*/
void FSMC_NORPSRAM1_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM2_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM3_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM4_set_BURSTEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_burst_access()	FSMC_NORPSRAM1_set_BURSTEN(1)
#define FSMC_NORPSRAM2_enable_burst_access()	FSMC_NORPSRAM2_set_BURSTEN(1)
#define FSMC_NORPSRAM3_enable_burst_access()	FSMC_NORPSRAM3_set_BURSTEN(1)
#define FSMC_NORPSRAM4_enable_burst_access()	FSMC_NORPSRAM4_set_BURSTEN(1)

#define FSMC_NORPSRAM1_disable_burst_access()	FSMC_NORPSRAM1_set_BURSTEN(0)
#define FSMC_NORPSRAM2_disable_burst_access()	FSMC_NORPSRAM2_set_BURSTEN(0)
#define FSMC_NORPSRAM3_disable_burst_access()	FSMC_NORPSRAM3_set_BURSTEN(0)
#define FSMC_NORPSRAM4_disable_burst_access()	FSMC_NORPSRAM4_set_BURSTEN(0)



/*
Bit 7
Reserved.
*/

/*
闪存访问使能   如果和NOR闪存工作时，该位要使能
Bit 6 FACCEN: Flash access enable
Enables NOR Flash memory access operations.
0: Corresponding NOR Flash memory access is disabled
1: Corresponding NOR Flash memory access is enabled (default after reset)
*/
void FSMC_NORPSRAM1_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM2_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM3_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM4_set_FACCEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_NOR_flash_access()	FSMC_NORPSRAM1_set_FACCEN(1)
#define FSMC_NORPSRAM2_enable_NOR_flash_access()	FSMC_NORPSRAM2_set_FACCEN(1)
#define FSMC_NORPSRAM3_enable_NOR_flash_access()	FSMC_NORPSRAM3_set_FACCEN(1)
#define FSMC_NORPSRAM4_enable_NOR_flash_access()	FSMC_NORPSRAM4_set_FACCEN(1)

#define FSMC_NORPSRAM1_disable_NOR_flash_access()	FSMC_NORPSRAM1_set_FACCEN(0)
#define FSMC_NORPSRAM2_disable_NOR_flash_access()	FSMC_NORPSRAM2_set_FACCEN(0)
#define FSMC_NORPSRAM3_disable_NOR_flash_access()	FSMC_NORPSRAM3_set_FACCEN(0)
#define FSMC_NORPSRAM4_disable_NOR_flash_access()	FSMC_NORPSRAM4_set_FACCEN(0)

/*
存储器位宽
Bits 5:4 MWID: Memory databus width.
Defines the external memory device width, valid for all type of memories.
00: 8 bits,
01: 16 bits (default after reset),
10: reserved, do not use,
11: reserved, do not use.
*/
void FSMC_NORPSRAM1_set_MWID(U8 sel);
void FSMC_NORPSRAM2_set_MWID(U8 sel);
void FSMC_NORPSRAM3_set_MWID(U8 sel);
void FSMC_NORPSRAM4_set_MWID(U8 sel);

#define FSMC_NORPSRAM1_data_width_is_8()	FSMC_NORPSRAM1_set_MWID(0)
#define FSMC_NORPSRAM1_data_width_is_16()	FSMC_NORPSRAM1_set_MWID(1)

#define FSMC_NORPSRAM2_data_width_is_8()	FSMC_NORPSRAM2_set_MWID(0)
#define FSMC_NORPSRAM2_data_width_is_16()	FSMC_NORPSRAM2_set_MWID(1)

#define FSMC_NORPSRAM3_data_width_is_8()	FSMC_NORPSRAM3_set_MWID(0)
#define FSMC_NORPSRAM3_data_width_is_16()	FSMC_NORPSRAM3_set_MWID(1)

#define FSMC_NORPSRAM4_data_width_is_8()	FSMC_NORPSRAM4_set_MWID(0)
#define FSMC_NORPSRAM4_data_width_is_16()	FSMC_NORPSRAM4_set_MWID(1)

/*
存储器类型
Bits 3:2 MTYP: Memory type.
Defines the type of external memory attached to the corresponding memory bank:
00: SRAM, ROM (default after reset for Bank 2...4)
01: PSRAM (Cellular RAM: CRAM)
10: NOR Flash(default after reset for Bank 1)
11: reserved
*/
void FSMC_NORPSRAM1_set_MTYP(U8 sel);
void FSMC_NORPSRAM2_set_MTYP(U8 sel);
void FSMC_NORPSRAM3_set_MTYP(U8 sel);
void FSMC_NORPSRAM4_set_MTYP(U8 sel);

//SRAM
#define FSMC_NORPSRAM1_memory_type_is_SRAM()	FSMC_NORPSRAM1_set_MTYP(0)
#define FSMC_NORPSRAM2_memory_type_is_SRAM()	FSMC_NORPSRAM2_set_MTYP(0)
#define FSMC_NORPSRAM3_memory_type_is_SRAM()	FSMC_NORPSRAM3_set_MTYP(0)
#define FSMC_NORPSRAM4_memory_type_is_SRAM()	FSMC_NORPSRAM4_set_MTYP(0)

//ROM
#define FSMC_NORPSRAM1_memory_type_is_ROM()	FSMC_NOR_PROM_1_set_MTYP(0)
#define FSMC_NORPSRAM2_memory_type_is_ROM()	FSMC_NOR_PROM_2_set_MTYP(0)
#define FSMC_NORPSRAM3_memory_type_is_ROM()	FSMC_NOR_PROM_3_set_MTYP(0)
#define FSMC_NORPSRAM4_memory_type_is_ROM()	FSMC_NOR_PROM_4_set_MTYP(0)

//PSRAM
#define FSMC_NORPSRAM1_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_1_set_MTYP(1)
#define FSMC_NORPSRAM2_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_2_set_MTYP(1)
#define FSMC_NORPSRAM3_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_3_set_MTYP(1)
#define FSMC_NORPSRAM4_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_4_set_MTYP(1)

//NOR flash
#define FSMC_NORPSRAM1_memory_type_is_NOR()	FSMC_NOR_PNOR_1_set_MTYP(2)
#define FSMC_NORPSRAM2_memory_type_is_NOR()	FSMC_NOR_PNOR_2_set_MTYP(2)
#define FSMC_NORPSRAM3_memory_type_is_NOR()	FSMC_NOR_PNOR_3_set_MTYP(2)
#define FSMC_NORPSRAM4_memory_type_is_NOR()	FSMC_NOR_PNOR_4_set_MTYP(2)

/*
复用模式使能
Bit 1 MUXEN: Address/data multiplexing enable bit.
When this bit is set, the address and data values are multiplexed on the databus, valid only with 
NOR and PSRAM memories:
0: Address/Data nonmultiplexed
1: Address/Data multiplexed on databus (default after reset)
*/
void FSMC_NORPSRAM1_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM2_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM3_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM4_set_MUXEN(U8 e_d);

//使能复用模式
#define FSMC_NORPSRAM1_enable_multiplexed()	FSMC_NORPSRAM1_set_MUXEN(1)
#define FSMC_NORPSRAM2_enable_multiplexed()	FSMC_NORPSRAM2_set_MUXEN(1)
#define FSMC_NORPSRAM3_enable_multiplexed()	FSMC_NORPSRAM3_set_MUXEN(1)
#define FSMC_NORPSRAM4_enable_multiplexed()	FSMC_NORPSRAM4_set_MUXEN(1)

//除能复用模式
#define FSMC_NORPSRAM1_disable_multiplexed()	FSMC_NORPSRAM1_set_MUXEN(0)
#define FSMC_NORPSRAM2_disable_multiplexed()	FSMC_NORPSRAM2_set_MUXEN(0)
#define FSMC_NORPSRAM3_disable_multiplexed()	FSMC_NORPSRAM3_set_MUXEN(0)
#define FSMC_NORPSRAM4_disable_multiplexed()	FSMC_NORPSRAM4_set_MUXEN(0)


/*
存储器块使能
Bit 0 MBKEN: Memory bank enable bit.
Enables the memory bank. After reset Bank1 is enabled, all others are disabled. Accessing a 
disabled bank causes an ERROR on AHB bus.
0: Corresponding memory bank is disabled
1: Corresponding memory bank is enabled
*/
void FSMC_NORPSRAM1_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM2_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM3_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM4_set_MBKEN(U8 e_d);

//使能存储器块
#define FSMC_NORPSRAM1_enable_bank()	FSMC_NORPSRAM1_set_MBKEN(1)
#define FSMC_NORPSRAM2_enable_bank()	FSMC_NORPSRAM2_set_MBKEN(1)
#define FSMC_NORPSRAM3_enable_bank()	FSMC_NORPSRAM3_set_MBKEN(1)
#define FSMC_NORPSRAM4_enable_bank()	FSMC_NORPSRAM4_set_MBKEN(1)

//除能存储器块
#define FSMC_NORPSRAM1_disable_bank()	FSMC_NORPSRAM1_set_MBKEN(0)
#define FSMC_NORPSRAM2_disable_bank()	FSMC_NORPSRAM2_set_MBKEN(0)
#define FSMC_NORPSRAM3_disable_bank()	FSMC_NORPSRAM3_set_MBKEN(0)
#define FSMC_NORPSRAM4_disable_bank()	FSMC_NORPSRAM4_set_MBKEN(0)

/*
PSRAMs (CRAMs) have a variable latency due to internal refresh. Therefore these 
memories issue the NWAIT signal during the whole latency phase to prolong the latency as 
needed.
With PSRAMs (CRAMs) the filed DATLAT must be set to 0, so that the FSMC exits its 
latency phase soon and starts sampling NWAIT from memory, then starts to read or write 
when the memory is ready.
This method can be used also with the latest generation of synchronous Flash memories 
that issue the NWAIT signal, unlike older Flash memories (check the datasheet of the 
specific Flash memory being used).
*/


//***************SRAM/NOR-Flash chip-select timing registers 1..4 (FSMC_BTR1..4) ***************//
/*
Address offset: 0xA000 0000 + 0x04 + 8 * (x – 1), x = 1..4
Reset value: 0x0FFF FFFF
This register contains the control information of each memory bank, used for SRAMs, ROMs 
and NOR Flash memories. If the EXTMOD bit is set in the FSMC_BCRx register, then this 
register is partitioned for write and read access, that is, 2 registers are available: one to 
configure read accesses (this register) and one to configure write accesses (FSMC_BWTRx 
registers).
*/

/*
访问模式
Bits 29:28 ACCMOD: Access mode
Specifies the asynchronous access modes as shown in the timing diagrams. These bits are 
taken into account only when the EXTMOD bit in the FSMC_BCRx register is 1.
00: access mode A
01: access mode B
10: access mode C
11: access mode D
*/
void FSMC_NORPSRAM1_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM2_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM3_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM4_set_ACCMOD(U8 mod);

//选择模式A
#define FSMC_NORPSRAM1_access_mode_A()	FSMC_NORPSRAM1_set_ACCMOD(0)
#define FSMC_NORPSRAM2_access_mode_A()	FSMC_NORPSRAM2_set_ACCMOD(0)
#define FSMC_NORPSRAM3_access_mode_A()	FSMC_NORPSRAM3_set_ACCMOD(0)
#define FSMC_NORPSRAM4_access_mode_A()	FSMC_NORPSRAM4_set_ACCMOD(0)

//选择模式B
#define FSMC_NORPSRAM1_access_mode_B()	FSMC_NORPSRAM1_set_ACCMOD(1)
#define FSMC_NORPSRAM2_access_mode_B()	FSMC_NORPSRAM2_set_ACCMOD(1)
#define FSMC_NORPSRAM3_access_mode_B()	FSMC_NORPSRAM3_set_ACCMOD(1)
#define FSMC_NORPSRAM4_access_mode_B()	FSMC_NORPSRAM4_set_ACCMOD(1)

//选择模式C
#define FSMC_NORPSRAM1_access_mode_C()	FSMC_NORPSRAM1_set_ACCMOD(2)
#define FSMC_NORPSRAM2_access_mode_C()	FSMC_NORPSRAM2_set_ACCMOD(2)
#define FSMC_NORPSRAM3_access_mode_C()	FSMC_NORPSRAM3_set_ACCMOD(2)
#define FSMC_NORPSRAM4_access_mode_C()	FSMC_NORPSRAM4_set_ACCMOD(2)

//选择模式D
#define FSMC_NORPSRAM1_access_mode_D()	FSMC_NORPSRAM1_set_ACCMOD(3)
#define FSMC_NORPSRAM2_access_mode_D()	FSMC_NORPSRAM2_set_ACCMOD(3)
#define FSMC_NORPSRAM3_access_mode_D()	FSMC_NORPSRAM3_set_ACCMOD(3)
#define FSMC_NORPSRAM4_access_mode_D()	FSMC_NORPSRAM4_set_ACCMOD(3)



/*
第一次访问的等待数据时间 (同步成组模式下)
Bits 27:24 DATLAT (see note below bit descriptions): Data latency (for synchronous burst NOR Flash)
For NOR Flash with synchronous burst mode enabled, defines the number of memory clock 
cycles (+2) to issue to the memory before getting the first data:
This timing parameter is not expressed in HCLK periods, but in Flash clock (CLK) periods. In 
asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care. In case of 
CRAM, this field must be set to 0
0000: Data latency of 2 CLK clock cycles for first burst access
.......
1111: Data latency of 17 CLK clock cycles for first burst access (default value after reset)
*/
void FSMC_NORPSRAM1_set_DATLAT(U8 sel);
void FSMC_NORPSRAM2_set_DATLAT(U8 sel);
void FSMC_NORPSRAM3_set_DATLAT(U8 sel);
void FSMC_NORPSRAM4_set_DATLAT(U8 sel);

//t = 2 - 17
#define FSMC_NORPSRAM1_set_latency(t)	FSMC_NORPSRAM1_set_DATLAT(t-2)
#define FSMC_NORPSRAM2_set_latency(t)	FSMC_NORPSRAM2_set_DATLAT(t-2)
#define FSMC_NORPSRAM3_set_latency(t)	FSMC_NORPSRAM3_set_DATLAT(t-2)
#define FSMC_NORPSRAM4_set_latency(t)	FSMC_NORPSRAM4_set_DATLAT(t-2)

//等待时间为2个CLK
#define FSMC_NORPSRAM1_latency_is_2_CLK()	FSMC_NORPSRAM1_set_DATLAT(0)
#define FSMC_NORPSRAM2_latency_is_2_CLK()	FSMC_NORPSRAM2_set_DATLAT(0)
#define FSMC_NORPSRAM3_latency_is_2_CLK()	FSMC_NORPSRAM3_set_DATLAT(0)
#define FSMC_NORPSRAM4_latency_is_2_CLK()	FSMC_NORPSRAM4_set_DATLAT(0)

//等待时间为3个CLK
#define FSMC_NORPSRAM1_latency_is_3_CLK()	FSMC_NORPSRAM1_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK()	FSMC_NORPSRAM3_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK()	FSMC_NORPSRAM3_set_DATLAT(1)
#define FSMC_NORPSRAM4_latency_is_3_CLK()	FSMC_NORPSRAM4_set_DATLAT(1)

//等待时间为4个CLK
#define FSMC_NORPSRAM1_latency_is_4_CLK()	FSMC_NORPSRAM1_set_DATLAT(2)
#define FSMC_NORPSRAM2_latency_is_4_CLK()	FSMC_NORPSRAM2_set_DATLAT(2)
#define FSMC_NORPSRAM3_latency_is_4_CLK()	FSMC_NORPSRAM3_set_DATLAT(2)
#define FSMC_NORPSRAM4_latency_is_4_CLK()	FSMC_NORPSRAM4_set_DATLAT(2)

//等待时间为5个CLK
#define FSMC_NORPSRAM1_latency_is_5_CLK()	FSMC_NORPSRAM1_set_DATLAT(3)
#define FSMC_NORPSRAM2_latency_is_5_CLK()	FSMC_NORPSRAM2_set_DATLAT(3)
#define FSMC_NORPSRAM3_latency_is_5_CLK()	FSMC_NORPSRAM3_set_DATLAT(3)
#define FSMC_NORPSRAM4_latency_is_5_CLK()	FSMC_NORPSRAM4_set_DATLAT(3)

//等待时间为6个CLK
#define FSMC_NORPSRAM1_latency_is_6_CLK()	FSMC_NORPSRAM1_set_DATLAT(4)
#define FSMC_NORPSRAM2_latency_is_6_CLK()	FSMC_NORPSRAM2_set_DATLAT(4)
#define FSMC_NORPSRAM3_latency_is_6_CLK()	FSMC_NORPSRAM3_set_DATLAT(4)
#define FSMC_NORPSRAM4_latency_is_6_CLK()	FSMC_NORPSRAM4_set_DATLAT(4)

//等待时间为7个CLK
#define FSMC_NORPSRAM1_latency_is_7_CLK()	FSMC_NORPSRAM1_set_DATLAT(5)
#define FSMC_NORPSRAM2_latency_is_7_CLK()	FSMC_NORPSRAM2_set_DATLAT(5)
#define FSMC_NORPSRAM3_latency_is_7_CLK()	FSMC_NORPSRAM3_set_DATLAT(5)
#define FSMC_NORPSRAM4_latency_is_7_CLK()	FSMC_NORPSRAM4_set_DATLAT(5)

//等待时间为8个CLK
#define FSMC_NORPSRAM1_latency_is_8_CLK()	FSMC_NORPSRAM1_set_DATLAT(6)
#define FSMC_NORPSRAM2_latency_is_8_CLK()	FSMC_NORPSRAM2_set_DATLAT(6)
#define FSMC_NORPSRAM3_latency_is_8_CLK()	FSMC_NORPSRAM3_set_DATLAT(6)
#define FSMC_NORPSRAM4_latency_is_8_CLK()	FSMC_NORPSRAM4_set_DATLAT(6)

//等待时间为9个CLK
#define FSMC_NORPSRAM1_latency_is_9_CLK()	FSMC_NORPSRAM1_set_DATLAT(7)
#define FSMC_NORPSRAM2_latency_is_9_CLK()	FSMC_NORPSRAM2_set_DATLAT(7)
#define FSMC_NORPSRAM3_latency_is_9_CLK()	FSMC_NORPSRAM3_set_DATLAT(7)
#define FSMC_NORPSRAM4_latency_is_9_CLK()	FSMC_NORPSRAM4_set_DATLAT(7)

//等待时间为10个CLK
#define FSMC_NORPSRAM1_latency_is_10_CLK()	FSMC_NORPSRAM1_set_DATLAT(8)
#define FSMC_NORPSRAM2_latency_is_10_CLK()	FSMC_NORPSRAM2_set_DATLAT(8)
#define FSMC_NORPSRAM3_latency_is_10_CLK()	FSMC_NORPSRAM3_set_DATLAT(8)
#define FSMC_NORPSRAM4_latency_is_10_CLK()	FSMC_NORPSRAM4_set_DATLAT(8)

//等待时间为11个CLK
#define FSMC_NORPSRAM1_latency_is_11_CLK()	FSMC_NORPSRAM1_set_DATLAT(9)
#define FSMC_NORPSRAM2_latency_is_11_CLK()	FSMC_NORPSRAM2_set_DATLAT(9)
#define FSMC_NORPSRAM3_latency_is_11_CLK()	FSMC_NORPSRAM3_set_DATLAT(9)
#define FSMC_NORPSRAM4_latency_is_11_CLK()	FSMC_NORPSRAM4_set_DATLAT(9)

//等待时间为12个CLK
#define FSMC_NORPSRAM1_latency_is_12_CLK()	FSMC_NORPSRAM1_set_DATLAT(10)
#define FSMC_NORPSRAM2_latency_is_12_CLK()	FSMC_NORPSRAM2_set_DATLAT(10)
#define FSMC_NORPSRAM3_latency_is_12_CLK()	FSMC_NORPSRAM3_set_DATLAT(10)
#define FSMC_NORPSRAM4_latency_is_12_CLK()	FSMC_NORPSRAM4_set_DATLAT(10)

//等待时间为13个CLK
#define FSMC_NORPSRAM1_latency_is_13_CLK()	FSMC_NORPSRAM1_set_DATLAT(11)
#define FSMC_NORPSRAM2_latency_is_13_CLK()	FSMC_NORPSRAM2_set_DATLAT(11)
#define FSMC_NORPSRAM3_latency_is_13_CLK()	FSMC_NORPSRAM3_set_DATLAT(11)
#define FSMC_NORPSRAM4_latency_is_13_CLK()	FSMC_NORPSRAM4_set_DATLAT(11)

//等待时间为14个CLK
#define FSMC_NORPSRAM1_latency_is_14_CLK()	FSMC_NORPSRAM1_set_DATLAT(12)
#define FSMC_NORPSRAM2_latency_is_14_CLK()	FSMC_NORPSRAM2_set_DATLAT(12)
#define FSMC_NORPSRAM3_latency_is_14_CLK()	FSMC_NORPSRAM3_set_DATLAT(12)
#define FSMC_NORPSRAM4_latency_is_14_CLK()	FSMC_NORPSRAM4_set_DATLAT(12)

//等待时间为15个CLK
#define FSMC_NORPSRAM1_latency_is_15_CLK()	FSMC_NORPSRAM1_set_DATLAT(13)
#define FSMC_NORPSRAM2_latency_is_15_CLK()	FSMC_NORPSRAM2_set_DATLAT(13)
#define FSMC_NORPSRAM3_latency_is_15_CLK()	FSMC_NORPSRAM3_set_DATLAT(13)
#define FSMC_NORPSRAM4_latency_is_15_CLK()	FSMC_NORPSRAM4_set_DATLAT(13)

//等待时间为16个CLK
#define FSMC_NORPSRAM1_latency_is_16_CLK()	FSMC_NORPSRAM1_set_DATLAT(14)
#define FSMC_NORPSRAM2_latency_is_16_CLK()	FSMC_NORPSRAM2_set_DATLAT(14)
#define FSMC_NORPSRAM3_latency_is_16_CLK()	FSMC_NORPSRAM3_set_DATLAT(14)
#define FSMC_NORPSRAM4_latency_is_16_CLK()	FSMC_NORPSRAM4_set_DATLAT(14)

//等待时间为17个CLK
#define FSMC_NORPSRAM1_latency_is_17_CLK()	FSMC_NORPSRAM1_set_DATLAT(15)
#define FSMC_NORPSRAM2_latency_is_17_CLK()	FSMC_NORPSRAM2_set_DATLAT(15)
#define FSMC_NORPSRAM3_latency_is_17_CLK()	FSMC_NORPSRAM3_set_DATLAT(15)
#define FSMC_NORPSRAM4_latency_is_17_CLK()	FSMC_NORPSRAM4_set_DATLAT(15)


/*
同步模式输出时钟分频 （HCLK分频）
Bits 23:20 CLKDIV: Clock divide ratio (for CLK signal)
Defines the period of CLK clock output signal, expressed in number of HCLK cycles:
0000: Reserved
0001: CLK period = 2 × HCLK periods
0010: CLK period = 3 × HCLK periods
......
1111: CLK period = 16 × HCLK periods (default value after reset) 
In asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care.
*/
void FSMC_NORPSRAM1_set_CLKDIV(U8 div);
void FSMC_NORPSRAM2_set_CLKDIV(U8 div);
void FSMC_NORPSRAM3_set_CLKDIV(U8 div);
void FSMC_NORPSRAM4_set_CLKDIV(U8 div);

//div = 2 - 16
#define FSMC_NORPSRAM1_set_div(div)	FSMC_NORPSRAM1_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM2_set_div(div)	FSMC_NORPSRAM2_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM3_set_div(div)	FSMC_NORPSRAM3_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM4_set_div(div)	FSMC_NORPSRAM4_set_CLKDIV(div - 1)

//对NOR_PRAM存储块1的时钟分频
#define FSMC_NORPSRAM1_div_HCLK_with_2()			FSMC_NORPSRAM1_set_CLKDIV(1)
#define FSMC_NORPSRAM1_div_HCLK_with_3()			FSMC_NORPSRAM1_set_CLKDIV(2)
#define FSMC_NORPSRAM1_div_HCLK_with_4()			FSMC_NORPSRAM1_set_CLKDIV(3)
#define FSMC_NORPSRAM1_div_HCLK_with_5()			FSMC_NORPSRAM1_set_CLKDIV(4)
#define FSMC_NORPSRAM1_div_HCLK_with_6()			FSMC_NORPSRAM1_set_CLKDIV(5)
#define FSMC_NORPSRAM1_div_HCLK_with_7()			FSMC_NORPSRAM1_set_CLKDIV(6)
#define FSMC_NORPSRAM1_div_HCLK_with_8()			FSMC_NORPSRAM1_set_CLKDIV(7)
#define FSMC_NORPSRAM1_div_HCLK_with_9()			FSMC_NORPSRAM1_set_CLKDIV(8)
#define FSMC_NORPSRAM1_div_HCLK_with_10()		FSMC_NORPSRAM1_set_CLKDIV(9)
#define FSMC_NORPSRAM1_div_HCLK_with_11()		FSMC_NORPSRAM1_set_CLKDIV(10)
#define FSMC_NORPSRAM1_div_HCLK_with_12()		FSMC_NORPSRAM1_set_CLKDIV(11)
#define FSMC_NORPSRAM1_div_HCLK_with_13()		FSMC_NORPSRAM1_set_CLKDIV(12)
#define FSMC_NORPSRAM1_div_HCLK_with_14()		FSMC_NORPSRAM1_set_CLKDIV(13)
#define FSMC_NORPSRAM1_div_HCLK_with_15()		FSMC_NORPSRAM1_set_CLKDIV(14)
#define FSMC_NORPSRAM1_div_HCLK_with_16()		FSMC_NORPSRAM1_set_CLKDIV(15)

//对NOR_PRAM存储块2的时钟分频
#define FSMC_NORPSRAM2_div_HCLK_with_2()			FSMC_NORPSRAM2_set_CLKDIV(1)
#define FSMC_NORPSRAM2_div_HCLK_with_3()			FSMC_NORPSRAM2_set_CLKDIV(2)
#define FSMC_NORPSRAM2_div_HCLK_with_4()			FSMC_NORPSRAM2_set_CLKDIV(3)
#define FSMC_NORPSRAM2_div_HCLK_with_5()			FSMC_NORPSRAM2_set_CLKDIV(4)
#define FSMC_NORPSRAM2_div_HCLK_with_6()			FSMC_NORPSRAM2_set_CLKDIV(5)
#define FSMC_NORPSRAM2_div_HCLK_with_7()			FSMC_NORPSRAM2_set_CLKDIV(6)
#define FSMC_NORPSRAM2_div_HCLK_with_8()			FSMC_NORPSRAM2_set_CLKDIV(7)
#define FSMC_NORPSRAM2_div_HCLK_with_9()			FSMC_NORPSRAM2_set_CLKDIV(8)
#define FSMC_NORPSRAM2_div_HCLK_with_10()		FSMC_NORPSRAM2_set_CLKDIV(9)
#define FSMC_NORPSRAM2_div_HCLK_with_11()		FSMC_NORPSRAM2_set_CLKDIV(10)
#define FSMC_NORPSRAM2_div_HCLK_with_12()		FSMC_NORPSRAM2_set_CLKDIV(11)
#define FSMC_NORPSRAM2_div_HCLK_with_13()		FSMC_NORPSRAM2_set_CLKDIV(12)
#define FSMC_NORPSRAM2_div_HCLK_with_14()		FSMC_NORPSRAM2_set_CLKDIV(13)
#define FSMC_NORPSRAM2_div_HCLK_with_15()		FSMC_NORPSRAM2_set_CLKDIV(14)
#define FSMC_NORPSRAM2_div_HCLK_with_16()		FSMC_NORPSRAM2_set_CLKDIV(15)

//对NOR_PRAM存储块3的时钟分频
#define FSMC_NORPSRAM3_div_HCLK_with_2()			FSMC_NORPSRAM3_set_CLKDIV(1)
#define FSMC_NORPSRAM3_div_HCLK_with_3()			FSMC_NORPSRAM3_set_CLKDIV(2)
#define FSMC_NORPSRAM3_div_HCLK_with_4()			FSMC_NORPSRAM3_set_CLKDIV(3)
#define FSMC_NORPSRAM3_div_HCLK_with_5()			FSMC_NORPSRAM3_set_CLKDIV(4)
#define FSMC_NORPSRAM3_div_HCLK_with_6()			FSMC_NORPSRAM3_set_CLKDIV(5)
#define FSMC_NORPSRAM3_div_HCLK_with_7()			FSMC_NORPSRAM3_set_CLKDIV(6)
#define FSMC_NORPSRAM3_div_HCLK_with_8()			FSMC_NORPSRAM3_set_CLKDIV(7)
#define FSMC_NORPSRAM3_div_HCLK_with_9()			FSMC_NORPSRAM3_set_CLKDIV(8)
#define FSMC_NORPSRAM3_div_HCLK_with_10()		FSMC_NORPSRAM3_set_CLKDIV(9)
#define FSMC_NORPSRAM3_div_HCLK_with_11()		FSMC_NORPSRAM3_set_CLKDIV(10)
#define FSMC_NORPSRAM3_div_HCLK_with_12()		FSMC_NORPSRAM3_set_CLKDIV(11)
#define FSMC_NORPSRAM3_div_HCLK_with_13()		FSMC_NORPSRAM3_set_CLKDIV(12)
#define FSMC_NORPSRAM3_div_HCLK_with_14()		FSMC_NORPSRAM3_set_CLKDIV(13)
#define FSMC_NORPSRAM3_div_HCLK_with_15()		FSMC_NORPSRAM3_set_CLKDIV(14)
#define FSMC_NORPSRAM3_div_HCLK_with_16()		FSMC_NORPSRAM3_set_CLKDIV(15)

//对NOR_PRAM存储块4的时钟分频
#define FSMC_NORPSRAM4_div_HCLK_with_2()			FSMC_NORPSRAM4_set_CLKDIV(1)
#define FSMC_NORPSRAM4_div_HCLK_with_3()			FSMC_NORPSRAM4_set_CLKDIV(2)
#define FSMC_NORPSRAM4_div_HCLK_with_4()			FSMC_NORPSRAM4_set_CLKDIV(3)
#define FSMC_NORPSRAM4_div_HCLK_with_5()			FSMC_NORPSRAM4_set_CLKDIV(4)
#define FSMC_NORPSRAM4_div_HCLK_with_6()			FSMC_NORPSRAM4_set_CLKDIV(5)
#define FSMC_NORPSRAM4_div_HCLK_with_7()			FSMC_NORPSRAM4_set_CLKDIV(6)
#define FSMC_NORPSRAM4_div_HCLK_with_8()			FSMC_NORPSRAM4_set_CLKDIV(7)
#define FSMC_NORPSRAM4_div_HCLK_with_9()			FSMC_NORPSRAM4_set_CLKDIV(8)
#define FSMC_NORPSRAM4_div_HCLK_with_10()		FSMC_NORPSRAM4_set_CLKDIV(9)
#define FSMC_NORPSRAM4_div_HCLK_with_11()		FSMC_NORPSRAM4_set_CLKDIV(10)
#define FSMC_NORPSRAM4_div_HCLK_with_12()		FSMC_NORPSRAM4_set_CLKDIV(11)
#define FSMC_NORPSRAM4_div_HCLK_with_13()		FSMC_NORPSRAM4_set_CLKDIV(12)
#define FSMC_NORPSRAM4_div_HCLK_with_14()		FSMC_NORPSRAM4_set_CLKDIV(13)
#define FSMC_NORPSRAM4_div_HCLK_with_15()		FSMC_NORPSRAM4_set_CLKDIV(14)
#define FSMC_NORPSRAM4_div_HCLK_with_16()		FSMC_NORPSRAM4_set_CLKDIV(15)




/*
总线恢复时间 在总线复用时使用
Bits 19:16 BUSTURN: Bus turnaround phase duration . just active in mul mode
These bits are written by software to introduce the bus turnaround delay after a read access 
(only from multiplexed NOR Flash memory) to avoid bus contention if the controller needs to 
drive addresses on the databus for the next side-by-side transaction. BUSTURN can be set 
to the minimum if the memory system does not include multiplexed memories or if the 
slowest memory does not take more than 6 HCLK clock cycles to put the databus in Hi-Z 
state:
0000: BUSTURN phase duration = 1 × HCLK clock cycle
...
1111: BUSTURN phase duration = 16 × HCLK clock cycles (default value after reset)
*/
void FSMC_NORPSRAM1_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM2_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM3_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM4_set_BUSTURN(U8 sel);

//sel = 1 -16
#define FSMC_NORPSRAM1_set_turnaround_phase(sel)	FSMC_NORPSRAM1_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM2_set_turnaround_phase(sel)	FSMC_NORPSRAM2_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM3_set_turnaround_phase(sel)	FSMC_NORPSRAM3_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM4_set_turnaround_phase(sel)	FSMC_NORPSRAM4_set_BUSTURN(sel-1)

//NORPRAM存储块1的总线恢复时间
#define	FSMC_NORPSRAM1_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(0)
#define	FSMC_NORPSRAM1_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(1)
#define	FSMC_NORPSRAM1_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(2)
#define	FSMC_NORPSRAM1_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(3)
#define	FSMC_NORPSRAM1_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(4)
#define	FSMC_NORPSRAM1_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(5)
#define	FSMC_NORPSRAM1_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(6)
#define	FSMC_NORPSRAM1_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(7)
#define	FSMC_NORPSRAM1_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(8)
#define	FSMC_NORPSRAM1_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(9)
#define	FSMC_NORPSRAM1_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(10)
#define	FSMC_NORPSRAM1_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(11)
#define	FSMC_NORPSRAM1_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(12)
#define	FSMC_NORPSRAM1_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(13)
#define	FSMC_NORPSRAM1_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(14)
#define	FSMC_NORPSRAM1_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(15)


//NORPRAM存储块2的总线恢复时间
#define	FSMC_NORPSRAM2_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(0)
#define	FSMC_NORPSRAM2_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(1)
#define	FSMC_NORPSRAM2_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(2)
#define	FSMC_NORPSRAM2_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(3)
#define	FSMC_NORPSRAM2_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(4)
#define	FSMC_NORPSRAM2_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(5)
#define	FSMC_NORPSRAM2_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(6)
#define	FSMC_NORPSRAM2_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(7)
#define	FSMC_NORPSRAM2_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(8)
#define	FSMC_NORPSRAM2_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(9)
#define	FSMC_NORPSRAM2_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(10)
#define	FSMC_NORPSRAM2_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(11)
#define	FSMC_NORPSRAM2_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(12)
#define	FSMC_NORPSRAM2_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(13)
#define	FSMC_NORPSRAM2_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(14)
#define	FSMC_NORPSRAM2_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(15)


//NORPRAM存储块3的总线恢复时间
#define	FSMC_NORPSRAM3_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(0)
#define	FSMC_NORPSRAM3_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(1)
#define	FSMC_NORPSRAM3_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(2)
#define	FSMC_NORPSRAM3_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(3)
#define	FSMC_NORPSRAM3_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(4)
#define	FSMC_NORPSRAM3_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(5)
#define	FSMC_NORPSRAM3_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(6)
#define	FSMC_NORPSRAM3_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(7)
#define	FSMC_NORPSRAM3_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(8)
#define	FSMC_NORPSRAM3_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(9)
#define	FSMC_NORPSRAM3_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(10)
#define	FSMC_NORPSRAM3_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(11)
#define	FSMC_NORPSRAM3_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(12)
#define	FSMC_NORPSRAM3_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(13)
#define	FSMC_NORPSRAM3_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(14)
#define	FSMC_NORPSRAM3_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(15)


//NORPRAM存储块4的总线恢复时间
#define	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(0)
#define	FSMC_NORPSRAM4_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(1)
#define	FSMC_NORPSRAM4_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(2)
#define	FSMC_NORPSRAM4_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(3)
#define	FSMC_NORPSRAM4_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(4)
#define	FSMC_NORPSRAM4_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(5)
#define	FSMC_NORPSRAM4_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(6)
#define	FSMC_NORPSRAM4_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(7)
#define	FSMC_NORPSRAM4_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(8)
#define	FSMC_NORPSRAM4_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(9)
#define	FSMC_NORPSRAM4_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(10)
#define	FSMC_NORPSRAM4_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(11)
#define	FSMC_NORPSRAM4_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(12)
#define	FSMC_NORPSRAM4_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(13)
#define	FSMC_NORPSRAM4_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(14)
#define	FSMC_NORPSRAM4_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(15)

/*
数据保持时间
Bits 15:8 DATAST: Data-phase duration
These bits are written by software to define the duration of the data phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous multiplexed NOR Flash 
accesses:
0000 0000: Reserved
0000 0001: DATAST phase duration = 2 × HCLK clock cycles
0000 0010: DATAST phase duration = 3 × HCLK clock cycles
...
1111 1111: DATAST phase duration = 256 × HCLK clock cycles (default value after reset)
For each memory type and access mode data-phase duration, please refer to the respective 
figure (Figure 187 to Figure 198).
Example: Mode1, read access, DATAST=1: Data-phase duration= DATAST+3 = 4 HCLK 
clock cycles.
*/
void FSMC_NORPSRAM1_set_DATAST(U16 sel);
void FSMC_NORPSRAM2_set_DATAST(U16 sel);
void FSMC_NORPSRAM3_set_DATAST(U16 sel);
void FSMC_NORPSRAM4_set_DATAST(U16 sel);

//sel = 2 - 256
#define FSMC_NORPSRAM1_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM1_set_DATAST(sel-1)
#define FSMC_NORPSRAM2_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM2_set_DATAST(sel-1)
#define FSMC_NORPSRAM3_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM3_set_DATAST(sel-1)
#define FSMC_NORPSRAM4_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM4_set_DATAST(sel-1)


/*
地址保持时间
Bits 7:4 ADDHLD: Address-hold phase duration
These bits are written by software to define the duration of the address hold phase (refer to 
Figure 196 to Figure 198), used in mode D and multiplexed accesses:
0000: Reserved
0001: ADDHLD phase duration = 2 × HCLK clock cycle
0010: ADDHLD phase duration = 3 × HCLK clock cycle
...
1111: ADDHLD phase duration = 16 × HCLK clock cycles (default value after reset)
For  each access mode address-hold phase duration, please refer to the respective figure 
(Figure 196 to Figure 198).
Example: ModeD, read access, ADDHLD=1: Address-hold phase duration = ADDHLD + 1 =2 
HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM2_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM3_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM4_set_ADDHLD(U8 hld);

//hld = 2-16
#define FSMC_NORPSRAM1_set_address_hold_phase_duration(hld) FSMC_NORPSRAM1_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM2_set_address_hold_phase_duration(hld) FSMC_NORPSRAM2_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM3_set_address_hold_phase_duration(hld) FSMC_NORPSRAM3_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM4_set_address_hold_phase_duration(hld) FSMC_NORPSRAM4_set_ADDHLD(hld-1)

//NORPRAM存储块1地址保持时间 
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(1)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(2)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(3)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(4)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(5)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(6)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(7)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(8)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(9)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(10)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(11)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(12)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(13)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(14)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(15)

//NORPRAM存储块2地址保持时间 
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(1)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(2)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(3)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(4)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(5)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(6)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(7)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(8)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(9)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(10)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(11)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(12)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(13)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(14)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(15)

//NORPRAM存储块3地址保持时间 
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(1)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(2)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(3)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(4)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(5)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(6)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(7)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(8)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(9)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(10)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(11)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(12)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(13)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(14)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(15)


//NORPRAM存储块4地址保持时间 
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(1)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(2)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(3)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(4)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(5)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(6)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(7)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(8)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(9)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(10)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(11)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(12)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(13)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(14)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(15)



/*
地址建立时间
Bits 3:0 ADDSET: Address setup phase duration
These bits are written by software to define the duration of the address setup phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous NOR Flash:
0000: ADDSET phase duration = 1 × HCLK clock cycle
...
1111: ADDSET phase duration = 16 × HCLK clock cycles (default value after reset)
For each access mode address setup phase duration, please refer to the respective figure 
(refer to Figure 187 to Figure 198).
Example: Mode2, read access, ADDSET=1: Address setup phase duration = ADDSET + 1 = 
2 HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_set_ADDSET(U8 st);
void FSMC_NORPSRAM2_set_ADDSET(U8 st);
void FSMC_NORPSRAM3_set_ADDSET(U8 st);
void FSMC_NORPSRAM4_set_ADDSET(U8 st);

//st = 1- 16
#define FSMC_NORPSRAM1_set_address_setup_phase_duration(st)	FSMC_NORPSRAM1_set_ADDSET(st - 1)
#define FSMC_NORPSRAM2_set_address_setup_phase_duration(st)	FSMC_NORPSRAM2_set_ADDSET(st - 1)
#define FSMC_NORPSRAM3_set_address_setup_phase_duration(st)	FSMC_NORPSRAM3_set_ADDSET(st - 1)
#define FSMC_NORPSRAM4_set_address_setup_phase_duration(st)	FSMC_NORPSRAM4_set_ADDSET(st - 1)

//存储块1地址建立时间
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM1_set_ADDSET(0)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM1_set_ADDSET(1)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM1_set_ADDSET(2)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM1_set_ADDSET(3)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM1_set_ADDSET(4)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM1_set_ADDSET(5)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM1_set_ADDSET(6)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM1_set_ADDSET(7)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM1_set_ADDSET(8)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM1_set_ADDSET(9)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM1_set_ADDSET(10)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM1_set_ADDSET(11)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM1_set_ADDSET(12)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM1_set_ADDSET(13)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM1_set_ADDSET(14)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM1_set_ADDSET(15)

//存储块2地址建立时间
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM2_set_ADDSET(0)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM2_set_ADDSET(1)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM2_set_ADDSET(2)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM2_set_ADDSET(3)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM2_set_ADDSET(4)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM2_set_ADDSET(5)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM2_set_ADDSET(6)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM2_set_ADDSET(7)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM2_set_ADDSET(8)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM2_set_ADDSET(9)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM2_set_ADDSET(10)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM2_set_ADDSET(11)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM2_set_ADDSET(12)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM2_set_ADDSET(13)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM2_set_ADDSET(14)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM2_set_ADDSET(15)

//存储块3地址建立时间
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM3_set_ADDSET(0)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM3_set_ADDSET(1)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM3_set_ADDSET(2)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM3_set_ADDSET(3)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM3_set_ADDSET(4)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM3_set_ADDSET(5)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM3_set_ADDSET(6)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM3_set_ADDSET(7)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM3_set_ADDSET(8)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM3_set_ADDSET(9)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM3_set_ADDSET(10)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM3_set_ADDSET(11)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM3_set_ADDSET(12)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM3_set_ADDSET(13)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM3_set_ADDSET(14)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM3_set_ADDSET(15)

//存储块4地址建立时间
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM4_set_ADDSET(0)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM4_set_ADDSET(1)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM4_set_ADDSET(2)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM4_set_ADDSET(3)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM4_set_ADDSET(4)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM4_set_ADDSET(5)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM4_set_ADDSET(6)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM4_set_ADDSET(7)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM4_set_ADDSET(8)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM4_set_ADDSET(9)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM4_set_ADDSET(10)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM4_set_ADDSET(11)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM4_set_ADDSET(12)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM4_set_ADDSET(13)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM4_set_ADDSET(14)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM4_set_ADDSET(15)



//*********SRAM/NOR-Flash write timing registers 1..4 (FSMC_BWTR1..4)**********//
/*
写时序控制
Address offset: 0xA000 0000 + 0x104 + 8 * (x – 1), x = 1...4
Reset value: 0x0FFF FFFF
This register contains the control information of each memory bank, used for SRAMs, ROMs 
and NOR Flash memories. When the EXTMOD bit is set in the FSMC_BCRx register, then 
this register is active for write access.
*/
/*
访问模式
Bits 29:28 ACCMOD: Access mode
Specifies the asynchronous access modes as shown in the timing diagrams. These bits are 
taken into account only when the EXTMOD bit in the FSMC_BCRx register is 1.
00: access mode A
01: access mode B
10: access mode C
11: access mode D
*/
void FSMC_NORPSRAM1_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM2_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM3_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM4_W_set_ACCMOD(U8 mod);


//选择模式A
#define FSMC_NORPSRAM1_access_mode_A_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(0)
#define FSMC_NORPSRAM2_access_mode_A_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(0)
#define FSMC_NORPSRAM3_access_mode_A_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(0)
#define FSMC_NORPSRAM4_access_mode_A_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(0)

//选择模式B
#define FSMC_NORPSRAM1_access_mode_B_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(1)
#define FSMC_NORPSRAM2_access_mode_B_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(1)
#define FSMC_NORPSRAM3_access_mode_B_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(1)
#define FSMC_NORPSRAM4_access_mode_B_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(1)

//选择模式C
#define FSMC_NORPSRAM1_access_mode_C_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(2)
#define FSMC_NORPSRAM2_access_mode_C_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(2)
#define FSMC_NORPSRAM3_access_mode_C_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(2)
#define FSMC_NORPSRAM4_access_mode_C_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(2)

//选择模式D
#define FSMC_NORPSRAM1_access_mode_D_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(3)
#define FSMC_NORPSRAM2_access_mode_D_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(3)
#define FSMC_NORPSRAM3_access_mode_D_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(3)
#define FSMC_NORPSRAM4_access_mode_D_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(3)

/*
数据保持时间(成组模式下)
Bits 27:24 DATLAT (see note below bit descriptions): Data latency (for synchronous burst NOR Flash)
For NOR Flash with synchronous burst mode enabled, defines the number of memory clock 
cycles (+2) to issue to the memory before getting the first data:
This timing parameter is not expressed in HCLK periods, but in Flash clock (CLK) periods. In 
asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care. In case of 
CRAM, this field must be set to 0
0000: Data latency of 2 CLK clock cycles for first burst access
.......
1111: Data latency of 17 CLK clock cycles for first burst access (default value after reset)
*/
void FSMC_NORPSRAM1_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM2_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM3_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM4_W_set_DATLAT(U8 sel);


//t = 2 - 17
#define FSMC_NORPSRAM1_W_set_latency_when_write(t)	FSMC_NORPSRAM1_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM2_W_set_latency_when_write(t)	FSMC_NORPSRAM2_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM3_W_set_latency_when_write(t)	FSMC_NORPSRAM3_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM4_W_set_latency_when_write(t)	FSMC_NORPSRAM4_W_set_DATLAT(t-2)

//等待时间为2个CLK
#define FSMC_NORPSRAM1_latency_is_2_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(0)
#define FSMC_NORPSRAM2_latency_is_2_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(0)
#define FSMC_NORPSRAM3_latency_is_2_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(0)
#define FSMC_NORPSRAM4_latency_is_2_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(0)

//等待时间为3个CLK
#define FSMC_NORPSRAM1_latency_is_3_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(1)
#define FSMC_NORPSRAM4_latency_is_3_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(1)

//等待时间为4个CLK
#define FSMC_NORPSRAM1_latency_is_4_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(2)
#define FSMC_NORPSRAM2_latency_is_4_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(2)
#define FSMC_NORPSRAM3_latency_is_4_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(2)
#define FSMC_NORPSRAM4_latency_is_4_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(2)

//等待时间为5个CLK
#define FSMC_NORPSRAM1_latency_is_5_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(3)
#define FSMC_NORPSRAM2_latency_is_5_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(3)
#define FSMC_NORPSRAM3_latency_is_5_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(3)
#define FSMC_NORPSRAM4_latency_is_5_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(3)

//等待时间为6个CLK
#define FSMC_NORPSRAM1_latency_is_6_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(4)
#define FSMC_NORPSRAM2_latency_is_6_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(4)
#define FSMC_NORPSRAM3_latency_is_6_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(4)
#define FSMC_NORPSRAM4_latency_is_6_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(4)

//等待时间为7个CLK
#define FSMC_NORPSRAM1_latency_is_7_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(5)
#define FSMC_NORPSRAM2_latency_is_7_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(5)
#define FSMC_NORPSRAM3_latency_is_7_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(5)
#define FSMC_NORPSRAM4_latency_is_7_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(5)

//等待时间为8个CLK
#define FSMC_NORPSRAM1_latency_is_8_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(6)
#define FSMC_NORPSRAM2_latency_is_8_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(6)
#define FSMC_NORPSRAM3_latency_is_8_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(6)
#define FSMC_NORPSRAM4_latency_is_8_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(6)

//等待时间为9个CLK
#define FSMC_NORPSRAM1_latency_is_9_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(7)
#define FSMC_NORPSRAM2_latency_is_9_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(7)
#define FSMC_NORPSRAM3_latency_is_9_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(7)
#define FSMC_NORPSRAM4_latency_is_9_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(7)

//等待时间为10个CLK
#define FSMC_NORPSRAM1_latency_is_10_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(8)
#define FSMC_NORPSRAM2_latency_is_10_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(8)
#define FSMC_NORPSRAM3_latency_is_10_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(8)
#define FSMC_NORPSRAM4_latency_is_10_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(8)

//等待时间为11个CLK
#define FSMC_NORPSRAM1_latency_is_11_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(9)
#define FSMC_NORPSRAM2_latency_is_11_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(9)
#define FSMC_NORPSRAM3_latency_is_11_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(9)
#define FSMC_NORPSRAM4_latency_is_11_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(9)

//等待时间为12个CLK
#define FSMC_NORPSRAM1_latency_is_12_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(10)
#define FSMC_NORPSRAM2_latency_is_12_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(10)
#define FSMC_NORPSRAM3_latency_is_12_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(10)
#define FSMC_NORPSRAM4_latency_is_12_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(10)

//等待时间为13个CLK
#define FSMC_NORPSRAM1_latency_is_13_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(11)
#define FSMC_NORPSRAM2_latency_is_13_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(11)
#define FSMC_NORPSRAM3_latency_is_13_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(11)
#define FSMC_NORPSRAM4_latency_is_13_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(11)

//等待时间为14个CLK
#define FSMC_NORPSRAM1_latency_is_14_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(12)
#define FSMC_NORPSRAM2_latency_is_14_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(12)
#define FSMC_NORPSRAM3_latency_is_14_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(12)
#define FSMC_NORPSRAM4_latency_is_14_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(12)

//等待时间为15个CLK
#define FSMC_NORPSRAM1_latency_is_15_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(13)
#define FSMC_NORPSRAM2_latency_is_15_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(13)
#define FSMC_NORPSRAM3_latency_is_15_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(13)
#define FSMC_NORPSRAM4_latency_is_15_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(13)

//等待时间为16个CLK
#define FSMC_NORPSRAM1_latency_is_16_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(14)
#define FSMC_NORPSRAM2_latency_is_16_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(14)
#define FSMC_NORPSRAM3_latency_is_16_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(14)
#define FSMC_NORPSRAM4_latency_is_16_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(14)

//等待时间为17个CLK
#define FSMC_NORPSRAM1_latency_is_17_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(15)
#define FSMC_NORPSRAM2_latency_is_17_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(15)
#define FSMC_NORPSRAM3_latency_is_17_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(15)
#define FSMC_NORPSRAM4_latency_is_17_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(15)

/*
同步模式输出时钟分频 （HCLK分频）
Bits 23:20 CLKDIV: Clock divide ratio (for CLK signal)
Defines the period of CLK clock output signal, expressed in number of HCLK cycles:
0000: Reserved
0001: CLK period = 2 × HCLK periods
0010: CLK period = 3 × HCLK periods
1111: CLK period = 16 × HCLK periods (default value after reset) 
In asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care.
*/
void FSMC_NORPSRAM1_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM2_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM3_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM4_W_set_CLKDIV(U8 div);


//div = 2 - 16
#define FSMC_NORPSRAM1_set_div_when_write(div)	FSMC_NORPSRAM1_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM2_set_div_when_write(div)	FSMC_NORPSRAM2_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM3_set_div_when_write(div)	FSMC_NORPSRAM3_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM4_set_div_when_write(div)	FSMC_NORPSRAM4_W_set_CLKDIV(div - 1)

//对NOR_PRAM存储块1的时钟分频
#define FSMC_NORPSRAM1_div_HCLK_with_2_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(1)
#define FSMC_NORPSRAM1_div_HCLK_with_3_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(2)
#define FSMC_NORPSRAM1_div_HCLK_with_4_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(3)
#define FSMC_NORPSRAM1_div_HCLK_with_5_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(4)
#define FSMC_NORPSRAM1_div_HCLK_with_6_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(5)
#define FSMC_NORPSRAM1_div_HCLK_with_7_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(6)
#define FSMC_NORPSRAM1_div_HCLK_with_8_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(7)
#define FSMC_NORPSRAM1_div_HCLK_with_9_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(8)
#define FSMC_NORPSRAM1_div_HCLK_with_10_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(9)
#define FSMC_NORPSRAM1_div_HCLK_with_11_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(10)
#define FSMC_NORPSRAM1_div_HCLK_with_12_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(11)
#define FSMC_NORPSRAM1_div_HCLK_with_13_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(12)
#define FSMC_NORPSRAM1_div_HCLK_with_14_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(13)
#define FSMC_NORPSRAM1_div_HCLK_with_15_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(14)
#define FSMC_NORPSRAM1_div_HCLK_with_16_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(15)

//对NOR_PRAM存储块2的时钟分频
#define FSMC_NORPSRAM2_div_HCLK_with_2_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(1)
#define FSMC_NORPSRAM2_div_HCLK_with_3_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(2)
#define FSMC_NORPSRAM2_div_HCLK_with_4_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(3)
#define FSMC_NORPSRAM2_div_HCLK_with_5_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(4)
#define FSMC_NORPSRAM2_div_HCLK_with_6_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(5)
#define FSMC_NORPSRAM2_div_HCLK_with_7_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(6)
#define FSMC_NORPSRAM2_div_HCLK_with_8_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(7)
#define FSMC_NORPSRAM2_div_HCLK_with_9_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(8)
#define FSMC_NORPSRAM2_div_HCLK_with_10_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(9)
#define FSMC_NORPSRAM2_div_HCLK_with_11_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(10)
#define FSMC_NORPSRAM2_div_HCLK_with_12_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(11)
#define FSMC_NORPSRAM2_div_HCLK_with_13_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(12)
#define FSMC_NORPSRAM2_div_HCLK_with_14_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(13)
#define FSMC_NORPSRAM2_div_HCLK_with_15_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(14)
#define FSMC_NORPSRAM2_div_HCLK_with_16_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(15)

//对NOR_PRAM存储块3的时钟分频
#define FSMC_NORPSRAM3_div_HCLK_with_2_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(1)
#define FSMC_NORPSRAM3_div_HCLK_with_3_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(2)
#define FSMC_NORPSRAM3_div_HCLK_with_4_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(3)
#define FSMC_NORPSRAM3_div_HCLK_with_5_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(4)
#define FSMC_NORPSRAM3_div_HCLK_with_6_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(5)
#define FSMC_NORPSRAM3_div_HCLK_with_7_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(6)
#define FSMC_NORPSRAM3_div_HCLK_with_8_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(7)
#define FSMC_NORPSRAM3_div_HCLK_with_9_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(8)
#define FSMC_NORPSRAM3_div_HCLK_with_10_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(9)
#define FSMC_NORPSRAM3_div_HCLK_with_11_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(10)
#define FSMC_NORPSRAM3_div_HCLK_with_12_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(11)
#define FSMC_NORPSRAM3_div_HCLK_with_13_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(12)
#define FSMC_NORPSRAM3_div_HCLK_with_14_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(13)
#define FSMC_NORPSRAM3_div_HCLK_with_15_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(14)
#define FSMC_NORPSRAM3_div_HCLK_with_16_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(15)

//对NOR_PRAM存储块4的时钟分频
#define FSMC_NORPSRAM4_div_HCLK_with_2_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(1)
#define FSMC_NORPSRAM4_div_HCLK_with_3_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(2)
#define FSMC_NORPSRAM4_div_HCLK_with_4_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(3)
#define FSMC_NORPSRAM4_div_HCLK_with_5_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(4)
#define FSMC_NORPSRAM4_div_HCLK_with_6_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(5)
#define FSMC_NORPSRAM4_div_HCLK_with_7_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(6)
#define FSMC_NORPSRAM4_div_HCLK_with_8_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(7)
#define FSMC_NORPSRAM4_div_HCLK_with_9_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(8)
#define FSMC_NORPSRAM4_div_HCLK_with_10_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(9)
#define FSMC_NORPSRAM4_div_HCLK_with_11_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(10)
#define FSMC_NORPSRAM4_div_HCLK_with_12_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(11)
#define FSMC_NORPSRAM4_div_HCLK_with_13_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(12)
#define FSMC_NORPSRAM4_div_HCLK_with_14_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(13)
#define FSMC_NORPSRAM4_div_HCLK_with_15_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(14)
#define FSMC_NORPSRAM4_div_HCLK_with_16_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(15)


/*
总线恢复时间 在总线复用时使用
Bits 19:16 BUSTURN: Bus turnaround phase duration . just active in mul mode
These bits are written by software to introduce the bus turnaround delay after a read access 
(only from multiplexed NOR Flash memory) to avoid bus contention if the controller needs to 
drive addresses on the databus for the next side-by-side transaction. BUSTURN can be set 
to the minimum if the memory system does not include multiplexed memories or if the 
slowest memory does not take more than 6 HCLK clock cycles to put the databus in Hi-Z 
state:
0000: BUSTURN phase duration = 1 × HCLK clock cycle
...
1111: BUSTURN phase duration = 16 × HCLK clock cycles (default value after reset)
*/
void FSMC_NORPSRAM1_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM2_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM3_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM4_W_set_BUSTURN(U8 sel);

//sel = 1 -16
#define FSMC_NORPSRAM1_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM1_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM2_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM2_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM3_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM3_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM4_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM4_set_BUSTURN(sel-1)

//NORPRAM存储块1的总线恢复时间
#define	FSMC_NORPSRAM1_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(0)
#define	FSMC_NORPSRAM1_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(1)
#define	FSMC_NORPSRAM1_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(2)
#define	FSMC_NORPSRAM1_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(3)
#define	FSMC_NORPSRAM1_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(4)
#define	FSMC_NORPSRAM1_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(5)
#define	FSMC_NORPSRAM1_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(6)
#define	FSMC_NORPSRAM1_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(7)
#define	FSMC_NORPSRAM1_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(8)
#define	FSMC_NORPSRAM1_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(9)
#define	FSMC_NORPSRAM1_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(10)
#define	FSMC_NORPSRAM1_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(11)
#define	FSMC_NORPSRAM1_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(12)
#define	FSMC_NORPSRAM1_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(13)
#define	FSMC_NORPSRAM1_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(14)
#define	FSMC_NORPSRAM1_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(15)


//NORPRAM存储块2的总线恢复时间
#define	FSMC_NORPSRAM2_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(0)
#define	FSMC_NORPSRAM2_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(1)
#define	FSMC_NORPSRAM2_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(2)
#define	FSMC_NORPSRAM2_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(3)
#define	FSMC_NORPSRAM2_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(4)
#define	FSMC_NORPSRAM2_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(5)
#define	FSMC_NORPSRAM2_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(6)
#define	FSMC_NORPSRAM2_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(7)
#define	FSMC_NORPSRAM2_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(8)
#define	FSMC_NORPSRAM2_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(9)
#define	FSMC_NORPSRAM2_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(10)
#define	FSMC_NORPSRAM2_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(11)
#define	FSMC_NORPSRAM2_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(12)
#define	FSMC_NORPSRAM2_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(13)
#define	FSMC_NORPSRAM2_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(14)
#define	FSMC_NORPSRAM2_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(15)


//NORPRAM存储块3的总线恢复时间
#define	FSMC_NORPSRAM3_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(0)
#define	FSMC_NORPSRAM3_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(1)
#define	FSMC_NORPSRAM3_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(2)
#define	FSMC_NORPSRAM3_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(3)
#define	FSMC_NORPSRAM3_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(4)
#define	FSMC_NORPSRAM3_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(5)
#define	FSMC_NORPSRAM3_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(6)
#define	FSMC_NORPSRAM3_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(7)
#define	FSMC_NORPSRAM3_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(8)
#define	FSMC_NORPSRAM3_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(9)
#define	FSMC_NORPSRAM3_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(10)
#define	FSMC_NORPSRAM3_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(11)
#define	FSMC_NORPSRAM3_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(12)
#define	FSMC_NORPSRAM3_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(13)
#define	FSMC_NORPSRAM3_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(14)
#define	FSMC_NORPSRAM3_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(15)


//NORPRAM存储块4的总线恢复时间
#define	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(0)
#define	FSMC_NORPSRAM4_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(1)
#define	FSMC_NORPSRAM4_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(2)
#define	FSMC_NORPSRAM4_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(3)
#define	FSMC_NORPSRAM4_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(4)
#define	FSMC_NORPSRAM4_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(5)
#define	FSMC_NORPSRAM4_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(6)
#define	FSMC_NORPSRAM4_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(7)
#define	FSMC_NORPSRAM4_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(8)
#define	FSMC_NORPSRAM4_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(9)
#define	FSMC_NORPSRAM4_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(10)
#define	FSMC_NORPSRAM4_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(11)
#define	FSMC_NORPSRAM4_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(12)
#define	FSMC_NORPSRAM4_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(13)
#define	FSMC_NORPSRAM4_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(14)
#define	FSMC_NORPSRAM4_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(15)


/*
数据保持时间
Bits 15:8 DATAST: Data-phase duration
These bits are written by software to define the duration of the data phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous multiplexed NOR Flash 
accesses:
0000 0000: Reserved
0000 0001: DATAST phase duration = 2 × HCLK clock cycles
0000 0010: DATAST phase duration = 3 × HCLK clock cycles
...
1111 1111: DATAST phase duration = 256 × HCLK clock cycles (default value after reset)
For each memory type and access mode data-phase duration, please refer to the respective 
figure (Figure 187 to Figure 198).
Example: Mode1, read access, DATAST=1: Data-phase duration= DATAST+3 = 4 HCLK 
clock cycles.
*/
void FSMC_NORPSRAM1_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM2_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM3_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM4_W_set_DATAST(U8 sel);


//sel = 2 - 256
#define FSMC_NORPSRAM1_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM1_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM2_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM2_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM3_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM3_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM4_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM4_W_set_DATAST(sel-1)


/*
地址保持时间
Bits 7:4 ADDHLD: Address-hold phase duration
These bits are written by software to define the duration of the address hold phase (refer to 
Figure 196 to Figure 198), used in mode D and multiplexed accesses:
0000: Reserved
0001: ADDHLD phase duration = 2 × HCLK clock cycle
0010: ADDHLD phase duration = 3 × HCLK clock cycle
...
1111: ADDHLD phase duration = 16 × HCLK clock cycles (default value after reset)
For  each access mode address-hold phase duration, please refer to the respective figure 
(Figure 196 to Figure 198).
Example: ModeD, read access, ADDHLD=1: Address-hold phase duration = ADDHLD + 1 =2 
HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM2_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM3_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM4_W_set_ADDHLD(U8 hld);


//hld = 2-16
#define FSMC_NORPSRAM1_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM1_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM2_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM2_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM3_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM3_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM4_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM4_W_set_ADDHLD(hld-1)

//NORPRAM存储块1地址保持时间 
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(1)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(2)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(3)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(4)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(5)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(6)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(7)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(8)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(9)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(10)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(11)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(12)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(13)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(14)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(15)

//NORPRAM存储块2地址保持时间 
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(1)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(2)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(3)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(4)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(5)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(6)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(7)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(8)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(9)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(10)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(11)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(12)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(13)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(14)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(15)

//NORPRAM存储块3地址保持时间 
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(1)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(2)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(3)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(4)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(5)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(6)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(7)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(8)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(9)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(10)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(11)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(12)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(13)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(14)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(15)


//NORPRAM存储块4地址保持时间 
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(1)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(2)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(3)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(4)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(5)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(6)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(7)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(8)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(9)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(10)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(11)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(12)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(13)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(14)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(15)


/*
地址建立时间
Bits 3:0 ADDSET: Address setup phase duration
These bits are written by software to define the duration of the address setup phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous NOR Flash:
0000: ADDSET phase duration = 1 × HCLK clock cycle
...
1111: ADDSET phase duration = 16 × HCLK clock cycles (default value after reset)
For each access mode address setup phase duration, please refer to the respective figure 
(refer to Figure 187 to Figure 198).
Example: Mode2, read access, ADDSET=1: Address setup phase duration = ADDSET + 1 = 
2 HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM2_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM3_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM4_W_set_ADDSET(U8 st);


//st = 1- 16
#define FSMC_NORPSRAM1_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM1_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM2_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM2_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM3_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM3_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM4_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM4_W_set_ADDSET(st - 1)

//存储块1地址建立时间
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(0)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(1)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(2)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(3)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(4)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(5)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(6)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(7)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(8)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(9)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(10)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(11)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(12)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(13)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(14)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(15)

//存储块2地址建立时间
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(0)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(1)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(2)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(3)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(4)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(5)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(6)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(7)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(8)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(9)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(10)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(11)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(12)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(13)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(14)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(15)

//存储块3地址建立时间
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(0)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(1)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(2)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(3)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(4)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(5)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(6)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(7)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(8)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(9)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(10)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(11)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(12)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(13)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(14)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(15)

//存储块4地址建立时间
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(0)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(1)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(2)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(3)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(4)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(5)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(6)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(7)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(8)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(9)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(10)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(11)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(12)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(13)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(14)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(15)

#endif



#ifndef __GPIO
#define	__GPIO


#include "com.h"


//类型定义
//定义端口
typedef enum
{
	GPIO_A = 0, 
	GPIO_B, 
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G 
}GPIO_PORT;

typedef enum
{
	PIN_1 = 1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
}GPIO_PIN;

typedef struct
{
	GPIO_PORT port;
	GPIO_PIN	pin;
}GPIO;


//GPIOA 寄存器
#define __GPIOA_CRL		(GPIOA_BASE + 0x00000000)
#define __GPIOA_CRH		(GPIOA_BASE + 0x00000004)
#define __GPIOA_IDR		(GPIOA_BASE + 0x00000008)
#define __GPIOA_ODR		(GPIOA_BASE + 0x0000000C)
#define __GPIOA_BSRR 	(GPIOA_BASE + 0x00000010)
#define __GPIOA_BRR		(GPIOA_BASE + 0x00000014)
#define __GPIOA_LCKR	(GPIOA_BASE + 0x00000018)

//GPIOB 寄存器
#define __GPIOB_CRL		(GPIOB_BASE + 0x00000000)
#define __GPIOB_CRH		(GPIOB_BASE + 0x00000004)
#define __GPIOB_IDR		(GPIOB_BASE + 0x00000008)
#define __GPIOB_ODR		(GPIOB_BASE + 0x0000000C)
#define __GPIOB_BSRR 	(GPIOB_BASE + 0x00000010)
#define __GPIOB_BRR		(GPIOB_BASE + 0x00000014)
#define __GPIOB_LCKR	(GPIOB_BASE + 0x00000018)

//GPIOC 寄存器
#define __GPIOC_CRL		(GPIOC_BASE + 0x00000000)
#define __GPIOC_CRH		(GPIOC_BASE + 0x00000004)
#define __GPIOC_IDR		(GPIOC_BASE + 0x00000008)
#define __GPIOC_ODR		(GPIOC_BASE + 0x0000000C)
#define __GPIOC_BSRR 	(GPIOC_BASE + 0x00000010)
#define __GPIOC_BRR		(GPIOC_BASE + 0x00000014)
#define __GPIOC_LCKR	(GPIOC_BASE + 0x00000018)

//GPIOD 寄存器
#define __GPIOD_CRL		(GPIOD_BASE + 0x00000000)
#define __GPIOD_CRH		(GPIOD_BASE + 0x00000004)
#define __GPIOD_IDR		(GPIOD_BASE + 0x00000008)
#define __GPIOD_ODR		(GPIOD_BASE + 0x0000000C)
#define __GPIOD_BSRR 	(GPIOD_BASE + 0x00000010)
#define __GPIOD_BRR		(GPIOD_BASE + 0x00000014)
#define __GPIOD_LCKR	(GPIOD_BASE + 0x00000018)

//GPIOE 寄存器
#define __GPIOE_CRL		(GPIOE_BASE + 0x00000000)
#define __GPIOE_CRH		(GPIOE_BASE + 0x00000004)
#define __GPIOE_IDR		(GPIOE_BASE + 0x00000008)
#define __GPIOE_ODR		(GPIOE_BASE + 0x0000000C)
#define __GPIOE_BSRR 	(GPIOE_BASE + 0x00000010)
#define __GPIOE_BRR		(GPIOE_BASE + 0x00000014)
#define __GPIOE_LCKR	(GPIOE_BASE + 0x00000018)

//GPIOF 寄存器
#define __GPIOF_CRL		(GPIOF_BASE + 0x00000000)
#define __GPIOF_CRH		(GPIOF_BASE + 0x00000004)
#define __GPIOF_IDR		(GPIOF_BASE + 0x00000008)
#define __GPIOF_ODR		(GPIOF_BASE + 0x0000000C)
#define __GPIOF_BSRR 	(GPIOF_BASE + 0x00000010)
#define __GPIOF_BRR		(GPIOF_BASE + 0x00000014)
#define __GPIOF_LCKR	(GPIOF_BASE + 0x00000018)

//GPIOF 寄存器
#define __GPIOG_CRL		(GPIOG_BASE + 0x00000000)
#define __GPIOG_CRH		(GPIOG_BASE + 0x00000004)
#define __GPIOG_IDR		(GPIOG_BASE + 0x00000008)
#define __GPIOG_ODR		(GPIOG_BASE + 0x0000000C)
#define __GPIOG_BSRR 	(GPIOG_BASE + 0x00000010)
#define __GPIOG_BRR		(GPIOG_BASE + 0x00000014)
#define __GPIOG_LCKR	(GPIOG_BASE + 0x00000018)


#define GPIOx_CR(GPIO_port, GPIO_pin)	(__GPIOA_CRL + (GPIOB_BASE - GPIOA_BASE) * GPIO_port + ((GPIO_pin >> 3) <<2))
#define GPIOx_CRH(GPIO_port) 			(__GPIOA_CRH + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)
#define GPIOx_CRL(GPIO_port)			(__GPIOA_CRL + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)

#define GPIOx_IDR(GPIO_port)			(__GPIOA_IDR + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)
#define GPIOx_ODR(GPIO_port)			(__GPIOA_ODR + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)
#define GPIOx_BSRR(GPIO_port)			(__GPIOA_BSRR +(GPIOB_BASE - GPIOA_BASE) * GPIO_port)
#define GPIOx_BRR(GPIO_port)			(__GPIOA_BRR + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)
#define GPIOx_LCKR(GPIO_port)			(__GPIOA_LCKR + (GPIOB_BASE - GPIOA_BASE) * GPIO_port)	

//模式
#define GPIO_INPUT			0x00		//输入模式
#define GPIO_OUTPUT_10		0x01		//输出模式10MHZ
#define GPIO_OUTPUT_2		0x02		//输出模式2MHZ
#define GPIO_OUTPUT_50		0x03		//输出模式50MHZ 

//输入配置
#define GPIO_INPUT_ANA			0x00		//模拟输入
#define GPIO_INPUT_FLT			0x01		//浮空输入
#define GPIO_INPUT_PP 			0x02		//上下拉输入
#define GPIO_INPUT_KEEP 		0x03		//保留

//输出配置 
#define GPIO_OUTPUT_PUSHPULL 	0x00		//推挽输出
#define GPIO_OUTPUT_OD			0x01		//开漏输出
#define GPIO_OUTPUT_PUSHPULL_MUL		0x02		//复用推挽输出模式
#define GPIO_OUTPUT_OD_MUL		0x03		//复用开漏输出模式	

/*
	模式配置
	配置GPIO_port端口的GPIO_pin脚为模式configure.
	参数: 	GPIO_port: 	被配置的端口(ABCDEFG)
			GPIO_pin:	被配置端口的引脚(0-15)
			configure:	根据mode的值不同而不同 取 
		MODE = 00  
			输入模式						
			0: 模拟输入模式
			1: 浮空输入模式
			2: 上下拉模式
			3: 保留
		MODE = 1， 2, 3  
			输出模式，分别为10MHZ, 2MHZ, 50MHZ的驱动电路响应速度
			0: 通用推挽输出模式
			1: 通用开口输出模式
			2: 复用功能推挽输出模式
			3: 复用功能开漏输出模式
*/
void GPIO_configure(GPIO_PORT GPIO_port, U8 GPIO_pin, U8 mode, U32 configure);

//输出模式配置
//配置为输出模式的2, 10, 50MHZ输出 推挽输出
#define GPIO_set_output_2MHZ_PP(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_PUSHPULL)		
#define GPIO_set_output_10MHZ_PP(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_PUSHPULL)	
#define GPIO_set_output_50MHZ_PP(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_PUSHPULL)

//配置为输出模式的2, 10, 50MHZ输出 开漏输出
#define GPIO_set_output_2MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_OD)		
#define GPIO_set_output_10MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_OD)	
#define GPIO_set_output_50MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_OD)

//配置为输出模式的2, 10, 50MHZ输出 复用推挽输出
#define GPIO_set_output_2MHZ_PP_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_PUSHPULL_MUL)		
#define GPIO_set_output_10MHZ_PP_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_PUSHPULL_MUL)	
#define GPIO_set_output_50MHZ_PP_MUL(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_PUSHPULL_MUL)

//配置为输出模式的2, 10, 50MHZ输出 复用开漏输出
#define GPIO_set_output_2MHZ_OD_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_OD_MUL)		
#define GPIO_set_output_10MHZ_OD_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_OD_MUL)	
#define GPIO_set_output_50MHZ_OD_MUL(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_OD_MUL)

//输入模式配置
#define GPIO_set_input_ANA(port , pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_ANA)	//模拟输入
#define GPIO_set_input_FLT(port , pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_FLT)	//浮空输入
#define GPIO_set_input_PP(port, pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_PP)	//上下拉输入

	
/*
	为端口输出
*/
void GPIO_send_port(GPIO_PORT GPIO_port, U16 data);


/*
	为引脚输出
*/
 void GPIO_send_pin(GPIO_PORT GPIO_port, U8 GPIO_pin, U16 data);


/*
	获取端口输入
*/
U16  GPIO_receive_port(GPIO_PORT GPIO_port);

#define GPIO_read_port(p)	GPIO_receive_port(p)


/*
	获取引脚输入
*/
U8   GPIO_receive_pin(GPIO_PORT GPIO_port, U8 GPIO_pin);

#define GPIO_read_pin(port, pin) GPIO_receive_pin(port, pin)

#endif


/*
	base_gtime.h文档说明:
		此文档定义了对计数器2到计数器5的寄存器的定义
		以及对这些寄存器配置的所有动作
*/

#ifndef __GTIME
#define __GTIME

#include "com.h"

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




#ifndef BASE_I2C
#define BASE_I2C


#include "com.h"

//*****************************************************//
//*****************I2C1寄存器定义**********************//
//*****************************************************//
#define __I2C1_CR1		(I2C1_BASE + 0x00)
#define __I2C1_CR2		(I2C1_BASE + 0x04)
#define __I2C1_OAR1		(I2C1_BASE + 0x08)
#define __I2C1_OAR2		(I2C1_BASE + 0x0C)
#define __I2C1_DR		(I2C1_BASE + 0x10)
#define __I2C1_SR1		(I2C1_BASE + 0x14)
#define __I2C1_SR2		(I2C1_BASE + 0x18)
#define __I2C1_CCR		(I2C1_BASE + 0x1C)
#define __I2C1_TRISE	(I2C1_BASE + 0x20)

#define _I2C1_CR1		ADR(__I2C1_CR1)	
#define _I2C1_CR2		ADR(__I2C1_CR2)		
#define _I2C1_OAR1		ADR(__I2C1_OAR1)		
#define _I2C1_OAR2		ADR(__I2C1_OAR2)
#define _I2C1_DR		ADR(__I2C1_DR)
#define _I2C1_SR1		ADR(__I2C1_SR1)
#define _I2C1_SR2		ADR(__I2C1_SR2)
#define _I2C1_CCR		ADR(__I2C1_CCR)
#define _I2C1_TRISE		ADR(__I2C1_TRISE)

#define I2C1_CR1		VAL(__I2C1_CR1)	
#define I2C1_CR2		VAL(__I2C1_CR2)		
#define I2C1_OAR1		VAL(__I2C1_OAR1)		
#define I2C1_OAR2		VAL(__I2C1_OAR2)
#define I2C1_DR			VAL(__I2C1_DR)
#define I2C1_SR1		VAL(__I2C1_SR1)
#define I2C1_SR2		VAL(__I2C1_SR2)
#define I2C1_CCR		VAL(__I2C1_CCR)
#define I2C1_TRISE		VAL(__I2C1_TRISE)

//*****************************************************//
//*****************I2C2寄存器定义**********************//
//*****************************************************//
#define __I2C2_CR1		(I2C2_BASE + 0x00)
#define __I2C2_CR2		(I2C2_BASE + 0x04)
#define __I2C2_OAR1		(I2C2_BASE + 0x08)
#define __I2C2_OAR2		(I2C2_BASE + 0x0C)
#define __I2C2_DR		(I2C2_BASE + 0x10)
#define __I2C2_SR1		(I2C2_BASE + 0x14)
#define __I2C2_SR2		(I2C2_BASE + 0x18)
#define __I2C2_CCR		(I2C2_BASE + 0x1C)
#define __I2C2_TRISE	(I2C2_BASE + 0x20)

#define _I2C2_CR1		ADR(__I2C2_CR1)	
#define _I2C2_CR2		ADR(__I2C2_CR2)		
#define _I2C2_OAR1		ADR(__I2C2_OAR1)		
#define _I2C2_OAR2		ADR(__I2C2_OAR2)
#define _I2C2_DR		ADR(__I2C2_DR)
#define _I2C2_SR1		ADR(__I2C2_SR1)
#define _I2C2_SR2		ADR(__I2C2_SR2)
#define _I2C2_CCR		ADR(__I2C2_CCR)
#define _I2C2_TRISE		ADR(__I2C2_TRISE)

#define I2C2_CR1		VAL(__I2C2_CR1)	
#define I2C2_CR2		VAL(__I2C2_CR2)		
#define I2C2_OAR1		VAL(__I2C2_OAR1)		
#define I2C2_OAR2		VAL(__I2C2_OAR2)
#define I2C2_DR			VAL(__I2C2_DR)
#define I2C2_SR1		VAL(__I2C2_SR1)
#define I2C2_SR2		VAL(__I2C2_SR2)
#define I2C2_CCR		VAL(__I2C2_CCR)
#define I2C2_TRISE		VAL(__I2C2_TRISE)


//*********************************************************************************//
//***************************Control register 1 (I2C_CR1)**************************//
//*********************************************************************************//

/*
Control register 1 (I2C_CR1)
Address offset: 0x00
Reset value: 0x0000
*/

/*
Bit 15 SWRST: Software reset
When set, the I2C is under reset state. Before resetting this bit, make sure the I2C lines are 
released and the bus is free.
0: I2C Peripheral not under reset
1: I2C Peripheral under reset state
Note: This bit can be used in case the BUSY bit is set to ‘1 when no stop condition has been 
detected on the bus.
*/
void I2C1_set_SWRST(U8 s);

#define I2C1_reset()	I2C1_set_SWRST(1)	

/*
Bit 14 Reserved, forced by hardware to 0. 
*/

/*
Bit 13 ALERT: SMBus alert
This bit is set and cleared by software, and cleared by hardware when PE=0.
0: Releases SMBA pin high. Alert Response Address Header followed by NACK.
1: Drives SMBA pin low. Alert Response Address Header followed by ACK.
*/


/*
Bit 12 PEC: Packet error checking
This bit is set and cleared by software, and cleared by hardware when PEC is transferred or 
by a START or Stop condition or when PE=0.
0: No PEC transfer
1: PEC transfer (in Tx or Rx mode)
Note: PEC calculation is corrupted by an arbitration loss.
*/


/*
Bit 11 POS: Acknowledge/PEC Position (for data reception)
This bit is set and cleared by software and cleared by hardware when PE=0.
0: ACK bit controls the (N)ACK of the current byte being received in the shift register. The 
PEC bit indicates that current byte in shift register is a PEC.
1: ACK bit controls the (N)ACK of the next byte which will be received in the shift register. 
The PEC bit indicates that the next byte in the shift register is a PEC
Note: The POS bit is used when the procedure for reception of 2 bytes (see Method 2: 
transfer sequence diagram for master receiver when N=2) is followed. It must be 
configured before data reception starts. In this case, to NACK the 2nd byte, the ACK bit 
must be cleared just after ADDR is cleared. 
*/


/*
Bit 10 ACK: Acknowledge enable
This bit is set and cleared by software and cleared by hardware when PE=0.
0: No acknowledge returned
1: Acknowledge returned after a byte is received (matched address or data)
*/
void I2C1_set_ACK(U8 a);

#define I2C1_enable_acknowledge()	I2C1_set_ACK(1)
#define I2C1_disable_acknowledge()	I2C1_set_ACK(0)

/*
Bit 9 STOP: Stop generation
The bit is set and cleared by software, cleared by hardware when a Stop condition is 
detected, set by hardware when a timeout error is detected.
In Master Mode:
0: No Stop generation.
1: Stop generation after the current byte transfer or after the current Start condition is sent.
In Slave mode:
0: No Stop generation.
1: Release the SCL and SDA lines after the current byte transfer. 
Note: When the STOP, START or PEC bit is set, the software must not perform any write 
access to I2C_CR1 before this bit is cleared by hardware. Otherwise there is a risk of 
setting a second STOP, START or PEC request.
*/
void I2C1_set_STOP(U8 s);

#define I2C1_generate_stop()	I2C1_set_STOP(1)	//对于主模式
#define I2C1_release_bus()		I2C1_set_STOP(1)	//对于从模式

/*
Bit 8 START: Start generation
This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
In Master Mode:
0: No Start generation
1: Repeated start generation
In Slave mode:
0: No Start generation
1: Start generation when the bus is free
*/
void I2C1_set_START(U8 s);

#define I2C1_generate_start()	I2C1_set_START(1)
/*
Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until 
it is reset by software.
0: Clock stretching enabled
1: Clock stretching disabled
*/


/*
Bit 6 ENGC: General call enable
0: General call disabled. Address 00h is NACKed.
1: General call enabled. Address 00h is ACKed.
*/


/*
Bit 5 ENPEC: PEC enable
0: PEC calculation disabled
1: PEC calculation enabled
*/



/*
Bit 4 ENARP: ARP enable
0: ARP disable
1: ARP enable
SMBus Device default address recognized if SMBTYPE=0
SMBus Host address recognized if SMBTYPE=1
*/

/*
Bit 3 SMBTYPE: SMBus type
0: SMBus Device
1: SMBus Host
*/

/*
Bit 2 Reserved, forced by hardware to 0. 
*/

/*
Bit 1 SMBUS: SMBus mode
0: I2C mode
1: SMBus mode
*/

/*
Bit 0 PE: Peripheral enable
0: Peripheral disable
1: Peripheral enable: the corresponding IOs are selected as alternate functions depending 
on SMBus bit.
Note: If this bit is reset while a communication is on going, the peripheral is disabled at the 
end of the current communication, when back to IDLE state. 
*/
void I2C1_set_PE(U8 p);
	
#define I2C1_enable_peripheral()	I2C1_set_PE(1)
#define I2C1_disable_peripheral()	I2C1_set_PE(0)

/*
All bit resets due to PE=0 occur at the end of the communication.
In master mode, this bit must not be reset before the end of the communication.
*/


//********************************************************************//
//**********************Control register 2 (I2C_CR2)******************//
//********************************************************************//
/*
Control register 2 (I2C_CR2)
Address offset: 0x04
Reset value: 0x0000
*/

/*Bits 15:13 Reserved, forced by hardware to 0.
*/

/*
Bit 12 LAST: DMA last transfer
0: Next DMA EOT is not the last transfer
1: Next DMA EOT is the last transfer
Note: This bit is used in master receiver mode to permit the generation of a NACK on the last 
received data.
*/


/*
Bit 11 DMAEN: DMA requests enable
0: DMA requests disabled
1: DMA request enabled when TxE=1 or RxNE =1
*/

/*
Bit 10 ITBUFEN: Buffer interrupt enable
0: TxE = 1 or RxNE = 1 does not generate any interrupt.
1:TxE = 1 or RxNE = 1 generates Event Interrupt (whatever the state of DMAEN)
*/
void I2C1_set_ITBUFEN(U8 i);

#define I2C1_enable_interrupt_at_buffer()	I2C1_set_ITBUFEN(1)
#define I2C1_disable_interrupt_at_buffer()	I2C1_set_ITBUFEN(0)

/*
Bit 9 ITEVTEN: Event interrupt enable
0: Event interrupt disabled
1: Event interrupt enabled
This interrupt is generated when:
–SB = 1 (Master)
–ADDR = 1 (Master/Slave)
–ADD10= 1 (Master)
–STOPF = 1 (Slave)
–BTF = 1 with no TxE or RxNE event
–TxE event to 1 if ITBUFEN = 1
–RxNE event to 1 if ITBUFEN = 1
*/
void I2C1_set_ITEVTEN(U8 i);

#define I2C1_enable_interrupt_at_event()	I2C1_set_ITEVTEN(1)
#define I2C1_disable_interrupt_at_event()	I2C1_set_ITEVTEN(0)

/*
Bit 8 ITERREN: Error interrupt enable
0: Error interrupt disabled
1: Error interrupt enabled
This interrupt is generated when:
–BERR = 1
–ARLO = 1
–AF = 1
–OVR = 1
–PECERR = 1
–TIMEOUT = 1
–SMBALERT = 1
*/
void I2C1_set_ITERREN(U8 i);

#define I2C1_enable_interrupt_ITERREN()		I2C1_set_ITERREN(1)
#define I2C1_disable_interrupt_ITERREN()	I2C1_set_ITERREN(0)

/*
Bits 7:6 Reserved, forced by hardware to 0.
*/

/*
Bits 5:0 FREQ[5:0]: Peripheral clock frequency
The peripheral clock frequency must be configured using the input APB clock frequency (I2C 
peripheral connected to APB). The minimum allowed frequency is 2 MHz, the maximum 
frequency is limited by the maximum APB frequency (36 MHz) and an intrinsic limitation of 
46 MHz.
0b000000: Not allowed
0b000001: Not allowed
0b000010: 2 MHz
...
0b100100: 36 MHz
Higher than 0b100100: Not allowed
*/
void I2C1_set_FREQ(U8 f);
	
#define I2C1_set_prequency_MHZ(m)	I2C1_set_FREQ(m)

//*********************************************************************//
//**********************Own address register 1 (I2C_OAR1)**************//
//*********************************************************************//

/*
Own address register 1 (I2C_OAR1)
Address offset: 0x08
Reset value: 0x0000
*/

/*
Bit 15 ADDMODE Addressing mode (slave mode)
0: 7-bit slave address (10-bit address not acknowledged)
1: 10-bit slave address (7-bit address not acknowledged)
*/
void I2C1_set_ADDMODE(U8 a);

#define I2C1_set_address_mode_7_bit()	I2C1_set_ADDMODE(0)
#define I2C1_set_address_mode_11_bit()	I2C1_set_ADDMODE(1)

/*
Bit 14
Should always be kept at 1 by software.
*/
void I2C1_set_bit14(void);

#define I2C1_set_neccessary()	I2C1_set_bit14()

/*
Bits 13:10 Reserved, forced by hardware to 0.
*/

/*
Bits 9:8 ADD[9:8]: Interface address
7-bit addressing mode: don’t care
10-bit addressing mode: bits9:8 of address
*/


/*
Bits 7:1 ADD[7:1]: Interface address
bits 7:1 of address
*/
void I2C1_set_ADD_7to1(U8 a);

#define I2C1_set_address_7to1(a)	I2C1_set_ADD_7to1(a)

/*
Bit 0 ADD0: Interface address
7-bit addressing mode: don’t care
10-bit addressing mode: bit 0 of address
*/
void I2C1_set_ADD0(U8 a);



//**********************************************************************//
//***********************Own address register 2 (I2C_OAR2)**************//
//**********************************************************************//

/*
Own address register 2 (I2C_OAR2)
Address offset: 0x0C
Reset value: 0x0000
*/
/*
Bits 15:8 Reserved, forced by hardware to 0.
*/

/*
Bits 7:1 ADD2[7:1]: Interface address
bits 7:1 of address in dual addressing mode
*/
void I2C1_set_ADD2(U8 a);

/*
Bit 0 ENDUAL: Dual addressing mode enable
0: Only OAR1 is recognized in 7-bit addressing mode
1: Both OAR1 and OAR2 are recognized in 7-bit addressing mode
*/
void I2C1_set_ENDUAL(U8 e);


//********************************************************************//
//************************Data register (I2C_DR)**********************//
//********************************************************************//

/*
Data register (I2C_DR)
Address offset: 0x10
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved, forced by hardware to 0.
*/

/*
Bits 7:0 DR[7:0] 8-bit data register
Byte received or to be transmitted to the bus.
–Transmitter mode: Byte transmission starts automatically when a byte is written in the DR 
register. A continuous transmit stream can be maintained if the next data to be transmitted 
is put in DR once the transmission is started (TxE=1)
–Receiver mode: Received byte is copied into DR (RxNE=1). A continuous transmit stream 
can be maintained if DR is read before the next data byte is received (RxNE=1).
Note: In slave mode, the address is not copied into DR.
Note: Write collision is not managed (DR can be written if TxE=0).
Note: If an ARLO event occurs on ACK pulse, the received byte is not copied into DR and so 
cannot be read.
*/
void I2C1_set_DR(U8 d);
U8	I2C1_get_DR(void);
void I2C1_set_address(U8 add, U8 send_read);

#define I2C1_send_data(d)		I2C1_set_DR(d)
#define I2C1_get_data()			I2C1_get_DR()

#define I2C1_send_address_send(add)			I2C1_set_address(add, 0)
#define I2C1_send_address_receive(add)	I2C1_set_address(add, 1)

//********************************************************************************//
//************************Status register 1 (I2C_SR1)*****************************//
//********************************************************************************//

/*
Status register 1 (I2C_SR1)
Address offset: 0x14
Reset value: 0x0000
*/

/*
Bit 15 SMBALERT: SMBus alert 
In SMBus host mode:
0: no SMBALERT
1: SMBALERT event occurred on pin
In SMBus slave mode:
0: no SMBALERT response address header
1: SMBALERT response address header to SMBALERT LOW received
– Cleared by software writing 0, or by hardware when PE=0.
*/

/*
Bit 14 TIMEOUT: Timeout or Tlow error 
0: No timeout error
1: SCL remained LOW for 25 ms (Timeout)
or
Master cumulative clock low extend time more than 10 ms (Tlow:mext)
or
Slave cumulative clock low extend time more than 25 ms (Tlow:sext)
– When set in slave mode: slave resets the communication and lines are released by hardware
– When set in master mode: Stop condition sent by hardware
– Cleared by software writing 0, or by hardware when PE=0.
Note: This functionality is available only in SMBus mode.
*/
U8 I2C1_get_TIMEOUT(void);


/*
Bit 13 Reserved, forced by hardware to 0.
*/

/*
Bit 12 PECERR: PEC Error in reception 
0: no PEC error: receiver returns ACK after PEC reception (if ACK=1)
1: PEC error: receiver returns NACK after PEC reception (whatever ACK)
–Cleared by software writing 0, or by hardware when PE=0.
*/


/*
Bit 11 OVR: Overrun/Underrun 
0: No overrun/underrun
1: Overrun or underrun 
–Set by hardware in slave mode when NOSTRETCH=1 and:
–In reception when a new byte is received (including ACK pulse) and the DR register has not 
been read yet. New received byte is lost.
–In transmission when a new byte should be sent and the DR register has not been written 
yet. The same byte is sent twice.
–Cleared by software writing 0, or by hardware when PE=0.
Note: If the DR write occurs very close to SCL rising edge, the sent data is unspecified and a 
hold timing error occurs
*/
U8 I2C1_get_OVR(void);
void I2C1_clear_OVR(void);

#define I2C1_get_overrun_flag()		I2C1_get_OVR()
#define I2C1_clear_overrun_flag()	I2C1_clear_OVR()

/*
Bit 10 AF: Acknowledge failure
0: No acknowledge failure
1: Acknowledge failure
–Set by hardware when no acknowledge is returned. 
–Cleared by software writing 0, or by hardware when PE=0.
*/
U8 I2C1_get_AF(void);
void I2C1_clear_AF(void);

#define I2C1_get_acknowledge_failure_flag()		I2C1_get_AF()
#define I2C1_clear_acknowledge_failure_flag()	I2C1_clear_AF()

/*
Bit 9 ARLO: Arbitration lost (master mode) 
0: No Arbitration Lost detected
1: Arbitration Lost detected
Set by hardware when the interface loses the arbitration of the bus to another master
–Cleared by software writing 0, or by hardware when PE=0.
After an ARLO event the interface switches back automatically to Slave mode (M/SL=0). 
Note: In SMBUS, the arbitration on the data in slave mode occurs only during the data phase, 
or the acknowledge transmission (not on the address acknowledge).
*/


/*
Bit 8 BERR: Bus error 
0: No misplaced Start or Stop condition
1: Misplaced Start or Stop condition
–Set by hardware when the interface detects a misplaced Start or Stop condition 
–Cleared by software writing 0, or by hardware when PE=0.
*/
U8 I2C1_get_BERR(void);
void I2C1_clear_BERR(void);


/*
Bit 7 TxE: Data register empty (transmitters) 
0: Data register not empty
1: Data register empty
–Set when DR is empty in transmission. TxE is not set during address phase.
–Cleared by software writing to the DR register or by hardware after a start or a stop 
condition or when PE=0.
TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
Note: TxE is not cleared by writing the first data being transmitted, or by writing data when 
BTF is set, as in both cases the data register is still empty.
*/
U8 I2C1_get_TxE(void);

#define I2C1_is_data_register_empty()			I2C1_get_TxE()
#define I2C1_get_data_register_empty_flag()		I2C1_get_TxE()

#define I2C1_is_data_sent()						I2C1_get_TxE()
/*
Bit 6 RxNE: Data register not empty (receivers)
0: Data register empty
1: Data register not empty
–Set when data register is not empty in receiver mode. RxNE is not set during address 
phase.
–Cleared by software reading or writing the DR register or by hardware when PE=0.
RxNE is not set in case of ARLO event.
Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
*/
U8 I2C1_get_RxNE(void);

#define I2C1_is_data_register_full()	I2C1_get_RxNE()
#define I2C1_get_data_register_full_flag()	I2C1_get_RxNE()

#define I2C1_is_data_received()			I2C1_get_RxNE()
/*
Bit 5 Reserved, forced by hardware to 0.
*/

/*
Bit 4 STOPF: Stop detection (slave mode) 
0: No Stop condition detected
1: Stop condition detected
–Set by hardware when a Stop condition is detected on the bus by the slave after an 
acknowledge (if ACK=1). 
–Cleared by software reading the SR1 register followed by a write in the CR1 register, or by 
hardware when PE=0
Note: The STOPF bit is not set after a NACK reception
*/
U8	I2C1_get_STOPF(void);

#define I2C1_get_stop_flag()	I2C1_get_STOPF()

/*
Bit 3 ADD10: 10-bit header sent (Master mode) 
0: No ADD10 event occurred.
1: Master has sent first address byte (header).
–Set by hardware when the master has sent the first byte in 10-bit address mode. 
–Cleared by software reading the SR1 register followed by a write in the DR register of the 
second address byte, or by hardware when PE=0.
Note: ADD10 bit is not set after a NACK reception
*/


/*
Bit 2 BTF: Byte transfer finished
0: Data byte transfer not done
1: Data byte transfer succeeded
–Set by hardware when NOSTRETCH=0 and: 
–In reception when a new byte is received (including ACK pulse) and DR has not been 
read yet (RxNE=1).
–In transmission when a new byte should be sent and DR has not been written yet 
(TxE=1). 
–Cleared by software reading SR1 followed by either a read or write in the DR register or 
by hardware after a start or a stop condition in transmission or when PE=0.
Note: The BTF bit is not set after a NACK reception
The BTF bit is not set if next byte to be transmitted is the PEC (TRA=1 in I2C_SR2 
register and PEC=1 in I2C_CR1 register)
*/
U8	I2C1_get_BTF(void);

#define I2C1_is_transfer_finish()			I2C1_get_BTF()
#define I2C1_get_transfer_finish_flag()		I2C1_get_BTF()

/*
Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
This bit is cleared by software reading SR1 register followed reading SR2, or by hardware 
when PE=0.
Address matched (Slave)
0: Address mismatched or not received.
1: Received address matched.
–Set by hardware as soon as the received slave address matched with the OAR registers 
content or a general call or a SMBus Device Default Address or SMBus Host or SMBus 
Alert is recognized. (when enabled depending on configuration).
Address sent (Master)
0: No end of address transmission
1: End of address transmission
–For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
–For 7-bit addressing, the bit is set after the ACK of the byte.
Note: ADDR is not set after a NACK reception
*/
U8 I2C1_get_ADDR(void);

#define I2C1_get_address_send_flag()	I2C1_get_ADDR()
#define I2C1_is_address_sent()			I2C1_get_ADDR()

/*
Bit 0 SB: Start bit (Master mode)
0: No Start condition
1: Start condition generated.
–Set when a Start condition generated.
–Cleared by software by reading the SR1 register followed by writing the DR register, or by 
hardware when PE=0
*/
U8 I2C1_get_SB(void);

#define I2C1_is_start_generated()	I2C1_get_SB()

//******************************************************************************//
//************************Status register 2 (I2C_SR2)***************************//
//******************************************************************************//

/*
Status register 2 (I2C_SR2)
Address offset: 0x18
Reset value:0x0000
*/

/*
Bits 15:8 PEC[7:0] Packet error checking register
This register contains the internal PEC when ENPEC=1. 
*/

/*
Bit 7 DUALF: Dual flag (Slave mode)
0: Received address matched with OAR1
1: Received address matched with OAR2
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 6 SMBHOST: SMBus host header (Slave mode)
0: No SMBus Host address
1: SMBus Host address received when SMBTYPE=1 and ENARP=1.
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 5 SMBDEFAULT: SMBus device default address (Slave mode) 
0: No SMBus Device Default address
1: SMBus Device Default address received when ENARP=1
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 4 GENCALL: General call address (Slave mode) 
0: No General Call
1: General Call Address received when ENGC=1
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 3 Reserved, forced by hardware to 0.
*/

/*
Bit 2 TRA: Transmitter/receiver
0: Data bytes received
1: Data bytes transmitted
This bit is set depending on the R/W bit of the address byte, at the end of total address 
phase.
It is also cleared by hardware after detection of Stop condition (STOPF=1), repeated Start 
condition, loss of bus arbitration (ARLO=1), or when PE=0.
*/
U8 I2C1_get_TRA(void);

#define I2C1_is_transmitter()	I2C1_get_TRA()		
#define I2C1_is_receiver()		(!I2C1_get_TRA())	

/*
Bit 1 BUSY: Bus busy
0: No communication on the bus
1: Communication ongoing on the bus
–Set by hardware on detection of SDA or SCL low 
–cleared by hardware on detection of a Stop condition. 
It indicates a communication in progress on the bus. This information is still updated when 
the interface is disabled (PE=0).
*/
U8 I2C1_get_BUSY(void);

#define I2C1_get_busy_flag()	I2C1_get_BUSY()
#define I2C1_is_busy()			I2C1_get_BUSY()

/*
Bit 0 MSL: Master/slave
0: Slave Mode
1: Master Mode
–Set by hardware as soon as the interface is in Master mode (SB=1). 
–Cleared by hardware after detecting a Stop condition on the bus or a loss of arbitration 
(ARLO=1), or by hardware when PE=0. 
*/
U8 I2C1_get_MSL(void);

#define I2C1_is_master()	I2C1_get_MSL()
#define I2C1_is_slaver()	(!I2C1_get_MSL())

//********************************************************************//
//********************Clock control register (I2C_CCR)****************//
//********************************************************************//

/*
Clock control register (I2C_CCR)
Address offset: 0x1C
Reset value: 0x0000
Note:
1FPCLK1 is the multiple of 10 MHz required to generate the Fast clock at 400 kHz.
2The CCR register must be configured only when the I2C is disabled (PE = 0).
*/

/*
Bit 15 F/S: I2C master mode selection 
0: Standard Mode I2C
1: Fast Mode I2C
*/
void I2C1_set_FS(U8 f);

#define I2C1_set_standard_mode()	I2C1_set_FS(0)
#define I2C1_set_fast_mode()		I2C1_set_FS(1)
/*
Bit 14 DUTY: Fast mode duty cycle 
0: Fast Mode tlow/thigh = 2
1: Fast Mode tlow/thigh = 16/9 (see CCR)
*/

/*
Bits 13:12 Reserved, forced by hardware to 0.
*/

/*
Bits 11:0 CCR[11:0]: 
Clock control register in Fast/Standard mode (Master mode) 
Controls the SCL clock in master mode.
Standard mode or SMBus:
Thigh = CCR * TPCLK1
Tlow = CCR * TPCLK1
Fast mode:
If DUTY = 0:
Thigh = CCR * TPCLK1
Tlow = 2 * CCR * TPCLK1
If DUTY = 1: (to reach 400 kHz)
Thigh = 9 * CCR * TPCLK1
Tlow = 16 * CCR * TPCLK1
For instance: in standard mode, to generate a 100 kHz SCL frequency: 
If FREQR = 08, TPCLK1 = 125 ns so CCR must be programmed with 0x28
(0x28 <=> 40d x 125 ns = 5000 ns.)
Note: 1. The minimum allowed value is 0x04, except in FAST DUTY mode where the 
minimum allowed value is 0x01
2. thigh = tr(SCL) + tw(SCLH). See device datasheet for the definitions of parameters
3. tlow = tf(SCL) + tw(SCLL). See device datasheet for the definitions of parameters
4. These timings are without filters.
5. The CCR register must be configured only when the I2C is disabled (PE = 0).
*/
void I2C1_set_CCR(U32 c);

#define I2C1_set_clock(c)	I2C1_set_CCR(c)


//*******************************************************************//
//********************TRISE register (I2C_TRISE)*********************//
//*******************************************************************//
/*
TRISE register (I2C_TRISE)
Address offset: 0x20
Reset value: 0x0002
*/

/*
Bits 5:0 TRISE[5:0]: Maximum rise time in Fast/Standard mode (Master mode)
These bits must be programmed with the maximum SCL rise time given in the I2C bus 
specification, incremented by 1.
For instance: in standard mode, the maximum allowed SCL rise time is 1000 ns.
If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns 
therefore the TRISE[5:0] bits must be programmed with 09h.
(1000 ns / 125 ns = 8 + 1)
The filter value can also be added to TRISE[5:0].
If the result is not an integer, TRISE[5:0] must be programmed with the integer part, in order 
to respect the tHIGH parameter.
Note: TRISE[5:0] must be configured only when the I2C is disabled (PE = 0).
*/
void I2C1_set_TRISE(U8 t);

#define I2C1_set_rise_time(t)	I2C1_set_TRISE(t)

#endif



/*
	为了对RTC的时钟源进行配置，暂时使用PWR模块的PWR_CR寄存器中的DBP位来控制是否可以读写备份区，该部分暂时基本空白。。。
*/


#ifndef __PWR
#define __PWR

#include "com.h"

#define __PWR_CR	(PWR_BASE + 0x00000000)


#define _PWR_CR		ADR(__PWR_CR)


#define PWR_CR		VAL(__PWR_CR)	



//*******************************PWR_CR**************************************//
/*
	DBP：取消后备区域的写保护  Domain Backup Protected
	位 8 
	在复位后，RTC和后备寄存器处于被保护状态以防意外写入。设置这位允许写入这些寄存器。 
	0：禁止写入RTC和后备寄存器 
	1：允许写入RTC和后备寄存器 
	注：如果RTC的时钟是HSE/128，该位必须保持为’1’。
*/
void PWR_set_DBP(U8 allow_forbid);

#define PWR_disable_domain_backup_protection() 	PWR_set_DBP(1)
#define PWR_enable_domain_backup_protection()	PWR_set_DBP(0)

#endif



#ifndef __RCC
#define __RCC


#include "com.h"


#define __RCC_CR		(RCC_BASE + 0x00000000)
#define __RCC_CFGR		(RCC_BASE + 0x00000004)
#define __RCC_CIR		(RCC_BASE + 0x00000008)
#define __RCC_APB2RSTR	(RCC_BASE + 0x0000000C)
#define __RCC_APB1RSTR	(RCC_BASE + 0x00000010)
#define __RCC_AHBENR	(RCC_BASE + 0x00000014)
#define __RCC_APB2ENR	(RCC_BASE + 0x00000018)
#define __RCC_APB1ENR	(RCC_BASE + 0x0000001C)
#define __RCC_BDCR		(RCC_BASE + 0x00000020)
#define __RCC_CSR		(RCC_BASE  + 0x00000024)

#define _RCC_CR			ADR(__RCC_CR)
#define _RCC_CFGR		ADR(__RCC_CFGR)		
#define _RCC_CIR		ADR(__RCC_CIR)		
#define _RCC_APB2RSTR	ADR(__RCC_APB2RSTR)	
#define _RCC_APB1RSTR	ADR(__RCC_APB1RSTR)	
#define _RCC_AHBENR		ADR(__RCC_AHBENR)
#define _RCC_APB2ENR	ADR(__RCC_APB2ENR)
#define _RCC_APB1ENR	ADR(__RCC_APB1ENR)
#define _RCC_BDCR		ADR(__RCC_BDCR)		
#define _RCC_CSR		ADR(__RCC_CSR)	

#define RCC_CR			VAL(__RCC_CR)
#define RCC_CFGR		VAL(__RCC_CFGR)		
#define RCC_CIR			VAL(__RCC_CIR)		
#define RCC_APB2RSTR	VAL(__RCC_APB2RSTR)	
#define RCC_APB1RSTR	VAL(__RCC_APB1RSTR)	
#define RCC_AHBENR		VAL(__RCC_AHBENR)
#define RCC_APB2ENR		VAL(__RCC_APB2ENR)
#define RCC_APB1ENR		VAL(__RCC_APB1ENR)
#define RCC_BDCR		VAL(__RCC_BDCR)		
#define RCC_CSR			VAL(__RCC_CSR)


/*************************************Clock control register (RCC_CR)************************/
/*
Bit 25 PLLRDY: PLL clock ready flag	 PLL倍频器是否稳定
Set by hardware to indicate that the PLL is locked.
0: PLL unlocked
1: PLL locked
*/
U8 RCC_get_PLLRDY(void);

#define RCC_is_PLL_ready()	RCC_get_PLLRDY()

/*
Bit 24 PLLON: PLL enable	 		 PLL倍频使能
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the 
PLL clock is used as system clock or is selected to become the system clock.
0: PLL OFF
1: PLL ON
*/
void RCC_set_PLLON(U8 e_d);
#define RCC_enable_PLL()	RCC_set_PLLON(1)
#define RCC_disable_PLL()	RCC_set_PLLON(0)


/*
Bit 19 CSSON: Clock security system enable	 时钟安全系统使能
Set and cleared by software to enable clock detector.
0: Clock detector OFF
1: Clock detector ON if external 4-16 MHz oscillator is ready.
*/
void RCC_set_CSSON(U8 e_d);
#define RCC_enable_CSS()	RCC_set_CSSON(1)
#define RCC_disable_CSS()	RCC_set_CSSON(0)

/*
Bit 18 HSEBYP: External high-speed clock bypass	 HSE旁路
Set and cleared by software for bypassing the oscillator with an external clock. This bit can 
be written only if the external 4-16 MHz oscillator is disabled.
0: external 4-16 MHz oscillator not bypassed
1: external 4-16 MHz oscillator bypassed with external clock
*/
void RCC_set_HSEBYP(U8 b);
#define RCC_bypass_HSE()	RCC_set_HSEBYP(1)
#define RCC_no_bypass_HSE()	RCC_set_HSEBYP(1)

/*
Bit 17 HSERDY: External high-speed clock ready flag	HSE是否准备好
Set by hardware to indicate that the external 4-16 MHz oscillator is stable. This bit needs 6 
cycles of external 4-16 MHz oscillator clock to fall down after HSEON reset.
0: external 4-16 MHz oscillator not ready
1: external 4-16 MHz oscillator ready
*/
U8	RCC_get_HSERDY(void);
#define RCC_is_HSE_ready()	RCC_get_HSERDY()

/*
Bit 16 HSEON: External high-speed clock enable 使能HSE时钟
Set and cleared by software.
Cleared by hardware to stop the external 1-25MHz oscillator when entering in Stop or 
Standby mode. This bit cannot be reset if the external 4-16 MHz oscillator is used directly or 
indirectly as the system clock or is selected to become the system clock.
0: HSE oscillator OFF
1: HSE oscillator ON
*/
void	RCC_set_HSEON(U8 e_d);

#define RCC_enable_HSE()	RCC_set_HSEON(1)
#define RCC_disable_HSE()	RCC_set_HSEON(0)

/*
Bits 15:8 HSICAL[7:0]: Internal high-speed clock calibration HSI出厂校准
These bits are initialized automatically at startup.
*/
U8	RCC_get_HSICAL(void);
#define RCC_get_HSI_cal()			RCC_get_HSICAL()
#define RCC_get_HSI_calibration()	RCC_get_HSICAL()

/*
Bits 7:3 HSITRIM[4:0]: Internal high-speed clock trimming	HSI出厂校准
These bits provide an additional user-programmable trimming value that is added to the 
HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature 
that influence the frequency of the internal HSI RC.
The default value is 16, which, when added to the HSICAL value, should trim the HSI to 8 
MHz ± 1%. The trimming step (Fhsitrim) is around 40 kHz between two consecutive HSICAL 
steps.
*/
void RCC_set_HSITRIM(U8 t);
#define RCC_set_HSI_trim(t) RCC_set_HSITRIM(t)

/*
Bit 1 HSIRDY: Internal high-speed clock ready flag	 HSI是否准备好
Set by hardware to indicate that internal 8 MHz RC oscillator is stable. After the HSION bit is 
cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
0: internal 8 MHz RC oscillator not ready
1: internal 8 MHz RC oscillator ready
*/
U8 RCC_get_HSIRDY(void);
#define RCC_is_HSI_ready()	RCC_get_HSIRDY()

/*
Bit 0 HSION: Internal high-speed clock enable	 HSI使能
Set and cleared by software.
Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby 
mode or in case of failure of the external 4-16 MHz oscillator used directly or indirectly as 
system clock. This bit cannot be reset if the internal 8 MHz RC is used directly or indirectly 
as system clock or is selected to become the system clock.
0: internal 8 MHz RC oscillator OFF
1: internal 8 MHz RC oscillator ON
*/
void RCC_set_HSION(U8 e_d);
#define RCC_enable_HSI()	RCC_set_HSION(1)
#define RCC_disable_HSI()	RCC_set_HSION(0)

	

/*****************************Clock configuration register (RCC_CFGR)***********/
/*Address offset: 0x04
Reset value: 0x0000 0000
Access: 0 ? wait state ? 2, word, half-word and byte access
1 or 2 wait states inserted only if the access occurs during clock source switch.
*/

/*
Bits 26:24 MCO: Microcontroller clock output 对外输出MCO时钟源选择
Set and cleared by software.
0xx: No clock
100: System clock (SYSCLK) selected
101: HSI clock selected
110: HSE clock selected
111: PLL clock divided by 2 selected
Note: This clock output may have some truncated cycles at startup or during MCO clock 
source switching.
When the System Clock is selected to output to the MCO pin, make sure that this clock 
does not exceed 50 MHz (the maximum IO speed). 
*/
void RCC_set_MCO(U8 m);


#define RCC_set_MCO_no_clock()	RCC_set_MCO(0)		//无时钟输出

//命名1
#define RCC_set_MCO_SYSCLK()		RCC_set_MCO(4)		//SYSCLK输出
#define RCC_set_MCO_HSI()			RCC_set_MCO(5)		//HSI输出
#define RCC_set_MCO_HSE()			RCC_set_MCO(6)		//HSE输出
#define RCC_set_MCO_PLL_DIV_2()	R	CC_set_MCO(7)		//PLL/2输出

//命名2
#define RCC_select_MCO_source(m)			RCC_set_MCO(m)
#define RCC_select_MCO_source_no_clock()	RCC_set_MCO(0)		//无时钟输出
#define RCC_disable_MCO()					RCC_set_MCO(0)		//同上
#define RCC_select_MCO_source_SYSCLK()		RCC_set_MCO(4)		//SYSCLK输出
#define RCC_select_MCO_source_HSI()			RCC_set_MCO(5)		//HSI输出
#define RCC_select_MCO_source_HSE()			RCC_set_MCO(6)		//HSE输出
#define RCC_select_MCO_source_PLL_DIV_2()	RCC_set_MCO(7)		//PLL/2输出



/*
Bit 22 USBPRE: USB prescaler			  USB分频设置
Set and cleared by software to generate 48 MHz USB clock. This bit must be valid before 
enabling the USB clock in the RCC_APB1ENR register. This bit can’t be reset if the USB 
clock is enabled.
0: PLL clock is divided by 1.5
1: PLL clock is not divided
*/
void RCC_set_USBPRE(U8 u);

//命名1
#define RCC_set_USBPRE_1()		RCC_set_USBPRE(1)
#define RCC_set_USBPRE_1_5()	RCC_set_USBPRE(0)
//命名2
#define RCC_set_USB_prescaler_1()	RCC_set_USBPRE(1)
#define RCC_set_USB_prescaler_1_5()	RCC_set_SUBPRE(0)

/*
Bits 21:18 PLLMUL: PLL multiplication factor	  PLL倍频设置
These bits are written by software to define the PLL multiplication factor. These bits can be 
written only when PLL is disabled. 
Caution: The PLL output frequency must not exceed 72 MHz.
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16
*/
void RCC_set_PLLMUL(U8 m);

#define RCC_set_PLLMUL_2()	RCC_set_PLLMUL(0)
#define RCC_set_PLLMUL_3()	RCC_set_PLLMUL(1)
#define RCC_set_PLLMUL_4()	RCC_set_PLLMUL(2)
#define RCC_set_PLLMUL_5()	RCC_set_PLLMUL(3)
#define RCC_set_PLLMUL_6()	RCC_set_PLLMUL(4)
#define RCC_set_PLLMUL_7()	RCC_set_PLLMUL(5)
#define RCC_set_PLLMUL_8()	RCC_set_PLLMUL(6)
#define RCC_set_PLLMUL_9()	RCC_set_PLLMUL(7)
#define RCC_set_PLLMUL_10()	RCC_set_PLLMUL(8)
#define RCC_set_PLLMUL_11()	RCC_set_PLLMUL(9)
#define RCC_set_PLLMUL_12()	RCC_set_PLLMUL(10)
#define RCC_set_PLLMUL_13()	RCC_set_PLLMUL(11)
#define RCC_set_PLLMUL_14()	RCC_set_PLLMUL(12)
#define RCC_set_PLLMUL_15()	RCC_set_PLLMUL(13)
#define RCC_set_PLLMUL_16()	RCC_set_PLLMUL(14)

/*
Bit 17 PLLXTPRE: HSE divider for PLL entry	  PLL入口设置
Set and cleared by software to divide HSE before PLL entry. This bit can be written only 
when PLL is disabled.
0: HSE clock not divided
1: HSE clock divided by 2
*/
void RCC_set_PLLXTPRE(U8 p);

#define RCC_set_PLLXTPRE_HSE_1()	RCC_set_PLLXTPRE(0)
#define RCC_set_PLLXTPRE_HSE_2()	RCC_set_PLLXTPRE(1)

/*
Bit 16 PLLSRC: PLL entry clock source		 PLL时钟源设置
Set and cleared by software to select PLL clock source. This bit can be written only when 
PLL is disabled.
0: HSI oscillator clock / 2 selected as PLL input clock
1: HSE oscillator clock selected as PLL input clock
*/
void RCC_set_PLLSRC(U8 s);

#define RCC_set_PLLSRC_HSI()	RCC_set_PLLSRC(0)
#define RCC_set_PLLSRC_HSE()	RCC_set_PLLSRC(1)



/*
Bits 15:14 ADCPRE: ADC prescaler				ADC分频设置
Set and cleared by software to select the frequency of the clock to the ADCs.
00: PCLK2 divided by 2
01: PCLK2 divided by 4
10: PCLK2 divided by 6
11: PCLK2 divided by 8
*/
void RCC_set_ADCPRE(U8 a);

#define RCC_set_ADCPRE_2()	RCC_set_ADCPRE(0)
#define RCC_set_ADCPRE_4()	RCC_set_ADCPRE(1)
#define RCC_set_ADCPRE_6()	RCC_set_ADCPRE(2)
#define RCC_set_ADCPRE_8()	RCC_set_ADCPRE(3)

#define RCC_set_ADC_prescaler_2()	RCC_set_ADCPRE(0)
#define RCC_set_ADC_prescaler_4()	RCC_set_ADCPRE(1)
#define RCC_set_ADC_prescaler_6()	RCC_set_ADCPRE(2)
#define RCC_set_ADC_prescaler_8()	RCC_set_ADCPRE(3)

/*
Bits 13:11 PPRE2: APB high-speed prescaler (APB2)	 APB2分频设置
Set and cleared by software to control the division factor of the APB high-speed clock 
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/
void RCC_set_PPRE2(U8 p);

//命名1
#define RCC_set_APB2PRE(p)		RCC_set_PPRE2(p)
#define RCC_set_APB2PRE_1()		RCC_set_PPRE2(0)
#define RCC_set_APB2PRE_2()		RCC_set_PPRE2(4)
#define RCC_set_APB2PRE_4()		RCC_set_PPRE2(5)
#define RCC_set_APB2PRE_8()		RCC_set_PPRE2(6)
#define RCC_set_APB2PRE_16()	RCC_set_PPRE2(7)

//命名2
#define RCC_set_APB2_prescaler(p)		RCC_set_PPRE2(p)
#define RCC_set_APB2_prescaler_1()		RCC_set_PPRE2(0)
#define RCC_set_APB2_prescaler_2()		RCC_set_PPRE2(4)
#define RCC_set_APB2_prescaler_4()		RCC_set_PPRE2(5)
#define RCC_set_APB2_prescaler_8()		RCC_set_PPRE2(6)
#define RCC_set_APB2_prescaler_16()		RCC_set_PPRE2(7)

/*
Bits 10:8 PPRE1: APB low-speed prescaler (APB1)	  APB1分频设置
Set and cleared by software to control the division factor of the APB low-speed clock 
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/
void RCC_set_PPRE1(U8 p);

#define RCC_set_APB1PRE(p)		RCC_set_PPRE1(p)
#define RCC_set_APB1PRE_1()		RCC_set_PPRE1(0)
#define RCC_set_APB1PRE_2()		RCC_set_PPRE1(4)
#define RCC_set_APB1PRE_4()		RCC_set_PPRE1(5)
#define RCC_set_APB1PRE_8()		RCC_set_PPRE1(6)
#define RCC_set_APB1PRE_16()	RCC_set_PPRE1(7)

#define RCC_set_APB1_prescaler(p)	RCC_set_PPRE1(p)
#define RCC_set_APB1_prescaler_1()	RCC_set_PPRE1(0)
#define RCC_set_APB1_prescaler_2()	RCC_set_PPRE1(4)
#define RCC_set_APB1_prescaler_4()	RCC_set_PPRE1(5)
#define RCC_set_APB1_prescaler_8()	RCC_set_PPRE1(6)
#define RCC_set_APB1_prescaler_16()	RCC_set_PPRE1(7)


/*
Bits 7:4 HPRE: AHB prescaler			 AHB分频设置
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512
Note: The prefetch buffer must be kept on when using a prescaler different from 1 on the 
AHB clock. Refer to Reading the Flash memory on page 52 section for more details.
*/
void RCC_set_HPRE(U8 p);

//命名1
#define RCC_set_AHBPRE(p)		RCC_set_HPRE(p)
#define RCC_set_AHBPRE_1()		RCC_set_HPRE(0)
#define RCC_set_AHBPRE_2()		RCC_set_HPRE(8)
#define RCC_set_AHBPRE_4()		RCC_set_HPRE(9)
#define RCC_set_AHBPRE_8()		RCC_set_HPRE(10)
#define RCC_set_AHBPRE_16()		RCC_set_HPRE(11)
#define RCC_set_AHBPRE_64()		RCC_set_HPRE(12)
#define RCC_set_AHBPRE_128()	RCC_set_HPRE(13)
#define RCC_set_AHBPRE_256()	RCC_set_HPRE(14)
#define RCC_set_AHBPRE_512()	RCC_set_HPRE(15)

//命名2
#define RCC_set_AHB_prescaler(p)		RCC_set_HPRE(p)
#define RCC_set_AHB_prescaler_1()		RCC_set_HPRE(0)
#define RCC_set_AHB_prescaler_2()		RCC_set_HPRE(8)
#define RCC_set_AHB_prescaler_4()		RCC_set_HPRE(9)
#define RCC_set_AHB_prescaler_8()		RCC_set_HPRE(10)
#define RCC_set_AHB_prescaler_16()		RCC_set_HPRE(11)
#define RCC_set_AHB_prescaler_64()		RCC_set_HPRE(12)
#define RCC_set_AHB_prescaler_128()		RCC_set_HPRE(13)
#define RCC_set_AHB_prescaler_256()		RCC_set_HPRE(14)
#define RCC_set_AHB_prescaler_512()		RCC_set_HPRE(15)


/*
Bits 3:2 SWS: System clock switch status  获取时钟时钟源
Set and cleared by hardware to indicate which clock source is used as system clock.
00: HSI oscillator used as system clock
01: HSE oscillator used as system clock
10: PLL used as system clock
11: not applicable
*/
U8 RCC_get_SWS(void);
#define RCC_get_SYSCLK_source()	RCC_get_SWS()
#define RCC_get_system_clock()	RCC_get_SWS()
#define RCC_get_system_clock_source()	RCC_get_SWS()

/*
Bits 1:0 SW: System clock switch	设置系统时钟源
Set and cleared by software to select SYSCLK source.
Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of 
failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security 
System is enabled).
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
11: not allowed
*/

void RCC_set_SW(U8 s);

//设置系统时钟源
#define RCC_set_SW_HSI()		RCC_set_SW(0)
#define RCC_set_SW_HSE()		RCC_set_SW(1)
#define RCC_set_SW_PLL()		RCC_set_SW(2)
#define RCC_set_SW_PLLCLK()		RCC_set_SW(2)

#define RCC_set_SYSCLK(s)		RCC_set_SW(s)
#define RCC_set_SYSCLK_HSI()	RCC_set_SW(0)
#define RCC_set_SYSCLK_HSE()	RCC_set_SW(1)
#define RCC_set_SYSCLK_PLL()	RCC_set_SW(2)




/*******************************Clock interrupt register (RCC_CIR)************************/


/*
Address offset: 0x08
Reset value: 0x0000 0000
Access: no wait state, word, half-word and byte access
*/


/*
Bit 23 CSSC: Clock security system interrupt clear	清除时钟安全系统中断标志
This bit is set by software to clear the CSSF flag.
0: No effect
1: Clear CSSF flag
*/
void RCC_set_CSSC(void);	

#define RCC_clear_CSS_interrupt_flag()	RCC_set_CSSC()
#define RCC_clear_clock_security_interrupt_flag()	RCC_set_CSSC()

/*
Bits 22:21
Reserved, always read as 0.
*/
/*
Bit 20 PLLRDYC: PLL ready interrupt clear			清除PLL准备中断标志
This bit is set by software to clear the PLLRDYF flag.
0: No effect
1: PLLRDYF cleared
*/
void RCC_set_PLLRDYC(void);

#define RCC_clear_PLL_ready_interrupt_flag()	RCC_set_PLLRDYC()


/*
Bit 19 HSERDYC: HSE ready interrupt clear			清除HSE准备中断标志 	
This bit is set by software to clear the HSERDYF flag.
0: No effect
1: HSERDYF cleared
*/
void RCC_set_HSERDYC(void);

#define RCC_clear_HSE_ready_interrupt_flag()	RCC_set_HSERDYC()

/*
Bit 18 HSIRDYC: HSI ready interrupt clear		  清除HSI准备中断标志
This bit is set software to clear the HSIRDYF flag.
0: No effect
1: HSIRDYF cleared
*/
void RCC_set_HSIRDYC(void);

#define RCC_clear_HSI_ready_interrupt_flag()	RCC_set_HSIRDYC()

/*
Bit 17 LSERDYC: LSE ready interrupt clear		   清除LSE准备中断标志
This bit is set by software to clear the LSERDYF flag.
0: No effect
1: LSERDYF cleared
*/
void RCC_set_LSERDYC(void);

#define RCC_clear_LSE_ready_interrupt_flag()	RCC_set_HSERDYC()

/*
Bit 16 LSIRDYC: LSI ready interrupt clear		   清除LSI准备中断标志
This bit is set by software to clear the LSIRDYF flag.
0: No effect
1: LSIRDYF cleared
*/
void RCC_set_LSIRDYC(void);

#define RCC_clear_LSI_ready_interrupt_flag()	RCC_set_LSIRDYC()

/*
Bits 15:13
Reserved, always read as 0.
*/


/*
Bit 12 PLLRDYIE: PLL ready interrupt enable	  PLL准备中断使能
Set and cleared by software to enable/disable interrupt caused by PLL lock.
0: PLL lock interrupt disabled
1: PLL lock interrupt enabled
*/
void RCC_set_PLLRDYIE(U8 e_d);

#define RCC_enable_interrupt_at_PLL_ready()	RCC_set_PLLRDYIE(1)
#define RCC_disable_interrupt_at_PLL_ready()	RCC_set_PLLRDYIE(0)


/*
Bit 11 HSERDYIE: HSE ready interrupt enable	  HSE准备中断使能
Set and cleared by software to enable/disable interrupt caused by the external 4-16 MHz 
oscillator stabilization.
0: HSE ready interrupt disabled
1: HSE ready interrupt enabled
*/
void RCC_set_HSERDYIE(U8 e_d) ;

#define RCC_enable_interrupt_at_HSE_ready()		RCC_set_HSERDYIE(1)
#define RCC_disable_interrupt_at_HSE_ready()	RCC_set_HSERDYIE(0)

/*
Bit 10 HSIRDYIE: HSI ready interrupt enable	  HSI准备中断使能
Set and cleared by software to enable/disable interrupt caused by the internal 8 MHz RC 
oscillator stabilization.
0: HSI ready interrupt disabled
1: HSI ready interrupt enabled
*/
void RCC_set_HSIRDYIE(U8 e_d);

#define RCC_enable_interrupt_at_HSI_ready()		RCC_set_HSIRDYIE(1)
#define RCC_disable_interrupt_at_HSI_ready()	RCC_set_HSIRDYIE(0)


/*
Bit 9 LSERDYIE: LSE ready interrupt enable			LSE准备中断使能
Set and cleared by software to enable/disable interrupt caused by the external 32 kHz 
oscillator stabilization.
0: LSE ready interrupt disabled
1: LSE ready interrupt enabled
*/
void RCC_set_LSERDYIE(U8 e_d);	

#define RCC_enable_interrupt_at_LSE_ready()		RCC_set_LSERDYIE(1)
#define RCC_disable_interrupt_at_LSE_ready()	RCC_set_LSERDYIE(0)

/*
Bit 8 LSIRDYIE: LSI ready interrupt enable			LSI准备中断使能
Set and cleared by software to enable/disable interrupt caused by internal RC 40 kHz 
oscillator stabilization.
0: LSI ready interrupt disabled
1: LSI ready interrupt enabled
*/
void RCC_set_LSIRDYIE(U8 e_d);

#define RCC_enable_interrupt_at_LSI_ready()		CC_set_LSIRDYIE(1)
#define RCC_disable_interrupt_at_LSI_ready()	RCC_set_LSIRDYIE(0)

/*
Bit 7 CSSF: Clock security system interrupt flag  	系统时钟安全中断标志
Set by hardware when a failure is detected in the external 4-16 MHz oscillator.
Cleared by software setting the CSSC bit.
0: No clock security interrupt caused by HSE clock failure
1: Clock security interrupt caused by HSE clock failure
*/
U8 RCC_get_CSSF(void);

#define RCC_is_interrupted_by_CSS()	RCC_get_CSSF()
#define RCC_is_interrupted_by_clock_security()	RCC_set_CSSF()

/*
Bits 6:5
Reserved, always read as 0.
*/
/*
Bit 4 PLLRDYF: PLL ready interrupt flag				PLL准备中断标志
Set by hardware when the PLL locks and PLLRDYDIE is set.
Cleared by software setting the PLLRDYC bit.
0: No clock ready interrupt caused by PLL lock
1: Clock ready interrupt caused by PLL lock
*/
U8  RCC_get_PLLRDYF(void);

#define RCC_is_interrupted_by_PLL_ready()	RCC_get_PLLRDYF()

/*
Bit3 HSERDYF: HSE ready interrupt flag			 	HSE准备中断标志
Set by hardware when External Low Speed clock becomes stable and HSERDYDIE is set.
Cleared by software setting the HSERDYC bit.
0: No clock ready interrupt caused by the external 4-16 MHz oscillator
1: Clock ready interrupt caused by the external 4-16 MHz oscillator
*/
U8	RCC_get_HSERDYF(void);

#define RCC_is_interrupted_by_HSE_ready()	RCC_get_HSERDYF()

/*
Bit 2 HSIRDYF: HSI ready interrupt flag			 	HSI准备中断标志
Set by hardware when the Internal High Speed clock becomes stable and HSIRDYDIE is 
set.
Cleared by software setting the HSIRDYC bit.
0: No clock ready interrupt caused by the internal 8 MHz RC oscillator
1: Clock ready interrupt caused by the internal 8 MHz RC oscillator
*/
U8 	RCC_get_HSIRDYF(void);

#define RCC_is_interrupted_by_HSI_ready()	RCC_get_HSIRDYF()

/*
Bit 1 LSERDYF: LSE ready interrupt flag				LSE准备中断标志
Set by hardware when the External Low Speed clock becomes stable and LSERDYDIE is 
set.
Cleared by software setting the LSERDYC bit.
0: No clock ready interrupt caused by the external 32 kHz oscillator
1: Clock ready interrupt caused by the external 32 kHz oscillator
*/
U8	RCC_get_LSERDYF(void);

#define RCC_is_interrupted_by_LSE_ready()	RCC_get_LSERDYF()

/*
Bit 0 LSIRDYF: LSI ready interrupt flag			  	LSI准备中断标志
Set by hardware when the internal low speed clock becomes stable and LSIRDYDIE is set.
Cleared by software setting the LSIRDYC bit.
0: No clock ready interrupt caused by the internal RC 40 kHz oscillator
1: Clock ready interrupt caused by the internal RC 40 kHz oscillator
*/
U8	RCC_get_LSIRDYF(void);

#define RCC_is_interrupted_by_LSI_ready()	RCC_get_LSIRDYF()



/*************************************APB2 peripheral reset register (RCC_APB2RSTR) APB2总线外设复位*******************************************/
/*
Address offset: 0x0C
Reset value: 0x00000 0000
Access: no wait state, word, half-word and byte access
*/


/*
Bit 21 TIM11RST: TIM11 timer reset TIM11复位
Set and cleared by software.
0: No effect
1: Reset TIM11 timer
*/
void RCC_set_TIM11RST(void);

#define RCC_reset_TIM11()	RCC_set_TIM11RST()

/*
Bit 20 TIM10RST: TIM10 timer reset	TIM10复位
Set and cleared by software.
0: No effect
1: Reset TIM10 timer
*/
void RCC_set_TIM10RST(void);

#define RCC_reset_TIM10()	RCC_set_TIM10RST()


/*
Bit 19 TIM9RST: TIM9 timer reset  TIM9复位
Set and cleared by software.
0: No effect
1: Reset TIM9 timer
*/
void RCC_set_TIM9RST(void);

#define RCC_reset_TIM9()	RCC_set_TIM9RST()

/*
Bits 18:16
Reserved, always read as 0.
*/

/*
Bit 15 ADC3RST: ADC3 interface reset  ADC3复位
Set and cleared by software.
0: No effect
1: Reset ADC3 interface
*/
void RCC_set_ADC3RST(void);

#define RCC_reset_ADC3()	RCC_set_ADC3RST()
/*
Bit 14 USART1RST: USART1 reset		 USART1复位
Set and cleared by software.
0: No effect
1: Reset USART1
*/
void RCC_set_USART1RST(void);

#define RCC_reset_USART1()	RCC_set_USART1RST()

/*
Bit 13 TIM8RST: TIM8 timer reset   TIM8复位
Set and cleared by software.
0: No effect
1: Reset TIM8 timer
*/
void RCC_set_TIM8RST(void);
#define RCC_reset_TIM8()	RCC_set_TIM8RST()

/*
Bit 12 SPI1RST: SPI1 reset		 SPI1复位
Set and cleared by software.
0: No effect
1: Reset SPI1
*/
void RCC_set_SPI1RST(void);
#define RCC_reset_SPI1()	RCC_set_SPI1RST()


/*
Bit 11 TIM1RST: TIM1 timer reset   TIM1复位
Set and cleared by software.
0: No effect
1: Reset TIM1 timer
*/
void RCC_set_TIM1RST(void);
#define RCC_reset_TIM1()	RCC_set_TIM1RST()

/*
Bit 10 ADC2RST: ADC 2 interface reset  ADC2复位
Set and cleared by software.
0: No effect
1: Reset ADC 2 interface
*/
void RCC_set_ADC2RST(void);
#define RCC_reset_ADC2()	RCC_set_ADC2RST()

/*
Bit 9 ADC1RST: ADC 1 interface reset  ADC1复位
Set and cleared by software.
0: No effect
1: Reset ADC 1 interface
*/
void RCC_set_ADC1RST(void);
#define RCC_reset_ADC1()	RCC_set_ADC1RST()

/*
Bit 8 IOPGRST: IO port G reset	   IOPG复位
Set and cleared by software.
0: No effect
1: Reset IO port G
*/
void RCC_set_IOPGRST(void);
#define RCC_reset_GPIO_G()	RCC_set_IOPGRST()
#define RCC_reset_IOPG()	RCC_set_IOPGRST()

/*
Bit 7 IOPFRST: IO port F reset	  IOPF复位
Set and cleared by software.
0: No effect
1: Reset IO port F
*/
void RCC_set_IOPFRST(void);
#define RCC_reset_GPIO_F()	RCC_set_IOPFRST()
#define RCC_reset_IOPF()	RCC_set_IOPFRST()

/*
Bit 6 IOPERST: IO port E reset	  IOPE复位
Set and cleared by software.
0: No effect
1: Reset IO port E
*/
void RCC_set_IOPERST(void);
#define RCC_reset_GPIO_E()	RCC_set_IOPERST()
#define RCC_reset_IOPE()	RCC_set_IOPERST()

/*
Bit 5 IOPDRST: IO port D reset	 IOPD复位
Set and cleared by software.
0: No effect
1: Reset IO port D
*/
void RCC_set_IOPDRST(void);
#define RCC_reset_GPIO_D()	RCC_set_IOPDRST()
#define RCC_reset_IOPD()	RCC_set_IOPDRST()

/*
Bit 4 IOPCRST: IO port C reset	   IOPC复位
Set and cleared by software.
0: No effect
1: Reset IO port C
*/
void RCC_set_IOPCRST(void);
#define RCC_reset_GPIO_C()	RCC_set_IOPCRST()
#define RCC_reset_IOPC()	RCC_set_IOPCRST()

/*
Bit 3 IOPBRST: IO port B reset	   IOPB复位
Set and cleared by software.
0: No effect
1: Reset IO port B
*/
void RCC_set_IOPBRST(void);
#define RCC_reset_GPIO_B()	RCC_set_IOPBRST()
#define RCC_reset_IOPB()	RCC_set_IOPBRST()

/*
Bit 2 IOPARST: IO port A reset	 IOPA复位
Set and cleared by software.
0: No effect
1: Reset IO port A
*/
void RCC_set_IOPARST(void);
#define RCC_reset_GPIO_A()	RCC_set_IOPARST()
#define RCC_reset_IOPA()	RCC_set_IOPARST()
/*
Bit 1
Reserved, always read as 0.
*/

/*
Bit 0 AFIORST: Alternate function IO reset	AFIO复位
Set and cleared by software.
0: No effect
1: Reset Alternate Function
*/
void RCC_set_AFIORST(void);
#define RCC_reset_AFIO()	RCC_set_AFIORST()


/*****************************APB1 peripheral reset register (RCC_APB1RSTR) APB1总线外设复位********************/

/*
	Address offset: 0x10
	Reset value: 0x0000 0000
	Access: no wait state, word, half-word and byte access
*/

/*
Bit 29 DACRST: DAC interface reset	 DAC复位
Set and cleared by software.
0: No effect
1: Reset DAC interface
*/
void RCC_set_DACRST(void);
#define RCC_reset_DAC()		RCC_set_DACRST()

/*
Bit 28 PWRRST: Power interface reset	PWR复位
Set and cleared by software.
0: No effect
1: Reset power interface
*/
void RCC_set_PWRRST(void);
#define RCC_reset_PWR()		RCC_set_PWRRST()

/*
Bit 27 BKPRST: Backup interface reset	 BKP复位
Set and cleared by software.
0: No effect
1: Reset backup interface
*/
void RCC_set_BKPRST(void);
#define RCC_reset_BKP()		RCC_set_BKPRST()

/*
Bit 26 Reserved, always read as 0.
*/

/*
Bit 25 CANRST: CAN reset			CAN复位
Set and cleared by software.
0: No effect
1: Reset CAN
*/
void RCC_set_CANRST(void);
#define RCC_reset_CAN()		RCC_set_CANRST()
/*
Bit 24 Reserved, always read as 0.
*/

/*
Bit 23 USBRST: USB reset
Set and cleared by software.		USB复位
0: No effect
1: Reset USB
*/
void RCC_set_USBRST(void);
#define RCC_reset_USB()		RCC_set_USBRST()
/*
Bit 22 I2C2RST: I2C 2 reset			I2C2复位
Set and cleared by software.
0: No effect
1: Reset I2C 2
*/
void RCC_set_I2C2RST(void);
#define RCC_reset_I2C2()	RCC_set_I2C2RST()
/*
Bit 21 I2C1RST: I2C 1 reset		   I2C1复位
Set and cleared by software.
0: No effect
1: Reset I2C 1
*/
void RCC_set_I2C1RST(void);
#define RCC_reset_I2C1()	RCC_set_I2C1RST()
/*
Bit 20 UART5RST: USART 5 reset	   USART5复位
Set and cleared by software.
0: No effect
1: Reset USART 5
*/
void RCC_set_UART5RST(void)	;
#define RCC_reset_UART5()	RCC_set_UART5RST()
/*
Bit 19 UART4RST: USART 4 reset	   USART4复位
Set and cleared by software.
0: No effect
1: Reset USART 4
*/
void RCC_set_UART4RST(void);
#define RCC_reset_UART4()	RCC_set_UART4RST()
/*
Bit 18 USART3RST: USART 3 reset		 USART3复位
Set and cleared by software.
0: No effect
1: Reset USART 3
*/
void RCC_set_USART3RST(void);
#define RCC_reset_USART3()	RCC_set_USART3RST()
/*
Bit 17 USART2RST: USART 2 reset		  USART2复位
Set and cleared by software.
0: No effect
1: Reset USART 2
*/
void RCC_set_USART2RST(void);
#define RCC_reset_USART2()	RCC_set_USART2RST()
/*
Bit 16 Reserved, always read as 0.
*/

/*
Bit 15 SPI3RST: SPI 3 reset		   SPI3复位
Set and cleared by software.
0: No effect
1: Reset SPI 3
*/
void RCC_set_SPI3RST(void);
#define RCC_reset_SPI3()	RCC_set_SPI3RST()
/*
Bit 14 SPI2RST: SPI 2 reset		  SPI2复位
Set and cleared by software.
0: No effect
1: Reset SPI 2
*/
void RCC_set_SPI2RST(void);
#define RCC_reset_SPI2()	RCC_set_SPI2RST()
/*
Bits 13:12 Reserved, always read as 0.
*/

/*
Bit 11 WWDGRST: Window watchdog reset  WWNG复位
Set and cleared by software.
0: No effect
1: Reset window watchdog
*/
void RCC_set_WWDGRST(void);
#define RCC_reset_WWDG()	RCC_set_WWDGRST()
/*
Bits 10:9 Reserved, always read as 0.
*/
/*
Bit 8 TIM14RST: TIM14 timer reset	 TIM14复位
Set and cleared by software.
0: No effect
1: Reset TIM14
*/
void RCC_set_TIM14RST(void);
#define RCC_reset_TIM14()	RCC_set_TIM14RST()
/*
Bit 7 TIM13RST: TIM13 timer reset	TIM13复位
Set and cleared by software.
0: No effect
1: Reset TIM13
*/
void RCC_set_TIM13RST(void);
#define RCC_reset_TIM13()	RCC_set_TIM13RST()
/*
Bit 6 TIM12RST: TIM12 timer reset	  TIM12复位
Set and cleared by software.
0: No effect
1: Reset TIM12
*/
void RCC_set_TIM12RST(void);
#define RCC_reset_TIM12()	RCC_set_TIM12RST()
/*
Bit 5 TIM7RST: TIM7 timer reset		 TIM7复位
Set and cleared by software.
0: No effect
1: Reset TIM7
*/
void RCC_set_TIM7RST(void);
#define RCC_reset_TIM7()	RCC_set_TIM7RST()
/*
Bit 4 TIM6RST: TIM6 timer reset		TIM6复位
Set and cleared by software.
0: No effect
1: Reset TIM6
*/
void RCC_set_TIM6RST(void);
#define RCC_reset_TIM6()	RCC_set_TIM6RST()
/*
Bit 3 TIM5RST: TIM5 timer reset		TIM5复位
Set and cleared by software.
0: No effect
1: Reset TIM5
*/
void RCC_set_TIM5RST(void);
#define RCC_reset_TIM5()	RCC_set_TIM5RST()
/*
Bit 2 TIM4RST: TIM4 timer reset	   	TIM4复位
Set and cleared by software.
0: No effect
1: Reset TIM4
*/
void RCC_set_TIM4RST(void);
#define RCC_reset_TIM4()	RCC_set_TIM4RST()
/*
Bit 1 TIM3RST: TIM3 timer reset	   	TIM3复位
Set and cleared by software.
0: No effect
1: Reset TIM3
*/
void RCC_set_TIM3RST(void);
#define RCC_reset_TIM3()	RCC_set_TIM3RST()

/*
Bit 0 TIM2RST: TIM2 timer reset		 TIM2复位
Set and cleared by software.
0: No effect
1: Reset TIM2
*/
void RCC_set_TIM2RST(void);
#define RCC_reset_TIM2()	RCC_set_TIM2RST(TIM2)



//*********************************AHB peripheral clock enable register (RCC_AHBENR)**********************//

/*
AHB peripheral clock enable register (RCC_AHBENR)	AHB总线外设使能
Address offset: 0x14
Reset value: 0x0000 0014
Access: no wait state, word, half-word and byte access
Note:
When the peripheral clock is not active, the peripheral register values may not be readable 
by software and the returned value is always 0x0.
*/

/*
Bits 31:11 Reserved, always read as 0.
*/

/*
Bit 10 SDIOEN: SDIO clock enable		SDIO使能
Set and cleared by software.
0: SDIO clock disabled
1: SDIO clock enabled
*/
void RCC_set_SDIOEN(U8 e_d);

#define RCC_enable_SDIO_clock()		RCC_set_SDIOEN(1)
#define RCC_disable_SDIO_clock()	RCC_set_SDIOEN(0)

/*
Bits 9
Reserved, always read as 0.
*/

/*
Bit 8 FSMCEN: FSMC clock enable			FSMC使能
Set and cleared by software.
0: FSMC clock disabled
1: FSMC clock enabled
*/
void RCC_set_FSMCEN(U8 e_d);
#define RCC_enable_FSMC_clock()		RCC_set_FSMCEN(1)
#define RCC_disable_FSMC_clock()	RCC_set_FSMCEN(0)

/*
Bit 7
Reserved, always read as 0.
*/

/*
Bit 6 CRCEN: CRC clock enable			 CRC使能
Set and cleared by software.
0: CRC clock disabled
1: CRC clock enabled
*/
void RCC_set_CRCEN(U8 e_d);
#define RCC_enable_CRC_clock()		RCC_set_CRCEN(1)
#define RCC_disable_CRC_clock()		RCC_set_CRCEN(0)

/*
Bit 5 Reserved, always read as 0.
*/

/*
Bit 4 FLITFEN: FLITF clock enable		  FLITF使能
Set and cleared by software to disable/enable FLITF clock during Sleep mode.
0: FLITF clock disabled during Sleep mode
1: FLITF clock enabled during Sleep mode
*/
void RCC_set_FLITFEN(U8 e_d);
#define RCC_enable_FLITF_clock()		RCC_set_FLITFEN(1)
#define RCC_disable_FLITF_clock()		RCC_set_FLITFEN(0)

/*
Bit 3 Reserved, always read as 0.
*/

/*
Bit 2 SRAMEN: SRAM interface clock enable	 SRAM使能(睡眠时)
Set and cleared by software to disable/enable SRAM interface clock during Sleep mode.
0: SRAM interface clock disabled during Sleep mode.
1: SRAM interface clock enabled during Sleep mode
*/
void RCC_set_SRAMEN(U8 e_d);
#define RCC_enable_SRAM_clock()		RCC_set_SRAMEN(1)
#define RCC_disable_SRAM_clock()	RCC_set_SRAMEN(0)

/*
Bit 1 DMA2EN: DMA2 clock enable			  DMA2使能
Set and cleared by software.
0: DMA2 clock disabled
1: DMA2 clock enabled
*/
void RCC_set_DMA2EN(U8 e_d) ;
#define RCC_enable_DMA2_clock()		RCC_set_DMA2EN(1)
#define RCC_disable_DMA2_clock()	RCC_set_DMA2EN(0)

/*
Bit 0 DMA1EN: DMA1 clock enable			  DMA1使能
Set and cleared by software.
0: DMA1 clock disabled
1: DMA1 clock enabled
*/
void RCC_set_DMA1EN(U8 e_d) ;
#define RCC_enable_DMA1_clock()		RCC_set_DMA1EN(1)
#define RCC_disable_DMA1_clock()	RCC_set_DMA1EN(0)



//***********************************APB2 peripheral clock enable register (RCC_APB2ENR)****************//
/*
Address: 0x18
Reset value: 0x0000 0000					   		APB2总线外设使能
Access: word, half-word and byte access
No wait states, except if the access occurs while an access to a peripheral in the APB2 
domain is on going. In this case, wait states are inserted until the access to APB2 peripheral 
is finished.
*/

/*
Bits 31:22 Reserved, always read as 0.
*/

/*
Bit 21 TIM11EN: TIM11 timer clock enable 			TIM11使能
Set and cleared by software.
0: TIM11 timer clock disabled
1: TIM11 timer clock enabled
*/
void RCC_set_TIM11EN(U8 e_d);
#define RCC_enable_TIM11_clock()	RCC_set_TIM11EN(1)
#define RCC_disable_TIM11_clock()	RCC_set_TIM11EN(0)

/*
Bit 20 TIM10EN: TIM10 timer clock enable	   		TIM10使能
Set and cleared by software.
0: TIM10 timer clock disabled
1: TIM10 timer clock enabled
*/
void RCC_set_TIM10EN(U8 e_d);
#define RCC_enable_TIM10_clock()	RCC_set_TIM10EN(1)
#define RCC_disable_TIM10_clock()	RCC_set_TIM10EN(0)

/*
Bit 19 TIM9EN: TIM9 timer clock enable				TIM9使能
Set and cleared by software.
0: TIM9 timer clock disabled
1: TIM9 timer clock enabled
*/
void RCC_set_TIM9EN(U8 e_d);
#define RCC_enable_TIM9_clock()		RCC_set_TIM9EN(1)
#define RCC_disable_TIM9_clock()	RCC_set_TIM9EN(0)


/*
Bits 18:16 Reserved, always read as 0.
*/

/*
Bit 15 ADC3EN: ADC 3 interface clock enable	  	 	ADC3使能
Set and cleared by software.
0: ADC 3 interface clock disabled
1: ADC 3 interface clock enabled
*/
void RCC_set_ADC3EN(U8 e_d);
#define RCC_enable_ADC3_clock()		RCC_set_ADC3EN(1)
#define RCC_disable_ADC3_clock()	RCC_set_ADC3EN(0)

/*												
Bit 14 USART1EN: USART1 clock enable				USART1使能
Set and cleared by software.
0: USART1 clock disabled
1: USART1 clock enabled
*/
void RCC_set_USART1EN(U8 e_d);
#define RCC_enable_USART1_clock()	RCC_set_USART1EN(1)
#define RCC_disable_USART1_clock()	RCC_set_USART1EN(0)


/*
Bit 13 TIM8EN: TIM8 Timer clock enable	   			TIM8使能
Set and cleared by software.
0: TIM8 timer clock disabled
1: TIM8 timer clock enabled
*/
void RCC_set_TIM8EN(U8 e_d);
#define RCC_enable_TIM8_clock()		RCC_set_TIM8EN(1)
#define RCC_disable_TIM8_clock()	RCC_set_TIM8EN(0)


/*
Bit 12 SPI1EN: SPI 1 clock enable		  			SPI1使能
Set and cleared by software.
0: SPI 1 clock disabled
1: SPI 1 clock enabled
*/
void RCC_set_SPI1EN(U8 e_d);
#define RCC_enable_SPI1_clock()		RCC_set_SPI1EN(1)
#define RCC_disable_SPI1_clock()	RCC_set_SPI1EN(0)


/*
Bit 11 TIM1EN: TIM1 timer clock enable	   			TIM1使能
Set and cleared by software.
0: TIM1 timer clock disabled
1: TIM1 timer clock enabled
*/
void RCC_set_TIM1EN(U8 e_d);
#define RCC_enable_TIM1_clock()		RCC_set_TIM1EN(1)
#define RCC_disable_TIM1_clock()	RCC_set_TIM1EN(0)


/*
Bit 10 ADC2EN: ADC 2 interface clock enable	  		ADC2使能
Set and cleared by software.
0: ADC 2 interface clock disabled
1: ADC 2 interface clock enabled
*/
void RCC_set_ADC2EN(U8 e_d);
#define RCC_enable_ADC2_clock()		RCC_set_ADC2EN(1)
#define RCC_disable_ADC2_clock()	RCC_set_ADC2EN(0)

/*
Bit 9 ADC1EN: ADC 1 interface clock enable			ADC1使能
Set and cleared by software.
0: ADC 1 interface disabled
1: ADC 1 interface clock enabled
*/
void RCC_set_ADC1EN(U8 e_d);
#define RCC_enable_ADC1_clock()		RCC_set_ADC1EN(1)
#define RCC_disable_ADC1_clock()	RCC_set_ADC1EN(0)

/*
Bit 8 IOPGEN: IO port G clock enable	   			IOPG使能
Set and cleared by software.
0: IO port G clock disabled
1: IO port G clock enabled
*/
void RCC_set_IOPGEN(U8 e_d);
#define RCC_enable_IOPG_clock()		RCC_set_IOPGEN(1)
#define RCC_disable_IOPG_clock()	RCC_set_IOPGEN(0)

#define RCC_enable_GPIO_G_clock()	RCC_set_IOPGEN(1)
#define RCC_disable_GPIO_G_clock()	RCC_set_IOPGEN(0)

/*
Bit 7 IOPFEN: IO port F clock enable	   			IOPF使能
Set and cleared by software.
0: IO port F clock disabled
1: IO port F clock enabled
*/
void RCC_set_IOPFEN(U8 e_d);
#define RCC_enable_IOPF_clock()		RCC_set_IOPFEN(1)
#define RCC_disable_IOPF_clock()	RCC_set_IOPFEN(0)

#define RCC_enable_GPIO_F_clock()	RCC_set_IOPFEN(1)
#define RCC_disable_GPIO_F_clock()	RCC_set_IOPFEN(0)

/*
Bit 6 IOPEEN: IO port E clock enable	  			IOPE使能
Set and cleared by software.
0: IO port E clock disabled
1: IO port E clock enabled
*/
void RCC_set_IOPEEN(U8 e_d);
#define RCC_enable_IOPE_clock()		RCC_set_IOPEEN(1)
#define RCC_disable_IOPE_clock()	RCC_set_IOPEEN(0)

#define RCC_enable_GPIO_E_clock()	RCC_set_IOPEEN(1)
#define RCC_disable_GPIO_E_clock()	RCC_set_IOPEEN(0)

/*
Bit 5 IOPDEN: IO port D clock enable	  			IOPD使能
Set and cleared by software.
0: IO port D clock disabled
1: IO port D clock enabled
*/
void RCC_set_IOPDEN(U8 e_d);
#define RCC_enable_IOPD_clock()		RCC_set_IOPDEN(1)
#define RCC_disable_IOPD_clock()	RCC_set_IOPDEN(0)

#define RCC_enable_GPIO_D_clock()	RCC_set_IOPDEN(1)
#define RCC_disable_GPIO_D_clock()	RCC_set_IOPDEN(0)

/*
Bit 4 IOPCEN: IO port C clock enable	  			IOPC使能
Set and cleared by software.
0: IO port C clock disabled
1: IO port C clock enabled
*/
void RCC_set_IOPCEN(U8 e_d);
#define RCC_enable_IOPC_clock()		RCC_set_IOPCEN(1)
#define RCC_disable_IOPC_clock()	RCC_set_IOPCEN(0)

#define RCC_enable_GPIO_C_clock()	RCC_set_IOPCEN(1)
#define RCC_disable_GPIO_C_clock()	RCC_set_IOPCEN(0)

/*
Bit 3 IOPBEN: IO port B clock enable				IOPB使能
Set and cleared by software.
0: IO port B clock disabled
1: IO port B clock enabled
*/
void RCC_set_IOPBEN(U8 e_d) ;
#define RCC_enable_IOPB_clock()		RCC_set_IOPBEN(1)
#define RCC_disable_IOPB_clock()	RCC_set_IOPBEN(0)

#define RCC_enable_GPIO_B_clock()	RCC_set_IOPBEN(1)
#define RCC_disable_GPIO_B_clock()	RCC_set_IOPBEN(0)

/*
Bit 2 IOPAEN: IO port A clock enable	  			IOPA使能
Set and cleared by software.
0: IO port A clock disabled
1: IO port A clock enabled
*/
void RCC_set_IOPAEN(U8 e_d);
#define RCC_enable_IOPA_clock()		RCC_set_IOPAEN(1)
#define RCC_disable_IOPA_clock()	RCC_set_IOPAEN(0)

#define RCC_enable_GPIO_A_clock()	RCC_set_IOPAEN(1)
#define RCC_disable_GPIO_A_clock()	RCC_set_IOPAEN(0)

/*
Set GPIO_x port clock enable
Set and cleared by software.
port:	GPIO_A - GPIO_G
e_d:	enable(1), disable(0)
*/
void RCC_set_IOPxEN(U8 port, U8 e_d);

#define RCC_enable_IOPx_clock(port)		RCC_set_IOPxEN(port, 1)
#define RCC_disable_IOPx_clock(port)	RCC_set_IOPxEN(port, 0)

#define RCC_enable_GPIO_x_clock(port)	RCC_set_IOPxEN(port, 1)
#define RCC_disable_GPIO_x_clock(port)	RCC_set_IOPxEN(port, 0)

/*
Bit 1 Reserved, always read as 0.
*/

/*
Bit 0 AFIOEN: Alternate function IO clock enable   	AFIO使能
Set and cleared by software.
0: Alternate Function IO clock disabled
1: Alternate Function IO clock enabled
*/
void RCC_set_AFIOEN(U8 e_d);
#define RCC_enable_AFIO_clock()		RCC_set_AFIOEN(1)
#define RCC_disable_AFIO_clock()	RCC_set_AFIOEN(0)



/************************APB1 peripheral clock enable register (RCC_APB1ENR)**************/

/*
APB1 peripheral clock enable register (RCC_APB1ENR)	  APB1外设总线使能
Address: 0x1C
Reset value: 0x0000 0000
Access: word, half-word and byte access
No wait state, except if the access occurs while an access to a peripheral on APB1 domain 
is on going. In this case, wait states are inserted until this access to APB1 peripheral is 
finished.
Note:
When the peripheral clock is not active, the peripheral register values may not be readable 
by software and the returned value is always 0x0.
*/

/*
Bit 29 DACEN: DAC interface clock enable	 	DAC使能
Set and cleared by software.
0: DAC interface clock disabled
1: DAC interface clock enable
*/
void RCC_set_DACEN(U8 e_d);
#define RCC_enable_DAC_clock()		RCC_set_DACEN(1)
#define RCC_disable_DAC_clock()		RCC_set_DACEN(0)

/*
Bit 28 PWREN: Power interface clock enable	   	PWR使能
Set and cleared by software.
0: Power interface clock disabled
1: Power interface clock enable
*/
void RCC_set_PWREN(U8 e_d) ;
#define RCC_enable_PWR_clock()		RCC_set_PWREN(1)
#define RCC_disable_PWR_clock()		RCC_set_PWREN(0)


/*
Bit 27 BKPEN: Backup interface clock enable		BKP使能
Set and cleared by software.
0: Backup interface clock disabled
1: Backup interface clock enabled
*/
void RCC_set_BKPEN(U8 e_d);
#define RCC_enable_BKP_clock()		RCC_set_BKPEN(1)
#define RCC_disable_BKP_clock()		RCC_set_BKPEN(0)

#define RCC_enable_backup_clock()		RCC_set_BKPEN(1)
#define RCC_disable_backup_clock()		RCC_set_BKPEN(0)

/*
Bit 26 Reserved, always read as 0.
*/

/*
Bit 25 CANEN: CAN clock enable			 		CAN使能
Set and cleared by software.
0: CAN clock disabled
1: CAN clock enabled
*/
void RCC_set_CANEN(U8 e_d);
#define RCC_enable_CAN_clock()		RCC_set_CANEN(1)
#define RCC_disable_CAN_clock()		RCC_set_CANEN(0)
/*
Bit 24 Reserved, always read as 0.
*/

/*
Bit 23 USBEN: USB clock enable			  		USB使能
Set and cleared by software.
0: USB clock disabled
1: USB clock enabled
*/
void RCC_set_USBEN(U8 e_d);
#define RCC_enable_USB_clock()		RCC_set_USBEN(1)
#define RCC_disable_USB_clock()		RCC_set_USBEN(0)

/*
Bit 22 I2C2EN: I2C 2 clock enable		  		I2C2使能
Set and cleared by software.
0: I2C 2 clock disabled
1: I2C 2 clock enabled
*/
void RCC_set_I2C2EN(U8 e_d);
#define RCC_enable_I2C2_clock()		RCC_set_I2C2EN(1)
#define RCC_disable_I2C2_clock()	RCC_set_I2C2EN(0)

/*
Bit 21 I2C1EN: I2C 1 clock enable		  		I2C1使能
Set and cleared by software.
0: I2C 1 clock disabled
1: I2C 1 clock enabled
*/
void RCC_set_I2C1EN(U8 e_d);
#define RCC_enable_I2C1_clock()		RCC_set_I2C1EN(1)
#define RCC_disable_I2C1_clock()	RCC_set_I2C1EN(0)

/*
Bit 20 UART5EN: USART 5 clock enable	   		UART5使能
Set and cleared by software.
0: USART 5 clock disabled
1: USART 5 clock enabled
*/
void RCC_set_UART5EN(U8 e_d);
#define RCC_enable_UART5_clock()		RCC_set_UART5EN(1)
#define RCC_disable_UART5_clock()		RCC_set_UART5EN(0)

/*
Bit 19 UART4EN: USART 4 clock enable			UART4使能
Set and cleared by software.
0: USART 4 clock disabled
1: USART 4 clock enabled
*/
void RCC_set_UART4EN(U8 e_d) ;
#define RCC_enable_UART4_clock()		RCC_set_UART4EN(1)
#define RCC_disable_UART4_clock()		RCC_set_UART4EN(0)


/*
Bit 18 USART3EN: USART 3 clock enable			USART3使能
Set and cleared by software.
0: USART 3 clock disabled
1: USART 3 clock enabled
*/
void RCC_set_USART3EN(U8 e_d);
#define RCC_enable_USART3_clock()		RCC_set_USART3EN(1)
#define RCC_disable_USART3_clock()		RCC_set_USART3EN(0)

/*
Bit 17 USART2EN: USART 2 clock enable			USART2使能
Set and cleared by software.
0: USART 2 clock disabled
1: USART 2 clock enabled
*/
void RCC_set_USART2EN(U8 e_d);
#define RCC_enable_USART2_clock()		RCC_set_USART2EN(1)
#define RCC_disable_USART2_clock()		RCC_set_USART2EN(0)

/*
Bits 16 Reserved, always read as 0.
*/
/*
Bit 15 SPI3EN: SPI 3 clock enable			 	SPI3使能
Set and cleared by software.
0: SPI 3 clock disabled
1: SPI 3 clock enabled
*/
void RCC_set_SPI3EN(U8 e_d);
#define RCC_enable_SPI3_clock()		RCC_set_SPI3EN(1)
#define RCC_disable_SPI3_clock()	RCC_set_SPI3EN(0)

/*
Bit 14 SPI2EN: SPI 2 clock enable		   		SPI2使能
Set and cleared by software.
0: SPI 2 clock disabled
1: SPI 2 clock enabled
*/
void RCC_set_SPI2EN(U8 e_d);
#define RCC_enable_SPI2_clock()		RCC_set_SPI2EN(1)
#define RCC_disable_SPI2_clock()	RCC_set_SPI2EN(0)

/*
Bits 13:12 Reserved, always read as 0.
*/

/*
Bit 11 WWDGEN: Window watchdog clock enable		WWDG使能
Set and cleared by software.
0: Window watchdog clock disabled
1: Window watchdog clock enabled
*/
void RCC_set_WWDGEN(U8 e_d);
#define RCC_enable_WWDG_clock()		RCC_set_WWDGEN(1)
#define RCC_disable_WWDG_clock()		RCC_set_WWDGEN(0)

#define RCC_enable_window_watchdog_clock()		RCC_set_WWDGEN(1)
#define RCC_disable_window_watchdog_clock()		RCC_set_WWDGEN(0)

/*
Bits 10:9 Reserved, always read as 0.
*/

/*
Bit 8 TIM14EN: TIM14 timer clock enable		  	TIM14使能
Set and cleared by software.
0: TIM14 clock disabled
1: TIM14 clock enabled
*/
void RCC_set_TIM14EN(U8 e_d);
#define RCC_enable_TIM14_clock()		RCC_set_TIM14EN(1)
#define RCC_disable_TIM14_clock()		RCC_set_TIM14EN(0)

/*
Bit 7 TIM13EN: TIM13 timer clock enable		   	TIM13使能
Set and cleared by software.
0: TIM13 clock disabled
1: TIM13 clock enabled
*/
void RCC_set_TIM13EN(U8 e_d);
#define RCC_enable_TIM13_clock()		RCC_set_TIM13EN(1)
#define RCC_disable_TIM13_clock()		RCC_set_TIM13EN(0)

/*
Bit 6 TIM12EN: TIM12 timer clock enable		  	TIM12使能
Set and cleared by software.
0: TIM12 clock disabled
1: TIM12 clock enabled
*/
void RCC_set_TIM12EN(U8 e_d);
#define RCC_enable_TIM12_clock()		RCC_set_TIM12EN(1)
#define RCC_disable_TIM12_clock()		RCC_set_TIM12EN(0)

/*
Bit 5 TIM7EN: TIM7 timer clock enable		 	TIM7使能
Set and cleared by software.
0: TIM7 clock disabled
1: TIM7 clock enabled
*/
void RCC_set_TIM7EN(U8 e_d);
#define RCC_enable_TIM7_clock()		RCC_set_TIM7EN(1)
#define RCC_disable_TIM7_clock()		RCC_set_TIM7EN(0)

/*
Bit 4 TIM6EN: TIM6 timer clock enable		  	TIM6使能
Set and cleared by software.
0: TIM6 clock disabled
1: TIM6 clock enabled
*/
void RCC_set_TIM6EN(U8 e_d);
#define RCC_enable_TIM6_clock()		RCC_set_TIM6EN(1)
#define RCC_disable_TIM6_clock()		RCC_set_TIM6EN(0)

/*
Bit 3 TIM5EN: TIM5 timer clock enable		 	TIM5使能
Set and cleared by software.
0: TIM5 clock disabled
1: TIM5 clock enabled
*/
void RCC_set_TIM5EN(U8 e_d);
#define RCC_enable_TIM5_clock()		RCC_set_TIM5EN(1)
#define RCC_disable_TIM5_clock()		RCC_set_TIM5EN(0)

/*
Bit 2 TIM4EN: TIM4 timer clock enable			TIM4使能
Set and cleared by software.
0: TIM4 clock disabled
1: TIM4 clock enabled
*/
void RCC_set_TIM4EN(U8 e_d);
#define RCC_enable_TIM4_clock()		RCC_set_TIM4EN(1)
#define RCC_disable_TIM4_clock()		RCC_set_TIM4EN(0)

/*
Bit 1 TIM3EN: TIM3 timer clock enable		   	TIM3使能
Set and cleared by software.
0: TIM3 clock disabled
1: TIM3 clock enabled
*/
void RCC_set_TIM3EN(U8 e_d);
#define RCC_enable_TIM3_clock()		RCC_set_TIM3EN(1)
#define RCC_disable_TIM3_clock()		RCC_set_TIM3EN(0)

/*
Bit 0 TIM2EN: TIM2 timer clock enable			TIM2使能
Set and cleared by software.
0: TIM2 clock disabled
1: TIM2 clock enabled
*/
void RCC_set_TIM2EN(U8 e_d);
#define RCC_enable_TIM2_clock()		RCC_set_TIM2EN(1)
#define RCC_disable_TIM2_clock()		RCC_set_TIM2EN(0)



//***********************************Backup domain control register (RCC_BDCR)*********************//
/*
Backup domain control register (RCC_BDCR) 			备份域中RCC控制寄存器
Address offset: 0x20
Reset value: 0x0000 0000, reset by Backup domain Reset.
Access: 0 ? wait state ? 3, word, half-word and byte access
Wait states are inserted in case of successive accesses to this register.
Note:
The LSEON, LSEBYP, RTCSEL and RTCEN bits of the Backup domain control register 
(RCC_BDCR) are in the Backup domain. As a result, after Reset, these bits are write-
protected and the DBP bit in the Power control register (PWR_CR) has to be set before 
these can be modified. Refer to Section 5 on page 73 for further information. These bits are 
only reset after a Backup domain Reset (see Section 6.1.3: Backup domain reset). Any 
internal or external Reset will not have any effect on these bits.
*/

/*
Bits 31:17 Reserved, always read as 0.
*/

/*
Bit 16 BDRST: Backup domain software reset		RCC的备份域控制寄存器复位
Set and cleared by software.
0: Reset not activated
1: Resets the entire Backup domain
*/
void RCC_set_BDRST(void);
#define RCC_reset_BD()				RCC_set_BDRST()
#define RCC_reset_backup_domain()	RCC_set_BDRST()

/*
Bit 15 RTCEN: RTC clock enable					RTC使能
Set and cleared by software.
0: RTC clock disabled
1: RTC clock enabled
*/
void RCC_set_RTCEN(U8 e_d);
#define RCC_enable_RTC()			RCC_set_RTCEN(1)
#define RCC_disable_RCT()			RCC_set_RTCEN(0)

/*
Bits 14:10
Reserved, always read as 0.						
*/

/*
Bits 9:8 RTCSEL[1:0]: RTC clock source selection	RTC时钟源选择
Set by software to select the clock source for the RTC. Once the RTC clock source has been 
selected, it cannot be changed anymore unless the Backup domain is reset. The BDRST bit 
can be used to reset them.
00: No clock
01: LSE oscillator clock used as RTC clock10: LSI oscillator clock used as RTC clock
11: HSE oscillator clock divided by 128 used as RTC clock
*/
void RCC_set_RTCSEL(U8 s);

#define RCC_set_RTCSEL_no_clock()	RCC_set_RTCSEL(0)
#define	RCC_set_RTCSEL_LSE()		RCC_set_RTCSEL(1)
#define RCC_set_RTCSEL_HSE()		RCC_set_RTCSEL(3)

#define RCC_select_RTC_source_none()	RCC_set_RTCSEL(0)	
#define RCC_select_RTC_source_LSE()		RCC_set_RTCSEL(1)
#define RCC_select_RTC_source_HSE_128()		RCC_set_RTCSEL(3)


/*
Bits 7:3 Reserved, always read as 0.
*/

/*
Bit 2 LSEBYP: External low-speed oscillator bypass	  LSE旁路
Set and cleared by software to bypass oscillator in debug mode. This bit can be written only 
when the external 32 kHz oscillator is disabled.
0: LSE oscillator not bypassed
1: LSE oscillator bypassed
*/
void RCC_set_LSEBYP(U8 l);

#define RCC_bypass_LSE()	RCC_set_LSEBYP(1)
#define RCC_no_bypass_LSE()	RCC_set_LSEBYP(0)


/*
Bit 1 LSERDY: External low-speed oscillator ready	  LSE是否准备好
Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After 
the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock 
cycles.
0: External 32 kHz oscillator not ready
1: External 32 kHz oscillator ready
*/
U8 RCC_get_LSERDY(void) ;

#define RCC_is_LSE_ready()	RCC_get_LSERDY()


/*
Bit 0 LSEON: External low-speed oscillator enable	  LSE使能
Set and cleared by software.
0: External 32 kHz oscillator OFF
1: External 32 kHz oscillator ON
*/
void RCC_set_LSEON(U8 e_d);

#define RCC_enable_LSE()	RCC_set_LSEON(1)
#define RCC_disable_LSE()	RCC_set_LSEON(0)


/***********************************Control/status register (RCC_CSR)*********************/
/*
Control/status register (RCC_CSR)			 	复位标志
Address: 0x24
Reset value: 0x0C00 0000, reset by system Reset, except reset flags by power Reset only.
Access: 0 ? wait state ? 3, word, half-word and byte access
Wait states are inserted in case of successive accesses to this register.
*/

/*
Bit 31 LPWRRSTF: Low-power reset flag	   		低电压复位标志
Set by hardware when a Low-power management reset occurs.
Cleared by writing to the RMVF bit.
0: No Low-power management reset occurred
1: Low-power management reset occurred
For further information on Low-power management reset, refer to Low-power management 
reset.
*/
U8	RCC_get_LPWRRSTF(void);

#define RCC_is_reseted_by_LPWR()	RCC_get_LPWRRSTF()
#define RCC_is_reseted_by_low_power()	RCC_get_LPWRRSTF()

/*
Bit 30 WWDGRSTF: Window watchdog reset flag		   看门狗复位标志
Set by hardware when a window watchdog reset occurs.
Cleared by writing to the RMVF bit.
0: No window watchdog reset occurred
1: Window watchdog reset occurred
*/
U8	RCC_get_WWDGRSTF(void);

#define RCC_is_reseted_by_WWDG()	RCC_get_WWDGRSTF()
#define RCC_is_reseted_by_window_dog()	RCC_get_WWDGRSTF()

/*
Bit 29 IWDGRSTF: Independent watchdog reset flag  独立看门狗复位标志
Set by hardware when an independent watchdog reset from VDD domain occurs.
Cleared by writing to the RMVF bit.
0: No watchdog reset occurred
1: Watchdog reset occurred
*/
U8	RCC_get_IWDGRSTF(void);

#define RCC_is_reseted_by_IWDG()	RCC_get_IWDGRSTF()
#define RCC_is_reseted_by_independent_watchdog()	RCC_get_IWDGRSTF()


/*
Bit 28 SFTRSTF: Software reset flag				  软件复位标志
Set by hardware when a software reset occurs.
Cleared by writing to the RMVF bit.
0: No software reset occurred
1: Software reset occurred
*/
U8	RCC_get_SFTRSTF(void);

#define RCC_is_reseted_by_SFT()		RCC_get_SFTRSTF()

/*
Bit 27 PORRSTF: POR/PDR reset flag				  POR/PDR上电掉电复位标志
Set by hardware when a POR/PDR reset occurs.
Cleared by writing to the RMVF bit.
0: No POR/PDR reset occurred
1: POR/PDR reset occurred
*/
U8	RCC_get_PORRSTF(void);

#define RCC_is_reseted_by_POR_PDR()	RCC_get_PORRSTF()
#define RCC_is_reseted_by_power_on_power_down()	RCC_get_PORRSTF()
#define RCC_is_reseted_by_power_on()	RCC_get_PORRSTF()
#define RCC_is_reseted_by_power_down()	RCC_get_PORRSTF()


/*
Bit 26 PINRSTF: PIN reset flag					   外部引脚复位标志
Set by hardware when a reset from the NRST pin occurs.
Cleared by writing to the RMVF bit.
0: No reset from NRST pin occurred
1: Reset from NRST pin occurred
*/
U8	RCC_get_PINRSTF(void);

#define RCC_is_reseted_by_PIN()		RCC_get_PINRSTF()
#define RCC_is_reseted_by_NRST()	RCC_get_PINRSTF()


/*
Bit 25
Reserved, always read as 0.
*/

/*
Bit 24 RMVF: Remove reset flag					 移除所有复位标志
Set by software to clear the reset flags.
0: No effect
1: Clear the reset flags
*/
void RCC_set_RMVF(void);

#define RCC_clear_reset_flag()	RCC_set_RMVF()

/*
Bits 23:2
Reserved, always read as 0.
*/

/*
Bit 1 LSIRDY: Internal low-speed oscillator ready	  LSI准备就绪
Set and cleared by hardware to indicate when the internal RC 40 kHz oscillator is stable. 
After the LSION bit is cleared, LSIRDY goes low after 3 internal RC 40 kHz oscillator clock 
cycles.
0: Internal RC 40 kHz oscillator not ready
1: Internal RC 40 kHz oscillator ready
*/
U8	RCC_get_LSIRDY(void);

#define RCC_is_LSI_ready()	RCC_get_LSIRDY()

/*
Bit 0 LSION: Internal low-speed oscillator enable	  LSI使能
Set and cleared by software.
0: Internal RC 40 kHz oscillator OFF
1: Internal RC 40 kHz oscillator ON
*/
void RCC_set_LSION(U8 e_d);

#define RCC_enable_LSI()	RCC_set_LSION()
#define RCC_disable_LSI()	RCC_set_LSION(0)




#endif

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

#ifndef __SPI
#define __SPI


#include "com.h"

//SPI1 Register
#define __SPI1_CR1 		SPI1_BASE + 0x00
#define __SPI1_CR2		SPI1_BASE + 0x04
#define __SPI1_SR		SPI1_BASE + 0x08
#define __SPI1_DR		SPI1_BASE + 0x0C
#define __SPI1_CRCPR	SPI1_BASE + 0x10
#define __SPI1_RXCRCR	SPI1_BASE + 0x14
#define __SPI1_TXCRCR	SPI1_BASE + 0x18
#define __SPI1_I2SCFGR	SPI1_BASE + 0x1C
#define __SPI1_I2SPR	SPI1_BASE + 0x20

#define _SPI1_CR1		ADR(__SPI1_CR1)
#define _SPI1_CR2		ADR(__SPI1_CR2)
#define _SPI1_SR       	ADR(__SPI1_SR)
#define _SPI1_DR		ADR(__SPI1_DR)
#define _SPI1_CRCPR		ADR(__SPI1_CRCPR)
#define _SPI1_RXCRCR   	ADR(__SPI1_RXCRCR)
#define _SPI1_TXCRCR	ADR(__SPI1_TXCRCR)
#define _SPI1_I2SCFGR  	ADR(__SPI1_I2SCFGR)
#define _SPI1_I2SPR		ADR(__SPI1_I2SPR)

#define SPI1_CR1		VAL(__SPI1_CR1)
#define SPI1_CR2		VAL(__SPI1_CR2)
#define SPI1_SR       	VAL(__SPI1_SR)
#define SPI1_DR			VAL(__SPI1_DR)
#define SPI1_CRCPR		VAL(__SPI1_CRCPR)
#define SPI1_RXCRCR   	VAL(__SPI1_RXCRCR)
#define SPI1_TXCRCR		VAL(__SPI1_TXCRCR)
#define SPI1_I2SCFGR  	VAL(__SPI1_I2SCFGR)
#define SPI1_I2SPR		VAL(__SPI1_I2SPR)

//SPi2 Register
#define __SPI2_CR1 		SPI2_BASE + 0x00
#define __SPI2_CR2		SPI2_BASE + 0x04
#define __SPI2_SR		SPI2_BASE + 0x08
#define __SPI2_DR		SPI2_BASE + 0x0C
#define __SPI2_CRCPR	SPI2_BASE + 0x10
#define __SPI2_RXCRCR	SPI2_BASE + 0x14
#define __SPI2_TXCRCR	SPI2_BASE + 0x18
#define __SPI2_I2SCFGR	SPI2_BASE + 0x1C
#define __SPI2_I2SPR	SPI2_BASE + 0x20

#define _SPI2_CR1		ADR(__SPI2_CR1)
#define _SPI2_CR2		ADR(__SPI2_CR2)
#define _SPI2_SR       	ADR(__SPI2_SR)
#define _SPI2_DR		ADR(__SPI2_DR)
#define _SPI2_CRCPR		ADR(__SPI2_CRCPR)
#define _SPI2_RXCRCR   	ADR(__SPI2_RXCRCR)
#define _SPI2_TXCRCR	ADR(__SPI2_TXCRCR)
#define _SPI2_I2SCFGR  	ADR(__SPI2_I2SCFGR)
#define _SPI2_I2SPR		ADR(__SPI2_I2SPR)

#define SPI2_CR1		VAL(__SPI2_CR1)
#define SPI2_CR2		VAL(__SPI2_CR2)
#define SPI2_SR       	VAL(__SPI2_SR)
#define SPI2_DR			VAL(__SPI2_DR)
#define SPI2_CRCPR		VAL(__SPI2_CRCPR)
#define SPI2_RXCRCR   	VAL(__SPI2_RXCRCR)
#define SPI2_TXCRCR		VAL(__SPI2_TXCRCR)
#define SPI2_I2SCFGR  	VAL(__SPI2_I2SCFGR)
#define SPI2_I2SPR		VAL(__SPI2_I2SPR)




//*******SPI control register 1 (SPI_CR1) (not used in I2S mode)******//
/*
SPI控制寄存器1
Address offset: 0x00
Reset value: 0x0000)
*/
/*
通信线数目选择(双线双向和单线双向)
Bit 15 BIDIMODE: Bidirectional data mode enable
0: 2-line unidirectional data mode selected
1: 1-line bidirectional data mode selected
Note: Not used in I2S mode
*/
void SPI1_set_BIDIMODE(U8 _2_1);

#define SPI1_set_conmunicate_with_2_lines()	SPI1_set_BIDIMODE(0)
#define SPI1_set_conmunicate_with_1_line() SPI1_set_BIDIMODE(1)

void SPI2_set_BIDIMODE(U8 _2_1);

#define SPI2_set_conmunicate_with_2_lines()	SPI2_set_BIDIMODE(0)
#define SPI2_set_conmunicate_with_1_line() SPI2_set_BIDIMODE(1)

/*
在单线时选择数据传输方向
Bit 14 BIDIOE: Output enable in bidirectional mode
This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
0: Output disabled (receive-only mode) 
1: Output enabled (transmit-only mode)
Note: In master mode, the MOSI pin is used and in slave mode, the MISO pin is used.
Not used in I2S mode
*/
void SPI1_set_BIDIOE(U8 e_d);

#define SPI1_set_receive_only_when_1_line()		SPI1_set_BIDIOE(0)
#define SPI1_set_transmit_only_when_1_line()    SPI1_set_BIDIOE(1)

void SPI2_set_BIDIOE(U8 e_d);

#define SPI2_set_receive_only_when_1_line()		SPI2_set_BIDIOE(0)
#define SPI2_set_transmit_only_when_1_line()    SPI2_set_BIDIOE(1)

/*
硬件CRC计算使能
Bit 13 CRCEN: Hardware CRC calculation enable
0: CRC calculation disabled
1: CRC calculation Enabled
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation
Not used in I2S mode
*/
void SPI1_set_CRCEN(U8 e_d);

#define SPI1_enable_CRC()	SPI1_set_CRCEN(1)	
#define SPI1_disable_CRC()  SPI1_set_CRCEN(0)

void SPI2_set_CRCEN(U8 e_d);

#define SPI2_enable_CRC()	SPI2_set_CRCEN(1)	
#define SPI2_disable_CRC()  SPI2_set_CRCEN(0)



/*
下一个将要传送的帧是CRC计算的结果还是发送缓冲器中的数据
Bit 12 CRCNEXT: Transmit CRC next
0: Next transmit value is from Tx buffer
1: Next transmit value is from Tx CRC register
Note: This bit has to be written as soon as the last data is written into the SPI_DR register.
Not used in I2S mode
*/
void SPI1_set_CRCNEXT(U8 n);

#define SPI1_set_next_value_frome_CRC_register()	SPI1_set_CRCNEXT(1)	

void SPI2_set_CRCNEXT(U8 n);

#define SPI2_set_next_value_frome_CRC_register()	SPI2_set_CRCNEXT(1)	


/*
数据帧长度选择
Bit 11 DFF: Data frame format
0: 8-bit data frame format is selected for transmission/reception
1: 16-bit data frame format is selected for transmission/reception
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation
Not used in I2S mode
*/
void SPI1_set_DFF(U8 _8_16)	;

#define SPI1_set_data_length_8_bit()	SPI1_set_DFF(0)	
#define SPI1_set_data_length_16_bit()   SPI1_set_DFF(1)

void SPI2_set_DFF(U8 _8_16)	;

#define SPI2_set_data_length_8_bit()	SPI2_set_DFF(0)	
#define SPI2_set_data_length_16_bit()   SPI2_set_DFF(1)

/*
在双线下使能只读模式
Bit 10 RXONLY: Receive only
This bit combined with the BIDImode bit selects the direction of transfer in 2-line 
unidirectional mode. This bit is also useful in a multislave system in which this particular 
slave is not accessed, the output from the accessed slave is not corrupted.
0: Full duplex (Transmit and receive)
1: Output disabled (Receive-only mode)
Note: Not used in I2S mode
*/
void SPI1_set_RXONLY(U8 e_d);

#define SPI1_set_full_duplex_when_2_lines()	SPI1_set_RXONLY(0)	
#define SPI1_set_receive_only_when_2_lines() SPI1_set_RXONLY(1)

void SPI2_set_RXONLY(U8 e_d);

#define SPI2_set_full_duplex_when_2_lines()	SPI2_set_RXONLY(0)	
#define SPI2_set_receive_only_when_2_lines() SPI2_set_RXONLY(1)

/*
软件从模式管理使能(使能该位后，NSS引脚的输入由软件设置(SSI位设置))
Bit 9 SSM: Software slave management
When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
0: Software slave management disabled
1: Software slave management enabled
Note: Not used in I2S mode
*/
void SPI1_set_SSM(U8 e_d);

#define SPI1_enable_software_slave_management()		SPI1_set_SSM(1)
#define SPI1_disable_software_slave_management()    SPI1_set_SSM(0)

void SPI2_set_SSM(U8 e_d);

#define SPI2_enable_software_slave_management()		SPI2_set_SSM(1)
#define SPI2_disable_software_slave_management()    SPI2_set_SSM(0)

/*
当软件从模式管理使能后，该位用来设置NSS引脚的输入
Bit 8 SSI: Internal slave select
This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the 
NSS pin and the IO value of the NSS pin is ignored.
Note: Not used in I2S mode
*/
void SPI1_set_SSI(U8 v);

#define SPI1_set_NSS_high()		SPI1_set_SSI(1)	//对于非多主模式，此位直接拉高就行
#define SPI1_set_NSS_low()    	SPI1_set_SSI(0) //对于主模式来说，此位不能拉低   对于从模式，就必须拉低了

#define SPI1_set_NSS_1()		SPI1_set_SSI(1)
#define SPI1_set_NSS_0()    	SPI1_set_SSI(0)

void SPI2_set_SSI(U8 v);

#define SPI2_set_NSS_high()		SPI2_set_SSI(1)	//对于非多主模式，此位直接拉高就行
#define SPI2_set_NSS_low()    	SPI2_set_SSI(0) //对于主模式来说，此位不能拉低   对于从模式，就必须拉低了

#define SPI2_set_NSS_1()		SPI2_set_SSI(1)
#define SPI2_set_NSS_0()    	SPI2_set_SSI(0)

/*
选择数据的传输方向 （LSB or MSB）
Bit 7 LSBFIRST: Frame format
0: MSB transmitted first
1: LSB transmitted first
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_LSBFIRST(U8 s);

#define SPI1_set_transmit_MSB_first()  SPI1_set_LSBFIRST(0)
#define SPI1_set_transmit_LSB_first()  SPI1_set_LSBFIRST(1)

void SPI2_set_LSBFIRST(U8 s);

#define SPI2_set_transmit_MSB_first()  SPI2_set_LSBFIRST(0)
#define SPI2_set_transmit_LSB_first()  SPI2_set_LSBFIRST(1)

/*
使能 除能 SPI
Bit 6 SPE: SPI enable
0: Peripheral disabled
1: Peripheral enabled
Note: 1- Not used in I2S mode.
Note: 2- When disabling the SPI, follow the procedure described in Section 24.3.8: Disabling the 
SPI.
*/
void SPI1_set_SPE(U8 e_d);

#define SPI1_enable_SPI()	SPI1_set_SPE(1)
#define SPI1_disable_SPI()  SPI1_set_SPE(0)

void SPI2_set_SPE(U8 e_d);

#define SPI2_enable_SPI()	SPI2_set_SPE(1)
#define SPI2_disable_SPI()  SPI2_set_SPE(0)

/*
设置SPI分频器对APB2总线时钟的分频系数
Bits 5:3 BR[2:0]: Baud rate control
000: fPCLK/2
001: fPCLK/4
010: fPCLK/8
011: fPCLK/16
100: fPCLK/32
101: fPCLK/64
110: fPCLK/128
111: fPCLK/256
Note: These bits should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_BR(U8 b);


#define SPI1_clock_division_is_2()		SPI1_set_BR(0)
#define SPI1_clock_division_is_4()		SPI1_set_BR(1)
#define SPI1_clock_division_is_8()		SPI1_set_BR(2)
#define SPI1_clock_division_is_16()		SPI1_set_BR(3)
#define SPI1_clock_division_is_32()		SPI1_set_BR(4)
#define SPI1_clock_division_is_64()		SPI1_set_BR(5)
#define SPI1_clock_division_is_128()	SPI1_set_BR(6)
#define SPI1_clock_division_is_256()	SPI1_set_BR(7)

void SPI2_set_BR(U8 b);


#define SPI2_clock_division_is_2()		SPI2_set_BR(0)
#define SPI2_clock_division_is_4()		SPI2_set_BR(1)
#define SPI2_clock_division_is_8()		SPI2_set_BR(2)
#define SPI2_clock_division_is_16()		SPI2_set_BR(3)
#define SPI2_clock_division_is_32()		SPI2_set_BR(4)
#define SPI2_clock_division_is_64()		SPI2_set_BR(5)
#define SPI2_clock_division_is_128()	SPI2_set_BR(6)
#define SPI2_clock_division_is_256()	SPI2_set_BR(7)



/*
主模式 从模式 选择
Bit 2 MSTR: Master selection 
0: Slave configuration
1: Master configuration
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_MSTR(U8 sel);

#define SPI1_set_master_mode()	SPI1_set_MSTR(1)
#define SPI1_set_slave_mode()   SPI1_set_MSTR(0)

void SPI2_set_MSTR(U8 sel);

#define SPI2_set_master_mode()	SPI2_set_MSTR(1)
#define SPI2_set_slave_mode()   SPI2_set_MSTR(0)

/*
时钟在空闲时的极性
Bit1 CPOL: Clock polarity 
0: CK to 0 when idle
1: CK to 1 when idle
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_CPOL(U8 p);

#define SPI1_clock_is_high_when_idle()	SPI1_set_CPOL(1)
#define SPI1_clock_is_low_when_idle()   SPI1_set_CPOL(0)

void SPI2_set_CPOL(U8 p);

#define SPI2_clock_is_high_when_idle()	SPI2_set_CPOL(1)
#define SPI2_clock_is_low_when_idle()   SPI2_set_CPOL(0)


/*
时钟的相位 当为一时，在时钟沿开始传输数据否则在第一个时钟沿传输数据(上下沿)
Bit 0 CPHA: Clock phase 
0: The first clock transition is the first data capture edge
1: The second clock transition is the first data capture edge
Note: This bit should not be changed when communication is ongoing.
Note: Not used in I2S mode
*/
void SPI1_set_CPHA(U8 f_s);

#define SPI1_capture_at_first_edge()	SPI1_set_CPHA(0)
#define SPI1_capture_at_second_edge()   SPI1_set_CPHA(1)

void SPI2_set_CPHA(U8 f_s);

#define SPI2_capture_at_first_edge()	SPI2_set_CPHA(0)
#define SPI2_capture_at_second_edge()   SPI2_set_CPHA(1)

//************SPI control register 2 (SPI_CR2)**********************//

/*
SPI控制器2  (中断相关)
SPI control register 2 (SPI_CR2)
Address offset: 0x04
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved. Forced to 0 by hardware.
*/

/*
当发送寄存器空的时候产生中断
Bit 7 TXEIE: Tx buffer empty interrupt enable
0: TXE interrupt masked 
1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
*/
void SPI1_set_TXEIE(U8 e_d);

#define SPI1_enable_interrupt_at_TX_buffer_empty()	SPI1_set_TXEIE(1)
#define SPI1_disable_interrupt_at_TX_buffer_empty() SPI1_set_TXEIE(0)

#define SPI1_enable_interrupt_at_transmit_over()	SPI1_set_TXEIE(1)
#define SPI1_disable_interrupt_at_transmit_over()   SPI1_set_TXEIE(0)

void SPI2_set_TXEIE(U8 e_d);

#define SPI2_enable_interrupt_at_TX_buffer_empty()	SPI2_set_TXEIE(1)
#define SPI2_disable_interrupt_at_TX_buffer_empty() SPI2_set_TXEIE(0)

#define SPI2_enable_interrupt_at_transmit_over()	SPI2_set_TXEIE(1)
#define SPI2_disable_interrupt_at_transmit_over()   SPI2_set_TXEIE(0)

/*
当接受寄存器非空时产生中断
Bit 6 RXNEIE: RX buffer not empty interrupt enable
0: RXNE interrupt masked 
1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is 
set.
*/
void SPI1_set_RXNEIE(U8 e_d);

#define SPI1_enable_interrupt_at_RX_buffer_not_empty()  SPI1_set_RXNEIE(1)
#define SPI1_disable_interrupt_at_RX_buffer_not_empty() SPI1_set_RXNEIE(0)

#define SPI1_enable_interrupt_at_receive_over()			SPI1_set_RXNEIE(1)	
#define SPI1_disable_interrupt_at_receive_over()	 	SPI1_set_RXNEIE(0)

void SPI1_set_RXNEIE(U8 e_d);

#define SPI2_enable_interrupt_at_RX_buffer_not_empty()  SPI2_set_RXNEIE(1)
#define SPI2_disable_interrupt_at_RX_buffer_not_empty() SPI2_set_RXNEIE(0)

#define SPI2_enable_interrupt_at_receive_over()			SPI2_set_RXNEIE(1)	
#define SPI2_disable_interrupt_at_receive_over()	 	SPI2_set_RXNEIE(0)

/*
Bit 5 ERRIE: Error interrupt enable
This bit controls the generation of an interrupt when an error condition occurs (CRCERR, 
OVR, MODF in SPI mode and UDR, OVR in I2S mode).
0: Error interrupt is masked
1: Error interrupt is enabled. 
*/
void SPI1_set_ERRIE(U8 e_d);

#define SPI1_enable_interrupt_at_error()	SPI1_set_ERRIE(1)
#define SPI1_disable_interrupt_at_error()   SPI1_set_ERRIE(0)

void SPI2_set_ERRIE(U8 e_d);

#define SPI2_enable_interrupt_at_error()	SPI2_set_ERRIE(1)
#define SPI2_disable_interrupt_at_error()   SPI2_set_ERRIE(0)
/*
Bits 4:3 Reserved. Forced to 0 by hardware.
*/

/*
在主模式下将NSS引脚配置成输出，以控制所有的从设备
Bit 2 SSOE: SS output enable
0: SS output is disabled in master mode and the cell can work in multimaster configuration
1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
in a multimaster environment.
Note: Not used in I2S mode
*/
void SPI1_set_SSOE(U8 e_d);

#define SPI1_set_SS_input_mode()	SPI1_set_SSOE(0)	
#define SPI1_set_SS_output_mode()   SPI1_set_SSOE(1)

void SPI2_set_SSOE(U8 e_d);

#define SPI2_set_SS_input_mode()	SPI2_set_SSOE(0)	
#define SPI2_set_SS_output_mode()   SPI2_set_SSOE(1)


/*
发送DMA使能(DMA会在发送一个帧后从指定的地方自动发送下一帧，而不需要CPU参与)
对于发送CRC校验帧则不需要手动设置CRCNEXT位，在所有给DMA指定的数据传输完之后，DMA自动发送CRC校验帧。
Bit 1 TXDMAEN: Tx buffer DMA enable
When this bit is set, the DMA request is made whenever the TXE flag is set.
0: Tx buffer DMA disabled
1: Tx buffer DMA enabled
*/
void SPI1_set_TXDMAEN(U8 e_d);

#define SPI1_enable_transmit_DMA()	SPI1_set_TXDMAEN(1)
#define SPI1_disable_tansmit_DMA()  SPI1_set_TXDMAEN(0)

void SPI2_set_TXDMAEN(U8 e_d);

#define SPI2_enable_transmit_DMA()	SPI2_set_TXDMAEN(1)
#define SPI2_disable_tansmit_DMA()  SPI2_set_TXDMAEN(0)


/*
接受DMA使能(DMA会在接收到一个数据后自动将该数据存到提前指定的地方，而不需要CPU参与)
Bit 0 RXDMAEN: Rx buffer DMA enable
When this bit is set, the DMA request is made whenever the RXNE flag is set.
0: Rx buffer DMA disabled
1: Rx buffer DMA enabled
*/
void SPI1_set_RXDMAEN(U8 e_d);

#define SPI1_enable_receive_DMA()	SPI1_set_RXDMAEN(1)
#define SPI1_disable_receive_DMA()  SPI1_set_RXDMAEN(0)

void SPI2_set_RXDMAEN(U8 e_d);

#define SPI2_enable_receive_DMA()	SPI2_set_RXDMAEN(1)
#define SPI2_disable_receive_DMA()  SPI2_set_RXDMAEN(0)


//*********************SPI status register (SPI_SR)**********************//


/*
SPI状态寄存器
SPI status register (SPI_SR)
Address offset: 0x08
Reset value: 0x0002
*/

/*
Bits 15:8 Reserved. Forced to 0 by hardware.
*/

/*
获取BSY位
Bit 7 BSY: Busy flag
0: SPI (or I2S) not busy
1: SPI (or I2S) is busy in communication or Tx buffer is not empty
This flag is set and cleared by hardware.
Note: BSY flag must be used with caution: refer to Section 24.3.7: Status flags and 
Section 24.3.8: Disabling the SPI.
*/
U8 SPI1_get_BSY(void);

#define SPI1_is_busy()	SPI1_get_BSY()
#define SPI1_get_busy_flag()	SPI1_get_BSY()

U8 SPI2_get_BSY(void);

#define SPI2_is_busy()	SPI2_get_BSY()
#define SPI2_get_busy_flag()	SPI2_get_BSY()

/*
覆盖标志
Bit 6 OVR: Overrun flag
0: No overrun occurred
1: Overrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.4.7 on 
page 692 for the software sequence.
*/
U8	SPI1_get_OVR(void);

#define SPI1_get_overrun_flag()	SPI1_get_OVR()
#define SPI1_is_overrun_occured()	SPI1_get_OVR()

#define SPI1_is_interrupted_by_overrun()	SPI1_get_OVR()

U8	SPI2_get_OVR(void);

#define SPI2_get_overrun_flag()	SPI2_get_OVR()
#define SPI2_is_overrun_occured()	SPI2_get_OVR()

#define SPI2_is_interrupted_by_overrun()	SPI2_get_OVR()


/*
主模式失败位, 本来配置成主模式的SPI设备的配置为非输出模式的NSS引脚被拉低时，
主模式会自动被清零，并进入从模式，同时产生主模式失败标志
Bit 5 MODF: Mode fault
0: No mode fault occurred
1: Mode fault occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.3.10 on 
page 674 for the software sequence.
Note: Not used in I2S mode
*/
U8 SPI1_get_MODF(void);

#define SPI1_get_mode_fault_flag()	SPI1_get_MODF()
#define SPI1_is_mode_fault_occured()	SPI1_get_MODF()

#define SPI1_is_interrupted_by_mode_fault()	SPI1_get_MODF()

U8 SPI2_get_MODF(void);

#define SPI2_get_mode_fault_flag()	SPI2_get_MODF()
#define SPI2_is_mode_fault_occured()	SPI2_get_MODF()

#define SPI2_is_interrupted_by_mode_fault()	SPI2_get_MODF()


/*
当自己计算的的CRC值和接收到的CRC校验值不同时，产生CRC error
Bit 4 CRCERR: CRC error flag
0: CRC value received matches the SPI_RXCRCR value
1: CRC value received does not match the SPI_RXCRCR value
This flag is set by hardware and cleared by software writing 0.
Note: Not used in I2S mode
*/
U8 SPI1_get_CRCERR(void);

#define SPI1_get_CRC_error_flag()	SPI1_get_CRCERR()
#define SPI1_is_CRC_error_occured()	SPI1_get_CRCERR()
#define SPI1_is_interrupted_by_CRC_error()	SPI1_get_CRCERR()

U8 SPI2_get_CRCERR(void);

#define SPI2_get_CRC_error_flag()	SPI2_get_CRCERR()
#define SPI2_is_CRC_error_occured()	SPI2_get_CRCERR()
#define SPI2_is_interrupted_by_CRC_error()	SPI2_get_CRCERR()


/*
I2S模式下
Bit 3 UDR: Underrun flag
0: No underrun occurred
1: Underrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.4.7 on 
page 692 for the software sequence.
Note: Not used in SPI mode
*/


/*
I2S模式下
Bit 2 CHSIDE: Channel side
0: Channel Left has to be transmitted or has been received
1: Channel Right has to be transmitted or has been received
Note: Not used for the SPI mode. No meaning in PCM mode
*/


/*
发送传送缓冲器为空
Bit 1 TXE: Transmit buffer empty
0: Tx buffer not empty
1: Tx buffer empty
*/
U8 SPI1_get_TXE(void);

#define SPI1_is_TX_buffer_emplty()		SPI1_get_TXE()
#define SPI1_is_transmit_buffer_empty()	SPI1_get_TXE()
#define SPI1_get_transmit_complete_flag()	SPI1_get_TXE()
#define SPI1_is_transmit_complete()			SPI1_get_TXE()
#define SPI1_is_interrupted_by_transmit_complete()	SPI1_get_TXE()

U8 SPI2_get_TXE(void);

#define SPI2_is_TX_buffer_emplty()		SPI2_get_TXE()
#define SPI2_is_transmit_buffer_empty()	SPI2_get_TXE()
#define SPI2_get_transmit_complete_flag()	SPI2_get_TXE()
#define SPI2_is_transmit_complete()			SPI2_get_TXE()
#define SPI2_is_interrupted_by_transmit_complete()	SPI2_get_TXE()



/*
接收传送缓冲器不为空
Bit 0 RXNE: Receive buffer not empty
0: Rx buffer empty
1: Rx buffer not empty
*/
U8 SPI1_get_RXNE(void);

#define SPI1_get_receive_complete_flag()

#define SPI1_is_RX_buffer_not_empty()	SPI1_get_RXNE()
#define SPI1_is_receive_complete()			SPI1_get_RXNE()

#define SPI1_is_interrupted_by_receive_complete()	SPI1_get_RXNE()

U8 SPI2_get_RXNE(void);

#define SPI2_get_receive_complete_flag()

#define SPI2_is_RX_buffer_not_empty()	SPI2_get_RXNE()
#define SPI2_is_receive_complete()			SPI2_get_RXNE()

#define SPI2_is_interrupted_by_receive_complete()	SPI2_get_RXNE()


//***********************88SPI data register (SPI_DR)*****************//

/*
发送数据寄存器(通过读写操作区分)
Bits 15:0 DR[15:0]: Data register
Data received or to be transmitted.
The data register is split into 2 buffers - one for writing (Transmit Buffer) and another one for 
reading (Receive buffer). A write to the data register will write into the Tx buffer and a read 
from the data register will return the value held in the Rx buffer.
Notes for the SPI mode:
Depending on the data frame format selection bit (DFF in SPI_CR1 register), the data 
sent or received is either 8-bit or 16-bit. This selection has to be made before enabling 
the SPI to ensure correct operation. 
For an 8-bit data frame, the buffers are 8-bit and only the LSB of the register 
(SPI_DR[7:0]) is used for transmission/reception. When in reception mode, the MSB of 
the register (SPI_DR[15:8]) is forced to 0.
For a 16-bit data frame, the buffers are 16-bit and the entire register, SPI_DR[15:0] is 
used for transmission/reception.
*/
void SPI1_set_DR(U16 data);

#define SPI1_send_data(data)	SPI1_set_DR(data)

U16 SPI1_get_DR(void);

#define SPI1_receive_data()		SPI1_get_DR()

void SPI2_set_DR(U16 data);

#define SPI2_send_data(data)	SPI2_set_DR(data)

U16 SPI2_get_DR(void);

#define SPI2_receive_data()		SPI2_get_DR()



//****SPI CRC polynomial register (SPI_CRCPR)*********//
/*
SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode)
Address offset: 0x10
Reset value: 0x0007
*/
/*
CRC的计算公式设置
Bits 15:0 CRCPOLY[15:0]: CRC polynomial register
This register contains the polynomial for the CRC calculation.
The CRC polynomial (0007h) is the reset value of this register. Another polynomial can be 
configured as required.
Note: Not used for the I2S mode.
*/ 
void SPI1_set_CRCPOLY(U16 poly);

#define SPI1_set_CRC_polynomial(p)	SPI1_set_CRCPOLY(p)	

void SPI2_set_CRCPOLY(U16 poly);

#define SPI2_set_CRC_polynomial(p)	SPI2_set_CRCPOLY(p)	


//****SPI Rx CRC register (SPI_RXCRCR) (not used in I2S mode)***********//

/*
SPI Rx CRC register (SPI_RXCRCR) (not used in I2S mode)
Address offset: 0x14
Reset value: 0x0000
*/
/*
接收帧数据计算的CRC校验值
RXCRC[15:0]: Rx CRC register
When CRC calculation is enabled, the RxCRC[15:0] bits contain the computed CRC value of 
the subsequently received bytes. This register is reset when the CRCEN bit in SPI_CR1 
register is written to 1. The CRC is calculated serially using the polynomial programmed in 
the SPI_CRCPR register. 
Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF 
bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
The entire 16-bits of this register are considered when a 16-bit data frame format is selected 
(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16 
standard.
Note: A read to this register when the BSY Flag is set could return an incorrect value.
Not used for the I2S mode.
*/

U16 SPI1_get_RXCRC(void);

#define SPI1_get_receive_CRC_value()	SPI1_get_RXCRC()

U16 SPI2_get_RXCRC(void);

#define SPI2_get_receive_CRC_value()	SPI2_get_RXCRC()


//****8SPI Tx CRC register (SPI_TXCRCR) (not used in I2S mode)**********//
/*
发送数据计算的CRC校验值
SPI Tx CRC register (SPI_TXCRCR) (not used in I2S mode)
Address offset: 0x18
Reset value: 0x0000
*/
/*
Bits 15:0 TxCRC[15:0]: Tx CRC register
When CRC calculation is enabled, the TxCRC[7:0] bits contain the computed CRC value of 
the subsequently transmitted bytes. This register is reset when the CRCEN bit of SPI_CR1 
is written to 1. The CRC is calculated serially using the polynomial programmed in the 
SPI_CRCPR register.
Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF 
bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
The entire 16-bits of this register are considered when a 16-bit data frame format is selected 
(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16 
standard.
Note: A read to this register when the BSY flag is set could return an incorrect value.
Not used for the I2S mode.
*/
U16 SPI1_get_TXCRC(void);

#define SPI1_get_transmit_CRC_value()	SPI1_get_TXCRC()

U16 SPI2_get_TXCRC(void);

#define SPI2_get_transmit_CRC_value()	SPI2_get_TXCRC()

#endif




#ifndef __USART1
#define __USART1
#include "com.h"



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



#ifndef __STM32F10x_MAP_H

#ifndef __MAP
#define __MAP

#define FLASH_BASE            ((U32)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((U32)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((U32)0x40000000) /*!< Peripheral base address in the alias region */

#define SRAM_BB_BASE          ((U32)0x22000000) /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        ((U32)0x42000000) /*!< Peripheral base address in the bit-band region */

#define FSMC_R_BASE           ((U32)0xA0000000) /*!< FSMC registers base address */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)
#define CEC_BASE              (APB1PERIPH_BASE + 0x7800)

#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x4000)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x4400)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x4800)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4C00)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x5000)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x5400)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000) /*!< Flash registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800)    /*!< Flash Option Bytes base address */

#define ETH_BASE              (AHBPERIPH_BASE + 0x8000)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000)

#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000) /*!< FSMC Bank1 registers base address */
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104) /*!< FSMC Bank1E registers base address */
#define FSMC_Bank2_R_BASE     (FSMC_R_BASE + 0x0060) /*!< FSMC Bank2 registers base address */
#define FSMC_Bank3_R_BASE     (FSMC_R_BASE + 0x0080) /*!< FSMC Bank3 registers base address */
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0) /*!< FSMC Bank4 registers base address */

#define DBGMCU_BASE          (0xE0042000) 	/*!< Debug MCU registers base address */


#endif
#endif

#ifndef __NVIC
#define __NVIC

#include "com.h"

//中断号
#define		_WWDG_IRQn                     0       //!< Window WatchDog Interrupt                            //
#define		_PVD_IRQn                      1       //!< PVD through EXTI Line detection Interrupt            //
#define		_TAMPER_IRQn                   2       //!< Tamper Interrupt                                     //
#define		_RTC_IRQn                      3       //!< RTC global Interrupt                                 //
#define		_FLASH_IRQn                    4       //!< FLASH global Interrupt                               //
#define		_RCC_IRQn                      5       //!< RCC global Interrupt                                 //
#define		_EXTI0_IRQn                    6       //!< EXTI Line0 Interrupt                                 //
#define		_EXTI1_IRQn                    7       //!< EXTI Line1 Interrupt                                 //
#define		_EXTI2_IRQn                    8       //!< EXTI Line2 Interrupt                                 //
#define		_EXTI3_IRQn                    9       //!< EXTI Line3 Interrupt                                 //
#define		_EXTI4_IRQn                    10      //!< EXTI Line4 Interrupt                                 //
#define		_DMA1_Channel1_IRQn            11      //!< DMA1 Channel 1 global Interrupt                      //
#define		_DMA1_Channel2_IRQn            12      //!< DMA1 Channel 2 global Interrupt                      //
#define		_DMA1_Channel3_IRQn            13      //!< DMA1 Channel 3 global Interrupt                      //
#define		_DMA1_Channel5_IRQn            15      //!< DMA1 Channel 5 global Interrupt                      //
#define		_DMA1_Channel6_IRQn            16      //!< DMA1 Channel 6 global Interrupt                      //
#define		_DMA1_Channel7_IRQn            17      //!< DMA1 Channel 7 global Interrupt                      //
#define		_ADC1_2_IRQn                   18      //!< ADC1 and ADC2 global Interrupt                       //
#define  	_USB_HP_CAN1_TX_IRQn           19      //!< USB Device High Priority or CAN1 TX Interrupts       //
#define  	_USB_LP_CAN1_RX0_IRQn          20      //!< USB Device Low Priority or CAN1 RX0 Interrupts       //
#define  	_CAN1_RX1_IRQn                 21      //!< CAN1 RX1 Interrupt                                   //
#define  	_CAN1_SCE_IRQn                 22      //!< CAN1 SCE Interrupt                                   //
#define 	_EXTI9_5_IRQn                  23      //!< External Line[9:5] Interrupts                        //
#define  	_TIM1_BRK_IRQn                 24      //!< TIM1 Break Interrupt                                 //
#define  	_TIM1_UP_IRQn                  25      //!< TIM1 Update Interrupt                                //
#define  	_TIM1_TRG_COM_IRQn             26      //!< TIM1 Trigger and Commutation Interrupt               //
#define  	_TIM1_CC_IRQn                  27      //!< TIM1 Capture Compare Interrupt                       //
#define  	_TIM2_IRQn                     28      //!< TIM2 global Interrupt                                //
#define  	_TIM3_IRQn                     29      //!< TIM3 global Interrupt                                //
#define  	_TIM4_IRQn                     30      //!< TIM4 global Interrupt                                //
#define  	_I2C1_EV_IRQn                  31      //!< I2C1 Event Interrupt                                 //
#define  	_I2C1_ER_IRQn                  32      //!< I2C1 Error Interrupt                                 //
#define 	_I2C2_EV_IRQn                  33      //!< I2C2 Event Interrupt                                 //
#define  	_I2C2_ER_IRQn                  34      //!< I2C2 Error Interrupt                                 //
#define  	_SPI1_IRQn                     35      //!< SPI1 global Interrupt                                //
#define  	_SPI2_IRQn                     36      //!< SPI2 global Interrupt                                //
#define 	_USART1_IRQn                   37      //!< USART1 global Interrupt                              //
#define  	_USART2_IRQn                   38      //!< USART2 global Interrupt                              //
#define  	_USART3_IRQn                   39      //!< USART3 global Interrupt                              //
#define  	_EXTI15_10_IRQn                40      //!< External Line[15:10] Interrupts                      //
#define  	_RTCAlarm_IRQn                 41      //!< RTC Alarm through EXTI Line Interrupt                //
#define  	_USBWakeUp_IRQn                42      //!< USB Device WakeUp from suspend through EXTI Line Interrupt //
#define  	_TIM8_BRK_IRQn                 43      //!< TIM8 Break Interrupt                                 //
#define  	_TIM8_UP_IRQn                  44      //!< TIM8 Update Interrupt                                //
#define  	_TIM8_TRG_COM_IRQn             45      //!< TIM8 Trigger and Commutation Interrupt               //
#define  	_TIM8_CC_IRQn                  46      //!< TIM8 Capture Compare Interrupt                       //
#define  	_ADC3_IRQn                     47      //!< ADC3 global Interrupt                                //
#define  	_FSMC_IRQn                     48      //!< FSMC global Interrupt                                //
#define  	_SDIO_IRQn                     49      //!< SDIO global Interrupt                                //
#define  	_TIM5_IRQn                     50      //!< TIM5 global Interrupt                                //
#define  	_SPI3_IRQn                     51      //!< SPI3 global Interrupt                                //
#define  	_UART4_IRQn                    52      //!< UART4 global Interrupt                               //
#define  	_UART5_IRQn                    53      //!< UART5 global Interrupt                               //
#define 	_TIM6_IRQn                     54      //!< TIM6 global Interrupt                                //
#define  	_TIM7_IRQn                     55      //!< TIM7 global Interrupt                                //
#define  	_DMA2_Channel1_IRQn            56      //!< DMA2 Channel 1 global Interrupt                      //
#define  	_DMA2_Channel2_IRQn            57      //!< DMA2 Channel 2 global Interrupt                      //
#define  	_DMA2_Channel3_IRQn            58      //!< DMA2 Channel 3 global Interrupt                      //
#define  	_DMA2_Channel4_5_IRQn          59      //!< DMA2 Channel 4 and Channel 5 global Interrupt        //
  
  
/*NVIC 寄存器*/

#define 	__SET_ENA 			(0xE000E100)	//使能中断地址
#define 	__CLEAR_ENA			(0xE000E180)	//清除中断地址
#define 	__SET_PEND			(0xE000E200)	//使能挂起
#define 	__CLEAR_PEND		(0xE000E280)	//除能挂起
#define 	__PRIORITY			(0xE000E400)	//优先级
#define 	__SYS_PRIORIY		(0xE000ED18)	//系统异常优先级
#define 	__ACTIVE			(0xE000E300)	//活动状态寄存器
#define 	__CSHCSR			(0xE000ED24)	//系统handler控制及状态寄存器
#define 	__ICSR				(0xE000ED04)	//中断控制及状态寄存器

#define 	_SET_ENA 			(unsigned int *)(__SET_ENA)		//使能中断地址
#define 	_CLEAR_ENA			(unsigned int *)(__CLEAR_ENA)	//清除中断地址
#define 	_SET_PEND			(unsigned int *)(__SET_PEND)	//使能挂起
#define 	_CLEAR_PEND			(unsigned int *)(__CLEAR_PEND)	//除能挂起
#define 	_PRIORITY			(unsigned int *)(__PRIORITY)	//优先级
#define 	_SYS_PRIORIY		(unsigned int *)(__SYS_PRIORIY)	//系统异常优先级
#define 	_ACTIVE				(unsigned int *)(__ACTIVE)		//活动状态寄存器
#define 	_CSHCSR				(unsigned int *)(__CSHCSR)		//系统handler控制及状态寄存器
#define 	_ICSR				(unsigned int *)(__ICSR)		//中断控制及状态寄存器

#define 	SET_ENA				(*_SET_ENA) 			//使能中断地址
#define 	CLEAR_ENA			(*_CLEAR_ENA)			//清除中断地址
#define 	SET_PEND			(*_SET_PEND)			//使能挂起
#define 	CLEAR_PEND			(*_CLEAR_PEND)			//除能挂起
#define 	PRIORITY			(*_PRIORITY)			//优先级
#define 	SYS_PRIORIY			(*_SYS_PRIORIY)			//系统异常优先级
#define 	ACTIVE				(*_ACTIVE)				//活动状态寄存器
#define 	CSHCSR				(*_CSHCSR)				//系统handler控制及状态寄存器
#define 	ICSR				(*_ICSR)				//中断控制及状态寄存器

//应用程序中断及复位控制寄存器
#define 	__NVIC_AIRCR			0xE000ED0C			
#define 	_NVIC_AIRCR			ADR(__NVIC_AIRCR)
#define 	NVIC_AIRCR			VAL(__NVIC_AIRCR)

//中断优先级寄存器阵列
#define __NVIC_PRIx(n) 	(0xE000E400 + n)
#define _NVIC_PRIx(n)	((unsigned char*)(__NVIC_PRIx(n)))
#define NVIC_PRIx(n)	(*(_NVIC_PRIx(n)))

void NVIC_enable_interrupt(U8 interNum);			//使能外部中断号为interNum的中断
void NVIC_disable_interrupt(U8 interNum);			//除能外部中断好为interNum的中断
void NVIC_pending_interrupt(U8 interNum);			//挂起中断
void NVIC_clear_pending(U8 interNum);					//去除挂起中断

//设置对应中断号的中断优先级
void NVIC_set_PRIx(U16 priNum, U8 pri);

//获取对应中断号的中断优先级
U8 NVIC_get_PRIx(U32 priNum);

#endif


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





/*
	此模块定义了Cyclic redundancy Check 循环冗余检测的寄存器及其所有操作
*/


/*
	Cyclic Redundancy Check	Introduce
	RCR用于计算一个32位数的冗余码，通过写入之后的读取即可得到。
*/

#ifndef __CRC
#define __CRC


#include "com.h"

/*
	CRC用来计算数据的循环冗余检验结果，每次计算需要4个AHB周期。
	每进入一个数，计算一次，再进来的数将根据上一个的计算结果合并计算
	所以可连续写入数据，最后再读取结果。
	详细配置方法见:Configure_CRC.c中定义的函数
*/


//
#define	__CRC_DR	(CRC_BASE + 0x00000000)
#define __CRC_IDR	(CRC_BASE + 0x00000004)
#define __CRC_CR	(CRC_BASE + 0x00000008)

//Address
#define _CRC_DR		ADR(__CRC_DR)
#define _CRC_IDR	ADR(__CRC_IDR)
#define _CRC_CR		ADR(__CRC_CR)

//Value
#define CRC_DR		VAL(__CRC_DR)
#define CRC_IDR		VAL(__CRC_IDR)
#define CRC_CR		VAL(__CRC_CR)


//*********************Data register (CRC_DR)******************//
/*
Data register (CRC_DR)
Address offset: 0x00
Reset value: 0xFFFF FFFF
*/

/*
Bits 31:0 Data register bits
Used as an input register when writing new data into the CRC calculator.
Holds the previous CRC calculation result when it is read.
*/
void CRC_set_DR(U32 data);

#define CRC_set_value(data)		CRC_set_DR(data)   //设置将被计算的值

U32	CRC_get_DR(void);

#define CRC_get_result()		CRC_get_DR()	// 获得计算结果

//******************Independent data register (CRC_IDR)********//
/*
Independent data register (CRC_IDR)
Address offset: 0x04
Reset value: 0x0000 0000
*/

/*
Bits 7:0 General-purpose 8-bit data register bits
Can be used as a temporary storage location for one byte.
This register is not affected by CRC resets generated by the RESET bit in the CRC_CR 
register.
*/

//设置临时值
void CRC_set_IDR(U8 data);

#define CRC_set_temporary_value(data) 	CRC_set_IDR(data)	//设置临时值


//获得临时值
U8	CRC_get_IDR(void);

#define CRC_get_temporary_value()		CRC_get_IDR()		//获得临时值



//*****************Control register (CRC_CR)***********************//
/*
Control register (CRC_CR)
Address offset: 0x08
Reset value: 0x0000 0000
*/
/*
复位
Bit 0 RESET bit
Resets the CRC calculation unit and sets the data register to FFFF FFFFh.
This bit can only be set, it is automatically cleared by hardware.
*/
void CRC_set_RESET(void);


#define CRC_reset()		CRC_set_RESET()		//复位CRC模块


#endif


/*
//此文档定义了重映像端口输入输出AFIO的寄存器
//分别有:
cortex的事件引出控制， 
IO口复用重映像.
外部中断选择信号线所接的具体IO脚.
*/

#ifndef __AFIO
#define __AFIO

#include "com.h"


#define __AFIO_EVCR		(AFIO_BASE + 0x00000000)	//事件控制寄存器
#define __AFIO_MARP		(AFIO_BASE + 0x00000004)	//IO重映射
#define __AFIO_EXTICR1	(AFIO_BASE + 0x00000008)	//外部中断选择接入引脚 中断0~3
#define __AFIO_EXTICR2	(AFIO_BASE + 0x0000000C)	//外部中断选择接入引脚 中断4~7	
#define __AFIO_EXTICR3	(AFIO_BASE + 0x00000010) 	//外部中断选择接入引脚 中断8~11
#define __AFIO_EXTICR4	(AFIO_BASE + 0x00000014)	//外部中断选择接入引脚 中断12~15

#define _AFIO_EVCR		ADR(__AFIO_EVCR)		//事件控制寄存器
#define _AFIO_MARP		ADR(__AFIO_MARP)		//IO重映射
#define _AFIO_EXTICR1	ADR(__AFIO_EXTICR1)		//外部中断选择接入引脚 中断0~3
#define _AFIO_EXTICR2	ADR(__AFIO_EXTICR2)		//外部中断选择接入引脚 中断4~7	
#define _AFIO_EXTICR3	ADR( __AFIO_EXTICR3)	//外部中断选择接入引脚 中断8~11
#define _AFIO_EXTICR4	ADR(__AFIO_EXTICR4)		//外部中断选择接入引脚 中断12~15

#define AFIO_EVCR		VAL(__AFIO_EVCR)		//事件控制寄存器
#define AFIO_MARP		VAL(__AFIO_MARP)		//IO重映射
#define AFIO_EXTICR1	VAL(__AFIO_EXTICR1)		//外部中断选择接入引脚 中断0~3
#define AFIO_EXTICR2	VAL(__AFIO_EXTICR2)		//外部中断选择接入引脚 中断4~7	
#define AFIO_EXTICR3	VAL(__AFIO_EXTICR3)	 	//外部中断选择接入引脚 中断8~11
#define AFIO_EXTICR4	VAL(__AFIO_EXTICR4)		//外部中断选择接入引脚 中断12~15


//***********************************事件控制寄存器AFIO_EVCR配置******************************//
/*
	函数功能:使Cortex的EVENTOUT将连接到由PORT和PIN选定的I/O口。
	port: 	000：选择PA 
			001：选择PB 
			010：选择PC 
			011：选择PD 
			100：选择PE
			101: 选择PF
			110: 选择PG
	PIN:	
	0000：选择Px0 	0001：选择Px1 	0010：选择Px2 
	0011：选择Px3 	0100：选择Px4 	0101：选择Px5 
	0110：选择Px6	0111：选择Px7 	1000：选择Px8 
	1001：选择Px9 	1010：选择Px10 	1011：选择Px11 
	1100：选择Px12 	1101：选择Px13 	1110：选择Px14 
	1111：选择Px15
*/
void AFIO_enable_EVO(U8 port, U8 pin);
void AFIO_disable_EVO(void);			   //禁用此功能



//********************************复用重映射和调试I/O配置寄存器AFIO_MAPR**************************//

/*
	SWJ_CFG[2:0]：串行线JTAG配置 (Serial wire JTAG configuration) 
	位26:24 
	这些位只可由软件写(读这些位，将返回未定义的数值)，
	用于配置SWJ和跟踪复用功能的I/O口。
	SWJ(串行线JTAG)支持JTAG或SWD访问Cortex的调试端口。
	系统复位后的默认状态是启用SWJ但没有跟踪功能，
	这种状态下可以通过JTMS/JTCK脚上的特定信号选择JTAG或SW(串行线)模式。
	000：完全SWJ(JTAG-DP + SW-DP)：复位状态； 
	001：完全SWJ(JTAG-DP + SW-DP)但没有NJTRST； 
	010：关闭JTAG-DP，启用SW-DP； 
	100：关闭JTAG-DP，关闭SW-DP； 
	其它组合：无作用。
*/
void AFIO_remap_SWJ(U8 conf);		//配置SWJ映射

/*
	ADC2_ETRGREG_REMAP：
	ADC2规则转换外部触发重映射 (ADC 2 external trigger regular conversion remapping) 
	位20 
	该位可由软件置’1’或置’0’。它控制与ADC2规则转换外部触发相连的触发输入。
	当该位置’0’时，ADC2规则转换外部触发与EXTI11相连；
	当该位置’1’时，ADC2规则转换外部触发与TIM8_TRGO相连。
*/
void AFIO_remap_ADC2_REG(U8 conf);

/*
	ADC2_ETRGINJ_REMAP：ADC2注入转换外部触发重映射 (ADC 2 external trigger injected conversion remapping) 
	位19 该位可由软件置’1’或置’0’。
	它控制与ADC2注入转换外部触发相连的触发输入。
	当该位置’0’时，ADC2注入转换外部触发与EXTI15相连；
	当该位置’1’时，ADC2注入转换外部触发与TIM8通道4相连。
*/
void AFIO_remap_ADC2_INJ(U8 conf);

/*
	ADC1_ETRGREG_REMAP：
	ADC1规则转换外部触发重映射 (ADC 1 external trigger regular conversion remapping) 
	位18 
	该位可由软件置’1’或置’0’。它控制与ADC2规则转换外部触发相连的触发输入。
	当该位置’0’时，ADC2规则转换外部触发与EXTI11相连；
	当该位置’1’时，ADC2规则转换外部触发与TIM8_TRGO相连。
*/
void AFIO_remap_ADC1_REG(U8 conf);

/*
	ADC1_ETRGINJ_REMAP：
	ADC1注入转换外部触发重映射 (ADC 1 external trigger injected conversion remapping) 
	位17 该位可由软件置’1’或置’0’。
	它控制与ADC2注入转换外部触发相连的触发输入。
	当该位置’0’时，ADC2注入转换外部触发与EXTI15相连；
	当该位置’1’时，ADC2注入转换外部触发与TIM8通道4相连。
*/
void AFIO_remap_ADC1_INJ(U8 conf); 

/*
	TIM5CH4_IREMAP：TIM5通道4内部重映射 (TIM5 channel4 internal remap) 
	位16 
	该位可由软件置’1’或置’0’。它控制TIM5通道4内部映像。
	当该位置’0’时，TIM5_CH4与PA3相连；
	当该位置’1’时，LSI内部振荡器与TIM5_CH4相连，目的是对LSI进行校准。
*/
void AFIO_remap_TIM5CH4(U8 conf);

/*
	PD01_REMAP：端口D0/端口D1映像到OSC_IN/OSC_OUT (Port D0/Port D1 mapping on OSC_IN/OSC_OUT) 
	位15 该位可由软件置’1’或置’0’。
	它控制PD0和PD1的GPIO功能映像。当不使用主振荡器HSE时(系统运行于内部的8MHz阻容振荡器)，
	PD0和PD1可以映像到OSC_IN和OSC_OUT引脚。
	此功能只能适用于36、48和64引脚的封装(PD0和PD1出现在100脚和144脚的封装上，不必重映像)。
	0：不进行PD0和PD1的重映像； 
	1：PD0映像到OSC_IN，PD1映像到OSC_OUT。
*/
void AFIO_remap_PD01(U8 conf);

/*
	CAN_REMAP[1:0]：CAN复用功能重映像 (CAN alternate function remapping) 
	位14:13 这些位可由软件置’1’或置’0’，在只有单个CAN接口的产品上控制复用功能CAN_RX和CAN_TX的重映像。 
	00：CAN_RX映像到PA11，CAN_TX映像到PA12； 
	01：未用组合； 
	10：CAN_RX映像到PB8，CAN_TX映像到PB9(不能用于36脚的封装)； 
	11：CAN_RX映像到PD0，CAN_TX映像到PD1。
*/
void AFIO_remap_CAN(U8 conf);

/*
	TIM4_REMAP：定时器4的重映像 (TIM4 remapping) 位12 该位可由软件置’1’或置’0’，
	控制将TIM4的通道1-4映射到GPIO端口上。 
	0：没有重映像(TIM4_CH1/PB6，TIM4_CH2/PB7，TIM4_CH3/PB8，TIM4_CH4/PB9)； 
	1：完全映像(TIM4_CH1/PD12，TIM4_CH2/PD13，TIM4_CH3/PD14，TIM4_CH4/PD15)。 
	注：重映像不影响在PE0上的TIM4_ETR。
*/
void AFIO_remap_TIM4(U8 conf);

/*
	TIM3_REMAP[1:0]：定时器3的重映像 (TIM3 remapping) 
	位11:10 这些位可由软件置’1’或置’0’，控制定时器3的通道1至4在GPIO端口的映像。 
	00：没有重映像(CH1/PA6，CH2/PA7，CH3/PB0，CH4/PB1)； 
	01：未用组合； 
	10：部分映像(CH1/PB4，CH2/PB5，CH3/PB0，CH4/PB1)； 
	11：完全映像(CH1/PC6，CH2/PC7，CH3/PC8，CH4/PC9)。 
	注：重映像不影响在PD2上的TIM3_ETR。
*/
void AFIO_remap_TIM3(U8 conf);

/*
	TIM2_REMAP[1:0]：定时器2的重映像 (TIM2 remapping) 位9:8 这些位可由软件置’1’或置’0’，
	控制定时器2的通道1至4和外部触发(ETR)在GPIO端口的映像。 
	00：没有重映像(CH1/ETR/PA0，CH2/PA1，CH3/PA2，CH4/PA3)； 
	01：部分映像(CH1/ETR/PA15，CH2/PB3，CH3/PA2，CH4/PA3)； 
	10：部分映像(CH1/ETR/PA0，CH2/PA1，CH3/PB10，CH4/PB11)； 
	11：完全映像(CH1/ETR/PA15，CH2/PB3，CH3/PB10，CH4/PB11)。
*/
void AFIO_remap_TIM2(U8 conf);

/*
	TIM1_REMAP[1:0]：定时器1的重映像 (TIM1 remapping) 位7:6 这些位可由软件置’1’或置’0’，
	控制定时器1的通道1至4、1N至3N、外部触发(ETR)和刹车输入(BKIN)在GPIO端口的映像。 
	00：没有重映像(ETR/PA12，CH1/PA8，CH2/PA9，CH3/PA10，CH4/PA11，BKIN/PB12，CH1N/PB13，CH2N/PB14，CH3N/PB15)；
	01：部分映像(ETR/PA12，CH1/PA8，CH2/PA9，CH3/PA10，CH4/PA11，BKIN/PA6，CH1N/PA7，CH2N/PB0，CH3N/PB1)； 
	10: 未用组合；
	11: 完全映像(ETR/PE7，CH1/PE9，CH2/PE11，CH3/PE13，CH4/PE14，BKIN/PE15，CH1N/PE8，CH2N/PE10，CH3N/PE12)。
*/
void AFIO_remap_TIM1(U8 conf);

/*
	USART3_REMAP[1:0]：USART3的重映像 (USART3 remapping) 位5:4 这些位可由软件置’1’或置’0’，
	控制USART3的CTS、RTS、CK、TX和RX复用功能在GPIO端口的映像。 
	00: 没有重映像(TX/PB10，RX/PB11，CK/PB12，CTS/PB13，RTS/PB14)； 
	01: 部分映像(TX/PC10，RX/PC11，CK/PC12，CTS/PB13，RTS/PB14)； 
	10: 未用组合； 
	11: 完全映像(TX/PD8，RX/PD9，CK/PD10，CTS/PD11，RTS/PD12)。
*/
void AFIO_remap_USART3(U8 conf);

/*
	USART2_REMAP：USART2的重映像 (USART2 remapping) 
	位3 这些位可由软件置’1’或置’0’，控制USART2的CTS、RTS、CK、TX和RX复用功能在GPIO端口的映像。 
	0: 没有重映像(CTS/PA0，RTS/PA1，TX/PA2，RX/PA3，CK/PA4)； 
	1: 重映像(CTS/PD3，RTS/PD4，TX/PD5，RX/PD6，CK/PD7)；
*/
void AFIO_remap_USART2(U8 conf);

/*
	USART1_REMAP：USART1的重映像 (USART1 remapping) 
	位2 该位可由软件置’1’或置’0’，控制USART1的TX和RX复用功能在GPIO端口的映像。
	0: 没有重映像(TX/PA9，RX/PA10)； 
	1: 重映像(TX/PB6，RX/PB7)。
*/
void AFIO_remap_USART1(U8 conf);

/*
	I2C1_REMAP：I2C1的重映像 (I2C1 remapping) 
	位1 该位可由软件置’1’或置’0’，
	控制I2C1的SCL和SDA复用功能在GPIO端口的映像。 
	0: 没有重映像(SCL/PB6，SDA/PB7)； 
	1: 重映像(SCL/PB8，SDA/PB9)。
*/
void AFIO_remap_I2C1(U8 conf);

/*
	SPI1_REMAP：SPI1的重映像 位0 该位可由软件置’1’或置’0’，
	控制SPI1的NSS、SCK、MISO和MOSI复用功能在GPIO端口的映像。 
	0: 没有重映像(NSS/PA4，SCK/PA5，MISO/PA6，MOSI/PA7)；
	1: 重映像(NSS/PA15，SCK/PB3，MISO/PB4，MOSI/PB5)。
*/

void AFIO_remap_SPI1(U8 conf);


//**************************************************************外部中断配置寄存器AFIO_EXTICR*******************************************//

/*
	EXTIx[3:0]：EXTIx配置(x = 0 … 15) (EXTI x configuration) 
	 这些位可由软件读写，用于选择EXTIx外部中断的输入源。
	 0000：PA[x]引脚 0100：PE[x]引脚 
	 0001：PB[x]引脚 0101：PF[x]引脚 
	 0010：PC[x]引脚 0110：PG[x]引脚 
	 0011：PD[x]引脚

	extiX:可取0-15，用来配置extiX的输入源
	port:输入源， 从0-7 ，共8个io端口。
*/
void AFIO_EXTI_set_entry(U8 extiX, GPIO_PORT port);


//lineX = 0 - 15
//port = GPIO_A - GPIO_G

#define AFIO_EXTI_set_entry_at_line_x(lineX, port)	AFIO_EXTI_set_entry(lineX, port)

#define AFIO_EXTI_set_entry_at_line_0(port)		AFIO_EXTI_set_entry(0, port)
#define AFIO_EXTI_set_entry_at_line_1(port)		AFIO_EXTI_set_entry(1, port)
#define AFIO_EXTI_set_entry_at_line_2(port)		AFIO_EXTI_set_entry(2, port)
#define AFIO_EXTI_set_entry_at_line_3(port)		AFIO_EXTI_set_entry(3, port)
#define AFIO_EXTI_set_entry_at_line_4(port)		AFIO_EXTI_set_entry(4, port)
#define AFIO_EXTI_set_entry_at_line_5(port)		AFIO_EXTI_set_entry(5, port)
#define AFIO_EXTI_set_entry_at_line_6(port)		AFIO_EXTI_set_entry(6, port)
#define AFIO_EXTI_set_entry_at_line_7(port)		AFIO_EXTI_set_entry(7, port)
#define AFIO_EXTI_set_entry_at_line_8(port)		AFIO_EXTI_set_entry(8, port)
#define AFIO_EXTI_set_entry_at_line_9(port)		AFIO_EXTI_set_entry(9, port)
#define AFIO_EXTI_set_entry_at_line_10(port)	AFIO_EXTI_set_entry(10, port)
#define AFIO_EXTI_set_entry_at_line_11(port)	AFIO_EXTI_set_entry(11, port)
#define AFIO_EXTI_set_entry_at_line_12(port)	AFIO_EXTI_set_entry(12, port)
#define AFIO_EXTI_set_entry_at_line_13(port)	AFIO_EXTI_set_entry(13, port)
#define AFIO_EXTI_set_entry_at_line_14(port)	AFIO_EXTI_set_entry(14, port)
#define AFIO_EXTI_set_entry_at_line_15(port)	AFIO_EXTI_set_entry(15, port)

#endif

#endif
