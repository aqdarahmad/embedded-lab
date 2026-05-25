// التحكم في شده الضاءه 
// C++ code
//
void setup()
{
  pinMode(5,OUTPUT);
    analogWrite(5,64); 
  
  for(int i=0;i<255;i+=5)
  {
  
  analogWrite(5,i);
    delay(100);
  }
 
}

void loop()
{
  
}
///////////
// C++ code
//
void setup()
{
  pinMode(5,OUTPUT);
    analogWrite(5,64); 
  
  for(int i=0;i<255;i+=5)
  {
  
  analogWrite(5,i);
    delay(200);
  }
 
}

void loop()
{
  
}