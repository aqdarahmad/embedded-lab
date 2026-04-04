// Turn on leds each time u pressed portb


//#include <xc.h>
//#include <pic18f4550.h> 

#pragma config PBADEN	= OFF 
#pragma config FOSC 	= HS
#pragma config PWRT 	= OFF
#pragma config BOR 		= OFF
#pragma config ICPRT 	= OFF
#pragma config LVP 		= OFF
#pragma config WDT 		= OFF
#pragma config DEBUG	= OFF
#pragma config CPUDIV	= OSC1_PLL2	


#define _XTAL_FREQ 8000000  
// portb is input and portd is output




void main(void)



{
TRISB=0xFF;
TRISD=0X00;
PORTD=0X00;

    while (1)
    {

       PORTD=PORTB;
       __delay_ms(200);
    }
    return;
}

