


#ifndef __Q_RTC
#define __Q_RTC

#include "com.h"
/*
	����ϵͳʱ��
	����hour, min ,sec,�㶮��
*/
void RTC_set_syetem_time(int hour, int min, int sec);	

/*
	RTC�����ó�ÿ�����һ���жϵ�ģʽ,����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/
void RTC_init_per_1_second(U8 new_or_old);		//1, 0


/*
	RTC�����ó�ÿper_ms�������һ���жϵ�ģʽ,
	����������ʼֵ��0��ʼ���Ǵ�֮ǰ�ļ�����ʼȡ���ڲ���
*/
void RTC_init(U32 per_ms, U8 new_or_old);
#endif
