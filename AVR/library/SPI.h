/*
 * spi.h
 *
 * Created: 10-Feb-21 11:23:55 AM
 * Author : Marina
 */ 

#ifndef SPI_H_
#define SPI_H_

#include "header.h"

#define  MOSI   5
#define  SCK    7
#define  MISO   6
#define  SS		4

void SlaveSPIinit();
void MasterSPIinit();
void SPIsend(char data);
char SPIrecive();

#endif /* SPI_H_ */
