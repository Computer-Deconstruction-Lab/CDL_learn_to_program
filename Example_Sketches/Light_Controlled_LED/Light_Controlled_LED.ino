//Light_Controlled_LED
//Snapino (Elenco 6SCU31) - Project 17: Light Controlled LED
//Transcribed from the Snapino Instruction Manual, page 27.
//
//Vary the brightness of light on the phototransistor (Q4) to change the
//brightness of the red LED (D1). The red LED gets brighter as the
//phototransistor gets darker. The circuit acts as a night light, making
//the red LED brighter as the room gets darker.
//
//The light on the phototransistor is measured with analogRead(), then
//1/16 of that value is used for the red LED brightness with
//analogWrite(). The value is divided by 16 because analogRead() returns a
//number between 0 and 1023 while the analogWrite() value must be between
//0 and 255, and because the red LED will appear to be near full
//brightness for values >30.

const int phototransistor = A0;
int lightval;

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  lightval = analogRead(phototransistor);   //Read the value from the phototransistor
  analogWrite(9, lightval / 16);            //Turn on the LED at a certain brightness
  delay(5);                                 //Wait 5 milliseconds
}
