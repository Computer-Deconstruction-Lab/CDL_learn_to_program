//Button
//Snapino (Elenco 6SCU31) - Project 6: Button
//Transcribed from the Snapino Instruction Manual, page 19.
//
//This sketch monitors the voltage between the 10K resistor (R4) and the
//press switch (S2); normally the resistor pulls the voltage high, but
//pushing the switch pulls it low. Snapino monitors the voltage and turns
//off the red LED when it receives a low signal from the button.
//
//Swap the locations of the press switch and the 10K resistor to make the
//red LED turn on when the press switch is pushed instead.

const int ledPin = 10;
const int button = 9;
int buttonState  = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);   //Read the value from the button

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);        //If the value is high (button not pushed), turn the LED on
  }
  else {
    digitalWrite(ledPin, LOW);         //If anything else happens, turn the LED off
  }
}
