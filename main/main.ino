#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
//returns true if all sensors see green, false if a sensor sees white
//SDAnum is pin of this sensor's SDA, SCLnum  is this sensor's SCL pin
bool rgbColor(SDAnum, SCLnum){
  const int threshold = 50;
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  lux = lux/256;
  if (lux > threshold) {
    return false;
  }
  return true;
}



void setup() {
  // put your setup code here, to run once:
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
