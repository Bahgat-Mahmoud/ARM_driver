/*
 * EXTI_prv.h
 *
 *  Created on: Aug 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

/*connect with APB2*/
#define  TXTI_BASE_ADDRESS       0x40013C00

typedef struct
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;

}EXTI_MemMap_t;

#define  EXTI   ((volatile EXTI_MemMap_t*) (TXTI_BASE_ADDRESS))

#define ENABLE  1
#define DISABLE 0

//#define EXTI_RISING
//#define EXTI_FAILING
//#define EXTI_

#endif /* MCAL_EXTI_EXTI_PRV_H_ */
