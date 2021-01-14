/*
 * VR.c
 *
 *  Created on: 26 Jun 2019
 *      Author: Sheded
 */
#include"STD_TYPES.h"
#include"DIO.h"
#include"UART.h"
#include"UART_service.h"

extern volatile u8 CurrentValue;
extern volatile u8 LastValue;
void Rotary (void)
{

	CurrentValue=DIO_GetPinValue(MY_PORTD,PIN2);
	if(CurrentValue != LastValue)
	{
		if(DIO_GetPinValue(MY_PORTA,PIN0) !=CurrentValue)
		{
			SendPosition('R');

		}else{
			SendPosition('L');
		}
	}

	LastValue=DIO_GetPinValue(MY_PORTD,PIN2);

}

