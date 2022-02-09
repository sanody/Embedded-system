/*
 * LCD.c
 *
 * Created: 12/2/2021 1:21:23 AM
 *  Author: Marina
 */ 

#include "LCD.h"

void LCD_init(void)
{
	LCD_init_();
		
	LCD_write_command(0x3);
	_delay_ms(3);
	LCD_write_command(0x3);
	_delay_ms(3);
	LCD_write_command(0x3);
	_delay_ms(3);
	LCD_write_command(0x2); // enable 4 bit mode
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01); // Clear display
	LCD_write_command(0x06); // to make courser increment to right
	LCD_write_command(0x0C); // to turn on the display
	_delay_ms(20);
}

void LCD_clear(void)
{
	LCD_write_command(0x1);
	LCD_write_command(0x80);
	_delay_ms(100);	
}

void LCD_write_char(uint8_t data)
{
		RS(1);
		D4(READBIT(data,4));
		D5(READBIT(data,5));
		D6(READBIT(data,6));
		D7(READBIT(data,7));
		EN(1);
		_delay_ms(1);
		EN(0);
		_delay_ms(1);
		
		
		D4(READBIT(data,0));
		D5(READBIT(data,1));
		D6(READBIT(data,2));
		D7(READBIT(data,3));
		EN(1);
		_delay_ms(1);
		EN(0);
		_delay_ms(1);
}

void LCD_write_command(uint8_t com)
{
	RS(0);
	D4(READBIT(com,4));
	D5(READBIT(com,5));
	D6(READBIT(com,6));
	D7(READBIT(com,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	
	D4(READBIT(com,0));
	D5(READBIT(com,1));
	D6(READBIT(com,2));
	D7(READBIT(com,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCD_postion(uint8_t row,uint8_t col)
{
	if(row == 1)
		LCD_write_command(0x80+col-1);
	else if(row == 2)
		LCD_write_command(0xC0+col-1);
	_delay_ms(100);
}

void LCD_write_string(uint8_t *data)
{
	uint8_t i = 0;
	while(data[i] != '\0')
		LCD_write_char(data[i++]);
}

void LCD_write_number(uint16_t num)
{
	uint8_t arr[5] ;
	signed char i = 0;
	if(!num)
	{
		LCD_write_char('0');
		return;
	}
	for(i = 0 ; num != 0 ; i++)
	{
		arr[i] = (num%10)+ '0' ;
		num /= 10;
	}
	i--;
	while (i>-1)
	 LCD_write_char(arr[i--]);
	
}
