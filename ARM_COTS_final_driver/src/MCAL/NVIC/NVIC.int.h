/*
 * NVIC.int.h
 *
 *  Created on: Aug 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

#define NVIC_EXTIO   6
/*SW vector table FOR  PERIPHERAL*/

#define	NVIC_WWDG            0
#define	NVIC_PVD             1
#define NVIC_EXTI16          1
#define	NVIC_TAMP_STAMP      2
#define NVIC_EXTI21          2
#define NVIC_EXTI22          3
#define	NVIC_RTC_WKUP        3

#define	NVIC_FLASH           4
#define	NVIC_RCC             5
#define	NVIC_EXTI0           6
#define	NVIC_EXTI1           7
#define	NVIC_EXTI2           8
#define	NVIC_EXTI3           9
#define	NVIC_EXTI4           10

#define	NVIC_DMA1_STREAM0    11
#define	NVIC_DMA1_STREAM1    12
#define	NVIC_DMA1_STREAM2    13
#define	NVIC_DMA1_STREAM3    14
#define	NVIC_DMA1_STREAM4    15
#define	NVIC_DMA1_STREAM5    16
#define	NVIC_DMA1_STREAM6    17

#define	NVIC_ADC             18
/*asking*/
#define	NVIC_EXTI5           23
#define	NVIC_EXTI6           23
#define	NVIC_EXTI7           23
#define	NVIC_EXTI8           23
#define	NVIC_EXTI9           23


#define	NVIC_TIM1_BRK_TIM9   24
#define	NVIC_TIM1_UP_TIM10   25
#define	NVIC_TIM1_TRG_COM_TIM11   26
#define	NVIC_TIM1_CC              27
#define	NVIC_TIM2                 28
#define	NVIC_TIM3                 29
#define	NVIC_TIM4                 30

#define	NVIC_I2C1_EV              31
#define	NVIC_I2C1_ER              32
#define	NVIC_I2C2_EV              33
#define	NVIC_I2C2_ER              34

#define	NVIC_SPI1                 35
#define	NVIC_SPI2                 36

#define	NVIC_USART1               37
#define	NVIC_USART2               38


#define NVIC_EXTI10               40
#define NVIC_EXTI11               40
#define NVIC_EXTI12               40
#define NVIC_EXTI13               40
#define NVIC_EXTI14               40
#define NVIC_EXTI15               40

#define NVIC_EXTI17               41
#define	NVIC_RTC_ALARM            41

#define NVIC_EXTI18               42
#define	NVIC_OTG_FS_WKUP          42

#define	NVIC_DMA1_STREAM7         47

#define NVIC_SDIO                 49
#define NVIC_TIM5                 50

#define NVIC_SPI3                 51

#define NVIC_DMA2_STREAM0         56
#define NVIC_DMA2_STREAM1         57
#define NVIC_DMA2_STREAM2         58
#define NVIC_DMA2_STREAM3         59
#define NVIC_DMA2_STREAM4         60

#define NVIC_OTG_FS               67

#define NVIC_DMA2_STREAM5         68
#define NVIC_DMA2_STREAM6         69
#define NVIC_DMA2_STREAM7         70

#define NVIC_USART6               71

#define NVIC_I2C3_EV              72
#define NVIC_I2C3_ER              73

#define NVIC_FPU                  81
#define NVIC_SPI4                 84

/*SW vector table for core peripheral*/

#define  NVIC_SYSTICK         -7
#define  NVIC_PENDSV          -6

#define  NVIC_PEND_SV         -5
#define  NVIC_DEBUG_MONITOR   -4

#define  NVIC_SV_ CALL        -3
#define  NVIC_USAGE_FAULT     -2
#define  NVIC_BUS_FAULT       -1

/*to define group*/
#define NVIC_GROUP_4BITS    0b000
#define NVIC_GROUP_3BITS    0b100
#define NVIC_GROUP_2BITS    0b101
#define NVIC_GROUP_1BITS    0b110
#define NVIC_GROUP_0BITS    0b111



void MNVIC_vEnableINTPeripheral(u8 A_u8INTID);
void MNVIC_vDisableINTPeripheral(u8 A_u8INTID);
/* Function: MNVIC_VoidSetPending */
/*I/P Parameters: Interrupt ID    */
/*Returns:it returns no thing	  */
/*Desc:This Function Sets pending flag of Peripheral */

//Function to test
void MNVIC_vSetPending(u8 A_u8INTID);
void MNVIC_vClearPending(u8 A_u8INTID);
//to check
u8 MNVIC_u8GetActive(u8 A_u8INTID);

//void MNVIC_vSetpriority(s8 A_s8IntId , u8 A_u8GroupPriorty ,u8 A_u8SupPriorty);
//void MNVIC_vSetPriorityConfig(u8 A_u8PriorityOption);

#endif /* MCAL_NVIC_NVIC_INT_H_ */
