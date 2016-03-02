#include "base_rcc.h"
#include "base_gpio.h"
#include "base_i2c.h"
#include "cnf_i2c.h"
#include "cnf_usart.h"




//��IC����add��ַ������data����
void IC_send_data(U8 add, U8 data)
{
	//�ȴ���æ
	//USART1_printf("æ�ȴ���\n");
	while(I2C1_is_busy());
	//USART1_printf("æ�ȴ�����\n");
	
	//USART1_printf("��ʼ�������͵ȴ�\n");
	
	I2C1_generate_start();
	while(!I2C1_is_master());
	//USART1_printf("������ģʽ\n");
	
	I2C1_send_address_send(0xA0);
	while(!I2C1_is_address_sent());	//�ȴ���ַ����
	
	if(I2C1_is_receiver())			//������˽�����ģʽ,��������
		while(1);
	
	I2C1_send_data(add);		//���͵�ַ 
	while(!I2C1_is_data_register_empty());
	
	I2C1_disable_acknowledge();
	I2C1_send_data(data);		//��������
	while(!I2C1_is_transfer_finish());
	
	I2C1_generate_stop();
	I2C1_enable_acknowledge();
	//USART1_printf("�ֽڷ������");
}




U8 IC_read_data(U8 address)
{
//	USART1_printf("��æ�ȴ���\n");
	while(I2C1_is_busy());
//	USART1_printf("��æ�ȴ����\n");
	
//	USART1_printf("�ȴ���ʼ����\n");
	I2C1_generate_start();
	while(!I2C1_is_master());
//	USART1_printf("��ʼ�����������\n");
	
	I2C1_send_address_send(0xA0);
	while(!I2C1_is_address_sent());	//�ȴ���ַ����
	
	if(I2C1_is_receiver())	//������˽�����ģʽ,��������
		while(1);
	
	//USART1_printf("�ȴ����͵�ַ\n");
	while(!I2C1_is_data_register_empty());
	I2C1_send_data(address);		//��������
	while(!I2C1_is_data_register_empty());
	while(!I2C1_is_transfer_finish());
	//USART1_printf("��ַ���ͳɹ�\n");
	
	//while(I2C1_is_busy());
	
	I2C1_generate_start();
	//while(!I2C1_is_master());
	//USART1_printf("����ʼλ���\n");
	while(!I2C1_is_start_generated());
	I2C1_send_address_receive(0xA0);
	while(!I2C1_is_address_sent());		//�ȴ���ַ����
	
	//USART1_printf("DR = %x\n", I2C1_DR);
	
	if(I2C1_is_transmitter())	//������˷�����ģʽ,��������
		while(1);
	I2C1_disable_acknowledge();
	
	while(!I2C1_is_data_register_full()); //�ȴ���������	
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
//		USART1_printf("��������:%d\n", temp);
//		IC_send_data(index, temp ++);
//		delay_ms(10);
	}
		
	
	for(index = 0; index < 100000; index ++)
	{

		
		USART1_printf("%d", IC_read_data(index));
	}
		
	
	while(1);
}
