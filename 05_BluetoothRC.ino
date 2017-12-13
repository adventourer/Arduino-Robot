char incomingByte; // variable to receive data from the serial port
int speedValue=120;

// MOTOR PIN ASSIGNMENTS
// Left motor
int enA = 10;  //Remove jumper and plug to outer pin of ENA
int in1 = 9;
int in2 = 8;

// Right motor
int in3 = 7;
int in4 = 6;
int enB = 5;  //Remove jumper and plug to outer pin of ENB


void setup()
{
  Serial.begin(9600); // start serial communication at 9600 bps
  
  // Make motor as output
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);

}

void loop()
{
  if(Serial.available()>0)  // if data is available to read
  {
    incomingByte = Serial.read(); //read it and store it in 'incomingByte'
    
    
    // Move according to BT status

    switch (incomingByte)
    {
      case 'W':
        moveForward();
        Serial.println(incomingByte);
        break;
      case 'D':
        moveRight();
        Serial.println(incomingByte);
        break;
      case 'A':
        moveLeft();
        Serial.println(incomingByte);
        break;
      case 'S':
        moveBack();
        Serial.println(incomingByte);
        break;
     
        
/*
  if (incomingByte=='W')
    moveForward();
    Serial.println(incomingByte);
  if (incomingByte=='D')
    moveRight();
    Serial.println(incomingByte);
  if (incomingByte=='A')
    moveLeft();
    Serial.println(incomingByte);
  if (incomingByte=='S')
    moveBack();
    Serial.println(incomingByte);
*/
    }
  }
}

void moveForward(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,speedValue);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,speedValue);
}

void moveRight(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,0);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,speedValue);
}

void moveLeft(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,speedValue);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,0);
}

void sharpRight(void)
{
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,speedValue);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,speedValue);
}

void sharpLeft(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,speedValue);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);
  analogWrite(enA,speedValue);
}


void moveBack(void)
{
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,speedValue);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);
  analogWrite(enA,speedValue);
}

void moveStop(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}


  
