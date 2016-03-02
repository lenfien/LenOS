
#ifndef __FSMC
#define __FSMC

#include "core_map.h"
#include "com.h"

//Nor/PSRAM控制寄存器
#define __FSMC_BCR1 	FSMC_Bank1_R_BASE + 0x00000000  	//块1 0xA0000000
#define __FSMC_BCR2 	FSMC_Bank1_R_BASE + 0x00000008  	//块2 0xA0000008
#define __FSMC_BCR3		FSMC_Bank1_R_BASE + 0x00000010  	//块3 0xA0000010
#define __FSMC_BCR4 	FSMC_Bank1_R_BASE + 0x00000018  	//块4 0xA0000018

//Nor/PSRAM读时序寄存器
#define __FSMC_BTR1		FSMC_Bank1_R_BASE + 0x00000004  	//块1 0xA0000004
#define __FSMC_BTR2		FSMC_Bank1_R_BASE + 0x0000000C  	//块2 0xA000000C
#define __FSMC_BTR3		FSMC_Bank1_R_BASE + 0x00000014 		//块3 0xA0000014
#define __FSMC_BTR4		FSMC_Bank1_R_BASE + 0x0000001C  	//块4 0xA000001C

//Nor/PSRAM写时序寄存器
#define __FSMC_BWTR1    FSMC_Bank1E_R_BASE + 0x00000000  	//块1 0xA0000104
#define __FSMC_BWTR2	FSMC_Bank1E_R_BASE + 0x00000008  	//块2 0xA000010C
#define __FSMC_BWTR3	FSMC_Bank1E_R_BASE + 0x00000010  	//块3 0xA0000114
#define __FSMC_BWTR4	FSMC_Bank1E_R_BASE + 0x00000018  	//块4 0xA000011C

//Nor/PSRAM控制寄存器
#define _FSMC_BCR1		ADR(__FSMC_BCR1) 	
#define _FSMC_BCR2 		ADR(__FSMC_BCR2)
#define _FSMC_BCR3		ADR(__FSMC_BCR3)
#define _FSMC_BCR4 		ADR(__FSMC_BCR4)

//Nor/PSRAM读时序寄存器
#define _FSMC_BTR1		ADR(__FSMC_BTR1)
#define _FSMC_BTR2		ADR(__FSMC_BTR2)
#define _FSMC_BTR3		ADR(__FSMC_BTR3)
#define _FSMC_BTR4		ADR(__FSMC_BTR4)

//Nor/PSRAM写时序寄存器
#define _FSMC_BWTR1		ADR(__FSMC_BWTR1)   
#define _FSMC_BWTR2		ADR(__FSMC_BWTR2)	
#define _FSMC_BWTR3		ADR(__FSMC_BWTR3)	
#define _FSMC_BWTR4		ADR(__FSMC_BWTR4)

//Nor/PSRAM控制寄存器
#define FSMC_BCR1		VAL(__FSMC_BCR1) 	
#define FSMC_BCR2 		VAL(__FSMC_BCR2)
#define FSMC_BCR3		VAL(__FSMC_BCR3)
#define FSMC_BCR4 		VAL(__FSMC_BCR4)

//Nor/PSRAM读时序寄存器
#define FSMC_BTR1		VAL(__FSMC_BTR1)
#define FSMC_BTR2		VAL(__FSMC_BTR2)
#define FSMC_BTR3		VAL(__FSMC_BTR3)
#define FSMC_BTR4		VAL(__FSMC_BTR4)

//Nor/PSRAM写时序寄存器
#define FSMC_BWTR1		VAL(__FSMC_BWTR1)   
#define FSMC_BWTR2		VAL(__FSMC_BWTR2)	
#define FSMC_BWTR3		VAL(__FSMC_BWTR3)	
#define FSMC_BWTR4		VAL(__FSMC_BWTR4)




//Bank1 NORPSRAM Address
#define __FSMC_NORPSRAM1_ADDRESS_START 		0x60000000
#define __FSMC_NORPSRAM1_ADDRESS_END	    0x60FFFFFF

#define __FSMC_NORPSRAM2_ADDRESS_START 		0x64000000
#define __FSMC_NORPSRAM2_ADDRESS_END		0x64FFFFFF

#define __FSMC_NORPSRAM3_ADDRESS_START 		0x68000000
#define __FSMC_NORPSRAM3_ADDRESS_END		0x68FFFFFF

#define __FSMC_NORPSRAM4_ADDRESS_START 		0x6C000000
#define __FSMC_NORPSRAM4_ADDRESS_END		0x6CFFFFFF

//Bank1 NORPSRAM Value
#define FSMC_NORPSRAM1_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM1_ADDRESS_START)))
#define FSMC_NORPSRAM1_ADDRESS_END	    	(*((U16*)(__FSMC_NORPSRAM1_ADDRESS_END)))

#define FSMC_NORPSRAM2_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM2_ADDRESS_START)))
#define FSMC_NORPSRAM2_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM2_ADDRESS_END)))

#define FSMC_NORPSRAM3_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM3_ADDRESS_START)))
#define FSMC_NORPSRAM3_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM3_ADDRESS_END)))

#define FSMC_NORPSRAM4_ADDRESS_START 		(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_START)))
#define FSMC_NORPSRAM4_ADDRESS_END			(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_END)))

#define FSMC_NORPSRAM4_VALUE(ADD)			(*((U16*)(__FSMC_NORPSRAM4_ADDRESS_START + ADD)))

 

//*************************************************************8NOR/PSRAM controller registers*****************************************//

//******************SRAM/NOR-Flash chip-select control registers 1..4 (FSMC_BCR1..4)*********//
/*
成组写模式使能
Bit 19 CBURSTRW: Write burst enable.
For Cellular RAM, the bit enables synchronous burst protocol during write operations. For Flash 
memory access in burst mode, this bit enables/disables the wait state insertion via the NWAIT 
signal. The enable bit for the synchronous burst protocol during read access is the BURSTEN bit in 
the FSMC_BCRx register.
0: Write operations are always performed in asynchronous mode
1: Write operations are performed in synchronous mode.
*/
void FSMC_NORPSRAM1_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM2_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM3_set_CBURSTRW(U8 e_d);
void FSMC_NORPSRAM4_set_CBURSTRW(U8 e_d);

#define FSMC_NORPSRAM1_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM1_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM2_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM2_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM3_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM3_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

#define FSMC_NORPSRAM4_enable_write_burst()		FSMC_NORPSRAM1_set_CBURSTRW(1)
#define FSMC_NORPSRAM4_disable_write_burst()	FSMC_NORPSRAM1_set_CBURSTRW(0)

/*             
同步模式下等待信号是否可用
Bit 15 ASYNCWAIT: Wait signal during asynchronous transfers
This bit enables the FSMC to use the wait signal even during an asynchronous protocol.
0: NWAIT signal is not taken in to account when running an asynchronous protocol (default after 
reset)
1: NWAIT signal is taken in to account when running an asynchronous protocol
*/
void FSMC_NORPSRAM1_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM2_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM3_set_ASYNCWAIT(U8 e_d);
void FSMC_NORPSRAM4_set_ASYNCWAIT(U8 e_d);

#define FSMC_NORPSRAM1_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM1_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM2_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM2_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM3_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM3_set_ASYNCWAIT(1)
#define FSMC_NORPSRAM4_enable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM4_set_ASYNCWAIT(1)

#define FSMC_NORPSRAM1_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM1_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM2_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM2_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM3_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM3_set_ASYNCWAIT(0)
#define FSMC_NORPSRAM4_disable_wait_signal_at_asyn_mode()	FSMC_NORPSRAM4_set_ASYNCWAIT(0)

/*
扩展模式是否使用(也就是是否读和写的时序独立)
Bit 14 EXTMOD: Extended mode enable.
This bit enables the FSMC to program inside the FSMC_BWTR register, so it allows different 
timings for read and write.
0: values inside FSMC_BWTR register are not taken into account (default after reset)
1: values inside FSMC_BWTR register are taken into account
*/
void FSMC_NORPSRAM1_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM2_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM3_set_EXTMOD(U8 e_d);
void FSMC_NORPSRAM4_set_EXTMOD(U8 e_d);

#define FSMC_NORPSRAM1_enable_extended_mode()	FSMC_NORPSRAM1_set_EXTMOD(1)
#define FSMC_NORPSRAM2_enable_extended_mode()	FSMC_NORPSRAM2_set_EXTMOD(1)
#define FSMC_NORPSRAM3_enable_extended_mode()	FSMC_NORPSRAM3_set_EXTMOD(1)
#define FSMC_NORPSRAM4_enable_extended_mode()	FSMC_NORPSRAM4_set_EXTMOD(1)

#define FSMC_NORPSRAM1_disable_extended_mode()	FSMC_NORPSRAM1_set_EXTMOD(0)
#define FSMC_NORPSRAM2_disable_extended_mode()	FSMC_NORPSRAM2_set_EXTMOD(0)
#define FSMC_NORPSRAM3_disable_extended_mode()	FSMC_NORPSRAM3_set_EXTMOD(0)
#define FSMC_NORPSRAM4_disable_extended_mode()	FSMC_NORPSRAM4_set_EXTMOD(0)

/*
在成组模式下等待信号是否
Bit 13 WAITEN: Wait enable bit.
For Flash memory access in burst mode, this bit enables/disables wait-state insertion via the 
NWAIT signal:
0: NWAIT signal is disabled (its level not taken into account, no wait state inserted after the 
programmed Flash latency period)
1: NWAIT signal is enabled (its level is taken into account after the programmed Flash latency 
period to insert wait states if asserted) (default after reset)
*/
void FSMC_NORPSRAM1_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM2_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM3_set_WAITEN(U8 e_d);
void FSMC_NORPSRAM4_set_WAITEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_wait_signal()	FSMC_NORPSRAM1_set_WAITEN(1)
#define FSMC_NORPSRAM2_enable_wait_signal()	FSMC_NORPSRAM2_set_WAITEN(1)
#define FSMC_NORPSRAM3_enable_wait_signal()	FSMC_NORPSRAM3_set_WAITEN(1)
#define FSMC_NORPSRAM4_enable_wait_signal()	FSMC_NORPSRAM4_set_WAITEN(1)

#define FSMC_NORPSRAM1_disable_wait_signal()	FSMC_NORPSRAM1_set_WAITEN(0)
#define FSMC_NORPSRAM2_disable_wait_signal()	FSMC_NORPSRAM2_set_WAITEN(0)
#define FSMC_NORPSRAM3_disable_wait_signal()	FSMC_NORPSRAM3_set_WAITEN(0)
#define FSMC_NORPSRAM4_disable_wait_signal()	FSMC_NORPSRAM4_set_WAITEN(0)

/*
写使能
Bit 12 WREN: Write enable bit.
This bit indicates whether write operations are enabled/disabled in the bank by the FSMC:
0: Write operations are disabled in the bank by the FSMC, an AHB error is reported,
1: Write operations are enabled for the bank by the FSMC (default after reset).
*/
void FSMC_NORPSRAM1_set_WREN(U8 e_d);
void FSMC_NORPSRAM2_set_WREN(U8 e_d);
void FSMC_NORPSRAM3_set_WREN(U8 e_d);
void FSMC_NORPSRAM4_set_WREN(U8 e_d);

#define FSMC_NORPSRAM1_enable_write_operation()	FSMC_NORPSRAM1_set_WREN(1)
#define FSMC_NORPSRAM2_enable_write_operation()	FSMC_NORPSRAM2_set_WREN(1)
#define FSMC_NORPSRAM3_enable_write_operation()	FSMC_NORPSRAM3_set_WREN(1)
#define FSMC_NORPSRAM4_enable_write_operation()	FSMC_NORPSRAM4_set_WREN(1)

#define FSMC_NORPSRAM1_disable_write_operation()	FSMC_NORPSRAM1_set_WREN(0)
#define FSMC_NORPSRAM2_disable_write_operation()	FSMC_NORPSRAM2_set_WREN(0)
#define FSMC_NORPSRAM3_disable_write_operation()	FSMC_NORPSRAM3_set_WREN(0)
#define FSMC_NORPSRAM4_disable_write_operation()	FSMC_NORPSRAM4_set_WREN(0)


/*
等待信号在等待之前插入还是在等待中插入
Bit 11 WAITCFG: Wait timing configuration.
For memory access in burst mode, the NWAIT signal indicates whether the data from the memory 
are valid or if a wait state must be inserted. This configuration bit determines if NWAIT is asserted 
by the memory one clock cycle before the wait state or during the wait state:
0: NWAIT signal is active one data cycle before wait state (default after reset),
1: NWAIT signal is active during wait state (not for Cellular RAM).
*/
void FSMC_NORPSRAM1_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM2_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM3_set_WAITCFG(U8 sel);
void FSMC_NORPSRAM4_set_WAITCFG(U8 sel);

#define FSMC_NORPSRAM1_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(0)
#define FSMC_NORPSRAM2_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM2_set_WAITCFG(0)
#define FSMC_NORPSRAM3_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM3_set_WAITCFG(0)
#define FSMC_NORPSRAM4_NWAIT_inserted_before_wait_state()	FSMC_NORPSRAM4_set_WAITCFG(0)

#define FSMC_NORPSRAM1_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM2_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM3_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)
#define FSMC_NORPSRAM4_NWAIT_inserted_during_wait_state()	FSMC_NORPSRAM1_set_WAITCFG(1)


/*
是否允许非对其的成组模式 是否允许在组模式下将AHB的组拆封成两个线性的访问.
Bit 10 WRAPMOD: Wrapped burst mode support.
Defines whether the controller will or not split an AHB burst wrap access into two linear accesses. 
Valid only when accessing memories in burst mode
0: Direct wrapped burst is not enabled (default after reset),
1: Direct wrapped burst is enabled.
Note: This bit has no effect as the CPU and DMA cannot generate wrapping burst transfers.
*/
void FSMC_NORPSRAM1_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM2_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM3_set_WRAPMOD(U8 e_d);
void FSMC_NORPSRAM4_set_WRAPMOD(U8 e_d);

#define FSMC_NORPSRAM1_enable_split()	FSMC_NORPSRAM1_set_WRAPMOD(1)
#define FSMC_NORPSRAM2_enable_split()	FSMC_NORPSRAM2_set_WRAPMOD(1)
#define FSMC_NORPSRAM3_enable_split()	FSMC_NORPSRAM3_set_WRAPMOD(1)
#define FSMC_NORPSRAM4_enable_split()	FSMC_NORPSRAM4_set_WRAPMOD(1)

#define FSMC_NORPSRAM1_disable_split()	FSMC_NORPSRAM1_set_WRAPMOD(0)
#define FSMC_NORPSRAM2_disable_split()	FSMC_NORPSRAM2_set_WRAPMOD(0)
#define FSMC_NORPSRAM3_disable_split()	FSMC_NORPSRAM3_set_WRAPMOD(0)
#define FSMC_NORPSRAM4_disable_split()	FSMC_NORPSRAM4_set_WRAPMOD(0)

/*
等待信号的极性
Bit 9 WAITPOL: Wait signal polarity bit.
Defines the polarity of the wait signal from memory. Valid only when accessing the memory in burst 
mode:
0: NWAIT active low (default after reset),
1: NWAIT active high.
*/
void FSMC_NORPSRAM1_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM2_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM3_set_WAITPOL(U8 sel);
void FSMC_NORPSRAM4_set_WAITPOL(U8 sel);

#define FSMC_NORPSRAM1_NWAIT_active_low()	FSMC_NORPSRAM1_set_WAITPOL(0)
#define FSMC_NORPSRAM2_NWAIT_active_low()	FSMC_NORPSRAM2_set_WAITPOL(0)
#define FSMC_NORPSRAM3_NWAIT_active_low()	FSMC_NORPSRAM3_set_WAITPOL(0)
#define FSMC_NORPSRAM4_NWAIT_active_low()	FSMC_NORPSRAM4_set_WAITPOL(0)

#define FSMC_NORPSRAM1_NWAIT_active_high()	FSMC_NORPSRAM1_set_WAITPOL(1)
#define FSMC_NORPSRAM2_NWAIT_active_high()	FSMC_NORPSRAM2_set_WAITPOL(1)
#define FSMC_NORPSRAM3_NWAIT_active_high()	FSMC_NORPSRAM3_set_WAITPOL(1)
#define FSMC_NORPSRAM4_NWAIT_active_high()	FSMC_NORPSRAM4_set_WAITPOL(1)



/*
成组模式使能  只能和支持同步成组模式的存储器合作
Bit 8 BURSTEN: Burst enable bit.
Enables the burst access mode for the memory. Valid only with synchronous burst memories:
0: Burst access mode disabled (default after reset)
1: Burst access mode enable
*/
void FSMC_NORPSRAM1_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM2_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM3_set_BURSTEN(U8 e_d);
void FSMC_NORPSRAM4_set_BURSTEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_burst_access()	FSMC_NORPSRAM1_set_BURSTEN(1)
#define FSMC_NORPSRAM2_enable_burst_access()	FSMC_NORPSRAM2_set_BURSTEN(1)
#define FSMC_NORPSRAM3_enable_burst_access()	FSMC_NORPSRAM3_set_BURSTEN(1)
#define FSMC_NORPSRAM4_enable_burst_access()	FSMC_NORPSRAM4_set_BURSTEN(1)

#define FSMC_NORPSRAM1_disable_burst_access()	FSMC_NORPSRAM1_set_BURSTEN(0)
#define FSMC_NORPSRAM2_disable_burst_access()	FSMC_NORPSRAM2_set_BURSTEN(0)
#define FSMC_NORPSRAM3_disable_burst_access()	FSMC_NORPSRAM3_set_BURSTEN(0)
#define FSMC_NORPSRAM4_disable_burst_access()	FSMC_NORPSRAM4_set_BURSTEN(0)



/*
Bit 7
Reserved.
*/

/*
闪存访问使能   如果和NOR闪存工作时，该位要使能
Bit 6 FACCEN: Flash access enable
Enables NOR Flash memory access operations.
0: Corresponding NOR Flash memory access is disabled
1: Corresponding NOR Flash memory access is enabled (default after reset)
*/
void FSMC_NORPSRAM1_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM2_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM3_set_FACCEN(U8 e_d);
void FSMC_NORPSRAM4_set_FACCEN(U8 e_d);

#define FSMC_NORPSRAM1_enable_NOR_flash_access()	FSMC_NORPSRAM1_set_FACCEN(1)
#define FSMC_NORPSRAM2_enable_NOR_flash_access()	FSMC_NORPSRAM2_set_FACCEN(1)
#define FSMC_NORPSRAM3_enable_NOR_flash_access()	FSMC_NORPSRAM3_set_FACCEN(1)
#define FSMC_NORPSRAM4_enable_NOR_flash_access()	FSMC_NORPSRAM4_set_FACCEN(1)

#define FSMC_NORPSRAM1_disable_NOR_flash_access()	FSMC_NORPSRAM1_set_FACCEN(0)
#define FSMC_NORPSRAM2_disable_NOR_flash_access()	FSMC_NORPSRAM2_set_FACCEN(0)
#define FSMC_NORPSRAM3_disable_NOR_flash_access()	FSMC_NORPSRAM3_set_FACCEN(0)
#define FSMC_NORPSRAM4_disable_NOR_flash_access()	FSMC_NORPSRAM4_set_FACCEN(0)

/*
存储器位宽
Bits 5:4 MWID: Memory databus width.
Defines the external memory device width, valid for all type of memories.
00: 8 bits,
01: 16 bits (default after reset),
10: reserved, do not use,
11: reserved, do not use.
*/
void FSMC_NORPSRAM1_set_MWID(U8 sel);
void FSMC_NORPSRAM2_set_MWID(U8 sel);
void FSMC_NORPSRAM3_set_MWID(U8 sel);
void FSMC_NORPSRAM4_set_MWID(U8 sel);

#define FSMC_NORPSRAM1_data_width_is_8()	FSMC_NORPSRAM1_set_MWID(0)
#define FSMC_NORPSRAM1_data_width_is_16()	FSMC_NORPSRAM1_set_MWID(1)

#define FSMC_NORPSRAM2_data_width_is_8()	FSMC_NORPSRAM2_set_MWID(0)
#define FSMC_NORPSRAM2_data_width_is_16()	FSMC_NORPSRAM2_set_MWID(1)

#define FSMC_NORPSRAM3_data_width_is_8()	FSMC_NORPSRAM3_set_MWID(0)
#define FSMC_NORPSRAM3_data_width_is_16()	FSMC_NORPSRAM3_set_MWID(1)

#define FSMC_NORPSRAM4_data_width_is_8()	FSMC_NORPSRAM4_set_MWID(0)
#define FSMC_NORPSRAM4_data_width_is_16()	FSMC_NORPSRAM4_set_MWID(1)

/*
存储器类型
Bits 3:2 MTYP: Memory type.
Defines the type of external memory attached to the corresponding memory bank:
00: SRAM, ROM (default after reset for Bank 2...4)
01: PSRAM (Cellular RAM: CRAM)
10: NOR Flash(default after reset for Bank 1)
11: reserved
*/
void FSMC_NORPSRAM1_set_MTYP(U8 sel);
void FSMC_NORPSRAM2_set_MTYP(U8 sel);
void FSMC_NORPSRAM3_set_MTYP(U8 sel);
void FSMC_NORPSRAM4_set_MTYP(U8 sel);

//SRAM
#define FSMC_NORPSRAM1_memory_type_is_SRAM()	FSMC_NORPSRAM1_set_MTYP(0)
#define FSMC_NORPSRAM2_memory_type_is_SRAM()	FSMC_NORPSRAM2_set_MTYP(0)
#define FSMC_NORPSRAM3_memory_type_is_SRAM()	FSMC_NORPSRAM3_set_MTYP(0)
#define FSMC_NORPSRAM4_memory_type_is_SRAM()	FSMC_NORPSRAM4_set_MTYP(0)

//ROM
#define FSMC_NORPSRAM1_memory_type_is_ROM()	FSMC_NOR_PROM_1_set_MTYP(0)
#define FSMC_NORPSRAM2_memory_type_is_ROM()	FSMC_NOR_PROM_2_set_MTYP(0)
#define FSMC_NORPSRAM3_memory_type_is_ROM()	FSMC_NOR_PROM_3_set_MTYP(0)
#define FSMC_NORPSRAM4_memory_type_is_ROM()	FSMC_NOR_PROM_4_set_MTYP(0)

//PSRAM
#define FSMC_NORPSRAM1_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_1_set_MTYP(1)
#define FSMC_NORPSRAM2_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_2_set_MTYP(1)
#define FSMC_NORPSRAM3_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_3_set_MTYP(1)
#define FSMC_NORPSRAM4_memory_type_is_PSRAM()	FSMC_NOR_PPSRAM_4_set_MTYP(1)

//NOR flash
#define FSMC_NORPSRAM1_memory_type_is_NOR()	FSMC_NOR_PNOR_1_set_MTYP(2)
#define FSMC_NORPSRAM2_memory_type_is_NOR()	FSMC_NOR_PNOR_2_set_MTYP(2)
#define FSMC_NORPSRAM3_memory_type_is_NOR()	FSMC_NOR_PNOR_3_set_MTYP(2)
#define FSMC_NORPSRAM4_memory_type_is_NOR()	FSMC_NOR_PNOR_4_set_MTYP(2)

/*
复用模式使能
Bit 1 MUXEN: Address/data multiplexing enable bit.
When this bit is set, the address and data values are multiplexed on the databus, valid only with 
NOR and PSRAM memories:
0: Address/Data nonmultiplexed
1: Address/Data multiplexed on databus (default after reset)
*/
void FSMC_NORPSRAM1_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM2_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM3_set_MUXEN(U8 e_d);
void FSMC_NORPSRAM4_set_MUXEN(U8 e_d);

//使能复用模式
#define FSMC_NORPSRAM1_enable_multiplexed()	FSMC_NORPSRAM1_set_MUXEN(1)
#define FSMC_NORPSRAM2_enable_multiplexed()	FSMC_NORPSRAM2_set_MUXEN(1)
#define FSMC_NORPSRAM3_enable_multiplexed()	FSMC_NORPSRAM3_set_MUXEN(1)
#define FSMC_NORPSRAM4_enable_multiplexed()	FSMC_NORPSRAM4_set_MUXEN(1)

//除能复用模式
#define FSMC_NORPSRAM1_disable_multiplexed()	FSMC_NORPSRAM1_set_MUXEN(0)
#define FSMC_NORPSRAM2_disable_multiplexed()	FSMC_NORPSRAM2_set_MUXEN(0)
#define FSMC_NORPSRAM3_disable_multiplexed()	FSMC_NORPSRAM3_set_MUXEN(0)
#define FSMC_NORPSRAM4_disable_multiplexed()	FSMC_NORPSRAM4_set_MUXEN(0)


/*
存储器块使能
Bit 0 MBKEN: Memory bank enable bit.
Enables the memory bank. After reset Bank1 is enabled, all others are disabled. Accessing a 
disabled bank causes an ERROR on AHB bus.
0: Corresponding memory bank is disabled
1: Corresponding memory bank is enabled
*/
void FSMC_NORPSRAM1_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM2_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM3_set_MBKEN(U8 e_d);
void FSMC_NORPSRAM4_set_MBKEN(U8 e_d);

//使能存储器块
#define FSMC_NORPSRAM1_enable_bank()	FSMC_NORPSRAM1_set_MBKEN(1)
#define FSMC_NORPSRAM2_enable_bank()	FSMC_NORPSRAM2_set_MBKEN(1)
#define FSMC_NORPSRAM3_enable_bank()	FSMC_NORPSRAM3_set_MBKEN(1)
#define FSMC_NORPSRAM4_enable_bank()	FSMC_NORPSRAM4_set_MBKEN(1)

//除能存储器块
#define FSMC_NORPSRAM1_disable_bank()	FSMC_NORPSRAM1_set_MBKEN(0)
#define FSMC_NORPSRAM2_disable_bank()	FSMC_NORPSRAM2_set_MBKEN(0)
#define FSMC_NORPSRAM3_disable_bank()	FSMC_NORPSRAM3_set_MBKEN(0)
#define FSMC_NORPSRAM4_disable_bank()	FSMC_NORPSRAM4_set_MBKEN(0)

/*
PSRAMs (CRAMs) have a variable latency due to internal refresh. Therefore these 
memories issue the NWAIT signal during the whole latency phase to prolong the latency as 
needed.
With PSRAMs (CRAMs) the filed DATLAT must be set to 0, so that the FSMC exits its 
latency phase soon and starts sampling NWAIT from memory, then starts to read or write 
when the memory is ready.
This method can be used also with the latest generation of synchronous Flash memories 
that issue the NWAIT signal, unlike older Flash memories (check the datasheet of the 
specific Flash memory being used).
*/


//***************SRAM/NOR-Flash chip-select timing registers 1..4 (FSMC_BTR1..4) ***************//
/*
Address offset: 0xA000 0000 + 0x04 + 8 * (x – 1), x = 1..4
Reset value: 0x0FFF FFFF
This register contains the control information of each memory bank, used for SRAMs, ROMs 
and NOR Flash memories. If the EXTMOD bit is set in the FSMC_BCRx register, then this 
register is partitioned for write and read access, that is, 2 registers are available: one to 
configure read accesses (this register) and one to configure write accesses (FSMC_BWTRx 
registers).
*/

/*
访问模式
Bits 29:28 ACCMOD: Access mode
Specifies the asynchronous access modes as shown in the timing diagrams. These bits are 
taken into account only when the EXTMOD bit in the FSMC_BCRx register is 1.
00: access mode A
01: access mode B
10: access mode C
11: access mode D
*/
void FSMC_NORPSRAM1_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM2_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM3_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM4_set_ACCMOD(U8 mod);

//选择模式A
#define FSMC_NORPSRAM1_access_mode_A()	FSMC_NORPSRAM1_set_ACCMOD(0)
#define FSMC_NORPSRAM2_access_mode_A()	FSMC_NORPSRAM2_set_ACCMOD(0)
#define FSMC_NORPSRAM3_access_mode_A()	FSMC_NORPSRAM3_set_ACCMOD(0)
#define FSMC_NORPSRAM4_access_mode_A()	FSMC_NORPSRAM4_set_ACCMOD(0)

//选择模式B
#define FSMC_NORPSRAM1_access_mode_B()	FSMC_NORPSRAM1_set_ACCMOD(1)
#define FSMC_NORPSRAM2_access_mode_B()	FSMC_NORPSRAM2_set_ACCMOD(1)
#define FSMC_NORPSRAM3_access_mode_B()	FSMC_NORPSRAM3_set_ACCMOD(1)
#define FSMC_NORPSRAM4_access_mode_B()	FSMC_NORPSRAM4_set_ACCMOD(1)

//选择模式C
#define FSMC_NORPSRAM1_access_mode_C()	FSMC_NORPSRAM1_set_ACCMOD(2)
#define FSMC_NORPSRAM2_access_mode_C()	FSMC_NORPSRAM2_set_ACCMOD(2)
#define FSMC_NORPSRAM3_access_mode_C()	FSMC_NORPSRAM3_set_ACCMOD(2)
#define FSMC_NORPSRAM4_access_mode_C()	FSMC_NORPSRAM4_set_ACCMOD(2)

//选择模式D
#define FSMC_NORPSRAM1_access_mode_D()	FSMC_NORPSRAM1_set_ACCMOD(3)
#define FSMC_NORPSRAM2_access_mode_D()	FSMC_NORPSRAM2_set_ACCMOD(3)
#define FSMC_NORPSRAM3_access_mode_D()	FSMC_NORPSRAM3_set_ACCMOD(3)
#define FSMC_NORPSRAM4_access_mode_D()	FSMC_NORPSRAM4_set_ACCMOD(3)



/*
第一次访问的等待数据时间 (同步成组模式下)
Bits 27:24 DATLAT (see note below bit descriptions): Data latency (for synchronous burst NOR Flash)
For NOR Flash with synchronous burst mode enabled, defines the number of memory clock 
cycles (+2) to issue to the memory before getting the first data:
This timing parameter is not expressed in HCLK periods, but in Flash clock (CLK) periods. In 
asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care. In case of 
CRAM, this field must be set to 0
0000: Data latency of 2 CLK clock cycles for first burst access
.......
1111: Data latency of 17 CLK clock cycles for first burst access (default value after reset)
*/
void FSMC_NORPSRAM1_set_DATLAT(U8 sel);
void FSMC_NORPSRAM2_set_DATLAT(U8 sel);
void FSMC_NORPSRAM3_set_DATLAT(U8 sel);
void FSMC_NORPSRAM4_set_DATLAT(U8 sel);

//t = 2 - 17
#define FSMC_NORPSRAM1_set_latency(t)	FSMC_NORPSRAM1_set_DATLAT(t-2)
#define FSMC_NORPSRAM2_set_latency(t)	FSMC_NORPSRAM2_set_DATLAT(t-2)
#define FSMC_NORPSRAM3_set_latency(t)	FSMC_NORPSRAM3_set_DATLAT(t-2)
#define FSMC_NORPSRAM4_set_latency(t)	FSMC_NORPSRAM4_set_DATLAT(t-2)

//等待时间为2个CLK
#define FSMC_NORPSRAM1_latency_is_2_CLK()	FSMC_NORPSRAM1_set_DATLAT(0)
#define FSMC_NORPSRAM2_latency_is_2_CLK()	FSMC_NORPSRAM2_set_DATLAT(0)
#define FSMC_NORPSRAM3_latency_is_2_CLK()	FSMC_NORPSRAM3_set_DATLAT(0)
#define FSMC_NORPSRAM4_latency_is_2_CLK()	FSMC_NORPSRAM4_set_DATLAT(0)

//等待时间为3个CLK
#define FSMC_NORPSRAM1_latency_is_3_CLK()	FSMC_NORPSRAM1_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK()	FSMC_NORPSRAM3_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK()	FSMC_NORPSRAM3_set_DATLAT(1)
#define FSMC_NORPSRAM4_latency_is_3_CLK()	FSMC_NORPSRAM4_set_DATLAT(1)

//等待时间为4个CLK
#define FSMC_NORPSRAM1_latency_is_4_CLK()	FSMC_NORPSRAM1_set_DATLAT(2)
#define FSMC_NORPSRAM2_latency_is_4_CLK()	FSMC_NORPSRAM2_set_DATLAT(2)
#define FSMC_NORPSRAM3_latency_is_4_CLK()	FSMC_NORPSRAM3_set_DATLAT(2)
#define FSMC_NORPSRAM4_latency_is_4_CLK()	FSMC_NORPSRAM4_set_DATLAT(2)

//等待时间为5个CLK
#define FSMC_NORPSRAM1_latency_is_5_CLK()	FSMC_NORPSRAM1_set_DATLAT(3)
#define FSMC_NORPSRAM2_latency_is_5_CLK()	FSMC_NORPSRAM2_set_DATLAT(3)
#define FSMC_NORPSRAM3_latency_is_5_CLK()	FSMC_NORPSRAM3_set_DATLAT(3)
#define FSMC_NORPSRAM4_latency_is_5_CLK()	FSMC_NORPSRAM4_set_DATLAT(3)

//等待时间为6个CLK
#define FSMC_NORPSRAM1_latency_is_6_CLK()	FSMC_NORPSRAM1_set_DATLAT(4)
#define FSMC_NORPSRAM2_latency_is_6_CLK()	FSMC_NORPSRAM2_set_DATLAT(4)
#define FSMC_NORPSRAM3_latency_is_6_CLK()	FSMC_NORPSRAM3_set_DATLAT(4)
#define FSMC_NORPSRAM4_latency_is_6_CLK()	FSMC_NORPSRAM4_set_DATLAT(4)

//等待时间为7个CLK
#define FSMC_NORPSRAM1_latency_is_7_CLK()	FSMC_NORPSRAM1_set_DATLAT(5)
#define FSMC_NORPSRAM2_latency_is_7_CLK()	FSMC_NORPSRAM2_set_DATLAT(5)
#define FSMC_NORPSRAM3_latency_is_7_CLK()	FSMC_NORPSRAM3_set_DATLAT(5)
#define FSMC_NORPSRAM4_latency_is_7_CLK()	FSMC_NORPSRAM4_set_DATLAT(5)

//等待时间为8个CLK
#define FSMC_NORPSRAM1_latency_is_8_CLK()	FSMC_NORPSRAM1_set_DATLAT(6)
#define FSMC_NORPSRAM2_latency_is_8_CLK()	FSMC_NORPSRAM2_set_DATLAT(6)
#define FSMC_NORPSRAM3_latency_is_8_CLK()	FSMC_NORPSRAM3_set_DATLAT(6)
#define FSMC_NORPSRAM4_latency_is_8_CLK()	FSMC_NORPSRAM4_set_DATLAT(6)

//等待时间为9个CLK
#define FSMC_NORPSRAM1_latency_is_9_CLK()	FSMC_NORPSRAM1_set_DATLAT(7)
#define FSMC_NORPSRAM2_latency_is_9_CLK()	FSMC_NORPSRAM2_set_DATLAT(7)
#define FSMC_NORPSRAM3_latency_is_9_CLK()	FSMC_NORPSRAM3_set_DATLAT(7)
#define FSMC_NORPSRAM4_latency_is_9_CLK()	FSMC_NORPSRAM4_set_DATLAT(7)

//等待时间为10个CLK
#define FSMC_NORPSRAM1_latency_is_10_CLK()	FSMC_NORPSRAM1_set_DATLAT(8)
#define FSMC_NORPSRAM2_latency_is_10_CLK()	FSMC_NORPSRAM2_set_DATLAT(8)
#define FSMC_NORPSRAM3_latency_is_10_CLK()	FSMC_NORPSRAM3_set_DATLAT(8)
#define FSMC_NORPSRAM4_latency_is_10_CLK()	FSMC_NORPSRAM4_set_DATLAT(8)

//等待时间为11个CLK
#define FSMC_NORPSRAM1_latency_is_11_CLK()	FSMC_NORPSRAM1_set_DATLAT(9)
#define FSMC_NORPSRAM2_latency_is_11_CLK()	FSMC_NORPSRAM2_set_DATLAT(9)
#define FSMC_NORPSRAM3_latency_is_11_CLK()	FSMC_NORPSRAM3_set_DATLAT(9)
#define FSMC_NORPSRAM4_latency_is_11_CLK()	FSMC_NORPSRAM4_set_DATLAT(9)

//等待时间为12个CLK
#define FSMC_NORPSRAM1_latency_is_12_CLK()	FSMC_NORPSRAM1_set_DATLAT(10)
#define FSMC_NORPSRAM2_latency_is_12_CLK()	FSMC_NORPSRAM2_set_DATLAT(10)
#define FSMC_NORPSRAM3_latency_is_12_CLK()	FSMC_NORPSRAM3_set_DATLAT(10)
#define FSMC_NORPSRAM4_latency_is_12_CLK()	FSMC_NORPSRAM4_set_DATLAT(10)

//等待时间为13个CLK
#define FSMC_NORPSRAM1_latency_is_13_CLK()	FSMC_NORPSRAM1_set_DATLAT(11)
#define FSMC_NORPSRAM2_latency_is_13_CLK()	FSMC_NORPSRAM2_set_DATLAT(11)
#define FSMC_NORPSRAM3_latency_is_13_CLK()	FSMC_NORPSRAM3_set_DATLAT(11)
#define FSMC_NORPSRAM4_latency_is_13_CLK()	FSMC_NORPSRAM4_set_DATLAT(11)

//等待时间为14个CLK
#define FSMC_NORPSRAM1_latency_is_14_CLK()	FSMC_NORPSRAM1_set_DATLAT(12)
#define FSMC_NORPSRAM2_latency_is_14_CLK()	FSMC_NORPSRAM2_set_DATLAT(12)
#define FSMC_NORPSRAM3_latency_is_14_CLK()	FSMC_NORPSRAM3_set_DATLAT(12)
#define FSMC_NORPSRAM4_latency_is_14_CLK()	FSMC_NORPSRAM4_set_DATLAT(12)

//等待时间为15个CLK
#define FSMC_NORPSRAM1_latency_is_15_CLK()	FSMC_NORPSRAM1_set_DATLAT(13)
#define FSMC_NORPSRAM2_latency_is_15_CLK()	FSMC_NORPSRAM2_set_DATLAT(13)
#define FSMC_NORPSRAM3_latency_is_15_CLK()	FSMC_NORPSRAM3_set_DATLAT(13)
#define FSMC_NORPSRAM4_latency_is_15_CLK()	FSMC_NORPSRAM4_set_DATLAT(13)

//等待时间为16个CLK
#define FSMC_NORPSRAM1_latency_is_16_CLK()	FSMC_NORPSRAM1_set_DATLAT(14)
#define FSMC_NORPSRAM2_latency_is_16_CLK()	FSMC_NORPSRAM2_set_DATLAT(14)
#define FSMC_NORPSRAM3_latency_is_16_CLK()	FSMC_NORPSRAM3_set_DATLAT(14)
#define FSMC_NORPSRAM4_latency_is_16_CLK()	FSMC_NORPSRAM4_set_DATLAT(14)

//等待时间为17个CLK
#define FSMC_NORPSRAM1_latency_is_17_CLK()	FSMC_NORPSRAM1_set_DATLAT(15)
#define FSMC_NORPSRAM2_latency_is_17_CLK()	FSMC_NORPSRAM2_set_DATLAT(15)
#define FSMC_NORPSRAM3_latency_is_17_CLK()	FSMC_NORPSRAM3_set_DATLAT(15)
#define FSMC_NORPSRAM4_latency_is_17_CLK()	FSMC_NORPSRAM4_set_DATLAT(15)


/*
同步模式输出时钟分频 （HCLK分频）
Bits 23:20 CLKDIV: Clock divide ratio (for CLK signal)
Defines the period of CLK clock output signal, expressed in number of HCLK cycles:
0000: Reserved
0001: CLK period = 2 × HCLK periods
0010: CLK period = 3 × HCLK periods
......
1111: CLK period = 16 × HCLK periods (default value after reset) 
In asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care.
*/
void FSMC_NORPSRAM1_set_CLKDIV(U8 div);
void FSMC_NORPSRAM2_set_CLKDIV(U8 div);
void FSMC_NORPSRAM3_set_CLKDIV(U8 div);
void FSMC_NORPSRAM4_set_CLKDIV(U8 div);

//div = 2 - 16
#define FSMC_NORPSRAM1_set_div(div)	FSMC_NORPSRAM1_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM2_set_div(div)	FSMC_NORPSRAM2_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM3_set_div(div)	FSMC_NORPSRAM3_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM4_set_div(div)	FSMC_NORPSRAM4_set_CLKDIV(div - 1)

//对NOR_PRAM存储块1的时钟分频
#define FSMC_NORPSRAM1_div_HCLK_with_2()			FSMC_NORPSRAM1_set_CLKDIV(1)
#define FSMC_NORPSRAM1_div_HCLK_with_3()			FSMC_NORPSRAM1_set_CLKDIV(2)
#define FSMC_NORPSRAM1_div_HCLK_with_4()			FSMC_NORPSRAM1_set_CLKDIV(3)
#define FSMC_NORPSRAM1_div_HCLK_with_5()			FSMC_NORPSRAM1_set_CLKDIV(4)
#define FSMC_NORPSRAM1_div_HCLK_with_6()			FSMC_NORPSRAM1_set_CLKDIV(5)
#define FSMC_NORPSRAM1_div_HCLK_with_7()			FSMC_NORPSRAM1_set_CLKDIV(6)
#define FSMC_NORPSRAM1_div_HCLK_with_8()			FSMC_NORPSRAM1_set_CLKDIV(7)
#define FSMC_NORPSRAM1_div_HCLK_with_9()			FSMC_NORPSRAM1_set_CLKDIV(8)
#define FSMC_NORPSRAM1_div_HCLK_with_10()		FSMC_NORPSRAM1_set_CLKDIV(9)
#define FSMC_NORPSRAM1_div_HCLK_with_11()		FSMC_NORPSRAM1_set_CLKDIV(10)
#define FSMC_NORPSRAM1_div_HCLK_with_12()		FSMC_NORPSRAM1_set_CLKDIV(11)
#define FSMC_NORPSRAM1_div_HCLK_with_13()		FSMC_NORPSRAM1_set_CLKDIV(12)
#define FSMC_NORPSRAM1_div_HCLK_with_14()		FSMC_NORPSRAM1_set_CLKDIV(13)
#define FSMC_NORPSRAM1_div_HCLK_with_15()		FSMC_NORPSRAM1_set_CLKDIV(14)
#define FSMC_NORPSRAM1_div_HCLK_with_16()		FSMC_NORPSRAM1_set_CLKDIV(15)

//对NOR_PRAM存储块2的时钟分频
#define FSMC_NORPSRAM2_div_HCLK_with_2()			FSMC_NORPSRAM2_set_CLKDIV(1)
#define FSMC_NORPSRAM2_div_HCLK_with_3()			FSMC_NORPSRAM2_set_CLKDIV(2)
#define FSMC_NORPSRAM2_div_HCLK_with_4()			FSMC_NORPSRAM2_set_CLKDIV(3)
#define FSMC_NORPSRAM2_div_HCLK_with_5()			FSMC_NORPSRAM2_set_CLKDIV(4)
#define FSMC_NORPSRAM2_div_HCLK_with_6()			FSMC_NORPSRAM2_set_CLKDIV(5)
#define FSMC_NORPSRAM2_div_HCLK_with_7()			FSMC_NORPSRAM2_set_CLKDIV(6)
#define FSMC_NORPSRAM2_div_HCLK_with_8()			FSMC_NORPSRAM2_set_CLKDIV(7)
#define FSMC_NORPSRAM2_div_HCLK_with_9()			FSMC_NORPSRAM2_set_CLKDIV(8)
#define FSMC_NORPSRAM2_div_HCLK_with_10()		FSMC_NORPSRAM2_set_CLKDIV(9)
#define FSMC_NORPSRAM2_div_HCLK_with_11()		FSMC_NORPSRAM2_set_CLKDIV(10)
#define FSMC_NORPSRAM2_div_HCLK_with_12()		FSMC_NORPSRAM2_set_CLKDIV(11)
#define FSMC_NORPSRAM2_div_HCLK_with_13()		FSMC_NORPSRAM2_set_CLKDIV(12)
#define FSMC_NORPSRAM2_div_HCLK_with_14()		FSMC_NORPSRAM2_set_CLKDIV(13)
#define FSMC_NORPSRAM2_div_HCLK_with_15()		FSMC_NORPSRAM2_set_CLKDIV(14)
#define FSMC_NORPSRAM2_div_HCLK_with_16()		FSMC_NORPSRAM2_set_CLKDIV(15)

//对NOR_PRAM存储块3的时钟分频
#define FSMC_NORPSRAM3_div_HCLK_with_2()			FSMC_NORPSRAM3_set_CLKDIV(1)
#define FSMC_NORPSRAM3_div_HCLK_with_3()			FSMC_NORPSRAM3_set_CLKDIV(2)
#define FSMC_NORPSRAM3_div_HCLK_with_4()			FSMC_NORPSRAM3_set_CLKDIV(3)
#define FSMC_NORPSRAM3_div_HCLK_with_5()			FSMC_NORPSRAM3_set_CLKDIV(4)
#define FSMC_NORPSRAM3_div_HCLK_with_6()			FSMC_NORPSRAM3_set_CLKDIV(5)
#define FSMC_NORPSRAM3_div_HCLK_with_7()			FSMC_NORPSRAM3_set_CLKDIV(6)
#define FSMC_NORPSRAM3_div_HCLK_with_8()			FSMC_NORPSRAM3_set_CLKDIV(7)
#define FSMC_NORPSRAM3_div_HCLK_with_9()			FSMC_NORPSRAM3_set_CLKDIV(8)
#define FSMC_NORPSRAM3_div_HCLK_with_10()		FSMC_NORPSRAM3_set_CLKDIV(9)
#define FSMC_NORPSRAM3_div_HCLK_with_11()		FSMC_NORPSRAM3_set_CLKDIV(10)
#define FSMC_NORPSRAM3_div_HCLK_with_12()		FSMC_NORPSRAM3_set_CLKDIV(11)
#define FSMC_NORPSRAM3_div_HCLK_with_13()		FSMC_NORPSRAM3_set_CLKDIV(12)
#define FSMC_NORPSRAM3_div_HCLK_with_14()		FSMC_NORPSRAM3_set_CLKDIV(13)
#define FSMC_NORPSRAM3_div_HCLK_with_15()		FSMC_NORPSRAM3_set_CLKDIV(14)
#define FSMC_NORPSRAM3_div_HCLK_with_16()		FSMC_NORPSRAM3_set_CLKDIV(15)

//对NOR_PRAM存储块4的时钟分频
#define FSMC_NORPSRAM4_div_HCLK_with_2()			FSMC_NORPSRAM4_set_CLKDIV(1)
#define FSMC_NORPSRAM4_div_HCLK_with_3()			FSMC_NORPSRAM4_set_CLKDIV(2)
#define FSMC_NORPSRAM4_div_HCLK_with_4()			FSMC_NORPSRAM4_set_CLKDIV(3)
#define FSMC_NORPSRAM4_div_HCLK_with_5()			FSMC_NORPSRAM4_set_CLKDIV(4)
#define FSMC_NORPSRAM4_div_HCLK_with_6()			FSMC_NORPSRAM4_set_CLKDIV(5)
#define FSMC_NORPSRAM4_div_HCLK_with_7()			FSMC_NORPSRAM4_set_CLKDIV(6)
#define FSMC_NORPSRAM4_div_HCLK_with_8()			FSMC_NORPSRAM4_set_CLKDIV(7)
#define FSMC_NORPSRAM4_div_HCLK_with_9()			FSMC_NORPSRAM4_set_CLKDIV(8)
#define FSMC_NORPSRAM4_div_HCLK_with_10()		FSMC_NORPSRAM4_set_CLKDIV(9)
#define FSMC_NORPSRAM4_div_HCLK_with_11()		FSMC_NORPSRAM4_set_CLKDIV(10)
#define FSMC_NORPSRAM4_div_HCLK_with_12()		FSMC_NORPSRAM4_set_CLKDIV(11)
#define FSMC_NORPSRAM4_div_HCLK_with_13()		FSMC_NORPSRAM4_set_CLKDIV(12)
#define FSMC_NORPSRAM4_div_HCLK_with_14()		FSMC_NORPSRAM4_set_CLKDIV(13)
#define FSMC_NORPSRAM4_div_HCLK_with_15()		FSMC_NORPSRAM4_set_CLKDIV(14)
#define FSMC_NORPSRAM4_div_HCLK_with_16()		FSMC_NORPSRAM4_set_CLKDIV(15)




/*
总线恢复时间 在总线复用时使用
Bits 19:16 BUSTURN: Bus turnaround phase duration . just active in mul mode
These bits are written by software to introduce the bus turnaround delay after a read access 
(only from multiplexed NOR Flash memory) to avoid bus contention if the controller needs to 
drive addresses on the databus for the next side-by-side transaction. BUSTURN can be set 
to the minimum if the memory system does not include multiplexed memories or if the 
slowest memory does not take more than 6 HCLK clock cycles to put the databus in Hi-Z 
state:
0000: BUSTURN phase duration = 1 × HCLK clock cycle
...
1111: BUSTURN phase duration = 16 × HCLK clock cycles (default value after reset)
*/
void FSMC_NORPSRAM1_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM2_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM3_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM4_set_BUSTURN(U8 sel);

//sel = 1 -16
#define FSMC_NORPSRAM1_set_turnaround_phase(sel)	FSMC_NORPSRAM1_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM2_set_turnaround_phase(sel)	FSMC_NORPSRAM2_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM3_set_turnaround_phase(sel)	FSMC_NORPSRAM3_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM4_set_turnaround_phase(sel)	FSMC_NORPSRAM4_set_BUSTURN(sel-1)

//NORPRAM存储块1的总线恢复时间
#define	FSMC_NORPSRAM1_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(0)
#define	FSMC_NORPSRAM1_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(1)
#define	FSMC_NORPSRAM1_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(2)
#define	FSMC_NORPSRAM1_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(3)
#define	FSMC_NORPSRAM1_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(4)
#define	FSMC_NORPSRAM1_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(5)
#define	FSMC_NORPSRAM1_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(6)
#define	FSMC_NORPSRAM1_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(7)
#define	FSMC_NORPSRAM1_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(8)
#define	FSMC_NORPSRAM1_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(9)
#define	FSMC_NORPSRAM1_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(10)
#define	FSMC_NORPSRAM1_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(11)
#define	FSMC_NORPSRAM1_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(12)
#define	FSMC_NORPSRAM1_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(13)
#define	FSMC_NORPSRAM1_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(14)
#define	FSMC_NORPSRAM1_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM1_set_BUSTURN(15)


//NORPRAM存储块2的总线恢复时间
#define	FSMC_NORPSRAM2_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(0)
#define	FSMC_NORPSRAM2_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(1)
#define	FSMC_NORPSRAM2_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(2)
#define	FSMC_NORPSRAM2_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(3)
#define	FSMC_NORPSRAM2_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(4)
#define	FSMC_NORPSRAM2_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(5)
#define	FSMC_NORPSRAM2_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(6)
#define	FSMC_NORPSRAM2_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(7)
#define	FSMC_NORPSRAM2_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(8)
#define	FSMC_NORPSRAM2_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(9)
#define	FSMC_NORPSRAM2_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(10)
#define	FSMC_NORPSRAM2_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(11)
#define	FSMC_NORPSRAM2_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(12)
#define	FSMC_NORPSRAM2_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(13)
#define	FSMC_NORPSRAM2_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(14)
#define	FSMC_NORPSRAM2_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM2_set_BUSTURN(15)


//NORPRAM存储块3的总线恢复时间
#define	FSMC_NORPSRAM3_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(0)
#define	FSMC_NORPSRAM3_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(1)
#define	FSMC_NORPSRAM3_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(2)
#define	FSMC_NORPSRAM3_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(3)
#define	FSMC_NORPSRAM3_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(4)
#define	FSMC_NORPSRAM3_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(5)
#define	FSMC_NORPSRAM3_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(6)
#define	FSMC_NORPSRAM3_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(7)
#define	FSMC_NORPSRAM3_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(8)
#define	FSMC_NORPSRAM3_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(9)
#define	FSMC_NORPSRAM3_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(10)
#define	FSMC_NORPSRAM3_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(11)
#define	FSMC_NORPSRAM3_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(12)
#define	FSMC_NORPSRAM3_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(13)
#define	FSMC_NORPSRAM3_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(14)
#define	FSMC_NORPSRAM3_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM3_set_BUSTURN(15)


//NORPRAM存储块4的总线恢复时间
#define	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(0)
#define	FSMC_NORPSRAM4_turnaround_phase_is_2_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(1)
#define	FSMC_NORPSRAM4_turnaround_phase_is_3_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(2)
#define	FSMC_NORPSRAM4_turnaround_phase_is_4_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(3)
#define	FSMC_NORPSRAM4_turnaround_phase_is_5_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(4)
#define	FSMC_NORPSRAM4_turnaround_phase_is_6_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(5)
#define	FSMC_NORPSRAM4_turnaround_phase_is_7_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(6)
#define	FSMC_NORPSRAM4_turnaround_phase_is_8_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(7)
#define	FSMC_NORPSRAM4_turnaround_phase_is_9_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(8)
#define	FSMC_NORPSRAM4_turnaround_phase_is_10_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(9)
#define	FSMC_NORPSRAM4_turnaround_phase_is_11_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(10)
#define	FSMC_NORPSRAM4_turnaround_phase_is_12_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(11)
#define	FSMC_NORPSRAM4_turnaround_phase_is_13_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(12)
#define	FSMC_NORPSRAM4_turnaround_phase_is_14_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(13)
#define	FSMC_NORPSRAM4_turnaround_phase_is_15_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(14)
#define	FSMC_NORPSRAM4_turnaround_phase_is_16_HCLK()	FSMC_NORPSRAM4_set_BUSTURN(15)

/*
数据保持时间
Bits 15:8 DATAST: Data-phase duration
These bits are written by software to define the duration of the data phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous multiplexed NOR Flash 
accesses:
0000 0000: Reserved
0000 0001: DATAST phase duration = 2 × HCLK clock cycles
0000 0010: DATAST phase duration = 3 × HCLK clock cycles
...
1111 1111: DATAST phase duration = 256 × HCLK clock cycles (default value after reset)
For each memory type and access mode data-phase duration, please refer to the respective 
figure (Figure 187 to Figure 198).
Example: Mode1, read access, DATAST=1: Data-phase duration= DATAST+3 = 4 HCLK 
clock cycles.
*/
void FSMC_NORPSRAM1_set_DATAST(U16 sel);
void FSMC_NORPSRAM2_set_DATAST(U16 sel);
void FSMC_NORPSRAM3_set_DATAST(U16 sel);
void FSMC_NORPSRAM4_set_DATAST(U16 sel);

//sel = 2 - 256
#define FSMC_NORPSRAM1_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM1_set_DATAST(sel-1)
#define FSMC_NORPSRAM2_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM2_set_DATAST(sel-1)
#define FSMC_NORPSRAM3_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM3_set_DATAST(sel-1)
#define FSMC_NORPSRAM4_set_data_setup_phase_duration(sel)	FSMC_NORPSRAM4_set_DATAST(sel-1)


/*
地址保持时间
Bits 7:4 ADDHLD: Address-hold phase duration
These bits are written by software to define the duration of the address hold phase (refer to 
Figure 196 to Figure 198), used in mode D and multiplexed accesses:
0000: Reserved
0001: ADDHLD phase duration = 2 × HCLK clock cycle
0010: ADDHLD phase duration = 3 × HCLK clock cycle
...
1111: ADDHLD phase duration = 16 × HCLK clock cycles (default value after reset)
For  each access mode address-hold phase duration, please refer to the respective figure 
(Figure 196 to Figure 198).
Example: ModeD, read access, ADDHLD=1: Address-hold phase duration = ADDHLD + 1 =2 
HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM2_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM3_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM4_set_ADDHLD(U8 hld);

//hld = 2-16
#define FSMC_NORPSRAM1_set_address_hold_phase_duration(hld) FSMC_NORPSRAM1_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM2_set_address_hold_phase_duration(hld) FSMC_NORPSRAM2_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM3_set_address_hold_phase_duration(hld) FSMC_NORPSRAM3_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM4_set_address_hold_phase_duration(hld) FSMC_NORPSRAM4_set_ADDHLD(hld-1)

//NORPRAM存储块1地址保持时间 
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(1)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(2)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(3)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(4)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(5)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(6)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(7)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM1_set_ADDHLD(8)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(9)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(10)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(11)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(12)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(13)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(14)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM1_set_ADDHLD(15)

//NORPRAM存储块2地址保持时间 
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(1)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(2)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(3)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(4)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(5)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(6)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(7)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM2_set_ADDHLD(8)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(9)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(10)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(11)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(12)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(13)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(14)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM2_set_ADDHLD(15)

//NORPRAM存储块3地址保持时间 
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(1)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(2)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(3)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(4)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(5)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(6)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(7)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM3_set_ADDHLD(8)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(9)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(10)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(11)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(12)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(13)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(14)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM3_set_ADDHLD(15)


//NORPRAM存储块4地址保持时间 
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(1)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_3_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(2)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_4_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(3)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_5_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(4)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_6_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(5)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_7_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(6)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_8_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(7)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_9_HCLK()		FSMC_NORPSRAM4_set_ADDHLD(8)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_10_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(9)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_11_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(10)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_12_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(11)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_13_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(12)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_14_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(13)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_15_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(14)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_16_HCLK()	FSMC_NORPSRAM4_set_ADDHLD(15)



/*
地址建立时间
Bits 3:0 ADDSET: Address setup phase duration
These bits are written by software to define the duration of the address setup phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous NOR Flash:
0000: ADDSET phase duration = 1 × HCLK clock cycle
...
1111: ADDSET phase duration = 16 × HCLK clock cycles (default value after reset)
For each access mode address setup phase duration, please refer to the respective figure 
(refer to Figure 187 to Figure 198).
Example: Mode2, read access, ADDSET=1: Address setup phase duration = ADDSET + 1 = 
2 HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_set_ADDSET(U8 st);
void FSMC_NORPSRAM2_set_ADDSET(U8 st);
void FSMC_NORPSRAM3_set_ADDSET(U8 st);
void FSMC_NORPSRAM4_set_ADDSET(U8 st);

//st = 1- 16
#define FSMC_NORPSRAM1_set_address_setup_phase_duration(st)	FSMC_NORPSRAM1_set_ADDSET(st - 1)
#define FSMC_NORPSRAM2_set_address_setup_phase_duration(st)	FSMC_NORPSRAM2_set_ADDSET(st - 1)
#define FSMC_NORPSRAM3_set_address_setup_phase_duration(st)	FSMC_NORPSRAM3_set_ADDSET(st - 1)
#define FSMC_NORPSRAM4_set_address_setup_phase_duration(st)	FSMC_NORPSRAM4_set_ADDSET(st - 1)

//存储块1地址建立时间
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM1_set_ADDSET(0)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM1_set_ADDSET(1)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM1_set_ADDSET(2)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM1_set_ADDSET(3)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM1_set_ADDSET(4)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM1_set_ADDSET(5)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM1_set_ADDSET(6)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM1_set_ADDSET(7)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM1_set_ADDSET(8)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM1_set_ADDSET(9)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM1_set_ADDSET(10)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM1_set_ADDSET(11)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM1_set_ADDSET(12)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM1_set_ADDSET(13)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM1_set_ADDSET(14)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM1_set_ADDSET(15)

//存储块2地址建立时间
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM2_set_ADDSET(0)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM2_set_ADDSET(1)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM2_set_ADDSET(2)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM2_set_ADDSET(3)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM2_set_ADDSET(4)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM2_set_ADDSET(5)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM2_set_ADDSET(6)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM2_set_ADDSET(7)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM2_set_ADDSET(8)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM2_set_ADDSET(9)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM2_set_ADDSET(10)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM2_set_ADDSET(11)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM2_set_ADDSET(12)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM2_set_ADDSET(13)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM2_set_ADDSET(14)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM2_set_ADDSET(15)

//存储块3地址建立时间
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM3_set_ADDSET(0)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM3_set_ADDSET(1)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM3_set_ADDSET(2)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM3_set_ADDSET(3)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM3_set_ADDSET(4)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM3_set_ADDSET(5)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM3_set_ADDSET(6)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM3_set_ADDSET(7)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM3_set_ADDSET(8)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM3_set_ADDSET(9)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM3_set_ADDSET(10)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM3_set_ADDSET(11)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM3_set_ADDSET(12)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM3_set_ADDSET(13)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM3_set_ADDSET(14)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM3_set_ADDSET(15)

//存储块4地址建立时间
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_1_HCLK()	FSMC_NORPSRAM4_set_ADDSET(0)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK()	FSMC_NORPSRAM4_set_ADDSET(1)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_3_HCLK()	FSMC_NORPSRAM4_set_ADDSET(2)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_4_HCLK()	FSMC_NORPSRAM4_set_ADDSET(3)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_5_HCLK()	FSMC_NORPSRAM4_set_ADDSET(4)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_6_HCLK()	FSMC_NORPSRAM4_set_ADDSET(5)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_7_HCLK()	FSMC_NORPSRAM4_set_ADDSET(6)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_8_HCLK()	FSMC_NORPSRAM4_set_ADDSET(7)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_9_HCLK()	FSMC_NORPSRAM4_set_ADDSET(8)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_10_HCLK()	FSMC_NORPSRAM4_set_ADDSET(9)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_11_HCLK()	FSMC_NORPSRAM4_set_ADDSET(10)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_12_HCLK()	FSMC_NORPSRAM4_set_ADDSET(11)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_13_HCLK()	FSMC_NORPSRAM4_set_ADDSET(12)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_14_HCLK()	FSMC_NORPSRAM4_set_ADDSET(13)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_15_HCLK()	FSMC_NORPSRAM4_set_ADDSET(14)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_16_HCLK()	FSMC_NORPSRAM4_set_ADDSET(15)



//*********SRAM/NOR-Flash write timing registers 1..4 (FSMC_BWTR1..4)**********//
/*
写时序控制
Address offset: 0xA000 0000 + 0x104 + 8 * (x – 1), x = 1...4
Reset value: 0x0FFF FFFF
This register contains the control information of each memory bank, used for SRAMs, ROMs 
and NOR Flash memories. When the EXTMOD bit is set in the FSMC_BCRx register, then 
this register is active for write access.
*/
/*
访问模式
Bits 29:28 ACCMOD: Access mode
Specifies the asynchronous access modes as shown in the timing diagrams. These bits are 
taken into account only when the EXTMOD bit in the FSMC_BCRx register is 1.
00: access mode A
01: access mode B
10: access mode C
11: access mode D
*/
void FSMC_NORPSRAM1_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM2_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM3_W_set_ACCMOD(U8 mod);
void FSMC_NORPSRAM4_W_set_ACCMOD(U8 mod);


//选择模式A
#define FSMC_NORPSRAM1_access_mode_A_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(0)
#define FSMC_NORPSRAM2_access_mode_A_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(0)
#define FSMC_NORPSRAM3_access_mode_A_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(0)
#define FSMC_NORPSRAM4_access_mode_A_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(0)

//选择模式B
#define FSMC_NORPSRAM1_access_mode_B_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(1)
#define FSMC_NORPSRAM2_access_mode_B_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(1)
#define FSMC_NORPSRAM3_access_mode_B_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(1)
#define FSMC_NORPSRAM4_access_mode_B_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(1)

//选择模式C
#define FSMC_NORPSRAM1_access_mode_C_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(2)
#define FSMC_NORPSRAM2_access_mode_C_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(2)
#define FSMC_NORPSRAM3_access_mode_C_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(2)
#define FSMC_NORPSRAM4_access_mode_C_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(2)

//选择模式D
#define FSMC_NORPSRAM1_access_mode_D_when_write()	FSMC_NORPSRAM1_W_set_ACCMOD(3)
#define FSMC_NORPSRAM2_access_mode_D_when_write()	FSMC_NORPSRAM2_W_set_ACCMOD(3)
#define FSMC_NORPSRAM3_access_mode_D_when_write()	FSMC_NORPSRAM3_W_set_ACCMOD(3)
#define FSMC_NORPSRAM4_access_mode_D_when_write()	FSMC_NORPSRAM4_W_set_ACCMOD(3)

/*
数据保持时间(成组模式下)
Bits 27:24 DATLAT (see note below bit descriptions): Data latency (for synchronous burst NOR Flash)
For NOR Flash with synchronous burst mode enabled, defines the number of memory clock 
cycles (+2) to issue to the memory before getting the first data:
This timing parameter is not expressed in HCLK periods, but in Flash clock (CLK) periods. In 
asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care. In case of 
CRAM, this field must be set to 0
0000: Data latency of 2 CLK clock cycles for first burst access
.......
1111: Data latency of 17 CLK clock cycles for first burst access (default value after reset)
*/
void FSMC_NORPSRAM1_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM2_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM3_W_set_DATLAT(U8 sel);
void FSMC_NORPSRAM4_W_set_DATLAT(U8 sel);


//t = 2 - 17
#define FSMC_NORPSRAM1_W_set_latency_when_write(t)	FSMC_NORPSRAM1_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM2_W_set_latency_when_write(t)	FSMC_NORPSRAM2_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM3_W_set_latency_when_write(t)	FSMC_NORPSRAM3_W_set_DATLAT(t-2)
#define FSMC_NORPSRAM4_W_set_latency_when_write(t)	FSMC_NORPSRAM4_W_set_DATLAT(t-2)

//等待时间为2个CLK
#define FSMC_NORPSRAM1_latency_is_2_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(0)
#define FSMC_NORPSRAM2_latency_is_2_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(0)
#define FSMC_NORPSRAM3_latency_is_2_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(0)
#define FSMC_NORPSRAM4_latency_is_2_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(0)

//等待时间为3个CLK
#define FSMC_NORPSRAM1_latency_is_3_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(1)
#define FSMC_NORPSRAM3_latency_is_3_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(1)
#define FSMC_NORPSRAM4_latency_is_3_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(1)

//等待时间为4个CLK
#define FSMC_NORPSRAM1_latency_is_4_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(2)
#define FSMC_NORPSRAM2_latency_is_4_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(2)
#define FSMC_NORPSRAM3_latency_is_4_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(2)
#define FSMC_NORPSRAM4_latency_is_4_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(2)

//等待时间为5个CLK
#define FSMC_NORPSRAM1_latency_is_5_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(3)
#define FSMC_NORPSRAM2_latency_is_5_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(3)
#define FSMC_NORPSRAM3_latency_is_5_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(3)
#define FSMC_NORPSRAM4_latency_is_5_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(3)

//等待时间为6个CLK
#define FSMC_NORPSRAM1_latency_is_6_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(4)
#define FSMC_NORPSRAM2_latency_is_6_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(4)
#define FSMC_NORPSRAM3_latency_is_6_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(4)
#define FSMC_NORPSRAM4_latency_is_6_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(4)

//等待时间为7个CLK
#define FSMC_NORPSRAM1_latency_is_7_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(5)
#define FSMC_NORPSRAM2_latency_is_7_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(5)
#define FSMC_NORPSRAM3_latency_is_7_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(5)
#define FSMC_NORPSRAM4_latency_is_7_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(5)

//等待时间为8个CLK
#define FSMC_NORPSRAM1_latency_is_8_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(6)
#define FSMC_NORPSRAM2_latency_is_8_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(6)
#define FSMC_NORPSRAM3_latency_is_8_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(6)
#define FSMC_NORPSRAM4_latency_is_8_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(6)

//等待时间为9个CLK
#define FSMC_NORPSRAM1_latency_is_9_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(7)
#define FSMC_NORPSRAM2_latency_is_9_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(7)
#define FSMC_NORPSRAM3_latency_is_9_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(7)
#define FSMC_NORPSRAM4_latency_is_9_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(7)

//等待时间为10个CLK
#define FSMC_NORPSRAM1_latency_is_10_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(8)
#define FSMC_NORPSRAM2_latency_is_10_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(8)
#define FSMC_NORPSRAM3_latency_is_10_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(8)
#define FSMC_NORPSRAM4_latency_is_10_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(8)

//等待时间为11个CLK
#define FSMC_NORPSRAM1_latency_is_11_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(9)
#define FSMC_NORPSRAM2_latency_is_11_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(9)
#define FSMC_NORPSRAM3_latency_is_11_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(9)
#define FSMC_NORPSRAM4_latency_is_11_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(9)

//等待时间为12个CLK
#define FSMC_NORPSRAM1_latency_is_12_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(10)
#define FSMC_NORPSRAM2_latency_is_12_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(10)
#define FSMC_NORPSRAM3_latency_is_12_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(10)
#define FSMC_NORPSRAM4_latency_is_12_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(10)

//等待时间为13个CLK
#define FSMC_NORPSRAM1_latency_is_13_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(11)
#define FSMC_NORPSRAM2_latency_is_13_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(11)
#define FSMC_NORPSRAM3_latency_is_13_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(11)
#define FSMC_NORPSRAM4_latency_is_13_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(11)

//等待时间为14个CLK
#define FSMC_NORPSRAM1_latency_is_14_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(12)
#define FSMC_NORPSRAM2_latency_is_14_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(12)
#define FSMC_NORPSRAM3_latency_is_14_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(12)
#define FSMC_NORPSRAM4_latency_is_14_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(12)

//等待时间为15个CLK
#define FSMC_NORPSRAM1_latency_is_15_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(13)
#define FSMC_NORPSRAM2_latency_is_15_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(13)
#define FSMC_NORPSRAM3_latency_is_15_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(13)
#define FSMC_NORPSRAM4_latency_is_15_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(13)

//等待时间为16个CLK
#define FSMC_NORPSRAM1_latency_is_16_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(14)
#define FSMC_NORPSRAM2_latency_is_16_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(14)
#define FSMC_NORPSRAM3_latency_is_16_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(14)
#define FSMC_NORPSRAM4_latency_is_16_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(14)

//等待时间为17个CLK
#define FSMC_NORPSRAM1_latency_is_17_CLK_when_write()	FSMC_NORPSRAM1_W_set_DATLAT(15)
#define FSMC_NORPSRAM2_latency_is_17_CLK_when_write()	FSMC_NORPSRAM2_W_set_DATLAT(15)
#define FSMC_NORPSRAM3_latency_is_17_CLK_when_write()	FSMC_NORPSRAM3_W_set_DATLAT(15)
#define FSMC_NORPSRAM4_latency_is_17_CLK_when_write()	FSMC_NORPSRAM4_W_set_DATLAT(15)

/*
同步模式输出时钟分频 （HCLK分频）
Bits 23:20 CLKDIV: Clock divide ratio (for CLK signal)
Defines the period of CLK clock output signal, expressed in number of HCLK cycles:
0000: Reserved
0001: CLK period = 2 × HCLK periods
0010: CLK period = 3 × HCLK periods
1111: CLK period = 16 × HCLK periods (default value after reset) 
In asynchronous NOR Flash, SRAM or ROM accesses, this value is don’t care.
*/
void FSMC_NORPSRAM1_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM2_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM3_W_set_CLKDIV(U8 div);
void FSMC_NORPSRAM4_W_set_CLKDIV(U8 div);


//div = 2 - 16
#define FSMC_NORPSRAM1_set_div_when_write(div)	FSMC_NORPSRAM1_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM2_set_div_when_write(div)	FSMC_NORPSRAM2_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM3_set_div_when_write(div)	FSMC_NORPSRAM3_W_set_CLKDIV(div - 1)
#define FSMC_NORPSRAM4_set_div_when_write(div)	FSMC_NORPSRAM4_W_set_CLKDIV(div - 1)

//对NOR_PRAM存储块1的时钟分频
#define FSMC_NORPSRAM1_div_HCLK_with_2_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(1)
#define FSMC_NORPSRAM1_div_HCLK_with_3_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(2)
#define FSMC_NORPSRAM1_div_HCLK_with_4_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(3)
#define FSMC_NORPSRAM1_div_HCLK_with_5_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(4)
#define FSMC_NORPSRAM1_div_HCLK_with_6_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(5)
#define FSMC_NORPSRAM1_div_HCLK_with_7_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(6)
#define FSMC_NORPSRAM1_div_HCLK_with_8_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(7)
#define FSMC_NORPSRAM1_div_HCLK_with_9_when_write()			FSMC_NORPSRAM1_W_set_CLKDIV(8)
#define FSMC_NORPSRAM1_div_HCLK_with_10_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(9)
#define FSMC_NORPSRAM1_div_HCLK_with_11_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(10)
#define FSMC_NORPSRAM1_div_HCLK_with_12_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(11)
#define FSMC_NORPSRAM1_div_HCLK_with_13_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(12)
#define FSMC_NORPSRAM1_div_HCLK_with_14_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(13)
#define FSMC_NORPSRAM1_div_HCLK_with_15_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(14)
#define FSMC_NORPSRAM1_div_HCLK_with_16_when_write()		FSMC_NORPSRAM1_W_set_CLKDIV(15)

//对NOR_PRAM存储块2的时钟分频
#define FSMC_NORPSRAM2_div_HCLK_with_2_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(1)
#define FSMC_NORPSRAM2_div_HCLK_with_3_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(2)
#define FSMC_NORPSRAM2_div_HCLK_with_4_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(3)
#define FSMC_NORPSRAM2_div_HCLK_with_5_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(4)
#define FSMC_NORPSRAM2_div_HCLK_with_6_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(5)
#define FSMC_NORPSRAM2_div_HCLK_with_7_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(6)
#define FSMC_NORPSRAM2_div_HCLK_with_8_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(7)
#define FSMC_NORPSRAM2_div_HCLK_with_9_when_write()			FSMC_NORPSRAM2_W_set_CLKDIV(8)
#define FSMC_NORPSRAM2_div_HCLK_with_10_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(9)
#define FSMC_NORPSRAM2_div_HCLK_with_11_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(10)
#define FSMC_NORPSRAM2_div_HCLK_with_12_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(11)
#define FSMC_NORPSRAM2_div_HCLK_with_13_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(12)
#define FSMC_NORPSRAM2_div_HCLK_with_14_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(13)
#define FSMC_NORPSRAM2_div_HCLK_with_15_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(14)
#define FSMC_NORPSRAM2_div_HCLK_with_16_when_write()		FSMC_NORPSRAM2_W_set_CLKDIV(15)

//对NOR_PRAM存储块3的时钟分频
#define FSMC_NORPSRAM3_div_HCLK_with_2_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(1)
#define FSMC_NORPSRAM3_div_HCLK_with_3_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(2)
#define FSMC_NORPSRAM3_div_HCLK_with_4_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(3)
#define FSMC_NORPSRAM3_div_HCLK_with_5_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(4)
#define FSMC_NORPSRAM3_div_HCLK_with_6_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(5)
#define FSMC_NORPSRAM3_div_HCLK_with_7_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(6)
#define FSMC_NORPSRAM3_div_HCLK_with_8_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(7)
#define FSMC_NORPSRAM3_div_HCLK_with_9_when_write()			FSMC_NORPSRAM3_W_set_CLKDIV(8)
#define FSMC_NORPSRAM3_div_HCLK_with_10_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(9)
#define FSMC_NORPSRAM3_div_HCLK_with_11_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(10)
#define FSMC_NORPSRAM3_div_HCLK_with_12_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(11)
#define FSMC_NORPSRAM3_div_HCLK_with_13_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(12)
#define FSMC_NORPSRAM3_div_HCLK_with_14_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(13)
#define FSMC_NORPSRAM3_div_HCLK_with_15_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(14)
#define FSMC_NORPSRAM3_div_HCLK_with_16_when_write()		FSMC_NORPSRAM3_W_set_CLKDIV(15)

//对NOR_PRAM存储块4的时钟分频
#define FSMC_NORPSRAM4_div_HCLK_with_2_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(1)
#define FSMC_NORPSRAM4_div_HCLK_with_3_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(2)
#define FSMC_NORPSRAM4_div_HCLK_with_4_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(3)
#define FSMC_NORPSRAM4_div_HCLK_with_5_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(4)
#define FSMC_NORPSRAM4_div_HCLK_with_6_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(5)
#define FSMC_NORPSRAM4_div_HCLK_with_7_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(6)
#define FSMC_NORPSRAM4_div_HCLK_with_8_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(7)
#define FSMC_NORPSRAM4_div_HCLK_with_9_when_write()			FSMC_NORPSRAM4_W_set_CLKDIV(8)
#define FSMC_NORPSRAM4_div_HCLK_with_10_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(9)
#define FSMC_NORPSRAM4_div_HCLK_with_11_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(10)
#define FSMC_NORPSRAM4_div_HCLK_with_12_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(11)
#define FSMC_NORPSRAM4_div_HCLK_with_13_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(12)
#define FSMC_NORPSRAM4_div_HCLK_with_14_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(13)
#define FSMC_NORPSRAM4_div_HCLK_with_15_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(14)
#define FSMC_NORPSRAM4_div_HCLK_with_16_when_write()		FSMC_NORPSRAM4_W_set_CLKDIV(15)


/*
总线恢复时间 在总线复用时使用
Bits 19:16 BUSTURN: Bus turnaround phase duration . just active in mul mode
These bits are written by software to introduce the bus turnaround delay after a read access 
(only from multiplexed NOR Flash memory) to avoid bus contention if the controller needs to 
drive addresses on the databus for the next side-by-side transaction. BUSTURN can be set 
to the minimum if the memory system does not include multiplexed memories or if the 
slowest memory does not take more than 6 HCLK clock cycles to put the databus in Hi-Z 
state:
0000: BUSTURN phase duration = 1 × HCLK clock cycle
...
1111: BUSTURN phase duration = 16 × HCLK clock cycles (default value after reset)
*/
void FSMC_NORPSRAM1_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM2_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM3_W_set_BUSTURN(U8 sel);
void FSMC_NORPSRAM4_W_set_BUSTURN(U8 sel);

//sel = 1 -16
#define FSMC_NORPSRAM1_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM1_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM2_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM2_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM3_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM3_set_BUSTURN(sel-1)
#define FSMC_NORPSRAM4_set_turnaround_phase_when_write(sel)	FSMC_NORPSRAM4_set_BUSTURN(sel-1)

//NORPRAM存储块1的总线恢复时间
#define	FSMC_NORPSRAM1_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(0)
#define	FSMC_NORPSRAM1_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(1)
#define	FSMC_NORPSRAM1_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(2)
#define	FSMC_NORPSRAM1_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(3)
#define	FSMC_NORPSRAM1_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(4)
#define	FSMC_NORPSRAM1_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(5)
#define	FSMC_NORPSRAM1_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(6)
#define	FSMC_NORPSRAM1_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(7)
#define	FSMC_NORPSRAM1_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(8)
#define	FSMC_NORPSRAM1_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(9)
#define	FSMC_NORPSRAM1_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(10)
#define	FSMC_NORPSRAM1_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(11)
#define	FSMC_NORPSRAM1_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(12)
#define	FSMC_NORPSRAM1_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(13)
#define	FSMC_NORPSRAM1_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(14)
#define	FSMC_NORPSRAM1_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM1_set_BUSTURN(15)


//NORPRAM存储块2的总线恢复时间
#define	FSMC_NORPSRAM2_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(0)
#define	FSMC_NORPSRAM2_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(1)
#define	FSMC_NORPSRAM2_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(2)
#define	FSMC_NORPSRAM2_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(3)
#define	FSMC_NORPSRAM2_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(4)
#define	FSMC_NORPSRAM2_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(5)
#define	FSMC_NORPSRAM2_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(6)
#define	FSMC_NORPSRAM2_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(7)
#define	FSMC_NORPSRAM2_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(8)
#define	FSMC_NORPSRAM2_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(9)
#define	FSMC_NORPSRAM2_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(10)
#define	FSMC_NORPSRAM2_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(11)
#define	FSMC_NORPSRAM2_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(12)
#define	FSMC_NORPSRAM2_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(13)
#define	FSMC_NORPSRAM2_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(14)
#define	FSMC_NORPSRAM2_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM2_set_BUSTURN(15)


//NORPRAM存储块3的总线恢复时间
#define	FSMC_NORPSRAM3_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(0)
#define	FSMC_NORPSRAM3_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(1)
#define	FSMC_NORPSRAM3_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(2)
#define	FSMC_NORPSRAM3_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(3)
#define	FSMC_NORPSRAM3_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(4)
#define	FSMC_NORPSRAM3_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(5)
#define	FSMC_NORPSRAM3_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(6)
#define	FSMC_NORPSRAM3_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(7)
#define	FSMC_NORPSRAM3_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(8)
#define	FSMC_NORPSRAM3_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(9)
#define	FSMC_NORPSRAM3_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(10)
#define	FSMC_NORPSRAM3_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(11)
#define	FSMC_NORPSRAM3_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(12)
#define	FSMC_NORPSRAM3_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(13)
#define	FSMC_NORPSRAM3_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(14)
#define	FSMC_NORPSRAM3_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM3_set_BUSTURN(15)


//NORPRAM存储块4的总线恢复时间
#define	FSMC_NORPSRAM4_turnaround_phase_is_1_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(0)
#define	FSMC_NORPSRAM4_turnaround_phase_is_2_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(1)
#define	FSMC_NORPSRAM4_turnaround_phase_is_3_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(2)
#define	FSMC_NORPSRAM4_turnaround_phase_is_4_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(3)
#define	FSMC_NORPSRAM4_turnaround_phase_is_5_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(4)
#define	FSMC_NORPSRAM4_turnaround_phase_is_6_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(5)
#define	FSMC_NORPSRAM4_turnaround_phase_is_7_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(6)
#define	FSMC_NORPSRAM4_turnaround_phase_is_8_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(7)
#define	FSMC_NORPSRAM4_turnaround_phase_is_9_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(8)
#define	FSMC_NORPSRAM4_turnaround_phase_is_10_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(9)
#define	FSMC_NORPSRAM4_turnaround_phase_is_11_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(10)
#define	FSMC_NORPSRAM4_turnaround_phase_is_12_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(11)
#define	FSMC_NORPSRAM4_turnaround_phase_is_13_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(12)
#define	FSMC_NORPSRAM4_turnaround_phase_is_14_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(13)
#define	FSMC_NORPSRAM4_turnaround_phase_is_15_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(14)
#define	FSMC_NORPSRAM4_turnaround_phase_is_16_HCLK_when_write()	FSMC_NORPSRAM4_set_BUSTURN(15)


/*
数据保持时间
Bits 15:8 DATAST: Data-phase duration
These bits are written by software to define the duration of the data phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous multiplexed NOR Flash 
accesses:
0000 0000: Reserved
0000 0001: DATAST phase duration = 2 × HCLK clock cycles
0000 0010: DATAST phase duration = 3 × HCLK clock cycles
...
1111 1111: DATAST phase duration = 256 × HCLK clock cycles (default value after reset)
For each memory type and access mode data-phase duration, please refer to the respective 
figure (Figure 187 to Figure 198).
Example: Mode1, read access, DATAST=1: Data-phase duration= DATAST+3 = 4 HCLK 
clock cycles.
*/
void FSMC_NORPSRAM1_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM2_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM3_W_set_DATAST(U8 sel);
void FSMC_NORPSRAM4_W_set_DATAST(U8 sel);


//sel = 2 - 256
#define FSMC_NORPSRAM1_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM1_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM2_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM2_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM3_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM3_W_set_DATAST(sel-1)
#define FSMC_NORPSRAM4_set_data_phase_duration_when_write(sel)	FSMC_NORPSRAM4_W_set_DATAST(sel-1)


/*
地址保持时间
Bits 7:4 ADDHLD: Address-hold phase duration
These bits are written by software to define the duration of the address hold phase (refer to 
Figure 196 to Figure 198), used in mode D and multiplexed accesses:
0000: Reserved
0001: ADDHLD phase duration = 2 × HCLK clock cycle
0010: ADDHLD phase duration = 3 × HCLK clock cycle
...
1111: ADDHLD phase duration = 16 × HCLK clock cycles (default value after reset)
For  each access mode address-hold phase duration, please refer to the respective figure 
(Figure 196 to Figure 198).
Example: ModeD, read access, ADDHLD=1: Address-hold phase duration = ADDHLD + 1 =2 
HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM2_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM3_W_set_ADDHLD(U8 hld);
void FSMC_NORPSRAM4_W_set_ADDHLD(U8 hld);


//hld = 2-16
#define FSMC_NORPSRAM1_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM1_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM2_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM2_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM3_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM3_W_set_ADDHLD(hld-1)
#define FSMC_NORPSRAM4_set_address_hold_phase_duration_when_write(hld) FSMC_NORPSRAM4_W_set_ADDHLD(hld-1)

//NORPRAM存储块1地址保持时间 
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(1)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(2)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(3)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(4)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(5)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(6)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(7)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(8)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(9)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(10)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(11)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(12)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(13)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(14)
#define FSMC_NORPSRAM1_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDHLD(15)

//NORPRAM存储块2地址保持时间 
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(1)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(2)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(3)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(4)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(5)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(6)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(7)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(8)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(9)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(10)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(11)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(12)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(13)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(14)
#define FSMC_NORPSRAM2_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDHLD(15)

//NORPRAM存储块3地址保持时间 
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(1)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(2)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(3)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(4)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(5)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(6)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(7)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(8)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(9)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(10)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(11)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(12)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(13)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(14)
#define FSMC_NORPSRAM3_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDHLD(15)


//NORPRAM存储块4地址保持时间 
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(1)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(2)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(3)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(4)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(5)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(6)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(7)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(8)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_10_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(9)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_11_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(10)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_12_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(11)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_13_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(12)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_14_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(13)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_15_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(14)
#define FSMC_NORPSRAM4_address_hold_phase_duration_is_16_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDHLD(15)


/*
地址建立时间
Bits 3:0 ADDSET: Address setup phase duration
These bits are written by software to define the duration of the address setup phase (refer to 
Figure 187 to Figure 198), used in SRAMs, ROMs and asynchronous NOR Flash:
0000: ADDSET phase duration = 1 × HCLK clock cycle
...
1111: ADDSET phase duration = 16 × HCLK clock cycles (default value after reset)
For each access mode address setup phase duration, please refer to the respective figure 
(refer to Figure 187 to Figure 198).
Example: Mode2, read access, ADDSET=1: Address setup phase duration = ADDSET + 1 = 
2 HCLK clock cycles.
Note: In synchronous accesses, this value is not used, the address hold phase is always 1 
memory clock period duration.
*/
void FSMC_NORPSRAM1_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM2_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM3_W_set_ADDSET(U8 st);
void FSMC_NORPSRAM4_W_set_ADDSET(U8 st);


//st = 1- 16
#define FSMC_NORPSRAM1_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM1_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM2_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM2_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM3_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM3_W_set_ADDSET(st - 1)
#define FSMC_NORPSRAM4_set_address_setup_phase_duration_when_write(st)	FSMC_NORPSRAM4_W_set_ADDSET(st - 1)

//存储块1地址建立时间
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(0)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(1)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(2)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(3)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(4)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(5)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(6)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(7)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM1_W_set_ADDSET(8)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(9)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(10)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(11)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(12)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(13)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(14)
#define FSMC_NORPSRAM1_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM1_W_set_ADDSET(15)

//存储块2地址建立时间
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(0)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(1)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(2)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(3)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(4)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(5)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(6)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(7)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM2_W_set_ADDSET(8)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(9)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(10)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(11)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(12)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(13)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(14)
#define FSMC_NORPSRAM2_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM2_W_set_ADDSET(15)

//存储块3地址建立时间
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(0)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(1)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(2)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(3)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(4)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(5)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(6)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(7)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM3_W_set_ADDSET(8)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(9)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(10)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(11)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(12)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(13)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(14)
#define FSMC_NORPSRAM3_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM3_W_set_ADDSET(15)

//存储块4地址建立时间
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_1_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(0)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_2_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(1)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_3_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(2)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_4_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(3)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_5_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(4)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_6_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(5)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_7_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(6)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_8_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(7)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_9_HCLK_when_write()		FSMC_NORPSRAM4_W_set_ADDSET(8)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_10_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(9)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_11_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(10)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_12_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(11)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_13_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(12)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_14_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(13)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_15_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(14)
#define FSMC_NORPSRAM4_address_setup_phase_duration_is_16_HCLK_when_write()	FSMC_NORPSRAM4_W_set_ADDSET(15)

#endif

