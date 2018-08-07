
#include <Arduino.h>
#include "main.h"

#include <delayAsync.h>
#include <readSensors.h>
#include <receive_data.h>
#include <ethernetSender.h>


void setup()
{
  Serial.begin(9600);

  setupDelayAsync(2 * 60);

  setupReadSensors();

  setupReceiveData();

  readSensors();

  setupEthernet();
}

void readLoop()
{
  if (delayCheck())
  {
    readSensors();
  }
}

void loop()
{
  readLoop();

  loopReceiveData();

  loopEthernet();
}

void readSensors()
{
  struct SensorData data = getSensorData();
  Serial.print("Primary temperature: "); Serial.println(data.primaryTemperatur);
  Serial.print("Secondary temperature: "); Serial.println(data.secondaryTemperatur);
  Serial.print("Humidity: "); Serial.println(data.humidity);
  Serial.print("Lightintensity: "); Serial.println(data.lightIntesity);
  Serial.print("Barometric pressure: "); Serial.println(data.pressure);
  Serial.print("Battery voltage: "); Serial.println(data.batteryVoltage);
  Serial.println();
}
