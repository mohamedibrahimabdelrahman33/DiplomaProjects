/*
 * UART_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

#include  "Datatype.h"

#define UDR        *((volatile u8*)  0x2c)
#define UCSRA  *((volatile u8*)  0x2b)
#define UCSRB  *((volatile u8*)  0x2a)
#define UCSRC  *((volatile u8*)  0x40)
#define UBRRL *((volatile u8*)  0x29)
#define UBRRH *((volatile u8*)  0x40)


#endif /* UART_REGISTERS_H_ */
