void setup() {
  for (int i = 9; i < 12; i++) {
    pinMode(i, OUTPUT);
    }
  Serial.begin(9600);

}

void loop() {
  // when writing this the blue ´strip´ was gone, so blue became ´all´
  // I also shortend the code so A0-A2 is right in the analogRead()
  int redValue = analogRead(A0);
  int greenValue = analogRead(A1);
  int allValue = analogRead(A2);

  delay(10);

  // just a simple serial print
  Serial.print(" the red vaule reads : ");
  Serial.print(redValue);
  Serial.print("  the green value reads : ");
  Serial.print(greenValue);
  Serial.print("  the value of all light is : ");
  Serial.print(allValue);
  Serial.print("\n");

  

}
