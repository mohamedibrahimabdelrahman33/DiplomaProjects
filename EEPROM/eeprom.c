#include "eeprom.h"

void eeprom_init(void)
{
	i2c_init_master();
}

void eeprom_write_byte(unsigned short address, unsigned char data)
{
    i2c_start();
	i2c_send_slave_address_with_write_req((unsigned char)(0x0050 | ((address & 0x0300)>>8)));

    //0b0101 0 xxx
	i2c_write_byte((unsigned char)address);
	i2c_write_byte(data);
	i2c_stop();
    return;
}

unsigned char eeprom_read_byte(unsigned short address)
{
	unsigned char data;
	i2c_start();

	i2c_send_slave_address_with_write_req((unsigned char)(0x0050 | ((address & 0x0300)>>8)) );
    i2c_write_byte((unsigned char)address);
	i2c_repeated_start();
	i2c_send_slave_address_with_read_req((unsigned char)(0x0050 | ((address & 0x0300)>>8)));
	data = i2c_read_byte();
	i2c_stop();
    return data;
}
