#include <Blynk.h>
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  WARNING :
  For this example you'll need Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App project setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include<BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "bb1d766fdf6841399f5c74c93d346347";
char ssid[] = "Boobal";
char pass[] = "boobal123";
float h;
float t;

BLYNK_READ(V6)
{
  Blynk.virtualWrite(V6,h);
  
}
BLYNK_READ(V5)
{
  Blynk.virtualWrite(V5,t);
}
#define DHTPIN 0         

#define DHTTYPE DHT11     // DHT 11


DHT dht(DHTPIN, DHTTYPE);

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth,ssid,pass);

  dht.begin();

  // Setup a function to be called every second
  
}

void loop()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 Blynk.virtualWrite(V5,t);
  Blynk.virtualWrite(V6,h);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("temrature is \n ");
  Serial.print(t);
   Serial.print("humidity is \n");
  Serial.print(h);
  delay(1000);
  Blynk.run();
  
}
