//LED_Brightness_Button
//Snapino (Elenco 6SCU31) - Project 18: LED Brightness Button
//Transcribed from the Snapino Instruction Manual, page 28.
//
//Push the press switch (S2) repeatedly; the red LED (D1) gets brighter
//each time. After the red LED reaches full brightness then it resets and
//starts over.
//
//The red LED brightness is set using the analogWrite() command, which
//uses values from 0 to 255, but incremental increases will be much more
//noticeable between low numbers than between high numbers. Because of
//this, this sketch uses an array to set the red LED brightness in
//multiples of 2, then resets back to minimum.

int LEDstate = 0;
int buttonval = 0;
int oldbuttonval = 0;
int level = 0;
int brightness [] = {1, 2, 4, 8, 16, 32, 64, 128, 255, 0};
                                                    //Set up array with LED brightness values

void setup() {
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  buttonval = digitalRead(9);
  if ((buttonval == LOW) && (oldbuttonval == HIGH)) {
    LEDstate ++;
  }
  oldbuttonval = buttonval;
  if (LEDstate >= 1) {
    LEDstate = 0;
    analogWrite(10, brightness[level]);             //Set LED brightness
    level ++;                                       //Increment array to next value
    if (level >= 10) {                              //Reset array after last value is used
      level = 0;
    }
  }
  delay(10);
}
