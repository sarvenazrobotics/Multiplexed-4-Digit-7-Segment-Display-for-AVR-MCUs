#include <mega328p.h>
#include <stdio.h>
#include <alcd.h>
#include <delay.h>
#define LED1(x) (x==1 ? (PORTD|=1<<5):(PORTD&=~(1<<5)));

char temp;
void main(void)
{
    #pragma optsize-
    CLKPR=(1<<CLKPCE);
    CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
    #ifdef _OPTIMIZE_SIZE_
    #pragma optsize+
    #endif


 UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (1<<U2X0) | (0<<MPCM0);
  UCSR0B=(1<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
  UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
  UBRR0H=0x00;
  UBRR0L=0xCF;


lcd_init(16);
DDRD.5=1;
DDRC.0=1;


#asm("sei")

while (1)
      {
        delay_ms(50);
        PORTC.0=!PORTC.0;

      }
}


interrupt [USART_RXC] void usart_rx_isr(void)
{
    temp=UDR0;
    if(temp=='y')
    {
        LED1(1);
    }
    if(temp=='n')
    {
       LED1(0);
    }
    
    lcd_gotoxy(0,0);
    lcd_putchar(temp);           
}
