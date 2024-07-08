/*
 * The purpose of this code is to count the ouput pulses or 
 * the encoder outputs as you rotate the Motor shaft. You can run the 
 * same code on the Arduino Uno, Arduino Nano, Arduino Mega, etc.
 */
#define Encoder_output_A D6// pin2 of the Arduino
#define Encoder_output_B D5 // pin 3 of the Arduino
// these two pins has the hardware interrupts as well. 
#define ENCZ D7
int Count_pulses = 0;
void setup() {
Serial.begin(9600); // activates the serial communication
pinMode(Encoder_output_A,INPUT); // sets the Encoder_output_A pin as the input
pinMode(Encoder_output_B,INPUT); // sets the Encoder_output_B pin as the input
attachInterrupt(digitalPinToInterrupt(Encoder_output_A),DC_Motor_Encoder,RISING);
}

void loop() {
  //Serial.println("Result: ");
  Serial.println(Count_pulses); 
}

ICACHE_RAM_ATTR void DC_Motor_Encoder(){
  int b = digitalRead(Encoder_output_A);
  if(b > 0){
    Count_pulses++;
  }
  else{
    Count_pulses--;
  }
}




