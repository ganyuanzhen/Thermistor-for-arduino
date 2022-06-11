#include "Thermistor.h"

Thermistor thermo(A0, 3950);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(thermo.temp());
  delay(1000);
}
