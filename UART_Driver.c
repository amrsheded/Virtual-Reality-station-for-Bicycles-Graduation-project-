/*
 * UART_Driver.c
 *
 *  Created on: Oct 20, 2018
 *      Author: Amr sheded
 */
#include"STD_TYPES.h"
#include"Registers.h"

void UART_vidInit(void)                  //Function to Initilaize UART peripheral
{
	UBRRL_REG=77;
	UBRRH_REG=0;
	UCSRC_REG=0b10000110;
	UCSRB_REG=0b00011000;

}

void UART_vidSendData(u16 Data)           //Function to send data from microcontroller to any device
{
	while(((UCSRA_REG)&(1<<5))==0);
     UDR_REG=Data;
}

u8 UART_u8ReciveData(void)               //Function to Receive data to microcontroler from any device
{
u8 retval;
while(((UCSRA_REG)&(1<<7))==0);

	retval=UDR_REG;
	return retval;

}
