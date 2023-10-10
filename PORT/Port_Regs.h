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

/************************************ GPIO register offsets *****************************************/
#define GPIO_O_DATA			0x00000000 /* GPIO Data Offset */
#define GPIO_O_DIR			0x00000400 /* GPIO Direction Offset */
#define GPIO_O_AFSEL		0x00000420 /* GPIO Alternate Function Select Offset */
#define GPIO_O_PUR			0x00000510 /* GPIO Pull-Up Select Offset */
#define GPIO_O_PDR			0x00000514 /* GPIO Pull-Down Select Offset */
#define GPIO_O_DEN			0x0000051C /* GPIO Digital Enable Offset */
#define GPIO_O_LOCK			0x00000520 /* GPIO Lock Offset */
#define GPIO_O_CR			0x00000524 /* GPIO Commit Offset */
#define GPIO_O_AMSEL		0x00000528 /* GPIO Analog Mode Select Offset */
#define GPIO_O_PCTL			0x0000052C /* GPIO Port Control Offset */

/*==================================================================================================*/

/************************************ GPIO register base address ************************************/
#define PORTA_BASE_ADDRESS	0x40004000 /* PORTA base address */
#define PORTB_BASE_ADDRESS	0x40005000 /* PORTB base address */
#define PORTC_BASE_ADDRESS	0x40006000 /* PORTC base address */
#define PORTD_BASE_ADDRESS	0x40007000 /* PORTD base address */
#define PORTE_BASE_ADDRESS	0x40024000 /* PORTE base address */
#define PORTF_BASE_ADDRESS	0x40025000 /* PORTF base address */
/*==================================================================================================*/

/************************************ GPIO clock register *******************************************/
#define RCGCGPIO			(*((volatile uint32*)(0x400FE608)))
/*==================================================================================================*/

/* 0x3FC for Bit Banding for the whole port (8 bits) 00000011 11111100 */
#define PORTA_DATA_BIT_BAND 0x3FC

/**
 * The following are pointer array that maps to the data register of every GPIO port
 * - 0x3FC for Bit Banding for the whole port (8 bits) 00000011 11111100
 */
static volatile uint32* const GPIODATA[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port F */
};

/*==================================================================================================*/

/**
 * The following are pointer array that maps to the data direction register of every GPIO port
 *
 */
static volatile uint32* const GPIODIR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Alternate function select register of every GPIO port
 */
static volatile uint32* const GPIOAFSEL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Pull up Resistor select register of every GPIO port
 */
static volatile uint32* const GPIOPUR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor  select register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Pull Down Resistor select register of every GPIO port
 */
static volatile uint32* const GPIOPDR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor  select register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Digital Enable register of every GPIO port
 */
static volatile uint32* const GPIODEN[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable  register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the GPIO Lock register of every GPIO port
 */
static volatile uint32* const GPIOLOCK[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the GPIO Commit register of every GPIO port
 */
static volatile uint32* const GPIOCR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Analog Mode select of every GPIO port
 */
static volatile uint32* const GPIOAMSEL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port F */
};
/*==================================================================================================*/

/**
 * The following are pointer array that maps to the Port control register of every GPIO port
 *
 */
static volatile uint32* const GPIOPCTL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port F */
};

#endif /* PORT_REGS_H */
