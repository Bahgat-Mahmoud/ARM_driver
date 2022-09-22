/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 9  sep 2022                                          */
/* Description : Interface file for LCD module                        */
/**********************************************************************/
#ifndef LCD_interface_H_
#define LCD_interface_H_

#define      LCD_LINE0        0
#define      LCD_LINE1        1
#define      LCD_LINE2        2
#define      LCD_LINE3        3

/*init*/
void HLCD_vInit(void); // initialize
/*send command*/
void HLCD_vSendCommand (u8 A_u8Cmd); // command
/*print data (Char , number , string)*/
void HLCD_vSendChar(u8 A_u8Char);// print data
void HLCD_vPrintString (char A_s8String[]);
void HLCD_vPrintNumber(s32 A_s32Number);
/*position control */
void HLCD_vSetCursorPostion(u8 A_u8LinePos , u8 A_u8LionNo);//A_u8LionPostion x axcis
/*Clear screan*/
void HLCD_vClearCommand(void);
/*for CGRAM for pattern*/
u8 HLC_u8WriteInCGRAM(u8 A_u8patternIdx , u8 *A_u8patternValue);
u8 HLCD_u8DisplayCustomChar(u8 A_u8patternIdx);

#endif
