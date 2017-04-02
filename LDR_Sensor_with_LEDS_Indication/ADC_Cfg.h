/*
 * ADC_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define TRUE    1
#define FALSE  0
#define LEFT    1
#define RIGHT 0

//===============================================
// REF_VOLTAGE_SOURCE
#define AREF                               										0b00000000
#define AVCC                               										0b01000000
#define INTERNAL_2.56V  										0b11000000


//  INITIAL_CHANNAL
#define CHANNAL0 														 0b00000000
#define CHANNAL1 														 0b00000001
#define CHANNAL2 														 0b00000010
#define CHANNAL3 														 0b00000011
#define CHANNAL4 														 0b00000100
#define CHANNAL5	 												     0b00000101
#define CHANNAL6                                                      0b00000110
#define CHANNAL7                                                       0b00000111
//=================================================

//=================================================
// ADC_PRESCALER

#define PRESCALER_2                                                 0b00000001
#define PRESCALER_4                                                 0b00000010
#define PRESCALER_8                                                 0b00000011
#define PRESCALER_16                                               0b00000100
#define PRESCALER_32                                               0b00000101
#define PRESCALER_64                                               0b00000110
#define PRESCALER_128                                            0b00000111


// SELECT_MODE
#define SINGEL_CONVERSION                              0b00000000
#define AUTO_TRIGGER                                              0b00100000
//=================================================


//=================================================
// AUTO_TRIGGER_SOURCE
#define FREE_RUNNING_MODE							   0b00000000
#define ANALOG COMPARATOR						   0b00000000
#define EXTERNAL_INTERRUPT0						   0b01000000
#define TIMER/COUNTER0_COMP_MATCH    0b00000000
#define TIMER/COUNTER0_OVF                             0b00000000
#define TIMER/COUNTER_COMP_MATCHB    0b00000000
#define TIMER/COUNTER1_OVF                             0b00000000
#define TIMER/COUNTER1_CAP_EV                    0b00000000

//=================================================


// ADMUX Register
#define REF_VOLTAGE_SOURCE                             AVCC
#define LEFT_ADJUST                                                     FALSE
#define INITIAL_CHANNAL                                         CHANNAL0
// ADCSRA  Register
#define ADC_ENABLE                                                      TRUE
#define SELECT_MODE                                                   AUTO_TRIGGER
#define ADC_INTERRUPT_ENABLE                       TRUE
#define ADC_PRESCALER                                             PRESCALER_32
// SFIOR Register
#define ADC_AUTO_TRIGGER_SOURCE			  FREE_RUNNING_MODE

#endif /* ADC_CFG_H_ */
