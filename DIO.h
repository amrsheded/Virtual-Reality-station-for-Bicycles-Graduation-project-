/*
 * DIO.h
 *
 *  Created on: Sep 9, 2018
 *      Author: sheded
 */

#ifndef DIO_H_
#define DIO_H_

                /*$$$$$$ define macros of ports in AVR $$$$$$ */
#define MY_PORTA  0
#define MY_PORTB  1
#define MY_PORTC  2
#define MY_PORTD  3


#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7

#define INPUT     0
#define OUTPUT    1

#define LOW       0
#define HIGH      1
                              // function to set any BIT direction inside any Register
void DIO_SetPinDirection (u8 PortNumber, u8 PinNumber, u8 Direction);
                            //function to set any BIT inside any Register with 0 or 1 volt
void DIO_SetPinValue(u8 PortNumber , u8 PinNumber, u8 PinValue);
                            //function to return any BIT value from a Register
u8 DIO_GetPinValue(u8 PortNumber,u8 PinNumber);
                             //function to set all BIT direction inside any Register
void DIO_SetPortDirection(u8 PortNumber,u8 PortDirection);
                              //set all BIT inside any Register with 0 or 1 volt
void DIO_SetPortValue(u8 PortNumber,u8 PortValue);
#endif /* DIO_H_ */

