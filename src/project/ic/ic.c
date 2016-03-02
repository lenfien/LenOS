#include "base_rcc.h"
#include "base_gpio.h"
#include "base_i2c.h"
#include "cnf_i2c.h"
#include "cnf_usart.h"




//给IC卡的add地址处发送data数据
void IC_send_data(U8 add, U8 data)
{
	//等待不忙
	//USART1_printf("忙等待中\n");
	while(I2C1_is_busy());
	//USART1_printf("忙等待结束\n");
	
	//USART1_printf("起始条件传送等待\n");
	
	I2C1_generate_start();
	while(!I2C1_is_master());
	//USART1_printf("进入主模式\n");
	
	I2C1_send_address_send(0xA0);
	while(!I2C1_is_address_sent());	//等待地址发送
	
	if(I2C1_is_receiver())			//如果成了接收器模式,则死在这
		while(1);
	
	I2C1_send_data(add);		//发送地址 
	while(!I2C1_is_data_register_empty());
	
	I2C1_disable_acknowledge();
	I2C1_send_data(data);		//发送数据
	while(!I2C1_is_transfer_finish());
	
	I2C1_generate_stop();
	I2C1_enable_acknowledge();
	//USART1_printf("字节发送完成");
}




U8 IC_read_data(U8 address)
{
//	USART1_printf("读忙等待中\n");
	while(I2C1_is_busy());
//	USART1_printf("读忙等待完成\n");
	
//	USART1_printf("等待起始条件\n");
	I2C1_generate_start();
	while(!I2C1_is_master());
//	USART1_printf("起始条件发送完成\n");
	
	I2C1_send_address_send(0xA0);
	while(!I2C1_is_address_sent());	//等待地址发送
	
	if(I2C1_is_receiver())	//如果成了接收器模式,则死在这
		while(1);
	
	//USART1_printf("等待发送地址\n");
	while(!I2C1_is_data_register_empty());
	I2C1_send_data(address);		//发送数据
	while(!I2C1_is_data_register_empty());
	while(!I2C1_is_transfer_finish());
	//USART1_printf("地址发送成功\n");
	
	//while(I2C1_is_busy());
	
	I2C1_generate_start();
	//while(!I2C1_is_master());
	//USART1_printf("读起始位完成\n");
	while(!I2C1_is_start_generated());
	I2C1_send_address_receive(0xA0);
	while(!I2C1_is_address_sent());		//等待地址发送
	
	//USART1_printf("DR = %x\n", I2C1_DR);
	
	if(I2C1_is_transmitter())	//如果成了发送器模式,则死在这
		while(1);
	I2C1_disable_acknowledge();
	
	while(!I2C1_is_data_register_full()); //等待接收器满	
	//USART1_printf("DR = %d\n", I2C1_DR);
	I2C1_generate_stop();
	I2C1_enable_acknowledge();
	
	return I2C1_get_data();
}



void IC_test()
{
	int temp = 0;
	int index;
	//I2C1_reset();
	I2C1_cnf_init();
//	for(index = 0; index < 256; index ++)
	{
//		USART1_printf("发送数据:%d\n", temp);
//		IC_send_data(index, temp ++);
//		delay_ms(10);
	}
		
	
	for(index = 0; index < 100000; index ++)
	{

		
		USART1_printf("%d", IC_read_data(index));
	}
		
	
	while(1);
}
