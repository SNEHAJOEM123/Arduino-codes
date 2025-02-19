#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;

#define INTERRUPT_PIN D8 

bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

volatile bool mpuInterrupt = false;
void ICACHE_RAM_ATTR dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
  Serial.begin(115200);
    //Wire.begin();    
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        //Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);
    devStatus = mpu.dmpInitialize();   

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(-2.56);
    mpu.setYGyroOffset(-0.83);
    mpu.setZGyroOffset(1.15);
    mpu.setZAccelOffset(0); // 1688 factory default for my test chip
    
    if (devStatus == 0) {  
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();  
        mpu.setDMPEnabled(true);
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
}

void loop() {

    if (!dmpReady) return;
    
    while (!mpuInterrupt && fifoCount < packetSize) {}

    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) 
    {
        mpu.resetFIFO();
    } 
    else if (mpuIntStatus & 0x01) 
    {
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        fifoCount -= packetSize;            
            
            // display quaternion values in easy matrix form: w x y z
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
            mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);


            Serial.print("Orientation X: ");
            Serial.print(q.x);
            Serial.print(", Y: ");
            Serial.print(q.y);
            Serial.print(", Z: ");
            Serial.print(q.z);
            Serial.print(", W: ");
            Serial.print(q.w);
            Serial.println("");
          

            Serial.print("Acceleration X: ");
            Serial.print(aaReal.x * 1/16384. * 9.80665);
            Serial.print(", Y: ");
            Serial.print(aaReal.y * 1/16384. * 9.80665);
            Serial.print(", Z: ");
            Serial.print(aaReal.z * 1/16384. * 9.80665);
            Serial.println("");


            Serial.print("Rotation X: ");
            Serial.print(ypr[0]);
            Serial.print(", Y: ");
            Serial.print(ypr[1]);
            Serial.print(", Z: ");
            Serial.print(ypr[2]);
            Serial.println("");

   
            delay(200);         
    }
}
