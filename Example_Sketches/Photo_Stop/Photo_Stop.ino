//Photo_Stop
//Snapino (Elenco 6SCU31) - Project 13: Photo Stop
//
//Uses the Project 12 (Distance Sensor) circuit: red LED (D1) on digital
//pin 11, yellow LED (D10) on digital pin 10, green LED (D2) on digital
//pin 9, phototransistor (Q4) into A0.
//
//The LEDs change colors in a stoplight pattern, with the rate of change
//controlled by the phototransistor (Q4). Vary the amount of light shining
//on the phototransistor; the brighter the light, the faster the LEDs
//change.
//
//NOTE: this sketch is NOT printed in the manual (page 23 only describes
//it). The code below is a reconstruction: it is the Stoplight sequence
//with the delay read from the phototransistor instead of being a fixed
//constant. In this circuit a bright light gives a LOW reading, so using
//the reading directly as the delay makes bright light = fast changes.

const int redLED    = 11;
const int yellowLED = 10;
const int greenLED  = 9;
const int phototransistor = A0;
int delay1 = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(phototransistor, INPUT);
}

void loop() {
  delay1 = analogRead(phototransistor);   //Brighter light = smaller value = faster stoplight

  digitalWrite(greenLED, HIGH);           //Turn the green light on
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  delay(delay1);

  digitalWrite(greenLED, LOW);            //Turn the yellow light on
  digitalWrite(yellowLED, HIGH);
  delay(delay1 / 2);                      //Yellow is on for half as long

  digitalWrite(yellowLED, LOW);           //Turn the red light on
  digitalWrite(redLED, HIGH);
  delay(delay1);

  digitalWrite(redLED, LOW);              //Turn the red light off
}
