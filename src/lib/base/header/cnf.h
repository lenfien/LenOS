

#ifndef __CNF__
#define __CNF__




#ifndef __Q_ADC
#define __Q_ADC

#include "com.h"

//��ʼ��ADC1��ͨ��10(PC0����)
void ADC1_IN10_init(void);
void ADC1_start_conversion(void);

#endif



#ifndef _Q_TIM18
#define _Q_TIM18

#include "com.h"


//��time1����ΪnUs��us����һ��
//���ڼ���preLoad�κ�����ж�
void TIM1_init_us(U32 us, U32 pre);

//��time1����ΪnMs��ms����һ��
//���ڼ���preLoad�κ�����ж�
void TIM1_init_ms(U32 nMs, U32 preLoad);

void TIM1_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH1_set_pwm_duty(U32 duty_us);

void TIM1_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH2_set_pwm_duty(U32 duty_us);

void TIM1_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput);
void TIM1_CH3_set_pwm_duty(U32 duty_us);

void TIM1_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos);
void TIM1_CH4_set_pwm_duty(U32 duty_us);



//��time8����ΪnUs��us����һ��
//���ڼ���preLoad�κ�����ж�
void TIM8_init_us(U32 us, U32 pre);

//��time1����ΪnMs��ms����һ��
//���ڼ���preLoad�κ�����ж�
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

//�رպͱ�������ص�����ģ��
void BKP_shutdown(void);

//����data��������Ĵ����е�xλ��
//���ظ�λ��֮ǰֵ
U16 BKP_save_data(U16 data, U8 x);

//��λ������Ĵ����е�����ֵΪ0
void BKP_reset(void);

#endif




#ifndef	__Q_CRC
#define __Q_CRC

void CRC_init(void);

/*
	�˺������������ pData ����ʼ����pData + dataSize*4��֮������ݵ�CRC�롣
*/
U32 CRC_check_data(U32 *pData, U32 dataSize);

#endif


#ifndef __CNF_DAC
#define __CND_DAC
/*
	mode1
	����Channel1Ϊ�Ǵ���������ͨģʽ
	�ڴ�ģʽ�£�ֻҪһ��DHRx�Ĵ�����д�������ͻ�����ת�Ƶ�DORx�У�����3��APB1ʱ�Ӻ�
	���������
	��ʹ��DMA
	����������
	���������ǲ�
	�����ѹ�ɵ�
*/
void DAC_cnf_mode1(void);


//��ģʽ1��ʹ�ܺ󣬵��ô˺���,�����ѹ���ɷ����仯
void DAC_cnf_write_holding_data(U16 hd);



/*
	Channel1���ó��������ģʽ�µ���ͨģʽ
	12λ�Ҷ���ģʽ
	���������
	����ת��
	�������
	�޲��β���
*/
void DAC_cnf_mode2(void);


/*
	Channel1����Ϊ����ģʽ�µ����ǲ�������
	12λ�Ҷ���
	�������
	���ǲ��в���
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
	����ϵͳʱ��
	����hour, min ,sec,�㶮��
*/
void RTC_set_syetem_time(int hour, int min, int sec);	

/*
	RTC�����ó�ÿ�����һ���жϵ�ģʽ,����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/
void RTC_init_per_1_second(U8 new_or_old);		//1, 0


/*
	RTC�����ó�ÿper_ms�������һ���жϵ�ģʽ,
	����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/
void RTC_init(U32 per_ms, U8 new_or_old);
#endif


#ifndef __CNF_SYSTICK
#define __CNF_SYSTICK

void SYSTICK_init(void);

//��Systick���ó�msΪ��λ�жϵĺ���
void SYSTICK_init_ms(U32 ms);

#endif



#ifndef __Q_USART
#define __Q_USART

typedef enum 
{
	BAUD_9600, BAUD_115200
}USART_BAUD_RATE;

void USART1_init(USART_BAUD_RATE);

//����ַ�
void USART1_put_char(char c);

//����ַ���
int USART1_put_string(char *str);

int USART1_put_int(int i);

int USART1_put_float(float f);

int USART1_put_double(double d);

int USART1_put_long(long l);

int USART1_printf(char *format, ...);



void USART2_init(USART_BAUD_RATE);

//����ַ�
void USART2_put_char(char c);

//����ַ���
int USART2_put_string(char *str);

int USART2_put_int(int i);

int USART2_put_float(float f);

int USART2_put_double(double d);

int USART2_put_long(long l);

int USART2_printf(char *format, ...);
#endif



#endif
