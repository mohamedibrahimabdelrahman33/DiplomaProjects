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
#include  "LCD.h"
#include  "ADC_Driver.h"
#include "Buzzer.h"
#include  "avr/interrupt.h"




u8 static State_Flg = 0;
u16 static Current_Value = 0;


int main(void)
{
	DIO_EnablePullupResistance(26);
	DIO_EnablePullupResistance(27);
	ADC_Init();
	LCD_Init();
	Buzzer_Init();

	MCUCR = 0x0a;
	GICR = 0xc0;
	SREG = 0x80;

	LCD_WriteCommand(0x80);
	LCD_WriteString("Buzzer State: ");
	LCD_WriteCommand(0xc0);
	LCD_WriteString("Value= (0000) ");



	ADC_AutoTriggerSource();
	ADC_StartConversion();

	while(1)
	{


		if(State_Flg == 0)
		{
			LCD_WriteCommand(0xc8);

			LCD_WriteDigits(4,Current_Value);
		}

		else
		{
			Buzzer_Active(Current_Value);
		}


	}

	return 0;
}


ISR( INT0_vect )
{
	State_Flg = ~State_Flg;
}


ISR( ADC_vect)
{
	Current_Value = ADC_Read_10_BitMode();
}
