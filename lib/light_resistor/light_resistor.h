#include <Arduino.h>

#define LIGHTSENSOR_PIN A0
//#define INPUT_VOLTAGE 504 // 5.04 volt on the uno multiplied by then since map() works with long
#define INPUT_VOLTAGE 423 // 5.04 volt on the uno multiplied by then since map() works with long
#define REFERENCE_VOLTAGE 500 // 5.0 volt exected

extern int lightIntensity; 

void setupLightIntesnity();

void readLightIntensity();