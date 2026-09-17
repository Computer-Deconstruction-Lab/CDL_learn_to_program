//Night_Light
//Snapino (Elenco 6SCU31) - Project 8: Night Light
//Transcribed from the Snapino Instruction Manual, page 21.
//
//Cover the phototransistor (Q4) to turn on the red LED (D1).
//
//analogRead(0) measures the voltage at analog pin A0 using a 10-bit
//analog-to-digital converter, and outputs a value from 0 to 1023
//(representing a voltage of 0V to 5V). You can adjust the sensitivity
//by changing 200 to be higher or lower.

const int LED = 9;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(0);              //Read the value of analog pin A0, and assign it to val

  if (val < 200) {
    digitalWrite(LED, HIGH);        //If the value is less than 200, turn the LED on
  }
  else
    digitalWrite(LED, LOW);         //If anything else happens, turn the LED off
}
