//Light_Monitor
//Snapino (Elenco 6SCU31) - Project 11: Light Monitor
//Transcribed from the Snapino Instruction Manual, page 22.
//
//Opens a window on your computer to display measured data in real time.
//After uploading, click the Tools menu, then pick Serial Monitor. Vary
//the amount of light shining on the phototransistor (Q4) and see how the
//number displayed changes.
//
//The 10K resistor (R4) allows the voltage at the A0 input to fall when it
//is dark and rise when there is light on the phototransistor. The
//measured value will be about 512 when the phototransistor resistance
//equals R4.

const int phototransistor = A0;
int Val = 0;

void setup() {
  Serial.begin(9600);                            //Open terminal window
  pinMode(phototransistor, INPUT);
}

void loop() {
  Val = analogRead(A0);                          //Measure light value

  Serial.print("Measured light value = ");       //Print text
  Serial.println(Val);                           //Print light value
  delay(250);
}
