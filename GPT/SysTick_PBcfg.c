/******************************************************************
 * @Module   	: 
 * @Title 	 	: 
 * @Filename 	: 
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#include "SysTick.h"

#define RELOAD_VALUE_1MS (16000U)

const SysTick_ConfigType SysTick_Configuration = {
	.ClkSrc = SYS_CLK, .Int = INT_ENABLE, .ReloadValue = RELOAD_VALUE_1MS};
