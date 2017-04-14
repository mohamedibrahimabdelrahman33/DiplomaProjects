/*
 * Timer_Counter_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "Macros.h"
#include  "Timer_Registers.h"
#include  "Interrupt_Registers.h"
#include  "PWM1_Cfg.h"


static u16 Total_Frequency = 0;
static u16 Total_TicNumber = 0;


//*Initial Setting to PWM Registers*//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void PWM_Init(void)
{
	TCCR1A = ( ( OC1A_FUNC )  |  ( OC1B_FUNC ) | ( TIMER1_MODE1 ) );
	TCCR1B = ( ( TIMER1_MODE2 ) | (PRESCALER) );
	#if (TIMER1_INTERRUPT_MODE	 != POLLING_BASED )
		TIMSK  = (TIMER1_INTERRUPT_MODE);
		SREG    =  0b10000000;
	#else
		//*Do Noting*//
	#endif
}




//* Set PWM Prescaller:calculate input frequency to the PWM *//
//*Input:      Prescaller *//
//*Output: None *//
//*Notes:    ........*//
void  PWM_SetPrescaller(u16 Prescaller)
{

	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);

	if(Prescaller == 8)
	{
		TCCR1B |= (0b00000010) ;
	}

	else if(Prescaller == 64 )
	{
		TCCR1B |= (0b00000011) ;
	}

	else if(Prescaller == 256 )
	{
		TCCR1B |= (0b00000100) ;
	}

	else if(Prescaller == 1024 )
	{
		TCCR1B |= (0b00000101) ;
	}

	else
	{
		//*Do Noting*//
	}

	Total_Frequency = (16000000/Prescaller);

}





//* Set PWM frequency:calculate output  frequency from the PWM *//
//*Input:      Frequency *//
//*Output: None *//
//*Notes:    ........*//
void PWM_SetFrequency(u8 Frequency)
{
	if((Frequency >= 0) && (Frequency <= 100))
	{
		Total_TicNumber  = (Total_Frequency / Frequency);
		ICR1LH = Total_TicNumber;
	}

	else
	{
		//*Do Noting*//
	}

}



//* Set PWM duty cycle : calculate output  DutyCycle from the PWM *//
//*Input:      DutyCycle *//
//*Output: None *//
//*Notes:    ........*//
void PWM_SetDutyCycle( float DutyCycle)
{
	if(( DutyCycle >= (float)  0.00  )  &&  (  DutyCycle <= (float)  11.00 ) )
	{
		OCR1ALH =(u16)  (  ((float) Total_TicNumber *   ( DutyCycle + (float) 3.75) ) / (float) 100);
	}

	else
	{
		//*Do Noting*//
	}
}




