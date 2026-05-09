// rotate stepper motor 1/8 rotation full step

// half step = 4096 
// full step = 2048 
// number of iteration = 2048/8/4 = 64
// number of iteration if it was half step = 4096/8/8 



void main(void)
{
    TRISB=0X00;
    for(unsigned int i=0;i<64;i++)
     { 
         PORTB=0b00001000;
         __delay_ms(20);
         PORTB=0b00010000;
            __delay_ms(20);
            PORTB=0b00100000;
            __delay_ms(20);
            PORTB=0b01000000;
            __delay_ms(20);    

     }
     while(1)
     {
        
     }


}