#define ENCA 2
#define ENCB 3

#define LS1 18

#define PWM 9
#define DIR 8


int PWM_Value= 100;


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
void InitialCalibration()
{ 
  Calibration_Flag = HIGH;
  while(Bot_Flag == LOW)
  {
  Serial.println("Calibration");
  digitalWrite(DIR,HIGH);
  analogWrite(PWM,PWM_Value);
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
  pinMode(LS1, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), EncoderDataA, RISING);
  // attachInterrupt(digitalPinToInterrupt(ENCB), EncoderDataB, RISING)
  attachInterrupt(digitalPinToInterrupt(LS1), LimitSwitch, FALLING);
}


void loop()
{ 
  if(Calibration_Flag==LOW)
  InitialCalibration();

  while(Bot_Flag == HIGH)
  {
    if(count<8000)
    {
    digitalWrite(DIR,LOW);
    analogWrite(PWM,PWM_Value);
    Serial.println("Inside WhileLoop");
    }

    analogWrite(PWM,0);

  }

    
    
}





 