

//4.1 TASK1: ROTATE THE DC MOTOR CLOCKWISE AT A HIGH SPEED (DUTY CYCLE = 84%) FOR 4 SECONDS.
//AFTER THAT, STOP THE MOTOR FOR 2 SECONDS, THEN ROTATE IT COUNTERCLOCKWISE AT A LOW SPEED (DUTY CYCLE = 26%) FOR 4 SECONDS, AND FINALLY STOP THE MOTOR

// dc motor 2 pin 1 2
// 1 0 clockwise
void main(void)
{
    TRISB=0X00;
for(unsigned int i=0;i<40;i++)
{



  POTRBbits.RB1=1;
  __delay_ms(84);
 
  PORTBbits.RB2=0;
  __delay_ms(16);

}
 PORTBbits.RB2=0;
  POTRBbits.RB1=0;
  __delay_ms(2000);

  for(unsigned int i=0;i<40;i++)
{


 PORTBbits.RB2=1;
  __delay_ms(74);

 
 
  PORTBbits.RB1=0;
  __delay_ms(26);
}

}