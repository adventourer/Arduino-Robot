/*
Simple line follower program using:
- Arduino Uno
- L298N motor driver
- 2 DC motors
- 5 x IR sensor

Created by Asep Nurul Haq.
*/

// MOTOR PIN ASSIGNMENTS
// Left motor
int enA = 10;  //Remove jumper and plug to outer pin of ENA
int in1 = 9;
int in2 = 8;

// Right motor
int in3 = 7;
int in4 = 6;
int enB = 5;  //Remove jumper and plug to outer pin of ENB

// IR PIN ASSIGNMENTS
int MiddleIRPin = 13;
int RightIRPin = 11;
int LeftIRPin = 12;
int RRIRPin = 4; //Most right IR
int LLIRPin =3; // Most left IR
int MiddleIR;
int RightIR;
int LeftIR;
int RRIR;
int LLIR;

// SET VARIABLES
int speedValue = 120;
int halfSpeed = speedValue/2;
int delayValue = 3000;

void setup()
{
  // Make IR as input
  pinMode(RRIRPin, INPUT);
  pinMode(LLIRPin, INPUT);
  pinMode(MiddleIRPin, INPUT);
  pinMode(RightIRPin, INPUT);
  pinMode(LeftIRPin, INPUT);
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
  
// Read value of IR    
RRIR=digitalRead(RRIRPin);
LLIR=digitalRead(LLIRPin);
MiddleIR=digitalRead(MiddleIRPin);
RightIR=digitalRead(RightIRPin);
LeftIR=digitalRead(LeftIRPin);

// Move according to IR status
  if (RRIR==0)
    sharpRight();
  else if (LLIR==0)
    sharpLeft();
  else if ((RightIR==0 && LeftIR ==1)==1)
    moveRight();
  else if ((LeftIR==0 && RightIR==1)==1)
    moveLeft();
  else if ((MiddleIR==0 && LeftIR==1 && RightIR == 1)==1)
    moveForward();
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

/*
void moveBack(void)
{
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,speedValue);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);
  analogWrite(enA,halfSpeed);
}

void moveStop(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
*/

  
