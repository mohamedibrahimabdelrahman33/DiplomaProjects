/*
 * Macros.h
 *
 *  Created on: ??‏/??‏/????
 *      Author: Mohamed
 */

#ifndef MACRO_H_
#define MACRO_H_



#define SET_BIT(R,BIT_NUMBER)  R |= (1<<BIT_NUMBER)
#define CLEAR_BIT(R,BIT_NUMBER)  R &= ~(1<<BIT_NUMBER)
#define TOGGLE_BIT(R,BIT_NUMBER) R ^= (1<<BIT_NUMBER)
#define GET_BIT(R,BIT_NUMBER)  (( R & ( 1<<BIT_NUMBER ) ) >> ( BIT_NUMBER ))


#endif /* MACRO_H_ */
