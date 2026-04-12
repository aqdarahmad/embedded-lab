// task 2 blink x led every 300 ms where x key is pressed
// المكشله في هاد الكود مش بلينك حقيقي 
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
     PORTB = 0b00000001;
        delay(x);
        PORTB = 0X00;
    }
     // four led
    if(PORTDbits.RD5)
    {
          PORTB = 0b00001111;
        delay(x);
        PORTB = 0X00;
    }
     // seven led
    if(PORTDbits.RD6)
    {
         PORTB = 0b01111111;
        delay(x);
        PORTB = 0X00;
    }
   
    PORTD = 0b00000010;
    __delay_ms(1);
       // two led
    if(PORTDbits.RD4)
    {
        PORTB = 0b00000011;
        delay(x);
        PORTB = 0X00;
    }
      // five led
    if(PORTDbits.RD5)
    {
          PORTB = 0b00011111;
        delay(x);
        PORTB = 0X00;
    }
      // 8 led
    if(PORTDbits.RD6)
    {
    PORTB = 0b11111111;
        delay(x);
        PORTB = 0X00;
    }
      // 0 led
    if(PORTDbits.RD7)
    {
    PORTB = 0b00000000;
        delay(x);
        PORTB = 0X00;
    }





    PORTD = 0b00000100;
    __delay_ms(1);

       // 3 led
    if(PORTDbits.RD4)
    {

    }
       // 6 led
    if(PORTDbits.RD5)
    {

    }
       // 9 led
    if(PORTDbits.RD6)
    {

    }
    

  }  
        

}