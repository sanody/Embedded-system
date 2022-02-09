/*
 * keybad.c
 *
 * Created: 12/2/2021 2:16:23 AM
 *  Author: Marina
 */ 


#include "keybad.h"

const uint8_t matrix[] = {'7','8','9','/' , '4','5','6','*' , '1','2','3','-' , 'c','0','=','+' };

void KEYPAD_init(void)
{
	KEYBAD_init_();	
	BUZZER_init();
}

uint8_t KEYPAD_read(void)
{
	uint8_t i = 0 ;
	static uint8_t flag = 0 ;

	for(;i<4;i++)
	{	
		if(flag == 0 )
		{	switch(i)
			{
				case 0:  KP0(0); KP1(1); KP2(1) ; KP3(1); break;
				case 1:  KP0(1); KP1(0); KP2(1) ; KP3(1); break;
				case 2:  KP0(1); KP1(1); KP2(0) ; KP3(1); break;
				case 3:  KP0(1); KP1(1); KP2(1) ; KP3(0); break;
			}
		}
		if((KP4 == 0)&&(flag == 0)) { flag = 1 ; return matrix[ 0 + i*4 ] ;}
		if((KP5 == 0)&&(flag == 0)) { flag = 1 ; return matrix[ 1 + i*4 ] ;}
		if((KP6 == 0)&&(flag == 0)) { flag = 1 ; return matrix[ 2 + i*4 ] ;}
		if((KP7 == 0)&&(flag == 0)) { flag = 1 ; return matrix[ 3 + i*4 ] ;}		 
		
		if(flag)
		{
			BUZZER(1);
			_delay_ms(100);
			BUZZER(0);
		}
		if((KP4 == 1) && (KP5 == 1) && (KP6 == 1) && (KP7 == 1))
			flag = 0;
		
		_delay_ms(1);
	}
	return '@';
}

