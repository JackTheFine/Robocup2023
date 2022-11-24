#include <Wire.h>
#include "Adafruit_TCS34725.h"

int motor1pin1 = 2;
int motor1pin2 = 3;
int spa = 10;
int motor2pin1 = 4;
int motor2pin2 = 5;
int spb = 11;
int motor3pin1 = 6;
int motor3pin2 = 7;
int spc = 12;
int motor4pin1 = 8;
int motor4pin2 = 9;
int spd = 13;
void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  Serial.begin(9600);
}


void foward() {
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
};

void backward() {
  
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  
};

void left() {

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  
}

void right() {
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  
}

void motortest() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  Serial.println("Motor two shoukld be moving");
  delay(1000);//Ari was here...
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  Serial.println("Motor two shoukld be moving");
  delay(1000);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  Serial.println("Motor two shoukld be moving");
  delay(1000);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  Serial.println("Motor two shoukld be moving");
  delay(1000);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
 foward();
 delay(10000);
 backward();
 delay(10000);
 left();
 delay(10000);
 right();
 delay(10000);
}
