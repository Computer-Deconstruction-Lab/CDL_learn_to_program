//Blink_Rate
//Snapino (Elenco 6SCU31) - Project 9: Blink Rate
//
//Uses the Project 8 (Night Light) circuit: red LED (D1) on digital pin 9,
//phototransistor (Q4) and 10K resistor (R4) forming a divider into A0.
//
//The red LED blinks; the darker the room, the faster it blinks. If the
//room is very dark then the red LED may appear to be on continuously.
//Swapping the locations of R4 and Q4 reverses this: brighter light then
//makes the LED blink faster and darkness makes it slower.
//
//NOTE: this sketch is NOT printed in the manual (page 21 only describes
//it). The code below is a reconstruction that produces the described
//behavior: the measured light value is used directly as the blink delay,
//so a low reading (dark room) gives a very short delay.

const int LED = 9;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(0);          //Read the light level, 0 (dark) to 1023 (bright)

  digitalWrite(LED, HIGH);      //Turn the LED on
  delay(val);                   //Darker room = smaller value = faster blink

  digitalWrite(LED, LOW);       //Turn the LED off
  delay(val);                   //Wait the same amount of time again
}
