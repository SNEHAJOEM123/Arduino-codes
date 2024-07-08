#include <Servo.h>

Servo myservo;
//int pin = 10;
char value;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);

  value=Serial.read();
  Serial.print(value);

  if (value == 'w') {
    for (pos = 0; pos <= 180; pos += 1) {       // goes from 0 degrees to 180 degrees
      myservo.write(pos);                          // tell servo to go to position in variable 'pos'
      delay(15);                                   // waits 30ms for the servo to reach the position
    }
  }
}