/*
 * PWM.c
 *
 * Created: 4/22/2020 5:46:17 PM
 *  Author: Ebtsam
 */ 
#include "PWM.h"


/*
10bit fast PWM 
non_inverting
oc1a
*/
void PWM_init_timer1_oc1a()
{
	SETBIT(DDRD ,5);
	TCCR1A |=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
	TCCR1B=(1<<WGM12)|(1<<CS10);
	
}

/*
duty = (ocr1a / 1023) * 100
OCR1A = duty* 10.23;
*/
void set_duty_oc1a(uint8_t duty)
{
	OCR1A=duty*10.23;
}


void PWM_init_timer1_oc1b()
{
	SETBIT(DDRD ,4);
	TCCR1A |=(1<<COM1B1)|(1<<WGM11)|(1<<WGM10);
	TCCR1B=(1<<WGM12)|(1<<CS10);
}
void set_duty_oc1b(uint8_t duty)
{
	OCR1B=duty*10.23;
}