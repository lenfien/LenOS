

#ifndef __SSD1289_CONFIGURE
#define __SSD1289_CONFIGURE

//********************************显示设置相关_结束***************************************//

int LCD_set_lineSpacing(int lineSpacing);			//行距设置

int LCD_set_rowSpacing(int rowSpacing);     		//列距离相关

U32 LCD_set_font_color(U32 color);               	//前景色

U32 LCD_set_font_backColor(U32 backColor);       	//文字背景色

FONT_TYPE LCD_set_font(FONT_TYPE newFont);  		//设置字体

//********************************显示设置相关_结束****************************************//


#endif

