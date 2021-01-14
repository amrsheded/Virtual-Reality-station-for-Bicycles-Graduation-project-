/*
 * DIO.c
 *
 *  Created on: Sep 9, 2018
 *      Author: sheded
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Registers.h"
#include "DIO.h"
                                        //set any BIT direction inside any Register
void DIO_SetPinDirection(u8 PortNumber, u8 PinNumber, u8 Direction)
{
	if(PortNumber==MY_PORTA)                                                      //DDRA Register
	{
		switch(Direction)
		{
		case INPUT: CLR_BIT(DDRA_REG,PinNumber); break;
		case OUTPUT:SET_BIT(DDRA_REG,PinNumber); break;
		}

	}
	else if(PortNumber==MY_PORTB)                                                 //DDRB Register
	{
		switch(Direction)
		{
		case INPUT: CLR_BIT(DDRB_REG,PinNumber); break;
		case OUTPUT:SET_BIT(DDRB_REG,PinNumber); break;
		}

	}
	else if(PortNumber==MY_PORTC)                                                  //DDRC Register
	{
		switch(Direction)
		{
		case INPUT: CLR_BIT(DDRC_REG,PinNumber); break;
		case OUTPUT:SET_BIT(DDRC_REG,PinNumber); break;
		}

	}
	else if(PortNumber==MY_PORTD)                                                   //DDRD  Register
	{
		switch(Direction)
		{
		case INPUT: CLR_BIT(DDRD_REG,PinNumber); break;
		case OUTPUT:SET_BIT(DDRD_REG,PinNumber); break;
		}

	}

}

                                           //set BIT inside any Register with 0 or 1 volt
void DIO_SetPinValue(u8 PortNumber,u8 PinNumber,u8 PinValue)
{
	if(PortNumber==MY_PORTA)                                                         //PORTA Register
		{
			switch(PinValue)
			{
			case LOW: CLR_BIT(PORTA_REG,PinNumber); break;
			case HIGH:SET_BIT(PORTA_REG,PinNumber); break;
			}

		}
		else if(PortNumber==MY_PORTB)                                                 //PORTB Register
		{
			switch(PinValue)
			{
			case LOW: CLR_BIT(PORTB_REG,PinNumber); break;
			case HIGH:SET_BIT(PORTB_REG,PinNumber); break;
			}

		}
		else if(PortNumber==MY_PORTC)                                                 //PORTC Register
		{
			switch(PinValue)
			{
			case LOW: CLR_BIT(PORTC_REG,PinNumber); break;
			case HIGH:SET_BIT(PORTC_REG,PinNumber); break;
			}

		}
		else if(PortNumber==MY_PORTD)                                                 //PORTD Register
		{
			switch(PinValue)
			{
			case LOW: CLR_BIT(PORTD_REG,PinNumber); break;
			case HIGH:SET_BIT(PORTD_REG,PinNumber); break;
			}

		}
}
                                                //Get BIT value from a Register
u8 DIO_GetPinValue(u8 PortNumber,u8 PinNumber)
{
	u8 retresult;
	switch(PortNumber)
	{
	case MY_PORTA: retresult=GET_BIT(PINA_REG,PinNumber); break;
	case MY_PORTB: retresult=GET_BIT(PINB_REG,PinNumber); break;
	case MY_PORTC: retresult=GET_BIT(PINC_REG,PinNumber); break;
	case MY_PORTD: retresult=GET_BIT(PIND_REG,PinNumber); break;
	}
return retresult ;
}
                                               //set all BIT direction inside any Register
void DIO_SetPortDirection(u8 PortNumber,u8 PortDirection)
{
	if(PortDirection==INPUT)
	{
		switch(PortNumber)
		{
		case MY_PORTA:  DDRA_REG=0x00;  break;
		case MY_PORTB:  DDRB_REG=0x00;  break;
		case MY_PORTC:  DDRC_REG=0x00;  break;
		case MY_PORTD:  DDRD_REG=0x00;  break;
		}
	}
	else if(PortDirection==OUTPUT)
	{
		switch(PortNumber)
		{
		case MY_PORTA:  DDRA_REG=0xff;  break;
		case MY_PORTB:  DDRB_REG=0xff;  break;
		case MY_PORTC:  DDRC_REG=0xff;  break;
		case MY_PORTD:  DDRD_REG=0xff;  break;
		}
	}
}
                                             //set all BIT inside any Register with 0 or 1 volt
void DIO_SetPortValue (u8 PortNumber, u8 PortValue)
{
			switch(PortNumber)
			{
			case MY_PORTA: PORTA_REG=PortValue;  break;
			case MY_PORTB: PORTB_REG=PortValue;  break;
			case MY_PORTC: PORTC_REG=PortValue;  break;
			case MY_PORTD: PORTD_REG=PortValue;  break;
			}
}
