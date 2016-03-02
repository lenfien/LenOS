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
#include "ads7483.h"
#include "ssd1289.h"

#include "font.h"
#include "window.h"
#include "button.h"

#include "adconverter.h"
#include "daConverter.h"
#include "cortex_msp.h"


#define BALL_COLOR RGB_RED

//定义直线
typedef struct 
{
	POINT 	p1;
	POINT 	p2;
	double 	angle;
	double 	A;
	double 	B;
	double 	C;
}LINE;

LINE Lines[48] =						//所有的障碍物线条
{
	
	{{1, 20}, 			{319, 20}},
	{{1, 20}, 			{1, 239}},
	{{1, 239}, 		{319, 239}},
	{{319, 239}, 	{319, 20}},
	{{0, 0}, 			{0, 0}},
	{{0, 0 }, {0 , 0}}

};

int LineIndex = 5;

bool IsGameStart = 0;				//游戏是否开始

double 	CurrentAngle = 0;	//当前球前进的角度
double	CurrentSpeed = 1;	//当前的速度(只每更新一次球的位移)

double CurrentPosition_x = 160;	//球的当前位置x
double CurrentPosition_y = 120;	//y

bool IsBallStuck = 0;
S32 	Radius = 10;									//球的半径

void BtnClickHandler_ball(BUTTON*);
void BtnHoldHandler_ball(POINT *p, BUTTON*);
void BtnReleaseHandler_ball(BUTTON*);

void BtnReleaseHandler_ready(BUTTON *pb);

U32 Speed = 2000;
/*
	根据当前的角度值更新球的位置
*/
void update_ball_position()
{
	static bool screenState = 0;
	if(IsBallStuck)
	{
		if(screenState == 0)
			LCD_printf(200, 0, "stucked!");
		screenState = 1;
		return;
	}
	else
	{
		if(screenState == 1)
		LCD_printf(200, 0, "OK      ");
		screenState = 0;
	}
		
	
	delay(Speed);
	
	LCD_draw_empty_circle(CurrentPosition_x, CurrentPosition_y, Radius, ScreenState.backgroundColor);

	CurrentPosition_x += cos(CurrentAngle/360 * 2 * PI) * CurrentSpeed;
	CurrentPosition_y -= sin(CurrentAngle/360 * 2 * PI) * CurrentSpeed;

	LCD_draw_empty_circle(CurrentPosition_x, CurrentPosition_y, Radius, BALL_COLOR);
}

double ads(double d)
{
	return d > 0 ? d : -1 * d;
}

LINE* Ball_line_init(LINE* pLine)
{
	double x1 = pLine->p1.x;
	double x2 = pLine->p2.x;
	double y1 = pLine->p1.y;
	double y2 = pLine->p2.y;
	
	LCD_draw_line(x1,y1,x2,y2, BALL_COLOR);
	
	//初始化直线角度
	if(x1 == x2)
		pLine->angle = 90;
	else
	{
		if((x1 - x2) * (y1 - y2) > 0)
		{
			pLine->angle = 180 - atan((y2-y1)/(x2 - x1))/(2*PI) * 360;
		}
		else if((x1 - x2) * (y1 - y2) < 0)
		{
			pLine->angle =  -1 * atan((y2-y1)/(x2 - x1))/(2*PI) * 360;
		}
		if(pLine->angle < 0)
				pLine->angle += 180;
	}
	
	//初始化直线方程系数
	if(x1 == x2)	//垂直x轴
	{
		pLine->A = 1;
		pLine->C = -1 * x1;
		pLine->B = 0;
	}
	else if(y1 == y2)	//平行x轴
	{
		pLine->A = 0;
		pLine->C = -1 * y1;;
		pLine->B = 1;
	}
	else
	{
		pLine->A = 1/(x2 - x1);
		pLine->B = 1/(y1 - y2);
		pLine->C = x1/(x1-x2) + y1/(y2-y1);
	}
	return pLine;
}

void Ball_lines_init()
{
	int index;
	for(index = 0; index < LineIndex; index ++)
		Ball_line_init(Lines + index);
}

/*
	获取反射角度数
	参数:	inAngle  入射角度数
				barAngle 障碍物角度
*/
double Ball_collide_angle(double inAngle, double barAngle)
{
	inAngle = (inAngle < 180) ? (inAngle + 180) : (inAngle - 180);		//将别人的射出角，变为自己的射入角
	//输入
	//LCD_printf(0,  0, "IN:%f, Bar:%f", inAngle, barAngle);
	return ((2 * barAngle - inAngle) > 180) ? (2 * barAngle - inAngle -180) : (2 * barAngle - inAngle) +  180;
}


bool Ball_is_amount_two_point(POINT p1, POINT p2)
{
	int maxX = p1.x > p2.x ? p1.x : p2.x;
	int minX = p1.x > p2.x ? p2.x : p1.x;
	int maxY = p1.y > p2.y ? p1.y : p2.y;
	int minY = p1.y > p2.y ? p2.y : p1.y;
	int curX = (int)CurrentPosition_x;
	int curY = (int)CurrentPosition_y;
	if(minX >= maxX - 20 || minX == maxX)	//如果差不多是一条横线，则只比较y
	{
		return (curY < maxY && curY > minY);
	}
	
	if(minY >= maxY - 20 || minY == maxY)
	{
		return (curX < maxX && curX > minX);
	}
	
	return (curX < maxX && curX > minX) && (curY < maxY && curY > minY);
}

LINE* Ball_is_collide()
{
	int index;

	for(index = 0; index < LineIndex; index ++)
	{
		double dis = ads(Lines[index].A*CurrentPosition_x + Lines[index].B*CurrentPosition_y + Lines[index].C)/sqrt(Lines[index].A*Lines[index].A + Lines[index].B*Lines[index].B);
		
		if(dis <= Radius - 3 && Ball_is_amount_two_point(Lines[index].p1, Lines[index].p2))
		{
		
			IsBallStuck = 1;
			return 0;
		}
		else
		{
			IsBallStuck = 0;
		
		}
		
		if(dis <= Radius + 3 && Ball_is_amount_two_point(Lines[index].p1, Lines[index].p2))
		{
			IsBallStuck = 0;
			return Lines + index;
		}
	}
	
	return null;
}

BUTTON* pBallScreen;
BUTTON* pReady;

void Ball_init()
{
		pBallScreen = BUTTON_create_button(SCREEN_SIZE_X, SCREEN_SIZE_Y, 
										RGB_262K_BLACK,
										" ",
										RGB_262K_BLACK,
										BtnClickHandler_ball,
										BtnHoldHandler_ball,
										BtnReleaseHandler_ball);
	pReady = BUTTON_create_button(1, 1, 
										RGB_262K_RED,
										"Ready?",
										RGB_262K_BLACK,
										null,
										null,
										BtnReleaseHandler_ready);
	BUTTON_draw_button(SCREEN_SIZE_X * 2 /3 , SCREEN_SIZE_Y/2, pReady);
	
	
}

void Ball_main()
{
	U32 scores = 0;
	bool pre_is_leave = 1;
	LINE* lt;
	LCD_clear_screen(ScreenState.backgroundColor);
	Ball_init();

	update_ball_position();
	while(IsGameStart == 0);
	BUTTON_delete_button(pReady);
	BUTTON_draw_button(0, 0, pBallScreen);
	LCD_printf(0, 0, "Your score:");
	Ball_lines_init();
	while(1)
	{
		LCD_printf(FONT_WIDTH('Y') * 10, 0, "%3d", scores);
		
		update_ball_position();
		if(null != (lt = Ball_is_collide()) && pre_is_leave)
		{
				pre_is_leave = 0;		
				CurrentAngle = Ball_collide_angle(CurrentAngle, lt->angle);
				if(Speed > 50)
					Speed -= 50;
				if((lt - Lines) >= 4)
					scores ++;
				else
					scores --;
		}
		else
		{
			pre_is_leave = 1;
		}
	}
}


S32 startX = -1;
S32 startY = -1;
S32 curX;
S32 curY;
U8 UserLineIndex = 4;
void BtnClickHandler_ball(BUTTON* pb)
{
	
}
void BtnHoldHandler_ball(POINT *p, BUTTON* pb)
{
	if(startX == -1 || startY == -1)
	{
		startX = p->x;
		startY = p->y;
	}
	curX = p->x;
	curY = p->y;
}

void BtnReleaseHandler_ball(BUTTON* pb)
{
	UserLineIndex = (UserLineIndex == 4) ? 5 : 4;
	LCD_draw_line(Lines[UserLineIndex].p1.x, Lines[UserLineIndex].p1.y, Lines[UserLineIndex].p2.x, Lines[UserLineIndex].p2.y, ScreenState.backgroundColor);
	Lines[UserLineIndex].p1.x = curX;
	Lines[UserLineIndex].p1.y = curY;
	Lines[UserLineIndex].p2.x = startX;
	Lines[UserLineIndex].p2.y = startY;
	Ball_line_init(Lines + UserLineIndex);
	startX = -1;
	startY = -1;
	LineIndex = 6;
}


void BtnReleaseHandler_ready(BUTTON *pb)
{
	IsGameStart = 1;
}



