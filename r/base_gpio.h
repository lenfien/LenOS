

#ifndef __GPIO
#define	__GPIO

#include "core_map.h"
#include "com.h"

//GPIOA �Ĵ���
#define __GPIOA_CRL		(GPIOA_BASE + 0x00000000)
#define __GPIOA_CRH		(GPIOA_BASE + 0x00000004)
#define __GPIOA_IDR		(GPIOA_BASE + 0x00000008)
#define __GPIOA_ODR		(GPIOA_BASE + 0x0000000C)
#define __GPIOA_BSRR 	(GPIOA_BASE + 0x00000010)
#define __GPIOA_BRR		(GPIOA_BASE + 0x00000014)
#define __GPIOA_LCKR	(GPIOA_BASE + 0x00000018)

//GPIOB �Ĵ���
#define __GPIOB_CRL		(GPIOB_BASE + 0x00000000)
#define __GPIOB_CRH		(GPIOB_BASE + 0x00000004)
#define __GPIOB_IDR		(GPIOB_BASE + 0x00000008)
#define __GPIOB_ODR		(GPIOB_BASE + 0x0000000C)
#define __GPIOB_BSRR 	(GPIOB_BASE + 0x00000010)
#define __GPIOB_BRR		(GPIOB_BASE + 0x00000014)
#define __GPIOB_LCKR	(GPIOB_BASE + 0x00000018)

//GPIOC �Ĵ���
#define __GPIOC_CRL		(GPIOC_BASE + 0x00000000)
#define __GPIOC_CRH		(GPIOC_BASE + 0x00000004)
#define __GPIOC_IDR		(GPIOC_BASE + 0x00000008)
#define __GPIOC_ODR		(GPIOC_BASE + 0x0000000C)
#define __GPIOC_BSRR 	(GPIOC_BASE + 0x00000010)
#define __GPIOC_BRR		(GPIOC_BASE + 0x00000014)
#define __GPIOC_LCKR	(GPIOC_BASE + 0x00000018)

//GPIOD �Ĵ���
#define __GPIOD_CRL		(GPIOD_BASE + 0x00000000)
#define __GPIOD_CRH		(GPIOD_BASE + 0x00000004)
#define __GPIOD_IDR		(GPIOD_BASE + 0x00000008)
#define __GPIOD_ODR		(GPIOD_BASE + 0x0000000C)
#define __GPIOD_BSRR 	(GPIOD_BASE + 0x00000010)
#define __GPIOD_BRR		(GPIOD_BASE + 0x00000014)
#define __GPIOD_LCKR	(GPIOD_BASE + 0x00000018)

//GPIOE �Ĵ���
#define __GPIOE_CRL		(GPIOE_BASE + 0x00000000)
#define __GPIOE_CRH		(GPIOE_BASE + 0x00000004)
#define __GPIOE_IDR		(GPIOE_BASE + 0x00000008)
#define __GPIOE_ODR		(GPIOE_BASE + 0x0000000C)
#define __GPIOE_BSRR 	(GPIOE_BASE + 0x00000010)
#define __GPIOE_BRR		(GPIOE_BASE + 0x00000014)
#define __GPIOE_LCKR	(GPIOE_BASE + 0x00000018)

//GPIOF �Ĵ���
#define __GPIOF_CRL		(GPIOF_BASE + 0x00000000)
#define __GPIOF_CRH		(GPIOF_BASE + 0x00000004)
#define __GPIOF_IDR		(GPIOF_BASE + 0x00000008)
#define __GPIOF_ODR		(GPIOF_BASE + 0x0000000C)
#define __GPIOF_BSRR 	(GPIOF_BASE + 0x00000010)
#define __GPIOF_BRR		(GPIOF_BASE + 0x00000014)
#define __GPIOF_LCKR	(GPIOF_BASE + 0x00000018)

//GPIOF �Ĵ���
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

//���Ͷ���
//����˿�
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


//ģʽ
#define GPIO_INPUT			0x00		//����ģʽ
#define GPIO_OUTPUT_10		0x01		//���ģʽ10MHZ
#define GPIO_OUTPUT_2		0x02		//���ģʽ2MHZ
#define GPIO_OUTPUT_50		0x03		//���ģʽ50MHZ 

//��������
#define GPIO_INPUT_ANA			0x00		//ģ������
#define GPIO_INPUT_FLT			0x01		//��������
#define GPIO_INPUT_PP 			0x02		//����������
#define GPIO_INPUT_KEEP 		0x03		//����

//������� 
#define GPIO_OUTPUT_PUSHPULL 	0x00		//�������
#define GPIO_OUTPUT_OD			0x01		//��©���
#define GPIO_OUTPUT_PUSHPULL_MUL		0x02		//�����������ģʽ
#define GPIO_OUTPUT_OD_MUL		0x03		//���ÿ�©���ģʽ	

/*
	ģʽ����
	����GPIO_port�˿ڵ�GPIO_pin��Ϊģʽconfigure.
	����: 	GPIO_port: 	�����õĶ˿�(ABCDEFG)
			GPIO_pin:	�����ö˿ڵ�����(0-15)
			configure:	����mode��ֵ��ͬ����ͬ ȡ 
		MODE = 00  
			����ģʽ						
			0: ģ������ģʽ
			1: ��������ģʽ
			2: ������ģʽ
			3: ����
		MODE = 1�� 2, 3  
			���ģʽ���ֱ�Ϊ10MHZ, 2MHZ, 50MHZ��������·��Ӧ�ٶ�
			0: ͨ���������ģʽ
			1: ͨ�ÿ������ģʽ
			2: ���ù����������ģʽ
			3: ���ù��ܿ�©���ģʽ
*/
void GPIO_configure(GPIO_PORT GPIO_port, U8 GPIO_pin, U8 mode, U32 configure);

//���ģʽ����
//����Ϊ���ģʽ��2, 10, 50MHZ��� �������
#define GPIO_set_output_2MHZ_PP(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_PUSHPULL)		
#define GPIO_set_output_10MHZ_PP(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_PUSHPULL)	
#define GPIO_set_output_50MHZ_PP(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_PUSHPULL)

//����Ϊ���ģʽ��2, 10, 50MHZ��� ��©���
#define GPIO_set_output_2MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_OD)		
#define GPIO_set_output_10MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_OD)	
#define GPIO_set_output_50MHZ_OD(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_OD)

//����Ϊ���ģʽ��2, 10, 50MHZ��� �����������
#define GPIO_set_output_2MHZ_PP_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_PUSHPULL_MUL)		
#define GPIO_set_output_10MHZ_PP_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_PUSHPULL_MUL)	
#define GPIO_set_output_50MHZ_PP_MUL(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_PUSHPULL_MUL)

//����Ϊ���ģʽ��2, 10, 50MHZ��� ���ÿ�©���
#define GPIO_set_output_2MHZ_OD_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_2, GPIO_OUTPUT_OD_MUL)		
#define GPIO_set_output_10MHZ_OD_MUL(port, pin)	GPIO_configure(port, pin, GPIO_OUTPUT_10, GPIO_OUTPUT_OD_MUL)	
#define GPIO_set_output_50MHZ_OD_MUL(port,pin)	GPIO_configure(port, pin, GPIO_OUTPUT_50, GPIO_OUTPUT_OD_MUL)

//����ģʽ����
#define GPIO_set_input_ANA(port , pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_ANA)	//ģ������
#define GPIO_set_input_FLT(port , pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_FLT)	//��������
#define GPIO_set_input_PP(port, pin)	GPIO_configure(port, pin, GPIO_INPUT, GPIO_INPUT_PP)	//����������

	
/*
	Ϊ�˿����
*/
void GPIO_send_port(GPIO_PORT GPIO_port, U16 data);


/*
	Ϊ�������
*/
void GPIO_send_pin(GPIO_PORT GPIO_port, U8 GPIO_pin, U16 data);


/*
	��ȡ�˿�����
*/
U16  GPIO_receive_port(GPIO_PORT GPIO_port);

#define GPIO_read_port(p)	GPIO_receive_port(p)


/*
	��ȡ��������
*/
U8   GPIO_receive_pin(GPIO_PORT GPIO_port, U8 GPIO_pin);

#define GPIO_read_pin(port, pin) GPIO_receive_pin(port, pin)

#endif
