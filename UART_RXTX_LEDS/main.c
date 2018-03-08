/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */
#undef  F_CPU
#define  F_CPU 16000000ul
#include  "Datatype.h"
#include  "Macros.h"
#include  "DIO_Driver.h"
#include  "UART_Driver.h"
#include  "UART_Registers.h"
#include  "ADC_Driver.h"
#include  "avr/interrupt.h"



static volatile u8 received_data = 0  ;
static volatile u8 send_data = 0  ;

void recieve(void)
{
	received_data = UART_DataRecive();
}

void send(void)
{
	UART_DataTransmit(send_data);
}


int main(void)
{
	DIO_SetPortDirection(1,1);

	UART_Init();
	ADC_Init();
	ADC_StartConversion();
	UART_BaudRate(9600);
	UART_SetRxIsr(recieve);
	UART_SetTxIsr(send);
	UART_DataTransmit(send_data);



	while(1)
	{
		DIO_SetPortValue(1,received_data);
	}

	return 0;
}


ISR( ADC_vect)
{
	send_data = (ADC_Read_10_BitMode() / 4);
}



