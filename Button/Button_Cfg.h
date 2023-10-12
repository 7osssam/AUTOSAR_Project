/******************************************************************
 * @Module   	: Button
 * @Title 	 	: Button Configuration Header
 * @Filename 	: Button_Cfg.h
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#ifndef BUTTON_CFG_H
#define BUTTON_CFG_H

#include "Dio.h"

/* Set the Button Port */
#define BUTTON_PORT	   DioConf_SW1_PORT_NUM

/* Set the Button Pin Number */
#define BUTTON_PIN_NUM DioConf_SW1_CHANNEL_NUM

#endif /* BUTTON_CFG_H */
