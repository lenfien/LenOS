

#ifndef BASE_I2C
#define BASE_I2C

#include "core_map.h"
#include "com.h"

//*****************************************************//
//*****************I2C1寄存器定义**********************//
//*****************************************************//
#define __I2C1_CR1		(I2C1_BASE + 0x00)
#define __I2C1_CR2		(I2C1_BASE + 0x04)
#define __I2C1_OAR1		(I2C1_BASE + 0x08)
#define __I2C1_OAR2		(I2C1_BASE + 0x0C)
#define __I2C1_DR		(I2C1_BASE + 0x10)
#define __I2C1_SR1		(I2C1_BASE + 0x14)
#define __I2C1_SR2		(I2C1_BASE + 0x18)
#define __I2C1_CCR		(I2C1_BASE + 0x1C)
#define __I2C1_TRISE	(I2C1_BASE + 0x20)

#define _I2C1_CR1		ADR(__I2C1_CR1)	
#define _I2C1_CR2		ADR(__I2C1_CR2)		
#define _I2C1_OAR1		ADR(__I2C1_OAR1)		
#define _I2C1_OAR2		ADR(__I2C1_OAR2)
#define _I2C1_DR		ADR(__I2C1_DR)
#define _I2C1_SR1		ADR(__I2C1_SR1)
#define _I2C1_SR2		ADR(__I2C1_SR2)
#define _I2C1_CCR		ADR(__I2C1_CCR)
#define _I2C1_TRISE		ADR(__I2C1_TRISE)

#define I2C1_CR1		VAL(__I2C1_CR1)	
#define I2C1_CR2		VAL(__I2C1_CR2)		
#define I2C1_OAR1		VAL(__I2C1_OAR1)		
#define I2C1_OAR2		VAL(__I2C1_OAR2)
#define I2C1_DR			VAL(__I2C1_DR)
#define I2C1_SR1		VAL(__I2C1_SR1)
#define I2C1_SR2		VAL(__I2C1_SR2)
#define I2C1_CCR		VAL(__I2C1_CCR)
#define I2C1_TRISE		VAL(__I2C1_TRISE)

//*****************************************************//
//*****************I2C2寄存器定义**********************//
//*****************************************************//
#define __I2C2_CR1		(I2C2_BASE + 0x00)
#define __I2C2_CR2		(I2C2_BASE + 0x04)
#define __I2C2_OAR1		(I2C2_BASE + 0x08)
#define __I2C2_OAR2		(I2C2_BASE + 0x0C)
#define __I2C2_DR		(I2C2_BASE + 0x10)
#define __I2C2_SR1		(I2C2_BASE + 0x14)
#define __I2C2_SR2		(I2C2_BASE + 0x18)
#define __I2C2_CCR		(I2C2_BASE + 0x1C)
#define __I2C2_TRISE	(I2C2_BASE + 0x20)

#define _I2C2_CR1		ADR(__I2C2_CR1)	
#define _I2C2_CR2		ADR(__I2C2_CR2)		
#define _I2C2_OAR1		ADR(__I2C2_OAR1)		
#define _I2C2_OAR2		ADR(__I2C2_OAR2)
#define _I2C2_DR		ADR(__I2C2_DR)
#define _I2C2_SR1		ADR(__I2C2_SR1)
#define _I2C2_SR2		ADR(__I2C2_SR2)
#define _I2C2_CCR		ADR(__I2C2_CCR)
#define _I2C2_TRISE		ADR(__I2C2_TRISE)

#define I2C2_CR1		VAL(__I2C2_CR1)	
#define I2C2_CR2		VAL(__I2C2_CR2)		
#define I2C2_OAR1		VAL(__I2C2_OAR1)		
#define I2C2_OAR2		VAL(__I2C2_OAR2)
#define I2C2_DR			VAL(__I2C2_DR)
#define I2C2_SR1		VAL(__I2C2_SR1)
#define I2C2_SR2		VAL(__I2C2_SR2)
#define I2C2_CCR		VAL(__I2C2_CCR)
#define I2C2_TRISE		VAL(__I2C2_TRISE)


//*********************************************************************************//
//***************************Control register 1 (I2C_CR1)**************************//
//*********************************************************************************//

/*
Control register 1 (I2C_CR1)
Address offset: 0x00
Reset value: 0x0000
*/

/*
Bit 15 SWRST: Software reset
When set, the I2C is under reset state. Before resetting this bit, make sure the I2C lines are 
released and the bus is free.
0: I2C Peripheral not under reset
1: I2C Peripheral under reset state
Note: This bit can be used in case the BUSY bit is set to ‘1 when no stop condition has been 
detected on the bus.
*/
void I2C1_set_SWRST(U8 s);

#define I2C1_reset()	I2C1_set_SWRST(1)	

/*
Bit 14 Reserved, forced by hardware to 0. 
*/

/*
Bit 13 ALERT: SMBus alert
This bit is set and cleared by software, and cleared by hardware when PE=0.
0: Releases SMBA pin high. Alert Response Address Header followed by NACK.
1: Drives SMBA pin low. Alert Response Address Header followed by ACK.
*/


/*
Bit 12 PEC: Packet error checking
This bit is set and cleared by software, and cleared by hardware when PEC is transferred or 
by a START or Stop condition or when PE=0.
0: No PEC transfer
1: PEC transfer (in Tx or Rx mode)
Note: PEC calculation is corrupted by an arbitration loss.
*/


/*
Bit 11 POS: Acknowledge/PEC Position (for data reception)
This bit is set and cleared by software and cleared by hardware when PE=0.
0: ACK bit controls the (N)ACK of the current byte being received in the shift register. The 
PEC bit indicates that current byte in shift register is a PEC.
1: ACK bit controls the (N)ACK of the next byte which will be received in the shift register. 
The PEC bit indicates that the next byte in the shift register is a PEC
Note: The POS bit is used when the procedure for reception of 2 bytes (see Method 2: 
transfer sequence diagram for master receiver when N=2) is followed. It must be 
configured before data reception starts. In this case, to NACK the 2nd byte, the ACK bit 
must be cleared just after ADDR is cleared. 
*/


/*
Bit 10 ACK: Acknowledge enable
This bit is set and cleared by software and cleared by hardware when PE=0.
0: No acknowledge returned
1: Acknowledge returned after a byte is received (matched address or data)
*/
void I2C1_set_ACK(U8 a);

#define I2C1_enable_acknowledge()	I2C1_set_ACK(1)
#define I2C1_disable_acknowledge()	I2C1_set_ACK(0)

/*
Bit 9 STOP: Stop generation
The bit is set and cleared by software, cleared by hardware when a Stop condition is 
detected, set by hardware when a timeout error is detected.
In Master Mode:
0: No Stop generation.
1: Stop generation after the current byte transfer or after the current Start condition is sent.
In Slave mode:
0: No Stop generation.
1: Release the SCL and SDA lines after the current byte transfer. 
Note: When the STOP, START or PEC bit is set, the software must not perform any write 
access to I2C_CR1 before this bit is cleared by hardware. Otherwise there is a risk of 
setting a second STOP, START or PEC request.
*/
void I2C1_set_STOP(U8 s);

#define I2C1_generate_stop()	I2C1_set_STOP(1)	//对于主模式
#define I2C1_release_bus()		I2C1_set_STOP(1)	//对于从模式

/*
Bit 8 START: Start generation
This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
In Master Mode:
0: No Start generation
1: Repeated start generation
In Slave mode:
0: No Start generation
1: Start generation when the bus is free
*/
void I2C1_set_START(U8 s);

#define I2C1_generate_start()	I2C1_set_START(1)
/*
Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until 
it is reset by software.
0: Clock stretching enabled
1: Clock stretching disabled
*/


/*
Bit 6 ENGC: General call enable
0: General call disabled. Address 00h is NACKed.
1: General call enabled. Address 00h is ACKed.
*/


/*
Bit 5 ENPEC: PEC enable
0: PEC calculation disabled
1: PEC calculation enabled
*/



/*
Bit 4 ENARP: ARP enable
0: ARP disable
1: ARP enable
SMBus Device default address recognized if SMBTYPE=0
SMBus Host address recognized if SMBTYPE=1
*/

/*
Bit 3 SMBTYPE: SMBus type
0: SMBus Device
1: SMBus Host
*/

/*
Bit 2 Reserved, forced by hardware to 0. 
*/

/*
Bit 1 SMBUS: SMBus mode
0: I2C mode
1: SMBus mode
*/

/*
Bit 0 PE: Peripheral enable
0: Peripheral disable
1: Peripheral enable: the corresponding IOs are selected as alternate functions depending 
on SMBus bit.
Note: If this bit is reset while a communication is on going, the peripheral is disabled at the 
end of the current communication, when back to IDLE state. 
*/
void I2C1_set_PE(U8 p);
	
#define I2C1_enable_peripheral()	I2C1_set_PE(1)
#define I2C1_disable_peripheral()	I2C1_set_PE(0)

/*
All bit resets due to PE=0 occur at the end of the communication.
In master mode, this bit must not be reset before the end of the communication.
*/


//********************************************************************//
//**********************Control register 2 (I2C_CR2)******************//
//********************************************************************//
/*
Control register 2 (I2C_CR2)
Address offset: 0x04
Reset value: 0x0000
*/

/*Bits 15:13 Reserved, forced by hardware to 0.
*/

/*
Bit 12 LAST: DMA last transfer
0: Next DMA EOT is not the last transfer
1: Next DMA EOT is the last transfer
Note: This bit is used in master receiver mode to permit the generation of a NACK on the last 
received data.
*/


/*
Bit 11 DMAEN: DMA requests enable
0: DMA requests disabled
1: DMA request enabled when TxE=1 or RxNE =1
*/

/*
Bit 10 ITBUFEN: Buffer interrupt enable
0: TxE = 1 or RxNE = 1 does not generate any interrupt.
1:TxE = 1 or RxNE = 1 generates Event Interrupt (whatever the state of DMAEN)
*/
void I2C1_set_ITBUFEN(U8 i);

#define I2C1_enable_interrupt_at_buffer()	I2C1_set_ITBUFEN(1)
#define I2C1_disable_interrupt_at_buffer()	I2C1_set_ITBUFEN(0)

/*
Bit 9 ITEVTEN: Event interrupt enable
0: Event interrupt disabled
1: Event interrupt enabled
This interrupt is generated when:
–SB = 1 (Master)
–ADDR = 1 (Master/Slave)
–ADD10= 1 (Master)
–STOPF = 1 (Slave)
–BTF = 1 with no TxE or RxNE event
–TxE event to 1 if ITBUFEN = 1
–RxNE event to 1 if ITBUFEN = 1
*/
void I2C1_set_ITEVTEN(U8 i);

#define I2C1_enable_interrupt_at_event()	I2C1_set_ITEVTEN(1)
#define I2C1_disable_interrupt_at_event()	I2C1_set_ITEVTEN(0)

/*
Bit 8 ITERREN: Error interrupt enable
0: Error interrupt disabled
1: Error interrupt enabled
This interrupt is generated when:
–BERR = 1
–ARLO = 1
–AF = 1
–OVR = 1
–PECERR = 1
–TIMEOUT = 1
–SMBALERT = 1
*/
void I2C1_set_ITERREN(U8 i);

#define I2C1_enable_interrupt_ITERREN()		I2C1_set_ITERREN(1)
#define I2C1_disable_interrupt_ITERREN()	I2C1_set_ITERREN(0)

/*
Bits 7:6 Reserved, forced by hardware to 0.
*/

/*
Bits 5:0 FREQ[5:0]: Peripheral clock frequency
The peripheral clock frequency must be configured using the input APB clock frequency (I2C 
peripheral connected to APB). The minimum allowed frequency is 2 MHz, the maximum 
frequency is limited by the maximum APB frequency (36 MHz) and an intrinsic limitation of 
46 MHz.
0b000000: Not allowed
0b000001: Not allowed
0b000010: 2 MHz
...
0b100100: 36 MHz
Higher than 0b100100: Not allowed
*/
void I2C1_set_FREQ(U8 f);
	
#define I2C1_set_prequency_MHZ(m)	I2C1_set_FREQ(m)

//*********************************************************************//
//**********************Own address register 1 (I2C_OAR1)**************//
//*********************************************************************//

/*
Own address register 1 (I2C_OAR1)
Address offset: 0x08
Reset value: 0x0000
*/

/*
Bit 15 ADDMODE Addressing mode (slave mode)
0: 7-bit slave address (10-bit address not acknowledged)
1: 10-bit slave address (7-bit address not acknowledged)
*/
void I2C1_set_ADDMODE(U8 a);

#define I2C1_set_address_mode_7_bit()	I2C1_set_ADDMODE(0)
#define I2C1_set_address_mode_11_bit()	I2C1_set_ADDMODE(1)

/*
Bit 14
Should always be kept at 1 by software.
*/
void I2C1_set_bit14(void);

#define I2C1_set_neccessary()	I2C1_set_bit14()

/*
Bits 13:10 Reserved, forced by hardware to 0.
*/

/*
Bits 9:8 ADD[9:8]: Interface address
7-bit addressing mode: don’t care
10-bit addressing mode: bits9:8 of address
*/


/*
Bits 7:1 ADD[7:1]: Interface address
bits 7:1 of address
*/
void I2C1_set_ADD_7to1(U8 a);

#define I2C1_set_address_7to1(a)	I2C1_set_ADD_7to1(a)

/*
Bit 0 ADD0: Interface address
7-bit addressing mode: don’t care
10-bit addressing mode: bit 0 of address
*/
void I2C1_set_ADD0(U8 a);



//**********************************************************************//
//***********************Own address register 2 (I2C_OAR2)**************//
//**********************************************************************//

/*
Own address register 2 (I2C_OAR2)
Address offset: 0x0C
Reset value: 0x0000
*/
/*
Bits 15:8 Reserved, forced by hardware to 0.
*/

/*
Bits 7:1 ADD2[7:1]: Interface address
bits 7:1 of address in dual addressing mode
*/
void I2C1_set_ADD2(U8 a);

/*
Bit 0 ENDUAL: Dual addressing mode enable
0: Only OAR1 is recognized in 7-bit addressing mode
1: Both OAR1 and OAR2 are recognized in 7-bit addressing mode
*/
void I2C1_set_ENDUAL(U8 e);


//********************************************************************//
//************************Data register (I2C_DR)**********************//
//********************************************************************//

/*
Data register (I2C_DR)
Address offset: 0x10
Reset value: 0x0000
*/

/*
Bits 15:8 Reserved, forced by hardware to 0.
*/

/*
Bits 7:0 DR[7:0] 8-bit data register
Byte received or to be transmitted to the bus.
–Transmitter mode: Byte transmission starts automatically when a byte is written in the DR 
register. A continuous transmit stream can be maintained if the next data to be transmitted 
is put in DR once the transmission is started (TxE=1)
–Receiver mode: Received byte is copied into DR (RxNE=1). A continuous transmit stream 
can be maintained if DR is read before the next data byte is received (RxNE=1).
Note: In slave mode, the address is not copied into DR.
Note: Write collision is not managed (DR can be written if TxE=0).
Note: If an ARLO event occurs on ACK pulse, the received byte is not copied into DR and so 
cannot be read.
*/
void I2C1_set_DR(U8 d);
U8	I2C1_get_DR(void);
void I2C1_set_address(U8 add, U8 send_read);

#define I2C1_send_data(d)		I2C1_set_DR(d)
#define I2C1_get_data()			I2C1_get_DR()

#define I2C1_send_address_send(add)			I2C1_set_address(add, 0)
#define I2C1_send_address_receive(add)	I2C1_set_address(add, 1)

//********************************************************************************//
//************************Status register 1 (I2C_SR1)*****************************//
//********************************************************************************//

/*
Status register 1 (I2C_SR1)
Address offset: 0x14
Reset value: 0x0000
*/

/*
Bit 15 SMBALERT: SMBus alert 
In SMBus host mode:
0: no SMBALERT
1: SMBALERT event occurred on pin
In SMBus slave mode:
0: no SMBALERT response address header
1: SMBALERT response address header to SMBALERT LOW received
– Cleared by software writing 0, or by hardware when PE=0.
*/

/*
Bit 14 TIMEOUT: Timeout or Tlow error 
0: No timeout error
1: SCL remained LOW for 25 ms (Timeout)
or
Master cumulative clock low extend time more than 10 ms (Tlow:mext)
or
Slave cumulative clock low extend time more than 25 ms (Tlow:sext)
– When set in slave mode: slave resets the communication and lines are released by hardware
– When set in master mode: Stop condition sent by hardware
– Cleared by software writing 0, or by hardware when PE=0.
Note: This functionality is available only in SMBus mode.
*/
U8 I2C1_get_TIMEOUT(void);


/*
Bit 13 Reserved, forced by hardware to 0.
*/

/*
Bit 12 PECERR: PEC Error in reception 
0: no PEC error: receiver returns ACK after PEC reception (if ACK=1)
1: PEC error: receiver returns NACK after PEC reception (whatever ACK)
–Cleared by software writing 0, or by hardware when PE=0.
*/


/*
Bit 11 OVR: Overrun/Underrun 
0: No overrun/underrun
1: Overrun or underrun 
–Set by hardware in slave mode when NOSTRETCH=1 and:
–In reception when a new byte is received (including ACK pulse) and the DR register has not 
been read yet. New received byte is lost.
–In transmission when a new byte should be sent and the DR register has not been written 
yet. The same byte is sent twice.
–Cleared by software writing 0, or by hardware when PE=0.
Note: If the DR write occurs very close to SCL rising edge, the sent data is unspecified and a 
hold timing error occurs
*/
U8 I2C1_get_OVR(void);
void I2C1_clear_OVR(void);

#define I2C1_get_overrun_flag()		I2C1_get_OVR()
#define I2C1_clear_overrun_flag()	I2C1_clear_OVR()

/*
Bit 10 AF: Acknowledge failure
0: No acknowledge failure
1: Acknowledge failure
–Set by hardware when no acknowledge is returned. 
–Cleared by software writing 0, or by hardware when PE=0.
*/
U8 I2C1_get_AF(void);
void I2C1_clear_AF(void);

#define I2C1_get_acknowledge_failure_flag()		I2C1_get_AF()
#define I2C1_clear_acknowledge_failure_flag()	I2C1_clear_AF()

/*
Bit 9 ARLO: Arbitration lost (master mode) 
0: No Arbitration Lost detected
1: Arbitration Lost detected
Set by hardware when the interface loses the arbitration of the bus to another master
–Cleared by software writing 0, or by hardware when PE=0.
After an ARLO event the interface switches back automatically to Slave mode (M/SL=0). 
Note: In SMBUS, the arbitration on the data in slave mode occurs only during the data phase, 
or the acknowledge transmission (not on the address acknowledge).
*/


/*
Bit 8 BERR: Bus error 
0: No misplaced Start or Stop condition
1: Misplaced Start or Stop condition
–Set by hardware when the interface detects a misplaced Start or Stop condition 
–Cleared by software writing 0, or by hardware when PE=0.
*/
U8 I2C1_get_BERR(void);
void I2C1_clear_BERR(void);


/*
Bit 7 TxE: Data register empty (transmitters) 
0: Data register not empty
1: Data register empty
–Set when DR is empty in transmission. TxE is not set during address phase.
–Cleared by software writing to the DR register or by hardware after a start or a stop 
condition or when PE=0.
TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
Note: TxE is not cleared by writing the first data being transmitted, or by writing data when 
BTF is set, as in both cases the data register is still empty.
*/
U8 I2C1_get_TxE(void);

#define I2C1_is_data_register_empty()			I2C1_get_TxE()
#define I2C1_get_data_register_empty_flag()		I2C1_get_TxE()

#define I2C1_is_data_sent()						I2C1_get_TxE()
/*
Bit 6 RxNE: Data register not empty (receivers)
0: Data register empty
1: Data register not empty
–Set when data register is not empty in receiver mode. RxNE is not set during address 
phase.
–Cleared by software reading or writing the DR register or by hardware when PE=0.
RxNE is not set in case of ARLO event.
Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
*/
U8 I2C1_get_RxNE(void);

#define I2C1_is_data_register_full()	I2C1_get_RxNE()
#define I2C1_get_data_register_full_flag()	I2C1_get_RxNE()

#define I2C1_is_data_received()			I2C1_get_RxNE()
/*
Bit 5 Reserved, forced by hardware to 0.
*/

/*
Bit 4 STOPF: Stop detection (slave mode) 
0: No Stop condition detected
1: Stop condition detected
–Set by hardware when a Stop condition is detected on the bus by the slave after an 
acknowledge (if ACK=1). 
–Cleared by software reading the SR1 register followed by a write in the CR1 register, or by 
hardware when PE=0
Note: The STOPF bit is not set after a NACK reception
*/
U8	I2C1_get_STOPF(void);

#define I2C1_get_stop_flag()	I2C1_get_STOPF()

/*
Bit 3 ADD10: 10-bit header sent (Master mode) 
0: No ADD10 event occurred.
1: Master has sent first address byte (header).
–Set by hardware when the master has sent the first byte in 10-bit address mode. 
–Cleared by software reading the SR1 register followed by a write in the DR register of the 
second address byte, or by hardware when PE=0.
Note: ADD10 bit is not set after a NACK reception
*/


/*
Bit 2 BTF: Byte transfer finished
0: Data byte transfer not done
1: Data byte transfer succeeded
–Set by hardware when NOSTRETCH=0 and: 
–In reception when a new byte is received (including ACK pulse) and DR has not been 
read yet (RxNE=1).
–In transmission when a new byte should be sent and DR has not been written yet 
(TxE=1). 
–Cleared by software reading SR1 followed by either a read or write in the DR register or 
by hardware after a start or a stop condition in transmission or when PE=0.
Note: The BTF bit is not set after a NACK reception
The BTF bit is not set if next byte to be transmitted is the PEC (TRA=1 in I2C_SR2 
register and PEC=1 in I2C_CR1 register)
*/
U8	I2C1_get_BTF(void);

#define I2C1_is_transfer_finish()			I2C1_get_BTF()
#define I2C1_get_transfer_finish_flag()		I2C1_get_BTF()

/*
Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
This bit is cleared by software reading SR1 register followed reading SR2, or by hardware 
when PE=0.
Address matched (Slave)
0: Address mismatched or not received.
1: Received address matched.
–Set by hardware as soon as the received slave address matched with the OAR registers 
content or a general call or a SMBus Device Default Address or SMBus Host or SMBus 
Alert is recognized. (when enabled depending on configuration).
Address sent (Master)
0: No end of address transmission
1: End of address transmission
–For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
–For 7-bit addressing, the bit is set after the ACK of the byte.
Note: ADDR is not set after a NACK reception
*/
U8 I2C1_get_ADDR(void);

#define I2C1_get_address_send_flag()	I2C1_get_ADDR()
#define I2C1_is_address_sent()			I2C1_get_ADDR()

/*
Bit 0 SB: Start bit (Master mode)
0: No Start condition
1: Start condition generated.
–Set when a Start condition generated.
–Cleared by software by reading the SR1 register followed by writing the DR register, or by 
hardware when PE=0
*/
U8 I2C1_get_SB(void);

#define I2C1_is_start_generated()	I2C1_get_SB()

//******************************************************************************//
//************************Status register 2 (I2C_SR2)***************************//
//******************************************************************************//

/*
Status register 2 (I2C_SR2)
Address offset: 0x18
Reset value:0x0000
*/

/*
Bits 15:8 PEC[7:0] Packet error checking register
This register contains the internal PEC when ENPEC=1. 
*/

/*
Bit 7 DUALF: Dual flag (Slave mode)
0: Received address matched with OAR1
1: Received address matched with OAR2
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 6 SMBHOST: SMBus host header (Slave mode)
0: No SMBus Host address
1: SMBus Host address received when SMBTYPE=1 and ENARP=1.
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 5 SMBDEFAULT: SMBus device default address (Slave mode) 
0: No SMBus Device Default address
1: SMBus Device Default address received when ENARP=1
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 4 GENCALL: General call address (Slave mode) 
0: No General Call
1: General Call Address received when ENGC=1
–Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.
*/

/*
Bit 3 Reserved, forced by hardware to 0.
*/

/*
Bit 2 TRA: Transmitter/receiver
0: Data bytes received
1: Data bytes transmitted
This bit is set depending on the R/W bit of the address byte, at the end of total address 
phase.
It is also cleared by hardware after detection of Stop condition (STOPF=1), repeated Start 
condition, loss of bus arbitration (ARLO=1), or when PE=0.
*/
U8 I2C1_get_TRA(void);

#define I2C1_is_transmitter()	I2C1_get_TRA()		
#define I2C1_is_receiver()		(!I2C1_get_TRA())	

/*
Bit 1 BUSY: Bus busy
0: No communication on the bus
1: Communication ongoing on the bus
–Set by hardware on detection of SDA or SCL low 
–cleared by hardware on detection of a Stop condition. 
It indicates a communication in progress on the bus. This information is still updated when 
the interface is disabled (PE=0).
*/
U8 I2C1_get_BUSY(void);

#define I2C1_get_busy_flag()	I2C1_get_BUSY()
#define I2C1_is_busy()			I2C1_get_BUSY()

/*
Bit 0 MSL: Master/slave
0: Slave Mode
1: Master Mode
–Set by hardware as soon as the interface is in Master mode (SB=1). 
–Cleared by hardware after detecting a Stop condition on the bus or a loss of arbitration 
(ARLO=1), or by hardware when PE=0. 
*/
U8 I2C1_get_MSL(void);

#define I2C1_is_master()	I2C1_get_MSL()
#define I2C1_is_slaver()	(!I2C1_get_MSL())

//********************************************************************//
//********************Clock control register (I2C_CCR)****************//
//********************************************************************//

/*
Clock control register (I2C_CCR)
Address offset: 0x1C
Reset value: 0x0000
Note:
1FPCLK1 is the multiple of 10 MHz required to generate the Fast clock at 400 kHz.
2The CCR register must be configured only when the I2C is disabled (PE = 0).
*/

/*
Bit 15 F/S: I2C master mode selection 
0: Standard Mode I2C
1: Fast Mode I2C
*/
void I2C1_set_FS(U8 f);

#define I2C1_set_standard_mode()	I2C1_set_FS(0)
#define I2C1_set_fast_mode()		I2C1_set_FS(1)
/*
Bit 14 DUTY: Fast mode duty cycle 
0: Fast Mode tlow/thigh = 2
1: Fast Mode tlow/thigh = 16/9 (see CCR)
*/

/*
Bits 13:12 Reserved, forced by hardware to 0.
*/

/*
Bits 11:0 CCR[11:0]: 
Clock control register in Fast/Standard mode (Master mode) 
Controls the SCL clock in master mode.
Standard mode or SMBus:
Thigh = CCR * TPCLK1
Tlow = CCR * TPCLK1
Fast mode:
If DUTY = 0:
Thigh = CCR * TPCLK1
Tlow = 2 * CCR * TPCLK1
If DUTY = 1: (to reach 400 kHz)
Thigh = 9 * CCR * TPCLK1
Tlow = 16 * CCR * TPCLK1
For instance: in standard mode, to generate a 100 kHz SCL frequency: 
If FREQR = 08, TPCLK1 = 125 ns so CCR must be programmed with 0x28
(0x28 <=> 40d x 125 ns = 5000 ns.)
Note: 1. The minimum allowed value is 0x04, except in FAST DUTY mode where the 
minimum allowed value is 0x01
2. thigh = tr(SCL) + tw(SCLH). See device datasheet for the definitions of parameters
3. tlow = tf(SCL) + tw(SCLL). See device datasheet for the definitions of parameters
4. These timings are without filters.
5. The CCR register must be configured only when the I2C is disabled (PE = 0).
*/
void I2C1_set_CCR(U32 c);

#define I2C1_set_clock(c)	I2C1_set_CCR(c)


//*******************************************************************//
//********************TRISE register (I2C_TRISE)*********************//
//*******************************************************************//
/*
TRISE register (I2C_TRISE)
Address offset: 0x20
Reset value: 0x0002
*/

/*
Bits 5:0 TRISE[5:0]: Maximum rise time in Fast/Standard mode (Master mode)
These bits must be programmed with the maximum SCL rise time given in the I2C bus 
specification, incremented by 1.
For instance: in standard mode, the maximum allowed SCL rise time is 1000 ns.
If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns 
therefore the TRISE[5:0] bits must be programmed with 09h.
(1000 ns / 125 ns = 8 + 1)
The filter value can also be added to TRISE[5:0].
If the result is not an integer, TRISE[5:0] must be programmed with the integer part, in order 
to respect the tHIGH parameter.
Note: TRISE[5:0] must be configured only when the I2C is disabled (PE = 0).
*/
void I2C1_set_TRISE(U8 t);

#define I2C1_set_rise_time(t)	I2C1_set_TRISE(t)

#endif
