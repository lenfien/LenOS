/*
	此文件定义了stm32f103zet所有外部中断 所有的外部中断都可在此实现
*/

#include "base.h"
#include "com.h"
#include "cnf.h"

#include "ads7843.h"
#include "touchable.h"
#include "out.h"
#include "touch.h"
#include "system.h"
#include "Color.h"

//--------------------------------内核#异常-----------------------------------//
extern "C" void  NMI_Handler(void )
{
	return;
}

extern "C" void  HardFault_Handler(void )
{
	//Out::printl(5, 5, "HardFaul!!!!");
	return;
}
                                                                                                                
 extern "C" void  MemManage_Handler(void )
{
	Out::printl(5, 6, "MemFaul!!!!");
	return;
}

 extern "C" void  BusFault_Handler(void )
{
	return;
}

 extern "C" void  UsageFault_Handler(void )
{
	return;
}

extern "C" void  SVC_Handler(void )
{
	return;
}

extern "C" void  DebugMon_Handler(void )
{
	return;
}

extern "C" void  PendSV_Handler(void )
{
	return;
}


//int logo_counter;
extern "C" void  SysTick_Handler()
{	
	static int i = 0;
	Out::print("%d", i++);
	return ;
}

/********************************内核异常结束********************************/
//-----------------------------------外设中断-----------------------------------//

//中断函数为触屏提供服务
extern "C" void  EXTI9_5_IRQHandler(void )
{
	if(!EXTI_is_interrupted_by_line_7())
		return; 
	
	EXTI_clear_interrupt_flag_at_line_7();
	
	NVIC_disable_interrupt(_DMA1_Channel1_IRQn); 
	NVIC_disable_interrupt(_RTC_IRQn);
	NVIC_disable_interrupt(_EXTI9_5_IRQn);
	
	ADS7843::update_state();//更新触摸屏状态, 
	System::touch_process();
	
	NVIC_enable_interrupt(_EXTI9_5_IRQn);
	NVIC_enable_interrupt(_DMA1_Channel1_IRQn);
	NVIC_enable_interrupt(_RTC_IRQn);	
	
	return;
}

extern "C" void  WWDG_IRQHandler(void )
{
	return;
} 


 extern "C" void  PVD_IRQHandler(void )
{
	return;
}	


 extern "C" void  TAMPER_IRQHandler(void )
{
	return;
}  

 extern "C" void  RTC_IRQHandler(void )
{
	return;
}  


 extern "C" void  FLASH_IRQHandler(void )
{
	return;
} 


 extern "C" void  RCC_IRQHandler(void )
{
	return;
}  


 extern "C" void  EXTI0_IRQHandler(void )
{
	return;
}  


 extern "C" void  EXTI1_IRQHandler(void )
{
	return;
} 


 extern "C" void  EXTI2_IRQHandler(void )
{
	return;
}  


 extern "C" void  EXTI3_IRQHandler(void )
{
	return;
} 


 extern "C" void  EXTI4_IRQHandler(void )
{
	return;
}  

 extern "C" void  DMA1_Channel1_IRQHandler(void )
{	
	

	return;
}  

 extern "C" void  DMA1_Channel2_IRQHandler(void )
{
	return;
} 


 extern "C" void  DMA1_Channel3_IRQHandler(void )
{
	return;
} 


 extern "C" void  DMA1_Channel4_IRQHandler(void )
{
	return;
}  


 extern "C" void  DMA1_Channel5_IRQHandler(void )
{
	return;
}  


 extern "C" void  DMA1_Channel6_IRQHandler(void )
{
	return;
}  


 extern "C" void  DMA1_Channel7_IRQHandler(void )
{
	return;
}  

 extern "C" void  ADC1_2_IRQHandler(void )
{

	return;
}  

 extern "C" void  USB_HP_CAN1_TX_IRQHandler(void )
{
	return;
} 

 extern "C" void  USB_LP_CAN1_RX0_IRQHandler(void )
{
	return;
} 

 extern "C" void  CAN1_RX1_IRQHandler(void )
{
	return;
} 


 extern "C" void  CAN1_SCE_IRQHandler(void )
{
	return;
}



//刹车事件
 extern "C" void  TIM1_BRK_IRQHandler(void )
{
	return;
} 

//更新事件
//现在函数里的东西是给ADConverter服务的
 extern "C" void  TIM1_UP_IRQHandler(void )
{

	return;
} 

//触发沿和端口事件
 extern "C" void  TIM1_TRG_COM_IRQHandler(void )
{
	return;
} 

//TIM1捕获比较事件
 extern "C" void  TIM1_CC_IRQHandler(void )
{

	return;
}


 extern "C" void  TIM2_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM3_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM4_IRQHandler(void )
{
	return;
} 


 extern "C" void  I2C1_EV_IRQHandler(void )
{
	return;
}


 extern "C" void  I2C1_ER_IRQHandler(void )
{
	return;
}


 extern "C" void  I2C2_EV_IRQHandler(void )
{
	return;
}


 extern "C" void  I2C2_ER_IRQHandler(void )
{
	return;
}


 extern "C" void  SPI1_IRQHandler(void )
{
	return;
}


 extern "C" void  SPI2_IRQHandler(void )
{
	return;
}

 extern "C" void  cortexMsp_data_handler(U8);
 extern "C" void  USART1_IRQHandler(void )
{
		return;
}


 extern "C" void  USART2_IRQHandler(void )
{
	return;
}


 extern "C" void  USART3_IRQHandler(void )
{
	return;
}


 extern "C" void  EXTI15_10_IRQHandler(void )
{
	return;
}


 extern "C" void  RTCAlarm_IRQHandler(void )
{
	return;
} 


 extern "C" void  USBWakeUp_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM8_BRK_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM8_UP_IRQHandler(void )
{
		return;
}


 extern "C" void  TIM8_TRG_COM_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM8_CC_IRQHandler(void )
{
	return;
}


 extern "C" void  ADC3_IRQHandler(void )
{
	return;
}


 extern "C" void  FSMC_IRQHandler(void )
{
	return;
}


 extern "C" void  SDIO_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM5_IRQHandler(void )
{
	return;
}


 extern "C" void  SPI3_IRQHandler(void )
{
	return;
}


 extern "C" void  UART4_IRQHandler(void )
{
	return;
}


 extern "C" void  UART5_IRQHandler(void )
{
	return;
}


 extern "C" void  TIM6_IRQHandler(void )
{
	return;
}



 extern "C" void  TIM7_IRQHandler(void )
{
	return;
}



 extern "C" void  DMA2_Channel1_IRQHandler(void )
{
	return;
}

 extern "C" void  DMA2_Channel2_IRQHandler(void )
{
	return;
}

 extern "C" void  DMA2_Channel3_IRQHandler(void )
{
	return;
}

 extern "C" void  DMA2_Channel4_5_IRQHandler(void )
{
	return;
}

//-----------------------------------外设中断结束-----------------------------------//
