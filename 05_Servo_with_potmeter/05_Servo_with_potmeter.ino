#include <Servo.h>
Servo Myservo;

int const potPin = A0;
int potVal;
int angle;
// dette er ting vi deklarerer fordi vi skal bruke de senere
// potPin kunne utelatt men da måtte vi forandre flere linjer senre



void setup() {
  // put your setup code here, to run once:
  Myservo.attach(8); // denne koden lar arduinoen skjønne hvilken utgang som styrer servoern

  Serial.begin(9600);
  // dette er linjen som lager det synslige vinduet vårt. veldig nyttig for debugging


  

}

void loop() {
  // put your main code here, to run repeatedly:

  potVal = analogRead(potPin);
  Serial.print("potval:  ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  // denne linjen er viktig å forstå
  // pottensometeret gir oss 0->1024 verdier og vi vil dele disse opp i
  // 0_> 179 verider fordi servoen vår går til 180 grader. 

  Serial.print("angle:  ");
  Serial.print(angle);
  Serial.print("\n");

  Myservo.write(angle);
  delay(15);

}
