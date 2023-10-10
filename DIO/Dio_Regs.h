/******************************************************************
 * @Module   	: Dio
 * @Title 	 	: DIO Register addresses header file
 * @Filename 	: Dio_Regs.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#ifndef DIO_REGS_H
#define DIO_REGS_H

#include "Std_Types.h"

/************************************ GPIO register addresses *************************************/
#define GPIO_PORTA_DATA_REG (*((volatile uint32*)0x400043FC))
#define GPIO_PORTB_DATA_REG (*((volatile uint32*)0x400053FC))
#define GPIO_PORTC_DATA_REG (*((volatile uint32*)0x400063FC))
#define GPIO_PORTD_DATA_REG (*((volatile uint32*)0x400073FC))
#define GPIO_PORTE_DATA_REG (*((volatile uint32*)0x400243FC))
#define GPIO_PORTF_DATA_REG (*((volatile uint32*)0x400253FC))

/************************************ GPIO register offsets *****************************************/
#define GPIO_O_DATA			0x00000000 /* GPIO Data Offset */
#define NUMBER_OF_PORTS		6		   /* Number of ports in TM4C123GH6PM */

/************************************ GPIO register base address ************************************/
#define PORTA_BASE_ADDRESS	0x40004000 /* PORTA base address */
#define PORTB_BASE_ADDRESS	0x40005000 /* PORTB base address */
#define PORTC_BASE_ADDRESS	0x40006000 /* PORTC base address */
#define PORTD_BASE_ADDRESS	0x40007000 /* PORTD base address */
#define PORTE_BASE_ADDRESS	0x40024000 /* PORTE base address */
#define PORTF_BASE_ADDRESS	0x40025000 /* PORTF base address */

/* 0x3FC for Bit Banding for the whole port (8 bits) 00000011 11111100 */
#define PORTA_DATA_BIT_BAND 0x3FC

/* The following are pointer array that maps to the data register of every GPIO port */
static volatile uint32* const GPIODATA[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port A*/
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port B*/
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port C*/
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port D*/
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port E*/
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /*GPIODATA for port F*/
};

#endif /* DIO_REGS_H */
