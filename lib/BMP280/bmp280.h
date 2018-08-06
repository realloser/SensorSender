

// we have to overwite the BPM280 address
#define BMP280_ADDRESS 0x76

extern float bmpTemperatur;
extern float bmpPressure;

void setupBMP();

void readBMP();