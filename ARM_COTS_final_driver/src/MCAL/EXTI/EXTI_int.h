/*
 * EXTI_int.h
 *
 *  Created on: Aug 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
};
/*from data sheet page 142 */
#define EXTI_PORTA      0b0000
#define EXTI_PORTB      0b0001
#define EXTI_PORTC      0b0010

/*for choose rising or failing */
#define  EXTI_RISING    1
#define  EXTI_FAILING   2
#define  EXTI_ONCHANGE  3

/*init*/
void MEXTI_vInit(void);
/*enable line*/
void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8line);
/*disable*/
void MEXTI_vDisableLine( u8 A_u8line);
/*for test*/
void MEXTI_vSoftwareTrigger(u8 A_u8Line);

/*to change trigger */
void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8line);
/*call back func*/
void MEXTI_vSetCallBack(void (*A_vCallBack)(void), u8 A_u8line);

void MSYSCFG_vSetExtiPort(u8 A_u8line,u8 A_u8PortNum);
#endif /* MCAL_EXTI_EXTI_INT_H_ */
