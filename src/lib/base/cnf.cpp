
/***********************************************************************************************/
//ADC
/***********************************************************************************************/
#include "base.h"
#include "com.h"

//��ʼ��ADC1��ͨ��10(PC0����)

#define CHANNEL 10
#define PORT	GPIO_C
#define PIN		0

void ADC1_IN10_init()
{
//ADC��������
	RCC_enable_GPIO_x_clock(PORT);
	GPIO_set_input_ANA(PORT, PIN);				//PC.0��������ģ��
	
	RCC_enable_ADC1_clock();					//��ADC1�ṩʱ��

//ADC����
	//ADC1_enable_interrupt_at_convert_end();		//ʹ����ת����ɺ�����ж�
	//NVIC_enable_interrupt(_ADC1_2_IRQn);		//NVICʹ���ж�
	
	ADC1_set_data_align_right();						//ת��������ݴ�ŵĶ��䷽ʽ
	//ADC1_set_conversion_in_continuous_mode();	//������ģʽ��ת��
	ADC1_set_conversion_in_single_mode();	    //�ڵ�һģʽ��ת��
	ADC1_set_sample_time_41_5(CHANNEL);			//41.5����������
	
	ADC1_set_sequence_length_1();				//Ҫת����ͨ����Ϊ1
	
	ADC1_set_sequence1(CHANNEL);                //�����еĵ�һ����ΪCHANNEL
	
	ADC1_enable_DMA();							//ʹ��DMA
	
	
//ADC����
	ADC1_wake_up_ADC();							//��һ������Ϊ����
	delay_us(200);								//�ȴ��ȶ�
	
	//ADCУ׼
	ADC1_reset_calibration();					//��λADC��У׼
	while(!ADC1_is_reset_calibration_done());	//�Ƿ�λ���
	ADC1_start_calibration();                   //��ʼУ׼
	while(!ADC1_is_calibration_done());			//�ȴ�У׼���	
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


//��ʼת��
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
//*************************************TIM1������************************************//
//***********************************************************************************//


//��time1����ΪnUs��us����һ��
//���ڼ���preLoad�κ�����ж�
void TIM1_init_us(U32 nUs, U32 reLoad)
{
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�����RCC�����ã������ʱ��ʱ48MHZ
	TIM1_set_slave_inside_clock();			//ѡ���ڲ�ʱ��ΪTIM1ʱ��
	TIM1_set_counter_prescaler(48 * nUs);			//����48��Ƶ,��ÿ1us����һ��
	TIM1_set_repetition_counter(0);				//�ظ������Ĵ���Ϊ1000
	TIM1_set_counter_auto_reload(reLoad);        		//����Ԥװ�ؼĴ���Ϊ1000
	TIM1_set_counter(0);                	//���ü�������ֵΪ0
	TIM1_set_counter_direction_up();		//����Ϊ���ϼ���
	TIM1_set_update_source_overflow(); 	//�����¼�ֻ�����ʱ����
	TIM1_enable_interrupt_at_update_event();//�ڸ����¼�ʱ�����ж�
	//TIM1_disable_extern_clock();		
	NVIC_enable_interrupt(_TIM1_UP_IRQn); 	//NVIC���ø����¼��ж�����
	TIM1_enable_counter();                  //��ʼ����
}


//��time1����ΪnMs��ms����һ��
//���ڼ���reLoad�κ�����ж�
//nMsΪ������ÿnMs����һ��
//reLoadΪ����reLoad�β����ж�
void TIM1_init_ms(U32 nMs, U32 reLoad)
{
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�����RCC�����ã������ʱ��ʱ48MHZ
	TIM1_set_slave_inside_clock();			//ѡ���ڲ�ʱ��ΪTIM1ʱ��
	TIM1_set_counter_prescaler(48000 * nMs);	//����48��Ƶ,��ÿ1ms����һ��
	TIM1_set_repetition_counter(0);				//�ظ������Ĵ���Ϊ1000
	TIM1_set_counter_auto_reload(reLoad);        		//����Ԥװ�ؼĴ���Ϊ1000
	TIM1_set_counter(0);                	//���ü�������ֵΪ0
	TIM1_set_counter_direction_up();		//����Ϊ���ϼ���
	TIM1_set_update_source_overflow(); 	//�����¼�ֻ�����ʱ����
	TIM1_enable_interrupt_at_update_event();//�ڸ����¼�ʱ�����ж�
	//TIM1_disable_extern_clock();				
	NVIC_enable_interrupt(_TIM1_UP_IRQn); 	//NVIC���ø����¼��ж�����
	TIM1_enable_counter();                  //��ʼ����
}

//***************************TIM1_CH1����PWM********************************//
/*
	��TIM1��ͨ��1����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PA8		
		�������:	PB13	
*/
void TIM1_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 8);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 13);	
	
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�48MHZ
	TIM1_set_slave_inside_clock();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM1_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM1_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM1_set_CCR1(ccr);							//���ò���ȽϼĴ���
	
	TIM1_set_channel1_output();				//ͨ��һ����Ϊ���
	TIM1_disable_OC1_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM1_set_OC1_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM1_set_OC1_PWM2_mode();			//�����PWMģʽ2
	
	TIM1_enable_CCR1_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM1_set_CC1_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM1_set_CC1N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM1_enable_main_output();				//��ʹ�����
	
	TIM1_enable_CC1();						//ʹ�����
	if(complementOutput)
		TIM1_enable_CC1N();						//����ʹ�����
	
	TIM1_enable_counter();					//ʹ�ܼ�����
}

void TIM1_CH1_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR1(duty_us);
}


//***************************TIM1_CH2����PWM********************************//
/*
	��TIM1��ͨ��2����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PA9		
		�������:	PB14	
*/
void TIM1_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 9);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 14);	
	
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�48MHZ
	TIM1_set_slave_inside_clock();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM1_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM1_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM1_set_CCR2(ccr);							//���ò���ȽϼĴ���
	
	TIM1_set_channel2_output();				//ͨ��һ����Ϊ���
	TIM1_disable_OC2_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM1_set_OC2_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM1_set_OC2_PWM2_mode();			//�����PWMģʽ2
	
	TIM1_enable_CCR2_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM1_set_CC2_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM1_set_CC2N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM1_enable_main_output();				//��ʹ�����
	
	TIM1_enable_CC2();						//ʹ�����
	if(complementOutput)
		TIM1_enable_CC2N();						//����ʹ�����
	
	TIM1_enable_counter();					//ʹ�ܼ�����
}

void TIM1_CH2_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR2(duty_us);
}


//***************************TIM1_CH3����PWM********************************//
/*
	��TIM1��ͨ��3����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PA10		
		�������:	PB15	
*/
void TIM1_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_A_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 10);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 15);	
	
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�48MHZ
	TIM1_set_slave_inside_clock();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM1_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM1_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM1_set_CCR3(ccr);							//���ò���ȽϼĴ���
	
	TIM1_set_channel3_output();				//ͨ��һ����Ϊ���
	TIM1_disable_OC3_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM1_set_OC3_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM1_set_OC3_PWM2_mode();			//�����PWMģʽ2
	
	TIM1_enable_CCR3_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM1_set_CC3_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM1_set_CC3N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM1_enable_main_output();				//��ʹ�����
	
	TIM1_enable_CC3();						//ʹ�����
	if(complementOutput)
		TIM1_enable_CC3N();						//����ʹ�����
	
	TIM1_enable_counter();					//ʹ�ܼ�����
}

void TIM1_CH3_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR3(duty_us);
}



//***************************TIM1_CH4����PWM********************************//
/*
	��TIM1��ͨ��4����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PA11		
		�������:	�޻������
*/
void TIM1_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos)
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 11);
	
	RCC_enable_TIM1_clock();				//��TIM1�ṩʱ�ӣ�48MHZ
	TIM1_set_slave_inside_clock();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM1_set_counter_direction_up();
	TIM1_disable_slave_mode();
	
	TIM1_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM1_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM1_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM1_set_CCR4(duty_pos);							//���ò���ȽϼĴ���
	
	TIM1_set_channel4_output();				//ͨ��һ����Ϊ���
	TIM1_disable_OC4_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM1_set_OC4_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM1_set_OC4_PWM2_mode();			//�����PWMģʽ2
	
	TIM1_enable_CCR4_preload();				//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM1_set_CC4_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	
	TIM1_enable_main_output();				//��ʹ�����
	TIM1_enable_CC4();						//ʹ�����
	TIM1_enable_counter();					//ʹ�ܼ�����
}

void TIM1_CH4_set_pwm_duty(U32 duty_us)
{
	TIM1_set_CCR4(duty_us);
}


//***********************************************************************************//
//*************************************TIM1������************************************//
//***********************************************************************************//


//��TIM8����ΪnUs��us����һ��
//���ڼ���preLoad�κ�����ж�
void TIM8_init_us(U32 nUs, U32 reLoad)
{
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�����RCC�����ã������ʱ��ʱ48MHZ
	TIM8_disable_slave_mode();			//ѡ���ڲ�ʱ��ΪTIM8ʱ��
	TIM8_set_counter_prescaler(48 * nUs);			//����48��Ƶ,��ÿ1us����һ��
	TIM8_set_repetition_counter(0);				//�ظ������Ĵ���Ϊ1000
	TIM8_set_counter_auto_reload(reLoad);        		//����Ԥװ�ؼĴ���Ϊ1000
	TIM8_set_counter(0);                	//���ü�������ֵΪ0
	TIM8_set_counter_direction_up();		//����Ϊ���ϼ���
	TIM8_set_update_source_overflow(); 	//�����¼�ֻ�����ʱ����
	TIM8_enable_interrupt_at_update_event();//�ڸ����¼�ʱ�����ж�
	//TIM8_disable_extern_clock();		
	NVIC_enable_interrupt(_TIM8_UP_IRQn); 	//NVIC���ø����¼��ж�����
	TIM8_enable_counter();                  //��ʼ����
}


//��time1����ΪnMs��ms����һ��
//���ڼ���preLoad�κ�����ж�
//nMs����һ��,����reLoad�β����ж�
void TIM8_init_ms(U32 nMs, U32 reLoad)
{
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�����RCC�����ã������ʱ��ʱ48MHZ
	TIM8_disable_slave_mode();			//ѡ���ڲ�ʱ��ΪTIM8ʱ��
	TIM8_set_counter_prescaler(48000 * nMs);			//����48��Ƶ,��ÿ1ms����һ��
	TIM8_set_repetition_counter(0);				//�ظ������Ĵ���Ϊ1000
	TIM8_set_counter_auto_reload(reLoad);        		//����Ԥװ�ؼĴ���Ϊ1000
	TIM8_set_counter(0);                	//���ü�������ֵΪ0
	TIM8_set_counter_direction_up();		//����Ϊ���ϼ���
	TIM8_set_update_source_overflow(); 	//�����¼�ֻ�����ʱ����
	TIM8_enable_interrupt_at_update_event();//�ڸ����¼�ʱ�����ж�
	//TIM8_disable_extern_clock();				
	NVIC_enable_interrupt(_TIM8_UP_IRQn); 	//NVIC���ø����¼��ж�����
	TIM8_enable_counter();                  //��ʼ����
}

//***************************TIM8_CH1����PWM********************************//
/*
	��TIM8��ͨ��1����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PC6		
		�������:	PA7	
*/
void TIM8_CH1_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_A_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 6);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 7);	
	
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�48MHZ
	TIM8_disable_slave_mode();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM8_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM8_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM8_set_CCR1(ccr);							//���ò���ȽϼĴ���
	
	TIM8_set_channel1_output();				//ͨ��һ����Ϊ���
	TIM8_disable_OC1_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM8_set_OC1_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM8_set_OC1_PWM2_mode();			//�����PWMģʽ2
	
	TIM8_enable_CCR1_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM8_set_CC1_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM8_set_CC1N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM8_enable_main_output();				//��ʹ�����
	
	TIM8_enable_CC1();						//ʹ�����
	if(complementOutput)
		TIM8_enable_CC1N();					//����ʹ�����
	
	TIM8_enable_counter();					//ʹ�ܼ�����
}

void TIM8_CH1_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR1(duty_us);
}


//***************************TIM8_CH2����PWM********************************//
/*
	��TIM8��ͨ��2����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PC7	
		�������:	PB0	
*/
void TIM8_CH2_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 7);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 0);	
	
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�48MHZ
	TIM8_disable_slave_mode();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM8_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM8_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM8_set_CCR2(ccr);							//���ò���ȽϼĴ���
	
	TIM8_set_channel2_output();				//ͨ��һ����Ϊ���
	TIM8_disable_OC2_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM8_set_OC2_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM8_set_OC2_PWM2_mode();			//�����PWMģʽ2
	
	TIM8_enable_CCR2_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM8_set_CC2_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM8_set_CC2N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM8_enable_main_output();				//��ʹ�����
	
	TIM8_enable_CC2();						//ʹ�����
	if(complementOutput)
		TIM8_enable_CC2N();						//����ʹ�����
	
	TIM8_enable_counter();					//ʹ�ܼ�����
}

void TIM8_CH2_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR2(duty_us);
}


//***************************TIM8_CH3����PWM********************************//
/*
	��TIM8��ͨ��3����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PC8	
		�������:	PB1
*/
void TIM8_CH3_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos, U8 complementOutput)
{
	U32 ccr = duty_pos ? (period_us - duty_us) : duty_us;
	
	RCC_enable_GPIO_C_clock();
	RCC_enable_GPIO_B_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 8);
	
	if(complementOutput)					//�������Ҫ�󻥲����,�����û������IO��(ע��:Ӱ�쵽������)
		GPIO_set_output_50MHZ_PP_MUL(GPIO_B, 1);	
	
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�48MHZ
	TIM8_disable_slave_mode();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM8_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM8_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM8_set_CCR3(ccr);							//���ò���ȽϼĴ���
	
	TIM8_set_channel3_output();				//ͨ��һ����Ϊ���
	TIM8_disable_OC3_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM8_set_OC3_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM8_set_OC3_PWM2_mode();			//�����PWMģʽ2
	
	TIM8_enable_CCR3_preload();			//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM8_set_CC3_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	TIM8_set_CC3N_polarity_high();			//����OC1N�����Ϊ�͵�ƽ��Ч
	
	TIM8_enable_main_output();				//��ʹ�����
	
	TIM8_enable_CC3();						//ʹ�����
	if(complementOutput)
		TIM8_enable_CC3N();						//����ʹ�����
	
	TIM8_enable_counter();					//ʹ�ܼ�����
}

void TIM8_CH3_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR3(duty_us);
}



//***************************TIM8_CH4����PWM********************************//
/*
	��TIM8��ͨ��4����һ·PWM�� 
		period_us:  ����
		duty_us:	ռ�ձ�
		duty_pos:	
			0:�ߵ�ƽ��ÿһ���ڵ���ʼλ��
			1:�ߵ�ƽ��ÿһ���ڵ�ĩβλ��
		complementOutput:
			�Ƿ����������
	�������:
		�����:		PC9	
		�������:	�޻������
*/
void TIM8_CH4_generate_pwm(U32 period_us, U32 duty_us, U8 duty_pos)
{
	RCC_enable_GPIO_C_clock();
	RCC_enable_AFIO_clock();
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_C, 9);
	
	RCC_enable_TIM8_clock();				//��TIM8�ṩʱ�ӣ�48MHZ
	TIM8_disable_slave_mode();			//������ʱ����Ϊ�ڲ�ʱ��
	TIM8_set_counter_direction_up();
	TIM8_disable_slave_mode();
	
	TIM8_set_counter_prescaler(48);				//���÷�ƵΪ48,������ÿһ΢�����һ��
	TIM8_set_counter_auto_reload(period_us);	//��Ƽ��������ؼ���20����������20ms����һ�Σ�1s�ڼ���50��
	TIM8_set_repetition_counter(0);				//�ظ�������Ϊ0
	TIM8_set_CCR4(duty_pos);							//���ò���ȽϼĴ���
	
	TIM8_set_channel4_output();				//ͨ��һ����Ϊ���
	TIM8_disable_OC4_clear();				//����ͨ������ĸ�λģʽ
	
	if(!duty_pos)							//�����PWMģʽ1
		TIM8_set_OC4_PWM1_mode();			//ͨ������Ϊ���PWMģʽ
	else
		TIM8_set_OC4_PWM2_mode();			//�����PWMģʽ2
	
	TIM8_enable_CCR4_preload();				//ʹ��ͨ��1�ĵ�Ԥװ�ع���
	TIM8_set_CC4_polarity_high();			//����OC1�����Ϊ�ߵ�ƽ��Ч
	
	TIM8_enable_main_output();				//��ʹ�����
	TIM8_enable_CC4();						//ʹ�����
	TIM8_enable_counter();					//ʹ�ܼ�����
}

void TIM8_CH4_set_pwm_duty(U32 duty_us)
{
	TIM8_set_CCR4(duty_us);
}




/***********************************************************************************************/
//CRC
/***********************************************************************************************/



//�������ԣ� CRC������ģ����ģ�⣬ֻ�ܽ��ϰ��Ӳ�����ȷ���С�

#include "base.h"
#include "com.h"


void CRC_init()
{
	RCC_enable_CRC_clock();	//ʹ��CRCʱ��
	CRC_reset();			//����CRC
}


/*
	�˺������������ pData ����ʼ����pData + dataSize*4��֮������ݵ�CRC�롣
*/
U32 CRC_check_data(U32 *pData, U32 dataSize)
{
	int temp = 0;
	for(temp =0; temp < dataSize; temp ++)
		CRC_set_value(*(pData + temp));   
	temp = CRC_get_result();		//��ý��
	CRC_reset();
	return temp;
}


/***********************************************************************************************/
//DMA
/***********************************************************************************************/


#include "base.h"
#include "com.h"



//��DMA1��CH1ͨ������Ϊ�洢�����洢������ ��0x20000000��0x20000010�����ݴ��� ֻ����һ��λ
void DMA1_CH1_init()
{
	RCC_enable_DMA1_clock();							//��DMA1�ṩʱ��
	
	DMA1_CH1_set_peripheral_address(__ADC1_DR);
	DMA1_CH1_set_memory_address((int)0);
	//DMA1_CH1_enable_MEM2MEM();							//ʹ�ܴ洢�����洢��, ʹ��DMA�󣬴��佫�Զ���ʼ
	
	DMA1_CH1_set_transfer_number(320);					//���͵�����
	//DMA1_CH1_enable_peripheral_increment_mode();  		//ʹ����������
	
	DMA1_CH1_disable_peripheral_increment_mode();		//��������ģʽ��ֹ
	DMA1_CH1_enable_memory_increment_mode();      		//ʹ�ܴ洢������
	DMA1_CH1_enable_circular_mode();					//ѭ��ģʽ
	DMA1_CH1_set_transfer_direction_from_peripheral(); 	//�����Ǵ����赽�洢��
	DMA1_CH1_set_priority_veryhigh();					//�������ȼ������
	
	DMA1_CH1_set_memory_size_16();						//���ô洢���ߴ�Ϊ32
	DMA1_CH1_set_peripheral_size_16();					//��������ߴ�Ϊ32

	DMA1_CH1_enable_interrupt_at_transfer_complete();	//������Ϻ󼤻��ж�
	DMA1_CH1_disable_interrupt_at_transfer_half();		//��ʹ��
	NVIC_enable_interrupt(_DMA1_Channel1_IRQn);         //�ڲ�NVIC�����ж�
	
	DMA1_CH1_enable_channel(); 							//ʹ��channel1
}
 


/***********************************************************************************************/
//RCC
/***********************************************************************************************/
#include "base.h"



//���ڲ�����ʱ�����õ����

void RCC_init()
{
//����ʱ��ǰ������
	RCC_set_PLLXTPRE_HSE_1();		//HSE��ڴ���Ƶ
	RCC_set_PLLSRC_HSE();				//����PLLʱ��Դ
	RCC_set_PLLMUL_6();					//�ⲿ8MHZ���屶Ƶ��48MHZ
	RCC_set_AHBPRE_1();					//AHB����Ϊ����Ƶ
	RCC_set_APB1PRE_2();				//APB1��������2��Ƶ Ϊ24MHZ
	RCC_set_APB2PRE_1();				//APB2�������ò���Ƶ Ϊ48MHZ
	
	//ADCʱ������
	//����ʱ�ӣ�����ADC1��APB2������(48MHZ��systeminit������),
	//ADC1��ʱ�����14MHZ������4��Ƶ����12MHZ����
	RCC_set_ADC_prescaler_4(); 		//��APB24��Ƶ 12MHZ
	
//�����ⲿHSEʱ��
	RCC_enable_HSE();				//�����ⲿʱ��
	while(!RCC_is_HSI_ready());		//�ȴ��ⲿʱ���ȶ�
	RCC_enable_PLL();				//������Ƶ
	while(!RCC_is_PLL_ready());		//�ȴ�PLL�ȶ�
	RCC_set_SW_PLLCLK();			//����ϵͳʱ��ԴΪPLL��������ʱ��
	RCC_disable_HSI();				//�ص��ڲ�HSI
}

//��Ƶģʽ
void _RCC_init()
{
	//����ʱ��ǰ������
	RCC_set_PLLXTPRE_HSE_1();		//HSE��ڴ���Ƶ
	RCC_set_PLLSRC_HSE();				//����PLLʱ��Դ
	RCC_set_PLLMUL_2();					//�ⲿ8MHZ���屶Ƶ��16MHZ
	RCC_set_AHBPRE_1();					//AHB����Ϊ����Ƶ
	RCC_set_APB1PRE_2();				//APB1��������2��ƵΪ8MHZ
	RCC_set_APB2PRE_1();				//APB2�������ò���ƵΪ16MHZ
	
	//ADCʱ������
	//����ʱ�ӣ�����ADC1��APB2������(48MHZ��systeminit������),
	//ADC1��ʱ�����14MHZ������4��Ƶ����12MHZ����
	RCC_set_ADC_prescaler_4(); 		//��APB24��Ƶ 12MHZ
	
//�����ⲿHSEʱ��
	RCC_enable_HSE();				//�����ⲿʱ��
	while(!RCC_is_HSI_ready());		//�ȴ��ⲿʱ���ȶ�
	RCC_enable_PLL();				//������Ƶ
	while(!RCC_is_PLL_ready());		//�ȴ�PLL�ȶ�
	RCC_set_SW_PLLCLK();			//����ϵͳʱ��ԴΪPLL��������ʱ��
	RCC_disable_HSI();				//�ص��ڲ�HSI
}



/***********************************************************************************************/
//RTC
/***********************************************************************************************/


#include "com.h"

#include "cnf.h"
#include "base.h"

/*
	RTC�����ó�ÿ�����һ���жϵ�ģʽ,����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/

void RTC_init_per_1_second(U8 new_or_old)		//1, 0
{
	RCC_enable_PWR_clock();						//��PWR�ṩʱ��
	PWR_disable_domain_backup_protection();		//�رյĺ��򱣻�
	
	//���ú���
	RCC_enable_LSE();
	while(!RCC_is_LSE_ready());			//�ȴ��ⲿ�����ȶ�
	RCC_set_RTCSEL_LSE();				//����RTCʱ��ԴΪLSE
	RCC_enable_RTC();					//����RTC��
	
	RTC_wait_sync();					//�ȴ���λ���APB1��ͬ��
	RTC_enter_configure_mode();			//��������ģʽ
	RTC_wait_operation_done();			//�ȴ���д
	
	RTC_wait_operation_done();			//�ȴ���д
	if(new_or_old)
	{
		RTC_set_system_time(0x00);		//���õ�ǰ��ϵͳʱ��
		RTC_wait_operation_done();		//�ȴ���д
	}
	RTC_set_prescaler(0x7FFF);
	RTC_exit_configure_mode();
	RTC_wait_operation_done();

	PWR_enable_domain_backup_protection();		//�رյĺ��򱣻�
	
	RTC_enable_interrupt_at_second();	//ʹ��ʱ���ж�
	NVIC_enable_interrupt(3);	
}


/*
	RTC�����ó�ÿper_ms�������һ���жϵ�ģʽ,
	����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/
void RTC_init(U32 per_ms, U8 new_or_old)					//1, 0
{
	U32 div = (0x7FFF/1000) * per_ms;			//����per_ms����Ҫ�ķ�Ƶϵ��
	RCC_enable_PWR_clock();						//��PWR�ṩʱ��
	PWR_disable_domain_backup_protection();		//�رյĺ��򱣻�
	
	//���ú���
	RCC_enable_LSE();
	while(!RCC_is_LSE_ready());			//�ȴ��ⲿ�����ȶ�
	RCC_set_RTCSEL_LSE();				//����RTCʱ��ԴΪLSE
	RCC_enable_RTC();					//����RTC��
	
	RTC_wait_sync();					//�ȴ���λ���APB1��ͬ��
	RTC_enter_configure_mode();			//��������ģʽ
	RTC_wait_operation_done();			//�ȴ���д
	
	RTC_wait_operation_done();			//�ȴ���д
	if(new_or_old)
	{
		RTC_set_system_time(0x00);		//���õ�ǰ��ϵͳʱ��
		RTC_wait_operation_done();		//�ȴ���д
	}
	RTC_set_prescaler(div);	
	RTC_exit_configure_mode();
	RTC_wait_operation_done();

	PWR_enable_domain_backup_protection();		//�رյĺ��򱣻�
	
	RTC_enable_interrupt_at_second();	//ʹ��ʱ���ж�
	NVIC_enable_interrupt(3);	
}





//����ϵͳʱ��
//����hour, min ,sec,�㶮��
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
//��USART1���ó�9600������
//bautRate : 9600 / 115200
void USART1_init(USART_BAUD_RATE baudRate)
{
	//��������
	RCC_enable_GPIO_A_clock();			//ʹ��GPIO_A�˿�ʱ��
	RCC_enable_AFIO_clock();			//ʹ��AFIOʱ�� ���⹦�ܵ�USART��Ҫ��ʹ��
	RCC_enable_USART1_clock();			//USART1ʱ��ʹ��
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 9);	//�� GPA9 ����Ϊ���⹦��
	GPIO_set_input_PP(GPIO_A, 10);				//�� GPA10����Ϊ����������
	
	USART1_enable();					//ʹ��USART1
	
	USART1_set_word_length_8_bit();		//���ô����ֳ�Ϊ1λ��ʼλ��8λ����λ,nλֹͣλ
	USART1_set_stop_length_1();			//����ֹͣλ����Ϊ1
	
	USART1_set_div(baudRate == BAUD_9600 ? 312.5 : 26.04);				//����DIVΪ31.25�� ������Ϊ9600
	USART1_enable_parity_check();
	
	//USART1_enable_interrupt_at_transmit_complete();	//ʹ�ܷ����ж�
	//USART1_enable_interrupt_at_receive_data();		//ʹ�ܽ����ж�
	//NVIC_enable_interrupt(_USART1_IRQn);                //NVICʹ���ж�
	
	USART1_disable_parity_check();							//�ر���ż����
	USART1_disable_interrupt_at_CTS_toggle();           //���ⲿCTS�źŷ�תʱ�������ж�
	USART1_disable_RTS();								//ʹ�ܽ����ж�
	USART1_enable_transmit();							//ʹ�ܷ���
	USART1_enable_receive();							//ʹ�ܽ���
	
	//USART1_put_char(0);									//����һ���ֽ�0
}

//USART2_TX PA2
//USART2_RX PA3
void USART2_init(USART_BAUD_RATE baudRate)
{
	RCC_enable_USART2_clock();	//��USART2�ṩʱ��
	
	RCC_enable_GPIO_A_clock();	//��GPIO_A�ṩʱ��
	RCC_enable_AFIO_clock();	//������ģ���ṩʱ��
	
	GPIO_set_output_50MHZ_PP_MUL(GPIO_A, 2);
	GPIO_set_input_PP(GPIO_A, 3);
	
	USART2_enable();
	
	USART2_set_word_length_8_bit();
	USART2_disable_parity_check();
	
	//USART2_enable_interrupt_at_transmit_register_empty();
	USART2_enable_interrupt_at_receive_data();
	//USART2_enable_interrupt_at_transmit_complete();
	
	USART2_set_div(baudRate == BAUD_9600 ? 156.25 : 13.02);			//24MHZ�¹��� 156.25 = 9600 13.02Ϊ115200
	NVIC_enable_interrupt(_USART2_IRQn);
	
	USART2_set_stop_length_1();
	
	USART2_enable_transmit();
	USART2_enable_receive();
}


//����ַ�
void USART1_put_char(char c)
{
	USART1_send_data(c);
	while(!USART1_is_transmit_register_empty());	//�ȴ��������
}


//����ַ���
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

//����ַ�
void USART2_put_char(char c)
{
	USART2_send_data(c);
	while(!USART2_is_transmit_register_empty());	//�ȴ��������
}


//����ַ���
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
	���ⲿ�ο�ʱ��Ϊ9MHZ(HCLK = 72MHZ)ʱ,��������������װ��ֵ��9000����ÿ1ms����һ���쳣.
	���ڵ��ⲿʱ��Ϊ8MHZ ������, ��������������װ��ֵ��8000,�ͻ����1ms���쳣��
	�������8000*1000��������жϡ�
*/
void SYSTICK_init()
{
	SYSTICK_set_reload(8000000);
	SYSTICK_enable_interrupt();
	//SYSTICK_set_clock_source_is_FCLK();
	SYSTICK_enable_systick();
}

//��Systick���ó�msΪ��λ�жϵĺ���
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
	����Channel1Ϊ�Ǵ���������ͨģʽ
	�ڴ�ģʽ�£�ֻҪһ��DHRx�Ĵ�����д�������ͻ�����ת�Ƶ�DORx�У�����3��APB1ʱ�Ӻ�
	���������
	��ʹ��DMA
	����������
	���������ǲ�
	�����ѹ�ɵ�
*/
void DAC_cnf_mode1()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//����������ģ�⿪©���
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	DAC_channel1_disable_DMA();				//��ֹDMA
	DAC_channel1_disable_wave_generator();	//��ֹ���β�������
	//DAC_channel2_enable_noise_wave_generator();	//��ֹ����������
	DAC_channel1_disable_trigger();			//��ֹ��������
	DAC_channel1_enable_output_buffer();	//ʹ���������
	DAC_set_data_align_12_right();			//����12λ�Ҷ���ģʽ
	DAC_channel1_enable();		//��DAC����
	delay_us(10);				//�ӳٱ����ʱ��
}


//��ģʽ1��ʹ�ܺ󣬵��ô˺���,�����ѹ���ɷ����仯
void DAC_cnf_write_holding_data(U16 hd)
{
	DAC_channel1_set_holding_data(hd);
}

/*
	Channel1���ó��������ģʽ�µ���ͨģʽ
	12λ�Ҷ���ģʽ
	���������
	����ת��
	�������
	�޲��β���
*/
void DAC_cnf_mode2()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//����
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	//�ڲ�����
	DAC_channel1_disable_DMA();					//��ֹDMA
	DAC_channel1_disable_wave_generator();		//��ֹ���β�������
	DAC_channel1_enable_trigger();				//��ֹ��������
	DAC_channel1_set_trigger_source_software();	//�����������ģʽ
	DAC_channel1_enable_output_buffer();		//ʹ���������
	DAC_set_data_align_12_right();				//����12λ�Ҷ���ģʽ
	
	//����
	DAC_channel1_enable();						//��DAC����
	delay_us(10);								//�ӳٱ����ʱ��
}

/*
	Channel1����Ϊ����ģʽ�µ����ǲ�������
	12λ�Ҷ���
	�������
	���ǲ��в���
*/

void DAC_cnf_mode3()
{
	RCC_enable_GPIO_A_clock();
	RCC_enable_DAC_clock();
	
	//����
	GPIO_set_output_50MHZ_OD(CHANNAL1_PORT, CHANNEL1_PIN);
	
	//�ڲ�����
	DAC_channel1_disable_DMA();						//��ֹDMA
	DAC_channel1_enable_wave_triangle_generator();	//�������ǲ���������
	DAC_channel1_set_triangle_amplitude_2047();		//���
	DAC_channel1_enable_trigger();					//��ֹ��������
	DAC_channel1_set_trigger_source_software();		//�����������ģʽ
	DAC_channel1_enable_output_buffer();			//ʹ���������
	DAC_set_data_align_12_right();					//����12λ�Ҷ���ģʽ
	
	//����
	DAC_channel1_enable();							//��DAC����
	delay_us(10);									//�ӳٱ����ʱ��
}








/***********************************************************************************************/
//BKP
/***********************************************************************************************/
#include "base.h"


U8 BkpInitState = 0; 		//BKP��ʼ��״̬

void BKP_init()
{
	
	RCC_enable_PWR_clock();	//ʹ�ܵ�Դģ��
	RCC_enable_BKP_clock();	//ʹ�ܱ�����
	
	PWR_disable_domain_backup_protection();	//��ֹ�����򱣻�
	BkpInitState = 1;
}

//�رպͱ�������ص�����ģ��
void BKP_shutdown()
{
	RCC_disable_PWR_clock();	//ʹ�ܵ�Դģ��
	RCC_disable_BKP_clock();	//ʹ�ܱ�����
	
	PWR_enable_domain_backup_protection();	//��ֹ�����򱣻�
	BkpInitState = 0;
}


//����data��������Ĵ����е�xλ��
//���ظ�λ��֮ǰֵ
U16 BKP_save_data(U16 data, U8 x)
{
	U16 oldData;
	if(!BkpInitState)	//���Bkpû�б���ʼ�������ʼ��֮
		BKP_init();
	
	oldData = BKP_get_data(x);
	BKP_set_data(data, x);
	return oldData;
}

//��λ������Ĵ����е�����ֵΪ0
void BKP_reset()
{
	RCC_reset_backup_domain();
}

//���ԣ��ɹ���
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
//��I2C1���ó�IC����ȡ��
void I2C1_cnf_init()
{
	RCC_enable_I2C1_clock();		//��I2C1�ṩʱ��
	RCC_enable_GPIO_B_clock();	//��GPIO�ṩʱ��
	RCC_enable_AFIO_clock();		//��AFIO�ṩʱ��
	GPIO_set_output_50MHZ_OD_MUL(GPIO_B, 6);		//��©�������
	GPIO_set_output_50MHZ_OD_MUL(GPIO_B, 7);		//��©�������
	
	I2C1_set_prequency_MHZ(8);			//MHZ����ʱ��
	I2C1_set_clock(0x28);						//100kbps
	I2C1_set_rise_time(9);					//����ʱ��
	
	I2C1_enable_peripheral();				//ʹ��I2Cģ��,ʹ��֮����������ò�����Ч
	I2C1_set_address_7to1(0x30);		
	I2C1_enable_acknowledge();			//�������Ӧ���ź�
	I2C1_set_address_mode_7_bit();	//��7λ��ַģʽ�¹���
	I2C1_set_neccessary();
}




