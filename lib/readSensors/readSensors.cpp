#include <readSensors.h>

#include <my_dht.h>
#include <light_resistor.h>
#include <bmp280.h>
#include <send_data.h>

bool bmpOK;

void setupReadSensors()
{
  bmpOK = setupBMP();
  setupDHT();
  inputVoltage = 503; // 423 volt on the nano on the breadboard
  setupLightIntensity();
}


void readAllSensors() {
    if (bmpOK) readBMP();

    readDHT();
    readLightIntensity();
    Serial.println();
}

struct SensorData getSensorData()
{
    readAllSensors();

    struct SensorData data;
    strcpy(data.node, NODE_HASH);
    data.primaryTemperatur = dhtTemp;
    data.humidity = dhtHum;
    data.lightIntesity = lightIntensity;
    data.secondaryTemperatur = bmpOK ? bmpTemperatur : -1;
    data.pressure = bmpOK ? bmpPressure : -1;

    return data;
}

