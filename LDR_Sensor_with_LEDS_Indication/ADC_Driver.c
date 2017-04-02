/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include  "ADC_Registers.h"
#include  "Macros.h"
#include "Datatype.h"
#include "ADC_Cfg.h"
#include  "Interrupt_Registers.h"




//=======================================
void ADC_Init(void)
{
	ADMUX   |=  ( ( REF_VOLTAGE_SOURCE ) |  ( INITIAL_CHANNAL ) | ( LEFT_ADJUST << 5 ) );
	ADCSRA |= ( (ADC_ENABLE << 7) | ( SELECT_MODE ) | ( ADC_INTERRUPT_ENABLE << 3 ) | ( ADC_PRESCALER )  );
	SREG = 0x80;
}


//=======================================
void ADC_AutoTriggerSource(void)
{
	SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
}



//===========================================
void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA, 6);
}



//==========================================
void ADC_DataAjustment(u8 Direction)
{
	if( Direction == LEFT )
	{
		SET_BIT(ADMUX, 5);
	}

	else if( Direction == RIGHT)
	{
		CLEAR_BIT(ADMUX, 5);
	}

}




//==============================================
u8  ADC_GetFlag(void)
{
	return  GET_BIT( ADCSRA,4 );
}




//=========================================
void ADC_ClearFlag(void)
{
#if (ADC_INTERRUPT_ENABLE == FALSE)
	SET_BIT( ADCSRA,4 );
#else

#endif
}




//=============================================
u16 ADC_Read_10_BitMode(void)
{
	return ADCLH;
}


//=============================================
u8 ADC_Read_8_BitMode(void)
{
	u8 Read = 0;
	if( LEFT_ADJUST  == FALSE )//adlr=0;
	{
		Read =  ADCL;
	}
	else if( LEFT_ADJUST  == TRUE )
	{
		Read =  ADCH;
	}

	return Read;
}












