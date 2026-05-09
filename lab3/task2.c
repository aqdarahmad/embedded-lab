//Turn on 1 led and keep shifting/rotating every 300 ms. Use the keypad so that key "1" increases the
//shifting time by 50 ms, key "0" decreases the shifting time by 50 ms.

unsigned int x=300;
void delay(int x)
{
  for(int i=0;i<x;i++)
    __delay_ms(1);
}
unsigned char led=0x01;

void main(void)
{
  TRISB=0XF0;
  TRISD=0X00;
  while(1)
  {
  PORTD=led;
  delay(x);
  led = led<<1;
  if(led==0)
  led=0x01;
  PORTB=0b00000010;
  __delay_ms(1);
  if(PORTBbits.RB7)
  {
    if(x<1000)
    x+=50;
  }
  PORTB=0b00000001;
    __delay_ms(1);
  if(PORTBbits.RB4)
  {
    if(x>100)
    x-=100;
  }

}
}








void blink(unsigned char n)
{  unsigned char led;
  if(n==0)
  {
    led=0x00;
  }
  else 
  {
    led = (1<<n) - 1;
  }
  portd=led;
  __delay_ms(300);
  portd=0x00;
  __delay_ms(300);
}

void main(void)
{
TRISD=0X00;
TRISB=0XF0;

while(1)
{
  PORTB=0b00000001;
  __delay_ms(5);
  if(PORTBbits.RB4)
  {
    blink(1);
  }
   if(PORTBbits.RB5)
  {
    blink(4);
  }
   if(PORTBbits.RB6)
  {
    blink(7);
  }
   PORTB=0b00000010;
  __delay_ms(5);
  if(PORTBbits.RB4)
  {
    blink(2);
  }
   if(PORTBbits.RB5)
  {
    blink(5);
  }
   if(PORTBbits.RB6)
  {
    blink(8);
  }
   if(PORTBbits.RB7)
  {
    blink(0);
  }

    PORTB=0b00000100;
  __delay_ms(5);
  if(PORTBbits.RB4)
  {
    blink(3);
  }
   if(PORTBbits.RB5)
  {
    blink(6);
  }
   if(PORTBbits.RB6)
  {
    blink(8);
  }

}

}
























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
void main(void) 
{ 
  TRISD = 0X00;
  TRISB=0XF0;
  PORTB=0;
  PORTD=0;
  while(1)
  {
    PORTD = led;
    delay(x);
   
    led = led <<1;
     if(led == 0)
    led = 0x01;
    PORTB = 0b00000001;
        __delay_ms(20);
       
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
        

}