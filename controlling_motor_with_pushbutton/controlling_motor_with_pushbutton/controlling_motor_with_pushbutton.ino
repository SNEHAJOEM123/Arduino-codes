#define MotorSpeed 9
#define LT 7
#define MotorDirection 8

int SWITCH=HIGH;

void setup() {

  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
  pinMode(LT, INPUT);
}

void loop() {
  
  SWITCH= digitalRead(LT);
  if(SWITCH==HIGH)
  {
  digitalWrite(MotorDirection, LOW);
  analogWrite(MotorSpeed,250);
  }

  else if (SWITCH==LOW)

 {
 
  analogWrite(MotorSpeed,0);
 }
  }