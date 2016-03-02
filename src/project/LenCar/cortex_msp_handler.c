
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "com.h"
#include "base.h"
#include "cnf.h"

#include "ssd1289.h"

#include "ads7483_base.h"

#include "font.h"
#include "button.h"
#include "window.h"

#include "adconverter.h"
#include "daConverter.h"

#include "cortex_msp.h"


/**************************************************************************************/
/*********************************Pad��ť������**************************************/
/**************************************************************************************/

BUTTON* btnPad;
void cortexMsp_btnHandler_pad_press(BUTTON* pBtn) 			
{
	
}

int CirclePreX = -1, CirclePreY = -1;
int touchPreX = -1, touchPreY = -1;
int preCommand = -1;
void cortexMsp_btnHandler_pad_hold(POINT* p, BUTTON* pBtn)
{
	int curCommand = 0;
	
	//���㰴ť��������
	int oX = btnPad->xStart + btnPad->buttonWidth/2;
	int oY = btnPad->yStart + btnPad->buttonHigh/2;
	int oR = btnPad->buttonWidth/2;
	int x;
	int y;
	double k;	//б��
	double angle;
	
	//������ڵ�λ5�������ڶ������㶯
	if(is_in_range(p->x, p->y, touchPreX - 3, touchPreY - 3, touchPreX + 3, touchPreY + 3))
		return;
	
	touchPreX = p->x;
	touchPreY = p->y;
	
	if(CirclePreX != -1)
		LCD_draw_circle(CirclePreX, CirclePreY, 20, PAD_BACK_COLOR);
	else
		LCD_draw_circle(btnPad->xStart + btnPad->buttonWidth/2, btnPad->yStart + btnPad->buttonWidth/2, 20, PAD_BACK_COLOR);
	
	//������ڰ�ť�ķ�Χ�ڣ������Բ��λ��
	if(is_in_range_circle(p->x, p->y, 
		btnPad -> xStart + btnPad->buttonWidth/2, btnPad->yStart + btnPad->buttonHigh/2, 
				(btnPad->buttonWidth > btnPad->buttonHigh ? btnPad->buttonHigh : btnPad->buttonWidth)/2 - 20))
	{
		//LCD_printf(0, 40, "in ");
		x = p->x;
		y = p->y;
		
		CirclePreX = p->x;
		CirclePreY = p->y;
	}
	else	//������ڰ�ť�ⲿ
	{
		//����б��
		k = -(double)(p->y - oY)/(double)(p->x - oX);
		
		//����Ƕ�ֵ
		angle = atan(k);
		if(angle < 0)
			angle += PI;
		
		y = (oR - 20)*sin(angle);
		x = (oR - 20)*cos(angle);
		
		y = p->y < oY ? oY - y : oY + y;
		x = p->y < oY ? oX + x : oX - x;
		
		CirclePreX = x;
		CirclePreY = y;
	}
	LCD_draw_circle(x, y, 20, PAD_FRONT_COLOR);
	
#define CORNER_X (btnPad->buttonWidth/3)
#define CORNER_Y (btnPad->buttonHigh/3)
	
	//LCD_printf(0, 0, "x = %3d\ny=%3d", x, y);
	//����
	if(x < (oX - 10) && y > btnPad->yStart + CORNER_Y && y< btnPad->yStart + btnPad->buttonHigh - CORNER_Y)
	{
		cortexMsp_update_pad_state( "Left    ");
		curCommand = DIR_LEFT;
	}
	//����
	else if(x > (oX + 10) && y > btnPad->yStart + CORNER_Y && y< btnPad->yStart + btnPad->buttonHigh - CORNER_Y)
	{
		cortexMsp_update_pad_state( "Right     ");
		curCommand = DIR_RIGHT;
	}
	//��ǰ
	else if(y < (oY - 10) && x > btnPad->xStart + CORNER_X && x< btnPad->xStart + btnPad->buttonWidth - CORNER_X)
	{
		cortexMsp_update_pad_state("Forward      ");
		curCommand = DIR_UP;
	}
	//���
	else if(y > (oY + 10) && x > btnPad->xStart + CORNER_X && x< btnPad->xStart + btnPad->buttonWidth - CORNER_X)
	{
		cortexMsp_update_pad_state( "Backward      ");
		curCommand = DIR_DOWN;
	}
	//ֹͣ
	else
	{
		cortexMsp_update_pad_state("Stop      ");
		curCommand = DIR_STOP;
		
	}
	if(preCommand != curCommand)
	{
		cortexMsp_send_data(curCommand);
	//LCD_printf(0,70, "%d send ok!", curCommand);
		preCommand = curCommand;
	}
}

void cortexMsp_btnHandler_pad_release(BUTTON* pBtn)
{
	if(CirclePreX != -1)
			LCD_draw_circle(CirclePreX, CirclePreY, 20, PAD_BACK_COLOR);
	LCD_draw_circle(btnPad->xStart + btnPad->buttonHigh/2, 
		btnPad->yStart + btnPad->buttonWidth/2,  20, PAD_FRONT_COLOR); //��СԲ�ص����ĵ�
	CirclePreX = btnPad->xStart + btnPad->buttonHigh/2;
	CirclePreY = btnPad->yStart + btnPad->buttonWidth/2;
	cortexMsp_send_data(DIR_STOP);
	cortexMsp_update_pad_state("lenfien");
	
	preCommand = -1;
	touchPreX = -1;
	touchPreY = -1;
	
	//ÿ�����ͷ�֮�󣬶�����һ��ָ������������ָ��Ը���ָ������ʾ
	cortexMsp_send_data(CMD_GET_COMPASS_DATA);
}
/**************************************************************************************/
/*********************************barrierSwitch��ť������**************************************/
/**************************************************************************************/

void 	cortexMsp_btnHandler_barrierSwitch_press(BUTTON* pBtn) 			//���������:�ڰ�ť���һ��ʱִ��
{
	
}

void	cortexMsp_btnHandler_barrierSwitch_hold(POINT* p, BUTTON* pBtn)	//���ִ�����:�ڰ�ť���ְ���ʱִ��
{
	
}

void	cortexMsp_btnHandler_barrierSwitch_release(BUTTON* pBtn)
{
	if(cortexMsp_send_data(BarrierState ? FUNC_BARRIER_OFF : FUNC_BARRIER_ON))
	{
			BarrierState = !BarrierState;
	}
	else
	{
		BarrierState = -1;
	}
	cortexMsp_update_barrier_state();
}
/**************************************************************************************/
/*********************************getBarrier��ť������**************************************/
/**************************************************************************************/

void cortexMsp_btnHandler_getBarrier_press(BUTTON* pBtn) 			//���������:�ڰ�ť���һ��ʱִ��
{
	
}
void cortexMsp_btnHandler_getBarrier_hold(POINT *p, BUTTON* pBtn)	//���ִ�����:�ڰ�ť���ְ���ʱִ��
{
	
}
void cortexMsp_btnHandler_getBarrier_release(BUTTON* pBtn)
{
	cortexMsp_send_data(CMD_GET_BARRIER_DATA);
}

/**************************************************************************************/
/*********************************getAngle��ť������**************************************/
/**************************************************************************************/

void cortexMsp_btnHandler_getAngle_press(BUTTON* pBtn)			//���������:�ڰ�ť���һ��ʱִ��
{
	
}
void cortexMsp_btnHandler_getAngle_hold(POINT* p, BUTTON* pBtn)	//���ִ�����:�ڰ�ť���ְ���ʱִ��
{
	
}							
void cortexMsp_btnHandler_getAngle_release(BUTTON* pBtn)
{
	cortexMsp_send_data(CMD_GET_COMPASS_DATA);
}
/**************************************************************************************/
/*********************************getAngle��ť������**************************************/
/**************************************************************************************/
void cortexMsp_btnHandler_free_press(BUTTON* pBtn) 			//���������:�ڰ�ť���һ��ʱִ��
{
	
}

void cortexMsp_btnHandler_free_hold(POINT* p, BUTTON* pBtn)	//���ִ�����:�ڰ�ť���ְ���ʱִ��
{
	
}

void cortexMsp_btnHandler_free_release(BUTTON* pBtn)
{
	
	U8 cmd = FreeState ? CMD_GO_FREE_OFF : CMD_GO_FREE_ON;
	
	if(cortexMsp_send_data(cmd))
	{
		FreeState = !FreeState;
	}
	else
		FreeState = -1;
	cortexMsp_update_free_state();
}

/**************************************************************************************/
/*********************************getAngle��ť������**********************************/
/**************************************************************************************/
void  cortexMsp_btnHandler_onOff_release(BUTTON* pBtn)
{
	U8 cmd = OnLineState ? CMD_TURN_OFF : CMD_TURN_ON;
	
	if(cortexMsp_send_data(cmd))
	{
		if(cmd == CMD_TURN_OFF)
		{
			OnLineState = 0;
			FreeState = -1;
			BarrierState = -1;
			cortexMsp_update_state();
		}
	}
}
