
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

void setupReadSensors(char *nodeName);

struct SensorData getSensorData();