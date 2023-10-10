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
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

	#include "Det.h"

	/* AUTOSAR Version checking between Det and PORT Modules */
	#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
		 (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || \
		 (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif

#endif

/* Number defined by the TM4C123GH6PM MCU creators to unlock GPIO Commit Register */
#define UNLOCK_GPIOCR	((uint32)0x4C4F434B)
#define FIRST_BYTE_MASK ((uint32)0x0000000F)

#define WRITE_PMCx_VALUE(PORT, BIT, VALUE) \
	(*GPIOPCTL[PORT] = ((*GPIOPCTL[PORT] & ~(FIRST_BYTE_MASK << (BIT * 4))) | (VALUE << (BIT * 4))))

static void GPIO_unlock(uint8 port, uint8 pin)
{
	/* Unlock the GPIO_CR register */
	*GPIOLOCK[port] = UNLOCK_GPIOCR;
	/* Allow changes on GPIO_CR register */
	SET_BIT(*GPIOCR[port], pin);
}

static void GPIO_clk_enable(uint8 port)
{
	/* Enable the clock for the given port */

	//SET_MASK(RCGCGPIO, BIT(Port_ConfigPtr[i].Port_Number));
	SET_MASK(RCGCGPIO, BIT(port));

	/* delay to make sure that the clock is enabled */
	volatile uint32 delay = RCGCGPIO;
}

STATIC const Port_ConfigPins* Port_ConfigPtr = NULL_PTR;
STATIC uint8				  Port_Status = PORT_NOT_INITIALIZED;

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
*              			- Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/* point to the required Port Registers base address */
	//volatile uint32* Port_GPIO_ptr = NULL_PTR;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
		error = TRUE;
	}
	else
#endif
		/* In-case there are no errors */
		if (FALSE == error)
		{
			/* address of the first Pins structure --> Pins[0] */
			/* point to the first Port_ConfigPins structure --> Port_Configuration.Pins[0] */
			Port_ConfigPtr = ConfigPtr->Pins;
			uint8 i = STD_LOW;
			for (i = 0; i < PORT_CONFIGURED_PINS; i++)
			{
				/**************************** Clock Enable ********************************/
				GPIO_clk_enable(Port_ConfigPtr[i].Port_Number);

				/**************************** Unlock GPIOCR *******************************/
				/* Unlock GPIOCR for PD7 or PF0 */
				if ((PORTF == Port_ConfigPtr[i].Port_Number && PIN0 == Port_ConfigPtr[i].Pin_Number) ||
					(PORTD == Port_ConfigPtr[i].Port_Number && PIN7 == Port_ConfigPtr[i].Pin_Number))
				{
					GPIO_unlock(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number);
				}
				/* PC0 to PC3 */
				else if (PORTC == Port_ConfigPtr[i].Port_Number && PIN0 >= Port_ConfigPtr[i].Port_Number)
				{
					/* Do Nothing ...  this is the JTAG pins */
				}
				else
				{
					/* Do Nothing ... No need to unlock the commit register for this pin */
				}

				/**************************** Direction ***********************************/
				if (PORT_PIN_OUT == (Port_PinDirectionType)Port_ConfigPtr[i].Pin_Direction)
				{
					SET_BIT(*GPIODIR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);

					/**************************** Initial Value *******************************/
					if (STD_HIGH == Port_ConfigPtr[i].Pin_Initial_Value)
					{
						SET_BIT(*GPIODATA[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
					else if (STD_LOW == Port_ConfigPtr[i].Pin_Initial_Value)
					{
						CLEAR_BIT(*GPIODATA[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
					else
					{
						/* Do Nothing */
					}
				}
				else if (PORT_PIN_IN == (Port_PinDirectionType)Port_ConfigPtr[i].Pin_Direction)
				{
					CLEAR_BIT(*GPIODIR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);

					//**************************** Resistor ************************************
					if (Port_ConfigPtr[i].Pin_Resistor == PULL_UP)
					{
						/* Enable the internal pull up resistor for the selected pin */
						SET_BIT(*GPIOPUR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
					else if (Port_ConfigPtr[i].Pin_Resistor == PULL_DOWN)
					{
						SET_BIT(*GPIOPDR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
					else
					{
						CLEAR_BIT(*GPIOPUR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
						CLEAR_BIT(*GPIOPDR[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
				}
				else
				{
					/* Do Nothing */
				}

				//**************************** Mode Select ********************************

				//if (PORT_GPIO_MODE == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode)
				//{
				//	/* Disable analog mode */
				//	CLEAR_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Disable alternate function */
				//	CLEAR_BIT(*GPIOAFSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Clear PMCx bits for the selected pin to use it as GPIO pin */
				//	WRITE_PMCx_VALUE(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number, STD_LOW);
				//	/* Enable digital mode */
				//	SET_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//}
				//else if ((ADC_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode) ||
				//		 (ANALOG_COMPARATOR_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode) ||
				//		 (ANALOG_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode))
				//{
				//	/* Enable analog mode */
				//	SET_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Disable alternate function */
				//	CLEAR_BIT(*GPIOAFSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Clear PMCx bits for the selected pin to use it as GPIO pin */
				//	WRITE_PMCx_VALUE(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number, STD_LOW);
				//	/* Disable digital mode */
				//	CLEAR_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//}
				//else
				//{
				//	/* Disable analog mode */
				//	CLEAR_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Enable alternate function */
				//	SET_BIT(*GPIOAFSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//	/* Set PMCx bits for the selected pin to use it as the selected alternate function */
				//	WRITE_PMCx_VALUE(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number,
				//					 Port_ConfigPtr[i].Pin_Mode);
				//	/* Enable digital mode */
				//	SET_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				//}

				//!! testing
				if ((PORT_GPIO_MODE == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode) ||
					(ADC_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode) ||
					(ANALOG_COMPARATOR_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode) ||
					(ANALOG_MODE_ID == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode))
				{
					/* Disable alternate function */
					CLEAR_BIT(*GPIOAFSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					/* Clear PMCx bits for the selected pin to use it as GPIO pin */
					WRITE_PMCx_VALUE(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number, STD_LOW);

					if (PORT_GPIO_MODE == (Port_PinMode)Port_ConfigPtr[i].Pin_Mode)
					{
						/* Disable analog mode */
						CLEAR_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
						/* Enable digital mode */
						SET_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
					else
					{
						/* Enable analog mode */
						SET_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
						/* Disable digital mode */
						CLEAR_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					}
				}
				else
				{
					/* Enable alternate function */
					SET_BIT(*GPIOAFSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					/* Set PMCx bits for the selected pin to use it as the selected alternate function */
					WRITE_PMCx_VALUE(Port_ConfigPtr[i].Port_Number, Port_ConfigPtr[i].Pin_Number,
									 Port_ConfigPtr[i].Pin_Mode);

					/* Disable analog mode */
					CLEAR_BIT(*GPIOAMSEL[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
					/* Enable digital mode */
					SET_BIT(*GPIODEN[Port_ConfigPtr[i].Port_Number], Port_ConfigPtr[i].Pin_Number);
				}
			}

			/*
		 	* Set the module state to initialized and point to the PB configuration structure using a
		 	* global pointer. This global pointer is global to be used by other functions to read the
		 	* PB configuration structures
		 	*/
			Port_Status = PORT_INITIALIZED;
		}
		else
		{
			/* Do Nothing */
		}
}

/************************************************************************************
void Gpio_Init(const GpioConfiguration* const cnfg_table, uint8_t cnfgTable_size)
{
	for (uint8_t i = 0; i < cnfgTable_size; i++)
	{
		//enable clock to the specific port
		RCGCGPIO = (1 << cnfg_table[i].port);

		//set direction of the pin
		if (cnfg_table[i].direction == gpio_output)
			//pin is output pin
			*GpioDataDIR[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			//pin is input
			*GpioDataDIR[cnfg_table[i].port] &= ~(1 << cnfg_table[i].pin);

		//digital enable for the pin in this port
		*GpioDEN[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);

		//check if pull up resistor is enabled
		if (cnfg_table[i].resistor == gpio_pullupenable)
			*GpioPUR[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			*GpioPUR[cnfg_table[i].port] &= ~(1 << cnfg_table[i].pin);

		//set state of the pin
		if (cnfg_table[i].state == gpio_high)
			//set pin high
			*GpioDataReg[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			*GpioDataReg[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
	}
}
************************************************************************************/

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
}
#endif

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
}
#endif

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