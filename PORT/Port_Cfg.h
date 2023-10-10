/******************************************************************
 * @Module   	: Port
 * @Title 	 	: PORT Pre-Compile Configuration Header File 
 * @Filename 	: Port_Cfg.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION		   (1U)
#define PORT_CFG_SW_MINOR_VERSION		   (0U)
#define PORT_CFG_SW_PATCH_VERSION		   (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION  (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION  (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION  (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT			   (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API			   (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API		   (STD_ON)

/* Pre-compile option for presence of Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API			   (STD_ON)

/* Configuration for The number of specified PortPins in this PortContainer */
#define PORT_CONFIGURED_PINS			   (39U) /* PC0 to PC3 are not used (Reserved for JTAG) */

/* Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PA0_PIN_ID_INDEX		   (uint8)0
#define PortConf_PA1_PIN_ID_INDEX		   (uint8)1
#define PortConf_PA2_PIN_ID_INDEX		   (uint8)2
#define PortConf_PA3_PIN_ID_INDEX		   (uint8)3
#define PortConf_PA4_PIN_ID_INDEX		   (uint8)4
#define PortConf_PA5_PIN_ID_INDEX		   (uint8)5
#define PortConf_PA6_PIN_ID_INDEX		   (uint8)6
#define PortConf_PA7_PIN_ID_INDEX		   (uint8)7
#define PortConf_PB0_PIN_ID_INDEX		   (uint8)8
#define PortConf_PB1_PIN_ID_INDEX		   (uint8)9
#define PortConf_PB2_PIN_ID_INDEX		   (uint8)10
#define PortConf_PB3_PIN_ID_INDEX		   (uint8)11
#define PortConf_PB4_PIN_ID_INDEX		   (uint8)12
#define PortConf_PB5_PIN_ID_INDEX		   (uint8)13
#define PortConf_PB6_PIN_ID_INDEX		   (uint8)14
#define PortConf_PB7_PIN_ID_INDEX		   (uint8)15
#define PortConf_PC4_PIN_ID_INDEX		   (uint8)16
#define PortConf_PC5_PIN_ID_INDEX		   (uint8)17
#define PortConf_PC6_PIN_ID_INDEX		   (uint8)18
#define PortConf_PC7_PIN_ID_INDEX		   (uint8)19
#define PortConf_PD0_PIN_ID_INDEX		   (uint8)20
#define PortConf_PD1_PIN_ID_INDEX		   (uint8)21
#define PortConf_PD2_PIN_ID_INDEX		   (uint8)22
#define PortConf_PD3_PIN_ID_INDEX		   (uint8)23
#define PortConf_PD4_PIN_ID_INDEX		   (uint8)24
#define PortConf_PD5_PIN_ID_INDEX		   (uint8)25
#define PortConf_PD6_PIN_ID_INDEX		   (uint8)26
#define PortConf_PD7_PIN_ID_INDEX		   (uint8)27
#define PortConf_PE0_PIN_ID_INDEX		   (uint8)28
#define PortConf_PE1_PIN_ID_INDEX		   (uint8)29
#define PortConf_PE2_PIN_ID_INDEX		   (uint8)30
#define PortConf_PE3_PIN_ID_INDEX		   (uint8)31
#define PortConf_PE4_PIN_ID_INDEX		   (uint8)32
#define PortConf_PE5_PIN_ID_INDEX		   (uint8)33
#define PortConf_PF0_PIN_ID_INDEX		   (uint8)34
#define PortConf_PF1_PIN_ID_INDEX		   (uint8)35
#define PortConf_PF2_PIN_ID_INDEX		   (uint8)36
#define PortConf_PF3_PIN_ID_INDEX		   (uint8)37
#define PortConf_PF4_PIN_ID_INDEX		   (uint8)38

/* PORT Configured Port Numbers  */
#define PortConf_PA0_PORT_NUM			   (uint8)0
#define PortConf_PA1_PORT_NUM			   (uint8)0
#define PortConf_PA2_PORT_NUM			   (uint8)0
#define PortConf_PA3_PORT_NUM			   (uint8)0
#define PortConf_PA4_PORT_NUM			   (uint8)0
#define PortConf_PA5_PORT_NUM			   (uint8)0
#define PortConf_PA6_PORT_NUM			   (uint8)0
#define PortConf_PA7_PORT_NUM			   (uint8)0
#define PortConf_PB0_PORT_NUM			   (uint8)1
#define PortConf_PB1_PORT_NUM			   (uint8)1
#define PortConf_PB2_PORT_NUM			   (uint8)1
#define PortConf_PB3_PORT_NUM			   (uint8)1
#define PortConf_PB4_PORT_NUM			   (uint8)1
#define PortConf_PB5_PORT_NUM			   (uint8)1
#define PortConf_PB6_PORT_NUM			   (uint8)1
#define PortConf_PB7_PORT_NUM			   (uint8)1
#define PortConf_PC4_PORT_NUM			   (uint8)2
#define PortConf_PC5_PORT_NUM			   (uint8)2
#define PortConf_PC6_PORT_NUM			   (uint8)2
#define PortConf_PC7_PORT_NUM			   (uint8)2
#define PortConf_PD0_PORT_NUM			   (uint8)3
#define PortConf_PD1_PORT_NUM			   (uint8)3
#define PortConf_PD2_PORT_NUM			   (uint8)3
#define PortConf_PD3_PORT_NUM			   (uint8)3
#define PortConf_PD4_PORT_NUM			   (uint8)3
#define PortConf_PD5_PORT_NUM			   (uint8)3
#define PortConf_PD6_PORT_NUM			   (uint8)3
#define PortConf_PD7_PORT_NUM			   (uint8)3
#define PortConf_PE0_PORT_NUM			   (uint8)4
#define PortConf_PE1_PORT_NUM			   (uint8)4
#define PortConf_PE2_PORT_NUM			   (uint8)4
#define PortConf_PE3_PORT_NUM			   (uint8)4
#define PortConf_PE4_PORT_NUM			   (uint8)4
#define PortConf_PE5_PORT_NUM			   (uint8)4
#define PortConf_PF0_PORT_NUM			   (uint8)5
#define PortConf_PF1_PORT_NUM			   (uint8)5
#define PortConf_PF2_PORT_NUM			   (uint8)5
#define PortConf_PF3_PORT_NUM			   (uint8)5
#define PortConf_PF4_PORT_NUM			   (uint8)5

/* PORT Configured Pin Numbers */
#define PortConf_PA0_PIN_NUM			   (Port_PinType)0
#define PortConf_PA1_PIN_NUM			   (Port_PinType)1
#define PortConf_PA2_PIN_NUM			   (Port_PinType)2
#define PortConf_PA3_PIN_NUM			   (Port_PinType)3
#define PortConf_PA4_PIN_NUM			   (Port_PinType)4
#define PortConf_PA5_PIN_NUM			   (Port_PinType)5
#define PortConf_PA6_PIN_NUM			   (Port_PinType)6
#define PortConf_PA7_PIN_NUM			   (Port_PinType)7
#define PortConf_PB0_PIN_NUM			   (Port_PinType)0
#define PortConf_PB1_PIN_NUM			   (Port_PinType)1
#define PortConf_PB2_PIN_NUM			   (Port_PinType)2
#define PortConf_PB3_PIN_NUM			   (Port_PinType)3
#define PortConf_PB4_PIN_NUM			   (Port_PinType)4
#define PortConf_PB5_PIN_NUM			   (Port_PinType)5
#define PortConf_PB6_PIN_NUM			   (Port_PinType)6
#define PortConf_PB7_PIN_NUM			   (Port_PinType)7
#define PortConf_PC4_PIN_NUM			   (Port_PinType)4
#define PortConf_PC5_PIN_NUM			   (Port_PinType)5
#define PortConf_PC6_PIN_NUM			   (Port_PinType)6
#define PortConf_PC7_PIN_NUM			   (Port_PinType)7
#define PortConf_PD0_PIN_NUM			   (Port_PinType)0
#define PortConf_PD1_PIN_NUM			   (Port_PinType)1
#define PortConf_PD2_PIN_NUM			   (Port_PinType)2
#define PortConf_PD3_PIN_NUM			   (Port_PinType)3
#define PortConf_PD4_PIN_NUM			   (Port_PinType)4
#define PortConf_PD5_PIN_NUM			   (Port_PinType)5
#define PortConf_PD6_PIN_NUM			   (Port_PinType)6
#define PortConf_PD7_PIN_NUM			   (Port_PinType)7
#define PortConf_PE0_PIN_NUM			   (Port_PinType)0
#define PortConf_PE1_PIN_NUM			   (Port_PinType)1
#define PortConf_PE2_PIN_NUM			   (Port_PinType)2
#define PortConf_PE3_PIN_NUM			   (Port_PinType)3
#define PortConf_PE4_PIN_NUM			   (Port_PinType)4
#define PortConf_PE5_PIN_NUM			   (Port_PinType)5
#define PortConf_PF0_PIN_NUM			   (Port_PinType)0
#define PortConf_PF1_PIN_NUM			   (Port_PinType)1
#define PortConf_PF2_PIN_NUM			   (Port_PinType)2
#define PortConf_PF3_PIN_NUM			   (Port_PinType)3
#define PortConf_PF4_PIN_NUM			   (Port_PinType)4

/* 
 * PORT Configured Pin Directions 
 * by default all pins are configured as GPIO Input, except for LEDs connected at PF1,PF2,PF3
 */
#define PortConf_PA0_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA1_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA2_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA3_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA5_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA6_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PA7_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB0_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB1_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_OUT
#define PortConf_PB2_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB3_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB5_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_OUT
#define PortConf_PB6_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PB7_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PC4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PC5_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PC6_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PC7_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD0_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD1_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD2_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD3_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD5_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD6_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PD7_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE0_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE1_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE2_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE3_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PE5_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PF0_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN
#define PortConf_PF1_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_OUT
#define PortConf_PF2_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_OUT
#define PortConf_PF3_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_OUT
#define PortConf_PF4_PIN_DIRECTION		   (Port_PinDirectionType) PORT_PIN_IN

/* 
 * PORT Configured Pin Modes 
 * by default all pins are configured as GPIO 
 */
#define PortConf_PA0_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA1_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA2_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA3_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA5_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA6_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PA7_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB0_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB1_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB2_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB3_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB5_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB6_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PB7_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PC4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PC5_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PC6_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PC7_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD0_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD1_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD2_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD3_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD5_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD6_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PD7_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE0_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE1_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE2_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE3_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PE5_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PF0_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PF1_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PF2_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PF3_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE
#define PortConf_PF4_PIN_MODE			   (Port_PinMode) PORT_GPIO_MODE

/* 
 * PORT Configured Pin Internal Resistor 
 * by default all pins are configured as inputs in pull-up configuration,
 * except for LEDs at PF1,PF2,PF3 is output  
 */
#define PortConf_PA0_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA1_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA2_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA3_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA5_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA6_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PA7_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB0_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB1_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) OFF
#define PortConf_PB2_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB3_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB5_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) OFF
#define PortConf_PB6_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PB7_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PC4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PC5_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PC6_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PC7_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD0_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD1_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD2_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD3_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD5_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD6_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PD7_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE0_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE1_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE2_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE3_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PE5_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PF0_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP
#define PortConf_PF1_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP /* LED */
#define PortConf_PF2_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) OFF
#define PortConf_PF3_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) OFF
#define PortConf_PF4_PIN_INTERNAL_RESISTOR (Port_InternalResistorType) PULL_UP

/* 
 * PORT Configured Pin Initial Value 
 * by default all pins are configured as inputs so the have no initial value,
 * except for LED at PF1 is output with initial value = STD_LOW  
 */
#define PortConf_PA0_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA1_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA2_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA3_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA4_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA5_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA6_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PA7_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB0_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB1_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB2_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB3_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB4_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB5_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB6_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PB7_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PC4_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PC5_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PC6_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PC7_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD0_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD1_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD2_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD3_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD4_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD5_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD6_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PD7_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE0_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE1_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE2_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE3_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE4_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PE5_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PF0_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PF1_PIN_INITIAL_VALUE	   STD_HIGH /* LED */
#define PortConf_PF2_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PF3_PIN_INITIAL_VALUE	   STD_LOW
#define PortConf_PF4_PIN_INITIAL_VALUE	   STD_LOW

/* 
 * PORT Configured Pin Direction changeability
 * by default all pins are changeable  
 */
#define PortConf_PA0_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA1_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA2_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA3_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA5_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA6_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PA7_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB0_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB1_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB2_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB3_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB5_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB6_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PB7_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PC4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PC5_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PC6_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PC7_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD0_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD1_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD2_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD3_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD5_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD6_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PD7_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE0_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE1_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE2_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE3_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PE5_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PF0_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PF1_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PF2_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PF3_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE
#define PortConf_PF4_PIN_DIRECTION_CHANGE  (Port_changeable) CHANGEABLE

/* 
 * PORT Configured Pin Mode changeability
 * by default all pins are changeable  
 */
#define PortConf_PA0_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA1_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA2_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA3_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA5_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA6_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PA7_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB0_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB1_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB2_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB3_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB5_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB6_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PB7_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PC4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PC5_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PC6_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PC7_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD0_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD1_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD2_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD3_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD5_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD6_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PD7_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE0_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE1_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE2_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE3_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PE5_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PF0_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PF1_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PF2_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PF3_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE
#define PortConf_PF4_PIN_MODE_CHANGE	   (Port_changeable) CHANGEABLE

#endif /* PORT_CFG_H */