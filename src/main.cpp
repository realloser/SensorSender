
#include <Arduino.h>
#include "main.h"

#include <delayAsync.h>
#include <readSensors.h>
#include <send_data.h>


void setup()
{
  Serial.begin(9600);

  setupSendData();

  setupDelayAsync(2 * 60);

  setupReadSensors();

  readSensors();

}

void readLoop()
{
  if (delayCheck())
  {
    readSensors();

    sendData();
  }
}

void loop()
{
  readLoop();
}

unsigned int messageIndex;
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

      // multiply the readings by factor 100 so we can just send the int.
    // node name, message index, primary temp, humidity, light intensity, voltage if any, secondary temp, air pressure
    sprintf(transmissionMessage, "%s|%i|%i|%i|%i|%i|%i|%lu", 
      NODE_HASH, messageIndex++, (int)(data.primaryTemperatur * 100), (int)(data.humidity * 100), data.lightIntesity,
      -1, (int)(data.secondaryTemperatur * 100), (unsigned long)(data.pressure * 100));

    Serial.println();
    Serial.print("Concatenated: ");
    Serial.println(transmissionMessage);
    Serial.println();
}
