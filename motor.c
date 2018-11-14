#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "lcd 23q31.h"
void usart_init();
int main()
{
	char x;
	DDRB=0xff;
	usart_init();
	lcd_init();
	lcd_comm(0x82);
	lcd_string("Rehman-Bot");
	while(1)
	{
		while((UCSRA & (1<<RXC))==0);
		x=UDR;
		if (x=='F')
		{
			PORTA= 0X03;//FORWORD
			PORTB=0X01;
			lcd_comm(0xC2);
			lcd_string("Forward");
			_delay_ms(500);
			lcd_comm(0x01);
		}
		else if(x=='B')
		{
			PORTA= 0X0C;//BAACKWORD
			PORTB=0X01;
			lcd_comm(0xC2);			
			lcd_string("Backward");
			_delay_ms(500);
			lcd_comm(0x01);
		}
		else if(x=='R')
		{
			PORTA= 0X06;//BAACKWORD
			PORTB=0X01;
			lcd_comm(0xC2);
			lcd_string("Right");
			_delay_ms(500);
			lcd_comm(0x01);							
		}
		else if(x=='L')
		{
			PORTA= 0X09;//BAACKWORD
			PORTB=0X01;
			lcd_comm(0xC2);
			lcd_string("Left");
			_delay_ms(500);
			lcd_comm(0x01);
		}
		else if(x=='S')
		{
			PORTA=0x00;
			PORTB=0X00;
			lcd_comm(0xC2);
			lcd_string("Stop");
			_delay_ms(500);
			lcd_comm(0x01);
		}
		
	}
}
void usart_init()
{
	UBRRL=103;
	UCSRB=UCSRB|(1<<RXEN);
	UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}