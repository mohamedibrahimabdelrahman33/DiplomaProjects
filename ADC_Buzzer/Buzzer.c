/*
 * Buzzer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */


#undef F_CPU
#define F_CPU 16000000ul
#include "DIO_Driver.h"
#include "Datatype.h"
#include "Macros.h"
#include "util/delay.h"
#include "Buzzer_cfg.h"



void Buzzer_Init(void)
{
	DIO_SetPinsDirection(Buzzer_Pin,Output);
}




void Buzzer_Active(u16 Time)
{
	DIO_SetPinsValue(Buzzer_Pin,High);
	_delay_us(Time);
	DIO_SetPinsValue(Buzzer_Pin,Low);
	_delay_us(Time);

}
