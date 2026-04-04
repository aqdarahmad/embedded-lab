// shift the led each time RD3 is pressed 
// rd3 is input 
// portb is output 



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
TRISDbits.TRISD3=1;
unsigned char led=0x01;
unsigned char rd3_old=0;


    while (1)
    {
       if(PORTDbit.RD3 == 1 && rd3_old == 0)
       {
        led=led<<1;
        PORTB=led;
        if(led==0)
        led=0x01;
        __delay_ms(200);
       }
       rd3_old=PORTDbits.RD3;
    }
    return;
}

