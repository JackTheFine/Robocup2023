#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to SCL (21)
   Connect SDA    to SDA (20)
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

Adafruit_TCS34725 tcs2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);
//for (int i = 0, i < 2, i++){
  if (!tcs1.begin()) {
    Serial.println("sensor 1 broken");
  } 

  if (!tcs1.begin()) {
    Serial.println("sensor 2 broken");
  } 
  // Now we're ready to get readings!
}
void loop(void) {
  uint16_t r1, g1, b1, c1, colorTemp1, lux1;
  uint16_t r2, g2, b2, c2, colorTemp2, lux2;

  tcs1.getRawData(&r1, &g1, &b1, &c1);
  tcs2.getRawData(&r1, &g2, &b2, &c2);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp1 = tcs1.calculateColorTemperature_dn40(r1, g1, b1, c1);
  colorTemp2 = tcs2.calculateColorTemperature_dn40(r2, g2, b2, c2);
  lux1 = tcs1.calculateLux(r2, g2, b2);
  lux2 = tcs2.calculateLux(r2, g2, b2);

  Serial.print("Color Temp1: "); Serial.print(colorTemp1, DEC); Serial.print(" K - ");
  Serial.print("Lux1: "); Serial.print(lux1, DEC); Serial.print(" - ");
  Serial.print("R1: "); Serial.print(r1, DEC); Serial.print(" ");
  Serial.print("G1: "); Serial.print(g1, DEC); Serial.print(" ");
  Serial.print("B1: "); Serial.print(b1, DEC); Serial.print(" ");
  Serial.print("C1: "); Serial.print(c1, DEC); Serial.print(" ");
  Serial.println(" ");
  Serial.print("Color Temp2: "); Serial.print(colorTemp2, DEC); Serial.print(" K - ");
  Serial.print("Lux2: "); Serial.print(lux2, DEC); Serial.print(" - ");
  Serial.print("R2: "); Serial.print(r2, DEC); Serial.print(" ");
  Serial.print("G2: "); Serial.print(g2, DEC); Serial.print(" ");
  Serial.print("B2: "); Serial.print(b2, DEC); Serial.print(" ");
  Serial.print("C2: "); Serial.print(c2, DEC); Serial.print(" ");
  Serial.println(" ");
}
