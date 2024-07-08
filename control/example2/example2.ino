int led1=9;
int led2=7;
int led3=2;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  myCustomLED(led1);
  myCustomLED(led2);
  myCustomLED(led3);
  
}
void myCustomLED(int pin)
{
  digitalWrite(pin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(pin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
  