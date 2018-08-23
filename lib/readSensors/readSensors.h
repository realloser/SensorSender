
// Use on of the given hashes: https://github.com/realloser/SensorHash
#define NODE_HASH "FA24C2A3"

struct SensorData
{
    char node[10];
    float primaryTemperature;
    float secondaryTemperature;
    float humidity;
    float pressure;
    int lightIntensity;
    float batteryVoltage;
};

void setupReadSensors();

struct SensorData getSensorData();