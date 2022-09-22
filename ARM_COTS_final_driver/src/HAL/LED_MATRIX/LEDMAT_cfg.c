/*
 * LEDMAT_cfg.c
 *  Created on: Sep 6, 2022
 *      Author: Bahgat Mahmoud
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "LEDMAT_cfg.h"

/*1-set GPIO configuration*/
MGPIO_Config_t   rows[NUM_OF_ROW] =
{
	   /* PORT                  PIN             Mode                   SPEED                       OUT_TYPE                 */
		{.port  = GPIO_PORTA , .pin=GPIO_PIN0 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN1 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN2 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN3 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN4 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN5 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN6 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTA , .pin=GPIO_PIN7 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },

};
MGPIO_Config_t      cols[NUM_OF_COL] =
{
	   /* PORT                  PIN             Mode                   SPEED                       OUT_TYPE                 */
		{.port  = GPIO_PORTB , .pin=GPIO_PIN5 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN6 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN7 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN8 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN9 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN10,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN12,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },
		{.port  = GPIO_PORTB , .pin=GPIO_PIN13,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL },

};

