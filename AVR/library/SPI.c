/*
 * spi.c
 *
 * Created: 10-Feb-21 11:23:46 AM
 * Author : Marina
 */ 

#include "SPI.h"

void SlaveSPIinit()
{
	DDRB &=~((1<<MOSI)|(1<<SCK)|(1<<SS));  
	DDRB |= (1<<MISO);			
	SPCR = (1<<SPE);	
}

void MasterSPIinit()
{

	DDRB  |= (1<<MOSI)|(1<<SCK)|(1<<SS);	// Make MOSI, SCK, SS as Output
	DDRB  &=~(1<<MISO);					    // Make MISO as input
	PORTB &=~(1<<SS);			            // Make SS pin high
	SPCR  |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);	// Enable SPI in master mode & freq = 1/16

}

void SPIsend(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

char SPIrecive()
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);		
}


