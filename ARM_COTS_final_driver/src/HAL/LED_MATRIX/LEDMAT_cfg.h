/*
 * LEDMAT_cfg.h
 *
 *  Created on: Sep 6, 2022
 *      Author: DELL
 */

#ifndef HAL_LED_MATRIX_LEDMAT_CFG_H_
#define HAL_LED_MATRIX_LEDMAT_CFG_H_
/*
 LEDMAT_S2P	              //serial to parallel
 LEDMAT_DIRECT
 */
/*******************************************
 *  Can Not You Change  *   Can you change *
 *******************************************/
#define LEDMAT_METHOD        LEDMAT_S2P

/*choose Number of column & row */
#define NUM_OF_ROW           8
#define NUM_OF_COL           8


#define SCAN_TIME            2500  //[# Timer Ticks]


#endif /* HAL_LED_MATRIX_LEDMAT_CFG_H_ */
