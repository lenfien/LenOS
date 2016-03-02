
/*
//此文档定义了重映像端口输入输出AFIO的寄存器
//分别有:
cortex的事件引出控制， 
IO口复用重映像.
外部中断选择信号线所接的具体IO脚.
*/

#ifndef __AFIO
#define __AFIO
#include "core_map.h"
#include "base_gpio.h"
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
