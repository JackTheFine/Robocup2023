#include "drivecode.h"
#include "rgbsensorcode.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"
RGBSensor rgb = new RGBSensor();

  int motor1pin1 = 1;
int motor1pin2 = 2;

int motor2pin1 = 3;
int motor2pin2 = 4;

int motor3pin1 = 5;
int motor3pin2 = 6;

int motor4pin1 = 7;
int motor4pin2 = 8;
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

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
  rgb.isConnected();
}



void loop() {
  // put your main code here, to run repeatedly:
  rgb.printResults();
}
