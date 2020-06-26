
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTPIN D4  
#define DHTTYPE DHT11     // DHT 11

ch  ar auth[] = "d4f5b735103941c0b2dedb316364cd06";

char ssid[] = "Abcayyasamy";
char pass[] = "123456789";

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimeEvent()
{
  float humi = dht.readHumidity();
  float temper = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(humi) || isnan(temper)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  else
  {
    Serial.print("Humidity");
    Serial.print(humi);
    Serial.print("temperature");
    Serial.print(temper);
    Blynk.virtualWrite(V5,humi);
    Blynk.virtualWrite(V6,temper);
    
  }
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimeEvent);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}

