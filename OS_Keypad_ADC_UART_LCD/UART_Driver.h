/*
 * UART_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_
#include  "Datatype.h"


void UART_Init(void);
void UART_BaudRate(u32 Baud_Rate);
void UART_DataTransmit(u16 Data);
u16 UART_DataRecive(void);
u8 UART_GetTxFlag(void);
u8 UART_GetRxFlag(void);
void UART_ClearTxFlag(void);
void UART_SetRxIsr(void (*Ptr)(void));
void UART_SetTxIsr(void (*Ptr)(void));
void UART_SetUdrIsr(void (*Ptr)(void));



#endif /* UART_DRIVER_H_ */
