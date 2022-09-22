/*
 * STK_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"
#include "STK_int.h"
#include "STK_cfg.h"
#include "STK_prv.h"
static u8 G_u8ModeInterval= 3 ;
static void (*MSTK_CallBack) (void);
/*
 SysTick design hints and tips
The SysTick counter runs on the processor clock. If this clock signal is stopped for low
power mode, the SysTick counter stops.
Ensure software uses aligned word accesses to access the SysTick registers.
The SysTick counter reload and current value are undefined at reset, the correct
initialization sequence for the SysTick counter is:
1. Program reload value.
2. Clear current value.
3. Program Control and Status register.
 */
void MSTK_vInit(void)
{
	/*
	 * choose Clock_Source
	 * AHB  or AHB/8
	 * I want every Tick == 1 microsecond
	 * AHB/8  + CLOCK HSI_ps2
	 */
#if CLOCK_SOURCE==AHB_PS_8
	CLR_BIT(STK->CTRL,CLK_SOURCE);
#else
	SET_BIT(STK->CTRL,CLK_SOURCE);
#endif
	/*interrupt enable or disable*/
	/*disable STK & disable interrupt*/
	CLR_BIT(STK->CTRL,ENABLE);
	CLR_BIT(STK->CTRL,TICK_INT);
}

void MSTK_vSetBusyWait_us(u32 A_u32Ticks)//delay func
{
	u8 L_u8ReadFlag ;
	/*1- load value */
	STK->VAL  = 0;
	STK->LOAD = A_u32Ticks ;
	/*2-start timer*/
	SET_BIT(STK->CTRL,ENABLE);
	/*3-Wait the counter is complete "polling" */
	while(GET_BIT(STK->CTRL,COUNT_FLAG)==0);
	/*4-Clear the Flag by read*/
	L_u8ReadFlag = GET_BIT(STK->CTRL,COUNT_FLAG) ;
	/*4-disable timer & erase the STK_VAL &STK_LOAD (stop) */
	CLR_BIT(STK->CTRL,ENABLE);
	//	STK->LOAD = 0;
	//	STK->VAL  = 0;
}
void MSTK_vSetIntervalSingle(u32 A_u32Ticks,void (*A_ptr) (void))
{

	/*1- load value */
	STK->VAL  = 0;
	STK->LOAD = A_u32Ticks ;
	SET_BIT(STK->CTRL,ENABLE);
	/*2-assign the function pointer & type of Mode*/
	MSTK_CallBack = A_ptr;
	G_u8ModeInterval = MSTK_SINGLE_INTERVAL ;
	/*3- Enable interrupt & start timer*/
	SET_BIT(STK->CTRL,TICK_INT);
}
void MSTK_vSetIntervalPeriodic(u32 A_u32Ticks,void (*A_ptr) (void))
{
	/*1- load value */
	STK->LOAD = A_u32Ticks ;
	/*2-assign the function pointer & type of Mode*/
	MSTK_CallBack = A_ptr;
	G_u8ModeInterval = MSTK_PERIODIC_INTERVAL ;
	/*3- Enable interrupt & start timer*/
	SET_BIT(STK->CTRL,ENABLE);
	SET_BIT(STK->CTRL,TICK_INT);
}
/*stop*/
void MSTK_vStopInterval(void)
{
//	u8 L_u8ReadFlag ;
	/*4-disable Interrupt & timer & erase the STK_VAL and STK_LOAD (stop) */
	CLR_BIT(STK->CTRL,TICK_INT);
	CLR_BIT(STK->CTRL,ENABLE);
	STK->LOAD = 0;
	/*write any value to clear this register this is clear the flag*/
	STK->VAL  = 0;
	/*clear flag*/
	//	 L_u8ReadFlag  = GET_BIT(STK->CTRL,COUNT_FLAG);
}
/*Read Elapsed time*/
u32  MSTK_u32GetElapsedTime(void)
{
	u32 L_u32ElapsedTime = (STK->LOAD) - (STK->VAL) ;
	return L_u32ElapsedTime ;
}
/*Read Remaining time*/
u32  MSTK_u32GetRemainingTime(void)
{
	u32 RemainingTime = STK->VAL ;
	return RemainingTime ;
}
//ISR of Timer in core peripheral
void  SysTick_Handler (void)
{
	u8 L_u8ReadFlag ;
	if(G_u8ModeInterval==MSTK_SINGLE_INTERVAL)
	{
		MSTK_vStopInterval();
	}
	if(MSTK_CallBack!=NULL)
	{
		MSTK_CallBack();
	}
	/*must be clear flag in any time enter ISR (clear by read flag)*/
	 L_u8ReadFlag  = GET_BIT(STK->CTRL,COUNT_FLAG);
}
