/*
 * main.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Sheded
 */
#define F_CPU 12000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Registers.h"
#include "DIO.h"
#include "UART.h"
#include "UART_service.h"
#include "EXT_INT.h"
#include "avr/interrupt.h"
#include "DC_MotorDriver.h"
#include "VR.h"
#include "util/delay.h"
                                     //Rotary encoder variables
volatile u8 LastValue;
volatile u8 CurrentValue;
                                     //optical encoder variables
volatile u16 count=0;
volatile f32 Rotation=0;
                                     //motor encoder variables
volatile u8 check;

volatile u16 pulse;                 //for Motor Encoder

int main(void)
{
	pwm();                           //Initialization for timer peripheral
	UART_vidInit();                 //Initialization for UART peripheral
	EXT_INT(0,Logical_change);      // EXT interrupt for rotary encoder at logical change event
	SET_BIT(SREG_REG,7);            //global interrupt

                                                             //MOTOR PINS
	DIO_SetPinDirection(MY_PORTB,PIN0,OUTPUT);              //E_Right
	DIO_SetPinDirection(MY_PORTB,PIN1,OUTPUT);             //E_left

	                               //L298 Driver
	DIO_SetPinDirection(MY_PORTA,PIN6,OUTPUT);
	DIO_SetPinDirection(MY_PORTA,PIN7,OUTPUT);

	DIO_SetPinDirection(MY_PORTB,PIN2,INPUT);              //MOTOR interrupt
	DIO_SetPinValue(MY_PORTB,PIN2,OUTPUT);

	EXT_INT(2,Rising);                         //EXT interrupt for motor encoder at Rising edge event
                                     //Rotary encoder PINS
	DIO_SetPinDirection(MY_PORTA,PIN0,INPUT);          //CLK
	DIO_SetPinDirection(MY_PORTD,PIN2,INPUT);          //DATA
                                     //UART PINS
	DIO_SetPinDirection(MY_PORTD,PIN0,INPUT);          //RX
	DIO_SetPinDirection(MY_PORTD,PIN1,OUTPUT);         //TX
                                     //Optical encoder
	DIO_SetPinDirection(MY_PORTD,PIN3,INPUT);      //set pin input for External event
	DIO_SetPinValue(MY_PORTD,PIN3,OUTPUT);

	EXT_INT(1,Rising);                    //EXT interrupt for Optical encoder at Rising edge event

	DIO_SetPinDirection(MY_PORTB,PIN7,INPUT);	       //limit switch
	DIO_SetPinValue(MY_PORTB,PIN7,HIGH);

	                                    //Initialization for timer 1
	TCCR1A_REG=0x00;                              //CTC mode
	SET_BIT(TCCR1B_REG,3);
	                                              //clock select
	CLR_BIT(TCCR1B_REG,0);
	CLR_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);

	OCR1A_REG=46750;                          //output compare match for 1sec

	SET_BIT(TIMSK_REG,4);                    //Output Compare A Match Interrupt Enable


	LastValue=DIO_GetPinValue(MY_PORTD,PIN2);

	 MotorStatus('R',HIGH);
	 MotorStatus('L',HIGH);

	 while((DIO_GetPinValue(MY_PORTB,PIN7)==1))
	 {
	        ControlMotorDirection('R',OUTPUT);
	        RunMotor('R',100);
	 }
	 	pulse=0;
	 	ControlMotorDirection('R',OUTPUT);
	    RunMotor('R',255);

	 while(pulse<=5000)
	 {
	 	 ControlMotorDirection('L',OUTPUT);
	 	 RunMotor('L',100);
	 }
	 	 pulse=0;
	 	 ControlMotorDirection('L',OUTPUT);
	 	 RunMotor('L',255);

while(1)
{
	    MotorStatus('R',HIGH);
        MotorStatus('L',HIGH);

		check=UART_u8ReciveData();

         if(check=='1')
          {
				 while(pulse<=7000)
				 {
				     ControlMotorDirection('L',OUTPUT);
				     RunMotor('L',0);
				 }
			    	 ControlMotorDirection('L',OUTPUT);
					 RunMotor('L',255);
					 pulse=0;

					 ControlMotorDirection('R',INPUT);

					 MotorStatus('R',LOW);
					 MotorStatus('L',LOW);
					 /*****************L298 Driver**********************/
				 DIO_SetPinValue(MY_PORTA,PIN6,HIGH);
				 OCR0_REG=50;
			     _delay_ms(500);
			     DIO_SetPinValue(MY_PORTA,PIN6,LOW);
	 	 }

		if(check=='2')
		{
			ControlMotorDirection('R',OUTPUT);
				while((pulse<=9000)&&(DIO_GetPinValue(MY_PORTB,PIN7)==1))
				{
			        ControlMotorDirection('R',OUTPUT);
				    RunMotor('R',55);
				}
					 ControlMotorDirection('R',OUTPUT);
					 RunMotor('R',255);
					 pulse=0;

					 ControlMotorDirection('L',INPUT);

					 MotorStatus('R',LOW);
					 MotorStatus('L',LOW);
			/*****************L298 Driver**********************/
					 DIO_SetPinValue(MY_PORTA,PIN7,HIGH);
					 OCR0_REG=50;
					 _delay_ms(500);
					 DIO_SetPinValue(MY_PORTA,PIN7,LOW);

					 ControlMotorDirection('R',INPUT);
					 RunMotor('R',255);
		}

}
return 0;
}

ISR(INT0_vect)
{
     Rotary();

}

ISR(INT1_vect)
{
    count++;                                        //one pulse per revolute

    CLR_BIT(TCCR1B_REG,0);                          //start timer1
    CLR_BIT(TCCR1B_REG,1);
    SET_BIT(TCCR1B_REG,2);

}

ISR(TIMER1_COMPA_vect)
{
   SendSpeed(count/100);                         //Update speed every 1sec
}
ISR(INT2_vect)
{
    pulse++;

}
