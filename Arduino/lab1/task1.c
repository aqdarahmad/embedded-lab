//Connect two leds. Blink one of them every 200ms and the other every 600ms


// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
}

void loop()
{
  
  for(int i=0;i<3;i++)
  {
  digitalWrite(13, HIGH);
     delay(200); 
     digitalWrite(13, LOW);
     delay(200);
  }
  
   digitalWrite(12, HIGH);
     delay(600); 
     digitalWrite(12, LOW);
     delay(600);

}