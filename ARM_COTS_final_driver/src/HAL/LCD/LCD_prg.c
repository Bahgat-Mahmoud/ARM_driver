/**********************************************************************/
/* AUTHOR      : Bahgat Mahmoud                                       */
/* DATE        : 9  sep 2022                                          */
/* Description : Program file for LCD module                          */
/**********************************************************************/
#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/BIT_MATH.h"

#include  "../../MCAL/GPIO/GPIO_int.h"
#include  "../../MCAL/SYSTICK/STK_int.h"
#include  "LCD_prv.h"
#include  "LCD_int.h"
#include  "LCD_cfg.h"



static void HLCD_svFallingEdge(void);
extern MGPIO_Config_t LCD_DATA_PORTS[8];
extern MGPIO_Config_t LCD_CTRL_RS_PIN;
extern MGPIO_Config_t LCD_CTRL_RW_PIN;
extern MGPIO_Config_t LCD_CTRL_EN_PIN;
void HLCD_vInit(void)
{
	/*Set Your pin Direction*/
	for(int i=0 ; i<8 ;i++)
	{
		MGPIO_vInit(&LCD_DATA_PORTS[i]);
	}
	MGPIO_vInit(&LCD_CTRL_RS_PIN);
	MGPIO_vInit(&LCD_CTRL_RW_PIN);
	MGPIO_vInit(&LCD_CTRL_EN_PIN);
	/*start initialize sequence 8bit initialization */
	/*Wait  bigger than 30ms ->50ms*/
	MSTK_vSetBusyWait_us(50000);
	/*Function Set*/
	HLCD_vSendCommand(LCD_FUNCTION_SET);
	/*Wait bigger than 39us->1ms*/
	MSTK_vSetBusyWait_us(1000);
	HLCD_vSendCommand(LCD_DISPLAY_CURSOR);
	/*Wait bigger than 39us -> 1ms*/
	MSTK_vSetBusyWait_us(1000);
	/*clear the screen*/
	HLCD_vSendCommand(LCD_CLEAR_SCREEN);
	/*Wait bigger than 1.53ms*/
	MSTK_vSetBusyWait_us(3000);
	HLCD_vSendCommand(LCD_ENTRY_MODE_SET);
}
//to send command
/*the important function Send Command and Send Character*/
void HLCD_vSendCommand (u8 A_u8Cmd)
{
	/*1-Control Rs & RW Pins*/
	MGPIO_vSetPinVal(LCD_CTRL_RS_PIN.port , LCD_CTRL_RS_PIN.pin , GPIO_LOW);//enable the command
	MGPIO_vSetPinVal(LCD_CTRL_RW_PIN.port , LCD_CTRL_RW_PIN.pin ,GPIO_LOW);//Write on LCD
	/*2-Write Command on the data pins*/
	for(u8 L_u8I=0 ;  L_u8I < 8 ;L_u8I++)
	{
		MGPIO_vSetPinVal(LCD_DATA_PORTS[L_u8I].port,LCD_DATA_PORTS[L_u8I].pin,GET_BIT(A_u8Cmd,L_u8I));
	}
	//falling edge
	HLCD_svFallingEdge();
}

static void HLCD_svFallingEdge(void)
{
	/*3-Pulse on the enable pin (enable=high and delay(1msec)and low delay(1ms)) */
	//falling edge
	MGPIO_vSetPinVal(LCD_CTRL_EN_PIN.port , LCD_CTRL_EN_PIN.pin ,GPIO_HIGH);
	MSTK_vSetBusyWait_us(1000);
	MGPIO_vSetPinVal(LCD_CTRL_EN_PIN.port , LCD_CTRL_EN_PIN.pin ,GPIO_LOW);
	MSTK_vSetBusyWait_us(1000);//the delay from data sheet of LCD interface timing chart minimum 230 nsec (pulse width)

}

//// to send data
void HLCD_vSendChar(u8 A_u8Char) // A_u8Char from data sheet CGROM  HIGH LOW example '0' = 48 = 0x30 =  0b00110000
{
	/*1-Control Rs & RW Pins*/
	MGPIO_vSetPinVal(LCD_CTRL_RS_PIN.port , LCD_CTRL_RS_PIN.pin ,GPIO_HIGH);//enable the data
	MGPIO_vSetPinVal(LCD_CTRL_RW_PIN.port , LCD_CTRL_RW_PIN.pin ,GPIO_LOW);//Write on LCD
	/*2-Write Command on the data pins*/
	for(u8 L_u8I=0 ;  L_u8I < 8 ;L_u8I++)
	{
		MGPIO_vSetPinVal(LCD_DATA_PORTS[L_u8I].port,LCD_DATA_PORTS[L_u8I].pin,GET_BIT(A_u8Char,L_u8I));
	}
	HLCD_svFallingEdge();

}
/* Clear the Screen */
void HLCD_vClearCommand(void)
{
	HLCD_vSendCommand(LCD_CLEAR_SCREEN);
}
/*Send string*/
void HLCD_vPrintString (char *A_s8str)
{
	u8 L_u8i = 0;
	while(A_s8str[L_u8i] != 0)
	{
		HLCD_vSendChar(A_s8str[L_u8i]);
		L_u8i ++;
	}
}

/*print number*/
void HLCD_vPrintNumber(s32 A_s32Number)
{
	u8 L_u8arr[44] ,L_u8i = 0;
	if(A_s32Number==0)
	{
		HLCD_vSendChar('0');
	}
	else if (A_s32Number < 0)
	{
		HLCD_vSendChar('-');
		A_s32Number=A_s32Number *(-1);
	}
	while(A_s32Number !=0)
	{
		L_u8arr[L_u8i] = A_s32Number % 10 ;//0 1 2 3
		A_s32Number = A_s32Number /10 ;
		L_u8i++;
	}
	while(L_u8i!=0)
	{
		L_u8i--;// 2 1 0
		HLCD_vSendChar(L_u8arr[L_u8i] + '0'); // '0'=48
	}
}
/*GO TO ROW COLUMN*/
void HLCD_vSetCursorPostion(u8 A_u8LineNoRow , u8 A_u8LionPos)// row , column
{
	u8 L_u8addressDDR = 0;
	/* If the condition data validation  ensure that the data in your range */
	if ((A_u8LineNoRow <= MAX_IDX_OF_ROWS) && (A_u8LionPos <=MAX_IDX_OF_COL))
	{
		switch(A_u8LineNoRow)
		{
		case LCD_LINE0 :
			L_u8addressDDR = A_u8LionPos + FIRST_ROW_START_ADDRESS;
			break ;
		case LCD_LINE1 :
			L_u8addressDDR = A_u8LionPos + SECOND_ROW_START_ADDRESS;
			break ;
		case LCD_LINE2 :
			L_u8addressDDR = A_u8LionPos + THREE_ROW_START_ADDRESS;
			break ;
		case LCD_LINE3 :
			L_u8addressDDR = A_u8LionPos + FOUR_ROW_START_ADDRESS;
			break ;
		default :
			/* Do NOTHING */
			break;
		}
		L_u8addressDDR = (L_u8addressDDR | LCD_SET_DDRAM_ADDRESS);
		HLCD_vSendCommand(L_u8addressDDR);
	}

}

u8 HLC_u8WriteInCGRAM(u8 A_u8patternIdx , u8 *A_u8patternValue)
{
	u8 L_u8LoopItrator ,L_u8ErrorState = 0;
	/*Step 1: Set ADDRESS COUNTER on CGRAM from command name set CGRAM ADDRES 6bit address CGRAM*/
	if(A_u8patternIdx<8)
	{
		HLCD_vSendCommand((LCD_SET_CGRAM_ADDRESS | (A_u8patternIdx*8)));
		for (L_u8LoopItrator=0 ; L_u8LoopItrator<8;L_u8LoopItrator++)
		{
			HLCD_vSendChar(A_u8patternValue[L_u8LoopItrator]);
		}
		/*Set DDRAM Address i.e to home*/
		HLCD_vSendCommand(LCD_SET_DDRAM_ADDRESS);
	}
	else
	{
		/*patternIndx not found*/
		L_u8ErrorState = 1;
	}
	return L_u8ErrorState ;
	//	/*Step 1: Set ADDRESS COUNTER on CGRAM from command name set CGRAM ADDRES 6bit address CGRAM*/
	//	switch(A_u8patternIdx)
	//	{
	//	case 0:
	//		HLCD_vSendCommand(0x40);//LCD_SET_CGRAM_ADDRESS+0*8
	//		break;
	//	case 1:
	//		HLCD_vSendCommand(0x48);//LCD_SET_CGRAM_ADDRESS+1*8
	//		break;
	//	case 2:
	//		HLCD_vSendCommand(0x50);//LCD_SET_CGRAM_ADDRESS+2*8
	//		break;
	//	case 3:
	//		HLCD_vSendCommand(0x58);//LCD_SET_CGRAM_ADDRESS+3*8
	//		break;
	//	case 4:
	//		HLCD_vSendCommand(0x60);//LCD_SET_CGRAM_ADDRESS+4*8
	//		break;
	//	case 5:
	//		HLCD_vSendCommand(0x68);//LCD_SET_CGRAM_ADDRESS+5*8
	//		break;
	//	case 6:
	//		HLCD_vSendCommand(0x70);//LCD_SET_CGRAM_ADDRESS+6*8
	//		break;
	//	case 7:
	//		HLCD_vSendCommand(0x78);//LCD_SET_CGRAM_ADDRESS+7*8
	//		break;
	//	default :
	//		/*Report Error */
	//		L_u8ErrorState = 1 ;
	//		break;
	//	}
	//	/* Step 2: Write pattern in CGRAM */
	//	if(L_u8ErrorState !=1)
	//	{
	//		for (L_u8LoopItrator=0 ; L_u8LoopItrator<8;L_u8LoopItrator++)
	//		{
	//			HLCD_vSendChar(A_u8patternValue[L_u8LoopItrator]);
	//		}
	//		/*Set DDRAM Address i.e to home*/
	//		HLCD_vSendCommand(LCD_SET_DDRAM_ADDRESS);
	//	}

	//	return L_u8ErrorState ;
}
u8 HLCD_u8DisplayCustomChar(u8 A_u8patternIndx)
{
	u8 L_u8ErrorState = 0;
	if(A_u8patternIndx <8)
	{
		HLCD_vSendChar(A_u8patternIndx);
	}
	else
	{
		/*pattern not found*/
		L_u8ErrorState = 1;
	}
	return L_u8ErrorState;
}
