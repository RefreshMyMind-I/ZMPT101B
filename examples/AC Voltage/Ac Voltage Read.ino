#include <Arduino.h>
#include "ZMPT101B.h"

ZMPT101B VoltageSensor(A0);

void setup() {
  Serial.begin(9600);
  Serial.print("Calibrating.............do not attach any voltage input right now ");
  VoltageSensor.calibration();
  Serial.println("Done.......Calibrating.");

}

void loop() {
  

double Voltage = VoltageSensor.getVac();
Serial.println("AC Voltage = ");
Serial.println(Voltage);
delay(500);

}