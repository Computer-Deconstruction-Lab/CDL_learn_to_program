//Copy_Cat_Light
//Snapino (Elenco 6SCU31) - Project 10: Copy Cat Light
//
//Uses the Project 8 circuit with the R4 and Q4 locations swapped (so Q4
//connects to the 5-snap wire). Red LED (D1) on digital pin 9, divider
//into A0. Place the circuit in a bright room. Block the light to the
//phototransistor with your hand; when you uncover it, the red LED will
//be on for as long as the phototransistor was covered.
//
//Programming note from the manual: "This program uses a counter to keep
//track of how long you cover the phototransistor. The longer you cover
//it, the higher the counter gets. Once the phototransistor is uncovered,
//the LED will turn on, and the program will start subtracting from the
//counter. This can count backwards until the counter is equal to zero,
//where it would then turn the LED off."
//
//NOTE: this sketch is NOT printed in the manual (page 21 only describes
//it). The code below is a reconstruction of that description. Because R4
//and Q4 are swapped, covering the phototransistor makes the A0 reading
//RISE, so "covered" is a reading above the threshold. Adjust THRESHOLD
//for your room lighting.

const int LED = 9;
const int THRESHOLD = 500;      //Above this = phototransistor is covered

int val = 0;
long counter = 0;               //How long the phototransistor has been covered

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(0);          //Read the light level

  if (val > THRESHOLD) {        //Covered: count up, keep the LED off
    ++counter;
    digitalWrite(LED, LOW);
  }
  else if (counter > 0) {       //Uncovered: count back down with the LED on
    --counter;
    digitalWrite(LED, HIGH);
  }
  else {                        //Counter reached zero, turn the LED off
    digitalWrite(LED, LOW);
  }

  delay(10);                    //Sets the time scale for the counter
}
