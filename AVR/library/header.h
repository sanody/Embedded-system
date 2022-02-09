/*
 * header.h
 *
 * Created: 12/2/2021 1:17:39 AM
 *  Author: sch
 */ 


#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 8000000


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define SETBIT(var,bit)		(var |= (1<<bit))
#define CLEARBIT(var,bit)	(var &=~(1<<bit))
#define READBIT(var,bit)	((var>>bit)&1)	 



#endif /* HEADER_H_ */