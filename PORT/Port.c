/******************************************************************
 * @Module   	: Port
 * @Title 	 	: PORT Module Source file 
 * @Filename 	: Port.c
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#include "Port.h"
#include "Peripheral_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

	#include "Det.h"

	/* AUTOSAR Version checking between Det and PORT Modules */
	#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
		 (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || \
		 (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif

#endif

/************************************************************************************
 * 								Private Macros										*
 ************************************************************************************/

/* Number defined by the TM4C123GH6PM MCU creators to unlock GPIO Commit Register */
#define UNLOCK_GPIOCR ((uint32)0x4C4F434B)

/* Mask of the 4 bits of the PMCx bits in the GPIOAFSEL register */
#define BYTE_MASK	  ((uint32)0x0000000F)

/* Macros to write value to the PMCx bits in the GPIOAFSEL register */
#define WRITE_PMCx_VALUE(PORT, BIT, VALUE) \
	(*GPIOPCTL[PORT] = ((*GPIOPCTL[PORT] & ~(BYTE_MASK << (BIT * 4))) | (VALUE << (BIT * 4))))

/************************************************************************************
 * 								Private Functions									*
 ************************************************************************************/

/************************************************************************************
 * Description : The function GPIO_unlock unlocks a specific GPIO pin on a given port.
 * 
 * @param port The port parameter is the number of the GPIO port that you want to unlock. It is
 * typically represented as a number from 0 to 7, where each number corresponds to a specific GPIO port
 * on the microcontroller.
 * @param pin The pin number of the GPIO port that needs to be unlocked.
 ************************************************************************************/
static void GPIO_unlock(uint8 port, uint8 pin)
{
	/* Unlock the GPIO_CR register */
	*GPIOLOCK[port] = UNLOCK_GPIOCR;
	/* Allow changes on GPIO_CR register */
	SET_BIT(*GPIOCR[port], pin);
}

/************************************************************************************
 * Description : The function GPIO_clk_enable enables the clock for a given port in C.
 * 
 * @param port The parameter "port" is a uint8 variable that represents the port number for which the
 * clock needs to be enabled.
 ************************************************************************************/
static void GPIO_clk_enable(uint8 port)
{
	/* Enable the clock for the given port */

	//SET_MASK(RCGCGPIO, BIT(g_Port_ConfigPtr[ID].Port_Number));
	SET_MASK(RCGCGPIO, BIT(port));

	/* delay to make sure that the clock is enabled */
	volatile uint32 delay = RCGCGPIO;
}

/************************************************************************************
 * 								Global Variables									*
 ************************************************************************************/
STATIC const Port_ConfigPins* g_Port_ConfigPtr = NULL_PTR;
STATIC uint8				  g_Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name		: Port_Init
* Service ID[hex]	: 0x00
* Sync/Async		: Synchronous
* Reentrancy		: Non Reentrant
* Parameters (in)	: ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out)	: None
* Return value		: None
* Description		: Function to initialize the Port module:
*              			- Setup the direction of the pin
*              			- Setup the mode of the pin
*              			- Provide initial value for o/p pin
*              			- Setup the internal resistor for ID/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
	}
	else
#endif
	/* In-case there are no errors */
	{
		/* Save the PB configuration structure pointer in a global pointer so that it can be used by
		 * other functions to read the PB configuration structures and point to  
		 * the first Port_ConfigPins structure --> Port_Configuration.Pins[0]*/
		g_Port_ConfigPtr = ConfigPtr->Pins;

		/* Loop through all the pins in the Pins structure */
		for (uint8 ID = STD_LOW; ID < PORT_CONFIGURED_PINS; ID++)
		{
			/**************************** Clock Enable ********************************/
			GPIO_clk_enable(g_Port_ConfigPtr[ID].Port_Number);

			/**************************** Unlock GPIOCR *******************************/
			/* Unlock GPIOCR for PD7 or PF0 */
			if ((PORTF == g_Port_ConfigPtr[ID].Port_Number && PIN0 == g_Port_ConfigPtr[ID].Pin_Number) ||
				(PORTD == g_Port_ConfigPtr[ID].Port_Number && PIN7 == g_Port_ConfigPtr[ID].Pin_Number))
			{
				GPIO_unlock(g_Port_ConfigPtr[ID].Port_Number, g_Port_ConfigPtr[ID].Pin_Number);
			}
			/* PC0 to PC3 - JTAG pins */
			else if (PORTC == g_Port_ConfigPtr[ID].Port_Number && PIN3 >= g_Port_ConfigPtr[ID].Pin_Number)
			{
				/* Do Nothing ...  this is the JTAG pins */
			}
			else
			{
				/* Do Nothing ... No need to unlock the commit register for this pin */
			}

			/**************************** Direction ***********************************/
			if (PORT_PIN_OUT == (Port_PinDirectionType)g_Port_ConfigPtr[ID].Pin_Direction)
			{
				SET_BIT(*GPIODIR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);

				/**************************** Initial Value *******************************/
				if (STD_HIGH == g_Port_ConfigPtr[ID].Pin_Initial_Value)
				{
					SET_BIT(*GPIODATA[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
				else if (STD_LOW == g_Port_ConfigPtr[ID].Pin_Initial_Value)
				{
					CLEAR_BIT(*GPIODATA[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
				else
				{
					/* Do Nothing */
				}
			}
			else if (PORT_PIN_IN == (Port_PinDirectionType)g_Port_ConfigPtr[ID].Pin_Direction)
			{
				CLEAR_BIT(*GPIODIR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);

				//**************************** Resistor ************************************
				if (g_Port_ConfigPtr[ID].Pin_Resistor == PULL_UP)
				{
					/* Enable the internal pull up resistor for the selected pin */
					SET_BIT(*GPIOPUR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
				else if (g_Port_ConfigPtr[ID].Pin_Resistor == PULL_DOWN)
				{
					SET_BIT(*GPIOPDR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
				else
				{
					CLEAR_BIT(*GPIOPUR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
					CLEAR_BIT(*GPIOPDR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
			}
			else
			{
				/* Do Nothing */
			}

			//**************************** Mode Select ********************************
			/* Check if the pin is a GPIO pin or analog pin */
			if ((PORT_GPIO_MODE == (Port_PinMode)g_Port_ConfigPtr[ID].Pin_Mode) ||
				(ADC_MODE_ID == (Port_PinMode)g_Port_ConfigPtr[ID].Pin_Mode) ||
				(ANALOG_COMPARATOR_MODE_ID == (Port_PinMode)g_Port_ConfigPtr[ID].Pin_Mode) ||
				(ANALOG_MODE_ID == (Port_PinMode)g_Port_ConfigPtr[ID].Pin_Mode))
			{
				/* Disable alternate function */
				CLEAR_BIT(*GPIOAFSEL[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);

				/* Clear PMCx bits for the selected pin to use it as GPIO pin */
				WRITE_PMCx_VALUE(g_Port_ConfigPtr[ID].Port_Number, g_Port_ConfigPtr[ID].Pin_Number, STD_LOW);

				/************************* GPIO Mode **********************************/
				if (PORT_GPIO_MODE == (Port_PinMode)g_Port_ConfigPtr[ID].Pin_Mode)
				{
					/* Disable analog mode */
					CLEAR_BIT(*GPIOAMSEL[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
					/* Enable digital mode */
					SET_BIT(*GPIODEN[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
				/************************* Analog Mode **********************************/
				else
				{
					/* Enable analog mode */
					SET_BIT(*GPIOAMSEL[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
					/* Disable digital mode */
					CLEAR_BIT(*GPIODEN[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				}
			}
			else /* alternate function pin */
			{
				/* Enable alternate function */
				SET_BIT(*GPIOAFSEL[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				/* Set PMCx bits for the selected pin to use it as the selected alternate function */
				WRITE_PMCx_VALUE(g_Port_ConfigPtr[ID].Port_Number, g_Port_ConfigPtr[ID].Pin_Number,
								 g_Port_ConfigPtr[ID].Pin_Mode);
				/* Disable analog mode */
				CLEAR_BIT(*GPIOAMSEL[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
				/* Enable digital mode */
				SET_BIT(*GPIODEN[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
			}
		}

		/*
		 	* Set the module state to initialized
		 	*/
		g_Port_Status = PORT_INITIALIZED;
	}
}

/************************************************************************************
* Service Name		: Port_SetPinDirection
* Service ID[hex]	: 0x01
* Sync/Async		: Synchronous
* Reentrancy		: Reentrant
* Parameters (in)	: Pin - Port Pin ID number, Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out)	: None
* Return value		: None
* Description		: Function to Set the direction of the pin
************************************************************************************/
#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	/* Local variable to hold the error status */
	boolean error = FALSE;

	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input pin number is within the valid range */
	if (Pin >= PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Check if the Port driver is initialized before using any API */
	if (PORT_NOT_INITIALIZED == g_Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Check if the input pin is not configured as changeable */
	if (STD_OFF == g_Port_ConfigPtr[Pin].Pin_Direction_Changeable)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
						PORT_E_DIRECTION_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	#endif

	/* In-case there are no errors */
	if (FALSE == error)
	{
		/**************************** Direction ***********************************/
		if (PORT_PIN_OUT == Direction)
		{
			SET_BIT(*GPIODIR[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
		}
		else if (PORT_PIN_IN == Direction)
		{
			CLEAR_BIT(*GPIODIR[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
}
#endif /* PORT_SET_PIN_DIRECTION_API */

/************************************************************************************
* Service Name		: Port_RefreshPortDirection
* Service ID[hex]	: 0x02
* Sync/Async		: Synchronous
* Reentrancy		: Non Reentrant
* Parameters (in)	: None
* Parameters (inout): None
* Parameters (out)	: None
* Return value		: None
* Description		: Function to Refresh the direction of the pin and return it to the 
*					  original configured value 
************************************************************************************/
void Port_RefreshPortDirection(void)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Port driver is initialized before using any API */
	if (PORT_NOT_INITIALIZED == g_Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
	}
	else
#endif
	{
		for (uint8 ID = STD_LOW; ID < PORT_CONFIGURED_PINS; ID++)
		{
			/**************************** Direction ***********************************/
			if (PORT_PIN_OUT == g_Port_ConfigPtr[ID].Pin_Direction)
			{
				SET_BIT(*GPIODIR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
			}
			else if (PORT_PIN_IN == g_Port_ConfigPtr[ID].Pin_Direction)
			{
				CLEAR_BIT(*GPIODIR[g_Port_ConfigPtr[ID].Port_Number], g_Port_ConfigPtr[ID].Pin_Number);
			}
			else
			{
				/* Do Nothing */
			}
		}
	}
}
/************************************************************************************
* Service Name		: Port_GetVersionInfo
* Service ID[hex]	: 0x03
* Sync/Async		: Synchronous
* Reentrancy		: Non Reentrant
* Parameters (in)	: None
* Parameters (inout): None
* Parameters (out)	: versioninfo 
*					 - Pointer to where to store the version information of this module.
* Return value		: None
* Description		: Function to Return the version information of this module.
************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if (NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}

/************************************************************************************
* Service Name		: Port_SetPinMode
* Service ID[hex]	: 0x04
* Sync/Async		: Synchronous
* Reentrancy		: Reentrant
* Parameters (in)	: Pin 
*					 - Port Pin ID number, Mode - New Port Pin mode to be set on port pin. 
* Parameters (inout): None
* Parameters (out)	: None
* Return value		: None
* Description		: Function to Set the mode of the pin
************************************************************************************/ \
#if (STD_ON == PORT_SET_PIN_MODE_API)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	/* Local variable to hold the error status */
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input pin number is within the valid range */
	if (Pin >= PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Check if the input mode is within the valid range */
	if (GROUP_14_MODE_ID < Mode || INVALID_MODE_ID == Mode)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Check if the input pin is not configured as changeable */
	if (STD_OFF == g_Port_ConfigPtr[Pin].Pin_Mode_Changeable)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}

	/* Check if the Port driver is initialized before using any API */
	if (PORT_NOT_INITIALIZED == g_Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	#endif

	/* In-case there are no errors */
	if (FALSE == error)
	{ /* Check if the pin is a GPIO pin or analog pin */
		if ((PORT_GPIO_MODE == Mode) || (ADC_MODE_ID == Mode) || (ANALOG_COMPARATOR_MODE_ID == Mode) ||
			(ANALOG_MODE_ID == Mode))
		{
			/* Disable alternate function */
			CLEAR_BIT(*GPIOAFSEL[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
			/* Clear PMCx bits for the selected pin to use it as GPIO pin */
			WRITE_PMCx_VALUE(g_Port_ConfigPtr[Pin].Port_Number, g_Port_ConfigPtr[Pin].Pin_Number, STD_LOW);

			/************************* GPIO Mode **********************************/
			if (PORT_GPIO_MODE == Mode)
			{
				/* Disable analog mode */
				CLEAR_BIT(*GPIOAMSEL[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
				/* Enable digital mode */
				SET_BIT(*GPIODEN[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
			}
			/************************* Analog Mode **********************************/
			else
			{
				/* Enable analog mode */
				SET_BIT(*GPIOAMSEL[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
				/* Disable digital mode */
				CLEAR_BIT(*GPIODEN[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
			}
		}
		else /* alternate function pin */
		{
			/* Enable alternate function */
			SET_BIT(*GPIOAFSEL[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
			/* Set PMCx bits for the selected pin to use it as the selected alternate function */
			WRITE_PMCx_VALUE(g_Port_ConfigPtr[Pin].Port_Number, g_Port_ConfigPtr[Pin].Pin_Number,
							 g_Port_ConfigPtr[Pin].Pin_Mode);
			/* Disable analog mode */
			CLEAR_BIT(*GPIOAMSEL[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
			/* Enable digital mode */
			SET_BIT(*GPIODEN[g_Port_ConfigPtr[Pin].Port_Number], g_Port_ConfigPtr[Pin].Pin_Number);
		}
	}
	else
	{
		/* Do Nothing */
	}
}
#endif /* PORT_SET_PIN_MODE_API */

/************************************************************************************
*  Service name      : PORT_GetVersionInfo
*  Syntax            : void PORT_GetVersionInfo(Std_VersionInfoType* versioninfo )
*  Mode              : User Mode (Non-Privileged Mode)
*  Service ID[hex]   : 0x03
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : None
*  Parameters (inout): None
*  Parameters (out)  : versioninfo - Pointer to where to store the version
*                      information of this module.
*  Return value      : None
*  Description       : Service to get the version information of this module
 ************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void PORT_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if (NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
	#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif