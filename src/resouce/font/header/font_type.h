


#ifndef __FONT_TYPE
#define __FONT_TYPE

#include "com.h"
typedef enum
{
	FONT_ASCII_8x16,
	FONT_ASCII_10x19,
	FONT_ASCII_YAHEI,
	//�����
	FONT_Other
}FONT_TYPE;


//�������ݶ���
typedef enum
{
	ALIGN_LEFT,
	ALIGN_RIGH
}FONT_ALIGN;

typedef enum
{
	WIDTH_VARIABLE,			//�ַ���Ϊ�ɱ������
	WIDTH_FIXED     		//�ַ���Ϊ�̶��������
}WIDTH_TYPE;


//�ַ�����Ϣ
typedef struct
{
	WIDTH_TYPE widthType;   		//�ַ����Ƿ�Ϊ�ɱ���ַ���
	U32  fontWidth;         		//����ǿɱ�����壬����������
	U32  fontHigh;							//�ַ��߶�
	FONT_ALIGN align;       		//���ݵĶ���ģʽ
}FONT_LIB;

typedef FONT_LIB* PFONT_LIB;

//������Ϣ����
typedef struct
{
	FONT_LIB* pLib;					//ָ������������ַ�����Ϣ��ָ��
	U32 fontWidth;
	U32 fontHigh;
	const unsigned char *pChar;     //ָ���ַ�������Ϣ��ָ��
}FONT;

typedef FONT* PFONT;

typedef struct
{
	U32 fontWidth;
	U32 fontHigh;
}FONT_SIZE;


#endif

