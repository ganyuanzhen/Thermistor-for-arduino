#ifndef Thermistor_h
  #define Thermistor_h
  #include "abbreviation.h"
  #include <math.h>

  #if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif

  class Thermistor 
  {
    public:
      uint8_t pin;
      float BETA;
      float temp();
      Thermistor(uint8_t pin, float BETA);
  };

  float Thermistor::temp() {
    int analogValue = analogRead(pin);
    float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
    return celsius;
  }

  Thermistor::Thermistor(uint8_t _pin, float _BETA) {
    pin = _pin;
    BETA = _BETA;
  }
#endif
