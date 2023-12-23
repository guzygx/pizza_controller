#include "Wire.h"
#include "SR04.h"
#include "LSM303.h"
#include "WiFi.h"

// SR04 config
#define TRIG_PIN 5
#define ECHO_PIN 18
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

// Potentiometer config
int potentiometer;

// GY-511 config
LSM303 compass;
float heading;

// ESP Config
String client_id = "esp32-client-" + String(WiFi.macAddress());

void setup() {
  Serial.begin(9600);

  // Initiate compass
  Wire.begin();
  compass.init();
  compass.enableDefault();
  // compass.m_min = (LSM303::vector<int16_t>){ -1616, -1096, -1728 };
  // compass.m_max = (LSM303::vector<int16_t>){ -1205, -662, -1550 };
  compass.m_min = (LSM303::vector<int16_t>){ -668, +207, -800 };
  compass.m_max = (LSM303::vector<int16_t>){ -266, +669, -718 };


}

void loop() {
  compass.read();
  heading = compass.heading();
  potentiometer = analogRead(34);
  distance = sr04.Distance();

  char message[20];
  sprintf(message, "%d %d %d", distance, potentiometer, int(heading));

  Serial.println(message);

  delay(20);
}