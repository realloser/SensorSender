#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <my_dht.h>
#include <light_resistor.h>
#include <bmp280.h>
#include <send_data.h>
#include <receive_data.h>

#define RECIVER true

// Use on of the given hashes: https://github.com/realloser/SensorHash
#define NODE_HASH "FA24C2A3"

void setup()
{
  Serial.begin(9600);
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
}

// constants won't change:
const long interval = 10 * 1000; // interval at which to read (milliseconds)
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; // will store last delay was updated
unsigned long currentMillis;

bool delayCheck()
{
  // check to see if the delay has passed; that is, if the difference
  // between the current time and last time
  currentMillis = millis();
// Serial.print("Current Mills: "); Serial.println(currentMillis);
// Serial.print("Previous Mills: "); Serial.println(previousMillis);

  if (currentMillis - previousMillis >= interval)
  {
    Serial.println("Delay passed");

    // save the last time delay
    previousMillis = currentMillis;
    return true;
  }
  else
  {
    return false;
  }
}

void readLoop()
{
  if (delayCheck())
  {
    readBMP();
    readDHT();
    readLightIntensity();
    Serial.println();
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
}
