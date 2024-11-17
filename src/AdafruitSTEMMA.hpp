#ifndef AdafruitSTEMMA_H
#define AdafruitSTEMMA_H
#include <Arduino.h>
#include <Wire.h>
#define ARDUINO_R3_SDA A4
#define ARDUINO_R3_SCL A5


class AdafruitSTEMMA
{
public:
    AdafruitSTEMMA();
    int initialize();
    double readAdafruit();
    ~AdafruitSTEMMA();

};

#endif