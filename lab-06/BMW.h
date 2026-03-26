#ifndef UNTITLED3_BMW_H
#define UNTITLED3_BMW_H
#include "Car.h"
class BMW : public Car
{
private:
    float fuelCapacity;
    float fuelConsumption;
    float speedRain;
    float speedSunny;
    float speedSnow;
public:
    BMW();

    const char* GetName() override;
    float GetFuelCapacity() override;
    float GetFuelConsumption() override;
    float GetAverageSpeed(Weather weather) override;
};
#endif