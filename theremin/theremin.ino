///*
//  This projects is a theremin created with two ultrasonic sensors,  one controls the frequency (tone) and the other controls the amplitude (volume).
//  This project is a fork of two projects:
//    - https://create.arduino.cc/projecthub/opus9/theremino-f72d32  (this project had library conflicts)
//    - https://create.arduino.cc/projecthub/jvmccall/ultrasonic-theremin-033d6f  (this project had typo errors in the code and a mistake in the schema)
//  Resource  on controlling similar potentiometer using SPI protocol, provides example code and  electrical setup: http://www.learningaboutelectronics.com/Articles/MCP4131-digital-potentiometer-circuit.php
//*/
//
///*                                                                                                                                                                                                                                               
//  Potentiometer conecctions:
// 1 - Arduino pin ~9
// 2 - Speaker +
// 3 - GND
//  4 - 5V
// 5 - Arduino pin ~10
// 6 - Arduino pin 13
// 7 - Arduino pin ~11
//  8 - GND
// More info https://app.ultralibrarian.com/details/23D04BE7-10A0-11E9-AB3A-0A3560A4CCCC/Microchip/MCP4161-103E-P
//*/
//
////  NewTone is used to avoid the timer incompatibiliy of Tone with NewPing. Download  https://bitbucket.org/teckel12/arduino-new-tone/downloads/ and import .zip
//#include  <NewTone.h>
//#include <NewPing.h>
//#include <SPI.h>
//
//#define MIN_DISTANCE  35 
//
//NewPing sonar(5, 6, 35); // the first and the second number are the pins  of the sensor of volume, the third is the maximum distance
//
//// For SPI
//byte  address = 0x00;
//int CS= 10;
//
//int echo = 3;                            
//int  trigger = 4;
//
//float distance;
//int PotValue;
//
//unsigned long TimeResponse;
//float  distance2;
//float tone1;
//
//void setup() {
//  // set all the pins 
//  Serial.begin(9600);  
//  pinMode(trigger, OUTPUT); // tone sensor                    
//  pinMode(echo,  INPUT); // tone sensor    
//  pinMode (CS, OUTPUT);
//  SPI.begin();
//
//  // this has the speaker emit a start up sound from Low to High to Low
//  digitalPotWrite(255);
//  
//  /*for (int i = 50; i <= 400; i++)
//  {
//    pinMode(9, OUTPUT);       //output for amplification
//    NewTone(9,i);           
//    delay(10);
//  }
//  
//  delay(500);
//  
//  for (int i = 400; i >= 50;  i--)
//  {
//    pinMode(9, OUTPUT);
//    NewTone(9,i);
//    delay(10);
//  } */
//}
//
//void loop() {  
//  digitalWrite(trigger, HIGH);           
//  delayMicroseconds(10);   // creates a 10 microsecond pulse                      
//  digitalWrite(trigger, LOW);                   
//  TimeResponse = pulseIn(echo,  HIGH);  // records how long it took to receive echo of the pulse
//  distance2  = TimeResponse* 0.017;  // calculates distance in centimeters
//
//  if (distance2  < MIN_DISTANCE) { 
//    // conversion of distance into a value for a sound 
//    tone1 = 50.0*pow(2,(distance2/12.0));  // calculate frequency, range of about  50-360 Hz
//    //pinMode(9, OUTPUT);
//    NewTone(9,tone1);
//  } else {
//    pinMode(9, OUTPUT); // this sets the sound to a high pitched noise when no distance  is detected
//    NewTone(9,0);
//  }
// 
//  distance = sonar.ping_cm(); //  uses the library NewPing to calculate distance
//
//  // distance is converted  to Potentiometer relevant values
//  int PotValue = map(distance, 0, 35, 240, 255);  // only use a range of resistance which is very low otherwise the speaker is too  quiet because it is only a 8 ohm speaker
//
//  if (distance == 0) // sets volume  to max when no hand is detected or if hand is too far away
//  {
//    PotValue  = 255;
//  }
//
//  digitalPotWrite(PotValue);
//  delay(10);  
//}
//
//int  digitalPotWrite(int value) {
//  digitalWrite(CS, LOW); // this uses SPI protocol  to communicate with the potentiometer and sets the resistance
//  SPI.transfer(address);
//  SPI.transfer(value);
//  digitalWrite(CS, HIGH);
//}


#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define END -1

const int trigPin = 9;  // Pin connected to the trigger pin of the ultrasonic sensor
const int echoPin = 10; // Pin connected to the echo pin of the ultrasonic sensor
const int speakerPin = 11; // Pin connected to the speaker

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Send a pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  float distance = duration /58;

  int frequency;
//  Serial.print("Distance: ");
 Serial.println(distance);
//  Serial.println(" cm");

  int x = 2.5;
  
    if(distance <= x && distance > 0)
    {
      frequency = NOTE_C6;
    }
    else if(distance <= 2*x && distance > x)
    {
      frequency = NOTE_CS6;
    }
    else if(distance <= 3*x && distance > 2*x)
    {
      frequency = NOTE_D6;
    }
    else if(distance <= 4*x && distance > 3*x)
    {
      frequency = NOTE_DS6;
    }
    else if(distance <= 5*x && distance > 4*x)
    {
      frequency = NOTE_E6;
    }
    else if(distance <= 6*x && distance > 5*x)
    {
      frequency = NOTE_F6;
    }
    else if(distance <= 7*x && distance > 6*x)
    {
      frequency = NOTE_FS6;
    }
    else if(distance <= 8*x && distance > 7*x)
    {
      frequency = NOTE_G6;
    }
    else if(distance <= 9*x && distance > 8*x)
    {
      frequency = NOTE_GS6;
    }
    else if(distance <= 10*x && distance > 9*x)
    {
      frequency = NOTE_A6;
    }
    else if(distance <= 11*x && distance > 10*x)
    {
      frequency = NOTE_AS6;
    }
    else if(distance <= 12*x && distance > 11*x)
    {
      frequency = NOTE_B6;
    }
    else if(distance > 12*x )
    {
      frequency = END;
    }
  
  
  // Calculate frequency based on distance
//  int frequency = map(distance, 0, 100, 200, 1000); // Adjust the range as needed

  // Generate tone on the speaker
  tone(speakerPin, frequency);

  delay(1000); // Delay before taking the next measurement
}
