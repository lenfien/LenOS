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
/*********************************数据处理部分*****************************************/
/**************************************************************************************/
char dataBuffer[32];
int  dataBufferIndex = 0;	
int 	intBuffer[12];
int 	intBufferIndex = 0;

//将数据流合成为可用的数据
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
	dataBufferIndex = 0;	//将总缓冲区的索引设置为0
	return dataType;
}

#define GET_FONT_COLOR	RGB(0x1, 0x16, 0x13)
//用来接收和解码数据
bool IsReceiving = 0;
S32 dataIndex = -3;
S32 dataSize = 0;
S32 dataAmount = 0;
//U8 FreeState_helper = 0xFF;	//Free状态下，存储将要发送的指令
void cortexMsp_data_handler(U8 data)
{
	static DATA_TYPE dataType = _char;	
	static S32 cmdData = 0;		//数据传输开始,标志将要传输的数据表示什么信息，是指南针，还是超声波
	U32 oldColor;
	
	if(!OnLineState)
	{
		OnLineState = 1;
		cortexMsp_update_connect_state();
	}
	oldColor = LCD_set_font_color(GET_FONT_COLOR);
	LCD_printf(SCREEN_SIZE_X*3/5 + 15, SCREEN_SIZE_Y/6 - FONT_HIGH + 5, "  Get:0x%x", data);
	LCD_set_font_color(oldColor);
	
	//如果空闲，则看接收到的数据是否为CMD_SUPERSONIC_START或CMD_COMPASS_START,如果是，则开始传输
	if(IsReceiving == 0)
	{
		if(data == 0x00)
			return;
		
		if(data == ACK)	//如果接收到的是ACK信息，则将Ack标志置一
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
	//如果忙的话,在dataIndex<0时记录数据的控制信息,然后开始往dataBuffer里写数据，在这个过程中一直累加dataIndex
	else
	{
		//在dataIndex小于0时，接收到的数据位控制信息
		if(dataIndex < 0)
		{
			switch(dataIndex)
			{
				case -3:	//数据类型信息
					dataType = (DATA_TYPE)data;
					break;
				case -2:	//数据类型大小
					dataSize = data;
				break;
				case -1:	//数据个数
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
		//如果接收到的数据已经到指定的个数，则只等待停止指令, 如果等待到了停止指令，则开始合并数据
		if(dataIndex >= dataAmount && data == CMD_STOP)
		{
			if(dataType == _int)
				cortexMsp_data_combine(cmdData, dataType, dataSize, dataAmount);
			
			//初始化所有状态为
			IsReceiving = 0;
			dataBufferIndex = dataIndex;
			dataIndex = -3;
			dataSize = 0;
			
			//处理从小车传过来的数据
			switch(cmdData)
			{
				case CMD_SUPERSONIC_START:	//超声波数据
					cortexMsp_update_supersonic_state();
					break;
				case CMD_COMPASS_START:			//指南针数据
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
		//其它情况则只记录数据
		else
			dataBuffer[dataIndex++] = data;
	}
}

/*
	从ARM向MSP发送字符
	会等待回馈信号
	如果没有等到则会尝试3次
	发送成功返回1，否则返回0
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
		
		//如果尝试发送了两次，并且失败的原因都是在接收数据，
		//那就终止接收，再试最后一次
		if(tryTimes == 2 && IsReceiving)	
		{
			LCD_set_font_color(RGB_RED);
			//初始化所有状态为S
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
	
	FreeState = -1;		//是否小车处于自由状态
	OnLineState = 0;
	BarrierState = -1;
	cortexMsp_update_state();
	
	return 0;
}
