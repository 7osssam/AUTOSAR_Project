/******************************************************************
 * @Module   	: Port
 * @Title 	 	: PORT Register addresses header file
 * @Filename 	: Port_Regs.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H

#include "Std_Types.h"

/************************************ GPIO Static Configurations ************************************/
#define NUMBER_OF_PORTS		(6U) /* Number of ports in TM4C123GH6PM */

/* PORTs names*/
#define PORTA				(uint8)0
#define PORTB				(uint8)1
#define PORTC				(uint8)2
#define PORTD				(uint8)3
#define PORTE				(uint8)4
#define PORTF				(uint8)5

/* PINs numbers*/
#define PIN0				(uint8)0
#define PIN1				(uint8)1
#define PIN2				(uint8)2
#define PIN3				(uint8)3
#define PIN4				(uint8)4
#define PIN5				(uint8)5
#define PIN6				(uint8)6
#define PIN7				(uint8)7

/************************************ GPIO register offsets *****************************************/
#define GPIO_O_DATA			(0x00000000) /* GPIO Data Offset */
#define GPIO_O_DIR			(0x00000400) /* GPIO Direction Offset */
#define GPIO_O_AFSEL		(0x00000420) /* GPIO Alternate Function Select Offset */
#define GPIO_O_PUR			(0x00000510) /* GPIO Pull-Up Select Offset */
#define GPIO_O_PDR			(0x00000514) /* GPIO Pull-Down Select Offset */
#define GPIO_O_DEN			(0x0000051C) /* GPIO Digital Enable Offset */
#define GPIO_O_LOCK			(0x00000520) /* GPIO Lock Offset */
#define GPIO_O_CR			(0x00000524) /* GPIO Commit Offset */
#define GPIO_O_AMSEL		(0x00000528) /* GPIO Analog Mode Select Offset */
#define GPIO_O_PCTL			(0x0000052C) /* GPIO Port Control Offset */

/*==================================================================================================*/

/************************************ GPIO register base address ************************************/
#define PORTA_BASE_ADDRESS	(0x40004000) /* PORTA base address */
#define PORTB_BASE_ADDRESS	(0x40005000) /* PORTB base address */
#define PORTC_BASE_ADDRESS	(0x40006000) /* PORTC base address */
#define PORTD_BASE_ADDRESS	(0x40007000) /* PORTD base address */
#define PORTE_BASE_ADDRESS	(0x40024000) /* PORTE base address */
#define PORTF_BASE_ADDRESS	(0x40025000) /* PORTF base address */
/*==================================================================================================*/

/************************************ GPIO clock register *******************************************/
#define RCGCGPIO			(*((volatile uint32*)(0x400FE608)))
/*==================================================================================================*/

/* 0x3FC for Bit Banding for the whole port (8 bits) 00000011 11111100 */
#define PORTA_DATA_BIT_BAND 0x3FC

extern volatile uint32* const GPIODATA[NUMBER_OF_PORTS];
extern volatile uint32* const GPIODIR[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOAFSEL[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOPUR[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOPDR[NUMBER_OF_PORTS];
extern volatile uint32* const GPIODEN[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOLOCK[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOCR[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOAMSEL[NUMBER_OF_PORTS];
extern volatile uint32* const GPIOPCTL[NUMBER_OF_PORTS];

#endif /* PORT_REGS_H */
