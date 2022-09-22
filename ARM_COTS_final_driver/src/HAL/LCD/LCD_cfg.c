/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 9  sep 2022                                          */
/* Description : Configuration file for LCD module                    */
/**********************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"

MGPIO_Config_t LCD_DATA_PORTS[8] =
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
MGPIO_Config_t LCD_CTRL_RS_PIN =
{
		.port  = GPIO_PORTC , .pin=GPIO_PIN0 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL
};

MGPIO_Config_t LCD_CTRL_RW_PIN =
{
		.port  = GPIO_PORTC , .pin=GPIO_PIN1 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL
};

MGPIO_Config_t LCD_CTRL_EN_PIN =
{
		.port  = GPIO_PORTC , .pin=GPIO_PIN2 ,.mode=GPIO_MODE_OUTPUT,.speed = GPIO_OUTSPEED_LOW ,.out_type= GPIO_PUSH_PULL
};
