/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 18 sep 2022                                          */
/* Description : Private file for OS module                           */
/* Version     : V01                                                  */
/**********************************************************************/
#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_

typedef enum
{
	Suspended,
	Running
}RunState;

typedef struct
{
	void  (*TaskHandler)(void)  ;
	u8        Periodicity       ;
	u8        FirstDelay        ;
	RunState  TaskRunState      ;
}Task;


#endif /* RTOS_RTOS_PRV_H_ */
