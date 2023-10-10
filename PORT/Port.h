/******************************************************************
 * @Module   	: Port
 * @Title 	 	: PORT Module Header File
 * @Filename 	: Port.h   
 * @target  	: TivaC TM4C123GH6PM Microcontroller             
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID				  (1000U)

/* Port Module Id */
#define PORT_MODULE_ID				  (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID			  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION		  (1U)
#define PORT_SW_MINOR_VERSION		  (0U)
#define PORT_SW_PATCH_VERSION		  (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_AR_RELEASE_PATCH_VERSION (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED			  (1U)
#define PORT_NOT_INITIALIZED		  (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
	 (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || \
	 (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
	 (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || \
	 (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || \
	 (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || \
	 (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
	#error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Registers Header File*/
#include "Port_Regs.h"

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for PORT init */
#define PORT_INIT_SID					(uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID		(uint8)0x01

/* Service ID for PORT refresh Port direction */
#define PORT_REFRESH_PORT_DIRECTION_SID (uint8)0x02

/* Service ID for PORT get version info */
#define PORT_GET_VERSION_INFO_SID		(uint8)0x03

/* Service ID for PORT set Pin mode */
#define PORT_SET_PIN_MODE_SID			(uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report invalid Port Pin ID is requested */
#define PORT_E_PARAM_PIN				(uint8)0x0A

/* Det Code to report that Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE	(uint8)0x0B

/* DET code to report that Port_Init service is called with a wrong Pointer parameter */
#define PORT_E_PARAM_CONFIG				(uint8)0x0C

/* DET code to report that API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE		(uint8)0x0D

/* DET code to report that API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE		(uint8)0x0E

/* DET code to report that an API service is called without module initialization */
#define PORT_E_UNINIT					(uint8)0x0F

/* Det Code to report that APIs called with a NULL Pointer*/
#define PORT_E_PARAM_POINTER			(uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Enumeration for Port_PinDirectionType used by the PORT APIs */
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
} Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Enumeration for internal resistor type for PIN */
typedef enum
{
	OFF,
	PULL_UP,
	PULL_DOWN
} Port_InternalResistorType;

/* Enumeration for Port_changeable used by the PORT APIs */
typedef enum
{
	NOT_CHANGEABLE,
	CHANGEABLE
} Port_changeable;

/* Data Structure for PIN configuration*/
typedef struct
{
	uint8					  Port_Number;
	Port_PinType			  Pin_Number;
	Port_PinDirectionType	  Pin_Direction;
	Port_PinModeType		  Pin_Mode;
	Port_InternalResistorType Pin_Resistor;
	uint8					  Pin_Initial_Value; // only for output pins
	boolean					  Pin_Direction_Changeable;
	boolean					  Pin_Mode_Changeable;
} Port_ConfigPins;

/* Data Structure required for initializing the Port Driver */
typedef struct
{
	Port_ConfigPins Pins[PORT_CONFIGURED_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

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
void Port_Init(const Port_ConfigType* ConfigPtr);

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
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
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
void Port_RefreshPortDirection(void);

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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

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
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/
/* PORTs names*/
#define PORTA					  (uint8)0
#define PORTB					  (uint8)1
#define PORTC					  (uint8)2
#define PORTD					  (uint8)3
#define PORTE					  (uint8)4
#define PORTF					  (uint8)5

/* PINs numbers*/
#define PIN0					  (uint8)0
#define PIN1					  (uint8)1
#define PIN2					  (uint8)2
#define PIN3					  (uint8)3
#define PIN4					  (uint8)4
#define PIN5					  (uint8)5
#define PIN6					  (uint8)6
#define PIN7					  (uint8)7

/* Definition for Mode IDs */
#define GPIO_MODE_ID			  (0U) /* GPIO */
#define GROUP_1_MODE_ID			  (1U)
#define GROUP_2_MODE_ID			  (2U)
#define GROUP_3_MODE_ID			  (3U)
#define GROUP_4_MODE_ID			  (4U)
#define GROUP_5_MODE_ID			  (5U)
#define GROUP_6_MODE_ID			  (6U)
#define GROUP_7_MODE_ID			  (7U)
#define GROUP_8_MODE_ID			  (8U)
#define GROUP_9_MODE_ID			  (9U)
#define ADC_MODE_ID				  (10U) /* ADC */
#define ANALOG_COMPARATOR_MODE_ID (11U) /* ANALOG COMPARATOR eg. C0-, C0+ */
#define ANALOG_MODE_ID			  (12U) /* ANALOG eg. USB0DM, USB0DP */
#define INVALID_MODE_ID			  (13U) /* INVALID MODE */
#define GROUP_14_MODE_ID		  (14U)

/* Enumeration for Port_PinMode used by the PORT APIs (This is target specific) */
typedef enum
{
	/* Group 0 */
	PORT_GPIO_MODE = GPIO_MODE_ID,
	/* Group 1 */
	PORT_U0RX_MODE = GROUP_1_MODE_ID,
	PORT_U0TX_MODE = GROUP_1_MODE_ID,
	PORT_U1RX_G1_MODE = GROUP_1_MODE_ID,
	PORT_U1TX_G1_MODE = GROUP_1_MODE_ID,
	PORT_U3RX_MODE = GROUP_1_MODE_ID,
	PORT_U3TX_MODE = GROUP_1_MODE_ID,
	PORT_U4RX_MODE = GROUP_1_MODE_ID,
	PORT_U4TX_MODE = GROUP_1_MODE_ID,
	PORT_SSI3CLK_MODE = GROUP_1_MODE_ID,
	PORT_SSI3FSS_MODE = GROUP_1_MODE_ID,
	PORT_SSI3RX_MODE = GROUP_1_MODE_ID,
	PORT_SSI3TX_MODE = GROUP_1_MODE_ID,
	PORT_U6RX_MODE = GROUP_1_MODE_ID,
	PORT_U6TX_M0DE = GROUP_1_MODE_ID,
	PORT_U2RX_MODE = GROUP_1_MODE_ID,
	PORT_U2TX_M0DE = GROUP_1_MODE_ID,
	PORT_U7RX_MODE = GROUP_1_MODE_ID,
	PORT_U7TX_M0DE = GROUP_1_MODE_ID,
	PORT_U5RX_MODE = GROUP_1_MODE_ID,
	PORT_U5TX_M0DE = GROUP_1_MODE_ID,
	PORT_U1RTS_MODE = GROUP_1_MODE_ID,
	PORT_U1CTS_G1_MODE = GROUP_1_MODE_ID,
	PORT_TCK_SWCLK_MODE = GROUP_1_MODE_ID,
	PORT_TMS_SWDI0_MODE = GROUP_1_MODE_ID,
	PORT_TD1_MODE = GROUP_1_MODE_ID,
	PORT_TD0_SW0_MODE = GROUP_1_MODE_ID,
	/* Group 2 */
	PORT_SSI0CLK_MODE = GROUP_2_MODE_ID,
	PORT_SSI0FSS_MODE = GROUP_2_MODE_ID,
	PORT_SSI0RX_MODE = GROUP_2_MODE_ID,
	PORT_SSI0TX_MODE = GROUP_2_MODE_ID,
	PORT_SSI2CLK_MODE = GROUP_2_MODE_ID,
	PORT_SSI2FSS_MODE = GROUP_2_MODE_ID,
	PORT_SSI2RX_MODE = GROUP_2_MODE_ID,
	PORT_SSI2TX_MODE = GROUP_2_MODE_ID,
	PORT_U1RX_G2_MODE = GROUP_2_MODE_ID,
	PORT_U1TX_G2_MODE = GROUP_2_MODE_ID,
	PORT_SSI1CLK_MODE = GROUP_2_MODE_ID,
	PORT_SSI1FSS_MODE = GROUP_2_MODE_ID,
	PORT_SSI1RX_MODE = GROUP_2_MODE_ID,
	PORT_SSI1TX_MODE = GROUP_2_MODE_ID,
	/* Group 3 */
	PORT_I2C1SCL_MODE = GROUP_3_MODE_ID,
	PORT_I2C1SDA_MODE = GROUP_3_MODE_ID,
	PORT_I2C0SCL_MODE = GROUP_3_MODE_ID,
	PORT_I2C0SDA_MODE = GROUP_3_MODE_ID,
	PORT_I2C3SCL_MODE = GROUP_3_MODE_ID,
	PORT_I2C3SDA_MODE = GROUP_3_MODE_ID,
	PORT_I2C2SCL_MODE = GROUP_3_MODE_ID,
	PORT_I2C2SDA_MODE = GROUP_3_MODE_ID,
	PORT_CAN0RX_G3_MODE = GROUP_3_MODE_ID,
	PORT_CAN0TX_G3_MODE = GROUP_3_MODE_ID,
	/* Group 4 */
	PORT_M0PWM2_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM3_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM0_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM1_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM6_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM7_MODE = GROUP_4_MODE_ID,
	PORT_M0FAULT0_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM4_MODE = GROUP_4_MODE_ID,
	PORT_M0PWM5_MODE = GROUP_4_MODE_ID,
	/* Group 5 */
	PORT_M1PWM0_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM1_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM2_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM3_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM4_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM5_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM6_MODE = GROUP_5_MODE_ID,
	PORT_M1PWM7_MODE = GROUP_5_MODE_ID,
	PORT_M1FAULT0_MODE = GROUP_5_MODE_ID,
	/* Group 6 */
	PORT_IDX1_MODE = GROUP_6_MODE_ID,
	PORT_PHA1_MODE = GROUP_6_MODE_ID,
	PORT_PHB1_MODE = GROUP_6_MODE_ID,
	PORT_IDX0_MODE = GROUP_6_MODE_ID,
	PORT_PHA0_MODE = GROUP_6_MODE_ID,
	PORT_PHB0_MODE = GROUP_6_MODE_ID,
	/* Group 7 */
	PORT_T2CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T2CCP1_MODE = GROUP_7_MODE_ID,
	PORT_T3CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T3CCP1_MODE = GROUP_7_MODE_ID,
	PORT_T1CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T1CCP1_MODE = GROUP_7_MODE_ID,
	PORT_T0CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T0CCP1_MODE = GROUP_7_MODE_ID,
	PORT_T4CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T4CCP1_MODE = GROUP_7_MODE_ID,
	PORT_T5CCP0_MODE = GROUP_7_MODE_ID,
	PORT_T5CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT0CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT0CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT1CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT1CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT2CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT2CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT3CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT3CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT4CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT4CCP1_MODE = GROUP_7_MODE_ID,
	PORT_WT5CCP0_MODE = GROUP_7_MODE_ID,
	PORT_WT5CCP1_MODE = GROUP_7_MODE_ID,
	/* Group 8 */
	PORT_CAN1RX_MODE = GROUP_8_MODE_ID,
	PORT_CAN1TX_MODE = GROUP_8_MODE_ID,
	PORT_CAN0RX_G8_MODE = GROUP_8_MODE_ID,
	PORT_CAN0TX_G8_MODE = GROUP_8_MODE_ID,
	PORT_U1TRS_MODE = GROUP_8_MODE_ID,
	PORT_U1CTS_G8_MODE = GROUP_8_MODE_ID,
	PORT_USB0EPEN_MODE = GROUP_8_MODE_ID,
	PORT_USB0PFLT_MODE = GROUP_8_MODE_ID,
	PORT_NMI_MODE = GROUP_8_MODE_ID,
	/* Group 9 */
	PORT_c0o_MODE = GROUP_9_MODE_ID,
	PORT_c1o_MODE = GROUP_9_MODE_ID,
	/* ADC MODE - 10 */
	PORT_ADC_MODE = ADC_MODE_ID,
	/* ANALOG COMPARATOR MODE - 11 */
	PORT_C1_NEGATIVE_MODE = ANALOG_COMPARATOR_MODE_ID,
	PORT_C1_POSITIVE_MODE = ANALOG_COMPARATOR_MODE_ID,
	PORT_C0_POSITIVE_MODE = ANALOG_COMPARATOR_MODE_ID,
	PORT_C0_NEGATIVE_MODE = ANALOG_COMPARATOR_MODE_ID,
	/* ANALOG MODE - 12 */
	PORT_USB0DM_MODE = ANALOG_MODE_ID,
	PORT_USB0DP_MODE = ANALOG_MODE_ID,
	PORT_USB0ID_MODE = ANALOG_MODE_ID,
	PORT_USB0VBUS_MODE = ANALOG_MODE_ID,
	/* GROUP 14 MODE */
	PORT_TRD1_MODE = GROUP_14_MODE_ID,
	PORT_TRD0_MODE = GROUP_14_MODE_ID,
	PORT_TRclk_MODE = GROUP_14_MODE_ID,

	//PORT_MODE_UART,
	//PORT_MODE_SSI,
	//PORT_MODE_I2C,
	//PORT_MODE_PWM,
	//PORT_MODE_QEI,
	//PORT_MODE_GPT,
	//PORT_MODE_CAN = 8,
	//PORT_MODE_USB,
	//PORT_MODE_SYS_CTRL,
	//PORT_MODE_ANALOG_COMP,
	//PORT_MODE_CORE,
	//PORT_MODE_ADC
} Port_PinMode;

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
