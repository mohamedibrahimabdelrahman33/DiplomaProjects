/*
 * UART_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */


#include  "Datatype.h"
#include  "Macro.h"
#include  "DIO_Driver.h"
#include  "UART_Registers.h"
#include  "Interrupt_Registers.h"
#include  "UART_CFG.h"
#include  "avr/interrupt.h"

static volatile void (*RX_PTR)(void) = '\0';
static volatile void (*TX_PTR)(void) = '\0';
static volatile void (*RXTX_PTR)(void) = '\0';


//* UART Registers  Initialization *//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void UART_Init(void)
{
	UCSRA =  ( (DOUBLE_SPEED << 1) | (MULTI_PROCESSOR << 0) );
	UCSRB |= ( (RECIVER_INT_ENABLE << 7) | (TRANSIMITTER_INT_ENABLE << 6) | (UDREMPTY_INT_ENABLE << 5 ) );
	UCSRB |= ( (RECIVER_ENABLE << 4) | (TRANSIMITTER_ENABLE << 3)  | (NINE_BITS_CHRACTER << 2) );
	UCSRC |= ((REGISTER_SELECT << 7) | (UART_MODE << 6) | (PARITY_MODE) | (STOP_BIT_MODE << 3) |  (CHRACTER_SIZE ) | (CLOCK_POLARITY << 0) );
	SREG =    0b10000000;
}




//* Setting UART Baud Rate *//
//*Input:      Baud Rate  *//
//*Output: None *//
//*Notes:    ........*//
void UART_BaudRate(u32 Baud_Rate)
{
	u8 U2X_bit = 0;
	U2X_bit = GET_BIT(UCSRA,1);

	if(U2X_bit == 0)
	{
		switch(Baud_Rate)
		{
		case 2400:
			UBRRL = 0xa0;
			UBRRH = 0x01 ;
			break;

		case 4800:
			UBRRL = 207;
			break;

		case 9600:
			UBRRL = 103;
			break;

		case 14400:
			UBRRL = 68;
			break;

		case 19200:
			UBRRL = 51;
			break;

		case 28800:
			UBRRL = 34;
			break;

		case 38400:
			UBRRL = 25;
			break;

		case 57600:
			UBRRL = 16;
			break;

		case 76800:
			UBRRL = 12;
			break;

		case 115200:
			UBRRL = 8;
			break;

		case 230400:
			UBRRL = 3;
			break;

		default:
			break;
		}

	}

	else
	{
		switch(Baud_Rate)
		{
		case 2400:
			UBRRL = 0x40;
			UBRRH = 0x03 ;
			break;

		case 4800:
			UBRRL = 0xa0;
			UBRRH = 0x01 ;
			break;

		case 9600:
			UBRRL = 207;
			break;

		case 14400:
			UBRRL = 138;
			break;

		case 19200:
			UBRRL = 103;
			break;

		case 28800:
			UBRRL = 68;
			break;

		case 38400:
			UBRRL = 51;
			break;

		case 57600:
			UBRRL = 34;
			break;

		case 76800:
			UBRRL = 25;
			break;

		case 115200:
			UBRRL = 16;
			break;

		case 230400:
			UBRRL = 8;
			break;

		case 250000:
			UBRRL = 7;
			break;

		default:
			break;
		}
	}

}




//* Setting Data for  UART Transmit *//
//*Input:      Data  *//
//*Output: None *//
//*Notes:    ........*//
void UART_DataTransmit(u16 Data)
{
#if( NINE_BITS_CHRACTER == FALSE )
	UDR = Data;
#elif( NINE_BITS_CHRACTER == TRUE )
	SET_BIT(UCSRB,0);
	UDR = (Data - 256) ;
#endif

}

u8 UART_GetTxFlag(void)
{
	return (GET_BIT(UCSRA,4));
}

u8 UART_GetRxFlag(void)
{
	return GET_BIT(UCSRA,7);
}

void UART_ClearTxFlag(void)
{
	SET_BIT(UCSRA,6);
}

//* getting Received Data from  UART  *//
//*Input:      None  *//
//*Output: Data *//
//*Notes:    ........*//
u16 UART_DataRecive(void)
{
	u16 Data = 0;

#if( (NINE_BITS_CHRACTER == FALSE) )
	Data = UDR ;
#elif( (NINE_BITS_CHRACTER == TRUE))
	Data = GET_BIT(UCSRB,0) ;
	Data = ((Data*256) + UDR) ;
#endif

	return Data;
}




void UART_SetRxIsr(void (*Ptr)(void))
{
	RX_PTR = Ptr;
}



void UART_SetTxIsr(void (*Ptr)(void))
{
	TX_PTR = Ptr;
}



void UART_SetUdrIsr(void (*Ptr)(void))
{
	RXTX_PTR = Ptr;
}



ISR(USART_RXC_vect)
{
	RX_PTR();
}




ISR(USART_TXC_vect)
{
	TX_PTR();
}




ISR(USART_UDRE_vect)
{
	RXTX_PTR();
}



