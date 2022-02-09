/*
 * keybad.h
 *
 * Created: 12/2/2021 2:16:35 AM
 *  Author: Marina
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#include "header.h"

#define keybadDDR	DDRD
#define keybadPORT	PORTD
#define keybadPIN	PIND


#define KEYBAD_init_()		keybadDDR |= 0x0F; keybadPORT |= 0xF0;
#define KP0(x) if(x == 1)	SETBIT(keybadPORT,0); else CLEARBIT(keybadPORT,0);
#define KP1(x) if(x == 1)	SETBIT(keybadPORT,1); else CLEARBIT(keybadPORT,1);
#define KP2(x) if(x == 1)	SETBIT(keybadPORT,2); else CLEARBIT(keybadPORT,2);
#define KP3(x) if(x == 1)	SETBIT(keybadPORT,3); else CLEARBIT(keybadPORT,3);

#define KP4					READBIT(keybadPIN , 4)
#define KP5					READBIT(keybadPIN , 5)
#define KP6					READBIT(keybadPIN , 6)
#define KP7					READBIT(keybadPIN , 7)

#define BUZZER_init()	SETBIT(DDRA,1)
#define BUZZER(x)		if(x == 1)	SETBIT(PORTA,1); else CLEARBIT(PORTA,1);

void KEYPAD_init(void);
uint8_t KEYPAD_read(void);

#endif /* KEYBAD_H_ */
