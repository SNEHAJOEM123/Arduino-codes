/*Example code for testing the Cytron Technologies 10A Rev 2.0 Motor Driver
 *The code uses only two pins, one for the motor direction (Pin 9) 
 * and one for the motor speed (pin 9). The speed is set using PWM. 
 * This code is meant to be run on the Arduino Uno hardware. 
 */


//Pins used to control direction and speed of the motor. Speed pin should be a pwm pin.
#define MotorDirection_1 24
#define MotorDirection_2 25
#define MotorDirection_3 51
#define Height_direction 37
#define Height_speed 6
#define MotorSpeed_1 2
#define MotorSpeed_2 3
#define MotorSpeed_3 4
#define forward 36  
#define backward 45
#define up 33
#define down 32

int SpeedVal = 255;

void setup() {
  Serial.begin(9600);
  //Declaration for the pins used, both should be outputs.
  pinMode(forward,INPUT_PULLUP);
  pinMode(backward,INPUT_PULLUP);
  pinMode(MotorDirection_1, OUTPUT);
  pinMode(MotorDirection_2, OUTPUT);
  pinMode(MotorDirection_3, OUTPUT);
  pinMode(MotorSpeed_1, OUTPUT);
  pinMode(MotorSpeed_2, OUTPUT);
  pinMode(MotorSpeed_3, OUTPUT);
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  pinMode(Height_direction,OUTPUT);
  pinMode(Height_speed,OUTPUT);
}

void loop() {
  
  int switchforward=digitalRead(36);
  int switchbackward=digitalRead(45);
//  int switchheight=digitalRead(37);
  int switch_up=digitalRead(33);
  int switch_down=digitalRead(32);
  int switchforward1=digitalRead(36);
  int switchbackward1=digitalRead(45);
  int switchforward2=digitalRead(36);
  int switchbackward2=digitalRead(45);
  int switchforward3=digitalRead(36);
  int switchbackward3=digitalRead(45);

  




  Serial.print("switch forward: ");
  Serial.println(switchforward);
  Serial.print("switch backward: ");
  Serial.println(switchbackward);
  Serial.print("switch Height: ");
  Serial.println(switch_up);
   Serial.println(switch_down);
  Serial.println("\n");

  delay(1000);
  
  if (switchforward==LOW)
  {
     digitalWrite(MotorDirection_1,HIGH);
     digitalWrite(MotorDirection_2,HIGH);
     digitalWrite(MotorDirection_3,HIGH);
     analogWrite(MotorSpeed_1,SpeedVal);
     analogWrite(MotorSpeed_2,SpeedVal);
     analogWrite(MotorSpeed_3,SpeedVal);
     Serial.println("switch forward");
  }
  else if (switchbackward==LOW)
  {
     digitalWrite(MotorDirection_1,LOW);
     digitalWrite(MotorDirection_2,LOW);
     digitalWrite(MotorDirection_3,LOW);
     analogWrite(MotorSpeed_1,SpeedVal);
     analogWrite(MotorSpeed_2,SpeedVal); 
     analogWrite(MotorSpeed_3,SpeedVal); 
     Serial.println("switch back ward"); 
  } 

 else if (switchbackward==HIGH and switchforward==HIGH) 
  {
    analogWrite(MotorSpeed_1,0);
    analogWrite(MotorSpeed_2,0);
    analogWrite(MotorSpeed_3,0);
    Serial.println("stop/halt");
  }

  if (switchforward1==LOW)
  {
     digitalWrite(MotorDirection_1,HIGH);
     analogWrite(MotorSpeed_1,SpeedVal);
     Serial.println("switch forward");
  }
  else if (switchbackward1==LOW)
  {
     digitalWrite(MotorDirection_1,LOW);
     analogWrite(MotorSpeed_1,SpeedVal);
     Serial.println("switch back ward"); 
  } 

 else if (switchbackward1==HIGH and switchforward1==HIGH) 
  {
    analogWrite(MotorSpeed_1,0);
    Serial.println("stop/halt");
  }

 if (switchforward2==LOW)
  {
     digitalWrite(MotorDirection_2,HIGH);
     analogWrite(MotorSpeed_2,SpeedVal);
     Serial.println("switch forward");
  }
  else if (switchbackward2==LOW)
  {
     digitalWrite(MotorDirection_2,LOW);
     analogWrite(MotorSpeed_2,SpeedVal);
     Serial.println("switch back ward"); 
  } 

 else if (switchbackward2==HIGH and switchforward2==HIGH) 
  {
    analogWrite(MotorSpeed_2,0);
    Serial.println("stop/halt");
  }

  if (switchforward3==LOW)
  {
     digitalWrite(MotorDirection_3,HIGH);
     analogWrite(MotorSpeed_3,SpeedVal);
     Serial.println("switch forward");
  }
  else if (switchbackward3==LOW)
  {
     digitalWrite(MotorDirection_3,LOW);
     analogWrite(MotorSpeed_3,SpeedVal);
     Serial.println("switch back ward"); 
  } 

 else if (switchbackward3==HIGH and switchforward3==HIGH) 
  {
    analogWrite(MotorSpeed_3,0);
    Serial.println("stop/halt");
  }





  if (switch_up==LOW and switch_down==HIGH)
  { digitalWrite(Height_direction,HIGH);
    analogWrite(Height_speed,SpeedVal);
    Serial.println("going up");
  }
  else if (switch_up==HIGH and switch_down==LOW)
  { digitalWrite(Height_direction,LOW);
    analogWrite(Height_speed,SpeedVal);
    Serial.println("going down");
  }
  else if (switch_up==HIGH and switch_down==HIGH ) 
  {
   analogWrite(Height_speed,0);
   Serial.println("stop/halt-height");
  }
 
 

}