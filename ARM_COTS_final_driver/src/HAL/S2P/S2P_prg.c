/*
 * S2P_prg.c
 *
 *  Created on: Sep 18, 2022
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/STK_int.h"
#include "S2P_prv.h"
#include "S2P_int.h"
#include "S2P_cfg.h"

extern  MGPIO_Config_t    S2P_Shift_Pin ;
extern  MGPIO_Config_t    S2P_Latch_Pin ;
extern  MGPIO_Config_t    S2P_Data_Pin ;
static void Latch_Data(void);
static void Shift_Data(void);
void HS2P_vInit(void)

{
	MGPIO_vInit(& S2P_Shift_Pin);
	MGPIO_vInit(& S2P_Latch_Pin);
	MGPIO_vInit(& S2P_Data_Pin);
}
/**
 * send a pulse on Shift pin
 */
static void Shift_Data(void)
{
	MGPIO_vSetPinVal(S2P_Shift_Pin.port,S2P_Shift_Pin.pin,GPIO_HIGH);
	/* delay */
	MSTK_vSetBusyWait_us(1000);
	MGPIO_vSetPinVal(S2P_Shift_Pin.port,S2P_Shift_Pin.pin,GPIO_LOW);
	MSTK_vSetBusyWait_us(1000);
}
/**
 * send a pulse on Latch pin
 */
static void Latch_Data(void)
{
	MGPIO_vSetPinVal(S2P_Latch_Pin.port,S2P_Latch_Pin.pin,GPIO_HIGH);
	/* delay */
	MSTK_vSetBusyWait_us(1000);
	MGPIO_vSetPinVal(S2P_Latch_Pin.port,S2P_Latch_Pin.pin,GPIO_LOW);
	MSTK_vSetBusyWait_us(1000);
}
/*send data*/
void HS2P_vSendData(u32 A_u32val)
{
	for(u32 A_u32Iter =0 ; A_u32Iter < 8*S2P_NO_REG ; A_u32Iter++)
	{
		/*1-put data on data pin*/
		MGPIO_vSetPinVal(S2P_Data_Pin.port,S2P_Data_Pin.pin,GET_BIT(A_u32val,A_u32Iter));
		/*2-shift data using shift pin
		 * 2a- send high
		 * 2a- delay
		 * 2a- send low
		 */
		Shift_Data();
	}
	/*3-send latch signal for the output
	 *
	 *3a- Send high
	 *3a- delay
	 *3a- send low
	 */
	Latch_Data();
}
