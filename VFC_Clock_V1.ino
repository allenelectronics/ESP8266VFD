#include <ESP8266WiFi.h>
#include <TimeLib.h>

#define WIFI_NAME "EE-22de33"
#define WIFI_PASSWORD "well-stack-dim"


const int timeZone = 0;
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
  // put your main code here, to run repeatedly:
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
