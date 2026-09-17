//Program Blinking_Light
//Snapino (Elenco 6SCU31) - Project 3: Blinking Light
//Transcribed from the Snapino Instruction Manual, page 15/16.
//
//Circuit: red snap-to-pin wire from the "+" snap into pin 13 on the
//Arduino UNO board of the Snapino module (U31); green LED D2 lights
//on digital pin 13, along with the "L" LED on the UNO board.

void setup() {
  pinMode(13, OUTPUT);        // Set digital pin 13 as an output.
}

void loop() {
  digitalWrite(13, HIGH);     // Set the LED on.
  delay(500);                 // Delay half a second.
  digitalWrite(13, LOW);      // Set the LED off.
  delay(500);                 // Delay half a second.
}
