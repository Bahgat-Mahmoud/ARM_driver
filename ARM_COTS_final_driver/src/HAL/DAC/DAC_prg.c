/*
 * DAC_prg.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"

#include "../../MCAL/SYSTICK/STK_int.h"

#include "DAC_prv.h"
#include "DAC_cfg.h"
#include "DAC_int.h"
extern  MGPIO_Config_t  HDAC_PIN[DAC_NO_PIN];
static u8 *ptr = 0;
static u32 G_u32Size =0;

static void HDAC_vStarSend(void)
{
	static u32 L_u32Iter =0 ;
	for(u8 L_u16Iter=0;L_u16Iter<8;L_u16Iter++)
	{
		MGPIO_vSetPinVal(HDAC_PIN[L_u16Iter].port,HDAC_PIN[L_u16Iter].pin,GET_BIT(ptr[L_u32Iter],L_u16Iter));
	}
	if (L_u32Iter < (G_u32Size)) L_u32Iter++;
	else L_u32Iter = 0 ;

}

void HDAC_vInit(void)
{
	for(u16 L_u16Iter=0;L_u16Iter<DAC_NO_PIN;L_u16Iter++)
	{
		MGPIO_vInit(&HDAC_PIN[L_u16Iter]);
	}
}
void HDAC_vSendSignal(unsigned char arr[] , u32 A_u32Size)
{
	ptr=arr;
	G_u32Size = A_u32Size;
	MSTK_vSetIntervalPeriodic(DAC_NO_TICK,HDAC_vStarSend);
}

void HDAC_vSendSignal_(unsigned char  arr[])
{
	for(u32 j=0 ;j<27957;j++)
	{
		for(u8 L_u16Iter=0;L_u16Iter<8;L_u16Iter++)
		{
			MGPIO_vSetPinVal(HDAC_PIN[L_u16Iter].port,HDAC_PIN[L_u16Iter].pin,GET_BIT(arr[j],L_u16Iter));
		}
		MSTK_vSetBusyWait_us(125);
	}

}
