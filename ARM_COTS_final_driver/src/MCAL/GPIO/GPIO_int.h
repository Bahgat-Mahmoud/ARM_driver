/*
 * GPIO_int.h
 *
 *  Created on: Aug 22, 2022
 *      Author: DELL
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_
typedef struct{
	u8 mode ;
	u8 port ;
	u8 pin;
	u8 speed;
    u8 out_type;
    u8 input_pull ;
	u8 alt_func;
}MGPIO_Config_t;
typedef enum{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
}PinNo;

#define 	GPIO_PORTA       'A'
#define 	GPIO_PORTB       'B'
#define 	GPIO_PORTC       'C'

//00: Input (reset state)
//01: General purpose output mode
//10: Alternate function mode
//11: Analog mode
typedef enum{             //from data sheet
	GPIO_MODE_INPUT,      //  0b00
	GPIO_MODE_OUTPUT,     //  0b01
	GPIO_MODE_ALTFUNC,    //  0b10
	GPIO_MODE_ANALOG      //  0b11
}GPIO_MODE;


/*out_type*/
#define GPIO_OPEN_DRAIN          1
#define GPIO_PUSH_PULL           0

/*to choose the speed */
#define GPIO_OUTSPEED_LOW        0b00
#define GPIO_OUTSPEED_MEDIUM     0b01
#define GPIO_OUTSPEED_HIGH       0b10
#define GPIO_OUTSPEED_VERYHIGH   0b11
/*Pin val*/
#define GPIO_HIGH                 1
#define GPIO_LOW                  0
/*input type*/
#define  GPIO_NO_PULL_UP_OR_DOWN  0b00
#define  GPIO_PULL_UP             0b01
#define  GPIO_PULL_DOWN           0b10


/*my func*/
/*init func*/
void MGPIO_vInit(MGPIO_Config_t* A_xconfig);
/*Pin mode*/
void MGPIO_vSetPinOutput(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8OutSpeed ,u8 A_u8OutType);
void MGPIO_vSetPinInput(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8PupDr);
void MGPIO_vSetPinAltFunc(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8AltFunc);
void MGPIO_vSetPinAnalog(u8 A_u8PortId ,PinNo A_PinNo);
void MGPIO_vLockPin(u8 A_u8PortId ,PinNo A_PinNo);
/*pin val*/
void MGPIO_vSetPinVal_Fast(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8Val);
void MGPIO_vSetPinVal(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8Val);
void MGPIO_vTogglePin(u8 A_u8PortId ,PinNo A_PinNo);
/*port val*/
void MGPIO_vSetPortVal(u8 A_u8PortId ,u16 A_u16Val);
/*Read pin*/
u8 MGPIO_u8GetPinVal(u8 A_u8PortId ,PinNo A_PinNo);
/*Get port*/
u16 MGPIO_u16GetPortVal(u8 A_u8PortId);
/*extra func */
void MGPIO_vSetPinOutPart(u8 A_u8PortId ,PinNo A_FirstPinNo,PinNo A_LastPinNo,u8 A_u8OutSpeed ,u8 A_u8OutType);
void MGPIO_vSetOnSomePinVal (u8 A_u8PortId , PinNo A_xFirstPinNo ,PinNo A_xLastPinNo , u16 A_u16Val);



/*in sec*/
void MGPIO_vSetPinMode(u8 A_u8PortId ,PinNo A_PinNo,GPIO_MODE A_u8Mode);
void MGPIO_vSetPinOutputType (u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8OutType);
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId ,PinNo A_PinNo,u8 A_u8OutSpeed);

#endif /* MCAL_GPIO_GPIO_INT_H_ */
