
int switchState = 0;

void setup() {
  pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); 
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2); 

  if (switchState == HIGH) {
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW); digitalWrite(3, LOW);
    }
}
