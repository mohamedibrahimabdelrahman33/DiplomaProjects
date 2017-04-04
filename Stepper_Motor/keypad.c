/*
 * keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include "DIO_Driver.h"
#include "Macros.h"
#include "Datatype.h"
#include "keypad_cfg.h"


#define Output  1
#define Input  0
#define High 1
#define Low 0





void Keypad_Init(void)
{
	u8 arr[8]= {R0,R1,R2,R3,C0,C1,C2,C3};
	u8 i = 0;

	for(i=0;i<4;i++)
	{
		DIO_SetPinsDirection(arr[i], Output );
	}

	for(i=4;i<8;i++)
	{
		DIO_SetPinsDirection(arr[i], Input);
	}


	DIO_EnablePullupResistance( C0 );
	DIO_EnablePullupResistance( C1 );
	DIO_EnablePullupResistance( C2 );
	DIO_EnablePullupResistance( C3 );

}




u8 Keypad_ReadButton(u8 Button_Number)
{
	u8 Return_Input =  0 ;
	u8 Row_Number = 0;

	Button_Number -= 1;

	Row_Number = ( Button_Number  / 4) ;
	Button_Number =  ( Button_Number  % 4) ;


	switch( Row_Number )
	{
	case 0:
		DIO_SetPinsValue(R0,Low);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,High);
		break;

	case 1:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,Low);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,High);
		break;

	case 2:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,Low);
		DIO_SetPinsValue(R3,High);
		break;

	case 3:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,Low);
		break;

	default :
		break;
	}



	switch( Button_Number)
	{
	case 0:
		Return_Input  =  DIO_GetPinsValue( C0 );
		break;

	case 1:
		Return_Input  = DIO_GetPinsValue( C1 );
		break;

	case 2:
		Return_Input = DIO_GetPinsValue( C2 );
		break;

	case 3:
		Return_Input = DIO_GetPinsValue( C3 );
		break;

	default :
		break;
	}


	return Return_Input;
}




struct keypad Keypad_Scan(void)
{
	struct keypad Mykeypad;

	DIO_SetPinsValue(R0,High);
	DIO_SetPinsValue(R1,High);
	DIO_SetPinsValue(R2,High);
	DIO_SetPinsValue(R3,High);


	DIO_SetPinsValue(R0,Low);
	Mykeypad.button1   = DIO_GetPinsValue( C0 );
	Mykeypad.button2   = DIO_GetPinsValue( C1 );
	Mykeypad.button3   = DIO_GetPinsValue( C2 );
	Mykeypad.button4   = DIO_GetPinsValue( C3 );
	DIO_SetPinsValue(R0,High);


	DIO_SetPinsValue(R1,Low);
	Mykeypad.button5   = DIO_GetPinsValue( C0 );
	Mykeypad.button6   = DIO_GetPinsValue( C1 );
	Mykeypad.button7   = DIO_GetPinsValue( C2 );
	Mykeypad.button8   = DIO_GetPinsValue( C3 );
	DIO_SetPinsValue(R1,High);


	DIO_SetPinsValue(R2,Low);
	Mykeypad.button9   = DIO_GetPinsValue( C0 );
	Mykeypad.button10   = DIO_GetPinsValue( C1 );
	Mykeypad.button11   = DIO_GetPinsValue( C2 );
	Mykeypad.button12   = DIO_GetPinsValue( C3 );
	DIO_SetPinsValue(R2,High);


	DIO_SetPinsValue(R3,Low);
	Mykeypad.button13   = DIO_GetPinsValue( C0 );
	Mykeypad.button14   = DIO_GetPinsValue( C1 );
	Mykeypad.button15   = DIO_GetPinsValue( C2 );
	Mykeypad.button16   = DIO_GetPinsValue( C3 );
	DIO_SetPinsValue(R3,High);





	return Mykeypad;


}
