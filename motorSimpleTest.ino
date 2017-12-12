

// Left motor
int enA = 10;
int in1 = 9;
int in2 = 8;

// Right motor
int in3 = 7;
int in4 = 6;
int enB = 5;

// Speed
int speedValue = 255;
int delayTime = 3000;

void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
}
void loop()
{
  // Move forward
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,speedValue);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,speedValue);
  delay(delayTime);
  // Move backward
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,speedValue);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);
  analogWrite(enA,speedValue);
  delay(delayTime);
  // Turn left
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,speedValue);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,0);
  delay(delayTime);
   // Turn right
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,0);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(enA,speedValue);
  delay(delayTime);
  // Turn off motors
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(delayTime);
}
  
