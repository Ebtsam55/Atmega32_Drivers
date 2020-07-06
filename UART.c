/*
 * UART.c
 *
 * Created: 4/29/2020 3:41:16 AM
 *  Author: Ebtsam
 */ 
#include "UART.h"

void UART_init()
{
	UCSRC |= 1<<UCSZ1 | 1<<UCSZ0 | 1<<URSEL; //8bit data
	
	UBRRL =103; //baud rate 9600 , freq 16M
	
	UCSRB |= 1<<RXEN | 1<<TXEN ;
}
void UART_write(uint8_t data)
{
	
	UDR=data;
	while(!(UCSRA &(1<<TXC)));
}
uint8_t UART_read()
{
	while(!(UCSRA &(1<<RXC)));;
	return UDR;
}