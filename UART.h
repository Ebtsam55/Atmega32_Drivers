/*
 * UART.h
 *
 * Created: 4/29/2020 3:41:27 AM
 *  Author: Ebtsam
 */ 


#ifndef UART_H_
#define UART_H_
#include "Header.h"

void UART_init();
void UART_write(uint8_t data);
uint8_t UART_read();



#endif /* UART_H_ */