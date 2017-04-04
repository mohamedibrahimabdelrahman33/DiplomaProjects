/*
 * keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Datatype.h"
#include "keypad_cfg.h"



void Keypad_Init(void);
u8 Keypad_ReadButton(u8 button_number);
struct keypad Keypad_Scan(void);



#endif /* KEYPAD_H_ */
