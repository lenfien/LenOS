
/*
//���ĵ���������ӳ��˿��������AFIO�ļĴ���
//�ֱ���:
cortex���¼��������ƣ� 
IO�ڸ�����ӳ��.
�ⲿ�ж�ѡ���ź������ӵľ���IO��.
*/

#ifndef __AFIO
#define __AFIO
#include "core_map.h"
#include "base_gpio.h"
#include "com.h"


#define __AFIO_EVCR		(AFIO_BASE + 0x00000000)	//�¼����ƼĴ���
#define __AFIO_MARP		(AFIO_BASE + 0x00000004)	//IO��ӳ��
#define __AFIO_EXTICR1	(AFIO_BASE + 0x00000008)	//�ⲿ�ж�ѡ��������� �ж�0~3
#define __AFIO_EXTICR2	(AFIO_BASE + 0x0000000C)	//�ⲿ�ж�ѡ��������� �ж�4~7	
#define __AFIO_EXTICR3	(AFIO_BASE + 0x00000010) 	//�ⲿ�ж�ѡ��������� �ж�8~11
#define __AFIO_EXTICR4	(AFIO_BASE + 0x00000014)	//�ⲿ�ж�ѡ��������� �ж�12~15

#define _AFIO_EVCR		ADR(__AFIO_EVCR)		//�¼����ƼĴ���
#define _AFIO_MARP		ADR(__AFIO_MARP)		//IO��ӳ��
#define _AFIO_EXTICR1	ADR(__AFIO_EXTICR1)		//�ⲿ�ж�ѡ��������� �ж�0~3
#define _AFIO_EXTICR2	ADR(__AFIO_EXTICR2)		//�ⲿ�ж�ѡ��������� �ж�4~7	
#define _AFIO_EXTICR3	ADR( __AFIO_EXTICR3)	//�ⲿ�ж�ѡ��������� �ж�8~11
#define _AFIO_EXTICR4	ADR(__AFIO_EXTICR4)		//�ⲿ�ж�ѡ��������� �ж�12~15

#define AFIO_EVCR		VAL(__AFIO_EVCR)		//�¼����ƼĴ���
#define AFIO_MARP		VAL(__AFIO_MARP)		//IO��ӳ��
#define AFIO_EXTICR1	VAL(__AFIO_EXTICR1)		//�ⲿ�ж�ѡ��������� �ж�0~3
#define AFIO_EXTICR2	VAL(__AFIO_EXTICR2)		//�ⲿ�ж�ѡ��������� �ж�4~7	
#define AFIO_EXTICR3	VAL(__AFIO_EXTICR3)	 	//�ⲿ�ж�ѡ��������� �ж�8~11
#define AFIO_EXTICR4	VAL(__AFIO_EXTICR4)		//�ⲿ�ж�ѡ��������� �ж�12~15


//***********************************�¼����ƼĴ���AFIO_EVCR����******************************//
/*
	��������:ʹCortex��EVENTOUT�����ӵ���PORT��PINѡ����I/O�ڡ�
	port: 	000��ѡ��PA 
			001��ѡ��PB 
			010��ѡ��PC 
			011��ѡ��PD 
			100��ѡ��PE
			101: ѡ��PF
			110: ѡ��PG
	PIN:	
	0000��ѡ��Px0 	0001��ѡ��Px1 	0010��ѡ��Px2 
	0011��ѡ��Px3 	0100��ѡ��Px4 	0101��ѡ��Px5 
	0110��ѡ��Px6	0111��ѡ��Px7 	1000��ѡ��Px8 
	1001��ѡ��Px9 	1010��ѡ��Px10 	1011��ѡ��Px11 
	1100��ѡ��Px12 	1101��ѡ��Px13 	1110��ѡ��Px14 
	1111��ѡ��Px15
*/
void AFIO_enable_EVO(U8 port, U8 pin);
void AFIO_disable_EVO(void);			   //���ô˹���



//********************************������ӳ��͵���I/O���üĴ���AFIO_MAPR**************************//

/*
	SWJ_CFG[2:0]��������JTAG���� (Serial wire JTAG configuration) 
	λ26:24 
	��Щλֻ�������д(����Щλ��������δ�������ֵ)��
	��������SWJ�͸��ٸ��ù��ܵ�I/O�ڡ�
	SWJ(������JTAG)֧��JTAG��SWD����Cortex�ĵ��Զ˿ڡ�
	ϵͳ��λ���Ĭ��״̬������SWJ��û�и��ٹ��ܣ�
	����״̬�¿���ͨ��JTMS/JTCK���ϵ��ض��ź�ѡ��JTAG��SW(������)ģʽ��
	000����ȫSWJ(JTAG-DP + SW-DP)����λ״̬�� 
	001����ȫSWJ(JTAG-DP + SW-DP)��û��NJTRST�� 
	010���ر�JTAG-DP������SW-DP�� 
	100���ر�JTAG-DP���ر�SW-DP�� 
	������ϣ������á�
*/
void AFIO_remap_SWJ(U8 conf);		//����SWJӳ��

/*
	ADC2_ETRGREG_REMAP��
	ADC2����ת���ⲿ������ӳ�� (ADC 2 external trigger regular conversion remapping) 
	λ20 
	��λ��������á�1�����á�0������������ADC2����ת���ⲿ���������Ĵ������롣
	����λ�á�0��ʱ��ADC2����ת���ⲿ������EXTI11������
	����λ�á�1��ʱ��ADC2����ת���ⲿ������TIM8_TRGO������
*/
void AFIO_remap_ADC2_REG(U8 conf);

/*
	ADC2_ETRGINJ_REMAP��ADC2ע��ת���ⲿ������ӳ�� (ADC 2 external trigger injected conversion remapping) 
	λ19 ��λ��������á�1�����á�0����
	��������ADC2ע��ת���ⲿ���������Ĵ������롣
	����λ�á�0��ʱ��ADC2ע��ת���ⲿ������EXTI15������
	����λ�á�1��ʱ��ADC2ע��ת���ⲿ������TIM8ͨ��4������
*/
void AFIO_remap_ADC2_INJ(U8 conf);

/*
	ADC1_ETRGREG_REMAP��
	ADC1����ת���ⲿ������ӳ�� (ADC 1 external trigger regular conversion remapping) 
	λ18 
	��λ��������á�1�����á�0������������ADC2����ת���ⲿ���������Ĵ������롣
	����λ�á�0��ʱ��ADC2����ת���ⲿ������EXTI11������
	����λ�á�1��ʱ��ADC2����ת���ⲿ������TIM8_TRGO������
*/
void AFIO_remap_ADC1_REG(U8 conf);

/*
	ADC1_ETRGINJ_REMAP��
	ADC1ע��ת���ⲿ������ӳ�� (ADC 1 external trigger injected conversion remapping) 
	λ17 ��λ��������á�1�����á�0����
	��������ADC2ע��ת���ⲿ���������Ĵ������롣
	����λ�á�0��ʱ��ADC2ע��ת���ⲿ������EXTI15������
	����λ�á�1��ʱ��ADC2ע��ת���ⲿ������TIM8ͨ��4������
*/
void AFIO_remap_ADC1_INJ(U8 conf); 

/*
	TIM5CH4_IREMAP��TIM5ͨ��4�ڲ���ӳ�� (TIM5 channel4 internal remap) 
	λ16 
	��λ��������á�1�����á�0����������TIM5ͨ��4�ڲ�ӳ��
	����λ�á�0��ʱ��TIM5_CH4��PA3������
	����λ�á�1��ʱ��LSI�ڲ�������TIM5_CH4������Ŀ���Ƕ�LSI����У׼��
*/
void AFIO_remap_TIM5CH4(U8 conf);

/*
	PD01_REMAP���˿�D0/�˿�D1ӳ��OSC_IN/OSC_OUT (Port D0/Port D1 mapping on OSC_IN/OSC_OUT) 
	λ15 ��λ��������á�1�����á�0����
	������PD0��PD1��GPIO����ӳ�񡣵���ʹ��������HSEʱ(ϵͳ�������ڲ���8MHz��������)��
	PD0��PD1����ӳ��OSC_IN��OSC_OUT���š�
	�˹���ֻ��������36��48��64���ŵķ�װ(PD0��PD1������100�ź�144�ŵķ�װ�ϣ�������ӳ��)��
	0��������PD0��PD1����ӳ�� 
	1��PD0ӳ��OSC_IN��PD1ӳ��OSC_OUT��
*/
void AFIO_remap_PD01(U8 conf);

/*
	CAN_REMAP[1:0]��CAN���ù�����ӳ�� (CAN alternate function remapping) 
	λ14:13 ��Щλ��������á�1�����á�0������ֻ�е���CAN�ӿڵĲ�Ʒ�Ͽ��Ƹ��ù���CAN_RX��CAN_TX����ӳ�� 
	00��CAN_RXӳ��PA11��CAN_TXӳ��PA12�� 
	01��δ����ϣ� 
	10��CAN_RXӳ��PB8��CAN_TXӳ��PB9(��������36�ŵķ�װ)�� 
	11��CAN_RXӳ��PD0��CAN_TXӳ��PD1��
*/
void AFIO_remap_CAN(U8 conf);

/*
	TIM4_REMAP����ʱ��4����ӳ�� (TIM4 remapping) λ12 ��λ��������á�1�����á�0����
	���ƽ�TIM4��ͨ��1-4ӳ�䵽GPIO�˿��ϡ� 
	0��û����ӳ��(TIM4_CH1/PB6��TIM4_CH2/PB7��TIM4_CH3/PB8��TIM4_CH4/PB9)�� 
	1����ȫӳ��(TIM4_CH1/PD12��TIM4_CH2/PD13��TIM4_CH3/PD14��TIM4_CH4/PD15)�� 
	ע����ӳ��Ӱ����PE0�ϵ�TIM4_ETR��
*/
void AFIO_remap_TIM4(U8 conf);

/*
	TIM3_REMAP[1:0]����ʱ��3����ӳ�� (TIM3 remapping) 
	λ11:10 ��Щλ��������á�1�����á�0�������ƶ�ʱ��3��ͨ��1��4��GPIO�˿ڵ�ӳ�� 
	00��û����ӳ��(CH1/PA6��CH2/PA7��CH3/PB0��CH4/PB1)�� 
	01��δ����ϣ� 
	10������ӳ��(CH1/PB4��CH2/PB5��CH3/PB0��CH4/PB1)�� 
	11����ȫӳ��(CH1/PC6��CH2/PC7��CH3/PC8��CH4/PC9)�� 
	ע����ӳ��Ӱ����PD2�ϵ�TIM3_ETR��
*/
void AFIO_remap_TIM3(U8 conf);

/*
	TIM2_REMAP[1:0]����ʱ��2����ӳ�� (TIM2 remapping) λ9:8 ��Щλ��������á�1�����á�0����
	���ƶ�ʱ��2��ͨ��1��4���ⲿ����(ETR)��GPIO�˿ڵ�ӳ�� 
	00��û����ӳ��(CH1/ETR/PA0��CH2/PA1��CH3/PA2��CH4/PA3)�� 
	01������ӳ��(CH1/ETR/PA15��CH2/PB3��CH3/PA2��CH4/PA3)�� 
	10������ӳ��(CH1/ETR/PA0��CH2/PA1��CH3/PB10��CH4/PB11)�� 
	11����ȫӳ��(CH1/ETR/PA15��CH2/PB3��CH3/PB10��CH4/PB11)��
*/
void AFIO_remap_TIM2(U8 conf);

/*
	TIM1_REMAP[1:0]����ʱ��1����ӳ�� (TIM1 remapping) λ7:6 ��Щλ��������á�1�����á�0����
	���ƶ�ʱ��1��ͨ��1��4��1N��3N���ⲿ����(ETR)��ɲ������(BKIN)��GPIO�˿ڵ�ӳ�� 
	00��û����ӳ��(ETR/PA12��CH1/PA8��CH2/PA9��CH3/PA10��CH4/PA11��BKIN/PB12��CH1N/PB13��CH2N/PB14��CH3N/PB15)��
	01������ӳ��(ETR/PA12��CH1/PA8��CH2/PA9��CH3/PA10��CH4/PA11��BKIN/PA6��CH1N/PA7��CH2N/PB0��CH3N/PB1)�� 
	10: δ����ϣ�
	11: ��ȫӳ��(ETR/PE7��CH1/PE9��CH2/PE11��CH3/PE13��CH4/PE14��BKIN/PE15��CH1N/PE8��CH2N/PE10��CH3N/PE12)��
*/
void AFIO_remap_TIM1(U8 conf);

/*
	USART3_REMAP[1:0]��USART3����ӳ�� (USART3 remapping) λ5:4 ��Щλ��������á�1�����á�0����
	����USART3��CTS��RTS��CK��TX��RX���ù�����GPIO�˿ڵ�ӳ�� 
	00: û����ӳ��(TX/PB10��RX/PB11��CK/PB12��CTS/PB13��RTS/PB14)�� 
	01: ����ӳ��(TX/PC10��RX/PC11��CK/PC12��CTS/PB13��RTS/PB14)�� 
	10: δ����ϣ� 
	11: ��ȫӳ��(TX/PD8��RX/PD9��CK/PD10��CTS/PD11��RTS/PD12)��
*/
void AFIO_remap_USART3(U8 conf);

/*
	USART2_REMAP��USART2����ӳ�� (USART2 remapping) 
	λ3 ��Щλ��������á�1�����á�0��������USART2��CTS��RTS��CK��TX��RX���ù�����GPIO�˿ڵ�ӳ�� 
	0: û����ӳ��(CTS/PA0��RTS/PA1��TX/PA2��RX/PA3��CK/PA4)�� 
	1: ��ӳ��(CTS/PD3��RTS/PD4��TX/PD5��RX/PD6��CK/PD7)��
*/
void AFIO_remap_USART2(U8 conf);

/*
	USART1_REMAP��USART1����ӳ�� (USART1 remapping) 
	λ2 ��λ��������á�1�����á�0��������USART1��TX��RX���ù�����GPIO�˿ڵ�ӳ��
	0: û����ӳ��(TX/PA9��RX/PA10)�� 
	1: ��ӳ��(TX/PB6��RX/PB7)��
*/
void AFIO_remap_USART1(U8 conf);

/*
	I2C1_REMAP��I2C1����ӳ�� (I2C1 remapping) 
	λ1 ��λ��������á�1�����á�0����
	����I2C1��SCL��SDA���ù�����GPIO�˿ڵ�ӳ�� 
	0: û����ӳ��(SCL/PB6��SDA/PB7)�� 
	1: ��ӳ��(SCL/PB8��SDA/PB9)��
*/
void AFIO_remap_I2C1(U8 conf);

/*
	SPI1_REMAP��SPI1����ӳ�� λ0 ��λ��������á�1�����á�0����
	����SPI1��NSS��SCK��MISO��MOSI���ù�����GPIO�˿ڵ�ӳ�� 
	0: û����ӳ��(NSS/PA4��SCK/PA5��MISO/PA6��MOSI/PA7)��
	1: ��ӳ��(NSS/PA15��SCK/PB3��MISO/PB4��MOSI/PB5)��
*/

void AFIO_remap_SPI1(U8 conf);


//**************************************************************�ⲿ�ж����üĴ���AFIO_EXTICR*******************************************//

/*
	EXTIx[3:0]��EXTIx����(x = 0 �� 15) (EXTI x configuration) 
	 ��Щλ���������д������ѡ��EXTIx�ⲿ�жϵ�����Դ��
	 0000��PA[x]���� 0100��PE[x]���� 
	 0001��PB[x]���� 0101��PF[x]���� 
	 0010��PC[x]���� 0110��PG[x]���� 
	 0011��PD[x]����

	extiX:��ȡ0-15����������extiX������Դ
	port:����Դ�� ��0-7 ����8��io�˿ڡ�
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
