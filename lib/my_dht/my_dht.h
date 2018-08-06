#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

extern float dhtHum;  //Stores humidity value
extern float dhtTemp; //Stores temperature value

void setupDHT();

void readDHT();