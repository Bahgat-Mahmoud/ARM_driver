/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 18 sep 2022                                          */
/* Description : Interface file for OS module                         */
/* Version     : V01                                                  */
/**********************************************************************/
#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_

void RTOS_voidStartOS(void);

u8 RTOS_u8CreateTask ( void(*A_Handler)(void) , u8 A_u8Periodicity, u8 A_u8Priority , u8 A_FirstD );
void Scheduler(void);

u8 RTOS_u8DeleteTask(u8 A_u8Priority);

u8 RTOS_u8SuspendTask(u8 A_u8Priority);

u8 RTOS_u8ResumeTask(u8 A_u8Priority);

#endif /* RTOS_RTOS_INT_H_ */
