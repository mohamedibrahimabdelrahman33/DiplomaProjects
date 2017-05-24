/*
 * LCD.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Mohamed Tarek
 */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#include "Datatype.h"

void LCD_WriteData(u8 Data);
void LCD_WriteCommand(u8 Command);
void LCD_Init(void);
void LCD_WriteString(u8 Char_Arr[LCD_RowLength]);
void LCD_WriteDigits(u8 Digit_Number, u32 Value );

#endif /* LCD_H_ */
