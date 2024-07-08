#define ENCA D6
#define ENCB D5
#define ENCZ D7
#define LS1 D4

#define PWM D2
#define DIR D1


int PWM_Value= 100;
volatile long pos=0;

// void EncoderData();
volatile long count = 0;
ICACHE_RAM_ATTR void EncoderDataA() 
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
  digitalWrite(DIR,LOW);
  analogWrite(PWM,PWM_Value);
  }
}


// void LimitSwitch();
ICACHE_RAM_ATTR void LimitSwitch()
{
  count=0;
  Bot_Flag = HIGH;
}



void setup() 
{
  Serial.begin(9600);
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
    if(count<5250)
    {
    digitalWrite(DIR,HIGH);
    analogWrite(PWM,PWM_Value);
    Serial.println("Inside WhileLoop");
    }

    analogWrite(PWM,0);
    yield();
  }

    
    
}
