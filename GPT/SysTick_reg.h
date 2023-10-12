/******************************************************************
 * @Title    : SysTick Peripherals Register Map for ARM Cortex-M4 
 * @Filename : SysTick_reg.h
 * @Author   : Hossam Mohamed
 * @Compiler : IAR
 * @Target   : Tiva-C (Tm4c123gh6pm)
 * @Notes 	 : this file lists the Cortex-M4 Peripheral SysTick registers
 ********************************************************************/

#ifndef SYS_TICK_REG_H_
#define SYS_TICK_REG_H_

#include "STD_TYPES.h"

/* Core Peripheral Base Address */
#define CORE_PERI_BASE_ADDRESS 0xE000E000

/* System Timer (SysTick) Registers offset */
#define STCTRL_OFFSET		   0x010
#define STRELOAD_OFFSET		   0x014
#define STCURRENT_OFFSET	   0x018
#define SYSPRI3_OFFSET		   0xD20

/* System Timer (SysTick) Registers Structure */

/************************************************************************************************
 * 						 SysTick Control and Status Register (STCTRL) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:17           Reserved           RO                    Reserved
 * 16              COUNT 		      RO                    Count Flag
 * 15:3 		   Reserved           RO                    Reserved
 * 2 			   CLK_SRC 		      RW                    Clock Source
 * 1 			   INTEN 			  RW                    Interrupt Enable
 * 0 			   ENABLE 			  RW                    Counter Enable
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 ENABLE	  : 1;
		uint32 INTEN	  : 1;
		uint32 CLK_SRC	  : 1;
		uint32			  : 13;
		uint32 COUNT_FLAG : 1; // Read only
		uint32			  : 15;
	} bits;
} SYSTICK_CTRL_REG_t;

/************************************************************************************************
 * 						 SysTick Reload Value Register (STRELOAD) 								*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24           Reserved           RO                    Reserved
 * 23:0            RELOAD 		      RW                    RELOAD Value
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 RELOAD : 24;
		uint32		  : 8;
	} bits;
} SYSTICK_LOAD_REG_t;

/************************************************************************************************
 * 						 SysTick Current Value Register (STCURRENT) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24           Reserved           RO                    Reserved
 * 23:0            CURRENT 		      RWC                   CURRENT Value
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 CURRENT : 24;
		uint32		   : 8;
	} bits;
} SYSTICK_CURRENT_REG_t;

/************************************************************************************************
 * 						 System Handler Priority 3 Register (SYSPRI3) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:29		   TICK 		      RW                    SysTick Exception Priority
 * 28:24 		   Reserved           RO                    Reserved
 * 23:21 		   PENDSV 		      RW                    PendSV Priority
 * 20:8 		   Reserved           RO                    Reserved
 * 7:5 			   DEBUG 		      RW                    Debug Monitor Priority
 * 4:0 			   Reserved           RO                    Reserved
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32		  : 5;
		uint32 DEBUG  : 3;
		uint32		  : 13;
		uint32 PENDSV : 3;
		uint32		  : 5;
		uint32 TICK	  : 3;
	} bits;
} SYSPRI3_REG_t;

#define STCTRL	  (*((volatile SYSTICK_CTRL_REG_t*)(CORE_PERI_BASE_ADDRESS + STCTRL_OFFSET)))
#define STRELOAD  (*((volatile SYSTICK_LOAD_REG_t*)(CORE_PERI_BASE_ADDRESS + STRELOAD_OFFSET)))
#define STCURRENT (*((volatile SYSTICK_CURRENT_REG_t*)(CORE_PERI_BASE_ADDRESS + STCURRENT_OFFSET)))
#define SYSPRI3	  (*((volatile SYSPRI3_REG_t*)(CORE_PERI_BASE_ADDRESS + SYSPRI3_OFFSET)))

#endif /* SYS_TICK_REG_H_ */