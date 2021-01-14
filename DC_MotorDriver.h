/*
 * DC_MotorDriver.h
 *
 *  Created on: May 6, 2019
 *      Author: sheded
 *
 */

#ifndef DC_MOTORDRIVER_H_
#define DC_MOTORDRIVER_H_

void pwm(void);
void MotorStatus(u8 direction,u8 status);
void RunMotor(u8 direction,u8 pwm);
void ControlMotorDirection(u8 direction,u8 status);


#endif /* DC_MOTORDRIVER_H_ */
