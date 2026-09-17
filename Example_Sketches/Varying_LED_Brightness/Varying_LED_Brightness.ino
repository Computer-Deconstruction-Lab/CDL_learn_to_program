//Varying_LED_Brightness
//Snapino (Elenco 6SCU31) - Project 16: Varying LED Brightness
//Transcribed from the Snapino Instruction Manual, page 26.
//
//The three LEDs (D1, D2, & D10) continuously vary in brightness.
//
//This sketch uses a counter to increase the brightness of the LEDs. Once
//the LED nears full brightness the counter decreases to make the LEDs
//dimmer. analogWrite() simulates an analog voltage using pulse width
//modulation. The value can be from 0 (LED off) to 255 (LED always on);
//this sketch uses a maximum value of 30, because the LED brightness would
//change very slowly for higher values. Try increasing this value from 30
//to 255, upload the sketch, and see how it affects the LED brightness.
//You can also adjust the delay value (currently 30) to make the LED
//brightness change faster or slower.

int lightval = 0;
int counter  = 1;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);                //Declare which variables are outputs.
  pinMode(11, OUTPUT);
}

void loop() {
  if (counter <= 0) {                 //Switch to add to counter.
    lightval = 1;
  }
  if (counter >= 30) {                //Switch to subtract from counter.
    lightval = 0;
  }
  if (lightval == 1) {                //Start adding to the counter.
    ++counter;
  }
  if (lightval == 0) {                //Start subtracting from the counter.
    --counter;
  }
  analogWrite(9, counter);
  analogWrite(10, counter);           //Turn the LEDs on at the value of the counter.
  analogWrite(11, counter);
  delay(30);                          //Wait 30 milliseconds.
}
