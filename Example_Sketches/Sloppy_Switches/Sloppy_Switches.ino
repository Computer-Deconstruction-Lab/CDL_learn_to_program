//Sloppy_Switches
//Snapino (Elenco 6SCU31) - Project 19: Sloppy Switches
//Transcribed from the Snapino Instruction Manual, page 29.
//
//Slowly push the press switch (S2) many times, watching the red LED (D1)
//as you do. Usually the LED will turn on or off when you push the switch,
//but sometimes it will stay the same. Do you know why?
//
//When you push the switch its contacts may bounce, sometimes making
//equipment monitoring the switch think it was pressed more than once.
//This effect is called "switch bounce". To prevent this, a small delay is
//normally added to ensure the switch contacts have settled before the
//sketch checks the switch again.
//
//In this sketch the delay(10); command has // in front of it, making it a
//comment that is ignored by the sketch. Remove the //, upload the revised
//sketch, and see if the red LED always changes when you push the switch.

int LEDstate = 0;
int buttonval;
int oldbuttonval;

void setup() {
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  buttonval = digitalRead(9);
  if ((buttonval == LOW) && (oldbuttonval == HIGH)) {
    ++LEDstate;
  }
  oldbuttonval = buttonval;
  if (LEDstate >= 2) {
    LEDstate = 0;
  }
  if (LEDstate == 1) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  //delay(10);
}
