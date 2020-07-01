const int switchPin = 9;
// unsigned long means the most positive numbers a variable can store
unsigned long prevTime = 0;

// sets the vars to be used 
int switchState = 0;
int prevState = 0;

// here its assumed all the lights a after echother starting with led
int led = 3;

// the time one pass is counted as 600 000 is one minutte in ms
unsigned long passes = 1200;


void setup() {
  // sets the lightpins to be output
  for(int i=led; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  sets the swutch to be input
  pinMode(switchPin, INPUT);
}


void loop() {
  // counts the time
  unsigned long currentTime = millis();

  // if we complete one pass, this is enabled.
  if (currentTime - prevTime > passes){
    prevTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }

  // reads the switch
  switchState = digitalRead(switchPin);
  // if the switch has been turned, this comes
  if (switchState != prevState) {
    // restes the led
    led = 2;
    for (int i=led; i < 9; i++) {
      digitalWrite(i, LOW);
    }
    prevTime = currentTime;
  }

  prevState = switchState;
}
