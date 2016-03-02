


#ifndef __RCC
#define __RCC

#include "core_map.h"
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
