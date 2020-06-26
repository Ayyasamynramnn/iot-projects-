#include <FirebaseArduino.h>
#include "DHT.h"

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "dht-trial-1.firebaseio.com"
#define FIREBASE_AUTH "advVDutU9hdkMHQP3p7XxQLjKDDhfTHiqrIAWHDj"
#define WIFI_SSID "Prateek" // Change the name of your WIFI
#define WIFI_PASSWORD "qazwsxedc" // Change the password of your WIFI

#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}

void loop() {
 
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Reading temperature as Celsius (the default)
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);
  delay(200);
}
