/*
 * ExInterrupt.h
 *
 * Created: 3/24/2020 6:21:39 PM
 *  Author: Ebtsam
 */ 


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_


void INT0_INIT()
{
	SETBIT(GICR,INT0);  //External Interrupt Request 0 Enable
	SETBIT(MCUCR ,ISC00); //rising edge of INT1 generates an interrupt request.
	SETBIT(MCUCR ,ISC01);
}

void INT1_INIT()
{
	SETBIT(GICR,INT1); 
	SETBIT(MCUCR ,ISC10); 
	SETBIT(MCUCR ,ISC11);
}

void Global_Interrupt_Enable()
{
	SETBIT(SREG,7) ; //Global Interrupt Enable
}



#endif /* EXINTERRUPT_H_ */