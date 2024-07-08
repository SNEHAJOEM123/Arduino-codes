int button=7;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(button));
  if (digitalRead(button)==HIGH)
  {
     digitalWrite(LED_BUILTIN,HIGH);
  } 
  else
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
}