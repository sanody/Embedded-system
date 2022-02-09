/*
 * Ultrasonic.h
 *
 * Created: 30-Nov-21 9:51:05 AM
 *  Author: Marina
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "header.h"

#define ulreasonic_init()		SETBIT(DDRD,1);SETBIT(DDRD,4);
#define ECHO1_interrupt_init()	SETBIT(MCUCR,ISC00); SETBIT(GICR,INT0); SETBIT(SREG,7); 
#define ECHO2_interrupt_init()	SETBIT(MCUCR,ISC10); SETBIT(GICR,INT1); 

#define TIMER_init()		    TCNT0 = 0 ; SETBIT (TIMSK,TOIE0);
#define TIMER_on()			    SETBIT(TCCR0,CS00);
#define TIMER_off()			    CLEARBIT(TCCR0,CS00);

#define TRIGGER1(x) if(x==1)	SETBIT(PORTD,1); else CLEARBIT(PORTD,1) ;
#define ECHO1				    READBIT(PIND,2)	

#define TRIGGER2(x) if(x==1)	SETBIT(PORTD,4); else CLEARBIT(PORTD,4) ;
#define ECHO2				    READBIT(PIND,3)	

void ULTRASONIC_init (void);
void ULTRASONIC_distance1(void);
void ULTRASONIC_distance2(void);

#endif /* ULTRASONIC_H_ */