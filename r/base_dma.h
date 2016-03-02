


/*
���ĵ�������DMA�Ĵ���������ز���������ֻ��DMA1������7��Сͨ�����պ����ð�

Channel configuration procedure
The following sequence should be followed to configure a DMA channelx (where x is the 
channel number).
1.
Set the peripheral register address in the DMA_CPARx register. The data will be 
moved from/ to this address to/ from the memory after the peripheral event.
2. 
Set the memory address in the DMA_CMARx register. The data will be written to or 
read from this memory after the peripheral event.
3. 
Configure the total number of data to be transferred in the DMA_CNDTRx register. 
After each peripheral event, this value will be decremented.
4. 
Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
5. 
Configure data transfer direction, circular mode, peripheral & memory incremented 
mode, peripheral & memory data size, and interrupt after half and/or full transfer in the 
DMA_CCRx register
6. 
Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
*/

#ifndef __DMA
#define __DMA

#include "core_map.h"
#include "com.h"


//**********************DMA1************************//
#define __DMA1_ISR		(DMA1_BASE + 0x00000000)
#define __DMA1_IFCR		(DMA1_BASE + 0x00000004)

//DMA1 	Channel1
#define __DMA1_CCR1		(DMA1_Channel1_BASE + 0x00000000)
#define __DMA1_CNDTR1	(DMA1_Channel1_BASE + 0x00000004)
#define __DMA1_CPAR1	(DMA1_Channel1_BASE + 0x00000008)
#define __DMA1_CMAR1	(DMA1_Channel1_BASE + 0x0000000C)

//DMA1	Channel2
#define __DMA1_CCR2		(DMA1_Channel2_BASE + 0x00000000)
#define __DMA1_CNDTR2	(DMA1_Channel2_BASE + 0x00000004)
#define __DMA1_CPAR2	(DMA1_Channel2_BASE + 0x00000008)
#define __DMA1_CMAR2	(DMA1_Channel2_BASE + 0x0000000C)

//DMA1	Channel3
#define __DMA1_CCR3		(DMA1_Channel3_BASE + 0x00000000)
#define __DMA1_CNDTR3	(DMA1_Channel3_BASE + 0x00000004)
#define __DMA1_CPAR3	(DMA1_Channel3_BASE + 0x00000008)
#define __DMA1_CMAR3	(DMA1_Channel3_BASE + 0x0000000C)

//DMA1	Channel4
#define __DMA1_CCR4		(DMA1_Channel4_BASE + 0x00000000)
#define __DMA1_CNDTR4	(DMA1_Channel4_BASE + 0x00000004)
#define __DMA1_CPAR4	(DMA1_Channel4_BASE + 0x00000008)
#define __DMA1_CMAR4	(DMA1_Channel4_BASE + 0x0000000C)

//DMA1	Channel5
#define __DMA1_CCR5		(DMA1_Channel5_BASE + 0x00000000)
#define __DMA1_CNDTR5	(DMA1_Channel5_BASE + 0x00000004)
#define __DMA1_CPAR5	(DMA1_Channel5_BASE + 0x00000008)
#define __DMA1_CMAR5	(DMA1_Channel5_BASE + 0x0000000C)

//DMA1	Channel6
#define __DMA1_CCR6		(DMA1_Channel6_BASE + 0x00000000)
#define __DMA1_CNDTR6	(DMA1_Channel6_BASE + 0x00000004)
#define __DMA1_CPAR6	(DMA1_Channel6_BASE + 0x00000008)
#define __DMA1_CMAR6	(DMA1_Channel6_BASE + 0x0000000C)

//DMA1	Channel7
#define __DMA1_CCR7		(DMA1_Channel7_BASE + 0x00000000)
#define __DMA1_CNDTR7	(DMA1_Channel7_BASE + 0x00000004)
#define __DMA1_CPAR7	(DMA1_Channel7_BASE + 0x00000008)
#define __DMA1_CMAR7	(DMA1_Channel7_BASE + 0x0000000C)

//DMA1	Channelx(1 - 7)
#define __DMA1_CCRx(channel)	(__DMA1_CCR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CNDTRx(channel)	(__DMA1_CNDTR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CPARx(channel)	(__DMA1_CPAR1 + (0x14 * ((channel%8) - 1)))
#define __DMA1_CMARx(channel)	(__DMA1_CMAR1 + (0x14 * ((channel%8) - 1)))

//********************DMA2***********************//
#define __DMA2_ISR		(DMA2_BASE + 0x00000000)
#define __DMA2_IFCR		(DMA2_BASE + 0x00000004)

//DMA2 	Channel1
#define __DMA2_CCR1		(DMA2_Channel1_BASE + 0x00000000)
#define __DMA2_CNDTR1	(DMA2_Channel1_BASE + 0x00000004)
#define __DMA2_CPAR1	(DMA2_Channel1_BASE + 0x00000008)
#define __DMA2_CMAR1	(DMA2_Channel1_BASE + 0x0000000C)

//DMA2	Channel2
#define __DMA2_CCR2		(DMA2_Channel2_BASE + 0x00000000)
#define __DMA2_CNDTR2	(DMA2_Channel2_BASE + 0x00000004)
#define __DMA2_CPAR2	(DMA2_Channel2_BASE + 0x00000008)
#define __DMA2_CMAR2	(DMA2_Channel2_BASE + 0x0000000C)

//DMA2	Channel3
#define __DMA2_CCR3		(DMA2_Channel3_BASE + 0x00000000)
#define __DMA2_CNDTR3	(DMA2_Channel3_BASE + 0x00000004)
#define __DMA2_CPAR3	(DMA2_Channel3_BASE + 0x00000008)
#define __DMA2_CMAR3	(DMA2_Channel3_BASE + 0x0000000C)

//DMA2	Channel4
#define __DMA2_CCR4		(DMA2_Channel4_BASE + 0x00000000)
#define __DMA2_CNDTR4	(DMA2_Channel4_BASE + 0x00000004)
#define __DMA2_CPAR4	(DMA2_Channel4_BASE + 0x00000008)
#define __DMA2_CMAR4	(DMA2_Channel4_BASE + 0x0000000C)

//DMA2	Channel5
#define __DMA2_CCR5		(DMA2_Channel5_BASE + 0x00000000)
#define __DMA2_CNDTR5	(DMA2_Channel5_BASE + 0x00000004)
#define __DMA2_CPAR5	(DMA2_Channel5_BASE + 0x00000008)
#define __DMA2_CMAR5	(DMA2_Channel5_BASE + 0x0000000C)

//DMA2	Channelx(1 - 5)
#define __DMA2_CCRx(channel)	(__DMA2_CCR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CNDTRx(channel)	(__DMA2_CNDTR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CPARx(channel)	(__DMA2_CPAR1 + (0x14 * ((channel%6) - 1)))
#define __DMA2_CMARx(channel)	(__DMA2_CMAR1 + (0x14 * ((channel%6) - 1)))


/*Adress*/
//**********************DMA1************************//
#define _DMA1_ISR		ADR(__DMA1_ISR)		
#define _DMA1_IFCR		ADR(__DMA1_IFCR)		

//DMA1 	Channel1
#define _DMA1_CCR1		ADR(__DMA1_CCR1)		
#define _DMA1_CNDTR1	ADR(__DMA1_CNDTR1)	
#define _DMA1_CPAR1		ADR(__DMA1_CPAR1)	
#define _DMA1_CMAR1		ADR(__DMA1_CMAR1)	

//DMA1	Channel2
#define _DMA1_CCR2		ADR(__DMA1_CCR2)
#define _DMA1_CNDTR2	ADR(__DMA1_CNDTR2)	
#define _DMA1_CPAR2		ADR(__DMA1_CPAR2)	
#define _DMA1_CMAR2		ADR(__DMA1_CMAR2)	

//DMA1	Channel3
#define _DMA1_CCR3		ADR(__DMA1_CCR3)	
#define _DMA1_CNDTR3	ADR(__DMA1_CNDTR3)	
#define _DMA1_CPAR3		ADR(__DMA1_CPAR3)	
#define _DMA1_CMAR3		ADR(__DMA1_CMAR3)	

//DMA1	Channel4
#define _DMA1_CCR4		ADR(__DMA1_CCR4)		
#define _DMA1_CNDTR4	ADR(__DMA1_CNDTR4)	
#define _DMA1_CPAR4		ADR(__DMA1_CPAR4)	
#define _DMA1_CMAR4		ADR(__DMA1_CMAR4)	

//DMA1	Channel5
#define _DMA1_CCR5		ADR(__DMA1_CCR5)		
#define _DMA1_CNDTR5	ADR(__DMA1_CNDTR5)	
#define _DMA1_CPAR5		ADR(__DMA1_CPAR5)	
#define _DMA1_CMAR5		ADR(__DMA1_CMAR5)	

//DMA1	Channel6
#define _DMA1_CCR6		ADR(__DMA1_CCR6)		
#define _DMA1_CNDTR6	ADR(__DMA1_CNDTR6)	
#define _DMA1_CPAR6		ADR(__DMA1_CPAR6)	
#define _DMA1_CMAR6		ADR(__DMA1_CMAR6)	

//DMA1	Channel7
#define _DMA1_CCR7		ADR(__DMA1_CCR7)	
#define _DMA1_CNDTR7	ADR(__DMA1_CNDTR7)	
#define _DMA1_CPAR7		ADR(__DMA1_CPAR7)	
#define _DMA1_CMAR7		ADR(__DMA1_CMAR7)

//DMA1	Channelx(1 - 7)
#define _DMA1_CCRx(channel)		ADR(__DMA1_CCRx(channel))	
#define _DMA1_CNDTRx(channel)	ADR(__DMA1_CNDTRx(channel))	
#define _DMA1_CPARx(channel)	ADR(__DMA1_CPARx(channel))	
#define _DMA1_CMARx(channel)	ADR(__DMA1_CMARx(channel))	

//********************DMA2***********************//
#define _DMA2_ISR		ADR(__DMA2_ISR)		
#define _DMA2_IFCR		ADR(__DMA2_IFCR)		

//DMA2 	Channel1
#define _DMA2_CCR1		ADR(__DMA2_CCR1)		
#define _DMA2_CNDTR1	ADR(__DMA2_CNDTR1)	
#define _DMA2_CPAR1		ADR(__DMA2_CPAR1)	
#define _DMA2_CMAR1		ADR(__DMA2_CMAR1)	

//DMA2	Channel2
#define _DMA2_CCR2		ADR(__DMA2_CCR2)	
#define _DMA2_CNDTR2	ADR(__DMA2_CNDTR2)	
#define _DMA2_CPAR2		ADR(__DMA2_CPAR2)	
#define _DMA2_CMAR2		ADR(__DMA2_CMAR2)	

//DMA2	Channel3
#define _DMA2_CCR3		ADR(__DMA2_CCR3)	
#define _DMA2_CNDTR3	ADR(__DMA2_CNDTR3)	
#define _DMA2_CPAR3		ADR(__DMA2_CPAR3)	
#define _DMA2_CMAR3		ADR(__DMA2_CMAR3)
	
//DMA2	Channel4
#define _DMA2_CCR4		ADR(__DMA2_CCR4)
#define _DMA2_CNDTR4	ADR(__DMA2_CNDTR4	
#define _DMA2_CPAR4		ADR(__DMA2_CPAR4)	
#define _DMA2_CMAR4		ADR(__DMA2_CMAR4)	

//DMA2	Channel5
#define _DMA2_CCR5		ADR(__DMA2_CCR5)	
#define _DMA2_CNDTR5	ADR(__DMA2_CNDTR5)	
#define _DMA2_CPAR5		ADR(__DMA2_CPAR5)	
#define _DMA2_CMAR5		ADR(__DMA2_CMAR5)	

//DMA2	Channelx(1 - 5)
#define _DMA2_CCRx(channel)		ADR(__DMA2_CCRx(channel))	
#define _DMA2_CNDTRx(channel)	ADR(__DMA2_CNDTRx(channel))	
#define _DMA2_CPARx(channel)	ADR(__DMA2_CPARx(channel))	
#define _DMA2_CMARx(channel)	ADR(__DMA2_CMARx(channel))	


/*Value*/
//**********************DMA1************************//
#define DMA1_ISR		VAL(__DMA1_ISR)		
#define DMA1_IFCR		VAL(__DMA1_IFCR)		

//DMA1 	Channel1
#define DMA1_CCR1		VAL(__DMA1_CCR1)		
#define DMA1_CNDTR1		VAL(__DMA1_CNDTR1)	
#define DMA1_CPAR1		VAL(__DMA1_CPAR1)	
#define DMA1_CMAR1		VAL(__DMA1_CMAR1)	

//DMA1	Channel2
#define DMA1_CCR2		VAL(__DMA1_CCR2)
#define DMA1_CNDTR2		VAL(__DMA1_CNDTR2)	
#define DMA1_CPAR2		VAL(__DMA1_CPAR2)	
#define DMA1_CMAR2		VAL(__DMA1_CMAR2)	

//DMA1	Channel3
#define DMA1_CCR3		VAL(__DMA1_CCR3)	
#define DMA1_CNDTR3		VAL(__DMA1_CNDTR3)	
#define DMA1_CPAR3		VAL(__DMA1_CPAR3)	
#define DMA1_CMAR3		VAL(__DMA1_CMAR3)	

//DMA1	Channel4
#define DMA1_CCR4		VAL(__DMA1_CCR4)		
#define DMA1_CNDTR4		VAL(__DMA1_CNDTR4)	
#define DMA1_CPAR4		VAL(__DMA1_CPAR4)	
#define DMA1_CMAR4		VAL(__DMA1_CMAR4)	

//DMA1	Channel5
#define DMA1_CCR5		VAL(__DMA1_CCR5)		
#define DMA1_CNDTR5		VAL(__DMA1_CNDTR5)	
#define DMA1_CPAR5		VAL(__DMA1_CPAR5)	
#define DMA1_CMAR5		VAL(__DMA1_CMAR5)	

//DMA1	Channel6
#define DMA1_CCR6		VAL(__DMA1_CCR6)		
#define DMA1_CNDTR6		VAL(__DMA1_CNDTR6)	
#define DMA1_CPAR6		VAL(__DMA1_CPAR6)	
#define DMA1_CMAR6		VAL(__DMA1_CMAR6)	

//DMA1	Channel7
#define DMA1_CCR7		VAL(__DMA1_CCR7)	
#define DMA1_CNDTR7		VAL(__DMA1_CNDTR7)	
#define DMA1_CPAR7		VAL(__DMA1_CPAR7)	
#define DMA1_CMAR7		VAL(__DMA1_CMAR7)	

//DMA1	Channelx(1 - 7)
#define DMA1_CCRx(channel)		VAL(__DMA1_CCRx(channel))	
#define DMA1_CNDTRx(channel)	VAL(__DMA1_CNDTRx(channel))	
#define DMA1_CPARx(channel)		VAL(__DMA1_CPARx(channel))	
#define DMA1_CMARx(channel)		VAL(__DMA1_CMARx(channel))

//********************DMA2***********************//
#define DMA2_ISR		VAL(__DMA2_ISR)		
#define DMA2_IFCR		VAL(__DMA2_IFCR)		

//DMA2 	Channel1
#define DMA2_CCR1		VAL(__DMA2_CCR1)		
#define DMA2_CNDTR1		VAL(__DMA2_CNDTR1)	
#define DMA2_CPAR1		VAL(__DMA2_CPAR1)	
#define DMA2_CMAR1		VAL(__DMA2_CMAR1)	

//DMA2	Channel2
#define DMA2_CCR2		VAL(__DMA2_CCR2)	
#define DMA2_CNDTR2		VAL(__DMA2_CNDTR2)	
#define DMA2_CPAR2		VAL(__DMA2_CPAR2)	
#define DMA2_CMAR2		VAL(__DMA2_CMAR2)	

//DMA2	Channel3
#define DMA2_CCR3		VAL(__DMA2_CCR3)	
#define DMA2_CNDTR3		VAL(__DMA2_CNDTR3)	
#define DMA2_CPAR3		VAL(__DMA2_CPAR3)	
#define DMA2_CMAR3		VAL(__DMA2_CMAR3)
	
//DMA2	Channel4
#define DMA2_CCR4		VAL(__DMA2_CCR4)
#define DMA2_CNDTR4		VAL(__DMA2_CNDTR4	
#define DMA2_CPAR4		VAL(__DMA2_CPAR4)	
#define DMA2_CMAR4		VAL(__DMA2_CMAR4)	

//DMA2	Channel5
#define DMA2_CCR5		VAL(__DMA2_CCR5)	
#define DMA2_CNDTR5		VAL(__DMA2_CNDTR5)	
#define DMA2_CPAR5		VAL(__DMA2_CPAR5)	
#define DMA2_CMAR5		VAL(__DMA2_CMAR5)

//DMA2	Channelx(1 - 5)
#define DMA2_CCRx(channel)		VAL(__DMA2_CCRx(channel))	
#define DMA2_CNDTRx(channel)	VAL(__DMA2_CNDTRx(channel))	
#define DMA2_CPARx(channel)		VAL(__DMA2_CPARx(channel))	
#define DMA2_CMARx(channel)		VAL(__DMA2_CMARx(channel))



//***********************************************************************************************//
//**************************************DMA1����*************************************************//
//***********************************************************************************************//
 
//************************DMA interrupt status register (DMA_ISR)*****************//
//DMA�ж�״̬�Ĵ���: ���ڻ�ȡDMA�ж�

/*
Bits 31:28
Reserved, always read as 0.
*/

/*
ͨ����������жϱ�־
Bits 27, 23, 19, 15,                      
11, 7, 3
TEIFx: Channel x transfer error flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No transfer error (TE) on channel x
1: A transfer error (TE) occurred on channel x
*/
U8	DMA1_get_TEIFx(U8 channel);

//����1
#define DAM1_is_transfer_error_occured(channel)	DMA1_get_TEIFx(channel)	//ͨ��x�����־

#define DMA1_CH1_is_transfer_error_occured()	DMA1_get_TEIFx(1)	//ͨ��1�����¼���־
#define DMA1_CH2_is_transfer_error_occured()	DMA1_get_TEIFx(2)   //ͨ��2�����¼���־
#define DMA1_CH3_is_transfer_error_occured()	DMA1_get_TEIFx(3)   //ͨ��3�����¼���־
#define DMA1_CH4_is_transfer_error_occured()	DMA1_get_TEIFx(4)   //ͨ��4�����¼���־
#define DMA1_CH5_is_transfer_error_occured()	DMA1_get_TEIFx(5)   //ͨ��5�����¼���־
#define DMA1_CH6_is_transfer_error_occured()	DMA1_get_TEIFx(6)   //ͨ��6�����¼���־
#define DMA1_CH7_is_transfer_error_occured()	DMA1_get_TEIFx(7)   //ͨ��7�����¼���־


//����2
#define DAM1_is_interrupted_by_transfer_error(channel)	DMA1_get_TEIFx(channel)	//ͨ��x�����жϱ�־

#define DMA1_CH1_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(1)	//ͨ��1�����жϱ�־
#define DMA1_CH2_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(2)   //ͨ��2�����жϱ�־
#define DMA1_CH3_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(3)   //ͨ��3�����жϱ�־
#define DMA1_CH4_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(4)   //ͨ��4�����жϱ�־
#define DMA1_CH5_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(5)   //ͨ��5�����жϱ�־
#define DMA1_CH6_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(6)   //ͨ��6�����жϱ�־
#define DMA1_CH7_is_interrupted_by_transfer_error()	DMA1_get_TEIFx(7)   //ͨ��7�����жϱ�־


/*
ͨ����������жϱ�־
Bits 26, 22, 18, 14,                     
10, 6, 2
HTIFx: Channel x half transfer flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No half transfer (HT) event on channel x
1: A half transfer (HT) event occurred on channel x
*/
U8	DMA1_get_HTIFx(U8 channel);

//����1
#define DMA1_is_transfer_half_occured(channel)  DMA1_get_HTIFx(channel)   //��������¼���־

#define DMA1_CH1_is_transfer_half_occured()  DMA1_get_HTIFx(1)   //ͨ��1��������¼���־
#define DMA1_CH2_is_transfer_half_occured()  DMA1_get_HTIFx(2)   //ͨ��2��������¼���־
#define DMA1_CH3_is_transfer_half_occured()  DMA1_get_HTIFx(3)   //ͨ��3��������¼���־
#define DMA1_CH4_is_transfer_half_occured()  DMA1_get_HTIFx(4)   //ͨ��4��������¼���־
#define DMA1_CH5_is_transfer_half_occured()  DMA1_get_HTIFx(5)   //ͨ��5��������¼���־
#define DMA1_CH6_is_transfer_half_occured()  DMA1_get_HTIFx(6)   //ͨ��6��������¼���־
#define DMA1_CH7_is_transfer_half_occured()  DMA1_get_HTIFx(7)   //ͨ��7��������¼���־

//����2
#define DMA1_is_interrupted_by_transfer_half(channel)  DMA1_get_HTIFx(channel)

#define DMA1_CH1_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(1)  	//ͨ��1��������жϱ�־
#define DMA1_CH2_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(2)   //ͨ��2��������жϱ�־
#define DMA1_CH3_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(3)   //ͨ��3��������жϱ�־
#define DMA1_CH4_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(4)   //ͨ��4��������жϱ�־
#define DMA1_CH5_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(5)   //ͨ��5��������жϱ�־
#define DMA1_CH6_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(6)   //ͨ��6��������жϱ�־
#define DMA1_CH7_is_interrupted_by_transfer_half()  DMA1_get_HTIFx(7)   //ͨ��7��������жϱ�־

/*
ͨ����������жϱ�־
Bits 25, 21, 17, 13,					  
9, 5, 1
TCIFx: Channel x transfer complete flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No transfer complete (TC) event on channel x
1: A transfer complete (TC) event occurred on channel x
*/

U8	DMA1_get_TCIFx(U8 channel);

//����1
#define DMA1_is_transfer_complete_occured(channel)  DMA1_get_TCIFx(channel)   //��������¼�

#define DMA1_CH1_is_transfer_complete_occured()  DMA1_get_TCIFx(1)   //ͨ��1��������¼���־
#define DMA1_CH2_is_transfer_complete_occured()  DMA1_get_TCIFx(2)   //ͨ��2��������¼���־
#define DMA1_CH3_is_transfer_complete_occured()  DMA1_get_TCIFx(3)   //ͨ��3��������¼���־
#define DMA1_CH4_is_transfer_complete_occured()  DMA1_get_TCIFx(4)   //ͨ��4��������¼���־
#define DMA1_CH5_is_transfer_complete_occured()  DMA1_get_TCIFx(5)   //ͨ��5��������¼���־
#define DMA1_CH6_is_transfer_complete_occured()  DMA1_get_TCIFx(6)   //ͨ��6��������¼���־
#define DMA1_CH7_is_transfer_complete_occured()  DMA1_get_TCIFx(7)   //ͨ��7��������¼���־

//����2
#define DMA1_is_interrupted_by_transfer_complete(channel)  DMA1_get_TCIFx(channel)

#define DMA1_CH1_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(1)  	//ͨ��1��������жϱ�־ 
#define DMA1_CH2_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(2)   //ͨ��2��������жϱ�־ 
#define DMA1_CH3_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(3)   //ͨ��3��������жϱ�־ 
#define DMA1_CH4_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(4)   //ͨ��4��������жϱ�־ 
#define DMA1_CH5_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(5)   //ͨ��5��������жϱ�־ 
#define DMA1_CH6_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(6)   //ͨ��6��������жϱ�־ 
#define DMA1_CH7_is_interrupted_by_transfer_complete()  DMA1_get_TCIFx(7)   //ͨ��7��������жϱ�־ 

/*
ͨ��ȫ���жϱ�־
Bits 24, 20, 16, 12,                      
8, 4, 0
GIFx: Channel x global interrupt flag (x = 1 ..7)
This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the 
DMA_IFCR register.
0: No TE, HT or TC event on channel x
1: A TE, HT or TC event occurred on channel x
*/
U8	DMA1_get_GIFx(U8 channel);

#define DMA1_is_event_occured(channel)	DMA1_get_GIFx(channel)    //�Ƿ����¼�����

#define DMA1_CH1_is_event_occured()		DMA1_get_GIFx(1)    //ͨ��1�Ƿ����¼�����
#define DMA1_CH2_is_event_occured()		DMA1_get_GIFx(2)    //ͨ��2�Ƿ����¼�����
#define DMA1_CH3_is_event_occured()		DMA1_get_GIFx(3)    //ͨ��3�Ƿ����¼�����
#define DMA1_CH4_is_event_occured()		DMA1_get_GIFx(4)    //ͨ��4�Ƿ����¼�����
#define DMA1_CH5_is_event_occured()		DMA1_get_GIFx(5)    //ͨ��5�Ƿ����¼�����
#define DMA1_CH6_is_event_occured()		DMA1_get_GIFx(6)    //ͨ��6�Ƿ����¼�����
#define DMA1_CH7_is_event_occured()		DMA1_get_GIFx(7)    //ͨ��7�Ƿ����¼�����


#define DMA1_is_interrupted_by_event(channel)	DMA1_get_GIFx(channel)

#define DMA1_CH1_is_interrupted_by_event()	DMA1_get_GIFx(1)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH2_is_interrupted_by_event()	DMA1_get_GIFx(2)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH3_is_interrupted_by_event()	DMA1_get_GIFx(3)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH4_is_interrupted_by_event()	DMA1_get_GIFx(4)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH5_is_interrupted_by_event()	DMA1_get_GIFx(5)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH6_is_interrupted_by_event()	DMA1_get_GIFx(6)    //ͨ��1�Ƿ����жϷ���
#define DMA1_CH7_is_interrupted_by_event()	DMA1_get_GIFx(7)    //ͨ��1�Ƿ����жϷ���


//*********************DMA interrupt flag clear register (DMA_IFCR)**************//
//DMA�жϱ�־����Ĵ���:����жϱ�־���
/*
Address offset: 0x04
Reset value: 0x0000 0000
*/
/*
Bits 31:28
Reserved, always read as 0.
*/

/*
���ͨ����������жϱ�־
Bits 27, 23, 19, 15,                      
11, 7, 3
CTEIFx: Channel x transfer error clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding TEIF flag in the DMA_ISR register 
*/
void DMA1_clear_CTEIFx(U8 channel);

//����1
#define	DMA1_clear_transfer_error_flag(channel)	  DMA1_clear_CTEIFx(channel)   //����������־

#define DMA1_CH1_clear_transfer_error_flag()	DMA1_clear_CTEIFx(1)    //ͨ��1����������־
#define DMA1_CH2_clear_transfer_error_flag()	DMA1_clear_CTEIFx(2)    //ͨ��2����������־
#define DMA1_CH3_clear_transfer_error_flag()	DMA1_clear_CTEIFx(3)    //ͨ��3����������־
#define DMA1_CH4_clear_transfer_error_flag()	DMA1_clear_CTEIFx(4)    //ͨ��4����������־
#define DMA1_CH5_clear_transfer_error_flag()	DMA1_clear_CTEIFx(5)    //ͨ��5����������־
#define DMA1_CH6_clear_transfer_error_flag()	DMA1_clear_CTEIFx(6)    //ͨ��6����������־
#define DMA1_CH7_clear_transfer_error_flag()	DMA1_clear_CTEIFx(7)    //ͨ��7����������־



/*
���ͨ����������жϱ�־
Bits 26, 22, 18, 14,                      
10, 6, 2
CHTIFx: Channel x half transfer clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding HTIF flag in the DMA_ISR register
*/
void DMA1_clear_CHTIFx(U8 channel);

#define DMA1_clear_transfer_half_flag(channel)	DMA1_clear_CHTIFx(channel)

#define DMA1_CH1_clear_transfer_half_flag()		DMA1_clear_CHTIFx(1)
#define DMA1_CH2_clear_transfer_half_flag()		DMA1_clear_CHTIFx(2)
#define DMA1_CH3_clear_transfer_half_flag()		DMA1_clear_CHTIFx(3)
#define DMA1_CH4_clear_transfer_half_flag()		DMA1_clear_CHTIFx(4)
#define DMA1_CH5_clear_transfer_half_flag()		DMA1_clear_CHTIFx(5)
#define DMA1_CH6_clear_transfer_half_flag()		DMA1_clear_CHTIFx(6)
#define DMA1_CH7_clear_transfer_half_flag()		DMA1_clear_CHTIFx(7)

/*
���ͨ����������жϱ�־
Bits 25, 21, 17, 13,                      
9, 5, 1
CTCIFx: Channel x transfer complete clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the corresponding TCIF flag in the DMA_ISR register
*/
void DMA1_clear_CTCIFx(U8 channel);

#define DMA1_clear_transfer_complete_flag(channel)	DMA1_clear_CTCIFx(channel)

#define DMA1_CH1_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(1)
#define DMA1_CH2_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(2)
#define DMA1_CH3_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(3)
#define DMA1_CH4_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(4)
#define DMA1_CH5_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(5)
#define DMA1_CH6_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(6)
#define DMA1_CH7_clear_transfer_complete_flag()		DMA1_clear_CTCIFx(7)


/*
�������ȫ���жϱ�־
Bits 24, 20, 16, 12,                      
8, 4, 0
CGIFx: Channel x global interrupt clear (x = 1 ..7)
This bit is set and cleared by software.
0: No effect
1: Clears the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
*/
void DMA1_clear_CGIFx(U8 channel);

#define DMA1_clear_event_flag(channel)		DMA1_clear_CGIFx(channel)

#define DMA1_CH1_clear_event_flag()		DMA1_clear_CGIFx(1)
#define DMA1_CH2_clear_event_flag()		DMA1_clear_CGIFx(2)
#define DMA1_CH3_clear_event_flag()		DMA1_clear_CGIFx(3)
#define DMA1_CH4_clear_event_flag()		DMA1_clear_CGIFx(4)
#define DMA1_CH5_clear_event_flag()		DMA1_clear_CGIFx(5)
#define DMA1_CH6_clear_event_flag()		DMA1_clear_CGIFx(6)
#define DMA1_CH7_clear_event_flag()		DMA1_clear_CGIFx(7)


//***********DMA channel x configuration register (DMA_CCRx)**************//
/*
DMA channel x configuration register (DMA_CCRx) (x = 1..7,
where x = channel number)
Address offset: 0x08 + 0d20 �� (channel number �C 1)
Reset value: 0x0000 0000
*/

/*
Bits 31:15
Reserved, always read as 0.
*/

/*
�洢�����洢��ģʽ ʹ��
Bit 14 MEM2MEM: Memory to memory mode         
This bit is set and cleared by software.
0: Memory to memory mode disabled
1: Memory to memory mode enabled 
*/
void DMA1_set_MEM2MEM(U8 channel, U8 a_d);

#define DMA1_enable_MEM2MEM(channel)	DMA1_set_MEM2MEM(channel, 1)

#define DMA1_CH1_enable_MEM2MEM()	DMA1_set_MEM2MEM(1, 1)
#define DMA1_CH2_enable_MEM2MEM()	DMA1_set_MEM2MEM(2, 1)
#define DMA1_CH3_enable_MEM2MEM()	DMA1_set_MEM2MEM(3, 1)
#define DMA1_CH4_enable_MEM2MEM()	DMA1_set_MEM2MEM(4, 1)
#define DMA1_CH5_enable_MEM2MEM()	DMA1_set_MEM2MEM(5, 1)
#define DMA1_CH6_enable_MEM2MEM()	DMA1_set_MEM2MEM(6, 1)
#define DMA1_CH7_enable_MEM2MEM()	DMA1_set_MEM2MEM(7, 1)


#define DMA1_CH1_disable_MEM2MEM()	DMA1_set_MEM2MEM(1, 0)
#define DMA1_CH2_disable_MEM2MEM()	DMA1_set_MEM2MEM(2, 0)
#define DMA1_CH3_disable_MEM2MEM()	DMA1_set_MEM2MEM(3, 0)
#define DMA1_CH4_disable_MEM2MEM()	DMA1_set_MEM2MEM(4, 0)
#define DMA1_CH5_disable_MEM2MEM()	DMA1_set_MEM2MEM(5, 0)
#define DMA1_CH6_disable_MEM2MEM()	DMA1_set_MEM2MEM(6, 0)
#define DMA1_CH7_disable_MEM2MEM()	DMA1_set_MEM2MEM(7, 0)

/*
ͨ�����ȼ�
Bits 13:12 PL[1:0]: Channel priority level     
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
*/
void DMA1_set_PL(U8 channel, U8 p);

#define DMA1_set_priority(channel, p)	DMA1_set_PL(channel, p)

//Channel 1 - 7���ȼ�����
#define DMA1_CH1_set_priority(p)	DMA1_set_PL(1, p)
#define DMA1_CH2_set_priority(p)	DMA1_set_PL(2, p)
#define DMA1_CH3_set_priority(p)	DMA1_set_PL(3, p)
#define DMA1_CH4_set_priority(p)	DMA1_set_PL(4, p)
#define DMA1_CH5_set_priority(p)	DMA1_set_PL(5, p)
#define DMA1_CH6_set_priority(p)	DMA1_set_PL(6, p)
#define DMA1_CH7_set_priority(p)	DMA1_set_PL(7, p)

//Channel 1���ȼ�����
#define DMA1_CH1_set_priority_low()			DMA1_set_PL(1, 0)
#define DMA1_CH1_set_priority_medium()		DMA1_set_PL(1, 1)
#define DMA1_CH1_set_priority_high()		DMA1_set_PL(1, 2)
#define DMA1_CH1_set_priority_veryhigh()	DMA1_set_PL(1, 3)
//Channel 2���ȼ�����
#define DMA1_CH2_set_priority_low()			DMA1_set_PL(2, 0)
#define DMA1_CH2_set_priority_medium()		DMA1_set_PL(2, 1)
#define DMA1_CH2_set_priority_high()		DMA1_set_PL(2, 2)
#define DMA1_CH2_set_priority_veryhigh()	DMA1_set_PL(2, 3)
//Channel 3���ȼ�����
#define DMA1_CH3_set_priority_low()			DMA1_set_PL(3, 0)
#define DMA1_CH3_set_priority_medium()		DMA1_set_PL(3, 1)
#define DMA1_CH3_set_priority_high()		DMA1_set_PL(3, 2)
#define DMA1_CH3_set_priority_veryhigh()	DMA1_set_PL(3, 3)
//Channel 4���ȼ�����
#define DMA1_CH4_set_priority_low()			DMA1_set_PL(4, 0)
#define DMA1_CH4_set_priority_medium()		DMA1_set_PL(4, 1)
#define DMA1_CH4_set_priority_high()		DMA1_set_PL(4, 2)
#define DMA1_CH4_set_priority_veryhigh()	DMA1_set_PL(4, 3)
//Channel 5���ȼ�����
#define DMA1_CH5_set_priority_low()			DMA1_set_PL(5, 0)
#define DMA1_CH5_set_priority_medium()		DMA1_set_PL(5, 1)
#define DMA1_CH5_set_priority_high()		DMA1_set_PL(5, 2)
#define DMA1_CH5_set_priority_veryhigh()	DMA1_set_PL(5, 3)
//Channel 6���ȼ�����
#define DMA1_CH6_set_priority_low()			DMA1_set_PL(6, 0)
#define DMA1_CH6_set_priority_medium()		DMA1_set_PL(6, 1)
#define DMA1_CH6_set_priority_high()		DMA1_set_PL(6, 2)
#define DMA1_CH6_set_priority_veryhigh()	DMA1_set_PL(6, 3)
//Channel 7���ȼ�����
#define DMA1_CH7_set_priority_low()			DMA1_set_PL(7, 0)
#define DMA1_CH7_set_priority_medium()		DMA1_set_PL(7, 1)
#define DMA1_CH7_set_priority_high()		DMA1_set_PL(7, 2)
#define DMA1_CH7_set_priority_veryhigh()	DMA1_set_PL(7, 3)


/*
�洢�����䵥λ�ߴ�
Bits 11:10 MSIZE[1:0]: Memory size        
These bits are set and cleared by software.
00: 8-bits
01: 16-bits
10: 32-bits
11: Reserved 
*/
void DMA1_set_MSIZE(U8 channel, U8 msz);

#define DMA1_set_memory_size(channel, size)	DMA1_set_MSIZE(channel, size)

//Channel1-7 �洢�����͵�λ�ߴ�
#define DMA1_CH1_set_memory_size(size)	DMA1_set_MSIZE(1, size)
#define DMA1_CH2_set_memory_size(size)	DMA1_set_MSIZE(2, size)
#define DMA1_CH3_set_memory_size(size)	DMA1_set_MSIZE(3, size)
#define DMA1_CH4_set_memory_size(size)	DMA1_set_MSIZE(4, size)
#define DMA1_CH5_set_memory_size(size)	DMA1_set_MSIZE(5, size)
#define DMA1_CH6_set_memory_size(size)	DMA1_set_MSIZE(6, size)
#define DMA1_CH7_set_memory_size(size)	DMA1_set_MSIZE(7, size)

//Channel1 �洢�����͵�λ�ߴ�
#define DMA1_CH1_set_memory_size_8()	DMA1_set_MSIZE(1, 0)
#define DMA1_CH1_set_memory_size_16()	DMA1_set_MSIZE(1, 1)
#define DMA1_CH1_set_memory_size_32()	DMA1_set_MSIZE(1, 2)
//Channel2 �洢�����͵�λ�ߴ�
#define DMA1_CH2_set_memory_size_8()	DMA1_set_MSIZE(2, 0)
#define DMA1_CH2_set_memory_size_16()	DMA1_set_MSIZE(2, 1)
#define DMA1_CH2_set_memory_size_32()	DMA1_set_MSIZE(2, 2)
//Channel3 �洢�����͵�λ�ߴ�
#define DMA1_CH3_set_memory_size_8()	DMA1_set_MSIZE(3, 0)
#define DMA1_CH3_set_memory_size_16()	DMA1_set_MSIZE(3, 1)
#define DMA1_CH3_set_memory_size_32()	DMA1_set_MSIZE(3, 2)
//Channel4 �洢�����͵�λ�ߴ�
#define DMA1_CH4_set_memory_size_8()	DMA1_set_MSIZE(4, 0)
#define DMA1_CH4_set_memory_size_16()	DMA1_set_MSIZE(4, 1)
#define DMA1_CH4_set_memory_size_32()	DMA1_set_MSIZE(4, 2)
//Channel5 �洢�����͵�λ�ߴ�
#define DMA1_CH5_set_memory_size_8()	DMA1_set_MSIZE(5, 0)
#define DMA1_CH5_set_memory_size_16()	DMA1_set_MSIZE(5, 1)
#define DMA1_CH5_set_memory_size_32()	DMA1_set_MSIZE(5, 2)
//Channel6 �洢�����͵�λ�ߴ�
#define DMA1_CH6_set_memory_size_8()	DMA1_set_MSIZE(6, 0)
#define DMA1_CH6_set_memory_size_16()	DMA1_set_MSIZE(6, 1)
#define DMA1_CH6_set_memory_size_32()	DMA1_set_MSIZE(6, 2)
//Channel7 �洢�����͵�λ�ߴ�
#define DMA1_CH7_set_memory_size_8()	DMA1_set_MSIZE(7, 0)
#define DMA1_CH7_set_memory_size_16()	DMA1_set_MSIZE(7, 1)
#define DMA1_CH7_set_memory_size_32()	DMA1_set_MSIZE(7, 2)


/*
���贫�䵥λ�ߴ�
Bits 9:8 PSIZE[1:0]: Peripheral size       
These bits are set and cleared by software.
00: 8-bits
01: 16-bits
10: 32-bits
11: Reserved 
*/
void DMA1_set_PSIZE(U8 channel, U8 psz);

#define DMA1_set_peripheral_size(channel, size)	DMA1_set_PSIZE(channel, size)

//Channel1-7 ���贫�͵�λ�ߴ�
#define DMA1_CH1_set_peripheral_size(size)	DMA1_set_PSIZE(1, size)
#define DMA1_CH2_set_peripheral_size(size)	DMA1_set_PSIZE(2, size)
#define DMA1_CH3_set_peripheral_size(size)	DMA1_set_PSIZE(3, size)
#define DMA1_CH4_set_peripheral_size(size)	DMA1_set_PSIZE(4, size)
#define DMA1_CH5_set_peripheral_size(size)	DMA1_set_PSIZE(5, size)
#define DMA1_CH6_set_peripheral_size(size)	DMA1_set_PSIZE(6, size)
#define DMA1_CH7_set_peripheral_size(size)	DMA1_set_PSIZE(7, size)

//Channel1 ���贫�͵�λ�ߴ�
#define DMA1_CH1_set_peripheral_size_8()	DMA1_set_PSIZE(1, 0)
#define DMA1_CH1_set_peripheral_size_16()	DMA1_set_PSIZE(1, 1)
#define DMA1_CH1_set_peripheral_size_32()	DMA1_set_PSIZE(1, 2)
//Channel2 ���贫�͵�λ�ߴ�
#define DMA1_CH2_set_peripheral_size_8()	DMA1_set_PSIZE(2, 0)
#define DMA1_CH2_set_peripheral_size_16()	DMA1_set_PSIZE(2, 1)
#define DMA1_CH2_set_peripheral_size_32()	DMA1_set_PSIZE(2, 2)
//Channel3 ���贫�͵�λ�ߴ�
#define DMA1_CH3_set_peripheral_size_8()	DMA1_set_PSIZE(3, 0)
#define DMA1_CH3_set_peripheral_size_16()	DMA1_set_PSIZE(3, 1)
#define DMA1_CH3_set_peripheral_size_32()	DMA1_set_PSIZE(3, 2)
//Channel4 ���贫�͵�λ�ߴ�
#define DMA1_CH4_set_peripheral_size_8()	DMA1_set_PSIZE(4, 0)
#define DMA1_CH4_set_peripheral_size_16()	DMA1_set_PSIZE(4, 1)
#define DMA1_CH4_set_peripheral_size_32()	DMA1_set_PSIZE(4, 2)
//Channel5 ���贫�͵�λ�ߴ�
#define DMA1_CH5_set_peripheral_size_8()	DMA1_set_PSIZE(5, 0)
#define DMA1_CH5_set_peripheral_size_16()	DMA1_set_PSIZE(5, 1)
#define DMA1_CH5_set_peripheral_size_32()	DMA1_set_PSIZE(5, 2)
//Channel6 ���贫�͵�λ�ߴ�
#define DMA1_CH6_set_peripheral_size_8()	DMA1_set_PSIZE(6, 0)
#define DMA1_CH6_set_peripheral_size_16()	DMA1_set_PSIZE(6, 1)
#define DMA1_CH6_set_peripheral_size_32()	DMA1_set_PSIZE(6, 2)
//Channel7 ���贫�͵�λ�ߴ�
#define DMA1_CH7_set_peripheral_size_8()	DMA1_set_PSIZE(7, 0)
#define DMA1_CH7_set_peripheral_size_16()	DMA1_set_PSIZE(7, 1)
#define DMA1_CH7_set_peripheral_size_32()	DMA1_set_PSIZE(7, 2)





/*
�洢������ģʽ
Bit 7 MINC: Memory increment mode        
This bit is set and cleared by software.
0: Memory increment mode disabled
1: Memory increment mode enabled 
*/
void DMA1_set_MINC(U8 channel, U8 minc);

//ʹ�ܴ洢������ģʽ
#define DMA1_enable_memory_increment_mode(channel)	DMA1_set_MINC(channel, 1)

#define DMA1_CH1_enable_memory_increment_mode()	DMA1_set_MINC(1, 1)    	//ͨ��1ʹ�ܴ洢������ģʽ
#define DMA1_CH2_enable_memory_increment_mode()	DMA1_set_MINC(2, 1)    	//ͨ��2ʹ�ܴ洢������ģʽ
#define DMA1_CH3_enable_memory_increment_mode()	DMA1_set_MINC(3, 1)		//ͨ��3ʹ�ܴ洢������ģʽ
#define DMA1_CH4_enable_memory_increment_mode()	DMA1_set_MINC(4, 1)     //ͨ��4ʹ�ܴ洢������ģʽ
#define DMA1_CH5_enable_memory_increment_mode()	DMA1_set_MINC(5, 1)     //ͨ��5ʹ�ܴ洢������ģʽ
#define DMA1_CH6_enable_memory_increment_mode()	DMA1_set_MINC(6, 1)     //ͨ��6ʹ�ܴ洢������ģʽ
#define DMA1_CH7_enable_memory_increment_mode()	DMA1_set_MINC(7, 1)     //ͨ��7ʹ�ܴ洢������ģʽ


//���ܴ洢������ģʽ
#define DMA1_disable_memory_increment_mode(channel)	DMA1_set_MINC(channel, 0)

#define DMA1_CH1_disable_memory_increment_mode()	DMA1_set_MINC(1, 0)  //ͨ��1���ܴ洢���Զ�ģʽ
#define DMA1_CH2_disable_memory_increment_mode()	DMA1_set_MINC(2, 0)  //ͨ��2���ܴ洢���Զ�ģʽ
#define DMA1_CH3_disable_memory_increment_mode()	DMA1_set_MINC(3, 0)  //ͨ��3���ܴ洢���Զ�ģʽ
#define DMA1_CH4_disable_memory_increment_mode()	DMA1_set_MINC(4, 0)  //ͨ��4���ܴ洢���Զ�ģʽ
#define DMA1_CH5_disable_memory_increment_mode()	DMA1_set_MINC(5, 0)  //ͨ��5���ܴ洢���Զ�ģʽ
#define DMA1_CH6_disable_memory_increment_mode()	DMA1_set_MINC(6, 0)  //ͨ��6���ܴ洢���Զ�ģʽ
#define DMA1_CH7_disable_memory_increment_mode()	DMA1_set_MINC(7, 0)  //ͨ��7���ܴ洢���Զ�ģʽ




/*
��������ģʽ
Bit 6 PINC: Peripheral increment mode     
This bit is set and cleared by software.
0: Peripheral increment mode disabled
1: Peripheral increment mode enabled 
*/
void DMA1_set_PINC(U8 channel, U8 pinc);

//ʹ����������ģʽ
#define DMA1_enable_peripheral_increment_mode(channel)	DMA1_set_PINC(channel, 1)

#define DMA1_CH1_enable_peripheral_increment_mode()	DMA1_set_PINC(1, 1)    	//ͨ��1ʹ����������ģʽ
#define DMA1_CH2_enable_peripheral_increment_mode()	DMA1_set_PINC(2, 1)    	//ͨ��2ʹ����������ģʽ
#define DMA1_CH3_enable_peripheral_increment_mode()	DMA1_set_PINC(3, 1)		//ͨ��3ʹ����������ģʽ
#define DMA1_CH4_enable_peripheral_increment_mode()	DMA1_set_PINC(4, 1)     //ͨ��4ʹ����������ģʽ
#define DMA1_CH5_enable_peripheral_increment_mode()	DMA1_set_PINC(5, 1)     //ͨ��5ʹ����������ģʽ
#define DMA1_CH6_enable_peripheral_increment_mode()	DMA1_set_PINC(6, 1)     //ͨ��6ʹ����������ģʽ
#define DMA1_CH7_enable_peripheral_increment_mode()	DMA1_set_PINC(7, 1)     //ͨ��7ʹ����������ģʽ


//������������ģʽ
#define DMA1_disable_peripheral_increment_mode(channel)	DMA1_set_PINC(channel, 0)

#define DMA1_CH1_disable_peripheral_increment_mode()	DMA1_set_PINC(1, 0)  //ͨ��1���������Զ�ģʽ
#define DMA1_CH2_disable_peripheral_increment_mode()	DMA1_set_PINC(2, 0)  //ͨ��2���������Զ�ģʽ
#define DMA1_CH3_disable_peripheral_increment_mode()	DMA1_set_PINC(3, 0)  //ͨ��3���������Զ�ģʽ
#define DMA1_CH4_disable_peripheral_increment_mode()	DMA1_set_PINC(4, 0)  //ͨ��4���������Զ�ģʽ
#define DMA1_CH5_disable_peripheral_increment_mode()	DMA1_set_PINC(5, 0)  //ͨ��5���������Զ�ģʽ
#define DMA1_CH6_disable_peripheral_increment_mode()	DMA1_set_PINC(6, 0)  //ͨ��6���������Զ�ģʽ
#define DMA1_CH7_disable_peripheral_increment_mode()	DMA1_set_PINC(7, 0)  //ͨ��7���������Զ�ģʽ



/*
ѭ��ģʽ ʹ��
Bit 5 CIRC: Circular mode                  
This bit is set and cleared by software.
0: Circular mode disabled
1: Circular mode enabled
*/
void DMA1_set_CIRC(U8 channel, U8 e_d);

//ʹ��ѭ��ģʽ
#define DMA1_enable_circular_mode(channel)	DMA1_set_CIRC(channel, 1)

#define DMA1_CH1_enable_circular_mode()	DMA1_set_CIRC(1, 1)    		//ͨ��1ʹ��ѭ��ģʽ
#define DMA1_CH2_enable_circular_mode()	DMA1_set_CIRC(2, 1)    		//ͨ��2ʹ��ѭ��ģʽ
#define DMA1_CH3_enable_circular_mode()	DMA1_set_CIRC(3, 1)    		//ͨ��3ʹ��ѭ��ģʽ
#define DMA1_CH4_enable_circular_mode()	DMA1_set_CIRC(4, 1)    		//ͨ��4ʹ��ѭ��ģʽ
#define DMA1_CH5_enable_circular_mode()	DMA1_set_CIRC(5, 1)    		//ͨ��5ʹ��ѭ��ģʽ
#define DMA1_CH6_enable_circular_mode()	DMA1_set_CIRC(6, 1)    		//ͨ��6ʹ��ѭ��ģʽ
#define DMA1_CH7_enable_circular_mode()	DMA1_set_CIRC(7, 1)    		//ͨ��7ʹ��ѭ��ģʽ

//����ѭ��ģʽ
#define DMA1_disable_circular_mode(channel)	DMA1_set_CIRC(channel, 0)

#define DMA1_CH1_disable_circular_mode()	DMA1_set_CIRC(1, 0)  	//ͨ��1����ѭ��ģʽ
#define DMA1_CH2_disable_circular_mode()	DMA1_set_CIRC(2, 0)  	//ͨ��2����ѭ��ģʽ
#define DMA1_CH3_disable_circular_mode()	DMA1_set_CIRC(3, 0)		//ͨ��3����ѭ��ģʽ
#define DMA1_CH4_disable_circular_mode()	DMA1_set_CIRC(4, 0)     //ͨ��4����ѭ��ģʽ
#define DMA1_CH5_disable_circular_mode()	DMA1_set_CIRC(5, 0)     //ͨ��5����ѭ��ģʽ
#define DMA1_CH6_disable_circular_mode()	DMA1_set_CIRC(6, 0)     //ͨ��6����ѭ��ģʽ
#define DMA1_CH7_disable_circular_mode()	DMA1_set_CIRC(7, 0)     //ͨ��7����ѭ��ģʽ


/*
���ݴ��䷽��
Bit 4 DIR: Data transfer direction
This bit is set and cleared by software.
0: Read from peripheral
1: Read from memory
*/
void DMA1_set_DIR(U8 channel, U8 dir);


//���ݴ��䷽��
#define DMA1_set_transfer_direction(channel, dir)	DMA1_set_DIR(channel, dir)

#define DMA1_CH1_set_transfer_direction(dir)		DMA1_set_DIR(1, dir)
#define DMA1_CH2_set_transfer_direction(dir)		DMA1_set_DIR(2, dir)
#define DMA1_CH3_set_transfer_direction(dir)		DMA1_set_DIR(3, dir)
#define DMA1_CH4_set_transfer_direction(dir)		DMA1_set_DIR(4, dir)
#define DMA1_CH5_set_transfer_direction(dir)		DMA1_set_DIR(5, dir)
#define DMA1_CH6_set_transfer_direction(dir)		DMA1_set_DIR(6, dir)
#define DMA1_CH7_set_transfer_direction(dir)		DMA1_set_DIR(7, dir)

//Channel 1 ����
#define DMA1_CH1_set_transfer_direction_from_peripheral()	DMA1_set_DIR(1, 0)   	//ͨ��1 �������ȡ
#define DMA1_CH1_set_transfer_direction_from_memory()		DMA1_set_DIR(1, 1)   	//ͨ��1 �Ӵ洢����ȡ

//Channel 2 ����
#define DMA1_CH2_set_transfer_direction_from_peripheral()	DMA1_set_DIR(2, 0)   	//ͨ��2 �������ȡ
#define DMA1_CH2_set_transfer_direction_from_memory()		DMA1_set_DIR(2, 1)   	//ͨ��2 �Ӵ洢����ȡ

//Channel 3 ����
#define DMA1_CH3_set_transfer_direction_from_peripheral()	DMA1_set_DIR(3, 0)    	//ͨ��3 �������ȡ
#define DMA1_CH3_set_transfer_direction_from_memory()		DMA1_set_DIR(3, 1)    	//ͨ��3 �Ӵ洢����ȡ

//Channel 4 ����
#define DMA1_CH4_set_transfer_direction_from_peripheral()	DMA1_set_DIR(4, 0)    	//ͨ��4 �������ȡ
#define DMA1_CH4_set_transfer_direction_from_memory()		DMA1_set_DIR(4, 1)    	//ͨ��4 �Ӵ洢����ȡ

//Channel 5 ����
#define DMA1_CH5_set_transfer_direction_from_peripheral()	DMA1_set_DIR(5, 0)    	//ͨ��5 �������ȡ
#define DMA1_CH5_set_transfer_direction_from_memory()		DMA1_set_DIR(5, 1)    	//ͨ��5 �Ӵ洢����ȡ

//Channel 6 ����
#define DMA1_CH6_set_transfer_direction_from_peripheral()	DMA1_set_DIR(6, 0)    	//ͨ��6 �������ȡ
#define DMA1_CH6_set_transfer_direction_from_memory()		DMA1_set_DIR(6, 1)    	//ͨ��6 �Ӵ洢����ȡ

//Channel 7 ����
#define DMA1_CH7_set_transfer_direction_from_peripheral()	DMA1_set_DIR(7, 0)     	//ͨ��7 �������ȡ
#define DMA1_CH7_set_transfer_direction_from_memory()		DMA1_set_DIR(7, 1)    	//ͨ��7 �Ӵ洢����ȡ


/*
��������ж�ʹ��
Bit 3 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
*/
void DMA1_set_TEIE(U8 channel, U8 e_d);

#define DMA1_enable_interrupt_at_transfer_error(channel)	DMA1_set_TEIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_error()		DMA1_set_TEIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_error(channel)	DMA1_set_TEIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_error()		DMA1_set_TEIE(7, 0)



/*
��������ж�ʹ��
Bit 2 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
*/
void DMA1_set_HTIE(U8 channel, U8 e_d);



#define DMA1_enable_interrupt_at_transfer_half(channel)	DMA1_set_HTIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_half()		DMA1_set_HTIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_half(channel)	DMA1_set_HTIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_half()		DMA1_set_HTIE(7, 0)


/*
��������ж�ʹ��
Bit 1 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
*/
void DMA1_set_TCIE(U8 channel, U8 e_d);


#define DMA1_enable_interrupt_at_transfer_complete(channel)	DMA1_set_TCIE(channel, 1)

#define	DMA1_CH1_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(1, 1)
#define	DMA1_CH2_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(2, 1)
#define	DMA1_CH3_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(3, 1)
#define	DMA1_CH4_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(4, 1)
#define	DMA1_CH5_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(5, 1)
#define	DMA1_CH6_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(6, 1)
#define	DMA1_CH7_enable_interrupt_at_transfer_complete()		DMA1_set_TCIE(7, 1)

#define DMA1_disable_interrupt_at_transfer_complete(channel)	DMA1_set_TCIE(channel, 0)

#define	DMA1_CH1_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(1, 0)
#define	DMA1_CH2_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(2, 0)
#define	DMA1_CH3_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(3, 0)
#define	DMA1_CH4_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(4, 0)
#define	DMA1_CH5_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(5, 0)
#define	DMA1_CH6_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(6, 0)
#define	DMA1_CH7_disable_interrupt_at_transfer_complete()		DMA1_set_TCIE(7, 0)



/*
DMAͨ��ʹ��
Bit 0 EN: Channel enable
This bit is set and cleared by software.
0: Channel disabled
1: Channel enabled
*/
void DMA1_set_EN(U8 channel, U8 e_d);

#define DMA1_enable_channel(channel)	DMA1_set_EN(channel, 1)

#define DMA1_CH1_enable_channel()		DMA1_set_EN(1, 1)
#define DMA1_CH2_enable_channel()		DMA1_set_EN(2, 1)
#define DMA1_CH3_enable_channel()		DMA1_set_EN(3, 1)
#define DMA1_CH4_enable_channel()		DMA1_set_EN(4, 1)
#define DMA1_CH5_enable_channel()		DMA1_set_EN(5, 1)
#define DMA1_CH6_enable_channel()		DMA1_set_EN(6, 1)
#define DMA1_CH7_enable_channel()		DMA1_set_EN(7, 1)

#define DMA1_disable_channel(channel)	DMA1_set_EN(channel, 0)

#define DMA1_CH1_disable_channel()		DMA1_set_EN(1, 0)
#define DMA1_CH2_disable_channel()		DMA1_set_EN(2, 0)
#define DMA1_CH3_disable_channel()		DMA1_set_EN(3, 0)
#define DMA1_CH4_disable_channel()		DMA1_set_EN(4, 0)
#define DMA1_CH5_disable_channel()		DMA1_set_EN(5, 0)
#define DMA1_CH6_disable_channel()		DMA1_set_EN(6, 0)
#define DMA1_CH7_disable_channel()		DMA1_set_EN(7, 0)


//***********DMA channel x number of data register (DMA_CNDTRx)***********//
//DMAͨ��x���������Ĵ���
/*
DMA channel x number of data register (DMA_CNDTRx) (x = 1..7),
where x = channel number)
Address offset: 0x0C + 0d20 �� (channel number �C 1)
Reset value: 0x0000 0000
*/
/*
Bits 31:16
Reserved, always read as 0.
*/

/*
��������
Bits 15:0 NDT[15:0]: Number of data to transfer
Number of data to be transferred (0 up to 65535). This register can only be written when the 
channel is disabled. Once the channel is enabled, this register is read-only, indicating the 
remaining bytes to be transmitted. This register decrements after each DMA transfer.
Once the transfer is completed, this register can either stay at zero or be reloaded 
automatically by the value previously programmed if the channel is configured in auto-reload 
mode.
If this register is zero, no transaction can be served whether the channel is enabled or not.
*/
//���ô�����
void DMA1_set_NDT(U8 channel, U16 num);


#define DMA1_set_transfer_number(channel, num)	DMA1_set_NDT(channel, num)

#define DMA1_CH1_set_transfer_number(num)	DMA1_set_NDT(1, num)
#define DMA1_CH2_set_transfer_number(num)	DMA1_set_NDT(2, num)
#define DMA1_CH3_set_transfer_number(num)	DMA1_set_NDT(3, num)
#define DMA1_CH4_set_transfer_number(num)	DMA1_set_NDT(4, num)
#define DMA1_CH5_set_transfer_number(num)	DMA1_set_NDT(5, num)
#define DMA1_CH6_set_transfer_number(num)	DMA1_set_NDT(6, num)
#define DMA1_CH7_set_transfer_number(num)	DMA1_set_NDT(7, num)



//��õ�ǰʣ��Ҫ�����������
U16 DMA1_get_NDT(U8 channel);

#define DMA1_get_transfer_number(channel)	DMA1_get_NDT(channel)

#define DMA1_CH1_get_transfer_number()		DMA1_get_NDT(1)
#define DMA1_CH2_get_transfer_number()		DMA1_get_NDT(2)
#define DMA1_CH3_get_transfer_number()		DMA1_get_NDT(3)
#define DMA1_CH4_get_transfer_number()		DMA1_get_NDT(4)
#define DMA1_CH5_get_transfer_number()		DMA1_get_NDT(5)
#define DMA1_CH6_get_transfer_number()		DMA1_get_NDT(6)
#define DMA1_CH7_get_transfer_number()		DMA1_get_NDT(7)




//****************DMA channel x peripheral address register******************//
//������ʼ��ַ�Ĵ���

/*
DMA channel x peripheral address register (DMA_CPARx) (x = 1..7),
where x = channel number)
Address offset: 0x10 + 0d20 �� (channel number �C 1)
Reset value: 0x0000 0000
This register must not be written when the channel is enabled.
*/

/*
Bits 31:0 PA[31:0]: Peripheral address
Base address of the peripheral data register from/to which the data will be read/written.
When PSIZE is 01 (16-bit), the PA[0] bit is ignored. Access is automatically aligned to a half-
word address.
When PSIZE is 10 (32-bit), PA[1:0] are ignored. Access is automatically aligned to a word 
address.
*/
void DMA1_set_PA(U8 channel, U32 adr);


#define DMA1_set_peripheral_address(channel, adr)	DMA1_set_PA(channel, adr)

#define DMA1_CH1_set_peripheral_address(adr)		DMA1_set_PA(1, adr)
#define DMA1_CH2_set_peripheral_address(adr)		DMA1_set_PA(2, adr)
#define DMA1_CH3_set_peripheral_address(adr)		DMA1_set_PA(3, adr)
#define DMA1_CH4_set_peripheral_address(adr)		DMA1_set_PA(4, adr)
#define DMA1_CH5_set_peripheral_address(adr)		DMA1_set_PA(5, adr)
#define DMA1_CH6_set_peripheral_address(adr)		DMA1_set_PA(6, adr)
#define DMA1_CH7_set_peripheral_address(adr)		DMA1_set_PA(7, adr)


U32	DMA1_get_PA(U8 channel);

#define DMA1_get_peripheral_address(channel)	DMA1_get_PA(channel)

#define DMA1_CH1_get_peripheral_address(adr)		DMA1_get_PA(1)
#define DMA1_CH2_get_peripheral_address(adr)		DMA1_get_PA(2)
#define DMA1_CH3_get_peripheral_address(adr)		DMA1_get_PA(3)
#define DMA1_CH4_get_peripheral_address(adr)		DMA1_get_PA(4)
#define DMA1_CH5_get_peripheral_address(adr)		DMA1_get_PA(5)
#define DMA1_CH6_get_peripheral_address(adr)		DMA1_get_PA(6)
#define DMA1_CH7_get_peripheral_address(adr)		DMA1_get_PA(7)


//**************DMA channel x memory address register (DMA_CMARx) ***********//
//�洢����ʼ��ַ�Ĵ���

/*
DMA channel x memory address register (DMA_CMARx) (x = 1..7),
where x = channel number)
Address offset: 0x14 + 0d20 �� (channel number �C 1)
Reset value: 0x0000 0000
This register must not be written when the channel is enabled.
*/

/*
Bits 31:0 MA[31:0]: Memory address
Base address of the memory area from/to which the data will be read/written. 
When MSIZE is 01 (16-bit), the MA[0] bit is ignored. Access is automatically aligned to a 
half-word address.
When MSIZE is 10 (32-bit), MA[1:0] are ignored. Access is automatically aligned to a word 
address.
*/

void DMA1_set_MA(U8 channel, U32 adr);


#define DMA1_set_memory_address(channel, adr)	DMA1_set_MA(channel, adr)

#define DMA1_CH1_set_memory_address(adr)		DMA1_set_MA(1, adr)
#define DMA1_CH2_set_memory_address(adr)		DMA1_set_MA(2, adr)
#define DMA1_CH3_set_memory_address(adr)		DMA1_set_MA(3, adr)
#define DMA1_CH4_set_memory_address(adr)		DMA1_set_MA(4, adr)
#define DMA1_CH5_set_memory_address(adr)		DMA1_set_MA(5, adr)
#define DMA1_CH6_set_memory_address(adr)		DMA1_set_MA(6, adr)
#define DMA1_CH7_set_memory_address(adr)		DMA1_set_MA(7, adr)




U32	 DMA1_get_MA(U8 channel);


#define DMA1_get_memory_address(channel)	DMA1_get_MA(channel)

#define DMA1_CH1_get_memory_address(adr)		DMA1_get_MA(1)
#define DMA1_CH2_get_memory_address(adr)		DMA1_get_MA(2)
#define DMA1_CH3_get_memory_address(adr)		DMA1_get_MA(3)
#define DMA1_CH4_get_memory_address(adr)		DMA1_get_MA(4)
#define DMA1_CH5_get_memory_address(adr)		DMA1_get_MA(5)
#define DMA1_CH6_get_memory_address(adr)		DMA1_get_MA(6)
#define DMA1_CH7_get_memory_address(adr)		DMA1_get_MA(7)



#endif
