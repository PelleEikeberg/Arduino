
// const means that this is a constant. sensorPin will now be READ only.
const int sensorPin = A0;
const float roomTemp = 24.0;

void setup() {
  // this opens a connection between the UNO and the PC.
  // 9600 is bits per second the connection is set to.
  // serial.begin can have one more argument, but its a bit more advanced
  Serial.begin(9600);
  for (int i = 2; i<5; i++) {
    pinMode(i, OUTPUT);
    //the book calls for us to do digitalWrite(i, LOW); here, but we will instead do it in loop
    }
  

}

void loop() {

  // could just set A0 here since we will not use sensorPin anymore
  int ValuePin = analogRead(sensorPin);
  Serial.print("bytes som kommer ut er : ");
  Serial.print(ValuePin);
  
  // the ValuePin is set in 0-1024 since it represents the voltage in max 1kilobyte
  // to get the voltage we take the (ValuePin/1024.00)*5.0 since we are using 5V.
  float voltage = (ValuePin/1024.00)*5.0;
  Serial.print("volt som måles er : ");
  Serial.print(voltage);
  
  // the documentaction of TMP36 says the offset voltage is 0.5 so we
  // subract that then mulityply with 100 becouse 10mV/C is the conversion.
  float temp = (voltage - .5)*100;
  Serial.print("tempratur er : ");
  Serial.print(temp);

  if (temp < roomTemp+2) {
    for (int i = 2; i < 5 ; i++) {
      digitalWrite(i, LOW);
      }
    }
  if (temp > roomTemp+2) {
    digitalWrite(2, HIGH);
    delay(250);
    if (temp > roomTemp+3) {
      digitalWrite(3, HIGH);
      delay(250);
      if (temp > roomTemp+4) {
        digitalWrite(4, HIGH);
        }
      }
    }
   Serial.print("\n");

}
