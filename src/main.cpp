
#include <Arduino.h>
#include "main.h"
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <my_dht.h>
#include <light_resistor.h>
#include <bmp280.h>
#include <send_data.h>
#include <receive_data.h>
#include <delayAsync.h>
#include <ethernetSender.h>

#define RECIVER true

void setup()
{
  Serial.begin(9600);
  setupDelayAsync(2 * 60);
  setupBMP();
  setupDHT();
  inputVoltage = 503; // 423 volt on the nano on the breadboard
  setupLightIntesnity();
  if (RECIVER)
  {
    setupReceiveData();
  }
  else
  {
    setupSendData();
    sendPing();
  }

  readAllSensors();

  setupEthernet();
}

void readLoop()
{
  if (delayCheck())
  {
    readAllSensors();
  }
}

void loop()
{
  readLoop();

  if (RECIVER)
  {
    loopReceiveData();
  }
  else
  {
    // multiply the readings by factor 100 so we can just send the int.
    // node name, message index, primary temp, humidity, light intensity, voltage if any, secondary temp, air pressure
    sprintf(transmissionMessage, "%s|%i|%i|%i|%i|%i|%i|%lu", NODE_HASH, messageIndex, (int)(dhtTemp * 100), (int)(dhtHum * 100), lightIntensity, -1, (int)(bmpTemperatur * 100), (unsigned long)(bmpPressure * 100));
    sendData();
  }

  loopEthernet();
}


void readAllSensors() {
    readBMP();
    readDHT();
    readLightIntensity();
    Serial.println();
}
