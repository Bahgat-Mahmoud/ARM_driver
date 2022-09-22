/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 18 sep 2022                                          */
/* Description : Program file for OS module                           */
/* Version     : V01                                                  */
/**********************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/SYSTICK/STK_int.h"

#include "RTOS_int.h"
#include "RTOS_cfg.h"
#include "RTOS_prv.h"

Task    SystemTasks    [MAX_NO_TASKS] ={0};
u8      G_u8TaskTiming [MAX_NO_TASKS];

Task Empty = {0} ;
void RTOS_voidStartOS(void)
{
	MSTK_vSetIntervalPeriodic(TICK_TIME,Scheduler);
}

u8 RTOS_u8CreateTask ( void(*A_Handler)(void) , u8 A_u8Periodicity, u8 A_u8Priority , u8 A_FirstD )
{
	u8 L_u8ErrorState =0 ;
	/* Verify that the priority index within the correct range */
	if(A_u8Priority<MAX_NO_TASKS)
	{
		if(SystemTasks[A_u8Priority].TaskHandler !=0 )
		{
			SystemTasks[A_u8Priority].TaskHandler = A_Handler;
			SystemTasks[A_u8Priority].Periodicity = A_u8Periodicity;
			G_u8TaskTiming[A_u8Priority]          = A_FirstD;
			SystemTasks[A_u8Priority].FirstDelay  = A_FirstD ;

		}
		else
		{
			/* The required priority is all read reserved */
			L_u8ErrorState = 2;
		}
	}
	else
	{
		/* Wrong priority */
		L_u8ErrorState = 1;
	}
	return L_u8ErrorState ;
}
void Scheduler(void)
{

	/*Loop on all tasks*/
	for(u8 L_u8Count=0; L_u8Count<MAX_NO_TASKS;L_u8Count++)
	{
		/*Is there a registered task ...?*/
		if(SystemTasks[L_u8Count].TaskHandler != NULL)
		{
			if(SystemTasks[L_u8Count].TaskRunState == Running)
			{
				if(G_u8TaskTiming[L_u8Count] == 0)
				{
					/*Run the task by call the function*/
					SystemTasks[L_u8Count].TaskHandler();
					/*Reload the periodicity*/
					G_u8TaskTiming[L_u8Count]=SystemTasks[L_u8Count].Periodicity;
				}
				else
				{
					G_u8TaskTiming[L_u8Count]--;
				}
			}
		}
	}
}
u8 RTOS_u8DeleteTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState =0 ;
	if(SystemTasks[A_u8Priority].TaskHandler !=NULL)
	{
		/* Task exist, execute the removal */
		SystemTasks[A_u8Priority]= Empty;
	}
	else
	{
		/*Task Not exist*/
		L_u8ErrorState = 3 ;
	}
	return L_u8ErrorState;
}

u8 RTOS_u8SuspendTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState=0;
	if(SystemTasks[A_u8Priority].TaskHandler !=NULL)
	{
		SystemTasks[A_u8Priority].TaskRunState = Suspended;
	}
	else
	{
		/*Task Not exist*/
		L_u8ErrorState = 3 ;
	}
	return L_u8ErrorState;

}

u8 RTOS_u8ResumeTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState=0;
	if(SystemTasks[A_u8Priority].TaskHandler != NULL)
	{
		SystemTasks[A_u8Priority].TaskRunState = Running;
	}
	else
	{
		/*Task Not exist*/
		L_u8ErrorState = 3 ;
	}
	return L_u8ErrorState;
}
