/*
 * EXT_INT.h
 *
 *  Created on: Mar 18, 2019
 *      Author: sheded
 */
#ifndef EXT_INT_H_
#define EXT_INT_H_

#define Rising           1             //EVENT for Raising edge
#define Falling          2             //EVENT for Faling edge
#define Logical_change   3             //EVENT for Logical change
#define Low_level        4             //EVENT for LOW Level


void EXT_INT(u8 INT_number,u8 INT_sense ); //Function for Initialize interrupt peripheral
u8 Check_flag(u8 INT_number);             //Funtion for check flag if interrupt is executed

#endif /* EXT_INT_H_ */
