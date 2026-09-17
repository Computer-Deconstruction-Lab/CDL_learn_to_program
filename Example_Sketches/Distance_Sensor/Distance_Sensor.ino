//Distance_Sensor
//Snapino (Elenco 6SCU31) - Project 12: Distance Sensor
//Transcribed from the Snapino Instruction Manual, page 23.
//
//This sketch changes which LED is on depending on the amount of light the
//phototransistor is getting. If the light is bright then the green LED
//(D2) will be on, if there is less light then the yellow LED (D10) will
//be on, and if there is low light or no light then the red LED (D1) will
//be on. This can be used to determine the distance something is above it,
//since the object will slowly block out more light the closer it gets to
//the phototransistor.
//
//You can adjust the sensitivity by changing 750 and 150 to be higher or
//lower.

const int redLED    = 11;
const int yellowLED = 10;
const int greenLED  = 9;
const int phototransistor = A0;
int Val = 0;

void setup() {                                //Declare which variables are outputs or inputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(phototransistor, INPUT);
}

void loop() {
  Val = analogRead(phototransistor);          //Read the value of the A0 pin and assign it to Val

  delay(50);

  if (Val >= 750) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);             //If the value is very high, just turn on the red LED
    digitalWrite(greenLED, LOW);
  }

  if ((Val < 750) && (Val > 150)) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);            //If the value is not high or low, just turn on the yellow LED
    digitalWrite(greenLED, LOW);
  }

  if (Val <= 150) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);             //If the value is low, just turn on the green LED
    digitalWrite(greenLED, HIGH);
  }
}
