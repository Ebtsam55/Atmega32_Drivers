/*
 * I2C.c
 *
 * Created: 4/29/2020 7:20:02 PM
 *  Author: Ebtsam
 */ 
#include "I2C.h"
#include "Header.h"
#include <avr/io.h>
//#include <inttypes.h >


#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

// Master
void I2C_master_init(void)
{
	TWBR = 12; // for 400khz scl and 16Mhz freq
}
void I2C_master_start()
{   
	// transmit START condition
	TWCR = 1<<TWEN | 1<<TWSTA |1<<TWINT;
	
	// wait for end of transmission
	while(GETBIT(TWCR,TWINT)==0);
}

void I2C_master_addr(uint8_t addr)
{   
	// for  write operation u should put 0 in LSB in TWDR
	// load slave address into data register
	TWDR = addr<<1; // write operation
	
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
}


void I2C_master_write(uint8_t data)
{
	// load data into data register
	TWDR = data;
	
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
}


void I2C_master_stop(void)
{
	TWCR =1<<TWSTO | 1<<TWINT |1<<TWEN;

}

// Slave
void I2C_slave_Init(uint8_t My_Add)
{
	TWAR =My_Add <<1;
}


uint8_t I2C_slave_avialable()
{
	TWCR = 1<<TWEN |1<<TWINT | 1<<TWEA ; // TWEA to enable ACK
	while( GETBIT(TWCR,TWINT) == 0);
	
    if(TWSR == 0x60) return 1; // 0x60 from status code table 76 page 191 , means slave recieved his add and write op 
    else return 0;
}

uint8_t I2C_slave_read(void)
{
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
	
	// return received data from TWDR
	return TWDR;
}
