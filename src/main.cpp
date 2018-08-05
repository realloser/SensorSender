#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// we have to overwite the BPM280 address
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp; // I2C

float bmpTemperatur = 0;
float bmpPressure = 0;

void setupBMP(){
  if (!bmp.begin(BMP280_ADDRESS)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    bmpTemperatur = -1;
    bmpPressure = -1;
  }
}

void readBMP() {
  float bmpTemperatur = bmp.readTemperature();
  float bmpPressure = bmp.readPressure();

  Serial.print("Temperature = ");
  Serial.print(bmpTemperatur);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmpTemperatur);
  Serial.println(" Pa");
}

void setup() {
  Serial.begin(9600);
  setupBMP();
}

void loop() {

  readBMP();


  Serial.println();
  delay(2000);
}
