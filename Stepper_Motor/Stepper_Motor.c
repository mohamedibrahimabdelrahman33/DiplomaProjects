/*
 * Stepper_Motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */
#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "DIO_Driver.h"
#include <util/delay.h>
#include "Stepper_Motor_Cfg.h"

static u8 Status = 0;

void StepperMotor_Init(void)
{
	DIO_SetPinsDirection(StepperMotor_PinA,1);
	DIO_SetPinsDirection(StepperMotor_PinB,1);
	DIO_SetPinsDirection(StepperMotor_PinC,1);
	DIO_SetPinsDirection(StepperMotor_PinD,1);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
}


void StepperMotor_Left(void)
{
	Status = Left;

	DIO_SetPinsValue(StepperMotor_PinA,1);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,1);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,1);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,1);
	_delay_ms(3);
}


void StepperMotor_Right(void)
{
	Status = Right;

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,1);
	_delay_ms(3);

	_delay_ms(3);
	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,1);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,1);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,1);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,1);
	DIO_SetPinsValue(StepperMotor_PinB,1);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);

	DIO_SetPinsValue(StepperMotor_PinA,1);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
	_delay_ms(3);


}



void StepperMotor_Brake(void)
{
	Status = Brake;

	DIO_SetPinsValue(StepperMotor_PinA,0);
	DIO_SetPinsValue(StepperMotor_PinB,0);
	DIO_SetPinsValue(StepperMotor_PinC,0);
	DIO_SetPinsValue(StepperMotor_PinD,0);
}

u8 StepperMotor_Status(void)
{
	return Status;
}
