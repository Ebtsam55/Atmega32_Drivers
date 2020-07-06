/*
 * I2c.h
 *
 * Created: 4/29/2020 7:20:18 PM
 *  Author: Ebtsam
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "Header.h"
#include <avr/io.h>
//#include <inttypes.h >


// Master
void I2C_master_init(void);
void I2C_master_start();
void I2C_master_addr(uint8_t addr);
void I2C_master_write(uint8_t data);
void I2C_master_stop(void);

// Slave
void I2C_slave_Init(uint8_t My_Add);
uint8_t I2C_slave_avialable();
uint8_t I2C_slave_read(void);





#endif /* I2C_H_ */