#ifndef UNTITLED3_SEAT_H
#define UNTITLED3_SEAT_H
#include "Car.h"
class Seat : public Car
{
private:
    float fuelCapacity;
    float fuelConsumption;
    float speedRain;
    float speedSunny;
    float speedSnow;
public:
    Seat();
    const char* GetName() override;
    float GetFuelCapacity() override;
    float GetFuelConsumption() override;
    float GetAverageSpeed(Weather weather) override;
};
#endif //UNTITLED3_SEAT_H