/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "Macros.h"
#include  "ADC_Registers.h"
#include  "DIO_Registers.h"
#include  "Interrupt_Registers.h"
#include  "DIO_Driver.h"
#include  "ADC_Driver.h"
#include  "avr/interrupt.h"



u16 static Current_Value = 0;

int main(void)
{
	ADC_Init();
	Leds_Init();
	ADC_AutoTriggerSource();
	ADC_StartConversion();


	while(1)
	{
		switch((Current_Value % 146) )
		{
		case 7:
			Leds_On(0x01);
			break;
		case 6:
			Leds_On(0x03);
			break;
		case 5:
			Leds_On(0x07);
			break;
		case 4:
			Leds_On(0x0f);
			break;
		case 3:
			Leds_On(0x1f);
			break;
		case 2:
			Leds_On(0x3f);
			break;
		case 1:
			Leds_On(0x7f);
			break;
		default:
			//*Do Nothing*//
			break;
		}

	}


	return 0;
}


ISR( ADC_vect)
{
	Current_Value = ADC_Read_10_BitMode();
}
