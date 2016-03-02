

#ifndef __CNF__
#define __CNF__




#ifndef __Q_ADC
#define __Q_ADC

#include "com.h"

//初始化ADC1的通道10(PC0引脚)
void ADC1_IN10_init(void);
void ADC1_start_conversion(void);

#endif



#ifndef _Q_TIM18
#define _Q_TIM18

#include "com.h"


//将time1配置为nUs个us计数一次
//并在计数preLoad次后产生中断
void TIM1_init_us(U32 us, U32 pre);

//将time1配置为nMs个ms计数一次
//并在计数preLoad次后产生中断
void TIM1_init_ms(U32 nMs, U32 preLoad);

void TIM1_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH1_set_pwm_duty(U32 duty_us);

void TIM1_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH2_set_pwm_duty(U32 duty_us);

void TIM1_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH3_set_pwm_duty(U32 duty_us);

void TIM1_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos);
void TIM1_CH4_set_pwm_duty(U32 duty_us);



//将time8配置为nUs个us计数一次
//并在计数preLoad次后产生中断
void TIM8_init_us(U32 us, U32 pre);

//将time1配置为nMs个ms计数一次
//并在计数preLoad次后产生中断
void TIM8_init_ms(U32 nMs, U32 preLoad);

void TIM8_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM8_CH1_set_pwm_duty(U32 duty_us);

void TIM8_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM8_CH2_set_pwm_duty(U32 duty_us);

void TIM8_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM8_CH3_set_pwm_duty(U32 duty_us);

void TIM8_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos);
void TIM8_CH4_set_pwm_duty(U32 duty_us);
#endif

#ifndef __CNF_BKP
#define __CNF_BKP

void BKP_init(void);

//关闭和备份域相关的所有模块
void BKP_shutdown(void);

//保存data到备份域寄存器中的x位置
//返回该位置之前值
U16 BKP_save_data(U16 data, U8 x);

//复位备份域寄存器中的所有值为0
void BKP_reset(void);

#endif




#ifndef	__Q_CRC
#define __Q_CRC

void CRC_init(void);

/*
	此函数用来计算从 pData 处开始，到pData + dataSize*4处之间的数据的CRC码。
*/
U32 CRC_check_data(U32 *pData, U32 dataSize);

#endif


#ifndef __CNF_DAC
#define __CND_DAC
/*
	mode1
	配置Channel1为非触发的最普通模式
	在此模式下，只要一往DHRx寄存器里写东西，就会立即转移到DORx中，并在3个APB1时钟后
	输出到引脚
	不使能DMA
	不开启噪音
	不开启三角波
	输出电压可调
*/
void DAC_cnf_mode1(void);


//在模式1下使能后，调用此函数,输出电压即可发生变化
void DAC_cnf_write_holding_data(U16 hd);



/*
	Channel1配置成软件触发模式下的普通模式
	12位右对齐模式
	带输出缓冲
	触发转换
	软件触发
	无波形产生
*/
void DAC_cnf_mode2(void);


/*
	Channel1配置为触发模式下的三角波发生器
	12位右对齐
	软件触发
	三角波行产生
*/
void DAC_cnf_mode3(void);


#endif


void DMA1_CH1_init(void);




#ifndef CNF_I2C
#define CNF_I2C

void I2C1_cnf_init(void);


#endif


#ifndef __Q_RCC
#define __Q_RCC


void RCC_init(void);


#endif

#ifndef __Q_RCC
#define __Q_RCC

void RCC_init(void);

#endif


#ifndef __Q_RTC
#define __Q_RTC

#include "com.h"
/*
	设置系统时间
	参数hour, min ,sec,你懂得
*/
void RTC_set_syetem_time(int hour, int min, int sec);	

/*
	RTC被配置成每秒产生一个中断的模式,并且它的起始值从0开始还是从之前的计数开始取决于参数
*/
void RTC_init_per_1_second(U8 new_or_old);		//1, 0


/*
	RTC被配置成每per_ms毫秒产生一个中断的模式,
	并且它的起始值从0开始还是从之前的计数开始取决于参数
*/
void RTC_init(U32 per_ms, U8 new_or_old);
#endif


#ifndef __CNF_SYSTICK
#define __CNF_SYSTICK

void SYSTICK_init(void);

//将Systick配置成ms为单位中断的函数
void SYSTICK_init_ms(U32 ms);

#endif



#ifndef __Q_USART
#define __Q_USART

typedef enum 
{
	BAUD_9600, BAUD_115200
}USART_BAUD_RATE;

void USART1_init(USART_BAUD_RATE);

//输出字符
void USART1_put_char(char c);

//输出字符串
int USART1_put_string(char *str);

int USART1_put_int(int i);

int USART1_put_float(float f);

int USART1_put_double(double d);

int USART1_put_long(long l);

int USART1_printf(char *format, ...);



void USART2_init(USART_BAUD_RATE);

//输出字符
void USART2_put_char(char c);

//输出字符串
int USART2_put_string(char *str);

int USART2_put_int(int i);

int USART2_put_float(float f);

int USART2_put_double(double d);

int USART2_put_long(long l);

int USART2_printf(char *format, ...);
#endif



#endif
