#include <Wire.h>
float RateRoll, RatePitch, RateYaw;
float RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
float AccX,AccY,AccZ;
float RateCalibrationAccX,RateCalibrationAccY,RateCalibrationAccZ;
int RateCalibrationNumber;
void gyro_signals(void) {
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission(); 
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission(); 
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
  
  
}

void accelerometer_signals(void){
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission(); 
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);
  int16_t AccX = (Wire.read() << 8 | Wire.read());
  int16_t AccY = (Wire.read() << 8 | Wire.read());
  int16_t AccZ = (Wire.read() << 8 | Wire.read());
  AccX=(float)AccX/16384.0;
  AccY=(float)AccY/16384.0;
  AccZ=(float)AccZ/16384.0;
}
void setup() {
  Serial.begin(57600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  for (RateCalibrationNumber=0;
         RateCalibrationNumber<2000; 
         RateCalibrationNumber ++) {
    gyro_signals();
    RateCalibrationRoll+=RateRoll;
    RateCalibrationPitch+=RatePitch;
    RateCalibrationYaw+=RateYaw;
    delay(1);
  }
  RateCalibrationRoll/=2000;
  RateCalibrationPitch/=2000;
  RateCalibrationYaw/=2000; 

  for (RateCalibrationNumber=0;
         RateCalibrationNumber<2000; 
         RateCalibrationNumber ++) {
    accelerometer_signals();
    RateCalibrationAccX+=AccX;
    RateCalibrationAccY+=AccY;
    RateCalibrationAccZ+=AccZ;
    delay(1);
  }
  RateCalibrationAccX/=2000;
  RateCalibrationAccY/=2000;
  RateCalibrationAccZ/=2000; 
   
}
void loop() {
  gyro_signals();
  accelerometer_signals();
  RateRoll-=RateCalibrationRoll;
  RatePitch-=RateCalibrationPitch;
  RateYaw-=RateCalibrationYaw;
  AccX-=RateCalibrationAccX;
  AccY-=RateCalibrationAccY;
  AccZ-=RateCalibrationAccZ;
  Serial.print("Roll_offset=");
  Serial.println(RateCalibrationRoll);
  Serial.print("Pitch_offset=");
  Serial.println(RateCalibrationPitch);
  Serial.print("Yaw_offset=");
  Serial.println(RateCalibrationYaw);
  Serial.print("AccX_offset=");
  Serial.println(RateCalibrationAccX);
  Serial.print("AccY_offset=");
  Serial.println(RateCalibrationAccY);
  Serial.print("AccZ_offset=");
  Serial.println(RateCalibrationAccZ);
  
  Serial.print("Roll rate [°/s]= ");
  Serial.println(RateRoll); 
  Serial.print("Pitch Rate [°/s]= ");
  Serial.println(RatePitch);
  Serial.print("Yaw Rate [°/s]= ");
  Serial.println(RateYaw);
  Serial.print("AccX= ");
  Serial.println(AccX);
  Serial.print("AccY= ");
  Serial.println(AccY);
  Serial.print("AccZ= ");
  Serial.println(AccZ);
  delay(50);
}
