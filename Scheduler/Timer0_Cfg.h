/*
 * Timer_Counter_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_


// TIMER0_MODE
#define OVF																	0b00000000
#define PWM																	0b01000000
#define CTC																	0b00001000
#define FAST_PWM 													0b01001000

//OC0_Func
#define DIS_CON														0b00000000
#define TOGGLE															0b00010000
#define CLEAR																0b00100000
#define SET																	0b00110000


//PRESCALER
#define OFF																	0b00000000
#define NO_PRESC													0b00000001
#define CLK_8																0b00000010
#define CLK_64															0b00000011
#define CLK_256															0b00000100
#define CLK_1024														0b00000101
#define EXT_CLK_FALLING_EDGE				0b00000110
#define EXT_CLK_RISING_EDGE						0b00000111


//TIMER0 INTERRUPT MASK
#define OVF_INT_MODE 										0b00000001
#define COMP_INT_MODE									0b00000010
#define POLLING_BASED									0b00000000




// TCCR0 Register
#define TIMER0_MODE											CTC
#define OC0_FUNC													DIS_CON
#define PRESCALER													CLK_256

//TIMSK
#define TIMER0_INTERRUPT_MODE			COMP_INT_MODE



#endif /* TIMER0_CFG_H_ */
