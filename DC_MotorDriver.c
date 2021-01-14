/*
 * DC_MotorDriver.c
 *
 *  Created on: May 6, 2019
 *      Author: sheded
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "Registers.h"
void pwm()
{
	       //////******************** TIMER 0 ********************//////
	SET_BIT(TCCR0_REG,PIN0);   //set clock select prescaler (no prescaling)
	CLR_BIT(TCCR0_REG,PIN1);
	CLR_BIT(TCCR0_REG,PIN2);
	CLR_BIT(TCCR0_REG,PIN3);   //phase correct pwm
	SET_BIT(TCCR0_REG,PIN6);
	SET_BIT(TCCR0_REG,PIN4);  //Set OC0 on compare match when up-counting
	SET_BIT(TCCR0_REG,PIN5);  // Clear OC0 on compare	match when downcounting

	      //////******************** TIMER 2 ********************//////
	SET_BIT(TCCR2_REG,PIN0);   //set clock select prescaler (no prescaling)
	CLR_BIT(TCCR2_REG,PIN1);
    CLR_BIT(TCCR2_REG,PIN2);
    CLR_BIT(TCCR2_REG,PIN3);   //phase correct pwm
	SET_BIT(TCCR2_REG,PIN4);   //Set OC0 on compare match when up-counting
	SET_BIT(TCCR2_REG,PIN5);   // Clear OC0 on compare	match when downcounting
    SET_BIT(TCCR2_REG,PIN6);	//phase correct pwm

}

void MotorStatus(u8 direction,u8 status)
{
	if(direction=='R')
	{
		DIO_SetPinValue(MY_PORTB,PIN0,status);
	}else if(direction=='L')
	{
		DIO_SetPinValue(MY_PORTB,PIN1,status);
	}
}
void RunMotor(u8 direction,u8 pwm)
{
	if(direction=='R')
	{
		OCR0_REG=pwm;
	}else if(direction=='L')
	{
		OCR2_REG=pwm;
	}
}
void ControlMotorDirection(u8 direction,u8 status)
{
	if(direction=='R')
	{
		DIO_SetPinDirection(MY_PORTB,PIN3,status);
	}else if(direction=='L')
	{
		DIO_SetPinDirection(MY_PORTD,PIN7,status);
	}
}

