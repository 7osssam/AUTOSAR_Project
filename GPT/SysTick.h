/******************************************************************
 * @Title    : System Tick Driver Header
 * @Filename : SysTick.h
 * @Author   : Hossam Mohamed
 * @Compiler : IAR
 * @Target   : Tiva-C (Tm4c123gh6pm)
 ********************************************************************/
#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "common_macros.h"
#include "STD_TYPES.h"

#define SYSTICK_PRIORITY (3U)

typedef enum
{
	PIOSC_4 = 0, /* use PIOSC/4 clock */
	SYS_CLK = 1	 /* use system clock */
} SysTick_CLK_SRC;

typedef enum
{
	INT_DISABLE = 0,
	INT_ENABLE = 1
} SysTick_INT;

/* Configuration structure for the SysTick driver */
typedef struct
{
	SysTick_CLK_SRC ClkSrc;
	SysTick_INT		Int;
	uint32			ReloadValue;
} SysTick_ConfigType;

void SysTick_init(const SysTick_ConfigType* Config_Ptr, uint32 N);
void SysTick_SetPriority(uint8 ExceptionPriority);
void SysTick_enableException(void);
void SysTick_disableException(void);
void SysTick_SetCallBack(void (*Ptr2Func)(void));

/* Global configuration structure to be used by the user to set the systick configuration */
extern const SysTick_ConfigType SysTick_Configuration;

#endif /* SYS_TICK_H_ */