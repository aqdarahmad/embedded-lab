// shift the led every 200 ms

#include <xc.h>
#include <pic18f4550.h> 

#pragma config PBADEN	= OFF 
#pragma config FOSC 	= HS
#pragma config PWRT 	= OFF
#pragma config BOR 		= OFF
#pragma config ICPRT 	= OFF
#pragma config LVP 		= OFF
#pragma config WDT 		= OFF
#pragma config DEBUG	= OFF
#pragma config CPUDIV	= OSC1_PLL2	


#define _XTAL_FREQ 16000000  


void main(void)
{
    TRISB=0X00;
    unsigned char led=0x01;



    while (1)
    {
       PORTB=led;
       __delay_ms(200);
       led=led<<1;
       if(led==0)
       led=0x01;
    }
    return;
}
