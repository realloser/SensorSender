#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <bmp280.h>

Adafruit_BMP280 bmp; // I2C

float bmpTemperatur = 0;
float bmpPressure = 0;

void setupBMP()
{
    if (!bmp.begin(BMP280_ADDRESS))
    {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
        bmpTemperatur = -1;
        bmpPressure = -1;
    }
}

void readBMP()
{
    if (bmpPressure == -1){
        Serial.println("BMP280 Sensor not found, restart.");
        return;
    }

    bmpTemperatur = bmp.readTemperature();
    bmpPressure = bmp.readPressure();

    Serial.print("Temperature = ");
    Serial.print(bmpTemperatur);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmpPressure);
    Serial.println(" Pa");
}