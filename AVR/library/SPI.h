/*
 * spi.h
 *
 * Created: 10-Feb-21 11:23:55 AM
 * Author : Marina
 */ 

#ifndef SPI_H_
#define SPI_H_

#include "header.h"

void SlaveSPIinit();
void MasterSPIinit();
void SPIsend(char data);
char SPIrecive();

#endif /* SPI_H_ */
