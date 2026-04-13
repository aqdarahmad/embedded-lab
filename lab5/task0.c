// show HI on LCD 
// port2 connected on portB 

#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 


void send_data(unsigned char data)
{ PORTB = 0X00;
   // RS = 1
   PORTBbits.RB4 = 1;
   PORTBbits.RB5 = 0;
   PORTB = PORTB | (data >> 4);
   // EN = 1
   PORTBbits.RB5 = 1;
   // EN = 0;
   __delay_us(40);
   PORTBbits.RB5 = 0;

   PORTB = PORTB & 0XF0;
   PORTB = PORTB | (data & 0X0F);
     PORTBbits.RB5 = 1;
   // EN = 0;
   __delay_us(40);
   PORTBbits.RB5 = 0;
   __delay_ms(100);
}

void send_cmd(unsigned char cmd)
{  PORTB = 0X00;
    PORTBbits.RB4 = 0;
     PORTBbits.RB5 = 0;
   PORTB = PORTB | (cmd >> 4);
   // EN = 1
   PORTBbits.RB5 = 1;
   // EN = 0;
   __delay_us(40);
   PORTBbits.RB5 = 0;

   PORTB = PORTB & 0XF0;
   PORTB = PORTB | (cmd & 0X0F);
     PORTBbits.RB5 = 1;
   // EN = 0;
   __delay_us(40);
   PORTBbits.RB5 = 0;
   __delay_ms(100);
}

void LCD_Init()
{
  send_cmd(0x30);
  send_cmd(0x20);
  send_cmd(0x28); 
  send_cmd(0x01);
  send_cmd(0x06);
  send_cmd(0x0C); 

}

void main(void) 
{ 
  TRISB = 0X00;
  LCD_Init();
  send_cmd(0x01);
  send_cmd(0x80);
  send_data('H');
  send_data('I');

  while(1)
  {
    
  }  
        

}






