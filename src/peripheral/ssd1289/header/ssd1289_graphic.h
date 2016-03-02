

#ifndef __GRAPHIC
#define __GRAPHIC

//************************************��ͼ���_��ʼ************************************//


void LCD_draw_point(U16 x, U16 y, U32 RGB_color);					//���

U32 LCD_get_point(U16 x, U16 y);		//���x,y�㴦����ɫ

void LCD_draw_rectangle(U16 oX, U16 oY, U16 eX, U16 eY, U32 color);	//���ƾ���

void LCD_draw_line(int x, int y, int _x, int _y, U32 color);  //��xy���������_x_y�㻭һ��ֱ�ߣ���ɫ��colorָ��
void LCD_draw_lines(POINT *p, U32 pointNum, U32 color);				
void LCD_draw_circle(S32 cX, S32 cY, S32 cR, U32 color);

void LCD_draw_empty_rectangle(U32 xStart, U32 yStart, U32 width, U32 high, U32 color);//��һ�����ľ���
void LCD_draw_empty_circle(S32 cX, S32 cY, S32 cR, U32 color);
//**************************************��ͼ���_����*******************************//

#endif
