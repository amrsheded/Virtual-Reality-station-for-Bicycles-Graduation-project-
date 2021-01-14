/*
 * Registers.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Amr sheded
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

//PORTA Register
#define PORTA_REG                   *((volatile u8* const)0x3B)
#define DDRA_REG                    *((volatile u8* const)0x3A)
#define PINA_REG                    *((volatile u8* const)0x39)
//PORTB Register
#define PORTB_REG                   *((volatile u8* const)0x38)
#define DDRB_REG                    *((volatile u8* const)0x37)
#define PINB_REG                    *((volatile u8* const)0x36)
//PORTC Register
#define PORTC_REG                   *((volatile u8* const)0x35)
#define DDRC_REG                    *((volatile u8* const)0x34)
#define PINC_REG                    *((volatile u8* const)0x33)
//PORTD Register
#define PORTD_REG                   *((volatile u8* const)0x32)
#define DDRD_REG                    *((volatile u8* const)0x31)
#define PIND_REG                    *((volatile u8* const)0x30)
//SREG Register
#define SREG_REG                    *((volatile u8* const)0x5F)
//EXT Interrupt
#define GIFR_REG                    *((volatile u8* const)0x5A)
#define GICR_REG                    *((volatile u8* const)0x5B)
#define MCUCR_REG                   *((volatile u8* const)0x55)
#define MCUCSR_REG                  *((volatile u8* const)0x54)
//Timer Registers
#define TCCR0_REG	                *((volatile u8* const)0x53)
#define TCNT0_REG	                *((volatile u8* const)0x52)
#define OCR0_REG	                *((volatile u8* const)0x5C)
#define TIMSK_REG	                *((volatile u8* const)0x59)
#define TCCR1A_REG	                *((volatile u8* const)0x4F)
#define TCCR1B_REG	                *((volatile u8* const)0x4E)
#define ICR1_REG                    ICR1
#define TCCR2_REG                   *((volatile u8* const)0x45)
#define TCNT2_REG                   *((volatile u8* const)0x44)
#define OCR2_REG	                *((volatile u8* const)0x43)
#define OCR1AL_REG                  *((volatile u8* const)0x4A)
#define OCR1AH_REG                  *((volatile u8* const)0x4B)
#define TCNT1L_REG                  *((volatile u8* const)0x4C)
#define TCNT1H_REG                  *((volatile u8* const)0x4D)
#define OCR1A_REG                    OCR1A
#define OCR1BH_REG                  *((volatile u8* const)0x49)
#define OCR1BL_REG                  *((volatile u8* const)0x48)
#define OCR1B_REG                    OCR1B
#define TIFR_REG                    *((volatile u8* const)0x58)


//UART Register
#define UCSRA_REG                   (*(volatile u8* const)0x2B)
#define UCSRB_REG                   (*(volatile u8* const)0x2A)
#define UBRRL_REG                   (*(volatile u8* const)0x29)
#define UBRRH_REG                   (*(volatile u8* const)0x40)
#define UCSRC_REG                   (*(volatile u8* const)0x40)
#define UDR_REG                     (*(volatile u8* const)0x2C)

#endif /* REGISTERS_H_ */

