/*
 * keypad_Cfg.h
 *
 *  created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define R0 16
#define R1 17
#define R2 18
#define R3 19
#define C0 23
#define C1 22
#define C2 21
#define C3 20



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
