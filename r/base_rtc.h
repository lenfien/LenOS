
/*
	���ĵ�������stm32f103����RTC��ص����мĴ���������Щ�Ĵ�����صĲ�����
	����RTC����ԭ����ο�оƬ�ֲ�16.

		
	��������RTC_CRL�Ĵ����е�CNFλ��ʹRTC��������ģʽ�󣬲���д��RTC_PRL��
	RTC_CNT��RTC_ALR�Ĵ����� 
	���⣬��RTC�κμĴ�����д��������������ǰһ��д������������С�����ͨ����ѯ
	RTC_CR�Ĵ����е�RTOFF״̬λ���ж�RTC�Ĵ����Ƿ��ڸ����С�����RTOFF״̬λ�ǡ�1��
	ʱ���ſ���д��RTC�Ĵ�������

	���ͨ��APB1�ӿڷ���RTC��Ԥ��Ƶֵ��������ֵ������ֵ�����ǣ���صĿɶ��Ĵ���ֻ����
	RTC APB1ʱ�ӽ�������ͬ����RTCʱ�ӵ������ر����¡�RTC��־Ҳ����˵ġ� 
	����ζ�ţ����APB1�ӿ��������رգ��������������ڸո����¿���APB1֮�����ڵ�һ��
	���ڲ��Ĵ�������֮ǰ����APB1�϶�����RTC�Ĵ�����ֵ���ܱ��ƻ���(ͨ������0)��

Reading RTC registers
	The RTC core is completely independent from the RTC APB1 interface.
	Software accesses the RTC prescaler, counter and alarm values through the APB1 interface 
	but the associated readable registers are internally updated at each rising edge of the RTC 
	clock resynchronized by the RTC APB1 clock. This is also true for the RTC flags.
	This means that the first read to the RTC APB1 registers may be corrupted (generally read 
	as 0) if the APB1 interface has previously been disabled and the read occurs immediately 
	after the APB1 interface is enabled but before the first internal update of the registers. This 
	can occur if:
	��A system reset or power reset has occurred
	��The MCU has just woken up from Standby mode (see Section 4.3: Low-power modes)
	��The MCU has just woken up from Stop mode (see Section 4.3: Low-power modes)
	In all the above cases, the RTC core has been kept running while the APB1 interface was 
	disabled (reset, not clocked or unpowered).
	Consequently when reading the RTC registers, after having disabled the RTC APB1 
	interface, the software must first wait for the RSF bit (Register Synchronized Flag) in the 
	RTC_CRL register to be set by hardware. 
	Note that the RTC APB1 interface is not affected by WFI and WFE low-power modes.
	
	
Configuring RTC registers
	To write in the RTC_PRL(Ԥ��Ƶ��), RTC_CNT(������), RTC_ALR(����) registers, 
	the peripheral must enter 
	Configuration Mode. This is done by setting the CNF bit in the RTC_CRL register.
	In addition, writing to any RTC register is only enabled if the previous write operation is 
	finished. To enable the software to detect this situation, the RTOFF status bit is provided in 
	the RTC_CR register to indicate that an update of the registers is in progress. A new value 
	can be written to the RTC registers only when the RTOFF status bit value is ��1��.
	Configuration procedure:
	1.Poll RTOFF, wait until its value goes to ��1��
	2. Set the CNF bit to enter configuration mode
	3. Write to one or more RTC registers
	4. Clear the CNF bit to exit configuration mode
	5. Poll RTOFF, wait until its value goes to ��1�� to check the end of the write operation.
	The write operation only executes when the CNF bit is cleared; it takes at least three 
	RTCCLK cycles to complete.
*/

#ifndef __RTC
#define __RTC

#include "core_map.h"
#include "com.h"

#define __RTC_CRH	(RTC_BASE + 0x00000000)
#define __RTC_CRL	(RTC_BASE + 0x00000004)
#define __RTC_PRLH	(RTC_BASE + 0x00000008)
#define __RTC_PRLL	(RTC_BASE + 0x0000000C)
#define __RTC_DIVH	(RTC_BASE + 0x00000010)
#define __RTC_DIVL	(RTC_BASE + 0x00000014)
#define __RTC_CNTH	(RTC_BASE + 0x00000018)
#define __RTC_CNTL	(RTC_BASE + 0x0000001C)
#define __RTC_ALRH	(RTC_BASE + 0x00000020)
#define __RTC_ALRL	(RTC_BASE + 0x00000024)

#define _RTC_CRH	ADR(__RTC_CRH)	
#define _RTC_CRL	ADR(__RTC_CRL)	
#define _RTC_PRLH	ADR(__RTC_PRLH)	
#define _RTC_PRLL	ADR(__RTC_PRLL)	
#define _RTC_DIVH	ADR(__RTC_DIVH)	
#define _RTC_DIVL	ADR(__RTC_DIVL)	
#define _RTC_CNTH	ADR(__RTC_CNTH)
#define _RTC_CNTL	ADR(__RTC_CNTL)	
#define _RTC_ALRH	ADR(__RTC_ALRH)	
#define _RTC_ALRL	ADR(__RTC_ALRL)	

#define RTC_CRH		VAL(__RTC_CRH)	
#define RTC_CRL		VAL(__RTC_CRL)	
#define RTC_PRLH	VAL(__RTC_PRLH)	
#define RTC_PRLL	VAL(__RTC_PRLL)	
#define RTC_DIVH	VAL(__RTC_DIVH)	
#define RTC_DIVL	VAL(__RTC_DIVL)	
#define RTC_CNTH	VAL(__RTC_CNTH)
#define RTC_CNTL	VAL(__RTC_CNTL)	
#define RTC_ALRH	VAL(__RTC_ALRH)	
#define RTC_ALRL	VAL(__RTC_ALRL)


//*************************RTC_CRH***********************//
//ע��:�ԸüĴ�����д����Ҫ��TROFFλΪ1ʱ����λ������RTC_CRL�Ĵ�����
/*
	OWIE����������ж�λ (Overflow interrupt enable) 
	λ2 
	0������(������)����ж� 
	1����������ж�
*/
void RTC_set_OWIE(U8 enable_disable);

#define RTC_enable_interrupt_at_overflow()	RTC_set_OWIE(1)
#define RTC_disable_interrupt_at_overflow()	 RTC_set_OWIE(0)


/*
	ALRIE�����������ж� (Alarm interrupt enable) 
	λ1 
	0������(������)�����ж� 
	1�����������ж� 
*/
void RTC_set_ALRIE(U8 enable_disable);

#define RTC_enable_interrupt_at_alarm()		RTC_set_ALRIE(1)
#define RTC_disable_interrupt_at_alarm()	RTC_set_ALRIE(0)

/*
	SECIE���������ж� (Second interrupt enable) 
	λ0 
	0������(������)���ж� 
	1���������ж�
*/
void RTC_set_SECIE(U8 enable_disable) ;

#define RTC_enable_interrupt_at_second() RTC_set_SECIE(1)
#define RTC_disable_interrupt_at_second() RTC_set_SECIE(0)

//*************************RTC_CRL*******************************//
/*
	RTOFF��RTC�����ر� (RTC operation OFF) 
	λ5 
	RTCģ��������λ��ָʾ����Ĵ������е����һ�β�����״̬��ָʾ�����Ƿ���ɡ�����λ
	Ϊ��0�������ʾ�޷����κε�RTC�Ĵ�������д��������λΪֻ��λ�� 
	0����һ�ζ�RTC�Ĵ�����д�������ڽ���; 
	1����һ�ζ�RTC�Ĵ�����д�����Ѿ���ɡ�
*/
#define RTC_get_RTOFF()				(__get_bit(RTC_CRL, 5))

#define RTC_is_operation_done()		RTC_get_RTOFF()	//�Ƿ���һ�εĲ������

#define RTC_wait_operation_done() 	while(!RTC_is_operation_done()) 

/*
	CNF�����ñ�־ (Configuration flag) 
	λ4 
	��λ����������á�1���Խ�������ģʽ���Ӷ�������RTC_CNT��RTC_ALR��RTC_PRL�Ĵ���
	д�����ݡ�ֻ�е���λ�ڱ��á�1��������������塯0���󣬲Ż�ִ��д������ 
	0���˳�����ģʽ(��ʼ����RTC�Ĵ���)�� 
	1����������ģʽ��
*/
void RTC_set_CNF(U8 conf);

#define RTC_enter_configure_mode()	RTC_set_CNF(1)
#define RTC_exit_configure_mode()	RTC_set_CNF(0)


/*
	RSF���Ĵ���ͬ����־ (Registers synchronized flag) 
	λ3 
	ÿ��RTC_CNT�Ĵ�����RTC_DIV�Ĵ�����������»��塯0��ʱ����λ��Ӳ���á�1������APB1��λ
	�󣬻�APB1ʱ��ֹͣ�󣬴�λ����������塯0����Ҫ�����κεĶ�����֮ǰ���û��������ȴ�
	��λ��Ӳ���á�1������ȷ��RTC_CNT��RTC_ALR��RTC_PRL�Ѿ���ͬ���� 
	0���Ĵ�����δ��ͬ���� 
	1���Ĵ����Ѿ���ͬ����
*/	
#define RTC_get_RSF()	(__get_bit(RTC_CRL, 3))
#define RTC_clear_RSF(conf)	(__clear_bit(_RTC_CRL,  3))

#define RTC_is_sync()		RTC_get_RSF()	//RTC�ڼĴ����Ƿ��Ѿ���APB1����ʱ��ͬ��

#define RTC_wait_sync()		while(!RTC_is_sync())
/*
	OWF�������־ (Overflow flag) 
	λ2 
	��32λ�ɱ�̼��������ʱ����λ��Ӳ���á�1�������RTC_CRH�Ĵ�����OWIE=1���������
	�ϡ���λֻ��������塯0�����Դ�λд��1������Ч�ġ� 
	0��������� 
	1��32λ�ɱ�̼���������� 
*/
#define RTC_get_OWF()	(__get_bit(RTC_CRL, 2))
#define RTC_clear_OWF()	(__clear_bit(_RTC_CRL,  2))

#define RTC_is_overflow()	RTC_get_OWF()	//RTC�Ƿ����
#define RTC_clear_overflow_flag()	RTC_clear_OWF()


/*
	ALRF�����ӱ�־ (Alarm flag) 
	λ1 
	��32λ�ɱ�̼������ﵽRTC_ALR�Ĵ��������õ�Ԥ��ֵ����λ��Ӳ���á�1�������RTC_CRH
	�Ĵ�����ALRIE=1��������жϡ���λֻ��������塯0�����Դ�λд��1������Ч�ġ� 
	0�������ӣ� 
	1�������ӡ�
*/
#define RTC_get_ALRF() 			(__get_bit(RTC_CRL, 1))
#define RTC_clear_ALRF()			(__clear_bit(_RTC_CRL, 1))

#define RTC_is_alarm()			RTC_get_ALRF()
#define RTC_clear_alarm_flag()	RTC_clear_ALRF()


/*
	SECF�����־ (Second flag) 
	λ0 
	��32λ�ɱ��Ԥ��Ƶ�����ʱ����λ��Ӳ���á�1��ͬʱRTC��������1����ˣ��˱�־Ϊ�ֱ��ʿ�
	��̵�RTC�������ṩһ�������Ե��ź�(ͨ��Ϊ1��)�����RTC_CRH�Ĵ�����SECIE=1����
	�����жϡ���λֻ�������������Դ�λд��1������Ч�ġ� 
	0�����־������������ 
	1�����־����������
*/
#define RTC_get_SECF()		(__get_bit(RTC_CRL, 0))
#define RTC_clear_SECF()	(__clear_bit(_RTC_CRL, 0))

#define RTC_is_second()			RTC_get_SECF()		//�Ƿ�����
#define RTC_clear_second_flag()		RTC_clear_SECF()	//������־



//**************************RTCԤ��Ƶװ�ؼĴ���(RTC_PRLH/RTC_PRLL)****************************//
/*
	PRL[19:16]��RTCԤ��Ƶװ��ֵ��λ (RTC prescaler reload value high) 
	λ3:0 
	�������¹�ʽ����Щλ���������������ʱ��Ƶ�ʣ� 
	fTR_CLK = fRTCCLK/(PRL[19:0]+1) 
	ע�����Ƽ�ʹ��0ֵ�������޷���ȷ�Ĳ���RTC�жϺͱ�־λ��

	PRL[15:0]��RTCԤ��Ƶװ��ֵ��λ 
	λ15:0 
	�������¹�ʽ����Щλ���������������ʱ��Ƶ�ʣ� 
	fTR_CLK = fRTCCLK/(PRL[19:0]+1)
*/
void RTC_set_PRL(U32 div);

#define RTC_set_prescaler(div) RTC_set_PRL(div)


//*****************RTCԤ��Ƶ�������Ĵ���(RTC_DIVH / RTC_DIVL)*************************//
/*
	�Ĵ�������:
	��TR_CLK��ÿ�������RTCԤ��Ƶ���м�������ֵ���ᱻ��������ΪRTC_PRL�Ĵ�����
	ֵ���û���ͨ����ȡRTC_DIV�Ĵ������Ի��Ԥ��Ƶ�������ĵ�ǰֵ������ֹͣ��Ƶ��������
	�������Ӷ���þ�ȷ��ʱ��������˼Ĵ�����ֻ���Ĵ�������ֵ��RTC_PRL��RTC_CNT�Ĵ�
	���е�ֵ�����ı����Ӳ������װ�ء�
*/
U32	RTC_get_DIV(void);


//**************RTC�������Ĵ��� (RTC_CNTH / RTC_CNTL) ****************************////
/*
	�Ĵ�������:
	RTC����һ��32λ�ɱ�̵ļ���������ͨ������16λ�ļĴ������ʡ���������Ԥ��Ƶ��������
	TR_CLKʱ���׼Ϊ�ο����м�����RTC_CNT�Ĵ���������ż������ļ���ֵ��������
	RTC_CR��λRTOFFд����������RTOFFֵΪ��1��ʱ������д�������ڸ߻�ͼĴ���
	(RTC_CNTH��RTC_CNTL)�ϵ�д�������ܹ�ֱ��װ�ص���Ӧ�Ŀɱ�̼���������������װ��
	RTCԤ��Ƶ���������ж�����ʱ��ֱ�ӷ��ؼ������ڵļ���ֵ(ϵͳʱ��)��
*/
/*
	RTC_CNT[31:16]��RTC��������λ (RTC counter high) 
	λ15:0 
	��ͨ����RTC_CNTH�Ĵ��������RTC��������ǰֵ�ĸ�λ���֡�Ҫ�Դ˼Ĵ�������д����
	ǰ�������Ƚ�������ģʽ(�μ�16.3.4��)��

	λ15:0 
	��ͨ����RTC_CNTL�Ĵ��������RTC��������ǰֵ�ĵ�λ���֡�Ҫ�Դ˼Ĵ�������д������
	�����Ƚ�������ģʽ(�μ�16.3.4��)
*/
#define	RTC_get_CNT() (((RTC_CNTH&0xFFFF)<<16) | (RTC_CNTL&0xFFFF))

//����CNT
void RTC_set_CNT(U32 time);


#define RTC_get_system_time()		RTC_get_CNT()			//���ϵͳʱ��
#define RTC_set_system_time(time)	RTC_set_CNT(time)	//����ϵͳʱ��

//******************RTC���ӼĴ���(RTC_ALRH/RTC_ALRL) *****************************//

/*
	���ɱ�̼�������ֵ��RTC_ALR�е�32λֵ���ʱ��������һ�������¼������Ҳ���RTC����
	�жϡ��˼Ĵ�����RTC_CR�Ĵ������RTOFFλд����������RTOFFֵΪ��1��ʱ������д������
*/
/*
	RTC_ALR[31:16]��RTC����ֵ��λ (RTC alarm high) 
	λ15:0 
	�˼Ĵ����������������д�������ʱ��ĸ�λ���֡�Ҫ�Դ˼Ĵ�������д�����������Ƚ���
	����ģʽ(�μ�16.3.4��)
	RTC_ALR[15:0]��RTC����ֵ��λ (RTC alarm low) 
	λ15:0 
	�˼Ĵ����������������д�������ʱ��ĵ�λ���֡�Ҫ�Դ˼Ĵ�������д�����������Ƚ���
	����ģʽ(�μ�16.3.4��)�� 
*/
void 	RTC_set_ALR(U32 alarm);
#define RTC_set_alarm_time(alarm) RTC_set_ALR(alarm)


#endif
