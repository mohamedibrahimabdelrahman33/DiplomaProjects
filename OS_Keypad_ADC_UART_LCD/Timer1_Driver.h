/*
 * Timer_Counter_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef TIMER1_DRIVER_H_
#define TIMER1_DRIVER_H_

#include "Datatype.h"

void Timer1_Init(void);
void Timer1_Preload(u16 Value);
void Timer1_CtcCompValue(u16 Value);
u8 Get_IntFlag(void);
void Clear_IntFlag(void);



#endif /* TIMER1_DRIVER_H_ */
