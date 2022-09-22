/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 9  sep 2022                                          */
/* Description : Configuration file for LCD module                    */
/**********************************************************************/

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


/*Please Configuration The AHB is HSI and signal frequency/2 & AHB/2*/


#define  MAX_IDX_OF_ROWS            2

#define  MAX_IDX_OF_COL             15

/*
 options:
 LCD_FUNCTION_SET: 0b0011NF00
  Where NF
  00  one line display  & 5*7 dot character font
  10  Two line display  & 5*7 dot character font

  */
#define   LCD_FUNCTION_SET   0b00111000

/*
 *  options:
 LCD_DISPLAY_CURSOR: 0b00001DCB
	 D=1 display on   D=1 display off
	 C=0 cursor off   C=1 cursor on
	 B=0 blink off    B=0 Blink on
*/
#define LCD_DISPLAY_CURSOR 0b00001100

/*
	  0b000001I/DSH
	  I/D  1   increment the cursor automatic +1
	  SH=0 don`t interested now
*/
#define LCD_ENTRY_MODE_SET 0b00000110


#endif /* HAL_LCD_LCD_CFG_H_ */
