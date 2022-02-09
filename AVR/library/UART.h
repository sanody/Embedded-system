/*
 * UART.h
 *
 * Created: 24-Jan-21 10:09:55 AM
 *  Author: Marina
 */ 


#ifndef UART_H_
#define UART_H_

#include "kernal.h"
#include <string.h>
#include <stdio.h>
#include <string.h>

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#define UART_DDR   DDRD
#define UART_PORT  PORTD
#define RX		   0
#define TX		   1

void USART_Init(void);
void USARTsendChar(  char data );
void USARTsendString(  char* data );
unsigned char USARTreceivechar( void );
char* USARTreceiveString( void );
void DataSend( char* N1,  char* L1 ,  char* N2 , char* L2,  char* N3,  char* L3 , char* N4 ,  char* L4);

#endif /* UART_H_ */