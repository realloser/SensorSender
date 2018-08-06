// #include <Arduino.h>
// #include <Wire.h>
// #include <SPI.h>
#include <my_dht.h>

#include <DHT.h>
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