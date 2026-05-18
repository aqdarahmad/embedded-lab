//Start the DC motor at high speed (duty cycle = 90%).
//Each time Button 0 is pressed, decrease the motor speed by 10% (i.e., decrease the PWM duty cycle by 10%).
//Each time Button 1 is pressed, increase the motor speed by 10% (i.e., increase the PWM duty cycle by 10%).


void main(void)
{
    TRISB=0X00;
    //TRISA=0XFF;
TRISA=0XF0;
    unsigned int time = 90;
    unsigned char rd0old=0;
    unsigned char rd1old=0;
    // with keubad 
    // 

    while(1)
    {  
        PORTBbits.RB1=1;
        __delay_ms(time);
        PORTBbits.RB2=0;
        __delay_ms(100-time);
        PORTA=0b00000001;
        __delay_ms(1);
        if(PORTDbits.RB4)
        {
            if(time>10)
            time -=10;
        }
        if(PORTDbits.RD1===1 && rd1old==0)
        {
            if(time>10)
            time -=10;
        }
        rd1old = PORTDbits.RD1;
        if(PORTDbits.RD0===1 && rd0old==0)
        {
            if(time<90)
            time +=10;
        }
        rd0old = PORTDbits.RD0;

    }
}