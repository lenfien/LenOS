
#ifndef __BASE_BKP
#define __BASE_BKP

#include "core_map.h"
#include "com.h"

#define __BKP_DRx(x)	(BKP_BASE + ((x <= 10) ? (0x04 * x) : (0x40 + (x - 11) * 0x04))) 
#define __BKP_RTCCR		(BKP_BASE + 0x2C)
#define __BKP_CR		(BKP_BASE + 0x30)
#define __BKP_CSR		(BKP_BASE + 0x34)

#define _BKP_DRx(x)		ADR(__BKP_DRx(x))	
#define _BKP_RTCCR		ADR(__BKP_RTCCR)		
#define _BKP_CR			ADR(__BKP_CR)
#define _BKP_CSR		ADR(__BKP_CSR)		

#define BKP_DRx(x)		VAL(__BKP_DRx(x))	
#define BKP_RTCCR		VAL(__BKP_RTCCR)		
#define BKP_CR			VAL(__BKP_CR)
#define BKP_CSR		VAL(__BKP_CSR)		





//********************************************************//
//*****Backup data register x (BKP_DRx) (x = 1 ..42)******//
//********************************************************//

/*
After reset, access to the Backup registers and RTC is disabled and the Backup domain 
(BKP) is protected against possible parasitic write access. To enable access to the Backup 
registers and the RTC, proceed as follows:
��enable the power and backup interface clocks by setting the PWREN and BKPEN bits 
in the RCC_APB1ENR register
��set the DBP bit the Power Control Register (PWR_CR) to enable access to the Backup 
registers and RTC.
//����:
�ڸ�λ֮�󣬶Ժ���Ĵ�����RTC�ķ����ǽ�ֹ�ģ����򱻱����Է�ֹ�Ժ��������д���������԰���
������ʹ�ܺ���Ĵ����ķ���:
1:ͨ������RCC_APB1ENR�Ĵ�����PWRENλ��BKPENλ��ʹ�ܵ�Դ�ͱ�����ӿ�ʱ�ӡ�
2:����PWR_CR�Ĵ����е�DBPλ����ֹ�Ժ���ı�����
*/

/*
Backup data register x (BKP_DRx) (x = 1 ..42)
Address offset: 0x04 to 0x28, 0x40 to 0xBC
Reset value: 0x0000 0000
*/
/*
Bits 15:0 D[15:0] Backup data
These bits can be written with user data. 
Note: The BKP_DRx registers are not reset by a System reset or Power reset or when the 
device wakes up from Standby mode.
They are reset by a Backup Domain reset or by a TAMPER pin event (if the TAMPER 
pin function is activated).
*/

void BKP_set_DRx(U16 data, U8 x);

//���ñ�����Ĵ������Ϊx�ļĴ�����ֵ
//x = 1 - 42
#define BKP_set_data(data, x)	BKP_set_DRx(data, x)

U16 BKP_get_DRx(U8 x);

//��ȡ������Ĵ������Ϊx�ļĴ�����ֵ
//x = 1 - 42
#define BKP_get_data(x)		BKP_get_DRx(x)

//********************************************************//
//********RTC clock calibration register (BKP_RTCCR)******//
//********************************************************//

/*
RTC clock calibration register (BKP_RTCCR)
Address offset: 0x2C
Reset value: 0x0000 0000
*/

/*
Bits 15:10 Reserved, always read as 0.
*/

/*
��TAMPER�������RTC�������廹����������(ÿ����һ�������¼����һ��)
Bit 9 ASOS: Alarm or second output selection
When the ASOE bit is set, the ASOS bit can be used to select whether the signal output on 
the TAMPER pin is the RTC Second pulse signal or the Alarm pulse signal:
0: RTC Alarm pulse output selected
1: RTC Second pulse output selected
Note: This bit is reset only by a Backup domain reset.
*/
void BKP_set_ASOS(U8 s);

#define BKP_set_tamper_pin_output_alarm()	BKP_set_ASOS(0)	//TAMPER���������������
#define BKP_set_tamper_pin_output_second()	BKP_set_ASOS(1)	//TAMPER�������������

/*
RTC alarm �� second�¼��������ʹ��
	�����廹�����ʱ�������ѡ����Ϻ���
Bit 8 ASOE: Alarm or second output enable
Setting this bit outputs either the RTC Alarm pulse signal or the Second pulse signal on the 
TAMPER pin depending on the ASOS bit.
The output pulse duration is one RTC clock period. The TAMPER pin must not be enabled 
while the ASOE bit is set.
Note: This bit is reset only by a Backup domain reset.
*/
void BKP_set_ASOE(U8 e_d);

//ʹ��TAMPER�����������������������
#define BKP_enable_tamper_output()	BKP_set_ASOE(1)	

//��ֹTAMPER�����������������������
#define BKP_disable_tamper_output()	BKP_set_ASOE(0)


/*
RTCʱ��(64��Ƶ��)�ڲ����䵽TAMPER���Ų����(���ⲿУ׼RTC������)
Bit 7 CCO: Calibration clock output 
0: No effect
1: Setting this bit outputs the RTC clock with a frequency divided by 64 on the TAMPER pin. 
The TAMPER pin must not be enabled while the CCO bit is set in order to avoid unwanted 
Tamper detection.
Note: This bit is reset when the VDD supply is powered off.
*/
void BKP_set_CCO(U8 e_d);

#define BKP_enable_rtc_clock_calibration()	BKP_set_CCO(1)
#define BKP_disable_rtc_clock_calibration()	BKP_set_CCO(0)


/*
���ȵ���
ÿ2^20��RTCʱ�Ӻ��Ե�CAL�����������ԴﵽУ׼RTCʱ�ӵ�Ŀ��
Bit 6:0 CAL[6:0]: Calibration value
This value indicates the number of clock pulses that will be ignored every 2^20 clock pulses. 
This allows the calibration of the RTC, slowing down the clock by steps of 1000000/2^20 
PPM. 
The clock of the RTC can be slowed down from 0 to 121PPM.
*/
void BKP_set_CAL(U8 c);

//����RTCʱ�ӵ�У׼��(�ο�λ��˵��)
#define BKP_set_rtc_calibration_value(c)	BKP_set_CAL(c)

U8 BKP_get_CAL(void);
//��ȡRTCʱ�ӵ�У׼��(�ο�λ��˵��)
#define BKP_get_rtc_calibration_value()		BKP_get_CAL()


//***********************************************************//
//***********Backup control register (BKP_CR)****************//
//***********************************************************//
/*
Backup control register (BKP_CR) 
Address offset: 0x30
Reset value: 0x0000 0000
*/

/*
Bits 15:2 Reserved, always read as 0.
*/
/*
TAMPER����źż���ѡ��
��⵽һ��TAMPER�źŻᵼ�±�����λһ��
��������жϣ�������жϣ�����ֻ�ἤ���¼�(�����¼�λ)
Bit 1 TPAL: TAMPER pin active level
0: A high level on the TAMPER pin resets all data backup registers (if TPE bit is set).
1: A low level on the TAMPER pin resets all data backup registers (if TPE bit is set).
*/
void BKP_set_TPAL(U8 s);

//��TAMPER���ŵ���������Ϊ�ߵ�ƽ����TAMPER�¼�
#define BKP_set_tamper_polarity_high()	BKP_set_TPAL(0)
//��TAMPER���ŵ���������Ϊ�͵�ƽ����TAMPER�¼�
#define BKP_set_tamper_polarity_low()	BKP_set_TPAL(1)

/*
ʹ��TAMPER���� 
Bit 0 TPE: TAMPER pin enable
0: The TAMPER pin is free for general purpose I/O
1: Tamper alternate I/O function is activated.
*/
void BKP_set_TAMPER(U8 e_d);

//ʹ��TAMPER����
#define BKP_enable_tamper()		BKP_set_TAMPER(1)
//����TAMPER����
#define BKP_disable_tamper()	BKP_set_TAMPER(0)

/*
Note:
Setting the TPAL and TPE bits at the same time is always safe, however resetting both at 
the same time can generate a spurious Tamper event. For this reason it is recommended to 
change the TPAL bit only when the TPE bit is reset.
*/

//**********************************************************//
//*********Backup control/status register (BKP_CSR)*********//
//**********************************************************//


/*
Backup control/status register (BKP_CSR) 
Address offset: 0x34
Reset value: 0x0000 0000
*/

/*
Bits 15:10 Reserved, always read as 0.
*/

/*
������Tamper�ж�ʱ��λ����־
Bit 9 TIF: Tamper interrupt flag 
This bit is set by hardware when a Tamper event is detected and the TPIE bit is set. It is 
cleared by writing 1 to the CTI bit (also clears the interrupt). It is also cleared if the TPIE bit is 
reset. 
0: No Tamper interrupt
1: A Tamper interrupt occurred
Note: This bit is reset only by a system reset and wakeup from Standby mode.
*/
U8 BKP_get_TIF(void);

#define BKP_get_tamper_interrupt_flag()	BKP_get_TIF()
#define BKP_is_interrupted_by_tamper()	BKP_get_TIF()	

/*
������Tamper�¼�ʱ��λ����־
Bit 8 TEF: Tamper event flag 
This bit is set by hardware when a Tamper event is detected. It is cleared by writing 1 to the 
CTE bit.
0: No Tamper event
1: A Tamper event occurred
Note: A Tamper event resets all the BKP_DRx registers. They are held in reset as long as the 
TEF bit is set. If a write to the BKP_DRx registers is performed while this bit is set, the 
value will not be stored.
*/
U8 BKP_get_TEF(void);

#define BKP_get_tamper_event_flag()		BKP_get_TEF()
#define BKP_is_tamper_event_occured()	BKP_get_TEF()

/*
Bits 7:3 Reserved, always read as 0.
*/

/*
ʹ��Tamper�¼������ж�
Bit 2 TPIE: TAMPER pin interrupt enable
0: Tamper interrupt disabled
1: Tamper interrupt enabled (the TPE bit must also be set in the BKP_CR register
Note: 
1: A Tamper interrupt does not wake up the core from low-power modes.
2: This bit is reset only by a system reset and wakeup from Standby mode.
*/
void BKP_set_TPIE(U8 e_d);

#define BKP_enable_interrupt_at_tamper()	BKP_set_TPIE(1)	
#define BKP_disable_interrupt_at_tamper()	BKP_set_TPIE(0)

/*
Bit 1 CTI: Clear tamper interrupt
This bit is write only, and is always read as 0.
0: No effect
1: Clear the Tamper interrupt and the TIF Tamper interrupt flag. 
*/
void BKP_set_CTI(void);

#define BKP_clear_tamper_interrupt_flag()	BKP_set_CTI()

/*
Bit 0 CTE: Clear tamper event
This bit is write only, and is always read as 0.
0: No effect
1: Reset the TEF Tamper event flag (and the Tamper detector) 
*/
void BKP_set_CTE(void);

#define BKP_clear_tamper_event_interrupt_flag()	BKP_set_CTE()


#endif
