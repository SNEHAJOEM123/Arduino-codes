int temperature=41;

void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
}


void loop()
{
  if (temperature<50 && temperature>10)
  {
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  }
  else if (temperature>50 && temperature<70)
  {
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(8,LOW);
    delay(1000);
  }
  
  
  
}