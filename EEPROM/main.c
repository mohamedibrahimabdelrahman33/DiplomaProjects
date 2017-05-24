#undef F_CPU
#define F_CPU 16000000ul
#include "eeprom.h"
#include <util/delay.h>
#include "DIO_Driver.h"



int main(void)
{
	DIO_SetPinDirection(3,7,1);

	unsigned char x = 0 ;
	eeprom_init();

	eeprom_write_byte(5,0x55);

	_delay_ms(100);
	x = eeprom_read_byte(5);
	





    while(1)
    {
    	if(x == 0x55)
    		{
    			DIO_SetPinValue(3,7,1);
    			_delay_ms(100);
    			DIO_SetPinValue(3,7,0);
    			_delay_ms(100);
    		}
    		else
    		{
    			DIO_SetPinValue(3,7,0);
    		}
    }
}
