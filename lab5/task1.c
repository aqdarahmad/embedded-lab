
//Display the message "Welcome" centered on the first line of the screen.












void send_data(unsigned char data)
{
  portb=0;
  portbbits.rb4=1;
  portb=portb | (data<<4);
  portbbits.rb5=1;
  __delay_ms(40);
  portbbits.rb5=0;
  portb=portb|0xf0;
  portb=portb|(data & 0x0f);
  portbbits.rb5=1;
  __delay_ms(40);
  portbbits.rb5=0;
  __delay_ms(100);
}






void main(void)
{
  TRISB=0X00;
  LCD_init();
  send_cmd(0x80);
  send_data('w');
  send_data('e');
  send_data('l');

}




























#include <xc.h> 
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000
#pragma config PBADEN = OFF
#pragma config FOSC = HS 
#pragma config WDT = OFF
#pragma config LVP = OFF 
data = h= 68 = 0110 1000 
0011 0100
0001 1101
0000 1110
0000 0110
data>>4 

0000 0110 

1 send higher nibble 
portb = 0001 0110 




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