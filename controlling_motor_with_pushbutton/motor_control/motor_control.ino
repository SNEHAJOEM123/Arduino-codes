#define MotorDirection 8
#define MotorSpeed 9

void setup()
{
  
  Serial.begin(9600);
  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
}

int SpeedVal = 0;

void loop() {
  
  //Ramps up the speed in the clockwise direction.
  digitalWrite(MotorDirection, LOW);
//Loop increases the speed slowly until it reaches max speed.
   for(SpeedVal = 0; SpeedVal < 255; SpeedVal++){
     analogWrite(MotorSpeed,SpeedVal);
      delay(40);
    }
   for(SpeedVal = 255; SpeedVal >0; SpeedVal--){
      analogWrite(MotorSpeed,SpeedVal);
     //Serial.println(Count_pulses); 
      delay(40);
   }  
}
