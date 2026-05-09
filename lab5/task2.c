
//Display the sequence A1, B1, C1, ..., F1, updating the display every 300 ms.



char arr[6]={'A','B','C','D','E','F'};

void main()
{
  for(unsigned iny j=0;j<6;j++)
  { send_cmd(0x80);
    send_data(arr[i]);
    send_data('1');
    __delay_ms(300);

  }
}



























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

unsigned char data[6]= {'A','B','C','D','E','F'};
void main(void) 
{ 
  TRISB = 0X00;
  LCD_Init();

  while(1)
  {
    for(unsigned int i=0;i<6;i++)
    {  send_cmd(0x80);
        send_data(data[i]);
        send_data('1');
        __delay_ms(300);
    }
  }  
        

}