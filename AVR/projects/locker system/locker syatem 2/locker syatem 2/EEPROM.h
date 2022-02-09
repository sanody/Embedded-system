/*
 * EEPROM.h
 *
 * Created: 12/3/2021 10:35:05 PM
 *  Author: Marina
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "header.h"

uint16_t power(uint8_t num , uint8_t pow );

void EEPROM_write(uint8_t data , uint8_t address);
void EEPROM_write_string(uint8_t string[] , uint8_t address);
void EEPROM_write_number(uint16_t num , uint8_t address);

uint8_t EEPROM_read(uint8_t address);
uint16_t EEPROM_read_number(uint8_t address);
void EEPROM_read_string(uint8_t *string , uint8_t address);

#endif /* EEPROM_H_ */