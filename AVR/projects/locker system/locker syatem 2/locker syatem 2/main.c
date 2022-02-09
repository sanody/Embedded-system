/*
 * locker system 2.c
 *
 * Created: 09-Feb-22 11:22:16 AM
 * Author : Marina
 */ 

#include "system.h"

int main(void)
{
    system_init();
    while (1) 
    {
		run_system();
    }
}

