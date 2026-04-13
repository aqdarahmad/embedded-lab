//Task 3:
//Display the word "Hi" centered on the second line. Use the buttons as follows:

//SW0: Shift the word one position to the left
//SW1: Shift the word one position to the right
// portd used for sw0 ans sw1

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
  TRISDbits.TRISD0 = 1;
  TRISDbits.TRISD1 = 1;
  int pos = 0xC3;
  int rd0 = 0;
  int rd1 = 0;
  //
    send_cmd(0x01);
    send_cmd(0x80);
    send_data('H');
    send_data('i');
  while(1)
  {
    
    if(PORTDbits.RD0 ==  1 && rd0 == 0)
    {  if(pos > 0xC0)
        pos--;
       

    }
        rd0 = PORTDbits.RD0;
        
      if(PORTDbits.RD1 ==  1 && rd1 == 0)
    {   if(pos < 0xC7)
        pos++;
       
        
    }
        rd1 = PORTDbits.RD1;
        send_cmd(pos);
        send_data('H');
        send_data('i');
      
    
  }  
        

}










