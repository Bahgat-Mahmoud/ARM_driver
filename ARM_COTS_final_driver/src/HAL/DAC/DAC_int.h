/*
 * DAC_int.h
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#ifndef HAL_DAC_DAC_INT_H_
#define HAL_DAC_DAC_INT_H_


void HDAC_vInit(void);
void HDAC_vSendSignal(unsigned char arr[] , u32 A_u32Size);
void HDAC_vSendSignal_(unsigned char  arr[]);
#endif /* HAL_DAC_DAC_INT_H_ */
