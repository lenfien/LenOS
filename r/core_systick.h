

#ifndef __SYSTICK
#define __SYSTICK


#include "com.h"


//ֵ��ַ
#define __SYSTICK_CSR		0xE000E010	//Systick���Ƽ�״̬�Ĵ���
#define __SYSTICK_RLR		0xE000E014	//systick��װ����ֵ�Ĵ���
#define __SYSTICK_CUR		0xE000E018	//Systick��ǰ��ֵ�Ĵ���
#define __SYSTICK_CAR		0xE000E01C	//SystickУ׼��ֵ�Ĵ���

//��ַ
#define _SYSTICK_CSR		ADR(__SYSTICK_CSR)	//Systick���Ƽ�״̬�Ĵ���
#define _SYSTICK_RLR		ADR(__SYSTICK_RLR)	//systick��װ����ֵ�Ĵ���
#define _SYSTICK_CUR		ADR(__SYSTICK_CUR)	//Systick��ǰ��ֵ�Ĵ���
#define _SYSTICK_CAR		ADR(__SYSTICK_CAR)	//SystickУ׼��ֵ�Ĵ���


//ֵ
#define SYSTICK_CSR			VAL(__SYSTICK_CSR)	//Systick���Ƽ�״̬�Ĵ���
#define SYSTICK_RLR			VAL(__SYSTICK_RLR)	//systick��װ����ֵ�Ĵ���
#define SYSTICK_CUR			VAL(__SYSTICK_CUR)	//Systick��ǰ��ֵ�Ĵ���
#define SYSTICK_CAR			VAL(__SYSTICK_CAR)	//SystickУ׼��ֵ�Ĵ���





/********************SYSTICK_CSR _ Systick���Ƽ�״̬�Ĵ���**************/

/*
Bit 16:
CONTFLAG:
�������ļ���״̬
ֻ��
0:	���ζ�ȡǰ��������ֵû�дﵽ0;
1:	���ζ�ȡǰ��������ֵ�ﵽ��0��
����:ͨ����ȡ��λ���Զ���0
*/
U8 SYSTICK_get_CONTFLAG(void);

#define SYSTICK_get_count_flag()	SYSTICK_get_CONTFLAG()


/*
Bit 2: CLKSOURCE:
Systick��ʱ��Դ����:
0: �ⲿʱ��Դ STCLK
1: �ں�ʱ�� FCLK
*/
void SYSTICK_set_CLKSOURCE(U8 s_f);

#define SYSTICK_set_clock_source(s_f)	SYSTICK_set_CLKSOURCE(s_f)

#define SYSTICK_set_clock_source_is_STCLK()	SYSTICK_set_CLKSOURCE(0)
#define SYSTICK_set_clock_source_is_FCLK()	SYSTICK_set_CLKSOURCE(1)
	
U8 SYSTICK_get_CLKSOURCE(void);

#define SYSTICK_get_clock_source()	SYSTICK_get_CLKSOURCE()

/*
Bit 1: TICKINT:
��������������0ʱ���Ƿ����SysTick�쳣
1: 	Systick��������1ʱ����Systick�쳣����
0:	����������
*/
void SYSTICK_set_TICKINT(U8 e_d);

#define SYSTICK_enable_interrupt()	SYSTICK_set_TICKINT(1)
#define SYSTICK_disable_interrupt()	SYSTICK_set_TICKINT(0)


/*
Bit 0: ENABLE
Systickʹ��λ
1: 	ʹ��Systick
0:	����Systick
*/
void SYSTICK_set_ENABLE(U8 e_d);

#define SYSTICK_enable_systick()	SYSTICK_set_ENABLE(1)
#define SYSTICK_disable_systick()	SYSTICK_set_ENABLE(0)


/***************************SYSTICK_RLR(systick��װ����ֵ�Ĵ���)**************/
/*
Bit [23:0]:RELOAD
��������������0ʱ����װ�ص�ֵ
*/
void SYSTICK_set_RELOAD(U32 re);
U32 SYSTICK_get_RELOAD(void);

#define SYSTICK_set_reload(re)	SYSTICK_set_RELOAD(re)
#define SYSTICK_get_reload()	SYSTICK_get_RELOAD()


/***************************SYSTICK_CUR(Systick��ǰ��ֵ�Ĵ���)***************/
/*
Bit [23:0]: CURRENT
��������ǰ��ֵ
*/
void SYSTICK_set_CURRENT(U32 cu);
U32 SYSTICK_get_CURRENT(void);

#define SYSTICK_set_counter(cu)		SYSTICK_set_CURRENT(cu)
#define SYSTICK_get_counter()		SYSTICK_get_CURRENT()

/***************************SYSTICK_CAR(SystickУ׼��ֵ�Ĵ���)**************/
/*
Bit 31: NOREFֻ��
�Ƿ��ⲿ�ο�ʱ�ӿ���
1:  �ⲿ�ο�ʱ�Ӳ����� 
0�� �ⲿ�ο�ʱ�ӿ���
*/
U8	SYSTICK_get_NOREF(void);

#define SYSTICK_is_reference_clock_available() (!SYSTICK_get_NOREF())


/*
Bit 30: SKEW:ֻ��
У׼ֵ�Ƿ�Ϊ��ȷ��10MS
1:	У׼ֵ���Ǿ�ȷ��10MS
0:	У׼ֵ�Ǿ�ȷ��10MS
*/
U8 SYSTICK_get_SKEW(void);

#define SYSTICK_is_calibration_value_precision()	(!(SYSTICK_get_SKEW()))


/*
Bit [23:0] TENMS:ֻ��
10MS����ʱ�ĸ���
0: �޷�ʹ��У׼����
*/
U32 SYSTICK_get_TENMS(void);

#define SYSTICK_get_10MS_calibration_value()	SYSTICK_get_TENMS()

#endif
