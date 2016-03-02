


#ifndef __FONT_OPERATION
#define __FONT_OPERATION

#include "com.h"
#include "font_type.h"

 //************���Ͷ��岿��


//************���ܶ��岿��***********//
/*
	�����ֿ���Ϣ������c��Ӧ���ֿ��е�������Ϣ
	��Ϊ���ڿɱ������
	��ͬ���ֿ⣬�����в�ͬ��������Ϣ
*/
PFONT FONT_get_font_info(char c, FONT_TYPE fontType);



//���ݿ�����(������FONT_LIB_TYPE��),�ҵ��ÿ����ϸ��Ϣ
const FONT_LIB* FONT_get_lib_info(FONT_TYPE fontLibType);


/*
	�����������һ������Ŀ��(���ڿɱ��������Ч)
	ֻ�������������ַ���������
	pFont:ָ���ַ����ݵ�ָ��
	charAmount: ÿһ��ռ�õ��ַ���
	fontHigh:	�ַ��ĸ߶�
*/
U32 FONT_get_width(const unsigned char *pFont, U32 charNumPerLine, U32 fontHigh);


//���һ���ַ����п����ַ��Ŀ�ȣ������ȣ�������strlen�Ŀ�ȣ�
U32 FONT_get_string_width(char *str, FONT_TYPE fontType);


//������������͵õ�һ���ַ��Ŀ��
U32 FONT_get_char_width(char c, FONT_TYPE fontType);


//�����ַ������ͻ��һ���ַ��ĸ߶�
U32 FONT_get_char_high(char c, FONT_TYPE fontType);


/*
�������ܺ�LCD_printfһ������������к����ǰ����ֵĿ�Ⱥ͸߶����ֵ�
line >= 0
cur >= 0
*/


int FONT_printf(U16 x, U16 y, char* format, ...);

PFONT FONT_interface_ascii_8x16_get_font(char c);

#endif
