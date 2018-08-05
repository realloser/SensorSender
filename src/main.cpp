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
  Serial.print(bmpTemperatur);
  Serial.println(" Pa");
}

void setup() {
  Serial.begin(9600);
  setupBMP();
  setupDHT();
}

void loop() {

  readBMP();
  readDHT();


  Serial.println();
  delay(2000);
}
