/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */


#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "DIO_Driver.h"
#include  "DIO_Regisers.h"
#include  "Interrupt_Registers.h"
#include  "Macro.h"
#include  "avr/interrupt.h"
#include  "LCD.h"

static u8 number_flg = '0';

int main(void)
{
SET_BIT(PORTD,2);

	LCD_Init();

	MCUCR = 0x02;
	GICR = 0x40;
	SREG = 0x80;

	LCD_WriteCommand(0x80);
	LCD_WriteString("Current Number:");

	while(1)
	{
		LCD_WriteCommand(0xc0);
		LCD_WriteDigits(2,number_flg);
	}

	return 0;
}


ISR( INT0_vect )
{
	number_flg += 1;
}
