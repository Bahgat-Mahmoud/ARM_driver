/*
 * STK_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: DELL
 */

#ifndef MCAL_SYSTICK_STK_INT_H_
#define MCAL_SYSTICK_STK_INT_H_

void MSTK_vInit(void);
void MSTK_vSetBusyWait_us(u32 A_u32Ticks);
void MSTK_vSetIntervalSingle(u32 A_u32Ticks,void (*A_ptr) (void));
void MSTK_vSetIntervalPeriodic(u32 A_u32Ticks,void (*A_ptr) (void));

void MSTK_vStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif /* MCAL_SYSTICK_STK_INT_H_ */
