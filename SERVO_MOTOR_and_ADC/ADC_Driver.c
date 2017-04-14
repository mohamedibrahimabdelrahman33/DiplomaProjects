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




//*Initial  Setting to  ADC *//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void ADC_Init(void)
{
	ADMUX   |=  ( ( REF_VOLTAGE_SOURCE ) |  ( INITIAL_CHANNAL ) | ( LEFT_ADJUST << 5 ) );
	ADCSRA |= ( (ADC_ENABLE << 7) | (  ADC_MODE ) | ( ADC_INTERRUPT_ENABLE << 3 ) | ( ADC_PRESCALER )  );
#if( ADC_MODE ==  AUTO_TRIGGER )
	SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
#else
	//*Do Noting*//
#endif
}




//*ADC Start Conversion Process  *//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA, 6);
}




//*ADC Set Reading Mode Left Or Right Mode *//
//*Input:      Direction *//
//*Output: None *//
//*Notes:    ........*//
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




//*Reading ADC Conversion Flag Status *//
//*Input:      None *//
//*Output: Flag Status *//
//*Notes:    ........*//
u8  ADC_GetFlag(void)
{
#if( ADC_MODE == SINGEL_CONVERSION )
	return  GET_BIT( ADCSRA,4 );
#else
	//*Do Noting*//
#endif
}




//*Clearing ADC Conversion Flag  *//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void ADC_ClearFlag(void)
{
#if ( ADC_INTERRUPT_ENABLE ==  FALSE )
	SET_BIT( ADCSRA,4 );
#else
//*Do Nothing*//
#endif
}




//*Reading  ADC Conversion Result In Right Mode From ADCL and ADCH *//
//*Input:      None *//
//*Output: Result From 0 to 1023 *//
//*Notes:    ........*//
u16 ADC_Read_10_BitMode(void)
{
#if ( LEFT_ADJUST  ==  FALSE )
	return ADCLH;
#else
//*Do Nothing*//
#endif

}




//*Reading  ADC Conversion Result In Left or Right  Mode From  ADCH  or ADCL*//
//*Input:      None *//
//*Output: Result From 0 to 255 *//
//*Notes:    ........*//
u8 ADC_Read_8_BitMode(void)
{
	u8 Read = 0;
	if( LEFT_ADJUST  == FALSE )
	{
		Read =  ADCL;
	}
	else if( LEFT_ADJUST  == TRUE )
	{
		Read =  ADCH;
	}

	return Read;
}












