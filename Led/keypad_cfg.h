/*
 * keypad_Cfg.h
 *
 *  created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define R0 24
#define R1 25
#define R2 26
#define R3 27
#define C0 28
#define C1 29
#define C2 30
#define C3 31



struct keypad
{
	 u16 button1 : 1;
	 u16 button2 : 1;
	 u16 button3 : 1;
	 u16 button4 : 1;
	 u16 button5 : 1;
	 u16 button6 : 1;
	 u16 button7 : 1;
	 u16 button8 : 1;
	 u16 button9 : 1;
	 u16 button10 : 1;
	 u16 button11 : 1;
	 u16 button12 : 1;
	 u16 button13 : 1;
	 u16 button14 : 1;
	 u16 button15 : 1;
	 u16 button16 : 1;
};



#endif /* KEYPAD_CFG_H_ */
