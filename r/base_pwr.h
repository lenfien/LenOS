

/*
	为了对RTC的时钟源进行配置，暂时使用PWR模块的PWR_CR寄存器中的DBP位来控制是否可以读写备份区，该部分暂时基本空白。。。
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
	DBP：取消后备区域的写保护  Domain Backup Protected
	位 8 
	在复位后，RTC和后备寄存器处于被保护状态以防意外写入。设置这位允许写入这些寄存器。 
	0：禁止写入RTC和后备寄存器 
	1：允许写入RTC和后备寄存器 
	注：如果RTC的时钟是HSE/128，该位必须保持为’1’。
*/
void PWR_set_DBP(U8 allow_forbid);

#define PWR_disable_domain_backup_protection() 	PWR_set_DBP(1)
#define PWR_enable_domain_backup_protection()	PWR_set_DBP(0)

#endif
