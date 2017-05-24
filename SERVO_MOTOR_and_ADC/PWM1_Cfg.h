/*
 * Timer_Counter_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef PWM1_CFG_H_
#define PWM1_CFG_H_



//*TCCR1A*//
//*Compare Output Mode for Channel A IN FAST PWM MODE*//
#define DIS_CON_CHANNELA							0b00000000
#define NONINVERTING_CHANNELA		0b10000000
#define INVERTING_CHANNELA					0b11000000
//*Compare Output Mode for Channel B IN FAST PWM MODE*//
#define DIS_CON_CHANNELB							0b00000000
#define NONINVERTING_CHANNELB		0b00100000 //*Starts from high to low*//
#define INVERTING_CHANNELB					0b00110000 //*Starts from low to high *//
//*Waveform Generation Mode for FAST PWM MODE *//
#define ICR1_TOP														0b00000010
#define OCR1A_TOP 												0b00000011



//*TCCR1B*//
//*Waveform Generation Mode*//
#define FAST_PWM													0b00011000
//*PRESCALER*//
#define OFF																	0b00000000
#define NO_PRESC													0b00000001
#define CLK_8																0b00000010
#define CLK_64															0b00000011
#define CLK_256															0b00000100
#define CLK_1024														0b00000101
#define EXT_CLK_FALLING_EDGE				0b00000110
#define EXT_CLK_RISING_EDGE						0b00000111




//*TIMSK*//
#define OVF_INT_MODE 										0b00000100
#define COMP_B_INT_MODE							0b00001000
#define COMP_A_INT_MODE							0b00010000
#define INPUT_CAP_INT_MODE						0b00100000
#define POLLING_BASED									0b00000000




// TCCR1 Register
#define TIMER1_MODE2										FAST_PWM
#define TIMER1_MODE1										ICR1_TOP
#define OC1A_FUNC												NONINVERTING_CHANNELA
#define OC1B_FUNC												DIS_CON_CHANNELB

#define PRESCALER													OFF

//TIMSK
#define TIMER1_INTERRUPT_MODE			POLLING_BASED



#endif /* PWM1_CFG_H_ */
