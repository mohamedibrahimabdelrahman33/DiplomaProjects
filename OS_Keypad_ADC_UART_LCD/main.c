/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */

#include "FreeRTOS.h"
#include "task.h"
#include "projdefs.h"
#include "Datatype.h"
#include "DIO_Driver.h"
#include "ADC_Driver.h"
#include "UART_Driver.h"
#include "LCD.h"
#include "queue.h"

xQueueHandle Data_Queue ;
xQueueHandle Counter_Queue ;


void UART_Task(void *x)
{
	u8  Received_Data ;

	UART_Init();
	UART_BaudRate(9600);
	UART_DataTransmit(Received_Data);

	while(1)
	{

		if(!( xQueueReceive(Data_Queue,&Received_Data,500)))
		{
			//*Do Noting*//
		}

		while((UART_GetTxFlag()));
		UART_DataTransmit(((u16)Received_Data));
		vTaskDelay(1000);
	}

}

void ADC_Task(void *x)
{
	u8 Data = 0;

	ADC_Init();



	while(1)
	{
		if(!(xQueueSend(Data_Queue,&Data,500)))
		{
			//*Do Noting*//
		}
		ADC_StartConversion();
		while(!(ADC_GetFlag()));
		Data = (u8) (ADC_Read_10_BitMode() / 4);



		vTaskDelay(1000);

	}

}




void Keypad_Task(void *x)
{
	u8 Switch_State = 0;
	u8 Counter = 0;

	DIO_EnablePullupResistance(29);
	DIO_SetPinDirection(3,5,0);


	while(1)
	{
		Switch_State = DIO_GetPinValue(3,5);
		if(!(xQueueSend(Counter_Queue,&Counter,500)))
		{
			//*Do Noting*//
		}

		if(!(Switch_State))
		{
			Counter++;
		}

		vTaskDelay(200);

	}

}



void LCD_Task(void *x)
{
	u8 Counter = 0;

	LCD_Init();

	while(1)
	{
		LCD_WriteCommand(0x80);

		if(!( xQueueReceive(Counter_Queue,&Counter,500)))
		{
			//*Do Noting*//
		}

		LCD_WriteDigits(4,Counter);
		vTaskDelay(100);

	}

}




int main( void )
{
	xTaskHandle ADC_Task_Handler;
	xTaskHandle UART_Task_Handler;
	xTaskHandle Keypad_Task_Handler;
	xTaskHandle LCD_Task_Handler;

	xTaskCreate(ADC_Task,0,150,0,1,&ADC_Task_Handler);
	xTaskCreate(UART_Task,0,150,0,2,&UART_Task_Handler);
	xTaskCreate(LCD_Task,0,150,0,4,&LCD_Task_Handler);
	xTaskCreate(Keypad_Task,0,150,0,3,&Keypad_Task_Handler);
	Data_Queue         =  xQueueCreate(10,1);
	Counter_Queue =  xQueueCreate(10,1);
	vTaskStartScheduler();


	return 0;
}

