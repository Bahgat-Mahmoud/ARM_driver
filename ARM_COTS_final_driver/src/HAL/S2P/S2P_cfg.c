/*
 * S2P_cfg.c
 *  config table file
 *  Created on        : Sep 18, 2022
 *      Author        : Bahgat Mahmoud
 */
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "S2P_cfg.h" // optional


MGPIO_Config_t S2P_Shift_Pin =
{
		.mode = GPIO_MODE_INPUT ,.port = GPIO_PORTA , .pin  = GPIO_PIN0  ,.speed = GPIO_OUTSPEED_MEDIUM, .out_type =GPIO_PUSH_PULL
};

MGPIO_Config_t S2PLatch_Pin =
{
		.mode = GPIO_MODE_INPUT ,.port = GPIO_PORTA , .pin  = GPIO_PIN1  ,.speed = GPIO_OUTSPEED_MEDIUM, .out_type =GPIO_PUSH_PULL
};
MGPIO_Config_t S2P_Data_Pin =
{
		.mode = GPIO_MODE_INPUT ,.port = GPIO_PORTA , .pin  = GPIO_PIN2  ,.speed = GPIO_OUTSPEED_MEDIUM, .out_type =GPIO_PUSH_PULL
};
