//Task#1: display the numbers 00, 01, 02 ,.....00,01,..etc.  Change the number every 300ms
char arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};
void main()
{
   TRISA=0X00;
   TRISB=0X00;
   unsigned int i,j;
   // delay is wrong لانه داخل اللوب ال ديلاي بتكرر مرتين و2*300=600 مو 300
   while(1)
   {
       
      for(i=0;i<10;i++)
      {
         for(j=0;j<150;j++)
         {
            PORTA=0X01;
            PORTB=arr[0];
            __delay_ms(1);
            PORTA=0X02;
            PORTB=arr[i];
            __delay_ms(1);    
           
        

         }
      }
   }
}



























#include <xc.h>
#include <pic18f4550.h> 

#pragma config PBADEN	= OFF 
#pragma config FOSC 	= HS
#pragma config PWRT 	= OFF
#pragma config BOR 		= OFF
#pragma config ICPRT 	= OFF
#pragma config LVP 		= OFF
#pragma config WDT 		= OFF
#pragma config DEBUG	= OFF
#pragma config CPUDIV	= OSC1_PLL2	


#define _XTAL_FREQ 16000000  

char arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};


void main(void)
{

 TRISA=0X00;
 TRISB=0X00;
 unsigned char i,j;

    while (1)
    {
        
       for(i=0;i<10;i++)
       {
        for(j=0;j<150;j++)
        {     PORTA=0;
              PORTB=arr[0];
               PORTA=0X01;
             __delay_ms(1);
             PORTA=0;
             PORTB=arr[i];
             PORTA=0X02;
             __delay_ms(1);
        }
       }
    }
    return;
}