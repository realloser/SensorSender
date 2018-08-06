#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <DHT.h>
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
float dhtHum;  //Stores humidity value
float dhtTemp; //Stores temperature value

#define LIGHTSENSOR_PIN A0
//#define INPUT_VOLTAGE 504 // 5.04 volt on the uno multiplied by then since map() works with long
#define INPUT_VOLTAGE 423 // 5.04 volt on the uno multiplied by then since map() works with long
#define REFERENCE_VOLTAGE 500 // 5.0 volt exected

int lightIntensityMeasured = 0, lightIntensityMappedValue = 0; // variable to store the value coming from the sensor

void setupLightIntesnity(){
  // nothing to do
}

void readLightIntensity(){
  lightIntensityMeasured = analogRead(LIGHTSENSOR_PIN); // read the value from the sensor
  lightIntensityMappedValue = map(lightIntensityMeasured, 0, INPUT_VOLTAGE, 0, 500); // normalize the sensor reading
  Serial.print("Lightintensity = ");
  Serial.println(lightIntensityMappedValue);
}

void setupDHT() {
  dht.begin();
}

void readDHT() {

  dhtHum = dht.readHumidity();
  dhtTemp= dht.readTemperature();

  Serial.print("Temperature = ");
  Serial.print(dhtTemp);
  Serial.println(" *C");

  Serial.print("Humidity = ");
  Serial.print(dhtHum);
  Serial.println(" %");
}

// we have to overwite the BPM280 address
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp; // I2C

float bmpTemperatur = 0;
float bmpPressure = 0;

void setupBMP(){
  if (!bmp.begin(BMP280_ADDRESS)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    bmpTemperatur = -1;
    bmpPressure = -1;
  }
}

void readBMP() {
  float bmpTemperatur = bmp.readTemperature();
  float bmpPressure = bmp.readPressure();

  Serial.print("Temperature = ");
  Serial.print(bmpTemperatur);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmpPressure);
  Serial.println(" Pa");
}

void setup() {
  Serial.begin(9600);
  setupBMP();
  setupDHT();
  setupLightIntesnity();
}

void loop() {

  readBMP();
  readDHT();
  readLightIntensity();


  Serial.println();
  delay(2000);
}
