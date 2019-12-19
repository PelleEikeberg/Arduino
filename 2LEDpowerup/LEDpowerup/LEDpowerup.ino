int switchState = 0;

void setup() {
  // some code to set the states of the programmable pins:
  pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); 
  pinMode(2, INPUT);
  // pinMode(#, INPUT/OUTPUT) where we set the pin and because the pin
  // cannot be both INPUT and output beacuse it can´t both cause a signal and read one

}

void loop() {
  // some code to run and check if the switch is pushed, 
  // if pushed the LEDs should light up 1 after another
  switchState = digitalRead(2); 
  // digitalRead(2) checks the "INPUT" of the pinMode(2, INPUT)
  // it returns LOW/HIGH based if INPUT is reciving power.
  
  if (switchState == LOW) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW); digitalWrite(3, LOW);
    // if the button is not pressed the RED(5) LED is powered on and
    // the rest is left unpowered and therefore not on.
    }

  if (switchState == HIGH) {
    digitalWrite(5, HIGH);
    delay(250);
    if (switchState == HIGH) {
      digitalWrite(4, HIGH);
      delay(250);
      if (switchState == HIGH) {
        digitalWrite(3, HIGH);
        delay(250);
        }
      if (switchState == LOW) {
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW); digitalWrite(3, LOW);
        }
      }
    if (switchState == LOW) {
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW); digitalWrite(3, LOW);
      }
    }

  // multiple if statements that powers on the LED one at a time
  // if the button is released a while in the code, then the same thing happens as if
  // the button was not pressed at all. 

}
