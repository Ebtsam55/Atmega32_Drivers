/*
 * PWM.h
 *
 * Created: 4/22/2020 5:46:42 PM
 *  Author: Ebtsam
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "Header.h"

void PWM_init_timer1_oc1a();
void set_duty_oc1a(uint8_t duty);
void PWM_init_timer1_oc1b();
void set_duty_oc1b(uint8_t duty);




#endif /* PWM_H_ */