

/*
���ĵ�������ADC1����ʱ�������мĴ����Ͷ���Щ�Ĵ��������ĺ���
��Щ������������������:
	���ڹ���ͨ��һ�ɲ�����ָ����ע��ͨ����֮
	��ȡ��־һ�������ֺ�����ʽget_xxx_flag��is_xxx_STAT
	Ҳ�������ж�����ô��is_interrupted_by_xxx
	�����������������Լ��۲�
*/

#ifndef __ADC
#define __ADC

#include "com.h"
#include "core_map.h"
//����ַ����
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

//��ַ����
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


//ֵ����
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
ADC״̬�Ĵ���
Address offset: 0x00
Reset value: 0x0000 0000
*/


/*
Bits 31:5
Reserved, must be kept cleared.
*/

/*
��ͨͨ��ת����ʼλ
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
ע��ת��ͨ����ʼλ
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
ע��ת������
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
��ͨת������
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
ģ�⿴�Ź��¼���־
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
ADC1���ƼĴ���1
ADC control register 1 (ADC_CR1)
Address offset: 0x04
Reset value: 0x0000 0000
*/
/*
Bits 31:24 Reserved, must be kept cleared.
*/

/*
Ϊ��ͨͨ��ʹ��ģ�⿴�Ź�
Bit 23 AWDEN: Analog watchdog enable on regular channels
This bit is set/reset by software.
0: Analog watchdog disabled on regular channels
1: Analog watchdog enabled on regular channels
*/
void ADC1_set_AWDEN(U8 e_d);

#define ADC1_enable_watchdog()	ADC1_set_AWDEN(1)
#define ADC1_disable_watchdog()	ADC1_set_AWDEN(0)

/*
Ϊע��ͨ��ʹ��ģ�⿴�Ź�
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
˫ADC����ģʽѡ��
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
���ģʽÿһ�δ���ת���ĵ�λ��Ŀ
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
ʹ��ע��ͨ���ļ��ģʽ �����ܺ͹���ͨ���ļ��ģʽһ��ʹ�ã�
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
ʹ�ܹ���ͨ���ļ��ģʽ  �����ܺ�ע��ͨ���ļ��ģʽһ��ʹ�ã�
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
ע��ͨ�����Զ��л�ʹ�� (����ͨ����SCAN��ɺ�
�Զ�����ע��ͨ����SCAN����ɺ��ٻص�����ͨ����SCAN(���CONTʹ�ܵĻ�))
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
��ģ�⿴�Ź�ʹ���ڵ�һͨ���ϻ������е�ͨ��,������һ����һͨ��ѡ����AWDCHλ��
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
ʹ��SCANģʽ
ע:	SCAN���е�ͨ����Ż�����жϣ���DR��ֻ�洢�����һ��ͨ���Ľ����
	�����м����ʹ��DMA��ÿ��ͨ����ת�����������ָ����λ��
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
ʹ����ע��ͨ��ת����ɺ���ж�
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
ʹ��ģ�⿴�Ź��¼��ж�(�����ѹ������ֵ�����Ź����)
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
ʹ�ܹ���ͨ����ת���¼��ж�
Bit 5 EOCIE: Interrupt enable for EOC 
This bit is set and cleared by software to enable/disable the End of Conversion interrupt. 
0: EOC interrupt disabled
1: EOC interrupt enabled. An interrupt is generated when the EOC bit is set.
*/
void ADC1_set_EOCIE(U8 e_d);

#define ADC1_enable_interrupt_at_convert_end()	ADC1_set_EOCIE(1)
#define ADC1_disable_interrupt_at_convert_end()	ADC1_set_EOCIE(0)


/*
ѡ��ģ�⿴�Ź���Ϊһ��ͨ������ʱ��ͨ��
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
�ڲ��¶ȴ��кͲο���ѹVREFʹ��,���Ҫ�����ڲ��¶ȣ�����Ҫʹ�ܸ�λ
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
����ͨ�����ⲿ����ģʽ���ģ�ⴥ��
Bit 22 SWSTART: Start conversion of regular channels
This bit is set by software to start conversion and cleared by hardware as soon as conversion 
starts. It starts a conversion of a group of regular channels if SWSTART is selected as trigger 
event by the EXTSEL[2:0] bits. 
0: Reset state
1: Starts conversion of regular channels
*/
void ADC1_set_SWSTART(void);

#define ADC1_generate_trigger()		ADC1_set_SWSTART()	//���ɹ���ͨ�����ⲿ�����ź�


/*
ע��ͨ�����ⲿ����ģʽ���ģ�ⴥ��
Bit 21 JSWSTART: Start conversion of injected channels
This bit is set by software and cleared by software or by hardware as soon as the conversion 
starts. It starts a conversion of a group of injected channels (if JSWSTART is selected as 
trigger event by the JEXTSEL[2:0] bits. 
0: Reset state
1: Starts conversion of injected channels
*/
void ADC1_set_JSWSTART(void);

#define ADC1_generate_inject_trigger()	ADC1_set_JSWSTART()  //����ע��ͨ�����ⲿ�����ź�


/*
����ͨ�����ⲿ����ģʽʹ��
Bit 20 EXTTRIG: External trigger conversion mode for regular channels
This bit is set and cleared by software to enable/disable the external trigger used to start 
conversion of a regular channel group.
0: Conversion on external event disabled
1: Conversion on external event enabled
*/
void ADC1_set_EXTTRIG(U8 e_d);

#define ADC1_enable_external_trigger()		ADC1_set_EXTTRIG(1)		//ʹ�ܹ���ͨ�����ⲿ����ģʽ
#define ADC1_disable_external_trigger()    ADC1_set_EXTTRIG(0)     //���ܹ���ͨ�����ⲿ����ģʽ


/*
����ͨ���ⲿ����Դѡ��
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
density devices) ���Էֱ�ͨ������ADC1��ADC2��ADC1_ETRGREG_REMAPλ��ADC2_ETRGREG_REMAPλʵ�֡�
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

#define ADC1_set_trigger_source(sel)	ADC1_set_EXTSEL(sel)	//���ù���ͨ���ⲿ�����Ĵ���Դ

#define ADC1_set_trigger_source_TIM1_CC1()	ADC1_set_EXTSEL(0)  //TIM1�Ĳ���Ƚ�ͨ��1����
#define ADC1_set_trigger_source_TIM1_CC2()	ADC1_set_EXTSEL(1)  //TIM1�Ĳ���Ƚ�ͨ��2����
#define ADC1_set_trigger_source_TIM1_CC3()	ADC1_set_EXTSEL(2)  //TIM1�Ĳ���Ƚ�ͨ��3����
#define ADC1_set_trigger_source_TIM2_CC2()	ADC1_set_EXTSEL(3)  //TIM2�Ĳ���Ƚ�ͨ��2����
#define ADC1_set_trigger_source_TIM3_TRGO()	ADC1_set_EXTSEL(4)  //TIM3���ⲿʱ�Ӵ���
#define ADC1_set_trigger_source_TIM4_CC4()	ADC1_set_EXTSEL(5)  //TIM4�Ĳ���Ƚ�ͨ��4����
#define ADC1_set_trigger_source_EXTI1_or_TIM8_TRGO()	ADC1_set_EXTSEL(6)	//���Էֱ�ͨ������ADC1��ADC2��ADC1_ETRGREG_REMAPλ��ADC2_ETRGREG_REMAPλʵ�֡�
#define ADC1_set_trigger_source_software()	ADC1_set_EXTSEL(7)	//�������

/*
Bit 16
Reserved, must be kept cleared.
*/

/*
ע��ͨ���ⲿ����ʹ��
Bit 15 JEXTTRIG: External trigger conversion mode for injected channels
This bit is set and cleared by software to enable/disable the external trigger used to start 
conversion of an injected channel group.
0: Conversion on external event disabled
1: Conversion on external event enabled
*/
void ADC1_set_JEXTTRIG(U8 e_d);

#define ADC1_enable_inject_trigger()   ADC1_set_JEXTTRIG(1)	//ʹ��ע��ͨ�����ⲿ����
#define ADC1_disable_inject_trigger()	ADC1_set_JEXTTRIG(0)	//����ע��ͨ�����ⲿ����


/*
ע��ͨ���ⲿ����Դѡ��
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

#define ADC1_set_inject_trigger_source(sel)		ADC1_set_JEXTSEL(sel)	//���ù���ͨ���ⲿ�����Ĵ���Դ

#define ADC1_set_inject_trigger_source_TIM1_CC1()			ADC1_set_JEXTSEL(0)  	//TIM1�Ĳ���Ƚ�ͨ��1����
#define ADC1_set_inject_trigger_source_TIM1_CC2()			ADC1_set_JEXTSEL(1)  	//TIM1�Ĳ���Ƚ�ͨ��2����
#define ADC1_set_inject_trigger_source_TIM1_CC3()			ADC1_set_JEXTSEL(2)  	//TIM1�Ĳ���Ƚ�ͨ��3����
#define ADC1_set_inject_trigger_source_TIM2_CC2()			ADC1_set_JEXTSEL(3)  	//TIM2�Ĳ���Ƚ�ͨ��2����
#define ADC1_set_inject_trigger_source_TIM3_TRGO()			ADC1_set_JEXTSEL(4)  	//TIM3���ⲿʱ�Ӵ���
#define ADC1_set_inject_trigger_source_TIM4_CC4()			ADC1_set_JEXTSEL(5) 	//TIM4�Ĳ���Ƚ�ͨ��4����
#define ADC1_set_inject_trigger_source_EXTI1_or_TIM8_TRGO()	ADC1_set_JEXTSEL(6)		//���Էֱ�ͨ������ADC1��ADC2��ADC1_ETRGREG_REMAPλ��ADC2_ETRGREG_REMAPλʵ�֡�
#define ADC1_set_inject_trigger_source_software()			ADC1_set_JEXTSEL(7)		//�������

/*
ת�������ݶ��䷽ʽ
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
DMAʹ��
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
��ʼ��У׼�� �������֮����Ӳ���ڳ�ʼ���Ĵ���������
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

#define ADC1_reset_calibration()			ADC1_set_RSTCAL()	//��λУ׼
#define	ADC1_is_reset_calibration_done()	(!ADC1_get_RSTCAL())	//��λ�Ƿ����

/*
��ʼУ׼
Bit 2 CAL: A/D Calibration
This bit is set by software to start the calibration. It is reset by hardware after calibration is 
complete. 
0: Calibration completed 
1: Enable calibration
*/
void ADC1_set_CAL(void);  //��ʼУ׼
U8	ADC1_get_CAL(void);	//���У׼��״̬

#define ADC1_start_calibration()	ADC1_set_CAL()
#define ADC1_is_calibration_done()	(!ADC1_get_CAL())


/*
����ת�����ǵ���ת��ģʽ
Bit 1 CONT: Continuous conversion
This bit is set and cleared by software. If set conversion takes place continuously till this bit is 
reset. 
0: Single conversion mode 
1: Continuous conversion mode 
*/
void ADC1_set_CONT(U8	c);

//����1
#define ADC1_enable_continuous_mode()		ADC1_set_CONT(1)
#define ADC1_disable_continuous_mode()		ADC1_set_CONT(0)

//����2
#define ADC1_set_conversion_in_continuous_mode()		ADC1_set_CONT(1)
#define ADC1_set_conversion_in_single_mode()			ADC1_set_CONT(0)

/*
ʹ��ADC
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
ѡ��ͨ���Ĳ���ʱ��, SMPR1 �� SMPR2�����Ĵ���
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
ע��ͨ��ת������ƫ�����趨��ע��ͨ��ת�������ݽ���ȥ���ֵ�洢��JDRx�У�
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
ģ�⿴�Ź��ľ����Ͻ�
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
ģ�⿴�Ź������½�
Bits 11:0 LT[11:0]: Analog watchdog low threshold 
These bits are written by software to define the low threshold for the analog watchdog.
*/
void ADC1_set_LT(U16 lt);
U16	ADC1_get_LT(void);

#define ADC1_set_watchdog_low_threshold(lt)	ADC1_set_LT(lt)
#define ADC1_get_watchdog_low_threshold()	ADC1_get_LT()

//����ͨ��ת�����мĴ���(�ڴ˺ϲ�)
//*********ADC regular sequence register 1 (ADC_SQR1)**************//
//*********ADC regular sequence register 2 (ADC_SQR2)**************//
//*********ADC regular sequence register 3 (ADC_SQR3)**************//

/*
ɨ��ת����ͨ����
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


//����1
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

//����2
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
����ͨ����ɨ��ģʽ�µ�����
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
	����sqrNum����������ΪchannelNumͨ��
	sqrNum: 1 - 16
	channelNum: 0 - 17
*/
void ADC1_set_SQRx(U8 sqrNum, U8 channelNum);

#define ADC1_set_sequnce(sqrNum, channelNum)	ADC1_set_SQRx(sqrNum, channelNum)

#define ADC1_set_sequence1(channel)		ADC1_set_SQRx(1, channel)    //���ù���ͨ��ɨ��ģʽ������1
#define ADC1_set_sequence2(channel)		ADC1_set_SQRx(2, channel)    //���ù���ͨ��ɨ��ģʽ������2
#define ADC1_set_sequence3(channel)		ADC1_set_SQRx(3, channel)    //���ù���ͨ��ɨ��ģʽ������3
#define ADC1_set_sequence4(channel)		ADC1_set_SQRx(4, channel)    //���ù���ͨ��ɨ��ģʽ������4
#define ADC1_set_sequence5(channel)		ADC1_set_SQRx(5, channel)    //���ù���ͨ��ɨ��ģʽ������5
#define ADC1_set_sequence6(channel)		ADC1_set_SQRx(6, channel)    //���ù���ͨ��ɨ��ģʽ������6
#define ADC1_set_sequence7(channel)		ADC1_set_SQRx(7, channel)    //���ù���ͨ��ɨ��ģʽ������7
#define ADC1_set_sequence8(channel)		ADC1_set_SQRx(8, channel)    //���ù���ͨ��ɨ��ģʽ������8
#define ADC1_set_sequence9(channel)		ADC1_set_SQRx(9, channel)    //���ù���ͨ��ɨ��ģʽ������9
#define ADC1_set_sequence10(channel)	ADC1_set_SQRx(10, channel)   //���ù���ͨ��ɨ��ģʽ������10
#define ADC1_set_sequence11(channel)	ADC1_set_SQRx(11, channel)   //���ù���ͨ��ɨ��ģʽ������11
#define ADC1_set_sequence12(channel)	ADC1_set_SQRx(12, channel)   //���ù���ͨ��ɨ��ģʽ������12
#define ADC1_set_sequence13(channel)	ADC1_set_SQRx(13, channel)   //���ù���ͨ��ɨ��ģʽ������13
#define ADC1_set_sequence14(channel)	ADC1_set_SQRx(14, channel)   //���ù���ͨ��ɨ��ģʽ������14
#define ADC1_set_sequence15(channel)	ADC1_set_SQRx(15, channel)   //���ù���ͨ��ɨ��ģʽ������15
#define ADC1_set_sequence16(channel)	ADC1_set_SQRx(16, channel)   //���ù���ͨ��ɨ��ģʽ������16


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
ɨ��ģʽ��ע��ͨ��������
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

#define ADC1_set_inject_sequence_length_1()	ADC1_set_JL(0)	//����ע��ɨ��ģʽ��lengthΪ1
#define ADC1_set_inject_sequence_length_2()	ADC1_set_JL(1)  //����ע��ɨ��ģʽ��lengthΪ2
#define ADC1_set_inject_sequence_length_3()	ADC1_set_JL(2)  //����ע��ɨ��ģʽ��lengthΪ3
#define ADC1_set_inject_sequence_length_4()	ADC1_set_JL(3)  //����ע��ɨ��ģʽ��lengthΪ4



/*
ע��ͨ����ɨ��ģʽ�µ�����
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
��˫��ģʽ��ADC2��ת�����
Bits 31:16 ADC2DATA[15:0]: ADC2 data
In ADC1: In dual mode, these bits contain the regular data of ADC2. Refer to Section 11.9: 
Dual ADC mode.
In ADC2 and ADC3: these bits are not used.
*/
U16 ADC1_get_ADC2DATA(void);

#define ADC1_get_ADC2_data()	ADC1_get_ADC2DATA()

/*
����ͨ����ת�����
Bits 15:0 DATA[15:0]: Regular data
These bits are read only. They contain the conversion result from the regular channels. The 
data is left or right-aligned as shown in Figure 31 and Figure 32.
*/
U16 ADC1_get_DATA(void);

#define ADC1_get_convert_data()	ADC1_get_DATA()

#define ADC1_get_convert_result()	ADC1_get_DATA()




#endif
