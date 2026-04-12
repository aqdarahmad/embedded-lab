//A. TASK 1: Use the keypad so that Key "4" turn on the odd LEDs and Key "6" turn on the even LEDs.
#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 
void main(void) 
{ 
  TRISD = 0X00;
  TRISB=0XF0;
  PORTB=0;
  PORTD=0;
  while(1)
  {
    PORTB = 0b00000001;
    __delay_ms(20);
    if(PORTBbits.RB5 == 1)
    {
       PORTD = 0b10101010; // Odd LEDs
    }
    PORTB = 0b00000100;
     __delay_ms(20);
    if(PORTBbits.RB5 == 1)
    {
         PORTD = 0b01010101; // Even LEDs
    }
  }  
        

}