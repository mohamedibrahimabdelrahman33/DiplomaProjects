/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 *
/

 */

#undef  F_CPU
#define  F_CPU 16000000ul
#include  "Datatype.h"
#include  "Macros.h"
#include  "Servo_Driver.h"
#include  "ADC_Driver.h"



int main(void)
{
	ADC_Init();
	ADC_StartConversion();
	Servo_Init();

	while(1)
	{
		Servo_SetAngle(ADC_Read_10_BitMode()/5.7);
	}

	return 0;
}



