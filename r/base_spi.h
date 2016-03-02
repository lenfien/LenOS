
#ifndef __SPI
#define __SPI

#include "core_map.h"
#include "com.h"

//SPI1 Register
#define __SPI1_CR1 		SPI1_BASE + 0x00
#define __SPI1_CR2		SPI1_BASE + 0x04
#define __SPI1_SR		SPI1_BASE + 0x08
#define __SPI1_DR		SPI1_BASE + 0x0C
#define __SPI1_CRCPR	SPI1_BASE + 0x10
#define __SPI1_RXCRCR	SPI1_BASE + 0x14
#define __SPI1_TXCRCR	SPI1_BASE + 0x18
#define __SPI1_I2SCFGR	SPI1_BASE + 0x1C
#define __SPI1_I2SPR	SPI1_BASE + 0x20

#define _SPI1_CR1		ADR(__SPI1_CR1)
#define _SPI1_CR2		ADR(__SPI1_CR2)
#define _SPI1_SR       	ADR(__SPI1_SR)
#define _SPI1_DR		ADR(__SPI1_DR)
#define _SPI1_CRCPR		ADR(__SPI1_CRCPR)
#define _SPI1_RXCRCR   	ADR(__SPI1_RXCRCR)
#define _SPI1_TXCRCR	ADR(__SPI1_TXCRCR)
#define _SPI1_I2SCFGR  	ADR(__SPI1_I2SCFGR)
#define _SPI1_I2SPR		ADR(__SPI1_I2SPR)

#define SPI1_CR1		VAL(__SPI1_CR1)
#define SPI1_CR2		VAL(__SPI1_CR2)
#define SPI1_SR       	VAL(__SPI1_SR)
#define SPI1_DR			VAL(__SPI1_DR)
#define SPI1_CRCPR		VAL(__SPI1_CRCPR)
#define SPI1_RXCRCR   	VAL(__SPI1_RXCRCR)
#define SPI1_TXCRCR		VAL(__SPI1_TXCRCR)
#define SPI1_I2SCFGR  	VAL(__SPI1_I2SCFGR)
#define SPI1_I2SPR		VAL(__SPI1_I2SPR)

//SPi2 Register
#define __SPI2_CR1 		SPI2_BASE + 0x00
#define __SPI2_CR2		SPI2_BASE + 0x04
#define __SPI2_SR		SPI2_BASE + 0x08
#define __SPI2_DR		SPI2_BASE + 0x0C
#define __SPI2_CRCPR	SPI2_BASE + 0x10
#define __SPI2_RXCRCR	SPI2_BASE + 0x14
#define __SPI2_TXCRCR	SPI2_BASE + 0x18
#define __SPI2_I2SCFGR	SPI2_BASE + 0x1C
#define __SPI2_I2SPR	SPI2_BASE + 0x20

#define _SPI2_CR1		ADR(__SPI2_CR1)
#define _SPI2_CR2		ADR(__SPI2_CR2)
#define _SPI2_SR       	ADR(__SPI2_SR)
#define _SPI2_DR		ADR(__SPI2_DR)
#define _SPI2_CRCPR		ADR(__SPI2_CRCPR)
#define _SPI2_RXCRCR   	ADR(__SPI2_RXCRCR)
#define _SPI2_TXCRCR	ADR(__SPI2_TXCRCR)
#define _SPI2_I2SCFGR  	ADR(__SPI2_I2SCFGR)
#define _SPI2_I2SPR		ADR(__SPI2_I2SPR)

#define SPI2_CR1		VAL(__SPI2_CR1)
#define SPI2_CR2		VAL(__SPI2_CR2)
#define SPI2_SR       	VAL(__SPI2_SR)
#define SPI2_DR			VAL(__SPI2_DR)
#define SPI2_CRCPR		VAL(__SPI2_CRCPR)
#define SPI2_RXCRCR   	VAL(__SPI2_RXCRCR)
#define SPI2_TXCRCR		VAL(__SPI2_TXCRCR)
#define SPI2_I2SCFGR  	VAL(__SPI2_I2SCFGR)
#define SPI2_I2SPR		VAL(__SPI2_I2SPR)




//*******SPI control register 1 (SPI_CR1) (not used in I2S mode)******//
/*
SPI控制寄存器1
Address offset: 0x00
Reset value: 0x0000)
*/
/*
通信线数目选择(双线双向和单线双向)
Bit 15 BIDIMODE: Bidirectional data mode enable
0: 2-line unidirectional data mode selected
1: 1-line bidirectional data mode selected
Note: Not used in I2S mode
*/
void SPI1_set_BIDIMODE(U8 _2_1);

#define SPI1_set_conmunicate_with_2_lines()	SPI1_set_BIDIMODE(0)
#define SPI1_set_conmunicate_with_1_line() SPI1_set_BIDIMODE(1)

void SPI2_set_BIDIMODE(U8 _2_1);

#define SPI2_set_conmunicate_with_2_lines()	SPI2_set_BIDIMODE(0)
#define SPI2_set_conmunicate_with_1_line() SPI2_set_BIDIMODE(1)

/*
在单线时选择数据传输方向
Bit 14 BIDIOE: Output enable in bidirectional mode
This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
0: Output disabled (receive-only mode) 
1: Output enabled (transmit-only mode)
Note: In master mode, the MOSI pin is used and in slave mode, the MISO pin is used.
Not used in I2S mode
*/
void SPI1_set_BIDIOE(U8 e_d);

#define SPI1_set_receive_only_when_1_line()		SPI1_set_BIDIOE(0)
#define SPI1_set_transmit_only_when_1_line()    SPI1_set_BIDIOE(1)

void SPI2_set_BIDIOE(U8 e_d);

#define SPI2_set_receive_only_when_1_line()		SPI2_set_BIDIOE(0)
#define SPI2_set_transmit_only_when_1_line()    SPI2_set_BIDIOE(1)

/*
硬件CRC计算使能
Bit 13 CRCEN: Hardware CRC calculation enable
0: CRC calculation disabled
1: CRC calculation Enabled
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation
Not used in I2S mode
*/
void SPI1_set_CRCEN(U8 e_d);

#define SPI1_enable_CRC()	SPI1_set_CRCEN(1)	
#define SPI1_disable_CRC()  SPI1_set_CRCEN(0)

void SPI2_set_CRCEN(U8 e_d);

#define SPI2_enable_CRC()	SPI2_set_CRCEN(1)	
#define SPI2_disable_CRC()  SPI2_set_CRCEN(0)



/*
下一个将要传送的帧是CRC计算的结果还是发送缓冲器中的数据
Bit 12 CRCNEXT: Transmit CRC next
0: Next transmit value is from Tx buffer
1: Next transmit value is from Tx CRC register
Note: This bit has to be written as soon as the last data is written into the SPI_DR register.
Not used in I2S mode
*/
void SPI1_set_CRCNEXT(U8 n);

#define SPI1_set_next_value_frome_CRC_register()	SPI1_set_CRCNEXT(1)	

void SPI2_set_CRCNEXT(U8 n);

#define SPI2_set_next_value_frome_CRC_register()	SPI2_set_CRCNEXT(1)	


/*
数据帧长度选择
Bit 11 DFF: Data frame format
0: 8-bit data frame format is selected for transmission/reception
1: 16-bit data frame format is selected for transmission/reception
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation
Not used in I2S mode
*/
void SPI1_set_DFF(U8 _8_16)	;

#define SPI1_set_data_length_8_bit()	SPI1_set_DFF(0)	
#define SPI1_set_data_length_16_bit()   SPI1_set_DFF(1)

void SPI2_set_DFF(U8 _8_16)	;

#define SPI2_set_data_length_8_bit()	SPI2_set_DFF(0)	
#define SPI2_set_data_length_16_bit()   SPI2_set_DFF(1)

/*
在双线下使能只读模式
Bit 10 RXONLY: Receive only
This bit combined with the BIDImode bit selects the direction of transfer in 2-line 
unidirectional mode. This bit is also useful in a multislave system in which this particular 
slave is not accessed, the output from the accessed slave is not corrupted.
0: Full duplex (Transmit and receive)
1: Output disabled (Receive-only mode)
Note: Not used in I2S mode
*/
void SPI1_set_RXONLY(U8 e_d);

#define SPI1_set_full_duplex_when_2_lines()	SPI1_set_RXONLY(0)	
#define SPI1_set_receive_only_when_2_lines() SPI1_set_RXONLY(1)

void SPI2_set_RXONLY(U8 e_d);

#define SPI2_set_full_duplex_when_2_lines()	SPI2_set_RXONLY(0)	
#define SPI2_set_receive_only_when_2_lines() SPI2_set_RXONLY(1)

/*
软件从模式管理使能(使能该位后，NSS引脚的输入由软件设置(SSI位设置))
Bit 9 SSM: Software slave management
When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
0: Software slave management disabled
1: Software slave management enabled
Note: Not used in I2S mode
*/
void SPI1_set_SSM(U8 e_d);

#define SPI1_enable_software_slave_management()		SPI1_set_SSM(1)
#define SPI1_disable_software_slave_management()    SPI1_set_SSM(0)

void SPI2_set_SSM(U8 e_d);

#define SPI2_enable_software_slave_management()		SPI2_set_SSM(1)
#define SPI2_disable_software_slave_management()    SPI2_set_SSM(0)

/*
当软件从模式管理使能后，该位用来设置NSS引脚的输入
Bit 8 SSI: Internal slave select
This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the 
NSS pin and the IO value of the NSS pin is ignored.
Note: Not used in I2S mode
*/
void SPI1_set_SSI(U8 v);

#define SPI1_set_NSS_high()		SPI1_set_SSI(1)	//对于非多主模式，此位直接拉高就行
#define SPI1_set_NSS_low()    	SPI1_set_SSI(0) //对于主模式来说，此位不能拉低   对于从模式，就必须拉低了

#define SPI1_set_NSS_1()		SPI1_set_SSI(1)
#define SPI1_set_NSS_0()    	SPI1_set_SSI(0)

void SPI2_set_SSI(U8 v);

#define SPI2_set_NSS_high()		SPI2_set_SSI(1)	//对于非多主模式，此位直接拉高就行
#define SPI2_set_NSS_low()    	SPI2_set_SSI(0) //对于主模式来说，此位不能拉低   对于从模式，就必须拉低了

#define SPI2_set_NSS_1()		SPI2_set_SSI(1)
#define SPI2_set_NSS_0()    	SPI2_set_SSI(0)

/*
选择数据的传输方向 （LSB or MSB）
Bit 7 LSBFIRST: Frame format
0: MSB transmitted first
1: LSB transmitted first
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_LSBFIRST(U8 s);

#define SPI1_set_transmit_MSB_first()  SPI1_set_LSBFIRST(0)
#define SPI1_set_transmit_LSB_first()  SPI1_set_LSBFIRST(1)

void SPI2_set_LSBFIRST(U8 s);

#define SPI2_set_transmit_MSB_first()  SPI2_set_LSBFIRST(0)
#define SPI2_set_transmit_LSB_first()  SPI2_set_LSBFIRST(1)

/*
使能 除能 SPI
Bit 6 SPE: SPI enable
0: Peripheral disabled
1: Peripheral enabled
Note: 1- Not used in I2S mode.
Note: 2- When disabling the SPI, follow the procedure described in Section 24.3.8: Disabling the 
SPI.
*/
void SPI1_set_SPE(U8 e_d);

#define SPI1_enable_SPI()	SPI1_set_SPE(1)
#define SPI1_disable_SPI()  SPI1_set_SPE(0)

void SPI2_set_SPE(U8 e_d);

#define SPI2_enable_SPI()	SPI2_set_SPE(1)
#define SPI2_disable_SPI()  SPI2_set_SPE(0)

/*
设置SPI分频器对APB2总线时钟的分频系数
Bits 5:3 BR[2:0]: Baud rate control
000: fPCLK/2
001: fPCLK/4
010: fPCLK/8
011: fPCLK/16
100: fPCLK/32
101: fPCLK/64
110: fPCLK/128
111: fPCLK/256
Note: These bits should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_BR(U8 b);


#define SPI1_clock_division_is_2()		SPI1_set_BR(0)
#define SPI1_clock_division_is_4()		SPI1_set_BR(1)
#define SPI1_clock_division_is_8()		SPI1_set_BR(2)
#define SPI1_clock_division_is_16()		SPI1_set_BR(3)
#define SPI1_clock_division_is_32()		SPI1_set_BR(4)
#define SPI1_clock_division_is_64()		SPI1_set_BR(5)
#define SPI1_clock_division_is_128()	SPI1_set_BR(6)
#define SPI1_clock_division_is_256()	SPI1_set_BR(7)

void SPI2_set_BR(U8 b);


#define SPI2_clock_division_is_2()		SPI2_set_BR(0)
#define SPI2_clock_division_is_4()		SPI2_set_BR(1)
#define SPI2_clock_division_is_8()		SPI2_set_BR(2)
#define SPI2_clock_division_is_16()		SPI2_set_BR(3)
#define SPI2_clock_division_is_32()		SPI2_set_BR(4)
#define SPI2_clock_division_is_64()		SPI2_set_BR(5)
#define SPI2_clock_division_is_128()	SPI2_set_BR(6)
#define SPI2_clock_division_is_256()	SPI2_set_BR(7)



/*
主模式 从模式 选择
Bit 2 MSTR: Master selection 
0: Slave configuration
1: Master configuration
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_MSTR(U8 sel);

#define SPI1_set_master_mode()	SPI1_set_MSTR(1)
#define SPI1_set_slave_mode()   SPI1_set_MSTR(0)

void SPI2_set_MSTR(U8 sel);

#define SPI2_set_master_mode()	SPI2_set_MSTR(1)
#define SPI2_set_slave_mode()   SPI2_set_MSTR(0)

/*
时钟在空闲时的极性
Bit1 CPOL: Clock polarity 
0: CK to 0 when idle
1: CK to 1 when idle
Note: This bit should not be changed when communication is ongoing.
Not used in I2S mode
*/
void SPI1_set_CPOL(U8 p);

#define SPI1_clock_is_high_when_idle()	SPI1_set_CPOL(1)
#define SPI1_clock_is_low_when_idle()   SPI1_set_CPOL(0)

void SPI2_set_CPOL(U8 p);

#define SPI2_clock_is_high_when_idle()	SPI2_set_CPOL(1)
#define SPI2_clock_is_low_when_idle()   SPI2_set_CPOL(0)


/*
时钟的相位 当为一时，在时钟沿开始传输数据否则在第一个时钟沿传输数据(上下沿)
Bit 0 CPHA: Clock phase 
0: The first clock transition is the first data capture edge
1: The second clock transition is the first data capture edge
Note: This bit should not be changed when communication is ongoing.
Note: Not used in I2S mode
*/
void SPI1_set_CPHA(U8 f_s);

#define SPI1_capture_at_first_edge()	SPI1_set_CPHA(0)
#define SPI1_capture_at_second_edge()   SPI1_set_CPHA(1)

void SPI2_set_CPHA(U8 f_s);

#define SPI2_capture_at_first_edge()	SPI2_set_CPHA(0)
#define SPI2_capture_at_second_edge()   SPI2_set_CPHA(1)

//************SPI control register 2 (SPI_CR2)**********************//

/*
SPI控制器2  (中断相关)
SPI control register 2 (SPI_CR2)
Address offset: 0x04
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved. Forced to 0 by hardware.
*/

/*
当发送寄存器空的时候产生中断
Bit 7 TXEIE: Tx buffer empty interrupt enable
0: TXE interrupt masked 
1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
*/
void SPI1_set_TXEIE(U8 e_d);

#define SPI1_enable_interrupt_at_TX_buffer_empty()	SPI1_set_TXEIE(1)
#define SPI1_disable_interrupt_at_TX_buffer_empty() SPI1_set_TXEIE(0)

#define SPI1_enable_interrupt_at_transmit_over()	SPI1_set_TXEIE(1)
#define SPI1_disable_interrupt_at_transmit_over()   SPI1_set_TXEIE(0)

void SPI2_set_TXEIE(U8 e_d);

#define SPI2_enable_interrupt_at_TX_buffer_empty()	SPI2_set_TXEIE(1)
#define SPI2_disable_interrupt_at_TX_buffer_empty() SPI2_set_TXEIE(0)

#define SPI2_enable_interrupt_at_transmit_over()	SPI2_set_TXEIE(1)
#define SPI2_disable_interrupt_at_transmit_over()   SPI2_set_TXEIE(0)

/*
当接受寄存器非空时产生中断
Bit 6 RXNEIE: RX buffer not empty interrupt enable
0: RXNE interrupt masked 
1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is 
set.
*/
void SPI1_set_RXNEIE(U8 e_d);

#define SPI1_enable_interrupt_at_RX_buffer_not_empty()  SPI1_set_RXNEIE(1)
#define SPI1_disable_interrupt_at_RX_buffer_not_empty() SPI1_set_RXNEIE(0)

#define SPI1_enable_interrupt_at_receive_over()			SPI1_set_RXNEIE(1)	
#define SPI1_disable_interrupt_at_receive_over()	 	SPI1_set_RXNEIE(0)

void SPI1_set_RXNEIE(U8 e_d);

#define SPI2_enable_interrupt_at_RX_buffer_not_empty()  SPI2_set_RXNEIE(1)
#define SPI2_disable_interrupt_at_RX_buffer_not_empty() SPI2_set_RXNEIE(0)

#define SPI2_enable_interrupt_at_receive_over()			SPI2_set_RXNEIE(1)	
#define SPI2_disable_interrupt_at_receive_over()	 	SPI2_set_RXNEIE(0)

/*
Bit 5 ERRIE: Error interrupt enable
This bit controls the generation of an interrupt when an error condition occurs (CRCERR, 
OVR, MODF in SPI mode and UDR, OVR in I2S mode).
0: Error interrupt is masked
1: Error interrupt is enabled. 
*/
void SPI1_set_ERRIE(U8 e_d);

#define SPI1_enable_interrupt_at_error()	SPI1_set_ERRIE(1)
#define SPI1_disable_interrupt_at_error()   SPI1_set_ERRIE(0)

void SPI2_set_ERRIE(U8 e_d);

#define SPI2_enable_interrupt_at_error()	SPI2_set_ERRIE(1)
#define SPI2_disable_interrupt_at_error()   SPI2_set_ERRIE(0)
/*
Bits 4:3 Reserved. Forced to 0 by hardware.
*/

/*
在主模式下将NSS引脚配置成输出，以控制所有的从设备
Bit 2 SSOE: SS output enable
0: SS output is disabled in master mode and the cell can work in multimaster configuration
1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
in a multimaster environment.
Note: Not used in I2S mode
*/
void SPI1_set_SSOE(U8 e_d);

#define SPI1_set_SS_input_mode()	SPI1_set_SSOE(0)	
#define SPI1_set_SS_output_mode()   SPI1_set_SSOE(1)

void SPI2_set_SSOE(U8 e_d);

#define SPI2_set_SS_input_mode()	SPI2_set_SSOE(0)	
#define SPI2_set_SS_output_mode()   SPI2_set_SSOE(1)


/*
发送DMA使能(DMA会在发送一个帧后从指定的地方自动发送下一帧，而不需要CPU参与)
对于发送CRC校验帧则不需要手动设置CRCNEXT位，在所有给DMA指定的数据传输完之后，DMA自动发送CRC校验帧。
Bit 1 TXDMAEN: Tx buffer DMA enable
When this bit is set, the DMA request is made whenever the TXE flag is set.
0: Tx buffer DMA disabled
1: Tx buffer DMA enabled
*/
void SPI1_set_TXDMAEN(U8 e_d);

#define SPI1_enable_transmit_DMA()	SPI1_set_TXDMAEN(1)
#define SPI1_disable_tansmit_DMA()  SPI1_set_TXDMAEN(0)

void SPI2_set_TXDMAEN(U8 e_d);

#define SPI2_enable_transmit_DMA()	SPI2_set_TXDMAEN(1)
#define SPI2_disable_tansmit_DMA()  SPI2_set_TXDMAEN(0)


/*
接受DMA使能(DMA会在接收到一个数据后自动将该数据存到提前指定的地方，而不需要CPU参与)
Bit 0 RXDMAEN: Rx buffer DMA enable
When this bit is set, the DMA request is made whenever the RXNE flag is set.
0: Rx buffer DMA disabled
1: Rx buffer DMA enabled
*/
void SPI1_set_RXDMAEN(U8 e_d);

#define SPI1_enable_receive_DMA()	SPI1_set_RXDMAEN(1)
#define SPI1_disable_receive_DMA()  SPI1_set_RXDMAEN(0)

void SPI2_set_RXDMAEN(U8 e_d);

#define SPI2_enable_receive_DMA()	SPI2_set_RXDMAEN(1)
#define SPI2_disable_receive_DMA()  SPI2_set_RXDMAEN(0)


//*********************SPI status register (SPI_SR)**********************//


/*
SPI状态寄存器
SPI status register (SPI_SR)
Address offset: 0x08
Reset value: 0x0002
*/

/*
Bits 15:8 Reserved. Forced to 0 by hardware.
*/

/*
获取BSY位
Bit 7 BSY: Busy flag
0: SPI (or I2S) not busy
1: SPI (or I2S) is busy in communication or Tx buffer is not empty
This flag is set and cleared by hardware.
Note: BSY flag must be used with caution: refer to Section 24.3.7: Status flags and 
Section 24.3.8: Disabling the SPI.
*/
U8 SPI1_get_BSY(void);

#define SPI1_is_busy()	SPI1_get_BSY()
#define SPI1_get_busy_flag()	SPI1_get_BSY()

U8 SPI2_get_BSY(void);

#define SPI2_is_busy()	SPI2_get_BSY()
#define SPI2_get_busy_flag()	SPI2_get_BSY()

/*
覆盖标志
Bit 6 OVR: Overrun flag
0: No overrun occurred
1: Overrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.4.7 on 
page 692 for the software sequence.
*/
U8	SPI1_get_OVR(void);

#define SPI1_get_overrun_flag()	SPI1_get_OVR()
#define SPI1_is_overrun_occured()	SPI1_get_OVR()

#define SPI1_is_interrupted_by_overrun()	SPI1_get_OVR()

U8	SPI2_get_OVR(void);

#define SPI2_get_overrun_flag()	SPI2_get_OVR()
#define SPI2_is_overrun_occured()	SPI2_get_OVR()

#define SPI2_is_interrupted_by_overrun()	SPI2_get_OVR()


/*
主模式失败位, 本来配置成主模式的SPI设备的配置为非输出模式的NSS引脚被拉低时，
主模式会自动被清零，并进入从模式，同时产生主模式失败标志
Bit 5 MODF: Mode fault
0: No mode fault occurred
1: Mode fault occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.3.10 on 
page 674 for the software sequence.
Note: Not used in I2S mode
*/
U8 SPI1_get_MODF(void);

#define SPI1_get_mode_fault_flag()	SPI1_get_MODF()
#define SPI1_is_mode_fault_occured()	SPI1_get_MODF()

#define SPI1_is_interrupted_by_mode_fault()	SPI1_get_MODF()

U8 SPI2_get_MODF(void);

#define SPI2_get_mode_fault_flag()	SPI2_get_MODF()
#define SPI2_is_mode_fault_occured()	SPI2_get_MODF()

#define SPI2_is_interrupted_by_mode_fault()	SPI2_get_MODF()


/*
当自己计算的的CRC值和接收到的CRC校验值不同时，产生CRC error
Bit 4 CRCERR: CRC error flag
0: CRC value received matches the SPI_RXCRCR value
1: CRC value received does not match the SPI_RXCRCR value
This flag is set by hardware and cleared by software writing 0.
Note: Not used in I2S mode
*/
U8 SPI1_get_CRCERR(void);

#define SPI1_get_CRC_error_flag()	SPI1_get_CRCERR()
#define SPI1_is_CRC_error_occured()	SPI1_get_CRCERR()
#define SPI1_is_interrupted_by_CRC_error()	SPI1_get_CRCERR()

U8 SPI2_get_CRCERR(void);

#define SPI2_get_CRC_error_flag()	SPI2_get_CRCERR()
#define SPI2_is_CRC_error_occured()	SPI2_get_CRCERR()
#define SPI2_is_interrupted_by_CRC_error()	SPI2_get_CRCERR()


/*
I2S模式下
Bit 3 UDR: Underrun flag
0: No underrun occurred
1: Underrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 24.4.7 on 
page 692 for the software sequence.
Note: Not used in SPI mode
*/


/*
I2S模式下
Bit 2 CHSIDE: Channel side
0: Channel Left has to be transmitted or has been received
1: Channel Right has to be transmitted or has been received
Note: Not used for the SPI mode. No meaning in PCM mode
*/


/*
发送传送缓冲器为空
Bit 1 TXE: Transmit buffer empty
0: Tx buffer not empty
1: Tx buffer empty
*/
U8 SPI1_get_TXE(void);

#define SPI1_is_TX_buffer_emplty()		SPI1_get_TXE()
#define SPI1_is_transmit_buffer_empty()	SPI1_get_TXE()
#define SPI1_get_transmit_complete_flag()	SPI1_get_TXE()
#define SPI1_is_transmit_complete()			SPI1_get_TXE()
#define SPI1_is_interrupted_by_transmit_complete()	SPI1_get_TXE()

U8 SPI2_get_TXE(void);

#define SPI2_is_TX_buffer_emplty()		SPI2_get_TXE()
#define SPI2_is_transmit_buffer_empty()	SPI2_get_TXE()
#define SPI2_get_transmit_complete_flag()	SPI2_get_TXE()
#define SPI2_is_transmit_complete()			SPI2_get_TXE()
#define SPI2_is_interrupted_by_transmit_complete()	SPI2_get_TXE()



/*
接收传送缓冲器不为空
Bit 0 RXNE: Receive buffer not empty
0: Rx buffer empty
1: Rx buffer not empty
*/
U8 SPI1_get_RXNE(void);

#define SPI1_get_receive_complete_flag()

#define SPI1_is_RX_buffer_not_empty()	SPI1_get_RXNE()
#define SPI1_is_receive_complete()			SPI1_get_RXNE()

#define SPI1_is_interrupted_by_receive_complete()	SPI1_get_RXNE()

U8 SPI2_get_RXNE(void);

#define SPI2_get_receive_complete_flag()

#define SPI2_is_RX_buffer_not_empty()	SPI2_get_RXNE()
#define SPI2_is_receive_complete()			SPI2_get_RXNE()

#define SPI2_is_interrupted_by_receive_complete()	SPI2_get_RXNE()


//***********************88SPI data register (SPI_DR)*****************//

/*
发送数据寄存器(通过读写操作区分)
Bits 15:0 DR[15:0]: Data register
Data received or to be transmitted.
The data register is split into 2 buffers - one for writing (Transmit Buffer) and another one for 
reading (Receive buffer). A write to the data register will write into the Tx buffer and a read 
from the data register will return the value held in the Rx buffer.
Notes for the SPI mode:
Depending on the data frame format selection bit (DFF in SPI_CR1 register), the data 
sent or received is either 8-bit or 16-bit. This selection has to be made before enabling 
the SPI to ensure correct operation. 
For an 8-bit data frame, the buffers are 8-bit and only the LSB of the register 
(SPI_DR[7:0]) is used for transmission/reception. When in reception mode, the MSB of 
the register (SPI_DR[15:8]) is forced to 0.
For a 16-bit data frame, the buffers are 16-bit and the entire register, SPI_DR[15:0] is 
used for transmission/reception.
*/
void SPI1_set_DR(U16 data);

#define SPI1_send_data(data)	SPI1_set_DR(data)

U16 SPI1_get_DR(void);

#define SPI1_receive_data()		SPI1_get_DR()

void SPI2_set_DR(U16 data);

#define SPI2_send_data(data)	SPI2_set_DR(data)

U16 SPI2_get_DR(void);

#define SPI2_receive_data()		SPI2_get_DR()



//****SPI CRC polynomial register (SPI_CRCPR)*********//
/*
SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode)
Address offset: 0x10
Reset value: 0x0007
*/
/*
CRC的计算公式设置
Bits 15:0 CRCPOLY[15:0]: CRC polynomial register
This register contains the polynomial for the CRC calculation.
The CRC polynomial (0007h) is the reset value of this register. Another polynomial can be 
configured as required.
Note: Not used for the I2S mode.
*/ 
void SPI1_set_CRCPOLY(U16 poly);

#define SPI1_set_CRC_polynomial(p)	SPI1_set_CRCPOLY(p)	

void SPI2_set_CRCPOLY(U16 poly);

#define SPI2_set_CRC_polynomial(p)	SPI2_set_CRCPOLY(p)	


//****SPI Rx CRC register (SPI_RXCRCR) (not used in I2S mode)***********//

/*
SPI Rx CRC register (SPI_RXCRCR) (not used in I2S mode)
Address offset: 0x14
Reset value: 0x0000
*/
/*
接收帧数据计算的CRC校验值
RXCRC[15:0]: Rx CRC register
When CRC calculation is enabled, the RxCRC[15:0] bits contain the computed CRC value of 
the subsequently received bytes. This register is reset when the CRCEN bit in SPI_CR1 
register is written to 1. The CRC is calculated serially using the polynomial programmed in 
the SPI_CRCPR register. 
Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF 
bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
The entire 16-bits of this register are considered when a 16-bit data frame format is selected 
(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16 
standard.
Note: A read to this register when the BSY Flag is set could return an incorrect value.
Not used for the I2S mode.
*/

U16 SPI1_get_RXCRC(void);

#define SPI1_get_receive_CRC_value()	SPI1_get_RXCRC()

U16 SPI2_get_RXCRC(void);

#define SPI2_get_receive_CRC_value()	SPI2_get_RXCRC()


//****8SPI Tx CRC register (SPI_TXCRCR) (not used in I2S mode)**********//
/*
发送数据计算的CRC校验值
SPI Tx CRC register (SPI_TXCRCR) (not used in I2S mode)
Address offset: 0x18
Reset value: 0x0000
*/
/*
Bits 15:0 TxCRC[15:0]: Tx CRC register
When CRC calculation is enabled, the TxCRC[7:0] bits contain the computed CRC value of 
the subsequently transmitted bytes. This register is reset when the CRCEN bit of SPI_CR1 
is written to 1. The CRC is calculated serially using the polynomial programmed in the 
SPI_CRCPR register.
Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF 
bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
The entire 16-bits of this register are considered when a 16-bit data frame format is selected 
(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16 
standard.
Note: A read to this register when the BSY flag is set could return an incorrect value.
Not used for the I2S mode.
*/
U16 SPI1_get_TXCRC(void);

#define SPI1_get_transmit_CRC_value()	SPI1_get_TXCRC()

U16 SPI2_get_TXCRC(void);

#define SPI2_get_transmit_CRC_value()	SPI2_get_TXCRC()

#endif
