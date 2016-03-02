



#ifndef __SSD1289_FONT
#define __SSD1289_FONT

#include "ssd1289_type.h"

extern LCD_FONT_FORMAT FontFormat;

#define FONT_HIGH					FONT_get_char_high('C', FontFormat.fontType)	//���һ����ǰ����������ֵĸ߶�
#define FONT_WIDTH(c)			FONT_get_char_width(c, FontFormat.fontType)		//��ÿ��
#define FONTS_WIDTH(str)	FONT_get_string_width(str, FontFormat.fontType)	//���һ���ַ����Ŀ��

//************************************�������_��ʼ************************************//					  
/*
����fontType���������������x,y����ʾ����ַ�c
	��ʾ�ַ�
	�����ʾ������ᳬ����Ļ�߽� ����ʾ ������0
	����ֵ:
		-2:	��ʾʧ��,xԽ��
		-3: ��ʾʧ��,yԽ��
		-1: ��ʾ�ɹ�
		c:	��ʾ�ɹ���ת���ַ�
*/
S8	LCD_print_char(S16 x, S16 y, char c, FONT_TYPE fontType);


/*
	���һ���ַ���(�ɰ����κ�ת���ַ�)
	ֻ֧��ANCI��
*/

void LCD_print_string(U16 xStart, U16 yStart, char *str, FONT_TYPE fontLibType);

/*
	ʹ��Ĭ�ϵ��ֿ�
	printf�÷�һ������ֻ֧��ANCI�ַ���
*/
int LCD_printf(U16 x, U16 y, char *format, ...);

//********************************************//
//**********��DOS��ʽ�������*****************//
//��һ�ε��õ�ʱ��, ������Ļ�����Ͻǿ�ʼһ��,
//�ڶ��ε��û�����һ����ʾ����һ����ʾ,�����Ļ
//���˻��Զ�����
//********************************************/
int CMD_printf(const char *format, ...);


//�����һ�ε���ʾ���Ϊ����ɫ
void LCD_clear_pre_print(void);


//************************************�������_����************************************//

#endif

