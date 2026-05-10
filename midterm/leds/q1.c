// Turn on LED x while button x is pressed.

void main(void)
{
    TRISB=0X00;
    TRISA=0XFF;
    while(1)
    {
        PORTB=PORTA;
        __delay_ms(50);
    }
}
// Turn on one LED and shift/rotate it each time button 3 is pressed.

void main(void)
{
    TRISB=0X00;
    TRISDbits.TRISD3=1;
    unsigned char oldd3=0;
    unsigned char led=0x01;
    while(1)
    {
        if(PORTDbits.RD3==1 && old3==0)
        {
            PORTB=led;
            __delay_ms(50);
            led=led<<1;
            if(led==0)
            {
                led=0x01;
            }
        }
    }
}
//Toggle all LEDs each time button 1 is pressed. 

void main(void)
{
    TRISB=0X00;
    TRISDbits.TRISD1=1;
    unsigned char old1=0;
    PORTB=0X00;
    while(1)
    {
        if(PORTDbits.RD1==1 && old1==0)
        {
            PORTB=~PORTB;
            __delay_ms(50);
        }
        old1=PORTDbits.RD1;
    }
}
//Make LEDs blink faster each time button 1 is pressed.
unsigned int ms=300;
void mydelay( int ms)
{
    for(unsigned int i=0;i<ms;i++)
    {
        __delay_ms(1);
    }
}

void main(void)
{
    TRISB=0X00;
    TRISDbits.TRISD1=1;
    unsigned char old1=0;

    while(1)
    {  PORTB=0XFF;
        mydelay(ms);
        PORTB=0X00;
        mydelay(ms);
        if(PORTDbits.RD1==1 && old1==0)
        {
            if(ms>50)
            ms -=50;
        }
        old1=PORTDbits.RD1;
    }

}