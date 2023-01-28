#include "ZMPT101B.h"

ZMPT101B::ZMPT101B(uint8_t _pin)
{
    pin = _pin;
    sensitivity = 0.010;
}

int ZMPT101B::calibration()
{
    uint16_t cal = 0;
    for (int x = 0; x < 10; x++)
    {
        cal += analogRead(pin);
    }
    z = cal / 10;
    return 0;
}

void ZMPT101B::setzero(int _zero)
{
    z = _zero;
}
void ZMPT101B::setSensitivity(float sense)
{
    sensitivity = sense;
}
float ZMPT101B::getVdc()
{
    uint16_t cal = 0;
    for (int x = 0; x < 10; x++)
    {
        cal += analogRead(pin) - z;
    }
    float Voltage = (float)cal / 10.0 / adcres * ip_vin / sensitivity;
    return Voltage;
}
float ZMPT101B::getVac(uint16_t ipfrequency)
{
    uint32_t scale = 100000 / ipfrequency;
    uint32_t start_t = millis();

    uint32_t sum = 0, counter = 0;
    uint32_t vn;
    while (millis() - start_t < scale)
    {
        vn = analogRead(pin) - z;
        sum += vn * vn;
        counter++;
    }
    float rmsv = sqrt(sum/counter) / adcres * default_frequency / sensitivity;
    return rmsv;
}