/*
 * LEDMAT_int.h
 *
 *  Created on: Sep 6, 2022
 *      Author: DELL
 */

#ifndef HAL_LED_MATRIX_LEDMAT_INT_H_
#define HAL_LED_MATRIX_LEDMAT_INT_H_

void HLEDMAT_vInit(void);


void HLEDMAT_vDisplayFrame(u8 fram[] , u32 A_u32FrameDelay);
/*snak_Tow*/
//void HLEDMAT_vDisplayMatrix(u8 matrix[NUM_OF_ROW][NUM_OF_COL],u32 A_u32FrameDelay);
/*
 * [array two de to one
 * HLEDMAT_vDisplayFrame
 */


#endif /* HAL_LED_MATRIX_LEDMAT_INT_H_ */
