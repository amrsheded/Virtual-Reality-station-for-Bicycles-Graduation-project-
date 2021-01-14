/*
 * UART_service.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Amr sheded
 */

#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

void UART_vidSendStr(u8 *str);
void UART_vidPrintNumber(u16 number);

void SendSpeed (u8 speed);
void SendPosition(u8 position);
#endif /* UART_SERVICE_H_ */
