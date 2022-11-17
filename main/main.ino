#include "drivecode.h"
#include "rgbsensorcode.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"
RGBSensor rgb = new RGBSensor();

void setup() {
  Serial.begin(9600);
  rgb.isConnected();
}


void loop() {
  // put your main code here, to run repeatedly:
  rgb.printResults();
}
