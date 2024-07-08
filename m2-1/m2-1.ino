#define ENCA D6
#define ENCB D5
#define ENCZ D7
#define LS1 D4

#define PWM D2
#define DIR D1


int PWM_Value= 100;
volatile long pos=0;

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
ICACHE_RAM_ATTR void LimitSwitch()
{
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
  //attachInterrupt(digitalPinToInterrupt(ENCA), EncoderDataA, RISING);
  // attachInterrupt(digitalPinToInterrupt(ENCB), EncoderDataB, RISING)
  attachInterrupt(digitalPinToInterrupt(LS1), LimitSwitch, FALLING);
}

void loop()
{ 
  if(Calibration_Flag==LOW)
  InitialCalibration();

  while(Bot_Flag == HIGH)
  {
    digitalWrite(DIR,LOW);
    analogWrite(PWM,PWM_Value);
    
    Serial.println("Inside WhileLoop");
    delay(1000);
    analogWrite(PWM,0);
    yield();
  }

    
    
}
