/*
 * Timer_Counter_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef PWM1_DRIVER_H_
#define PWM1_DRIVER_H_

#include "Datatype.h"

void PWM_Init(void);
void  PWM_SetPrescaller(u16 Prescaller);
void PWM_SetFrequency(u8 Frequency);
void PWM_SetDutyCycle(float DutyCycle);




#endif /* PWM1_DRIVER_H_ */
