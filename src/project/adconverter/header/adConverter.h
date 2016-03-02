

#ifndef __ADCONVERTER
#define __ADCONVERTER

#include "com.h"
void ADConverter_init(void);
 
int ADConverter_record_ADValue(U32);
 
 
void ADConverter_update_UI(void);

//���ƽ����ѹ
float ADConverter_get_voltage(void);

/*
	���ݵ�n���������
	nΪ�������е�һ��
*/
int ADConverter_record_data(U32 adResult);

//�������us

int  ADConverter_get_cycle(void);

void ADConverter_draw_UI(void);

void ADConverter_adjust_para(void);

U16 ADConverter_AD2COR(U16 adV);

#endif
