#ifndef UNTITLED3_RANGEROVER_H
#define UNTITLED3_RANGEROVER_H
#include "Car.h"
class RangeRover : public Car
{
private:
    float fuelCapacity;
    float fuelConsumption;
    float speedRain;
    float speedSunny;
    float speedSnow;
public:
    RangeRover();
    const char* GetName() override;
    float GetFuelCapacity() override;
    float GetFuelConsumption() override;
    float GetAverageSpeed(Weather weather) override;
};
#endif