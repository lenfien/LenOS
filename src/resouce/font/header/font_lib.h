
#ifndef __FONT_LIB
#define __FONT_LIB


#include "font_operation.h"
#include "com.h"

//���������Ե��ֿ�ı�ʶ��Ϣ


/*
	ASCII 8*16
*/
extern const unsigned char ansi_font8x16[][16];       	//�ṩ�Կ�ĵײ�ķ���(������)
extern FONT_LIB ansi_font8x16_inf;                      //�ṩ�Կ���޸�Ȩ(������)

PFONT FONT_interface_ascii_8x16_get_font(char c);		//�ÿ������ṩ�ķŷ������ڲ����ݵ�ͨ��
const FONT_LIB* FONT_interface_ascii_8x16_get_lib(void);	//�ṩ�������������Ϣ��ͨ��(����粻�ɸı�֮)


/*
	ASCII 10*19
*/
extern  const unsigned char ansi_font10x19[][38];

PFONT FONT_interface_ascii_10x19_get_font(char c);
const FONT_LIB* FONT_interface_ascii_10x19_get_lib(void);


//�ɱ������壬YAHEI

PFONT FONT_interface_ascii_YAHEI_get_font(char c);
const FONT_LIB* FONT_interface_ascii_YAHEI_get_lib(void);


#endif
