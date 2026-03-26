#ifndef UNTITLED3_VOLVO_H
#define UNTITLED3_VOLVO_H
#include "Car.h"
class Volvo : public Car
{
private:
    float fuelCapacity;
    float fuelConsumption;
    float speedRain;
    float speedSunny;
    float speedSnow;
public:
    Volvo();
    const char* GetName() override;
    float GetFuelCapacity() override;
    float GetFuelConsumption() override;
    float GetAverageSpeed(Weather weather) override;
};
#endif