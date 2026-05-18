//Display the pressed keypad number on LEDs in binary form
//    B0 B1 B2
// B4 1  2  3
// B5 4  5  6
// B6 7  8  9
// B7 *  0  #

void main(void)
{
    TRISD=0X00;//LEDS
    TRISB=0XF0;
    while(1)
    {
        PORTB=0b00000001;
        __delay_ms(10);
        if(PORTBbits.RB4==1)
        {
            PORTD=0b00000001;
            __delay_ms(50);

        }
        if(PORTBbits.RB5==1)
        {
            PORTD=0b00000010;
            __delay_ms(50);
        }
        if(PORTBbits.RB6==1)
        {
            PORTD=0b00000100;
            __delay_ms(50);
        }
       
    }

}

unsigned int num=0;
void checkkey()
{ 
    PORTB=0b00000001;
    if(PORTBbits.RB4==1)
    {
        num=1;
    }
    if(PORTBbits.RB5==1)
    {
        num=4;
    }
    if(PORTBbits.RB6==1)
    {
        num=7;
    }
    PORTB=0b00000010;
    if(PORTBbits.RB4==1)
    {
        num=2;
    }
    if(PORTBbits.RB5==1)
    {
        num=5;
    }
    if(PORTBbits.RB6==1)
    {
        num=8;
    }

}
void display(unsigned int num)
{
    PORTD=num;
    __delay_ms(50);
}

// imterrupts and leds 
void __interrupt() isr(void)
{
    if(INTCONbits.RBIF)
    {
         checkkey();
    }
    INTCONbits.RBIF=0;
}


void main()
{
    INTCONbits.GIE=1;
    INTCONbits.RBIE=1;
    TRISD=0X00;
    TRISB=0xF0;
    while(1)
    {
          display(num);
    }

}
