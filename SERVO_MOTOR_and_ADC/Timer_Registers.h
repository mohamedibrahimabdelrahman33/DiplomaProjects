/*
 * Timer_Counter_Register.h
 *
 *  Created on: ??�/??�/????
 *      Author: Mohamed
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_


//Timer_0 8_Bit
#define TCCR0 *((volatile u8*)  0x53)
#define TCNT0  *((volatile u8*)  0x52)
#define OCR0  *((volatile u8*)  0x5c)


//Timer_1 16_Bit
#define TCCR1A *((volatile u8*)  0x4f)
#define TCCR1B *((volatile u8*)  0x4e)

#define TCNT1H *((volatile u8*)  0x4d)
#define TCNT1L *((volatile u8*)  0x4c)
#define TCNT1LH *((volatile u16*)  0x4c)

#define OCR1AH *((volatile u8*)  0x4b)
#define OCR1AL *((volatile u8*)  0x4a)
#define OCR1ALH *((volatile u16*)  0x4a)

#define OCR1BH *((volatile u8*)  0x49)
#define OCR1BL *((volatile u8*)  0x48)
#define OCR1BLH *((volatile u16*)  0x48)

#define ICR1L *((volatile u8*)  0x46)
#define ICR1H *((volatile u8*)  0x47)
#define ICR1LH *((volatile u16*)  0x46)

#define TIMSK *((volatile u8*)  0x59)
#define TIFR *((volatile u8*)  0x53)

#endif /* TIMER_REGISTERS_H_ */
