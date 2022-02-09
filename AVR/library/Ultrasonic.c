/*
 * Ultrasonic.c
 *
 * Created: 30-Nov-21 9:50:44 AM
 *  Author: Marina
 */ 

#include "Ultrasonic.h"

double distance1   = 0;
double distance2   = 0;
uint32_t timer     = 0;
uint8_t  flag      = 0;

void ULTRASONIC_init (void)
{
	ulreasonic_init();
	ECHO1_interrupt_init();
	ECHO2_interrupt_init();
	
	TIMER_init();
	sei();
}

void ULTRASONIC_distance1(void)
{
	if(!flag)
	{	TRIGGER1(1);
		_delay_us(10);
		TRIGGER1(0);
		flag = 1;
	}
}

void ULTRASONIC_distance2(void)
{
	if(!flag)
	{	TRIGGER2(1);
		_delay_us(10);
		TRIGGER2(0);
		flag = 1;
	}
}

ISR(TIMER0_OVF_vect)
{
	timer++;
}

ISR(INT0_vect)
{	

	if(ECHO1)
	{	TIMER_on();}
	else
	{	distance1 = (double)((double)(256*timer + TCNT0)/((double)58*8));
		flag = 0;
		TIMER_off();
		TCNT0 = 0;
		timer = 0;
	}
}

ISR(INT1_vect)
{

	if(ECHO2)
	{	TIMER_on();}
	else
	{	distance2 = (double)((double)(256*timer + TCNT0)/((double)58*8));
		flag = 0;
		TIMER_off();
		TCNT0 = 0;
		timer = 0;
	}
}
