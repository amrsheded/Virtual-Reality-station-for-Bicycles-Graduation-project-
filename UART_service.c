/*
 * UART_service.c
 *
 *  Created on: Jun 16, 2019
 *      Author: Amr sheded
 */
#include"STD_TYPES.h"
#include"UART.h"

void UART_vidSendStr(u8 *str)
{
u8 i=0;
while(str[i]!=0)
{
	UART_vidSendData(str[i]);
	i++;
}
}


void UART_vidPrintNumber(u16 number)
{
	u8 digit;

	if(number > 1000)
	{
		digit = number / 1000;

		UART_vidSendData(digit + 48);

		number = number - digit * 1000;

		digit = number / 100;

		UART_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		UART_vidSendData(digit + 48);

		UART_vidSendData(number + 48);

	}
	else if(number >= 100)
	{
		digit = number / 100;

		UART_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		UART_vidSendData(digit + 48);

		UART_vidSendData(number + 48);
	}
	else if(number > 10)
	{
		digit = number / 10;

		number = number - digit * 10;

		UART_vidSendData(digit + 48);

		UART_vidSendData(number + 48);
	}
	else if(number > 0)
	{
		UART_vidSendData(number + 48);
	}
}

void SendSpeed(u8 speed)
{
	UART_vidSendData('s');
	UART_vidSendData(speed);
	UART_vidSendData(255);
}

void SendPosition(u8 position)
{
	UART_vidSendData('p');
	UART_vidSendData(position);
	UART_vidSendData(255);
}
