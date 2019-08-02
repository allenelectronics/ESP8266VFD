// J. Allen August 2019
// This is an ESP8266 project which takes the time from the NIST Internet Time Service and outputs over Serial to a VFD Display
// This is designed to interface with a MAX232 Dual EIA-232 Driver/Receiver. RS232 and TTL levels are not voltage compatible. Damage can occur if these are mixed incorrectly.
// Simple Pin Configuration. TX Pin ----> T2 IN (MAX232) -----> T2 OUT (MAX232) ------> SERIAL IN (VFD)
// Lead Project - https://github.com/jamesdallen91/ESP8266VFD
// ESP8266 Library and Board Installation Instructions - https://github.com/esp8266/Arduino
// Time Library - https://github.com/michaelmargolis/arduino_time


#include <ESP8266WiFi.h>
#include <TimeLib.h>

#define WIFI_NAME "WIFI SSID" // REPLACE WITH YOUR SSID
#define WIFI_PASSWORD "INSERT PASSWORD" // REPLACE WITH YOUR WIFI PASSWORD


const int timeZone = 0; // CHANGE YOUR TIMEZONE 0 = GMT
int HT = 9;
int esc = 27;

void setup() {
  Serial.begin(9600);
  Serial.write(13);
  Serial.print("Connecting... 1.0A");
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
  delay(3000);
  configTime(1 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println();
  Serial.print("Waiting for time");
  while (!time(nullptr));
  Serial.println();
  delay(2000);
 
    }
  }

void loop() {

      time_t now;
      struct tm * timeinfo;
      time(&now);
      timeinfo = localtime(&now);
      Serial.print("      ");
      Serial.printf("%02d", timeinfo->tm_hour);
      Serial.print(":");
      Serial.printf("%02d", timeinfo->tm_min);
      Serial.print(":");
      Serial.printf("%02d", timeinfo->tm_sec);
      Serial.print("      ");
      Serial.print("                    ");
      delay(200);

}
