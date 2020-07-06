#include "DHT.h"
#define DHTPIN 8          // pin digital connectée
#define DHTTYPE DHT11     // DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000);
  float humi = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  if (isnan(humi) || isnan(tempC) || isnan(tempF))
  {
    Serial.println("Echec de la lecture");
    return;
  }

  Serial.print("Humidité: ");Serial.print(humi);Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(tempC);Serial.print(" *C ");
  Serial.print(tempF);Serial.println(" *F");
}
