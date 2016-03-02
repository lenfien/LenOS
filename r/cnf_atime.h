
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
