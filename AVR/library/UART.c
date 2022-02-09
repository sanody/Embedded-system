/*
 * UART.c
 *
 * Created: 24-Jan-21 10:09:19 AM
 *  Author: Marina
 */ 

#include "UART.h"
#include "lcd.h"

void USART_Init()
{
	UART_DDR &= ~(1<<RX);
	UART_DDR |=  (1<<TX);
	DDRD     |=  (1<<2);        //Max485 enable pin is output
	PORTD    |=  (1<<2);		//Max485 enable pin is high (Transmitter)
	/* Set baud rate */
	UBRRH = (unsigned char)(BAUD_PRESCALLER>>8);
	UBRRL = (unsigned char)BAUD_PRESCALLER;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void USARTsendChar(  char data )
{
	while ( !( UCSRA & (1<<UDRE)) );	/* Wait for empty transmit buffer */
	UDR = data;							/* Put data into buffer, sends the data */
}

void USARTsendString( char* data )
{
	int i=0;
	while (data[i] != '\0' && data[i] != '/')
	{
		USARTsendChar(data[i]);
		i++;
		_delay_ms(10);
	}
	USARTsendChar('/');
}

void DataSend(char* N1,  char* L1 ,  char* N2 , char* L2,  char* N3,  char* L3 , char* N4 ,  char* L4)
{
	USARTsendChar('*');
	_delay_ms(10);
	USARTsendString(N1);
	USARTsendString(L1);
	USARTsendString(N2);
	USARTsendString(L2);
	USARTsendString(N3);
	USARTsendString(L3);
	USARTsendString(N4);
	USARTsendString(L4);
}


unsigned char USARTreceivechar()
{
	while((UCSRA & (1 << RXC)) == 0);		/* Wait for data to be received */
	return UDR;							/* Get and return received data from buffer */
}

char* USARTreceiveString( )
{
	unsigned char charData = USARTreceivechar();
	char* data = "";
	
	while (charData != '/')
	{	strcat(data,charData) ;
		charData = USARTreceivechar();
		_delay_ms(100);
	}
	return data;
}

void DataReceive()
{
	int x = 1 , index = 0 , j = 0, row = 1;
	unsigned char c;
	
	c = USARTreceivechar();
	if(c == '*')
	{
		while (row <= 4)
		{
			c = USARTreceivechar();
			while (c != '/')
			{
				index *= pow(10,j++);
				x = c - '0';
				index += x ;
				c = USARTreceivechar();
			}
			c = USARTreceivechar();
			while (c != '/')
			{
				lcdSendingCharacter(c,row,index++);
				c = USARTreceivechar();
			}
			j = 0;
			index = 0;
			row++;
		}
	}
}


