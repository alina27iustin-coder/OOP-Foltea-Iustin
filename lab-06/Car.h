#ifndef UNTITLED3_CAR_H
#define UNTITLED3_CAR_H
#include "Weather.h"
class Car//clasa abstracta: "=0"
{
public:
    virtual const char* GetName() =0;
    virtual float GetFuelCapacity()=0;
    virtual float GetFuelConsumption()=0;
    virtual float GetAverageSpeed(Weather weather)=0;
    virtual ~Car() {}
};
#endif