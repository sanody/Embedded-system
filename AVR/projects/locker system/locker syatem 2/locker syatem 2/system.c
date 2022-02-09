/*
 * system.c
 *
 * Created: 09-Feb-22 11:36:12 AM
 *  Author: Marina
 */ 

#include "system.h"

lockerSystem locker ;

void system_init(void)
{
	LCD_init();
	KEYPAD_init();
	BUZZER_init();
	LOCKER_init();
 	SEARCH_PASSWORD(locker.password);
 	locker.state = close;
 	locker.clear = 1;
	LOCKER(0);
}

void check_state(void)
{
	static uint8_t count = 0;
	uint8_t symbol = KEYPAD_read();
	switch(symbol)
	{
		case '/':
			locker.state = changePassword ;
			count = 0;
			LCD_clear();
		break;
		
		case '*':
			locker.state = close ;
			count = 0;
			LCD_clear();
		break;
		
		case '0':
			count++;
			if (count == 10)
			{	locker.state = reset ;
				count = 0;
				LCD_clear();
			}
		break;
	}
}


void run_system(void)
{

	switch(locker.state)
	{
		case close:
			LOCKER(0);
			LCD_write_string("Enter password",1,1);
			CHECK_entered_password(locker.password ,&locker.state);
			LCD_clear();
		break;
		
		case open:
			LOCKER(1);
			LCD_write_string("open",1,1);
			check_state();
		break;
		
		case changePassword:
			LCD_write_string("New password",1,1);
			new_password(locker.NewPassword);
			locker.state = savePassword ;
			_delay_ms(100);
			LCD_clear();
		break;
		
		case savePassword:
			LCD_write_string("save ?",1,1);
			uint8_t symbol = KEYPAD_read();
			if(symbol == '/')
			{	SAVE_paswword(locker.NewPassword,locker.password);
				locker.state = open;
				LCD_clear();
			}
			else if(symbol == '*')
			{	locker.state = open;
				LCD_clear();
			}
		break;
		
		case reset:
			LCD_write_string("reset password",1,1);
			RESET_password(locker.password);
			locker.state = open;
			LCD_clear();
		break;
	}
}