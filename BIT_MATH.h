/*
 * BIT_MATH.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Amr sheded
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO)   VAR|=(1<<(BIT_NO))          //Set any bit in register
#define TOG_BIT(VAR,BIT_NO)   VAR^=(1<<(BIT_NO))          //toggle any bit in register
#define CLR_BIT(VAR,BIT_NO)   VAR&=~(1<<(BIT_NO))         //clear any bit in register
#define GET_BIT(VAR,BIT_NO)   (((VAR)>>(BIT_NO)) & 0x01)  //get any bit in register

#endif /* BIT_MATH_H_ */
