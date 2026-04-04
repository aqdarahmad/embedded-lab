//Task3: Turn on one led (PORTD) and keep shifting/rotating it every 200ms.
// Reverse direction of rotation each time a button connected to RB2 is pressed. 
//Use interrupts.

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


unsigned char led = 0x01;
unsigned char direction = 1; // 1 = left, 0 = right

void __interrupt() isr(void)
{
    if(INTCON3bits.INT2IF == 1)
    {        
             direction = !direction;
              INTCON3bits.INT2IF = 0;
    }
  
}
void main(void)
{

 TRISD = 0X00;
 TRISBbits.TRISB2=1;
 INTCON3bits.INT2IE = 1;
 INTCONbits.GIE = 1;


    while (1)
    {
        
       PORTD = led;
       __delay_ms(200);
       if(direction)
       {
           led = led <<1;
          
          if(led == 0x00)
          led = 0x01;
       }
       else 
       {
          led = led >>1;
          
           if(led == 0)
           led = 0x80;
       }
    }   
    return;
}
