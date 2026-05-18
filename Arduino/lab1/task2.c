// C++ code
//
int x=500;
int b1old=LOW;
int b2old=LOW;
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop()
{
  
  digitalWrite(13, HIGH);
     delay(x); 
     digitalWrite(13, LOW);
     delay(x);
  digitalWrite(12, HIGH);
     delay(x); 
     digitalWrite(12, LOW);
     delay(x);
  int but1=digitalRead(7);
   int but2=digitalRead(8);
  
  
  if(but1 == HIGH && b1old==LOW)
  {
    x+=100;  
  }
  b1old=but1;
   if(but2 == HIGH && b2old==LOW)
  {  if(x>100)
    x-=100;  
  }
  b2old=but2;
  
  

  

}