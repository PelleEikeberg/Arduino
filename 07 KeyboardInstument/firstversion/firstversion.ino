//int buttons[6];
// makes an array with 6 int slots

//int button[0] = 2;
// sets array[0] = 2

int notes[] = {262, 294, 330, 349};
// also makes an array, but filles it with the values from the get go

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // the && is used a and in C++. 
  if(keyVal <= 1023 && keyVal >= 1010){
    // the notes[0] will be played if the first button is pressed.
    tone(8, notes[0]);
  }
  else if(keyVal >= 990 && keyVal <= 1010) {
    // the values is chosen from the guide, but is from max to min of the A0 sensor
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }


  else {
    noTone(8);
  }
}
