/*
 * ADC_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADMUX *((volatile u8*)  0x27)
#define ADCSRA *((volatile u8*)  0x26)
#define ADCL *((volatile u8*)  0x24)
#define ADCH *((volatile u8*)  0x25)
#define ADCLH *((volatile u16*)  0x24)
#define SFIOR *((volatile u8*)  0x50)


#endif /* ADC_REGISTERS_H_ */
