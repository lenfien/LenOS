

#ifndef __GRAPHIC
#define __GRAPHIC

//************************************绘图相关_开始************************************//


void LCD_draw_point(U16 x, U16 y, U32 RGB_color);					//绘点

U32 LCD_get_point(U16 x, U16 y);		//获得x,y点处的颜色

void LCD_draw_rectangle(U16 oX, U16 oY, U16 eX, U16 eY, U32 color);	//绘制矩形

void LCD_draw_line(int x, int y, int _x, int _y, U32 color);  //从xy点出发，到_x_y点画一条直线，颜色由color指定
void LCD_draw_lines(POINT *p, U32 pointNum, U32 color);				
void LCD_draw_circle(S32 cX, S32 cY, S32 cR, U32 color);

void LCD_draw_empty_rectangle(U32 xStart, U32 yStart, U32 width, U32 high, U32 color);//画一个空心矩形
void LCD_draw_empty_circle(S32 cX, S32 cY, S32 cR, U32 color);
//**************************************绘图相关_结束*******************************//

#endif
