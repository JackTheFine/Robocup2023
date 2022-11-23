class RGBSensor {
  #include <Wire.h>
  #include "Adafruit_TCS34725.h"
  
  private double red;
  private double green;
  private double blue;
  private double co; //c
  private double l; //lux
  private double cT; //colortemp
  private Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
  
  
  /* Example code for the Adafruit TCS34725 breakout library */
  
  /* Connect SCL    to SCL (pin 21)
     Connect SDA    to SDA (pin 20)
     Connect VDD    to 3.3V DC
     Connect GROUND to common ground */
  
  /* Initialise with default values (int time = 2.4ms, gain = 1x) */
  // Adafruit_TCS34725 tcs = Adafruit_TCS34725();
  
  /* Initialise with specific int time and gain values */

  public RGBSensor(){}
  
  public void isConnected(){
    if (tcs.begin()) {
      Serial.println("Found sensor");
    } 
    else {
      Serial.println("No TCS34725 found ... check your connections");
    }
  }
  public void printResults() {
      
    uint16_t r, g, b, c, colorTemp, lux;
    tcs.getRawData(&r, &g, &b, &c);
    // colorTemp = tcs.calculateColorTemperature(r, g, b);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);
  
    Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
    Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
    Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
    Serial.println(" ");
   }
}
