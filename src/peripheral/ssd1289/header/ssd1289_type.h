
#ifndef __LCD_TYPE_SSD1289
#define __LCD_TYPE_SSD1289

#include "com.h"
#include "font_operation.h"


typedef struct
{
	int x;
	int y;
}POINT;


typedef struct
{
	S32 lineSpacing;   	//�о�
	S32 rowSpacing;    	//�о�
	U32 color;     			//������ɫ
	U32 backColor;     	//������ɫ
	FONT_TYPE fontType;
}LCD_FONT_FORMAT;


//RGB ��ɫֵ����
typedef struct
{
	U8 R;
	U8 G;
	U8 B;
}RGB_COLOR;


//LCD SSD1289��Ļ������
typedef enum
{
	ORITATION_320_240,     //320 * 240�����Ӷ��ӳ����Լ�����Ļ�����Ͻ�Ϊ0, 0��
	ORITATION_240_320      //240 * 320 (���Ӵ��ڳ����Լ�����Ļ�����Ͻ�Ϊ0, 0��
}SSD1289_ORITATION;


//LCD SSd1289��ɫ����
typedef enum
{
	COLOR_65K,
	COLOR_262K
}SSD1289_COLOR;


//SSD1289 ��ʼ���ṹ��
typedef struct
{
	SSD1289_ORITATION oritation;          //��Ļ�ķ���
	SSD1289_COLOR			color;              //��ɫ����
	U32								backgroundColor;    //������ɫ
	U8								backLight;					//������״̬(1:�� 0:�ر�)
	U8 								isInit;
}SSD1289_INITIAL_STRUCT;


#endif
