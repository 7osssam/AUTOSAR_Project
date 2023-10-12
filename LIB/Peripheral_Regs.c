
/********************************************************************
 * @Title 	 	: Peripheral Registers Header File
 * @Filename 	: Peripheral_Regs.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller 
 * @Author 	 	: Hossam Mohamed
 * @Discrption  : The code below is defining an arrays of pointers for various GPIO registers on the
 * 				  TivaC TM4C123GH6PM microcontroller for ports A, B, C, D, E, and F. These arrays store
 * 				  the addresses of data, direction, alternate function, pull-up, pull-down, digital enable,
 * 				  lock, commit, analog mode, and port control registers for each port. 
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#include "Peripheral_Regs.h"

/************************************ DATA REGISTERS ***********************************************
 * Description:
 * The `GPIODATA` array is a pointer array that maps to the data register of every GPIO port. Each
 * element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). 
 ***************************************************************************************************/
volatile uint32* const GPIODATA[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DATA) + (PORTA_DATA_BIT_BAND)), /* Data register for port F */
};

/************************************ DATA DIRECTION REGISTERS *************************************
 * Description:
 * The `GPIODIR` array is a pointer array that maps to the data direction register of every GPIO port.
 * Each element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). The data
 * direction register determines whether a specific pin in a GPIO port is configured as an input or an
 * output. The values in the `GPIODIR` array are the addresses of the data direction registers for each
 * port.
 ***************************************************************************************************/
volatile uint32* const GPIODIR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DIR)), /* Data direction register for port F */
};

/********************************* ALTERNATE FUNCTION SELECT REGISTERS *****************************
 * Description:
 * The `GPIOAFSEL` array is a pointer array that maps to the Alternate Function Select register of
 * every GPIO port. Each element of the array is a volatile pointer to a 32-bit unsigned integer
 * (`uint32*`). The Alternate Function Select register determines whether a specific pin in a GPIO port
 * is configured to use its alternate function or its GPIO function. The values in the `GPIOAFSEL`
 * array are the addresses of the Alternate Function Select registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOAFSEL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_AFSEL)), /* Alternate function select register for port F */
};

/************************************ PULL-UP RESISTOR SELECT REGISTERS ****************************
 * Description:
 * The `GPIOPUR` array is a pointer array that maps to the Pull-Up Resistor select register of every
 * GPIO port. Each element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`).
 * The Pull-Up Resistor select register determines whether a specific pin in a GPIO port has a pull-up
 * resistor enabled or disabled. The values in the `GPIOPUR` array are the addresses of the Pull-Up
 * Resistor select registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOPUR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PUR)), /* Pull Up Resistor select register for port F */
};

/************************************ PULL-DOWN RESISTOR SELECT REGISTERS **************************
 * Description:
 * The `GPIOPDR` array is a pointer array that maps to the Pull Down Resistor select register of every
 * GPIO port. Each element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`).
 * The Pull Down Resistor select register determines whether a specific pin in a GPIO port has a
 * pull-down resistor enabled or disabled. The values in the `GPIOPDR` array are the addresses of the
 * Pull Down Resistor select registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOPDR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PDR)), /* Pull Down Resistor select register for port F */
};

/************************************ DIGITAL ENABLE REGISTERS *************************************
 * Description:
 * The `GPIODEN` array is a pointer array that maps to the Digital Enable register of every GPIO port.
 * Each element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). The
 * Digital Enable register determines whether a specific pin in a GPIO port is configured as a digital
 * input or output. The values in the `GPIODEN` array are the addresses of the Digital Enable registers
 * for each port.
 ***************************************************************************************************/
volatile uint32* const GPIODEN[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_DEN)), /* Digital Enable register for port F */
};

/************************************ GPIO LOCK REGISTERS ******************************************
 * Description:
 * The `GPIOLOCK` array is a pointer array that maps to the Lock register of every GPIO port. Each
 * element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). The Lock
 * register is used to lock the configuration of the GPIO port, preventing any changes to the GPIO
 * configuration until the lock is cleared. The values in the `GPIOLOCK` array are the addresses of the
 * Lock registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOLOCK[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_LOCK)), /* Lock register for port F */
};

/************************************ COMMIT REGISTERS *********************************************
 * Description:
 * The `GPIOCR` array is a pointer array that maps to the Commit register of every GPIO port. Each
 * element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). The Commit
 * register is used to enable changes to the GPIO configuration, such as enabling or disabling the
 * pull-up or pull-down resistors. The values in the `GPIOCR` array are the addresses of the Commit
 * registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOCR[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_CR)), /* commit register for port F */
};

/************************************ ANALOG MODE SELECT REGISTERS *********************************
 * Description:
 * The `GPIOAMSEL` array is a pointer array that maps to the Analog Mode Select register of every GPIO
 * port. Each element of the array is a volatile pointer to a 32-bit unsigned integer (`uint32*`). The
 * Analog Mode Select register determines whether a specific pin in a GPIO port is configured as an
 * analog input or a digital input/output. The values in the `GPIOAMSEL` array are the addresses of the
 * Analog Mode Select registers for each port.
 ***************************************************************************************************/
volatile uint32* const GPIOAMSEL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_AMSEL)), /* Analog Mode Select register for port F */
};

/************************************ PORT CONTROL REGISTERS ***************************************
 * Description:
 * The above code is declaring an array of volatile pointers to uint32. Each element of the array
 * represents the Port Control register for a specific port (A, B, C, D, E, F). The base address of
 * each port is added to the offset of the Port Control register (GPIO_O_PCTL) to get the address of
 * the register. The volatile keyword is used to indicate that the value of the register can change
 * unexpectedly, so the compiler should not optimize any read or write operations on it.
 ***************************************************************************************************/
volatile uint32* const GPIOPCTL[NUMBER_OF_PORTS] = {
	(uint32*)((PORTA_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port A */
	(uint32*)((PORTB_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port B */
	(uint32*)((PORTC_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port C */
	(uint32*)((PORTD_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port D */
	(uint32*)((PORTE_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port E */
	(uint32*)((PORTF_BASE_ADDRESS) + (GPIO_O_PCTL)), /* Port Control register for port F */
};
