#include "drivecode.h"
#include "rgbsensorcode.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"
RGBSensor rgb = new RGBSensor();

int m1p1 = 1;
int m1p2 = 2;
int enA = 9;
//motor 2 - right on L298N - front right motor
int m2p1 = 3;
int m2p2 = 4;
int enB = 10;
//motor 3 - left on L298N - back right motor
int m3p1 = 5;
int m3p2 = 6;
int enC = 11;
//motor 4 - right on L298N - back left motor
int m4p1 = 7;
int m4p2 = 8;
int enD = 12;
//speed, angle, and rotation to be varied
double gSpeed;
double gAngle;
double gRotation;

double drivex(double speed, double angle, double rotation) {
  angle = radians(angle);
  return (speed * sin(angle - 45) + rotation );
}

double drivey(double speed, double angle, double rotation) {
  angle = radians(angle);
  return (speed * sin(angle + 45) + rotation );
}


void setup() {
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m3p1, OUTPUT);
  pinMode(m3p2, OUTPUT);
  pinMode(m4p1, OUTPUT);
  pinMode(m4p2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  Serial.begin(9600);
  rgb.isConnected();
}



void loop() {
  // put your main code here, to run repeatedly:
  rgb.printResults();
}
