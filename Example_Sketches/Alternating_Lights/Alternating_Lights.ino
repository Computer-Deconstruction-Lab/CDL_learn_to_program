//Alternating_Lights
//Snapino (Elenco 6SCU31) - Project 4: Alternating Lights
//
//Circuit: green LED (D2) on digital pin 9, red LED (D1) on digital pin 10.
//Arduino alternates turning the two LEDs on and off.
//
//NOTE: the manual's screenshot (page 17) is cut off after setup(); the
//loop() below is reconstructed from the project description
//("alternates turning them on and off") and the declared delay value.

int delay1 = 250;             //Set delay value.

void setup()
{
  pinMode(9, OUTPUT);         //Set digital pin 9 as an output.
  pinMode(10, OUTPUT);        //Set digital pin 10 as an output.
}

void loop()
{
  digitalWrite(9, HIGH);      //Turn the first LED on.
  digitalWrite(10, LOW);      //Turn the second LED off.
  delay(delay1);              //Wait.

  digitalWrite(9, LOW);       //Turn the first LED off.
  digitalWrite(10, HIGH);     //Turn the second LED on.
  delay(delay1);              //Wait.
}
