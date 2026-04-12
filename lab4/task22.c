
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
void main(void) 
{ 
  TRISD = 0XF0H;
  TRISB = 0X00H;
  while(1)

  {
   
    PORTD = 0b00000001;
    __delay_ms(1);
    // one led
    if(PORTDbits.RD4)
    {
     blink(1);
    }
     // four led
    if(PORTDbits.RD5)
    {
        blink(4);
    }
     // seven led
    if(PORTDbits.RD6)
    {
       blink(7);
    }
   
    PORTD = 0b00000010;
    __delay_ms(1);
       // two led
    if(PORTDbits.RD4)
    {
        blink(2);
    }
      // five led
    if(PORTDbits.RD5)
    {
         blink(5);
    }
      // 8 led
    if(PORTDbits.RD6)
    {
     blink(8);
    }
      // 0 led
    if(PORTDbits.RD7)
    {
      blink(0);
    }
    PORTD = 0b00000100;
    __delay_ms(1);

       // 3 led
    if(PORTDbits.RD4)
    {
     blink(3);
    }
       // 6 led
    if(PORTDbits.RD5)
    {
      blink(6);
    }
       // 9 led
    if(PORTDbits.RD6)
    {
       blink(9);
    }
    

  }  
        

}