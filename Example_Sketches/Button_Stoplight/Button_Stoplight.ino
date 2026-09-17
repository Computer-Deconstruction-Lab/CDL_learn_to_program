//Button_Stoplight
//Snapino (Elenco 6SCU31) - Project 14: Button Stoplight
//Transcribed from the Snapino Instruction Manual, page 24.
//
//The red LED (D1) should be on; push the press switch (S2) to change
//which LED is on, order is red-yellow-green like a stoplight.
//
//This sketch uses a counter to switch between different LEDs. When the
//button is pressed, it increases the counter by 1. Each LED is activated
//when the counter reaches a certain number. When the counter reaches 4 it
//is reset back to 1.
//
//NOTE: the manual's screenshot is cut off after the "counter == 2" block.
//The remaining blocks below (counter == 3 and the reset at 4) are
//reconstructed from the programming note on the same page.

const int redLED    = 11;
const int yellowLED = 10;
const int greenLED  = 9;
const int button    = A0;
int Val;
int oldVal;
int counter = 3;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  Val = digitalRead(button);                     //Read the value from the button
  if ((Val == HIGH) && (oldVal == LOW)) {        //If Val is HIGH and oldVal is LOW then
    ++counter;                                   //Add to the counter when the button is pressed
  }
  oldVal = Val;
  delay(10);

                                                 //When the counter variable = 1, turn on the red LED
  if (counter == 1) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

                                                 //When the counter variable = 2, turn on the yellow LED
  } if (counter == 2) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

                                                 //When the counter variable = 3, turn on the green LED
  } if (counter == 3) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

                                                 //When the counter reaches 4, reset it back to 1
  } if (counter >= 4) {
    counter = 1;
  }
}
