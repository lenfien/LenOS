

#ifndef __SSD1289_CONFIGURE
#define __SSD1289_CONFIGURE

//********************************��ʾ�������_����***************************************//

int LCD_set_lineSpacing(int lineSpacing);			//�о�����

int LCD_set_rowSpacing(int rowSpacing);     		//�о������

U32 LCD_set_font_color(U32 color);               	//ǰ��ɫ

U32 LCD_set_font_backColor(U32 backColor);       	//���ֱ���ɫ

FONT_TYPE LCD_set_font(FONT_TYPE newFont);  		//��������

//********************************��ʾ�������_����****************************************//


#endif

