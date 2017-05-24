/*
 * UART_CFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#include  "Datatype.h"
#include  "UART_Registers.h"
#include  "Macros.h"

#define  FALSE  																	0
#define  TRUE 																		1

//* USART Control and Status Register A – UCSRA *//
#define DOUBLE_SPEED 												FALSE
#define MULTI_PROCESSOR										FALSE


//* USART Control and Status Register B – UCSRB *//
#define RECIVER_INT_ENABLE								FALSE
#define TRANSIMITTER_INT_ENABLE				FALSE
#define UDREMPTY_INT_ENABLE						FALSE
#define RECIVER_ENABLE											FALSE
#define TRANSIMITTER_ENABLE							TRUE
#define NINE_BITS_CHRACTER								FALSE //UCSZ2 = 1


//* USART Control and Status Register C – UCSRC *//
//BIT7:
#define UCSRC_REGISTER											TRUE
#define UBRRH_REGISTER											FALSE
//BIT6:
#define SYNCHRONOUS												TRUE
#define ASYNCHRONOUS											FALSE
//BIT5:4
#define PARITY_DISABLED										0b00000000
#define PARITY_EVEN													0b00100000
#define PARITY_ODD														0b00110000
//BIT3:
#define ONE_STOP_BIT												FALSE
#define TWO_STOP_BITS											TRUE
//BIT2:1
#define FIVE_BITS_CHRACTER									0b00000000
#define SIX_BITS_CHRACTER									0b00000010
#define SEVEN_BITS_CHRACTER							0b00000100
#define EIGHT_BITS_CHRACTER								0b00000110//UCSZ2 = 0
//BIT0:
#define TANSMITTED_RISING_EDGE					FALSE
#define TANSMITTED_FALLING_EDGE				TRUE
#define RECEIVED_RISING_EDGE							TRUE
#define RECEIVED_FALLING_EDGE						FALSE
//BIT7:0
#define REGISTER_SELECT											UCSRC_REGISTER
#define UART_MODE														ASYNCHRONOUS
#define PARITY_MODE													PARITY_DISABLED
#define STOP_BIT_MODE											ONE_STOP_BIT
#define CHRACTER_SIZE												EIGHT_BITS_CHRACTER
#define CLOCK_POLARITY											FALSE




#endif /* UART_CFG_H_ */
