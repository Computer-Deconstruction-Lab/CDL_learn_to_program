//Bicolor_Light
//Snapino (Elenco 6SCU31) - Project 7: Bicolor Light
//Transcribed from the Snapino Instruction Manual, page 20.
//
//The red/yellow bicolor LED (D10) has red and yellow LEDs connected in
//opposite directions. The sketch alternates digital pins 9 and 10 HIGH
//and LOW, so that electricity flows out of one and into the other.
//
//Try reducing the delay to 100 to make it change colors faster. Next,
//reduce the delay to 10 - so fast that red and yellow blend into orange.

int delay1 = 1000;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(delay1);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(delay1);
}
