

#ifndef __ADCONVERTER
#define __ADCONVERTER

#include "com.h"
void ADConverter_init(void);
 
int ADConverter_record_ADValue(U32);
 
 
void ADConverter_update_UI(void);

//获得平均电压
float ADConverter_get_voltage(void);

/*
	根据第n个点测周期
	n为采样点中的一个
*/
int ADConverter_record_data(U32 adResult);

//获得周期us

int  ADConverter_get_cycle(void);

void ADConverter_draw_UI(void);

void ADConverter_adjust_para(void);

U16 ADConverter_AD2COR(U16 adV);

#endif
