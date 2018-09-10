/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
.


// This is all more or less copy pasted from Blynk. See links above. 

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "Timer.h"


char auth[] = "authorization key from blynk cloud";

char ssid[] = "SSID";
char pass[] = "password";


unsigned long count = millis()/1000;
int pinCoffee = 13;
int pinLed = 12; 

void setup()
{
 
  pinMode(pinCoffee, OUTPUT); 
  pinMode(pinLed, OUTPUT); 
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

// Using the virtual pins is not a necessity with simple project, but can be useful in th efututre if one would want to add an screen or similar. 
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(pinValue == 1)
  { 
    digitalWrite(pinCoffee, HIGH);
  }
  else 
  digitalWrite(pinCoffee, LOW);
  
//Confirmation of value in the serial terminal. 
  Serial.print("V1 button value is: ");  
  Serial.println(pinValue);

}

void loop()
{
  Blynk.run();  //  This is all you actually need 
  if(Blynk.run()) //a led to indicate that Blynk is running. 
  {
     digitalWrite(pinLed, HIGH);
    }
    else
     digitalWrite(pinLed, LOW);
     
  Serial.println(millis()/1000);
  delay(1000);
  
}

