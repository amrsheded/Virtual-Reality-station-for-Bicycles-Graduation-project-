/*
 * UART.h
 *
 *  Created on: Oct 20, 2018
 *      Author: Amr sheded
 */

#ifndef UART_H_
#define UART_H_

void UART_vidInit(void);               //Function to Initilaize UART peripheral
void UART_vidSendData(u16 Data);       //Function to send data from microcontroller to any device
u8 UART_u8ReciveData(void);            //Function to Receive data to microcontroler from any device


#endif /* UART_H_ */
