#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

#include "cnf_usart.h"

#include "ssd1289_base.h"
#include "ssd1289_type.h"

#include "com.h"

#include "font_operation.h"
#include "font_lib.h"


/*
��x,y������(RGB_color���Ƹĵ���ɫ)
	������240*320�����COLOR_262K��COLOR_65K
	������320*240�����COLOR_262K��COLOR_65K
	������LCD_SSD1289_set_GDDRAM_position����
	��ɫ��LCD_SSD1289_set_point����
*/
void LCD_draw_point(U16 x, U16 y, U32 RGB_color)
{	
	if(x > SCREEN_SIZE_X || y > SCREEN_SIZE_Y)
		return;
	SSD1289_set_GDDRAM_position(x, y);
	SSD1289_set_point(RGB_color);
	//delay(100);
}

//���x,y�㴦����ɫ
U32 LCD_get_point(U16 x, U16 y)
{
	if(x > SCREEN_SIZE_X || y > SCREEN_SIZE_Y)
		return 0;
	SSD1289_set_GDDRAM_position(x, y);
	return SSD1289_get_point();
}

/*
	��һ������
	x, y,��ʼ����
	width,high:����
	color:	��ɫ
	�˺��������ٶȺܿ�
*/
void LCD_draw_rectangle(U16 x, U16 y, U16 width, U16 high, U32 color)
{
	int i = width * high;
	
	width = (x + width > SCREEN_SIZE_X) ? SCREEN_SIZE_X - x : width;
	high  = (y + high  > SCREEN_SIZE_Y) ? SCREEN_SIZE_Y - y : high; 
	
	SSD1289_set_window(x , y,  (x + width - 1), y + high - 1);
	
	while(i--)
		SSD1289_set_point(color);
		
	SSD1289_set_full_window();
}


/*
	��xy���������_x_y�㻭һ��ֱ�ߣ���ɫ��colorָ��
*/
void LCD_draw_line(int x, int y, int _x, int _y, U32 color)
{
	int x_len = _x - x;
	int y_len = _y - y;

	float xDiv;
	float yDiv;
	float xIndex;
	float yIndex;
	int xStart, xEnd;
	int yStart, yEnd;
	
	//��ֱ
	if(x_len == 0)
	{
		yStart = (y > _y) ? _y : y;
		yEnd = (y > _y) ? y : _y;

		for(yIndex = yStart; yIndex <= yEnd; yIndex ++)
			LCD_draw_point(x, yIndex, color);
		return;
	}
	
	//ˮƽ���
	if(y_len == 0)
	{
	
		xStart = (x > _x) ? _x : x;
		xEnd = (x > _x) ? x : _x;

		for(xIndex = xStart; xIndex < xEnd; xIndex ++)
			LCD_draw_point(xIndex, y, color);
		return;
	}

	//����
	if(x_len >= 0)
	{
		xStart = x;
		xEnd = _x;
	}
	else
	{
		xStart = _x;
		xEnd = x;
	}
	
	if(abs(x_len) >= abs(y_len))
	{
		xDiv = x_len/(float)abs(x_len);
		yDiv = y_len/(float)abs(x_len);
	}
	else
	{
		yDiv = y_len/(float)abs(y_len);
		xDiv = x_len/(float)abs(y_len);
	}

	for(xIndex = x, yIndex = y; 
		xIndex <= xEnd && xIndex >= xStart;  
			xIndex = xIndex + xDiv, yIndex = yIndex + yDiv)
	{
		LCD_draw_point((int)xIndex, (int)yIndex, color);
	}
}

void LCD_draw_lines(POINT *p, U32 pointNum, U32 color)
{
	int index;
	for(index = 0; index < pointNum - 1; index ++)
		LCD_draw_line(p[index].x, p[index].y, p[index + 1].x, p[index + 1].y, color);
}

//��һ�����ľ���
void LCD_draw_empty_rectangle(U32 xStart, U32 yStart, U32 width, U32 high, U32 color)
{
	U32 xEnd = xStart + width;
	U32 yEnd = yStart + high;
	LCD_draw_line(xStart, yStart, xEnd, yStart, color);
	LCD_draw_line(xEnd, yStart, xEnd, yEnd, color);
	LCD_draw_line(xEnd, yEnd, xStart, yEnd, color);
	LCD_draw_line(xStart, yEnd, xStart, yStart, color);
}


void LCD_draw_circle(S32 cX, S32 cY, S32 cR, U32 color)
{
	int yIndex;
	int xIndex;
	for(xIndex = -cR; xIndex < cR; xIndex ++)
	{
		yIndex = sqrt(cR*cR - xIndex*xIndex);
		LCD_draw_line(xIndex + cX, yIndex + cY, xIndex + cX, -yIndex + cY, color);
	}
}

void LCD_draw_empty_circle(S32 cX, S32 cY, S32 cR, U32 color)
{
	int yIndex;
	int xIndex;
	for(xIndex = -cR; xIndex < cR; xIndex ++)
	{
		yIndex = sqrt(cR*cR - xIndex*xIndex);
		LCD_draw_point(xIndex + cX, yIndex + cY, color);
		LCD_draw_point(xIndex + cX, -yIndex + cY, color);
		LCD_draw_point(yIndex +cX, xIndex + cY, color);
		LCD_draw_point(-yIndex + cX, xIndex + cY, color);
	}
}



//**********************����ĺ�����Ҫ��������Graphics*******************//
void LCD_SSD1289_graphic_test()
{
	LCD_draw_point(319, 239, RGB_RED);
	LCD_draw_line(0, 0, 320, 240, RGB_RED);
}
