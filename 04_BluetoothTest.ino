char incomingByte; // variable to receive data from the serial port

void setup(){
  Serial.begin(9600); // start serial communication at 9600 bps
}

void loop(){
  if(Serial.available()>0)  // if data is available to read
  {
  incomingByte = Serial.read(); //read it and store it in 'incomingByte'
  Serial.println(incomingByte);
  delay(1); // delay in between reads for stability
  }
}
