// blink x led where x key is pressed using interrupt
#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 
unsigned int x = 150;
void delay(int x)
{
    for(unsigned int i=0;i<x;i++)
    __delay_ms(1);
}
unsigned int led = 0;

void blink(int led)
{  if(led > 8) led = 8; 
   PORTB = (1<<led) - 1;
    delay(x);
    PORTB = 0x00;
}

void check_key()

{
  

   PORTBbits.RB0=1;
   PORTBbits.RB1=0;
   PORTBbits.RB2=0;
   
   if(PORTBbits.RB4)
   {
       led = 1;
   }
   if(PORTBbits.RB5)
   {
       led = 4;
   }
   if(PORTBbits.RB6)
   {
       led = 7;
   }



   PORTBbits.RB0=0;
   PORTBbits.RB1=1;
   PORTBbits.RB2=0;
   
   if(PORTBbits.RB4)
   {
       led = 2;
   }
   if(PORTBbits.RB5)
   {
       led = 5;
   }
   if(PORTBbits.RB6)
   {
       led = 8;
   }


   PORTBbits.RB0=0;
   PORTBbits.RB1=0;
   PORTBbits.RB2=1;
   if(PORTBbits.RB4)
   {
       led = 3;
   }
   if(PORTBbits.RB5)
   {
       led = 6;
   }
   if(PORTBbits.RB6)
   {
       led = 9;
   }

}

void __interrupt()isr(void)
{
    if(INTCONbits.RBIF == 1)
    {
        check_key();
        INTCONbits.RBIF = 0;
    }
}
void main(void) 
{ 
  TRISD = 0X00H;
  TRISB = 0XF0H;
  INTCONbits.RBIE = 1;
  INTCONbits.GIE = 1;

  while(1)

  {
   
    PORTD = (1<<led) - 1;
    delay(x);
    PORTD = 0x00;
    delay(x);

  }  
        

}