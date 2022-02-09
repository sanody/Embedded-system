/*
 * password.h
 *
 * Created: 12/3/2021 11:36:02 PM
 *  Author: Marina
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "header.h"
#include "EEPROM.h"
#include "LCD.h"

#define PASSOWRD_DIGITS		    4
#define PASSWORD_check_address	10
#define PASSWORD_save_address	50

#define OPEN_LOCKER				2
#define CLOSE_LOCKER			3

uint8_t lenstr(uint8_t *str);
uint8_t comstr(uint8_t *str1 , uint8_t *str2);

void RESET_password(uint8_t *arr );
void RESTOR_PASSWORD(uint8_t *arr );
void SEARCH_PASSWORD(uint8_t *arr);
void CHECK_entered_password(uint8_t *arr , uint8_t *state);
void new_password(uint8_t *arr);
void SAVE_paswword(uint8_t *new,uint8_t *pass);
void SHOW_password(uint8_t *arr);

#endif /* PASSWORD_H_ */