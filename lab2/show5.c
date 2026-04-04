// to show 57 on 7 seg 
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

char arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};


void main(void)
{
 TRISA=0X00;
 TRISB=0X00;


    while (1)
    {
       PORTB=arr[5];
       PORTA=0X01;
       __delay_ms(1);
       PORTB=arr[7];
       PORTA=0X02;
       __delay_ms(1);
    }
    return;
}