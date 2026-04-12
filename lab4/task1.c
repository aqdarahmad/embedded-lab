// blink all leds 500 ms where key0 increase delay by 100ms up to 1000 ms
// key1 decrese delay by 100 ms  dwon to 100 ms

#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 
unsigned int x = 250;
void delay(int x)
{
    for(unsigned int i=0;i<x;i++)
    __delay_ms(1);
}
void main(void) 
{ 
  TRISD = 0XF0H;
  TRISB = 0X00H;
  while(1)

  {
     
    // blink 
    PORTB = 0X00;
    delay(x);
    PORTB = 0XFF;
    delay(x);  
    // key 0 
    PORTD = 0b00000010;
    __delay_ms(1);
    if(PORTDbits.RD7){
      if(x<1000)
       x+=100;
    }
    //key 1
      PORTD = 0b00000001;
       __delay_ms(1);
      if(PORTDbits.RD4)
      {
        if(x>100)
        x -=100;
      }
    

  }  
        

}