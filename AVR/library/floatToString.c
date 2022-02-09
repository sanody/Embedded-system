/*
 * floatToString.c
 *
 * Created: 12/6/2020 9:17:31 AM
 *  Author: Marina_Gerges
 */ 

#include "floatToString.h"

void ftoa(double n, char* res, int afterpoint)
{
	char str[10];
	unsigned long int x ,y;
	
	x = ((unsigned  long int)n);
	ultoa(x,res,10);	
	if(afterpoint > 0)
	{
		strcat(res,".");
		y = (unsigned long int)((n-x)*(pow(10,afterpoint)));
		ultoa(y,str,10);
		int length = strlen(str);
		
		if(length != afterpoint )
		for(int i =0 ;i<(afterpoint - length);i++ )
		strcat(res,"0");

		strcat(res,str);
	}
}