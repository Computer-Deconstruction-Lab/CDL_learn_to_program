//Click_Counter
//Snapino (Elenco 6SCU31) - Project 20: Click Counter
//
//Uses the Project 19 (Sloppy Switches) circuit. The red LED (D1) is not
//used, and may be removed.
//
//This project opens a window on your computer to display how many times
//you pressed a button. When the upload is finished, click on the Tools
//menu, then pick Serial Monitor. Push the press switch (S2) as many times
//as you like; the program displays the current count on your computer
//screen.
//
//Programming note from the manual: "Remove the delay(10); command from
//the sketch (or add // in front to make it a comment, ignored), upload
//the revised sketch, and watch the display as you are pushing the press
//switch. Sometimes the display will show you pushed the switch several
//times when you only pushed it once."
//
//NOTE: this sketch is NOT printed in the manual (page 29 only describes
//it). The code below is a reconstruction: it is the Sloppy_Switches
//switch-reading logic with a running count printed to the serial monitor,
//and the debounce delay left in place so it can be removed as an
//experiment.

int counter = 0;
int buttonval;
int oldbuttonval;

void setup() {
  pinMode(9, INPUT);
  Serial.begin(9600);                                 //Open terminal window
}

void loop() {
  buttonval = digitalRead(9);
  if ((buttonval == LOW) && (oldbuttonval == HIGH)) { //Switch was just pushed
    ++counter;
    Serial.print("Button pushed ");                   //Print text
    Serial.print(counter);                            //Print the count
    Serial.println(" times");
  }
  oldbuttonval = buttonval;
  delay(10);                                          //Remove or comment out to see switch bounce
}
