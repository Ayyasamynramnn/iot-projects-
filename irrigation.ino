#include <Blynk.h>

/**************************************************************
   Blynk is a platform with iOS and Android apps to control
   Arduino, Raspberry Pi and the likes over the Internet.
   You can easily build graphic interfaces for all your
   projects by simply dragging and dropping widgets.

     Downloads, docs, tutorials: http://www.blynk.cc
     Blynk community:            http://community.blynk.cc
     Social networks:            http://www.fb.com/blynkapp
                                 http://twitter.com/blynk_app

   Blynk library is licensed under MIT license
   This example code is in public domain.

 **************************************************************
   This example runs directly on ESP8266 chip.

   You need to install this for ESP8266 development:
     https://github.com/esp8266/Arduino

   Please be sure to select the right ESP8266 module
   in the Tools -> Board menu!

   Change WiFi ssid, pass, and Blynk auth token to run :)

 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "3e9d548c851e4056b331ad9a31c97ef5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Prateek";
char pass[] = "qazwsxedc";
int sensor = A0; // D4
int pump = 16; // D1
BLYNK_READ(V5)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  Blynk.virtualWrite(V5,sensor);
}
void setup()
{
  Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
  pinMode(sensor, INPUT);
  pinMode(pump,OUTPUT);
}

void loop()
{
  digitalWrite(pump,LOW);
int sensorVal = analogRead(sensor);
Serial.println(sensorVal);
if(sensorVal > 1000)
{
Serial.println("WATER CONTENT IS LOW....ENABLING PUMP");
Blynk.notify("WATER CONTENT IS LOW....ENABLING PUMP");
Blynk.email("prateek.iotclub@gmail.com", "Subject: IOT NOTIFICATION", "WATER CONTENT IS LOW....ENABLING PUMP");
delay(1000);
digitalWrite(pump,HIGH);
}
if(sensorVal < 800)
{
digitalWrite(pump,LOW);
Serial.println("Watering Done");
Blynk.notify("watering done");
Blynk.email("prateek.iotclub@gmail.com", "Subject: IOT NOTIFICATION", "WATER CONTENT IS LOW....ENABLING PUMP");
delay(2000);
}
Blynk.run();
}


