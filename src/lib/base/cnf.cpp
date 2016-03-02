
/***********************************************************************************************/
//ADC
/***********************************************************************************************/
#include "base.h"
#include "com.h"

//初始化ADC1的通道10(PC0引脚)

#define CHANNEL 10
#define PORT	GPIO_C
#define PIN		0

void ADC1_IN10_init()
{
//ADC引脚配置
	RCC_enable_GPIO_x_clock(PORT);
	GPIO_set_input_ANA(PORT, PIN);				//PC.0配置输入模拟
	
	RCC_enable_ADC1_clock();					//给ADC1提供时钟

//ADC配置
	//ADC1_enable_interrupt_at_convert_end();		//使能在转换完成后产生中断
	//NVIC_enable_interrupt(_ADC1_2_IRQn);		//NVIC使能中断
	
	ADC1_set_data_align_right();						//转换后的数据存放的对其方式
	//ADC1_set_conversion_in_continuous_mode();	//在连续模式下转换
	ADC1_set_conversion_in_single_mode();	    //在单一模式下转换
	ADC1_set_sample_time_41_5(CHANNEL);			//41.5个采样周期
	
	ADC1_set_sequence_length_1();				//要转换的通道数为1
	
	ADC1_set_sequence1(CHANNEL);                //在序列的第一个中为CHANNEL
	
	ADC1_enable_DMA();							//使能DMA
	
	
//ADC唤醒
	ADC1_wake_up_ADC();							//第一次启动为唤醒
	delay_us(200);								//等待稳定
	
	//ADC校准
	ADC1_reset_calibration();					//复位ADC的校准
	while(!ADC1_is_reset_calibration_done());	//是否复位完成
	ADC1_start_calibration();                   //开始校准
	while(!ADC1_is_calibration_done());			//等待校准完成	
}

void ADC1_cnf_temperature()
{
	RCC_enable_ADC1_clock();
	ADC1_enable_interrupt_at_convert_end();
	NVIC_enable_interrupt(_ADC1_2_IRQn);
	ADC1_set_sample_time_41_5(16);
	ADC1_enable_temperature();
	delay_ms(100);
	ADC1_wake_up_ADC();
	ADC1_set_sequence1(16);
	ADC1_set_sequence_length_1();
	ADC1_set_conversion_in_continuous_mode();
	
	ADC1_enable_ADC();
}


//开始转换
void ADC1_start_conversion()
{
	ADC1_enable_ADC();							
}


/***********************************************************************************************/
//Atime
/***********************************************************************************************/
#include "base.h"
#include "cnf.h"
//***********************************************************************************//
//*************************************TIM1的配置************************************//
//***********************************************************************************//


//将time1配置为nUs个us计数一次
//并在计数preLoad次后产生中断
void TIM1_init_us(U32 nUs, U32 reLoad)
{
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，根据RCC的配置，这里的时钟时48MHZ
	TIM1_set_slave_inside_clock();			//选择内部时钟为TIM1时钟
	TIM1_set_counter_prescaler(48 * nUs);			//设置48分频,则每1us计数一次
	TIM1_set_repetition_counter(0);				//重复计数寄存器为1000
	TIM1_set_counter_auto_reload(reLoad);        		//设置预装载寄存器为1000
	TIM1_set_counter(0);                	//设置计数器的值为0
	TIM1_set_counter_direction_up();		//设置为向上计数
	TIM1_set_update_source_overflow(); 	//更新事件只在溢出时发生
	TIM1_enable_interrupt_at_update_event();//在更新事件时发生中断
	//TIM1_disable_extern_clock();		
	NVIC_enable_interrupt(_TIM1_UP_IRQn); 	//NVIC设置更新事件中断允许
	TIM1_enable_counter();                  //开始计数
}


//将time1配置为nMs个ms计数一次
//并在计数reLoad次后产生中断
//nMs为计数器每nMs计数一次
//reLoad为计数reLoad次产生中断
void TIM1_init_ms(U32 nMs, U32 reLoad)
{
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，根据RCC的配置，这里的时钟时48MHZ
	TIM1_set_slave_inside_clock();			//选择内部时钟为TIM1时钟
	TIM1_set_counter_prescaler(48000 * nMs);	//设置48分频,则每1ms计数一次
	TIM1_set_repetition_counter(0);				//重复计数寄存器为1000
	TIM1_set_counter_auto_reload(reLoad);        		//设置预装载寄存器为1000
	TIM1_set_counter(0);                	//设置计数器的值为0
	TIM1_set_counter_direction_up();		//设置为向上计数
	TIM1_set_update_source_overflow(); 	//更新事件只在溢出时发生
	TIM1_enable_interrupt_at_update_event();//在更新事件时发生中断
	//TIM1_disable_extern_clock();				
	NVIC_enable_interrupt(_TIM1_UP_IRQn); 	//NVIC设置更新事件中断允许
	TIM1_enable_counter();                  //开始计数
}

//***************************TIM1_CH1产生PWM********************************//
/*
	从TIM1的通道1产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PA8		
		互补输出:	PB13	
*/
void TIM1_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 8);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 13);	
	
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，48MHZ
	TIM1_set_slave_inside_clock();			//计数器时钟设为内部时钟
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM1_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM1_set_repetition_counter(0);				//重复计数器为0
	TIM1_set_CCR1(ccr);							//设置捕获比较寄存器
	
	TIM1_set_channel1_output();				//通道一配置为输出
	TIM1_disable_OC1_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM1_set_OC1_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM1_set_OC1_PWM2_mode();			//如果是PWM模式2
	
	TIM1_enable_CCR1_preload();			//使能通道1的的预装载功能
	TIM1_set_CC1_polarity_high();			//设置OC1的输出为高电平有效
	TIM1_set_CC1N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM1_enable_main_output();				//主使能输出
	
	TIM1_enable_CC1();						//使能输出
	if(complementOutput)
		TIM1_enable_CC1N();						//互补使能输出
	
	TIM1_enable_counter();					//使能计数器
}

void TIM1_CH1_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR1(duty_us);
}


//***************************TIM1_CH2产生PWM********************************//
/*
	从TIM1的通道2产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PA9		
		互补输出:	PB14	
*/
void TIM1_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 9);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 14);	
	
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，48MHZ
	TIM1_set_slave_inside_clock();			//计数器时钟设为内部时钟
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM1_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM1_set_repetition_counter(0);				//重复计数器为0
	TIM1_set_CCR2(ccr);							//设置捕获比较寄存器
	
	TIM1_set_channel2_output();				//通道一配置为输出
	TIM1_disable_OC2_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM1_set_OC2_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM1_set_OC2_PWM2_mode();			//如果是PWM模式2
	
	TIM1_enable_CCR2_preload();			//使能通道1的的预装载功能
	TIM1_set_CC2_polarity_high();			//设置OC1的输出为高电平有效
	TIM1_set_CC2N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM1_enable_main_output();				//主使能输出
	
	TIM1_enable_CC2();						//使能输出
	if(complementOutput)
		TIM1_enable_CC2N();						//互补使能输出
	
	TIM1_enable_counter();					//使能计数器
}

void TIM1_CH2_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR2(duty_us);
}


//***************************TIM1_CH3产生PWM********************************//
/*
	从TIM1的通道3产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PA10		
		互补输出:	PB15	
*/
void TIM1_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 10);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 15);	
	
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，48MHZ
	TIM1_set_slave_inside_clock();			//计数器时钟设为内部时钟
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM1_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM1_set_repetition_counter(0);				//重复计数器为0
	TIM1_set_CCR3(ccr);							//设置捕获比较寄存器
	
	TIM1_set_channel3_output();				//通道一配置为输出
	TIM1_disable_OC3_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM1_set_OC3_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM1_set_OC3_PWM2_mode();			//如果是PWM模式2
	
	TIM1_enable_CCR3_preload();			//使能通道1的的预装载功能
	TIM1_set_CC3_polarity_high();			//设置OC1的输出为高电平有效
	TIM1_set_CC3N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM1_enable_main_output();				//主使能输出
	
	TIM1_enable_CC3();						//使能输出
	if(complementOutput)
		TIM1_enable_CC3N();						//互补使能输出
	
	TIM1_enable_counter();					//使能计数器
}

void TIM1_CH3_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR3(duty_us);
}



//***************************TIM1_CH4产生PWM********************************//
/*
	从TIM1的通道4产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PA11		
		互补输出:	无互补输出
*/
void TIM1_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos)
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 11);
	
	RCC_enable_TIM1_clock();				//给TIM1提供时钟，48MHZ
	TIM1_set_slave_inside_clock();			//计数器时钟设为内部时钟
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM1_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM1_set_repetition_counter(0);				//重复计数器为0
	TIM1_set_CCR4(duty_pos);							//设置捕获比较寄存器
	
	TIM1_set_channel4_output();				//通道一配置为输出
	TIM1_disable_OC4_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM1_set_OC4_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM1_set_OC4_PWM2_mode();			//如果是PWM模式2
	
	TIM1_enable_CCR4_preload();				//使能通道1的的预装载功能
	TIM1_set_CC4_polarity_high();			//设置OC1的输出为高电平有效
	
	TIM1_enable_main_output();				//主使能输出
	TIM1_enable_CC4();						//使能输出
	TIM1_enable_counter();					//使能计数器
}

void TIM1_CH4_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR4(duty_us);
}


//***********************************************************************************//
//*************************************TIM1的配置************************************//
//***********************************************************************************//


//将TIM8配置为nUs个us计数一次
//并在计数preLoad次后产生中断
void TIM8_init_us(U32 nUs, U32 reLoad)
{
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，根据RCC的配置，这里的时钟时48MHZ
	TIM8_disable_slave_mode();			//选择内部时钟为TIM8时钟
	TIM8_set_counter_prescaler(48 * nUs);			//设置48分频,则每1us计数一次
	TIM8_set_repetition_counter(0);				//重复计数寄存器为1000
	TIM8_set_counter_auto_reload(reLoad);        		//设置预装载寄存器为1000
	TIM8_set_counter(0);                	//设置计数器的值为0
	TIM8_set_counter_direction_up();		//设置为向上计数
	TIM8_set_update_source_overflow(); 	//更新事件只在溢出时发生
	TIM8_enable_interrupt_at_update_event();//在更新事件时发生中断
	//TIM8_disable_extern_clock();		
	NVIC_enable_interrupt(_TIM8_UP_IRQn); 	//NVIC设置更新事件中断允许
	TIM8_enable_counter();                  //开始计数
}


//将time1配置为nMs个ms计数一次
//并在计数preLoad次后产生中断
//nMs计数一次,计数reLoad次产生中断
void TIM8_init_ms(U32 nMs, U32 reLoad)
{
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，根据RCC的配置，这里的时钟时48MHZ
	TIM8_disable_slave_mode();			//选择内部时钟为TIM8时钟
	TIM8_set_counter_prescaler(48000 * nMs);			//设置48分频,则每1ms计数一次
	TIM8_set_repetition_counter(0);				//重复计数寄存器为1000
	TIM8_set_counter_auto_reload(reLoad);        		//设置预装载寄存器为1000
	TIM8_set_counter(0);                	//设置计数器的值为0
	TIM8_set_counter_direction_up();		//设置为向上计数
	TIM8_set_update_source_overflow(); 	//更新事件只在溢出时发生
	TIM8_enable_interrupt_at_update_event();//在更新事件时发生中断
	//TIM8_disable_extern_clock();				
	NVIC_enable_interrupt(_TIM8_UP_IRQn); 	//NVIC设置更新事件中断允许
	TIM8_enable_counter();                  //开始计数
}

//***************************TIM8_CH1产生PWM********************************//
/*
	从TIM8的通道1产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PC6		
		互补输出:	PA7	
*/
void TIM8_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_A_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 6);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 7);	
	
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，48MHZ
	TIM8_disable_slave_mode();			//计数器时钟设为内部时钟
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM8_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM8_set_repetition_counter(0);				//重复计数器为0
	TIM8_set_CCR1(ccr);							//设置捕获比较寄存器
	
	TIM8_set_channel1_output();				//通道一配置为输出
	TIM8_disable_OC1_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM8_set_OC1_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM8_set_OC1_PWM2_mode();			//如果是PWM模式2
	
	TIM8_enable_CCR1_preload();			//使能通道1的的预装载功能
	TIM8_set_CC1_polarity_high();			//设置OC1的输出为高电平有效
	TIM8_set_CC1N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM8_enable_main_output();				//主使能输出
	
	TIM8_enable_CC1();						//使能输出
	if(complementOutput)
		TIM8_enable_CC1N();					//互补使能输出
	
	TIM8_enable_counter();					//使能计数器
}

void TIM8_CH1_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR1(duty_us);
}


//***************************TIM8_CH2产生PWM********************************//
/*
	从TIM8的通道2产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PC7	
		互补输出:	PB0	
*/
void TIM8_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 7);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 0);	
	
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，48MHZ
	TIM8_disable_slave_mode();			//计数器时钟设为内部时钟
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM8_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM8_set_repetition_counter(0);				//重复计数器为0
	TIM8_set_CCR2(ccr);							//设置捕获比较寄存器
	
	TIM8_set_channel2_output();				//通道一配置为输出
	TIM8_disable_OC2_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM8_set_OC2_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM8_set_OC2_PWM2_mode();			//如果是PWM模式2
	
	TIM8_enable_CCR2_preload();			//使能通道1的的预装载功能
	TIM8_set_CC2_polarity_high();			//设置OC1的输出为高电平有效
	TIM8_set_CC2N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM8_enable_main_output();				//主使能输出
	
	TIM8_enable_CC2();						//使能输出
	if(complementOutput)
		TIM8_enable_CC2N();						//互补使能输出
	
	TIM8_enable_counter();					//使能计数器
}

void TIM8_CH2_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR2(duty_us);
}


//***************************TIM8_CH3产生PWM********************************//
/*
	从TIM8的通道3产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PC8	
		互补输出:	PB1
*/
void TIM8_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 8);
	
	if(complementOutput)					//如果主调要求互补输出,则配置互补输出IO脚(注意:影响到触摸屏)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 1);	
	
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，48MHZ
	TIM8_disable_slave_mode();			//计数器时钟设为内部时钟
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM8_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM8_set_repetition_counter(0);				//重复计数器为0
	TIM8_set_CCR3(ccr);							//设置捕获比较寄存器
	
	TIM8_set_channel3_output();				//通道一配置为输出
	TIM8_disable_OC3_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM8_set_OC3_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM8_set_OC3_PWM2_mode();			//如果是PWM模式2
	
	TIM8_enable_CCR3_preload();			//使能通道1的的预装载功能
	TIM8_set_CC3_polarity_high();			//设置OC1的输出为高电平有效
	TIM8_set_CC3N_polarity_high();			//设置OC1N的输出为低电平有效
	
	TIM8_enable_main_output();				//主使能输出
	
	TIM8_enable_CC3();						//使能输出
	if(complementOutput)
		TIM8_enable_CC3N();						//互补使能输出
	
	TIM8_enable_counter();					//使能计数器
}

void TIM8_CH3_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR3(duty_us);
}



//***************************TIM8_CH4产生PWM********************************//
/*
	从TIM8的通道4产生一路PWM波 
		period_us:  周期
		duty_us:	占空比
		duty_pos:	
			0:高电平在每一周期的起始位置
			1:高电平在每一周期的末尾位置
		complementOutput:
			是否允许互补输出
	输出引脚:
		正输出:		PC9	
		互补输出:	无互补输出
*/
void TIM8_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos)
{
	RCC_enable_GPIO_C_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 9);
	
	RCC_enable_TIM8_clock();				//给TIM8提供时钟，48MHZ
	TIM8_disable_slave_mode();			//计数器时钟设为内部时钟
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//设置分频为48,计数器每一微秒计数一次
	TIM8_set_counter_auto_reload(period_us);	//设计计数器的重计数20，这样就是20ms计数一次，1s内计数50次
	TIM8_set_repetition_counter(0);				//重复计数器为0
	TIM8_set_CCR4(duty_pos);							//设置捕获比较寄存器
	
	TIM8_set_channel4_output();				//通道一配置为输出
	TIM8_disable_OC4_clear();				//禁用通道输出的复位模式
	
	if(!duty_pos)							//如果是PWM模式1
		TIM8_set_OC4_PWM1_mode();			//通道配置为输出PWM模式
	else
		TIM8_set_OC4_PWM2_mode();			//如果是PWM模式2
	
	TIM8_enable_CCR4_preload();				//使能通道1的的预装载功能
	TIM8_set_CC4_polarity_high();			//设置OC1的输出为高电平有效
	
	TIM8_enable_main_output();				//主使能输出
	TIM8_enable_CC4();						//使能输出
	TIM8_enable_counter();					//使能计数器
}

void TIM8_CH4_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR4(duty_us);
}




/***********************************************************************************************/
//CRC
/***********************************************************************************************/



//经过测试， CRC不能由模拟器模拟，只能接上板子才能正确运行。

#include "base.h"
#include "com.h"


void CRC_init()
{
	RCC_enable_CRC_clock();	//使能CRC时钟
	CRC_reset();			//重置CRC
}


/*
	此函数用来计算从 pData 处开始，到pData + dataSize*4处之间的数据的CRC码。
*/
U32 CRC_check_data(U32 *pData, U32 dataSize)
{
	int temp = 0;
	for(temp =0; temp < dataSize; temp ++)
		CRC_set_value(*(pData + temp));   
	temp = CRC_get_result();		//获得结果
	CRC_reset();
	return temp;
}


/***********************************************************************************************/
//DMA
/***********************************************************************************************/


#include "base.h"
#include "com.h"



//将DMA1的CH1通道配置为存储器到存储器传输 从0x20000000到0x20000010的数据传输 只传输一个位
void DMA1_CH1_init()
{
	RCC_enable_DMA1_clock();							//给DMA1提供时钟
	
	DMA1_CH1_set_peripheral_address(__ADC1_DR);
	DMA1_CH1_set_memory_address((int)0);
	//DMA1_CH1_enable_MEM2MEM();							//使能存储器到存储器, 使能DMA后，传输将自动开始
	
	DMA1_CH1_set_transfer_number(320);					//传送的数量
	//DMA1_CH1_enable_peripheral_increment_mode();  		//使能外设增量
	
	DMA1_CH1_disable_peripheral_increment_mode();		//外设增量模式禁止
	DMA1_CH1_enable_memory_increment_mode();      		//使能存储器增量
	DMA1_CH1_enable_circular_mode();					//循环模式
	DMA1_CH1_set_transfer_direction_from_peripheral(); 	//方向是从外设到存储器
	DMA1_CH1_set_priority_veryhigh();					//设置优先级有最高
	
	DMA1_CH1_set_memory_size_16();						//设置存储器尺寸为32
	DMA1_CH1_set_peripheral_size_16();					//设置外设尺寸为32

	DMA1_CH1_enable_interrupt_at_transfer_complete();	//传输完毕后激活中断
	DMA1_CH1_disable_interrupt_at_transfer_half();		//不使能
	NVIC_enable_interrupt(_DMA1_Channel1_IRQn);         //内部NVIC允许中断
	
	DMA1_CH1_enable_channel(); 							//使能channel1
}
 


/***********************************************************************************************/
//RCC
/***********************************************************************************************/
#include "base.h"



//将内部工作时钟配置到最高

void RCC_init()
{
//启动时钟前的配置
	RCC_set_PLLXTPRE_HSE_1();		//HSE入口处分频
	RCC_set_PLLSRC_HSE();				//设置PLL时钟源
	RCC_set_PLLMUL_6();					//外部8MHZ晶体倍频到48MHZ
	RCC_set_AHBPRE_1();					//AHB设置为不分频
	RCC_set_APB1PRE_2();				//APB1总线设置2分频 为24MHZ
	RCC_set_APB2PRE_1();				//APB2总线设置不分频 为48MHZ
	
	//ADC时钟配置
	//设置时钟，由于ADC1在APB2总线上(48MHZ在systeminit中配置),
	//ADC1的时钟最高14MHZ，所以4分频，以12MHZ工作
	RCC_set_ADC_prescaler_4(); 		//将APB24分频 12MHZ
	
//启动外部HSE时钟
	RCC_enable_HSE();				//开启外部时钟
	while(!RCC_is_HSI_ready());		//等待外部时钟稳定
	RCC_enable_PLL();				//开启分频
	while(!RCC_is_PLL_ready());		//等待PLL稳定
	RCC_set_SW_PLLCLK();			//设置系统时钟源为PLL所产生的时钟
	RCC_disable_HSI();				//关掉内部HSI
}

//低频模式
void _RCC_init()
{
	//启动时钟前的配置
	RCC_set_PLLXTPRE_HSE_1();		//HSE入口处分频
	RCC_set_PLLSRC_HSE();				//设置PLL时钟源
	RCC_set_PLLMUL_2();					//外部8MHZ晶体倍频到16MHZ
	RCC_set_AHBPRE_1();					//AHB设置为不分频
	RCC_set_APB1PRE_2();				//APB1总线设置2分频为8MHZ
	RCC_set_APB2PRE_1();				//APB2总线设置不分频为16MHZ
	
	//ADC时钟配置
	//设置时钟，由于ADC1在APB2总线上(48MHZ在systeminit中配置),
	//ADC1的时钟最高14MHZ，所以4分频，以12MHZ工作
	RCC_set_ADC_prescaler_4(); 		//将APB24分频 12MHZ
	
//启动外部HSE时钟
	RCC_enable_HSE();				//开启外部时钟
	while(!RCC_is_HSI_ready());		//等待外部时钟稳定
	RCC_enable_PLL();				//开启分频
	while(!RCC_is_PLL_ready());		//等待PLL稳定
	RCC_set_SW_PLLCLK();			//设置系统时钟源为PLL所产生的时钟
	RCC_disable_HSI();				//关掉内部HSI
}



/***********************************************************************************************/
//RTC
/***********************************************************************************************/


#include "com.h"

#include "cnf.h"
#include "base.h"

/*
	RTC被配置成每秒产生一个中断的模式,并且它的起始值从0开始还是从之前的计数开始取决于参数
*/

void RTC_init_per_1_second(U8 new_or_old)		//1, 0
{
	RCC_enable_PWR_clock();						//给PWR提供时钟
	PWR_disable_domain_backup_protection();		//关闭的后备域保护
	
	//设置后备域
	RCC_enable_LSE();
	while(!RCC_is_LSE_ready());			//等待外部晶振稳定
	RCC_set_RTCSEL_LSE();				//设置RTC时钟源为LSE
	RCC_enable_RTC();					//开启RTC啊
	
	RTC_wait_sync();					//等待复位后和APB1的同步
	RTC_enter_configure_mode();			//进入配置模式
	RTC_wait_operation_done();			//等待可写
	
	RTC_wait_operation_done();			//等待可写
	if(new_or_old)
	{
		RTC_set_system_time(0x00);		//设置当前的系统时间
		RTC_wait_operation_done();		//等待可写
	}
	RTC_set_prescaler(0x7FFF);
	RTC_exit_configure_mode();
	RTC_wait_operation_done();

	PWR_enable_domain_backup_protection();		//关闭的后备域保护
	
	RTC_enable_interrupt_at_second();	//使能时钟中断
	NVIC_enable_interrupt(3);	
}


/*
	RTC被配置成每per_ms毫秒产生一个中断的模式,
	并且它的起始值从0开始还是从之前的计数开始取决于参数
*/
void RTC_init(U32 per_ms, U8 new_or_old)					//1, 0
{
	U32 div = (0x7FFF/1000) * per_ms;			//计算per_ms所需要的分频系数
	RCC_enable_PWR_clock();						//给PWR提供时钟
	PWR_disable_domain_backup_protection();		//关闭的后备域保护
	
	//设置后备域
	RCC_enable_LSE();
	while(!RCC_is_LSE_ready());			//等待外部晶振稳定
	RCC_set_RTCSEL_LSE();				//设置RTC时钟源为LSE
	RCC_enable_RTC();					//开启RTC啊
	
	RTC_wait_sync();					//等待复位后和APB1的同步
	RTC_enter_configure_mode();			//进入配置模式
	RTC_wait_operation_done();			//等待可写
	
	RTC_wait_operation_done();			//等待可写
	if(new_or_old)
	{
		RTC_set_system_time(0x00);		//设置当前的系统时间
		RTC_wait_operation_done();		//等待可写
	}
	RTC_set_prescaler(div);	
	RTC_exit_configure_mode();
	RTC_wait_operation_done();

	PWR_enable_domain_backup_protection();		//关闭的后备域保护
	
	RTC_enable_interrupt_at_second();	//使能时钟中断
	NVIC_enable_interrupt(3);	
}





//设置系统时间
//参数hour, min ,sec,你懂得
void RTC_set_syetem_time(int hour, int min, int sec)
{
	int result = hour * 3600 + min * 60 + sec;
	RCC_enable_PWR_clock();
	PWR_disable_domain_backup_protection();
	RTC_enter_configure_mode();
	RTC_set_system_time(result);
	RTC_wait_operation_done();
	RTC_exit_configure_mode();
	RTC_wait_operation_done();
	PWR_enable_domain_backup_protection();
}



/***********************************************************************************************/
//USART
/***********************************************************************************************/
#include <stdio.h>
#include <stdarg.h>


#include "base.h"

#include "cnf.h"


//USART1_TX	PA9
//USART1_RX PA10
//将USART1配置成9600波特率
//bautRate : 9600 / 115200
void USART1_init(USART_BAUD_RATE baudRate)
{
	//配置引脚
	RCC_enable_GPIO_A_clock();			//使能GPIO_A端口时钟
	RCC_enable_AFIO_clock();			//使能AFIO时钟 特殊功能的USART将要被使用
	RCC_enable_USART1_clock();			//USART1时钟使能
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 9);	//将 GPA9 配置为特殊功能
	GPIO_set_input_PP(GPIO_A, 10);				//将 GPA10配置为上下拉输入
	
	USART1_enable();					//使能USART1
	
	USART1_set_word_length_8_bit();		//设置传送字长为1位起始位，8位数据位,n位停止位
	USART1_set_stop_length_1();			//设置停止位长度为1
	
	USART1_set_div(baudRate == BAUD_9600 ? 312.5 : 26.04);				//设置DIV为31.25， 波特率为9600
	USART1_enable_parity_check();
	
	//USART1_enable_interrupt_at_transmit_complete();	//使能发送中断
	//USART1_enable_interrupt_at_receive_data();		//使能接收中断
	//NVIC_enable_interrupt(_USART1_IRQn);                //NVIC使能中断
	
	USART1_disable_parity_check();							//关闭奇偶检验
	USART1_disable_interrupt_at_CTS_toggle();           //在外部CTS信号翻转时不激活中断
	USART1_disable_RTS();								//使能接收中断
	USART1_enable_transmit();							//使能发送
	USART1_enable_receive();							//使能接收
	
	//USART1_put_char(0);									//发送一个字节0
}

//USART2_TX PA2
//USART2_RX PA3
void USART2_init(USART_BAUD_RATE baudRate)
{
	RCC_enable_USART2_clock();	//给USART2提供时钟
	
	RCC_enable_GPIO_A_clock();	//给GPIO_A提供时钟
	RCC_enable_AFIO_clock();	//给复用模块提供时钟
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 2);
	GPIO_set_input_PP(GPIO_A, 3);
	
	USART2_enable();
	
	USART2_set_word_length_8_bit();
	USART2_disable_parity_check();
	
	//USART2_enable_interrupt_at_transmit_register_empty();
	USART2_enable_interrupt_at_receive_data();
	//USART2_enable_interrupt_at_transmit_complete();
	
	USART2_set_div(baudRate == BAUD_9600 ? 156.25 : 13.02);			//24MHZ下工作 156.25 = 9600 13.02为115200
	NVIC_enable_interrupt(_USART2_IRQn);
	
	USART2_set_stop_length_1();
	
	USART2_enable_transmit();
	USART2_enable_receive();
}


//输出字符
void USART1_put_char(char c)
{
	USART1_send_data(c);
	while(!USART1_is_transmit_register_empty());	//等待发送完成
}


//输出字符串
int USART1_put_string(char *str)
{
	int count = 0;
	while(*str)
	{
		USART1_put_char(*str++);
		count ++;
	}
	while(!USART1_is_transmit_complete());
	return count;
}


int USART1_put_int(int i)
{
	char buffer[20];
	sprintf(buffer, "%d", i);
	return USART1_put_string(buffer);
}

int USART1_put_float(float f)
{
	char buffer[20];
	sprintf(buffer, "%f", f);
	return USART1_put_string(buffer);
}


int USART1_put_double(double d)
{
	char buffer[20];
	sprintf(buffer, "%lf", d);
	return USART1_put_string(buffer);
}


int USART1_put_long(long l)
{
	char buffer[20];
	sprintf(buffer, "%ld", l);
	return USART1_put_string(buffer);
}


int USART1_printf(char *format, ...)
{
	char buffer[60];
	va_list list;
	
	va_start(list, format);
	vsprintf(buffer, format, list);
	va_end(list);
	return USART1_put_string(buffer);
}

//输出字符
void USART2_put_char(char c)
{
	USART2_send_data(c);
	while(!USART2_is_transmit_register_empty());	//等待发送完成
}


//输出字符串
int USART2_put_string(char *str)
{
	int count = 0;
	while(*str)
	{
		USART2_put_char(*str++);
		count ++;
	}
	while(!USART2_is_transmit_complete());
	return count;
}


int USART2_put_int(int i)
{
	char buffer[20];
	sprintf(buffer, "%d", i);
	return USART2_put_string(buffer);
}

int USART2_put_float(float f)
{
	char buffer[20];
	sprintf(buffer, "%f", f);
	return USART2_put_string(buffer);
}


int USART2_put_double(double d)
{
	char buffer[20];
	sprintf(buffer, "%lf", d);
	return USART2_put_string(buffer);
}


int USART2_put_long(long l)
{
	char buffer[20];
	sprintf(buffer, "%ld", l);
	return USART2_put_string(buffer);
}


int USART2_printf(char *format, ...)
{
	char buffer[60];
	std::va_list list;
	
	va_start(list, format);
	std::vsprintf(buffer, format, list);
	va_end(list);
	return USART2_put_string(buffer);
}

/***********************************************************************************************/
//SYSTICK
/***********************************************************************************************/
#include "base.h"


/*
	在外部参考时钟为9MHZ(HCLK = 72MHZ)时,给计数器的重新装载值给9000将会每1ms产生一个异常.
	现在的外部时钟为8MHZ ，所以, 给计数器的重新装载值给8000,就会产生1ms的异常。
	在这里给8000*1000会产生秒中断。
*/
void SYSTICK_init()
{
	SYSTICK_set_reload(8000000);
	SYSTICK_enable_interrupt();
	//SYSTICK_set_clock_source_is_FCLK();
	SYSTICK_enable_systick();
}

//将Systick配置成ms为单位中断的函数
void SYSTICK_init_ms(U32 ms)
{
	SYSTICK_set_reload(8000 * ms);
	SYSTICK_enable_interrupt();
	//SYSTICK_set_clock_source_is_FCLK();
	SYSTICK_enable_systick();
}


/***********************************************************************************************/
//DAC
/***********************************************************************************************/
#include "base.h"

#include "com.h"


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
void DAC_cnf_mode1()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//将引脚配置模拟开漏输出
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	DAC_channel1_disable_DMA();				//禁止DMA
	DAC_channel1_disable_wave_generator();	//禁止波形产生功能
	//DAC_channel2_enable_noise_wave_generator();	//禁止噪声发生器
	DAC_channel1_disable_trigger();			//禁止触发启动
	DAC_channel1_enable_output_buffer();	//使能输出缓冲
	DAC_set_data_align_12_right();			//设置12位右对齐模式
	DAC_channel1_enable();		//给DAC供电
	delay_us(10);				//延迟必须的时间
}


//在模式1下使能后，调用此函数,输出电压即可发生变化
void DAC_cnf_write_holding_data(U16 hd)
{
	DAC_channel1_set_holding_data(hd);
}

/*
	Channel1配置成软件触发模式下的普通模式
	12位右对齐模式
	带输出缓冲
	触发转换
	软件触发
	无波形产生
*/
void DAC_cnf_mode2()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//引脚
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	//内部配置
	DAC_channel1_disable_DMA();					//禁止DMA
	DAC_channel1_disable_wave_generator();		//禁止波形产生功能
	DAC_channel1_enable_trigger();				//禁止触发启动
	DAC_channel1_set_trigger_source_software();	//设置软件触发模式
	DAC_channel1_enable_output_buffer();		//使能输出缓冲
	DAC_set_data_align_12_right();				//设置12位右对齐模式
	
	//启动
	DAC_channel1_enable();						//给DAC供电
	delay_us(10);								//延迟必须的时间
}

/*
	Channel1配置为触发模式下的三角波发生器
	12位右对齐
	软件触发
	三角波行产生
*/

void DAC_cnf_mode3()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//引脚
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	//内部配置
	DAC_channel1_disable_DMA();						//禁止DMA
	DAC_channel1_enable_wave_triangle_generator();	//开启三角波产生功能
	DAC_channel1_set_triangle_amplitude_2047();		//振幅
	DAC_channel1_enable_trigger();					//禁止触发启动
	DAC_channel1_set_trigger_source_software();		//设置软件触发模式
	DAC_channel1_enable_output_buffer();			//使能输出缓冲
	DAC_set_data_align_12_right();					//设置12位右对齐模式
	
	//启动
	DAC_channel1_enable();							//给DAC供电
	delay_us(10);									//延迟必须的时间
}








/***********************************************************************************************/
//BKP
/***********************************************************************************************/
#include "base.h"


U8 BkpInitState = 0; 		//BKP初始化状态

void BKP_init()
{
	
	RCC_enable_PWR_clock();	//使能电源模块
	RCC_enable_BKP_clock();	//使能备份域
	
	PWR_disable_domain_backup_protection();	//禁止备份域保护
	BkpInitState = 1;
}

//关闭和备份域相关的所有模块
void BKP_shutdown()
{
	RCC_disable_PWR_clock();	//使能电源模块
	RCC_disable_BKP_clock();	//使能备份域
	
	PWR_enable_domain_backup_protection();	//禁止备份域保护
	BkpInitState = 0;
}


//保存data到备份域寄存器中的x位置
//返回该位置之前值
U16 BKP_save_data(U16 data, U8 x)
{
	U16 oldData;
	if(!BkpInitState)	//如果Bkp没有被初始化，则初始化之
		BKP_init();
	
	oldData = BKP_get_data(x);
	BKP_set_data(data, x);
	return oldData;
}

//复位备份域寄存器中的所有值为0
void BKP_reset()
{
	RCC_reset_backup_domain();
}

//测试（成功）
#include "font.h"
void BKP_CNF_test()
{
	//U16 x;
	BKP_init();
	BKP_set_data(0xF, 1);
	BKP_reset();
	//x = BKP_get_data(1);
	//FONT_printf(0,0, "%d", x);
}


/***********************************************************************************************/
//I2C1
/***********************************************************************************************/
#include "base.h"

//	I2C1_SCL		PB6	136
//	I2C1_SDA		PB7	137
//将I2C1配置成IC卡读取器
void I2C1_cnf_init()
{
	RCC_enable_I2C1_clock();		//给I2C1提供时钟
	RCC_enable_GPIO_B_clock();	//给GPIO提供时钟
	RCC_enable_AFIO_clock();		//给AFIO提供时钟
	GPIO_set_output_50MHZ_OD_MUL(GPIO_B, 6);		//开漏复用输出
	GPIO_set_output_50MHZ_OD_MUL(GPIO_B, 7);		//开漏复用输出
	
	I2C1_set_prequency_MHZ(8);			//MHZ工作时钟
	I2C1_set_clock(0x28);						//100kbps
	I2C1_set_rise_time(9);					//上升时间
	
	I2C1_enable_peripheral();				//使能I2C模块,使能之后下面的设置才能生效
	I2C1_set_address_7to1(0x30);		
	I2C1_enable_acknowledge();			//允许产生应答信号
	I2C1_set_address_mode_7_bit();	//在7位地址模式下工作
	I2C1_set_neccessary();
}




