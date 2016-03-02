

#ifndef __GPIO
#define	__GPIO

#include "core_map.h"
#include "com.h"

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
