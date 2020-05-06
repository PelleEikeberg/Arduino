#include <Servo.h>
Servo Myservo;

int Lightmeter;
//setting the low and high to use in the if else later. the meter will give us 0-1023 values.
int Lightlow = 1023; int Lighthigh = 0;

const int ledPin = 13; // this is the om board led we will "ping" when calibation is complete

//setting wich pins are where:
int const Lightpin = A0;
int const Therapin = 8;



void setup() {
  // put your setup code here, to run once:

  // sets the onbard to be a output and sets it to light up
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);


  // this is what calibrates. this is the biggest code part of this task
  // it runs through the while for 5s and changes the High and Low value
  // to what it senses in the room.
  while (millis() < 5000) {
    Lightmeter = analogRead(Lightpin);
    if (Lightmeter > Lighthigh) {
      Lighthigh = Lightmeter; 
      }
    if (Lightmeter < Lightlow) {
      Lightlow = Lightmeter;
      }
    }
  // sets the onboard low so we know the calibration is complete
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Lightmeter = analogRead(Lightpin);
  // the same as task 05. we map low to high in the 50-4000 spectrum, since this is the freq we want to genrate.
  int pitch = map(Lightmeter, Lightlow, Lighthigh, 50, 4000);
  // makes the freq for 20 millisec on pin 8 (the theramin)
  tone(Therapin,pitch,20);

  // so we can make some consistent sounds. 
  delay(10);

}
