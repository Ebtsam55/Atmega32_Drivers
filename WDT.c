/*
 * WDT.c
 *
 * Created: 4/27/2020 3:57:27 PM
 *  Author: Ebtsam
 */ 
#include "WDT.h"
void WDT_ON()
{
	WDTCR= 0b1111;
}

void WDT_OFF()
{ 
	WDTCR = 1<<WDTOE | 1<<WDE ;
	WDTCR =0;
	
}