/*
 * Led_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include "Datatype.h"
#include  "Macros.h"
#include  "DIO_Registers.h"
#include  "DIO_Driver.h"
#include  "Led_Cfg.h"


u8 static State = 0;

void Led_Init(void)
{
	DIO_SetPinDirection(LED_PORT,LED_PIN,OUTPUT);
}

void Leds_Init(void)
{
	DIO_SetPortDirection(LED_PORT,OUTPUT);
}


void Led_On(void)
{
	DIO_SetPinValue(LED_PORT,LED_PIN,HiGH);
	State = ON;
}

void Led_Off(void)
{
	DIO_SetPinValue(LED_PORT,LED_PIN,LOW);
	State = OFF;
}

void Led_Toggle(void)
{
	if (State == ON)
	{
		DIO_SetPinValue(LED_PORT,LED_PIN,LOW);
		State = OFF;
	}

	else if (State == OFF)
	{
		DIO_SetPinValue(LED_PORT,LED_PIN,HiGH);
		State = ON;
	}

}

void Leds_On(u8 Value)
{
	DIO_SetPortValue(LED_PORT,Value);
}
