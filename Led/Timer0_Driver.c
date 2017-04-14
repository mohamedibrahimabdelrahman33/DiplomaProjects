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
#include  "Timer0_Cfg.h"


void Timer0_Init(void)
{
	TCCR0 = ( ( TIMER0_MODE )  |  ( OC0_FUNC )  |  ( PRESCALER ) );
	TIMSK  = (TIMER0_INTERRUPT_MODE);
	SREG    =  0b10000000;
}

void Timer0_Preload(u8 Value)
{
	TCNT0 = Value;
}

void Timer0_CtcCompValue(u8 Value)
{
#if (TIMER0_MODE == CTC )
	OCR0 = Value;
#else
	//*Do Nothing*//
#endif
}


u8 Get_IntFlag(void)
{
	u8 Read = 0;

#if ( TIMER0_INTERRUPT_MODE == OVF_INT_MODE )
	Read = GET_BIT(TIFR,0);
#elif ( TIMER0_INTERRUPT_MODE == COMP_INT_MODE )
	Read = GET_BIT(TIFR,1);
#else
	//*Do Nothing*//
#endif
	return Read;
}



void Clear_IntFlag(void)
{


#if ( ( TIMER0_INTERRUPT_MODE == POLLING_BASED ) && ( TIMER0_MODE == OVF ))
	SET_BIT(TIFR,0);
#elif ( ( TIMER0_INTERRUPT_MODE == POLLING_BASED ) && ( TIMER0_MODE == CTC ))
	SET_BIT(TIFR,1);
#else
	//*Do Nothing*//
#endif
}


