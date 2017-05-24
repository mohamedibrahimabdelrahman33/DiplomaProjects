/*
 * Interrupt_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef INTERRUPT_REGISTERS_H_
#define INTERRUPT_REGISTERS_H_

#define MCUCR *((volatile u8*)  0x55)
#define MCUCSR *((volatile u8*)  0x54)
#define GICR *((volatile u8*)  0x5B)
#define SREG *((volatile u8*)  0x5F)

#define EN_INT  7
#define INT0 6
#define INT1 7
#define INT2 5
#define  INT0_FallingEdge 1
#define  INT1_FallingEdge 3

#endif /* INTERRUPT_REGISTERS_H_ */
