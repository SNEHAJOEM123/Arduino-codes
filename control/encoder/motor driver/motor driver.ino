/*Example code for testing the Cytron Technologies 10A Rev 2.0 Motor Driver
 *The code uses only two pins, one for the motor direction (Pin 9) 
 * and one for the motor speed (pin 9). The speed is set using PWM. 
 * This code is meant to be run on the Arduino Uno hardware. 
 */


//Pins used to control direction and speed of the motor. Speed pin should be a pwm pin.
#define MotorDirection 8
#define MotorSpeed 9
#define Encoder_output_A 2 // pin2 of the Arduino
#define Encoder_output_B 3 // pin 3 of the Arduino

int Count_pulses = 0;
int SpeedVal = 0;

void setup() {
 Serial.begin(9600);  
  //Declaration for the pins used, both should be outputs.
  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
  pinMode(Encoder_output_A,INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder_output_B,INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A),DC_Motor_Encoder,RISING);  
}

void loop() {
  
  //Ramps up the speed in the clockwise direction.
  digitalWrite(MotorDirection, LOW);                  //Loop increases the speed slowly until it reaches max speed.
  for(SpeedVal = 0; SpeedVal < 255; SpeedVal++){
      analogWrite(MotorSpeed,SpeedVal);
      Serial.println(Count_pulses);       
      delay(40);
  }
for(SpeedVal = 255; SpeedVal >0; SpeedVal--){
      analogWrite(MotorSpeed,SpeedVal);
      Serial.println(Count_pulses); 
      delay(40);
  }  
  
  analogWrite(MotorSpeed,0);
  //Ramps up the speed in the counter clockwise direction.  
  digitalWrite(MotorDirection, HIGH);                //Loop increases the speed slowly until it reaches max speed.
  for(SpeedVal = 0; SpeedVal < 255; SpeedVal++){
      analogWrite(MotorSpeed,SpeedVal);
      Serial.println(Count_pulses);       
      delay(40);
  } 
  for(SpeedVal = 255; SpeedVal >0; SpeedVal--){
      analogWrite(MotorSpeed,SpeedVal);
      Serial.println(Count_pulses); 
      delay(40);
  }  
  analogWrite(MotorSpeed,0);
    
  
}



void DC_Motor_Encoder(){
  int b = digitalRead(Encoder_output_B);
  if(b > 0){
    Count_pulses++;
  //  Serial.println(Count_pulses);     
  }
  else{
    Count_pulses--;
// Serial.println(Count_pulses);     
    
  }
}


