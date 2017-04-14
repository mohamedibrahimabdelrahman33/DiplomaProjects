/*
 * Servo_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#include "Datatype.h"
#include  "Macros.h"
#include  "DIO_Driver.h"
#include  "PWM1_Driver.h"
#include  "Servo_Cfg.h"





//*Initial Setting to PWM Registers and servo motor pin*//
//*Input:      None *//
//*Output: None *//
//*Notes:    ........*//
void Servo_Init(void)
{
	DIO_SetPinDirection(SERVO_PORT,SERVO_PIN,OUTPUT);
	PWM_Init();
	PWM_SetPrescaller(PRESCALLER);
	PWM_SetFrequency(FREQUENCY);
}




//* Set Servo Motor Angle *//
//*Input:      Angle *//
//*Output: None *//
//*Notes:    ........*//
void Servo_SetAngle(float Angle)
{
	if((Angle >= (float) 0.0 )  && (Angle <= (float) 180.0 ) )
	{
		Angle =  ( ( ( (Angle * (float) 10.0) /100) /180) * 100);
		PWM_SetDutyCycle(Angle );
	}

	else
	{
		//*Do Noting*//
	}
}
