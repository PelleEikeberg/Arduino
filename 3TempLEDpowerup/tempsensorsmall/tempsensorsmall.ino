
// found no way of setting the room temp from the sensor. might need to be configured
const float roomtemp = 25.00;


void setup() {
  for (int i=2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    }
  Serial.begin(9600);

}

void loop() {
  
  int Sensor = analogRead(A0);
  float volt = (Sensor/1024.00)*5.0; // assumes 5V is the input voltage
  float temp = (volt - 0.5)*100.0;
  Serial.print("the temp is : ");
  Serial.print(temp);
  Serial.print(" the room is : ");
  Serial.print(roomtemp);
  Serial.print("\n");

  if (temp > roomtemp+2 && temp < roomtemp+5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }

   else if (temp > roomtemp+5 && temp < roomtemp+8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    }
   else if (temp > roomtemp+8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    }

   else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }

}
