
// Use on of the given hashes: https://github.com/realloser/SensorHash
#define NODE_HASH "FA24C2A3"

struct SensorData {
    char node[10];
    float primaryTemperatur;
    float secondaryTemperatur;
    float humidity;
    float pressure;
    float lightIntesity;
    float batteryVoltage;
};

void setupReadSensors();

struct SensorData getSensorData();