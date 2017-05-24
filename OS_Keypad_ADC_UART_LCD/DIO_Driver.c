/*
 * DIO_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */


#include  "Macro.h"
#include  "Datatype.h"
#include  "DIO_Registers.h"


#define Input      					 0
#define Output  					 1
#define High 							 1
#define Low  							 0
#define  Register_Size   	 8




void DIO_SetPinDirection( u8 Port_Number, u8 Pin_Number, u8 Direction)
{
	volatile  u8  *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};

	if(Port_Number <= 3)
	{
		if(Direction == Input)
		{
			CLEAR_BIT(*arr[Port_Number],Pin_Number);
		}

		else if(Direction == Output)
		{
			SET_BIT(*arr[Port_Number],Pin_Number);
		}

	}


	else
	{
		//*Do Nothing*//
	}

}




void DIO_SetPinValue( u8 Port_Number, u8 Pin_Number, u8 Value)
{
	volatile u8 *arr[4]= { &PORTA, &PORTB, &PORTC, &PORTD };

	if(Port_Number <= 3)
	{
		if(Value == Low)
		{
			CLEAR_BIT(*arr[Port_Number],Pin_Number);
		}

		else if(Value == High)
		{
			SET_BIT(*arr[Port_Number],Pin_Number);
		}

	}


	else
	{
		//*Do Nothing*//
	}

}




u8  DIO_GetPinValue( u8 Port_Number, u8 Pin_Number)
{
	u8 Return_Value;
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND };

	if(Port_Number <= 3)
	{
		Return_Value = GET_BIT(*arr[Port_Number], Pin_Number);
	}

	else
	{
		//*Do Nothing*//
	}

	return Return_Value ;

}




void DIO_SetPortDirection( u8 Port_Number,  u8 Direction)
{
	volatile u8 *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};

	if(Port_Number <= 3)
	{
		if(Direction == Input)
		{
			*arr[Port_Number] = 0x00;
		}

		else if(Direction == Output)
		{
			*arr[Port_Number] = 0xff;
		}

	}


	else
	{
		//*Do Nothing*//
	}

}




void DIO_SetPortValue( u8 Port_Number, u8 Value)
{
	volatile u8 *arr[4]= { &PORTA, &PORTB, &PORTC, &PORTD };

	if(Port_Number <= 3)
	{
		*arr[Port_Number] = Value;
	}


	else
	{
		//*Do Nothing*//
	}

}





u8  DIO_GetPortValue( u8 Port_Number)
{
	u8 Return_Value;
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND };

	if(Port_Number <= 3)
	{
		Return_Value =  *arr[Port_Number];
	}

	else
	{
		//*Do Nothing*//
	}

	return Return_Value;
}




void DIO_SetPinsDirection( u8 Pin_Number, u8 Direction)
{
	u8 Port_Number = 0;
	volatile u8 *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};

	Port_Number = ( Pin_Number / Register_Size) ;
	Pin_Number   = (Pin_Number %  Register_Size) ;

	if(Port_Number <= 3)
	{
		if(Direction == Input)
		{
			CLEAR_BIT(*arr[Port_Number],Pin_Number);
		}

		else if(Direction == Output)
		{
			SET_BIT(*arr[Port_Number],Pin_Number);
		}

	}


	else
	{
		//*Do Nothing*//
	}

}




void DIO_SetPinsValue( u8 Pin_Number, u8 Value)
{
	u8 Port_Number = 0;
	volatile u8 *arr[4]= { &PORTA, &PORTB, &PORTC, &PORTD };


	Port_Number = ( Pin_Number / Register_Size) ;
	Pin_Number   = (Pin_Number %  Register_Size) ;


	if(Port_Number <= 3)
	{
		if(Value == Low)
		{
			CLEAR_BIT(*arr[Port_Number],Pin_Number);
		}


		else if(Value == High)
		{
			SET_BIT(*arr[Port_Number],Pin_Number);
		}

	}


	else
	{
		//*Do Nothing*//
	}

}







u8  DIO_GetPinsValue( u8 Pin_Number)
{
	u8 Return_Value;
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND };
	u8 Port_Number = 0;


	Port_Number = ( Pin_Number / Register_Size) ;
	Pin_Number   = (Pin_Number %  Register_Size) ;


	if(Port_Number <= 3)
	{
		Return_Value = GET_BIT(*arr[Port_Number], Pin_Number);
	}

	else
	{
		//*Do Nothing*//
	}

	return Return_Value ;
}







void DIO_EnablePullupResistance( u8 Pin_Number)
{
	u8 Port_Number = 0;
	volatile u8 *arr[4]= { &PORTA, &PORTB, &PORTC, &PORTD };


	Port_Number = ( Pin_Number / Register_Size) ;
	Pin_Number   = (Pin_Number %  Register_Size) ;


	if(Port_Number <= 3)
	{
		SET_BIT(*arr[Port_Number],Pin_Number);
	}


	else
	{

	}

}
