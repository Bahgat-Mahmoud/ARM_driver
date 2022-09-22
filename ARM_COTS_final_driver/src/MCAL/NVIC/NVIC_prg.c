/*
 * NVIC_prg.c
 *
 *  Created on: Aug 30, 2022
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "NVIC_prv.h"
#include "NVIC.int.h"

/*INVIC enable peripheral INT */

void MNVIC_vEnableINTPeripheral(u8 A_u8INTID)
{
//A_u8INTID / 32  to get the number of register
//A_u8INTID % 32  to get the number of bit
	NVIC->ISER[A_u8INTID / 32]= 1<< (A_u8INTID % 32);//set bit

}
void MNVIC_vDisableINTPeripheral(u8 A_u8INTID)
{
NVIC->ICER[A_u8INTID / 32] = 1<< (A_u8INTID % 32);//CLEAR BIT
}

//Function to test
void MNVIC_vSetPending(u8 A_u8INTID)
{
NVIC->ISPR [A_u8INTID / 32] = 1 << (A_u8INTID % 32); // change interrupt state to pending
}
void MNVIC_vClearPending(u8 A_u8INTID)
{
NVIC->ICPR [A_u8INTID / 32] = 1<< (A_u8INTID % 32);//1: Removes the pending state of an interrupt
}
//to check
u8 MNVIC_u8GetActive(u8 A_u8INTID)
{
 u8 L_u8IntActive = GET_BIT(NVIC->IABR[A_u8INTID / 32],(A_u8INTID % 32) );
return L_u8IntActive;
}
// (the register of AIRCR) page  228 priority grouping
//void MNVIC_vSetpriority(s8 A_s8IntId , u8 A_u8GroupPriorty ,u8 A_u8SupPriorty)
//{
//
//}
//void MNVIC_vSetPriorityConfig(u8 A_u8PriorityOption)
//{
//
//}

