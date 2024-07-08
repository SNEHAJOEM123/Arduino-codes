#define MotorSpeed 9
#define LT 4
#define MotorDirection 8
#define Encoder_output_A 2// pin2 of the Arduino
#define Encoder_output_B 3// pin 3 of the Arduino

int SWITCH;
int Count_pulses=0 ;

void setup() {
  Serial.begin(9600);
  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
  pinMode(LT, INPUT);
  pinMode(Encoder_output_A,INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder_output_B,INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A),DC_Motor_Encoder,RISING);
}

void loop() {
  
  SWITCH= digitalRead(LT);
  if(SWITCH==HIGH)
  {    
  digitalWrite(MotorDirection, LOW);
  analogWrite(MotorSpeed,250);
  Serial.println(Count_pulses); 
  }

  else if (SWITCH==LOW)

 {
 
  analogWrite(MotorSpeed,0);
  Count_pulses=0;
  Serial.println(Count_pulses); 
  
 }
}

void DC_Motor_Encoder(){
  int b = digitalRead(Encoder_output_B);
  if(b > 0){
    Count_pulses++;9
  }
  else{
    Count_pulses--;
  }
}




