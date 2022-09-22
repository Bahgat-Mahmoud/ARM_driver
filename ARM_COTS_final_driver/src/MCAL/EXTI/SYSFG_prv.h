/*
 * SYSFG_prv.h
 *
 *  Created on: Sep 1, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_SYSFG_PRV_H_
#define MCAL_EXTI_SYSFG_PRV_H_

#define  SYSCFG_BASE_ADDRESS   0x40013800

typedef struct
{
volatile u32  MEMRMP ;
volatile u32  PMC ;
volatile u32  EXTICR[4];
volatile u8 RESERRVED1;
volatile u32 RESERRVED2;
volatile u32 CMPCR;

}SYSCFG_MemMap_t;

#define  SYSCFG   ((volatile SYSCFG_MemMap_t*)SYSCFG_BASE_ADDRESS)




#endif /* MCAL_EXTI_SYSFG_PRV_H_ */
