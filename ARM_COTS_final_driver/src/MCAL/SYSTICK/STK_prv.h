/*
 * STK_prv.h
 *
 *  Created on: Aug 31, 2022
 *      Author: DELL
 */

#ifndef MCAL_SYSTICK_STK_PRV_H_
#define MCAL_SYSTICK_STK_PRV_H_


#define STK_BASE_ADDRESS    0xE000E010

typedef struct
{
volatile u32  CTRL;
volatile u32  LOAD;
volatile u32  VAL;//note A write of any value clears the field to 0, and also clears the COUNTFLAG bit in the STK_CTRL register to 0.
volatile u32  CALIB;
}STK_MemMap_t;

#define  STK   ((volatile STK_MemMap_t*)(STK_BASE_ADDRESS))
/*
 0: Counter disabled
1: Counter enabled
 */
#define  ENABLE         0 //Counter enable
/*enable interrupt*/
#define  TICK_INT       1
/*
CLKSOURCE: Clock source selection Selects the clock source.
0: AHB/8
1: Processor clock (AHB)
 */
#define  CLK_SOURCE     2
/*flag of interrupt occurs */
#define  COUNT_FLAG     16

#define  MSTK_SINGLE_INTERVAL      1
#define  MSTK_PERIODIC_INTERVAL    2

#define  AHB_PS_8       8
#define  AHB_PS_1       1

#endif /* MCAL_SYSTICK_STK_PRV_H_ */
