


#ifndef __Q_RTC
#define __Q_RTC

#include "com.h"
/*
	设置系统时间
	参数hour, min ,sec,你懂得
*/
void RTC_set_syetem_time(int hour, int min, int sec);	

/*
	RTC被配置成每秒产生一个中断的模式,并且它的起始值从0开始还是从之前的计数开始取决于参数
*/
void RTC_init_per_1_second(U8 new_or_old);		//1, 0


/*
	RTC被配置成每per_ms毫秒产生一个中断的模式,
	并且它的起始值从0开始还是从之前的计数开始取决于参数
*/
void RTC_init(U32 per_ms, U8 new_or_old);
#endif
