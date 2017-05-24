/*
 * Timer_Counter_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_



//*TCCR1A*//
//*Compare Output Mode for Channel A*//
#define DIS_CON_CHANNELA							0b00000000
#define TOGGLE_CHANNELA							0b01000000
#define CLEAR_CHANNELA								0b10000000
#define SET_CHANNELA										0b11000000
//*Compare Output Mode for Channel B*//
#define DIS_CON_CHANNELB							0b00000000
#define TOGGLE_CHANNELB							0b00010000
#define CLEAR_CHANNELB								0b00100000
#define SET_CHANNELB										0b00110000



//*TCCR1B*//
//*Waveform Generation Mode*//
#define OVF																	0b00000000
#define CTC_OCR1A													0b00001000
#define CTC_ICR1														0b00011000
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
#define TIMER1_MODE										    CTC_OCR1A
#define OC1A_FUNC												DIS_CON_CHANNELA
#define OC1B_FUNC												DIS_CON_CHANNELB
#define PRESCALER													CLK_1024

//TIMSK
#define TIMER1_INTERRUPT_MODE			POLLING_BASED



#endif /* TIMER1_CFG_H_ */
