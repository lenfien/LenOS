#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lenfien.h"

#include "core_nvic.h"
#include "core_systick.h"

#include "com.h"
#include "base.h"


#include "cnf.h"


#include "ssd1289.h"

#include "ads7483_base.h"
#include "ssd1289_font.h"
#include "ds18b20_base.h"

#include "font.h"
#include "button.h"
#include "window.h"

#include "adconverter.h"
#include "daConverter.h"

#include "cortex_msp.h"


/**************************************************************************************/
/*********************************���ݴ�����*****************************************/
/**************************************************************************************/
char dataBuffer[32];
int  dataBufferIndex = 0;	
int 	intBuffer[12];
int 	intBufferIndex = 0;

//���������ϳ�Ϊ���õ�����
DATA_TYPE cortexMsp_data_combine(U8 cmd, DATA_TYPE dataType, U8 dataSize, U32 dataAmount)
{
	int index;
	for(index = 0; index < dataAmount; index += dataSize)
	{
		int temp = 0;
		int _index;
		for(_index = 0; _index < dataSize; _index ++)
			temp |= (dataBuffer[index + _index] << (_index * 8));
		intBuffer[index/dataSize] = temp;
	}
	intBufferIndex = dataAmount/dataSize;
	dataBufferIndex = 0;	//���ܻ���������������Ϊ0
	return dataType;
}

#define GET_FONT_COLOR	RGB(0x1, 0x16, 0x13)
//�������պͽ�������
bool IsReceiving = 0;
S32 dataIndex = -3;
S32 dataSize = 0;
S32 dataAmount = 0;
//U8 FreeState_helper = 0xFF;	//Free״̬�£��洢��Ҫ���͵�ָ��
void cortexMsp_data_handler(U8 data)
{
	static DATA_TYPE dataType = _char;	
	static S32 cmdData = 0;		//���ݴ��俪ʼ,��־��Ҫ��������ݱ�ʾʲô��Ϣ����ָ���룬���ǳ�����
	U32 oldColor;
	
	if(!OnLineState)
	{
		OnLineState = 1;
		cortexMsp_update_connect_state();
	}
	oldColor = LCD_set_font_color(GET_FONT_COLOR);
	LCD_printf(SCREEN_SIZE_X*3/5 + 15, SCREEN_SIZE_Y/6 - FONT_HIGH + 5, "  Get:0x%x", data);
	LCD_set_font_color(oldColor);
	
	//������У��򿴽��յ��������Ƿ�ΪCMD_SUPERSONIC_START��CMD_COMPASS_START,����ǣ���ʼ����
	if(IsReceiving == 0)
	{
		if(data == 0x00)
			return;
		
		if(data == ACK)	//������յ�����ACK��Ϣ����Ack��־��һ
		{
			if(AckSignal == 1)
				AckSignalSure = 1;
			else
				AckSignal = 1;
			return;
		}
	
		if(data == CMD_SUPERSONIC_START || data == CMD_COMPASS_START || data == CMD_STATE_START)
		{
			IsReceiving = 1;
			cmdData = data;
		}
		else
			return;
	}
	//���æ�Ļ�,��dataIndex<0ʱ��¼���ݵĿ�����Ϣ,Ȼ��ʼ��dataBuffer��д���ݣ������������һֱ�ۼ�dataIndex
	else
	{
		//��dataIndexС��0ʱ�����յ�������λ������Ϣ
		if(dataIndex < 0)
		{
			switch(dataIndex)
			{
				case -3:	//����������Ϣ
					dataType = (DATA_TYPE)data;
					break;
				case -2:	//�������ʹ�С
					dataSize = data;
				break;
				case -1:	//���ݸ���
					dataAmount = data;
					break;
				default:
					break;
			}
			dataIndex++;
			return;
		}
		else
		{
			if((dataType != _char && dataType != _int && dataType != _float) || dataSize <= 0 || dataAmount <= 0)
			{
				IsReceiving = 0;
				dataBufferIndex = dataIndex;
				dataIndex = -3;
				dataSize = 0;
				return;
			}
		}
		//������յ��������Ѿ���ָ���ĸ�������ֻ�ȴ�ָֹͣ��, ����ȴ�����ָֹͣ���ʼ�ϲ�����
		if(dataIndex >= dataAmount && data == CMD_STOP)
		{
			if(dataType == _int)
				cortexMsp_data_combine(cmdData, dataType, dataSize, dataAmount);
			
			//��ʼ������״̬Ϊ
			IsReceiving = 0;
			dataBufferIndex = dataIndex;
			dataIndex = -3;
			dataSize = 0;
			
			//�����С��������������
			switch(cmdData)
			{
				case CMD_SUPERSONIC_START:	//����������
					cortexMsp_update_supersonic_state();
					break;
				case CMD_COMPASS_START:			//ָ��������
					cortexMsp_update_compass_state();	
					break;
				case CMD_STATE_START:
					FreeState = __get_bit(dataBuffer[0], 0);
					BarrierState = __get_bit(dataBuffer[0], 1);
					cortexMsp_update_state();
				break;
				default:
					break;
			}
			return;
		}
		//���������ֻ��¼����
		else
			dataBuffer[dataIndex++] = data;
	}
}

/*
	��ARM��MSP�����ַ�
	��ȴ������ź�
	���û�еȵ���᳢��3��
	���ͳɹ�����1�����򷵻�0
*/
#define SEND_FONT_COLOR RGB(0xd, 0x23, 0x1)
bool cortexMsp_send_data(U8 data)
{
	S32 index = 0;
	int tryTimes = 1;
	U32 oldColor = LCD_set_font_color(SEND_FONT_COLOR);
	
	LCD_printf(0, 3, "Send:0x%0x...    ", data);
	do
	{
		LCD_printf(FONT_WIDTH('A') * 12, 3, "%ds", tryTimes);
		index = (data == CMD_GET_BARRIER_DATA) || (data == CMD_GET_COMPASS_DATA) || (data == CMD_GET_STATE) || (data == CMD_GO_FREE_OFF)
			? 5000000 : 1000000;
		AckSignal = 0;
		AckSignalSure = 0;
		if(!IsReceiving)
		{
			USART1_put_char(data);
			while((0 == AckSignal || 0 == AckSignalSure) && index-- > 0);
		}
		else
			while(index--);
		
		//������Է��������Σ�����ʧ�ܵ�ԭ�����ڽ������ݣ�
		//�Ǿ���ֹ���գ��������һ��
		if(tryTimes == 2 && IsReceiving)	
		{
			LCD_set_font_color(RGB_RED);
			//��ʼ������״̬ΪS
			IsReceiving = 0;
			dataBufferIndex = dataIndex;
			dataIndex = -3;
			dataSize = 0;
			
			tryTimes = 1;
		}
	}
	while(tryTimes++ < 3 && (AckSignal == 0 || AckSignalSure == 0));
	
	if(AckSignal == 1 && AckSignalSure == 1)
	{
		AckSignal = 0;
		AckSignalSure = 0;
		LCD_printf(FONT_WIDTH('A') * 12, 3, "done", data);
		//cortexMsp_update_connect_state(1);
		OnLineState = 1;
		cortexMsp_update_connect_state();
		LCD_set_font_color(oldColor);
		return 1;
	}
	
	AckSignal = 0;
	AckSignalSure = 0;
	oldColor = LCD_set_font_color(RGB_RED);
	LCD_printf(0, 3, "Send:0x%0x...fail", data);
	LCD_set_font_color(oldColor);
	OnLineState = 0;
	
	FreeState = -1;		//�Ƿ�С����������״̬
	OnLineState = 0;
	BarrierState = -1;
	cortexMsp_update_state();
	
	return 0;
}
