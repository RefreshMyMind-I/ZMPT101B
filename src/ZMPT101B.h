#ifndef ZMPT101B_h
#define ZMPT101B_h

#include <Arduino.h>

#define adcres 1023.0
#define ip_vin 5.0
#define default_frequency 50

class ZMPT101B
{
public:
    ZMPT101B(uint8_t _pin);
    int calibration();
    void setzero(int _zero);
    void setSensitivity(float sense);
    float getVdc();
    float getVac(uint16_t ipfrequency = 50);

private:
    uint8_t pin;
    float sensitivity;
    int z = 512;
};

#endif