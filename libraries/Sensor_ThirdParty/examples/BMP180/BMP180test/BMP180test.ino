#include <Wire.h>
#include <Adafruit_BMP085.h>

/***************************************************
  This is an example for the BMP085 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit BMP085 Breakout
  ----> https://www.adafruit.com/products/391

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

/**
   Adapted to CubeCell HTCC-AB01 by Mike Cochrane
   Feb 09, 2020

   Hardware Connections:

    CubeCell Pin  BMP180 Board   Function

    Vext          Vin              Power
    GND           GND              Ground
    SDA           SDA              I2C Data
    SCL           SCL              I2C Clock
*/

Adafruit_BMP085 bmp;

void setup() {
  // Vext ON
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
  delay(10);

  // Initialize Serial port
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("-----------------------------------"));
  Serial.println(F("BMP180 - Barometric Pressure Sensor"));
  Serial.println(F("-----------------------------------"));

  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1) {}
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1021 millibars
  // that is equal to 102100 Pascals.
  Serial.print("Real altitude = ");
  Serial.print(bmp.readAltitude(102100));
  Serial.println(" meters");

  Serial.println();
  delay(1000);
}
