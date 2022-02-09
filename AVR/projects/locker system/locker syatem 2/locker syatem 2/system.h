/*
 * system.h
 *
 * Created: 09-Feb-22 11:36:25 AM
 *  Author: Marina
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "header.h"
#include "EEPROM.h"
#include "keybad.h"
#include "LCD.h"
#include "password.h"

#define LOCKER_init()		SETBIT(DDRA,2)
#define LOCKER(x)if(x == 1)	SETBIT(PORTA,2); else CLEARBIT(PORTA,2);

typedef struct  
{
	uint8_t state;
	uint8_t clear;
	uint8_t password[PASSOWRD_DIGITS];
	uint8_t NewPassword[PASSOWRD_DIGITS];
} lockerSystem;

typedef enum
{
	reset			= 0,
	changePassword  = 1,
	open			= 2,
	close			= 3,
	savePassword	= 4
}systemStates;

void system_init(void);
void check_state(void);
void run_system(void);

#endif /* SYSTEM_H_ */