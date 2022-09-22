/*
 * LEDMAT_prg.c
 *
 *  Created on: Sep 6, 2022
 *      Author: DELL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/STK_int.h"
#include "../S2P/S2P_int.h"
#include "LEDMAT_cfg.h"
#include "LEDMAT_int.h"
#include "LEDMAT_prv.h"

#if LEDMAT_METHOD == LEDMAT_DIRECT
extern MGPIO_Config_t rows[NUM_OF_ROW] ;
extern MGPIO_Config_t cols[NUM_OF_COL] ;
#endif

void HLEDMAT_vInit(void)
{
#if LEDMAT_METHOD == LEDMAT_DIRECT

	for(int i=0 ; i<NUM_OF_COL ;i++)
	{
		MGPIO_vInit(&cols[i]);
	}
	for(int i=0 ; i<NUM_OF_ROW ;i++)
	{
		MGPIO_vInit(&rows[i]);
	}
#elif LEDMAT_METHOD == LEDMAT_S2P
	HS2P_vInit();
#else
#error  "Please Choose the method"
#endif
	MSTK_vInit();
}
#if LEDMAT_METHOD == LEDMAT_DIRECT

static void HLEDMTX_vDisableAllColumns(void)
{
	for(int i=0 ; i<NUM_OF_COL;i++)
	{
		MGPIO_vSetPinVal(cols[i].port,cols[i].pin,GPIO_HIGH);
	}
}
static void LEDMTX_vSetRowVal(u8 A_u8Values)
{
	for(int i=0 ; i<NUM_OF_ROW;i++)
	{

		MGPIO_vSetPinVal(cols[i].port,rows[i].pin,GET_BIT(A_u8Values,i));
	}
}
static void LEDMTX_vSetCurrentColumn(u8 A_u8ColNo)
{
	MGPIO_vSetPinVal(cols[A_u8ColNo].port,cols[A_u8ColNo].pin,GPIO_LOW);
}
#endif
void HLEDMAT_vDisplayFrame(u8 A_u8fram[] , u32 A_u32FrameDelay)
{
	//A_u32FrameDelay
#if  LEDMAT_METHOD == LEDMAT_S2P
	u16 L_u16S2pData ;
#endif

	for (u32 A_u32J= 0 ; A_u32J <A_u32FrameDelay ;A_u32J++)
	{
		for(int A_u32Iter=0 ; A_u32Iter < NUM_OF_COL; A_u32Iter++)
		{
#if LEDMAT_METHOD == LEDMAT_DIRECT
			/*disable all columns*/
			HLEDMTX_vDisableAllColumns();
			/*2- Set row Values*/
			LEDMTX_vSetRowVal(~fram[A_u32Iter]);
			/*3- Set current column*/
			LEDMTX_vSetCurrentColumn(A_u32Iter);

#elif LEDMAT_METHOD == LEDMAT_S2P
			/* 1- disable all columns */
			L_u16S2pData = 0xff00 ; // 0x00ff
			HS2P_vSendData(L_u16S2pData) ;
			/* 2- set row values      */
			/* 3- set current column  */
			L_u16S2pData = (~(u16)A_u8fram[A_u32Iter]) & ~((1<<(A_u32Iter+8))) ;
			HS2P_vSendData(L_u16S2pData) ;
#endif
			/*4- delay for suitable FPS*/
			MSTK_vSetBusyWait_us(SCAN_TIME);//2.5msec

		}
	}


}
///*snak_Tow*/
//void HLEDMAT_vDisplayMatrix(u8 matrix[NUM_OF_ROW][NUM_OF_COL],u32 A_u32FrameDelay)
//{
//
//}

//
//#define LSBFIRST 0
//#define MSBFIRST 1

//typedef struct {
//    volatile unsigned char * Port;
//    u16 NUmber;
//}Pin;

// function Implementation
//void MGPIO_vShiftOutPin(Pin A_u8DataPin, Pin A_u8ClockPin, u8 A_u8BitOrder, u16 A_u16Val)
//{
//    char i;
//
//    for (i = 0; i < 16; i++)
//     {
//        if (A_u8BitOrder == LSBFIRST)
//        {
//            (A_u16Val & (1 << i)) ? MGPIO_vSetPinVal(A_u8DataPin.Port,A_u8DataPin.NUmber,GPIO_HIGH) : MGPIO_vSetPinVal(A_u8DataPin.Port,A_u8DataPin.NUmber,GPIO_LOW);

//        }
//        else
//        {
//            (A_u16Val & (1 << (15 - i))) ? MGPIO_vSetPinVal(A_u8DataPin.Port,A_u8DataPin.NUmber,GPIO_HIGH) : MGPIO_vSetPinVal(A_u8DataPin.Port,A_u8DataPin.NUmber,GPIO_LOW);;
//        }
//
//        // make a clockpin go from high to low
//        MGPIO_vSetPinVal(A_u8ClockPin.Port,A_u8ClockPin.NUmber,GPIO_HIGH);
//
//        MGPIO_vSetPinVal(A_u8ClockPin.Port,A_u8ClockPin.NUmber,GPIO_LOW);
//    }
//}
