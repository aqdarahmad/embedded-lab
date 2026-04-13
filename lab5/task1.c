
//Display the message "Welcome" centered on the first line of the screen.


#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 



void send_data(unsigned char data)
{
  PORTB = 0;
  PORTBbits.RB4=1;
  PORTBbits.RB5=0;
  PORTB = PORTB | (data>>4);
  PORTBbits.RB5=1;
  PORTBbits.RB5=0;
  PORTB = PORTB  & 0XF0;
  PORTB = PORTB | (data &  0X0F);
 PORTBbits.RB5=1;
  PORTBbits.RB5=0;

}

void send_cmd(unsigned char cmd)
{
   PORTB = 0;
  PORTBbits.RB4=0;
  PORTBbits.RB5=0;
  PORTB = PORTB | (cmd>>4);
  PORTBbits.RB5=1;
  PORTBbits.RB5=0;
  PORTB = PORTB  & 0XF0;
  PORTB = PORTB | (cmd &  0X0F);
 PORTBbits.RB5=1;
  PORTBbits.RB5=0;
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
   send_cmd(0x80);
    send_data('W');
    send_data('e');
    send_data('l');
    send_data('c');
    send_data('o');
    send_data('m');
    send_data('e');

  while(1)
  {
   
  }  
        

}