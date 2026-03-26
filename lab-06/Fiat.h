#ifndef UNTITLED3_FIAT_H
#define UNTITLED3_FIAT_H
#include "Car.h"
class Fiat : public Car
{
private:
    float fuelCapacity;
    float fuelConsumption;
    float speedRain;
    float speedSunny;
    float speedSnow;
public:
    Fiat();
    const char* GetName() override;
    float GetFuelCapacity() override;
    float GetFuelConsumption() override;
    float GetAverageSpeed(Weather weather) override;
};
#endif //UNTITLED3_FIAT_H