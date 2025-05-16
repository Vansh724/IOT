#define BLYNK_TEMPLATE_ID "TMPL3R-rbaPWK"
#define BLYNK_TEMPLATE_NAME "Shivam Raj"
#define BLYNK_AUTH_TOKEN "eHwB8DFD5lGnu9d4RtM0PgZN4qFdEPVw"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "shivam";
char pass[] = "12215157";

#define RELAY_PIN D1

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); 
}

void loop() {
  Blynk.run();
}

// Function to control the relay using a virtual pin V1
BLYNK_WRITE(V1) {
  int relayState = param.asInt(); // Get the value from the widget (0 or 1)
  if (relayState == 1) {
    digitalWrite(RELAY_PIN, LOW); // Turn on the relay
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn off the relay
  }
}