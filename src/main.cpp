#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <my_dht.h>
#include <light_resistor.h>
#include <bmp280.h>

void setup() {
  Serial.begin(9600);
  setupBMP();
  setupDHT();
  setupLightIntesnity();
}

void loop() {

  readBMP();
  readDHT();
  readLightIntensity();


  Serial.println(bmpPressure);
  delay(2000);
}
