/*
 * Stepper_Motor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "Datatype.h"

void StepperMotor_Init(void);
void StepperMotor_Left(void);
void StepperMotor_Right(void);
void StepperMotor_Brake(void);
u8 StepperMotor_Status(void);


#endif /* STEPPER_MOTOR_H_ */
