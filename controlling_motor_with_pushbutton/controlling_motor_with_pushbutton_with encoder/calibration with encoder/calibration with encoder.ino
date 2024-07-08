#define ENCA 2
#define ENCB 3

#define LS1 18

#define PWM 9
#define DIR 8


// void EncoderData();
volatile long count = 0;
void EncoderDataA() 
{
  if(digitalRead(ENCB) == LOW) 
  count--;
  else
  count++; 
}


// void InitialCalibration();
int Calibration_Flag = LOW;
int Bot_Flag = LOW;
int PWM_Value= 100;
void InitialCalibration()
{ 
  Calibration_Flag = HIGH;
  while(Bot_Flag != HIGH)
  {
  Serial.println("Calibration");
  digitalWrite(DIR,HIGH);
  analogWrite(PWM,PWM_Value);
  // Serial.println("Exiting Calibration");
  }
}


// void LimitSwitch();
void LimitSwitch()
{
  count=0;
  Bot_Flag = HIGH;
}



void setup() 
{
  Serial.begin(57600);
  pinMode(ENCA, INPUT_PULLUP); 
  pinMode(ENCB, INPUT_PULLUP); 
  pinMode(LS1, INPUT_PULLUP);
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), EncoderDataA, RISING);
  // attachInterrupt(digitalPinToInterrupt(ENCB), EncoderDataB, RISING)
  attachInterrupt(digitalPinToInterrupt(LS1), LimitSwitch, RISING);
}


void loop()
{ 
  if(Calibration_Flag==LOW)
  InitialCalibration();

  Serial.println("Main Loop");

  while(Bot_Flag = HIGH)
  {
    if(count<10000)
    {
    digitalWrite(DIR,LOW);
    analogWrite(PWM,PWM_Value);
    Serial.println("Inside WhileLoop");
    analogWrite(PWM,0);
    }

    // digitalWrite(DIR,HIGH);
    // analogWrite(PWM,PWM_Value);
    // delay(5000);
  }

    Serial.println("Outside While Loop");
    digitalWrite(DIR,LOW);
    analogWrite(PWM,0);
    
}

