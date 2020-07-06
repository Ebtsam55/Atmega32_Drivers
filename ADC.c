/*
 * ADC.c
 *
 * Created: 4/19/2020 11:58:08 PM
 *  Author: Ebtsam
 */ 

#include "ADC.h"

void ADC_init()
{
	SETBIT(ADMUX, REFS0); // Vcc is the voltage reference 
	SETBIT(ADCSRA,ADEN);
	SETBIT(ADCSRA , ADPS0);
	SETBIT(ADCSRA , ADPS1);
	SETBIT(ADCSRA , ADPS2);
	SETBIT(ADCSRA, ADIE);
}
void  ADC_read()
{   
	SETBIT(ADCSRA,ADSC); //start conversion 
	 /*while(GETBIT(ADCSRA,ADSC));
	return ADC;*/
	
}