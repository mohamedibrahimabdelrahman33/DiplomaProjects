/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include  "Macros.h"
#include "Datatype.h"

void ADC_Init(void);
void ADC_StartConversion(void);
void ADC_DataAjustment(u8 Direction);
    u8 ADC_GetFlag(void);
void ADC_ClearFlag(void);
 u16 ADC_Read_10_BitMode(void);
    u8 ADC_Read_8_BitMode(void);
void ADC_AutoTriggerSource(void);

#endif /* ADC_DRIVER_H_ */
