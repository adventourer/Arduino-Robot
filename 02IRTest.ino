/*
 IR Test
 Reads IR input on pin 11 & 12, prints the result to the serial monitor 
 
 */

// Assign IR input to pins:
int IRRight = 11;
int IRLeft = 12;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the IR pin an input:
  pinMode(IRRight, INPUT);
  pinMode(IRLeft, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int Right = digitalRead(IRRight);
  int Left = digitalRead(IRLeft);
  // print out the state of the button:
  Serial.print("Right = ");
  Serial.print(Right);
  Serial.print(" | Left = ");
  Serial.println(Left);
  delay(1);        // delay in between reads for stability
}



