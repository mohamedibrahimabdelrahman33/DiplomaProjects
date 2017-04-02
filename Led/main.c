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
#include "Datatype.h"
#include  "Macros.h"
#include  "DIO_Registers.h"
#include  "DIO_Driver.h"
#include  "Led_Driver.h"
#include  "keypad.h"
#include  "Timer_Counter_Driver.h"
#include  "avr/interrupt.h"



u8 static Counter = 0;


int main(void)
{
	u8  i=1,flg=0,j=0;

	Leds_Init();
	Keypad_Init();
	Timer0_Init();
	Timer0_CtcCompValue(70);

	while(1)
	{
		if( Keypad_ReadButton(1) == 0 )
		{
			flg = 1;
			i = 1;
			Counter = 0;
		}

		else if(  Keypad_ReadButton(2) == 0 )
		{
			flg =  2;
			i = 128;
			Counter = 0;
		}

		else if( Keypad_ReadButton(3) == 0  )
		{
			flg =  3;
			i = 8;
			j = 16;
			Counter = 0;
		}

		else if( Keypad_ReadButton(4) == 0 )
		{
			flg =  4;
			i = 1;
			j = 128;
			Counter = 0;
		}
		else if( Keypad_ReadButton(5) == 0 )
		{
			flg =  5;
			Counter = 0;
		}

		else
		{
			//*Do Nothing*//
		}


//============================================
		if(flg == 1)
		{
			if(Counter == 61)
			{
				i *= 2;
				Counter = 0;
			}
			else
			{
				//*Do Nothing*//
			}

			Leds_On(i);

			if(i == 0)
			{
				i = 1;
			}
			else
			{
				//*Do Nothing*//
			}
		}



//==============================================================
		else if(flg == 2)
		{
			if(Counter == 61)
			{
				i /= 2;
				Counter = 0;
			}
			else
			{
				//*Do Nothing*//
			}

			Leds_On(i);

			if(i == 0)
			{
				i = 128;
			}
			else
			{
				//*Do Nothing*//
			}
		}

//==============================================================
		else if(flg == 3)
		{
			if(Counter == 61)
			{
				i /= 2;
				j *= 2;
				Counter = 0;
			}
			else
			{
				//*Do Nothing*//
			}

			Leds_On(i+j);

			if((i == 0) || (j == 256))
			{
				i = 8;
				j = 16;
			}
			else
			{
				//*Do Nothing*//
			}
		}


//==============================================================
		else if(flg == 4)
		{
			if(Counter == 61)
			{
				i *= 2;
				j /= 2;
				Counter = 0;
			}
			else
			{
				//*Do Nothing*//
			}

			Leds_On(i+j);

			if((i == 16) || (j == 8))
			{
				i = 1;
				j = 128;
			}
			else
			{
				//*Do Nothing*//
			}
		}


//===========================================
		else if(flg == 5)
		{
			Leds_On(0);
		}

		else
		{
			//*Do Nothing*//
		}
	}

	return 0;
}


ISR( TIMER0_COMP_vect)
{
	Counter++;
}
