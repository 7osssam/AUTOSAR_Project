/******************************************************************
 * @Module   	: Port
 * @Title 	 	: PORT Post Build Configuration Source file
 * @Filename 	: Port_PBcfg.c
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/
#include "Port.h"
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION			(1U)
#define PORT_PBCFG_SW_MINOR_VERSION			(0U)
#define PORT_PBCFG_SW_PATCH_VERSION			(0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
	 (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || \
	 (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || \
	 (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || \
	 (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
	#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
	.Pins =
		{
			/********************************************************
			 * 							PORTA 						*
			 ********************************************************/
			[PortConf_PA0_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA0_PORT_NUM,
					.Pin_Number = PortConf_PA0_PIN_NUM,
					.Pin_Direction = PortConf_PA0_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA0_PIN_MODE,
					.Pin_Resistor = PortConf_PA0_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA0_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA0_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA0_PIN_MODE_CHANGE,
				},
			[PortConf_PA1_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA1_PORT_NUM,
					.Pin_Number = PortConf_PA1_PIN_NUM,
					.Pin_Direction = PortConf_PA1_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA1_PIN_MODE,
					.Pin_Resistor = PortConf_PA1_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA1_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA1_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA1_PIN_MODE_CHANGE,
				},
			[PortConf_PA2_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA2_PORT_NUM,
					.Pin_Number = PortConf_PA2_PIN_NUM,
					.Pin_Direction = PortConf_PA2_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA2_PIN_MODE,
					.Pin_Resistor = PortConf_PA2_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA2_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA2_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA2_PIN_MODE_CHANGE,
				},
			[PortConf_PA3_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA3_PORT_NUM,
					.Pin_Number = PortConf_PA3_PIN_NUM,
					.Pin_Direction = PortConf_PA3_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA3_PIN_MODE,
					.Pin_Resistor = PortConf_PA3_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA3_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA3_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA3_PIN_MODE_CHANGE,
				},
			[PortConf_PA4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA4_PORT_NUM,
					.Pin_Number = PortConf_PA4_PIN_NUM,
					.Pin_Direction = PortConf_PA4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA4_PIN_MODE,
					.Pin_Resistor = PortConf_PA4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA4_PIN_MODE_CHANGE,
				},
			[PortConf_PA5_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA5_PORT_NUM,
					.Pin_Number = PortConf_PA5_PIN_NUM,
					.Pin_Direction = PortConf_PA5_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA5_PIN_MODE,
					.Pin_Resistor = PortConf_PA5_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA5_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA5_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA5_PIN_MODE_CHANGE,
				},
			[PortConf_PA6_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA6_PORT_NUM,
					.Pin_Number = PortConf_PA6_PIN_NUM,
					.Pin_Direction = PortConf_PA6_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA6_PIN_MODE,
					.Pin_Resistor = PortConf_PA6_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA6_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA6_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA6_PIN_MODE_CHANGE,
				},
			[PortConf_PA7_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PA7_PORT_NUM,
					.Pin_Number = PortConf_PA7_PIN_NUM,
					.Pin_Direction = PortConf_PA7_PIN_DIRECTION,
					.Pin_Mode = PortConf_PA7_PIN_MODE,
					.Pin_Resistor = PortConf_PA7_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PA7_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PA7_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PA7_PIN_MODE_CHANGE,
				},
			/********************************************************
			 * 							PORTB 						*
			 ********************************************************/
			[PortConf_PB0_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB0_PORT_NUM,
					.Pin_Number = PortConf_PB0_PIN_NUM,
					.Pin_Direction = PortConf_PB0_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB0_PIN_MODE,
					.Pin_Resistor = PortConf_PB0_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB0_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB0_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB0_PIN_MODE_CHANGE,
				},
			[PortConf_PB1_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB1_PORT_NUM,
					.Pin_Number = PortConf_PB1_PIN_NUM,
					.Pin_Direction = PortConf_PB1_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB1_PIN_MODE,
					.Pin_Resistor = PortConf_PB1_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB1_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB1_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB1_PIN_MODE_CHANGE,
				},
			[PortConf_PB2_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB2_PORT_NUM,
					.Pin_Number = PortConf_PB2_PIN_NUM,
					.Pin_Direction = PortConf_PB2_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB2_PIN_MODE,
					.Pin_Resistor = PortConf_PB2_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB2_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB2_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB2_PIN_MODE_CHANGE,
				},
			[PortConf_PB3_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB3_PORT_NUM,
					.Pin_Number = PortConf_PB3_PIN_NUM,
					.Pin_Direction = PortConf_PB3_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB3_PIN_MODE,
					.Pin_Resistor = PortConf_PB3_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB3_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB3_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB3_PIN_MODE_CHANGE,
				},
			[PortConf_PB4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB4_PORT_NUM,
					.Pin_Number = PortConf_PB4_PIN_NUM,
					.Pin_Direction = PortConf_PB4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB4_PIN_MODE,
					.Pin_Resistor = PortConf_PB4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB4_PIN_MODE_CHANGE,
				},
			[PortConf_PB5_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB5_PORT_NUM,
					.Pin_Number = PortConf_PB5_PIN_NUM,
					.Pin_Direction = PortConf_PB5_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB5_PIN_MODE,
					.Pin_Resistor = PortConf_PB5_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB5_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB5_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB5_PIN_MODE_CHANGE,
				},
			[PortConf_PB6_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB6_PORT_NUM,
					.Pin_Number = PortConf_PB6_PIN_NUM,
					.Pin_Direction = PortConf_PB6_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB6_PIN_MODE,
					.Pin_Resistor = PortConf_PB6_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB6_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB6_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB6_PIN_MODE_CHANGE,
				},
			[PortConf_PB7_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PB7_PORT_NUM,
					.Pin_Number = PortConf_PB7_PIN_NUM,
					.Pin_Direction = PortConf_PB7_PIN_DIRECTION,
					.Pin_Mode = PortConf_PB7_PIN_MODE,
					.Pin_Resistor = PortConf_PB7_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PB7_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PB7_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PB7_PIN_MODE_CHANGE,
				},
			/********************************************************
			 * 							PORTC 						*
			 ********************************************************/
			[PortConf_PC4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PC4_PORT_NUM,
					.Pin_Number = PortConf_PC4_PIN_NUM,
					.Pin_Direction = PortConf_PC4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PC4_PIN_MODE,
					.Pin_Resistor = PortConf_PC4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PC4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PC4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PC4_PIN_MODE_CHANGE,
				},
			[PortConf_PC5_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PC5_PORT_NUM,
					.Pin_Number = PortConf_PC5_PIN_NUM,
					.Pin_Direction = PortConf_PC5_PIN_DIRECTION,
					.Pin_Mode = PortConf_PC5_PIN_MODE,
					.Pin_Resistor = PortConf_PC5_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PC5_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PC5_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PC5_PIN_MODE_CHANGE,
				},
			[PortConf_PC6_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PC6_PORT_NUM,
					.Pin_Number = PortConf_PC6_PIN_NUM,
					.Pin_Direction = PortConf_PC6_PIN_DIRECTION,
					.Pin_Mode = PortConf_PC6_PIN_MODE,
					.Pin_Resistor = PortConf_PC6_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PC6_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PC6_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PC6_PIN_MODE_CHANGE,
				},
			[PortConf_PC7_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PC7_PORT_NUM,
					.Pin_Number = PortConf_PC7_PIN_NUM,
					.Pin_Direction = PortConf_PC7_PIN_DIRECTION,
					.Pin_Mode = PortConf_PC7_PIN_MODE,
					.Pin_Resistor = PortConf_PC7_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PC7_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PC7_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PC7_PIN_MODE_CHANGE,
				},
			/********************************************************
			 * 							PORTD 						*
			 ********************************************************/
			[PortConf_PD0_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD0_PORT_NUM,
					.Pin_Number = PortConf_PD0_PIN_NUM,
					.Pin_Direction = PortConf_PD0_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD0_PIN_MODE,
					.Pin_Resistor = PortConf_PD0_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD0_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD0_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD0_PIN_MODE_CHANGE,
				},
			[PortConf_PD1_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD1_PORT_NUM,
					.Pin_Number = PortConf_PD1_PIN_NUM,
					.Pin_Direction = PortConf_PD1_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD1_PIN_MODE,
					.Pin_Resistor = PortConf_PD1_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD1_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD1_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD1_PIN_MODE_CHANGE,
				},
			[PortConf_PD2_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD2_PORT_NUM,
					.Pin_Number = PortConf_PD2_PIN_NUM,
					.Pin_Direction = PortConf_PD2_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD2_PIN_MODE,
					.Pin_Resistor = PortConf_PD2_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD2_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD2_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD2_PIN_MODE_CHANGE,
				},
			[PortConf_PD3_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD3_PORT_NUM,
					.Pin_Number = PortConf_PD3_PIN_NUM,
					.Pin_Direction = PortConf_PD3_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD3_PIN_MODE,
					.Pin_Resistor = PortConf_PD3_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD3_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD3_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD3_PIN_MODE_CHANGE,
				},
			[PortConf_PD4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD4_PORT_NUM,
					.Pin_Number = PortConf_PD4_PIN_NUM,
					.Pin_Direction = PortConf_PD4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD4_PIN_MODE,
					.Pin_Resistor = PortConf_PD4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD4_PIN_MODE_CHANGE,
				},
			[PortConf_PD5_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD5_PORT_NUM,
					.Pin_Number = PortConf_PD5_PIN_NUM,
					.Pin_Direction = PortConf_PD5_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD5_PIN_MODE,
					.Pin_Resistor = PortConf_PD5_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD5_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD5_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD5_PIN_MODE_CHANGE,
				},
			[PortConf_PD6_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD6_PORT_NUM,
					.Pin_Number = PortConf_PD6_PIN_NUM,
					.Pin_Direction = PortConf_PD6_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD6_PIN_MODE,
					.Pin_Resistor = PortConf_PD6_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD6_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD6_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD6_PIN_MODE_CHANGE,
				},
			[PortConf_PD7_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PD7_PORT_NUM,
					.Pin_Number = PortConf_PD7_PIN_NUM,
					.Pin_Direction = PortConf_PD7_PIN_DIRECTION,
					.Pin_Mode = PortConf_PD7_PIN_MODE,
					.Pin_Resistor = PortConf_PD7_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PD7_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PD7_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PD7_PIN_MODE_CHANGE,
				},
			/********************************************************
			 * 							PORTF 						*
			 ********************************************************/
			[PortConf_PE0_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE0_PORT_NUM,
					.Pin_Number = PortConf_PE0_PIN_NUM,
					.Pin_Direction = PortConf_PE0_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE0_PIN_MODE,
					.Pin_Resistor = PortConf_PE0_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE0_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE0_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE0_PIN_MODE_CHANGE,
				},
			[PortConf_PE1_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE1_PORT_NUM,
					.Pin_Number = PortConf_PE1_PIN_NUM,
					.Pin_Direction = PortConf_PE1_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE1_PIN_MODE,
					.Pin_Resistor = PortConf_PE1_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE1_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE1_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE1_PIN_MODE_CHANGE,
				},
			[PortConf_PE2_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE2_PORT_NUM,
					.Pin_Number = PortConf_PE2_PIN_NUM,
					.Pin_Direction = PortConf_PE2_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE2_PIN_MODE,
					.Pin_Resistor = PortConf_PE2_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE2_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE2_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE2_PIN_MODE_CHANGE,
				},
			[PortConf_PE3_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE3_PORT_NUM,
					.Pin_Number = PortConf_PE3_PIN_NUM,
					.Pin_Direction = PortConf_PE3_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE3_PIN_MODE,
					.Pin_Resistor = PortConf_PE3_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE3_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE3_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE3_PIN_MODE_CHANGE,
				},
			[PortConf_PE4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE4_PORT_NUM,
					.Pin_Number = PortConf_PE4_PIN_NUM,
					.Pin_Direction = PortConf_PE4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE4_PIN_MODE,
					.Pin_Resistor = PortConf_PE4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE4_PIN_MODE_CHANGE,
				},
			[PortConf_PE5_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PE5_PORT_NUM,
					.Pin_Number = PortConf_PE5_PIN_NUM,
					.Pin_Direction = PortConf_PE5_PIN_DIRECTION,
					.Pin_Mode = PortConf_PE5_PIN_MODE,
					.Pin_Resistor = PortConf_PE5_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PE5_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PE5_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PE5_PIN_MODE_CHANGE,
				},
			/********************************************************
			 * 							PORTF 						*
			 ********************************************************/
			[PortConf_PF0_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PF0_PORT_NUM,
					.Pin_Number = PortConf_PF0_PIN_NUM,
					.Pin_Direction = PortConf_PF0_PIN_DIRECTION,
					.Pin_Mode = PortConf_PF0_PIN_MODE,
					.Pin_Resistor = PortConf_PF0_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PF0_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PF0_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PF0_PIN_MODE_CHANGE,
				},
			[PortConf_PF1_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PF1_PORT_NUM,
					.Pin_Number = PortConf_PF1_PIN_NUM,
					.Pin_Direction = PortConf_PF1_PIN_DIRECTION,
					.Pin_Mode = PortConf_PF1_PIN_MODE,
					.Pin_Resistor = PortConf_PF1_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PF1_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PF1_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PF1_PIN_MODE_CHANGE,
				},
			[PortConf_PF2_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PF2_PORT_NUM,
					.Pin_Number = PortConf_PF2_PIN_NUM,
					.Pin_Direction = PortConf_PF2_PIN_DIRECTION,
					.Pin_Mode = PortConf_PF2_PIN_MODE,
					.Pin_Resistor = PortConf_PF2_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PF2_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PF2_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PF2_PIN_MODE_CHANGE,
				},
			[PortConf_PF3_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PF3_PORT_NUM,
					.Pin_Number = PortConf_PF3_PIN_NUM,
					.Pin_Direction = PortConf_PF3_PIN_DIRECTION,
					.Pin_Mode = PortConf_PF3_PIN_MODE,
					.Pin_Resistor = PortConf_PF3_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PF3_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PF3_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PF3_PIN_MODE_CHANGE,
				},
			[PortConf_PF4_PIN_ID_INDEX] =
				{
					.Port_Number = PortConf_PF4_PORT_NUM,
					.Pin_Number = PortConf_PF4_PIN_NUM,
					.Pin_Direction = PortConf_PF4_PIN_DIRECTION,
					.Pin_Mode = PortConf_PF4_PIN_MODE,
					.Pin_Resistor = PortConf_PF4_PIN_INTERNAL_RESISTOR,
					.Pin_Initial_Value = PortConf_PF4_PIN_INITIAL_VALUE,
					.Pin_Direction_Changeable = PortConf_PF4_PIN_DIRECTION_CHANGE,
					.Pin_Mode_Changeable = PortConf_PF4_PIN_MODE_CHANGE,
				},

		},
};