/*
 * Timer_Counter_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "Macro.h"
#include  "Timer_Registers.h"
#include  "Interrupt_Registers.h"
#include  "Timer1_Cfg.h"



//*Initial Setting to Timer1 Registers*//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void Timer1_Init(void)
{
	TCCR1A = ( ( OC1A_FUNC )  |  ( OC1B_FUNC ) );
	TCCR1B = ( ( TIMER1_MODE ) | (PRESCALER) );
#if (TIMER1_INTERRUPT_MODE	 != POLLING_BASED )
	TIMSK  = (TIMER1_INTERRUPT_MODE);
	SREG    =  0b10000000;
#else
	//*Do Noting*//
#endif
}



//*Setting Start Value  to Timer1*//
//*Input:     Starting Value *//
//*Output: None *//
//*Notes:    ........*//
void Timer1_Preload(u16 Value)
{
	TCNT1LH = Value;
}




//*Setting Comparing Value  to Timer1*//
//*Input:     Comparing Value *//
//*Output: None *//
//*Notes:    ........*//
void Timer1_CtcCompValue(u16 Value)
{
#if (TIMER1_MODE == CTC_OCR1A )
	OCR1ALH = Value;
#elif (TIMER1_MODE == CTC_ICR1 )
	ICR1LH = Value;
#else
	//*Do Nothing*//
#endif
}



//*Get Flag State  to Timer1*//
//*Input:     None  *//
//*Output: Flag State *//
//*Notes:    ........*//
u8 Get_IntFlag(void)
{
	u8 Read = 0;

#if ( (TIMER1_INTERRUPT_MODE == POLLING_BASED) && (TIMER1_MODE ==  OVF) )
	Read = GET_BIT(TIFR,2);
#elif ( (TIMER1_INTERRUPT_MODE == POLLING_BASED) && (TIMER1_MODE ==  CTC_OCR1A) )
	Read = GET_BIT(TIFR,4);
#elif ( (TIMER1_INTERRUPT_MODE == POLLING_BASED) && (TIMER1_MODE ==  CTC_ICR1) )
	Read = GET_BIT(TIFR,5);
#else
	//*Do Nothing*//
#endif
	return Read;
}


//*Clear Flag  to Timer1*//
//*Input:     None  *//
//*Output: None *//
//*Notes:    ........*//
void Clear_IntFlag(void)
{
#if ( ( TIMER0_INTERRUPT_MODE == POLLING_BASED ) && ( TIMER0_MODE == OVF ))
	SET_BIT(TIFR,2);
#elif ( ( TIMER0_INTERRUPT_MODE == POLLING_BASED ) && ( TIMER0_MODE == CTC_OCR1A ))
	SET_BIT(TIFR,4);
#elif ( (TIMER1_INTERRUPT_MODE == POLLING_BASED) && (TIMER1_MODE ==  CTC_ICR1) )
	SET_BIT(TIFR,5);
#else
	//*Do Nothing*//
#endif
}


