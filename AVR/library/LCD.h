/*
 * LCD.h
 *
 * Created: 12/2/2021 1:21:08 AM
 *  Author: Marina
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "header.h"

#define Lcd_DDR  DDRC
#define Lcd_PORT PORTC

#define LCD_init_()			Lcd_DDR |= 0x3f ;
#define RS(x) if(x == 1)	SETBIT(Lcd_PORT,0); else CLEARBIT(Lcd_PORT,0); 
#define EN(x) if(x == 1)	SETBIT(Lcd_PORT,1); else CLEARBIT(Lcd_PORT,1);
#define D4(x) if(x == 1)	SETBIT(Lcd_PORT,2); else CLEARBIT(Lcd_PORT,2);
#define D5(x) if(x == 1)	SETBIT(Lcd_PORT,3); else CLEARBIT(Lcd_PORT,3);
#define D6(x) if(x == 1)	SETBIT(Lcd_PORT,4); else CLEARBIT(Lcd_PORT,4);
#define D7(x) if(x == 1)	SETBIT(Lcd_PORT,5); else CLEARBIT(Lcd_PORT,5);


void LCD_init(void);
void LCD_write_char(uint8_t ch);
void LCD_write_command(uint8_t com);
void LCD_postion(uint8_t row,uint8_t col);
void LCD_write_string(uint8_t *data);
void LCD_write_number(uint16_t num);
void LCD_clear(void);
#endif /* LCD_H_ */
