/*
 * password.c
 *
 * Created: 12/3/2021 11:35:42 PM
 *  Author: Marina
 */ 

#include "password.h"
#include "keybad.h"
#include "EEPROM.h"

//uint8_t position = 0;

uint8_t lenstr(uint8_t *str)
{
	uint8_t i = 0;
	for(;str[i] != 0 ; i++);
	return i ;
}

uint8_t comstr(uint8_t *str1 , uint8_t *str2 )
{
	uint8_t size1 = lenstr(str1) , size2 = lenstr(str2) ;  
	if(size1 != size2)
		return 0;
	
	uint8_t i = 0;		
	for (;i<size2 ;i++)
		if(str1[i] != str2[i])
			return 0;
			
	return 1;	
}

void RESTOR_PASSWORD(uint8_t *arr)
{
	uint8_t i = 0;
	for( ; i<PASSOWRD_DIGITS ; i++)
		arr[i] = EEPROM_read(PASSWORD_save_address+i);
}

void SEARCH_PASSWORD(uint8_t *arr)
{
	uint8_t flag[5]={0};
	EEPROM_read_string(flag , PASSWORD_check_address);
	if(comstr(flag , "first"))
		RESTOR_PASSWORD(arr);
	else
		RESET_password(arr);
}

void CHECK_entered_password(uint8_t *arr , uint8_t *state)
{
	uint8_t i = 0 , count = 0;
	uint8_t entered;
	while(i < 4)
	{	entered = KEYPAD_read();
		if(entered == '@') continue;
		LCD_write_char('*',2,1+i);
		if(entered == arr[i++])
			count++;
	}
	if (count == 4)
		*state = OPEN_LOCKER;
	else
	{	LCD_clear();
		*state = CLOSE_LOCKER;
		LCD_write_string("Try Again",1,1);
		_delay_ms(100);
	}
}

void RESET_password(uint8_t *arr)
{
	uint8_t i = 0;
	EEPROM_write_string("nooo",PASSWORD_check_address);
	for(;i < PASSOWRD_DIGITS; i++)
		arr[i] = '0';
}

void new_password(uint8_t *arr)
{
	uint8_t digit_value = 0 , index = 0;
		
	while (index < PASSOWRD_DIGITS)
	{	digit_value = KEYPAD_read();
		if (digit_value>= '0' && digit_value<= '9')
		{	arr[index] = digit_value;
			LCD_write_char(digit_value,2,2+index++);
		}
	}
}

void SAVE_paswword(uint8_t *new,uint8_t *pass)
{
	uint8_t i = 0;
	EEPROM_write_string("first",PASSWORD_check_address);
	for( ; i<PASSOWRD_DIGITS ; i++)
	{	EEPROM_write(new[i] , PASSWORD_save_address+i);
		pass[i] = new[i];
	}
}

void SHOW_password(uint8_t *arr)
{
	for (uint8_t i = 0 ; i < PASSOWRD_DIGITS ; i++)
	{
		LCD_write_char(arr[i],2,2+i);
	}
		
}