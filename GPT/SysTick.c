/******************************************************************
 * @Title    : System Tick Driver Source
 * @Filename : SysTick.c
 * @Author   : Hossam Mohamed
 * @Compiler : IAR
 * @Target   : Tiva-C (Tm4c123gh6pm)
 * @Notes 	 :
 ********************************************************************/

#include "sysTick.h"
#include "SysTick_reg.h"

/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static void (*g_SysTick_Call_Back_Ptr)(void) = NULL_PTR;

/**
 * The SysTick_Handler function checks if a callback function has been set and calls it if it has.
 */
void SysTick_Handler(void)
{
	/* Check if the Timer0_setCallBack is already called */
	if (g_SysTick_Call_Back_Ptr != NULL_PTR)
	{
		(*g_SysTick_Call_Back_Ptr)(); /* call the function in the scheduler using call-back concept */
	}
	/* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
}

/**
 * @brief Initialize the SysTick timer with the specified configuration.
 *
 * This function initializes the SysTick timer with the provided configuration settings.
 * It allows you to specify the clock source, reload value, and interrupt enable/disable
 * for the SysTick timer.
 *
 * @param Config_Ptr A pointer to a SysTick_ConfigType structure containing the
 *                   configuration settings for the SysTick timer.
 *
 * @note This function assumes that the SysTick timer is correctly set up in the hardware.
 *       Ensure that the clock source, reload value, and interrupt settings are compatible
 *       with the hardware and application requirements.
 *
 * @param[in] Config_Ptr Pointer to the configuration structure.
 * @param[in] N The number of clock cycles to wait before the timer expires.
 *
 * @see SysTick_CLK_SRC
 * @see SysTick_INT
 *
 * @return None
 */
void SysTick_init(const SysTick_ConfigType* Config_Ptr, uint32 N)
{
	/* disable systick */
	STCTRL.bits.ENABLE = 0;

	/* Set clock source
	 * 0: PIOSC/4
	 * 1: System Clock */
	STCTRL.bits.CLK_SRC = Config_Ptr->ClkSrc;

	/* Set reload value */
	STRELOAD.bits.RELOAD = (Config_Ptr->ReloadValue - 1) * N;

	/* Set interrupt enable
	 * 0: Disable
	 * 1: Enable */
	STCTRL.bits.INTEN = Config_Ptr->Int;

	/* enable systick */
	STCTRL.bits.ENABLE = 1;
}

/**
 * @brief Set the SysTick timer priority.
 *
 * This function sets the SysTick timer priority.
 *
 * @param ExceptionPriority The priority for the SysTick timer interrupt.
 *
 * @note This function assumes that the SysTick timer is correctly set up in the hardware.
 *       Ensure that the SysTick timer interrupt is enabled in the NVIC.
 *
 * @note This function should be called after SysTick_init() function.
 *
 * @return None
 */
void SysTick_SetPriority(uint8 ExceptionPriority)
{
	/*Make Sure That Total Priority Doesnot Exceed 3 Bits*/
	ExceptionPriority &= 0x00000007;

	/* set priority of the systick interrupt using TICK field in SYSPRI3 register in SCB */
	SYSPRI3.bits.TICK = ExceptionPriority;
}

/**
 * @brief Enable the SysTick timer exception.
 *
 * This function enables the SysTick timer exception.
 *
 * @return None
 */
void SysTick_enableException(void)
{
	/* Set interrupt enable
	 * 0: Disable
	 * 1: Enable */
	STCTRL.bits.INTEN = 1;
}

/**
 * @brief Disable the SysTick timer exception.
 *
 * This function disables the SysTick timer exception.
 *
 * @return None
 */
void SysTick_disableException(void)
{
	/* Set interrupt enable
	 * 0: Disable
	 * 1: Enable */
	STCTRL.bits.INTEN = 0;
}

void SysTick_SetCallBack(void (*Ptr2Func)(void))
{
	g_SysTick_Call_Back_Ptr = Ptr2Func;
}