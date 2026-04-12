//Same as Task2 but using interrupts.

#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 
unsigned char led = 0x01;
unsigned int x = 300;

void delay(int x)
{   
    for(unsigned int i = 0; i < x; i++)
    {
        __delay_ms(1);
    }
}

void check_key()
{ PORTB = 0b00000001;
if(PORTBbits.RB4 == 1)
  {     if(x<1000)
         x=x+50;
        
    }
    PORTB = 0b00000010;
   __delay_ms(20);
    if(PORTBbits.RB7 == 1)
    {   if(x>50)     
         x=x-50;
         
    }
}
void __interrupt()isr(void)
{   if(  INTCONbits.RBIF = 1;){


      check_key();
      INTCONbits.RBIF = 0;

}
   
}


void main(void) 
{ 
  TRISD = 0X00;
  TRISB=0XF0;
  PORTB=0;
  PORTD=0;
  PORTB = 0x0F;

 

 INTCONbits.RBIE = 1;
 INTCONbits.GIE = 1;
  while(1)
  {
    PORTD = led;
    delay(x);
   
    led = led <<1;
     if(led == 0)
    led = 0x01;
   
        __delay_ms(20);
       
    
    
  }  
        

}