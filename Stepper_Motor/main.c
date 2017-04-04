/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */


#undef F_CPU
#define F_CPU 16000000ul
#include  "Datatype.h"
#include  "DIO_Driver.h"
#include  "Stepper_Motor.h"
#include  "keypad.h"
#include  "LCD.h"
#include  <util/delay.h>


int main(void)
{
	u8 Status_Flg = 0;

	Keypad_Init();
	LCD_Init();
	StepperMotor_Init();



	LCD_WriteCommand(0x80);
	LCD_WriteString("Motor Status:");

	while(1)
	{

		if( (Keypad_ReadButton(1) == 0) )
		{
			_delay_ms(150);
			Status_Flg = 1;
			LCD_WriteCommand(0xc0);
			LCD_WriteString("Right");
		}


		else if( (Keypad_ReadButton(2) == 0) )
		{
			_delay_ms(150);
			Status_Flg = 2;
			LCD_WriteCommand(0xc0);
		}


		else if( (Keypad_ReadButton(3) == 0) )
		{
			_delay_ms(150);
			Status_Flg = 3;
			LCD_WriteCommand(0xc0);
			LCD_WriteString("Brake");
		}

		if(Status_Flg == 1)
		{
			StepperMotor_Right();
		}

		else if(Status_Flg == 2)
		{
			StepperMotor_Left();
		}

		else if(Status_Flg == 3)
		{
			StepperMotor_Brake();
		}


	}

	return 0;
}
