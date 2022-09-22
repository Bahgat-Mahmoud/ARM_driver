/*
 * EXTI_prg.c
 *
 *  Created on: Aug 30, 2022
 *      Author: DELL
 */

#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"
#include "SYSFG_prv.h"
// interrupt based register
// enable interrupt by IMR
/*to init external interrupt*/
static void (*EXTI_CallBack_LINE[16])(void);

void MEXTI_vInit(void)
{
	EXTI->IMR = 0;
	EXTI->IMR |= ( EXTI_LINE_0_EN << 0)|
			(EXTI_LINE_1_EN <<1 )|
			(EXTI_LINE_2_EN <<2 )|
			(EXTI_LINE_3_EN <<3 )|
			(EXTI_LINE_4_EN <<4 )|
			(EXTI_LINE_5_EN <<5 )|
			(EXTI_LINE_6_EN <<6 )|
			(EXTI_LINE_7_EN <<7 )|
			(EXTI_LINE_8_EN <<8 )|
			(EXTI_LINE_9_EN <<9 )|
			(EXTI_LINE_10_EN <<10)|
			(EXTI_LINE_11_EN <<11)|
			(EXTI_LINE_12_EN <<12)|
			(EXTI_LINE_13_EN <<13)|
			(EXTI_LINE_14_EN <<14)|
			(EXTI_LINE_15_EN <<15)
			;
	/*for trigger*/
	//#if EXTI_LINE_0_TRIGGER == EXTI_RISING
	//	SET_BIT(EXTI->RTSR,0) ;
	//#endif
	/*clear all flag*/
	EXTI->PR =0xffffffff;
}
/*to Enable Line external interrupt*/
void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8line)
{
	if(A_u8line< 16)
	{
		SET_BIT(EXTI->IMR,A_u8line);

		switch(A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8line);
			CLR_BIT(EXTI->FTSR,A_u8line);//should the foaling is clear
			break;
		case EXTI_FAILING:
			CLR_BIT(EXTI->RTSR,A_u8line);
			SET_BIT(EXTI->FTSR,A_u8line);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR,A_u8line);
			SET_BIT(EXTI->FTSR,A_u8line);
			break;
		}
	}
}
/*to disable interrupt*/
void MEXTI_vDisableLine(u8 A_u8line)
{
	if(A_u8line< 16)
	{
		CLR_BIT(EXTI->IMR,A_u8line);
	}
}
/*to  test*/
void MEXTI_vSoftwareTrigger(u8 A_u8line)
{
	if(A_u8line< 16)
	{
		SET_BIT(EXTI->SWIER,A_u8line);//like set pending
	}

}
/*to change trigger */
void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8line)
{
	if(A_u8line< 16)
	{
		switch(A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8line);
			CLR_BIT(EXTI->FTSR,A_u8line);//should the foaling is clear
			break;
		case EXTI_FAILING:
			CLR_BIT(EXTI->RTSR,A_u8line);
			SET_BIT(EXTI->FTSR,A_u8line);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR,A_u8line);
			SET_BIT(EXTI->FTSR,A_u8line);
			break;
		}
	}

}
void MEXTI_vSetCallBack(void (*A_vCallBack)(void), u8 A_u8line)
{
	if( A_u8line<16)
	{
		switch(A_u8line)
		{
		case EXTI_LINE0 :
			EXTI_CallBack_LINE[0] = A_vCallBack;
			break;
		case EXTI_LINE1 :
			EXTI_CallBack_LINE[1] = A_vCallBack;
			break;
		case EXTI_LINE2 :
			EXTI_CallBack_LINE[2] = A_vCallBack;
			break;
		case EXTI_LINE3 :
			EXTI_CallBack_LINE[3] = A_vCallBack;
			break;
		case EXTI_LINE4 :
			EXTI_CallBack_LINE[4] = A_vCallBack;
			break;
		case EXTI_LINE5 :
			EXTI_CallBack_LINE[5] = A_vCallBack;
			break;
		case EXTI_LINE6 :
			EXTI_CallBack_LINE[6] = A_vCallBack;
			break;
		case EXTI_LINE7 :
			EXTI_CallBack_LINE[7] = A_vCallBack;
			break;
		case EXTI_LINE8 :
			EXTI_CallBack_LINE[8] = A_vCallBack;
			break;
		case EXTI_LINE9 :
			EXTI_CallBack_LINE[9] = A_vCallBack;
			break;
		case EXTI_LINE10 :
			EXTI_CallBack_LINE[10] = A_vCallBack;
			break;
		case EXTI_LINE11 :
			EXTI_CallBack_LINE[11] = A_vCallBack;
			break;
		case EXTI_LINE12 :
			EXTI_CallBack_LINE[12] = A_vCallBack;
			break;
		case EXTI_LINE13 :
			EXTI_CallBack_LINE[13] = A_vCallBack;
			break;
		case EXTI_LINE14 :
			EXTI_CallBack_LINE[14] = A_vCallBack;
			break;
		case EXTI_LINE15 :
			EXTI_CallBack_LINE[15] = A_vCallBack;
			break;
		}
	}
}


/*ISR*/
void EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack_LINE[0] !=NULL)
	{
		EXTI_CallBack_LINE[0]();
	}
	//clear flag EXTI0
	SET_BIT(EXTI->PR,EXTI_LINE0);

}
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_LINE1);
	if(EXTI_CallBack_LINE[1] !=NULL)
	{
		EXTI_CallBack_LINE[1]();
	}
}
void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_LINE2);
	if(EXTI_CallBack_LINE[2] !=NULL)
	{
		EXTI_CallBack_LINE[2]();
	}
}
void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_LINE3);
	if(EXTI_CallBack_LINE[3] !=NULL)
	{
		EXTI_CallBack_LINE[3]();
	}
}
void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_LINE4);
	if(EXTI_CallBack_LINE[4] !=NULL)
	{
		EXTI_CallBack_LINE[4]();
	}
}
void EXTI9_5_IRQHandler(void)
{
	if( GET_BIT(EXTI->PR,EXTI_LINE5)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE5);
		if(EXTI_CallBack_LINE[5] !=NULL)
		{
			EXTI_CallBack_LINE[5]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE6)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE6);
		if(EXTI_CallBack_LINE[6] !=NULL)
		{
			EXTI_CallBack_LINE[6]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE7)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE7);
		if(EXTI_CallBack_LINE[7] !=NULL)
		{
			EXTI_CallBack_LINE[7]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE8)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE8);
		if(EXTI_CallBack_LINE[8] !=NULL)
		{
			EXTI_CallBack_LINE[8]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE9)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE9);
		if(EXTI_CallBack_LINE[9] !=NULL)
		{
			EXTI_CallBack_LINE[9]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE10)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE10);
		if(EXTI_CallBack_LINE[0] !=NULL)
		{
			EXTI_CallBack_LINE[10]();
		}
	}

}
void EXTI15_10_IRQHandler(void)
{
	if( GET_BIT(EXTI->PR,EXTI_LINE10)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE10);
		if(EXTI_CallBack_LINE[10] !=NULL)
		{
			EXTI_CallBack_LINE[10]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE11)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE11);
		if(EXTI_CallBack_LINE[11] !=NULL)
		{
			EXTI_CallBack_LINE[11]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE12)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE12);
		if(EXTI_CallBack_LINE[12] !=NULL)
		{
			EXTI_CallBack_LINE[12]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE13)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE13);
		if(EXTI_CallBack_LINE[13] !=NULL)
		{
			EXTI_CallBack_LINE[13]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE14)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE14);
		if(EXTI_CallBack_LINE[14] !=NULL)
		{
			EXTI_CallBack_LINE[14]();
		}
	}
	if( GET_BIT(EXTI->PR,EXTI_LINE15)==1)
	{
		SET_BIT(EXTI->PR,EXTI_LINE15);
		if(EXTI_CallBack_LINE[15] !=NULL)
		{
			EXTI_CallBack_LINE[15]();
		}
	}
}
void MSYSCFG_vSetExtiPort(u8 A_u8LinNO,u8 A_u8PortNo)
{
	u8 L_u8Index = A_u8LinNO/4;
	u8 L_u8ShiftAmount = (A_u8LinNO%4) *4 ;
	SYSCFG->EXTICR[L_u8Index] &= ~((0b1111)   << (L_u8ShiftAmount));
	SYSCFG->EXTICR[L_u8Index] |=((A_u8PortNo) << (L_u8ShiftAmount));
}
/*please not forgive*/
//void MSYSCFG_vSetExtiPort(u8 A_u8line,u8 A_u8PortNum)
//{
//	if(A_u8line< 16)
//	{
//		switch(A_u8PortNum)
//		{
//		case GPIO_PORTA :
//
//			break;
//		case GPIO_PORTB :
//
//			break;
//		case GPIO_PORTC :
//
//			break;
//		}
//	}
//}
