/*
 * EEPROM.c
 *
 * Created: 12/3/2021 10:35:17 PM
 *  Author: Marina
 */ 

#include "EEPROM.h"

uint16_t power(uint8_t num , uint8_t pow )
{
	uint8_t i = 0 ;
	uint16_t result = 1;
	for (;i<pow;i++)
		result*=num;
	return result;
}

void EEPROM_write(uint8_t data , uint8_t address)
{
	while(READBIT(EECR,EEWE));
	while(READBIT(SPMCR,SPMEN));
	EEAR = address;
	EEDR = data;
	SETBIT(EECR,EEMWE);
	SETBIT(EECR,EEWE);
	
}

void EEPROM_write_string(uint8_t *string , uint8_t address)
{
	uint8_t i = 0;
	while(string[i] != 0)
	{	EEPROM_write(string[i] , address+i);
		i++;
	}
	EEPROM_write(0 , address+i);
}

void EEPROM_write_number(uint16_t num , uint8_t address)
{
	uint8_t i = 0;
	while(num != 0)
	{
		EEPROM_write(num%10 , address+i);
		i++;
		num/=10;
	}
	EEPROM_write('n' , address+i);
}

uint8_t EEPROM_read(uint8_t address)
{
	while(READBIT(EECR,EEWE));
	EEAR = address;
	SETBIT(EECR,EERE);
	return EEDR ;
}

void EEPROM_read_string(uint8_t *string , uint8_t address)
{
	uint8_t data = EEPROM_read(address);
	uint8_t  i   = 0 ;
	
	while(data != 0)
	{	string[i++] = data;
		data = EEPROM_read(address+i);
	}
	string[i] = data;
}

uint16_t EEPROM_read_number(uint8_t address)
{
	uint8_t i = 0 , num = 0;
	uint16_t result = 0;
	num = EEPROM_read(address+i);
	while(num != 'n')
	{
		result += (num * power(10,i)) ;
		i++;
		num = EEPROM_read(address+i);	
	}

	return result;
}
