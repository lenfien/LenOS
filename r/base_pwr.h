

/*
	Ϊ�˶�RTC��ʱ��Դ�������ã���ʱʹ��PWRģ���PWR_CR�Ĵ����е�DBPλ�������Ƿ���Զ�д���������ò�����ʱ�����հס�����
*/


#ifndef __PWR
#define __PWR
#include "core_map.h"
#include "com.h"

#define __PWR_CR	(PWR_BASE + 0x00000000)


#define _PWR_CR		ADR(__PWR_CR)


#define PWR_CR		VAL(__PWR_CR)	



//*******************************PWR_CR**************************************//
/*
	DBP��ȡ���������д����  Domain Backup Protected
	λ 8 
	�ڸ�λ��RTC�ͺ󱸼Ĵ������ڱ�����״̬�Է�����д�롣������λ����д����Щ�Ĵ����� 
	0����ֹд��RTC�ͺ󱸼Ĵ��� 
	1������д��RTC�ͺ󱸼Ĵ��� 
	ע�����RTC��ʱ����HSE/128����λ���뱣��Ϊ��1����
*/
void PWR_set_DBP(U8 allow_forbid);

#define PWR_disable_domain_backup_protection() 	PWR_set_DBP(1)
#define PWR_enable_domain_backup_protection()	PWR_set_DBP(0)

#endif
