/*
 * DAC_cfg.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "DAC_cfg.h"

MGPIO_Config_t  HDAC_PIN[DAC_NO_PIN] ={
		{.port  = GPIO_PORTA , .pin=GPIO_PIN0 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN1 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN2 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN3 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN4 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN5 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN6 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN7 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },

};
