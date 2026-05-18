//Task2: Display the number 50.
// Each time SW0 (RD0) is presses, the displayed number is incremented by 10(up to 90). 
//Each time SW1 (RD1) is presses, the displayed number is decremented by 10 (down to 00). 

char arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};
unsigned int num=5;
void main(void)
{
    TRISB=0X00;
    TRISA=0X00;
    TRISD=0XF0;// KEYBAD
    
    while(1)
    {  

        PORTA=0;
        PORTB=arr[0];
         PORTA=1;
        __delay_ms(1);
         PORTA=0;
        PORTB=arr[num];
         PORTA=2;
        __delay_ms(1);
        if(PORTDbits.RD7)
        {
            if(num<9)
            num++;
        }

         PORTD=0b00000010;
        __delay_ms(1);
        if(PORTDbits.RD4)
        {
            if(num>0)
            num--;
        }
    }


}




























void main()
{
    TRISB=0X00;
    TRISA=0X00;
    TRISDbits.RD0=1;
    TRISDbits.RD1=1;
    unsigned int i=5;
    unsigned char rd0old=0;
    unsigned char rd1old=0;


    while(1)
    {  
        PORTA=0;
        PORTB=arr[0];
         PORTA=1;
        __delay_ms(1);
         PORTA=0;
        PORTB=arr[i];
         PORTA=2;
        __delay_ms(1);

        if(PORTDbits.RD0==1 && rd0old==0)
        {
               if(i<9)
               i++;
        }
        rd0old=PORTDbits.RD0;

            if(PORTDbits.RD1==1 && rd1old==0)
        {
               if(i>0)
               i--;
        }
        rd1old=PORTDbits.RD1;
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
TRISDbits.TRISD0=1;//increment
TRISDbits.TRISD1=1;//decrement
unsigned char rd0old=0;
unsigned char rd1old=0;
unsigned char num=5;


    while (1)
    {

        PORTA=0X00;
        PORTB=arr[num];
        PORTA=0X01;
        __delay_ms(1);
        PORTA=0X00;
        PORTB=arr[0];
        PORTA=0X02;
        __delay_ms(1);

        if(PORTDbits.RD0==1 && rd0old==0)
        {  
           if(num<9)
           num++;
             __delay_ms(2);
        }   
        rd0old =  PORTDbits.RD0;

        if(PORTDbits.RD1==1 && rd1old==0)
        {
          
           if(num>0)
           num--;
           __delay_ms(2);
        }   
        rd1old =  PORTDbits.RD1;



    }
    return;
}