
#ifndef __NVIC
#define __NVIC

#include "com.h"

//�жϺ�
#define		_WWDG_IRQn                     0       //!< Window WatchDog Interrupt                            //
#define		_PVD_IRQn                      1       //!< PVD through EXTI Line detection Interrupt            //
#define		_TAMPER_IRQn                   2       //!< Tamper Interrupt                                     //
#define		_RTC_IRQn                      3       //!< RTC global Interrupt                                 //
#define		_FLASH_IRQn                    4       //!< FLASH global Interrupt                               //
#define		_RCC_IRQn                      5       //!< RCC global Interrupt                                 //
#define		_EXTI0_IRQn                    6       //!< EXTI Line0 Interrupt                                 //
#define		_EXTI1_IRQn                    7       //!< EXTI Line1 Interrupt                                 //
#define		_EXTI2_IRQn                    8       //!< EXTI Line2 Interrupt                                 //
#define		_EXTI3_IRQn                    9       //!< EXTI Line3 Interrupt                                 //
#define		_EXTI4_IRQn                    10      //!< EXTI Line4 Interrupt                                 //
#define		_DMA1_Channel1_IRQn            11      //!< DMA1 Channel 1 global Interrupt                      //
#define		_DMA1_Channel2_IRQn            12      //!< DMA1 Channel 2 global Interrupt                      //
#define		_DMA1_Channel3_IRQn            13      //!< DMA1 Channel 3 global Interrupt                      //
#define		_DMA1_Channel5_IRQn            15      //!< DMA1 Channel 5 global Interrupt                      //
#define		_DMA1_Channel6_IRQn            16      //!< DMA1 Channel 6 global Interrupt                      //
#define		_DMA1_Channel7_IRQn            17      //!< DMA1 Channel 7 global Interrupt                      //
#define		_ADC1_2_IRQn                   18      //!< ADC1 and ADC2 global Interrupt                       //
#define  	_USB_HP_CAN1_TX_IRQn           19      //!< USB Device High Priority or CAN1 TX Interrupts       //
#define  	_USB_LP_CAN1_RX0_IRQn          20      //!< USB Device Low Priority or CAN1 RX0 Interrupts       //
#define  	_CAN1_RX1_IRQn                 21      //!< CAN1 RX1 Interrupt                                   //
#define  	_CAN1_SCE_IRQn                 22      //!< CAN1 SCE Interrupt                                   //
#define 	_EXTI9_5_IRQn                  23      //!< External Line[9:5] Interrupts                        //
#define  	_TIM1_BRK_IRQn                 24      //!< TIM1 Break Interrupt                                 //
#define  	_TIM1_UP_IRQn                  25      //!< TIM1 Update Interrupt                                //
#define  	_TIM1_TRG_COM_IRQn             26      //!< TIM1 Trigger and Commutation Interrupt               //
#define  	_TIM1_CC_IRQn                  27      //!< TIM1 Capture Compare Interrupt                       //
#define  	_TIM2_IRQn                     28      //!< TIM2 global Interrupt                                //
#define  	_TIM3_IRQn                     29      //!< TIM3 global Interrupt                                //
#define  	_TIM4_IRQn                     30      //!< TIM4 global Interrupt                                //
#define  	_I2C1_EV_IRQn                  31      //!< I2C1 Event Interrupt                                 //
#define  	_I2C1_ER_IRQn                  32      //!< I2C1 Error Interrupt                                 //
#define 	_I2C2_EV_IRQn                  33      //!< I2C2 Event Interrupt                                 //
#define  	_I2C2_ER_IRQn                  34      //!< I2C2 Error Interrupt                                 //
#define  	_SPI1_IRQn                     35      //!< SPI1 global Interrupt                                //
#define  	_SPI2_IRQn                     36      //!< SPI2 global Interrupt                                //
#define 	_USART1_IRQn                   37      //!< USART1 global Interrupt                              //
#define  	_USART2_IRQn                   38      //!< USART2 global Interrupt                              //
#define  	_USART3_IRQn                   39      //!< USART3 global Interrupt                              //
#define  	_EXTI15_10_IRQn                40      //!< External Line[15:10] Interrupts                      //
#define  	_RTCAlarm_IRQn                 41      //!< RTC Alarm through EXTI Line Interrupt                //
#define  	_USBWakeUp_IRQn                42      //!< USB Device WakeUp from suspend through EXTI Line Interrupt //
#define  	_TIM8_BRK_IRQn                 43      //!< TIM8 Break Interrupt                                 //
#define  	_TIM8_UP_IRQn                  44      //!< TIM8 Update Interrupt                                //
#define  	_TIM8_TRG_COM_IRQn             45      //!< TIM8 Trigger and Commutation Interrupt               //
#define  	_TIM8_CC_IRQn                  46      //!< TIM8 Capture Compare Interrupt                       //
#define  	_ADC3_IRQn                     47      //!< ADC3 global Interrupt                                //
#define  	_FSMC_IRQn                     48      //!< FSMC global Interrupt                                //
#define  	_SDIO_IRQn                     49      //!< SDIO global Interrupt                                //
#define  	_TIM5_IRQn                     50      //!< TIM5 global Interrupt                                //
#define  	_SPI3_IRQn                     51      //!< SPI3 global Interrupt                                //
#define  	_UART4_IRQn                    52      //!< UART4 global Interrupt                               //
#define  	_UART5_IRQn                    53      //!< UART5 global Interrupt                               //
#define 	_TIM6_IRQn                     54      //!< TIM6 global Interrupt                                //
#define  	_TIM7_IRQn                     55      //!< TIM7 global Interrupt                                //
#define  	_DMA2_Channel1_IRQn            56      //!< DMA2 Channel 1 global Interrupt                      //
#define  	_DMA2_Channel2_IRQn            57      //!< DMA2 Channel 2 global Interrupt                      //
#define  	_DMA2_Channel3_IRQn            58      //!< DMA2 Channel 3 global Interrupt                      //
#define  	_DMA2_Channel4_5_IRQn          59      //!< DMA2 Channel 4 and Channel 5 global Interrupt        //
  
  
/*NVIC �Ĵ���*/

#define 	__SET_ENA 			(0xE000E100)	//ʹ���жϵ�ַ
#define 	__CLEAR_ENA			(0xE000E180)	//����жϵ�ַ
#define 	__SET_PEND			(0xE000E200)	//ʹ�ܹ���
#define 	__CLEAR_PEND		(0xE000E280)	//���ܹ���
#define 	__PRIORITY			(0xE000E400)	//���ȼ�
#define 	__SYS_PRIORIY		(0xE000ED18)	//ϵͳ�쳣���ȼ�
#define 	__ACTIVE			(0xE000E300)	//�״̬�Ĵ���
#define 	__CSHCSR			(0xE000ED24)	//ϵͳhandler���Ƽ�״̬�Ĵ���
#define 	__ICSR				(0xE000ED04)	//�жϿ��Ƽ�״̬�Ĵ���

#define 	_SET_ENA 			(unsigned int *)(__SET_ENA)		//ʹ���жϵ�ַ
#define 	_CLEAR_ENA			(unsigned int *)(__CLEAR_ENA)	//����жϵ�ַ
#define 	_SET_PEND			(unsigned int *)(__SET_PEND)	//ʹ�ܹ���
#define 	_CLEAR_PEND			(unsigned int *)(__CLEAR_PEND)	//���ܹ���
#define 	_PRIORITY			(unsigned int *)(__PRIORITY)	//���ȼ�
#define 	_SYS_PRIORIY		(unsigned int *)(__SYS_PRIORIY)	//ϵͳ�쳣���ȼ�
#define 	_ACTIVE				(unsigned int *)(__ACTIVE)		//�״̬�Ĵ���
#define 	_CSHCSR				(unsigned int *)(__CSHCSR)		//ϵͳhandler���Ƽ�״̬�Ĵ���
#define 	_ICSR				(unsigned int *)(__ICSR)		//�жϿ��Ƽ�״̬�Ĵ���

#define 	SET_ENA				(*_SET_ENA) 			//ʹ���жϵ�ַ
#define 	CLEAR_ENA			(*_CLEAR_ENA)			//����жϵ�ַ
#define 	SET_PEND			(*_SET_PEND)			//ʹ�ܹ���
#define 	CLEAR_PEND			(*_CLEAR_PEND)			//���ܹ���
#define 	PRIORITY			(*_PRIORITY)			//���ȼ�
#define 	SYS_PRIORIY			(*_SYS_PRIORIY)			//ϵͳ�쳣���ȼ�
#define 	ACTIVE				(*_ACTIVE)				//�״̬�Ĵ���
#define 	CSHCSR				(*_CSHCSR)				//ϵͳhandler���Ƽ�״̬�Ĵ���
#define 	ICSR				(*_ICSR)				//�жϿ��Ƽ�״̬�Ĵ���

//Ӧ�ó����жϼ���λ���ƼĴ���
#define 	__NVIC_AIRCR			0xE000ED0C			
#define 	_NVIC_AIRCR			ADR(__NVIC_AIRCR)
#define 	NVIC_AIRCR			VAL(__NVIC_AIRCR)

//�ж����ȼ��Ĵ�������
#define __NVIC_PRIx(n) 	(0xE000E400 + n)
#define _NVIC_PRIx(n)	((unsigned char*)(__NVIC_PRIx(n)))
#define NVIC_PRIx(n)	(*(_NVIC_PRIx(n)))



void NVIC_enable_interrupt(U8 interNum);			//ʹ���ⲿ�жϺ�ΪinterNum���ж�
void NVIC_disable_interrupt(U8 interNum);			//�����ⲿ�жϺ�ΪinterNum���ж�
void NVIC_pending_interrupt(U8 interNum);			//�����ж�
void NVIC_clear_pending(U8 interNum);				//ȥ�������ж�

//���ö�Ӧ�жϺŵ��ж����ȼ�
void NVIC_set_PRIx(U16 priNum, U8 pri);
//��ȡ��Ӧ�жϺŵ��ж����ȼ�
U8 NVIC_get_PRIx(U32 priNum);

#endif
