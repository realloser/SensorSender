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
    // 423 volt on the nano on the breadboard
    inputVoltage = 423; 
    setupLightIntensity();
}

void readAllSensors()
{
    if (bmpOK)
        readBMP();

    readDHT();
    readLightIntensity();
    Serial.println();
}

struct SensorData getSensorData()
{
    readAllSensors();

    struct SensorData data;
    strcpy(data.node, NODE_HASH);
    data.primaryTemperature = dhtTemp;
    data.humidity = dhtHum;
    data.lightIntensity = lightIntensity;
    data.secondaryTemperature = bmpOK ? bmpTemperature : -1;
    data.pressure = bmpOK ? bmpPressure : -1;
    data.batteryVoltage = -1;

    return data;
}
