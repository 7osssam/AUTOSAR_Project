/******************************************************************
 * @Module   	: Led
 * @Title 	 	: Led Configuration Header
 * @Filename 	: Led_Cfg.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#ifndef LED_CFG_H
#define LED_CFG_H

#include "Dio.h"

/* Set the LED Port */
#define LED_PORT	DioConf_LED1_PORT_NUM

/* Set the LED Pin Number */
#define LED_PIN_NUM DioConf_LED1_CHANNEL_NUM

#endif /* LED_CFG_H */
