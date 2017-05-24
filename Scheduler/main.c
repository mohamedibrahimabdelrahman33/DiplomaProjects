/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#undef  F_CPU
#define  F_CPU 16000000ul
#include  "Datatype.h"
#include  "Macros.h"
#include  "DIO_Registers.h"
#include  "DIO_Driver.h"
#include  "LCD.h"
#include "UART_Driver.h"
#include  "ADC_Driver.h"
#include  "Timer0_Driver.h"
#include  "avr/interrupt.h"


u8 static volatile Flg1 = 0,Flg2 = 0,Flg3 = 0,x=0;


int main(void)
{

	DIO_SetPinDirection(3,7,0);
	DIO_EnablePullupResistance(31);

	LCD_Init();
	ADC_Init();
	UART_Init();
	UART_BaudRate(9600);
	Timer0_Init();
	Timer0_CtcCompValue(63);


	while(1)
	{
		if(Flg1 == 1)
		{
			LCD_WriteCommand(0x80);
			LCD_WriteData('A' + x );
			Flg1 = 0;
		}

		if(Flg2 == 1)
		{
			if(DIO_GetPinValue(3,7) == 0 )
			{
				x++;
				Flg2 = 0;
			}
		}

		if(Flg3 == 1)
		{
			ADC_StartConversion();
			while((ADC_GetFlag()) == 0);
			UART_DataTransmit( ADC_Read_10_BitMode() );
			Flg3 = 0;
		}

	}

	return 0;
}



ISR( TIMER0_COMP_vect)
{
	u8 static Counter0 = 0 ,Counter1 = 0,Counter2 = 0;
	Counter0++;
	Counter1++;
	Counter2++;

	if(Counter0  == 20 )
	{
		Flg1 = 1;
	}

	if(Counter1  == 200 )
	{
		Flg2 = 1;
	}

	if(Counter0  == 100 )
	{
		Flg3 = 1;
	}

}


