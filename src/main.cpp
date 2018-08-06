#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <my_dht.h>
#include <light_resistor.h>
#include <bmp280.h>
#include <send_data.h>

// Use on of the given hashes: https://github.com/realloser/SensorHash
#define NODE_HASH "FA24C2A3"

void setup()
{
  Serial.begin(9600);
  setupBMP();
  setupDHT();
  setupLightIntesnity();
  setupSendData();
  
  sendPing();
}

void loop()
{

  readBMP();
  readDHT();
  readLightIntensity();

  // multiply the readings by factor 100 so we can just send the int.
  // node name, message index, primary temp, humidity, light intensity, voltage if any, secondary temp, air pressure
  sprintf(transmissionMessage, "%s|%i|%i|%i|%i|%i|%i|%lu", NODE_HASH, messageIndex, (int)(dhtTemp * 100), (int)(dhtHum * 100), lightIntensity, -1, (int)(bmpTemperatur * 100), (unsigned long)(bmpPressure * 100));
  sendData();

  Serial.println();
  delay(2000);
}
