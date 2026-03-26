#include "Volvo.h"
Volvo::Volvo()
{
    fuelCapacity=60;
    fuelConsumption=8;
    speedRain=70;
    speedSunny=90;
    speedSnow=50;
}
const char* Volvo::GetName()
{
    return "Volvo";
}
float Volvo::GetFuelCapacity()
{
    return fuelCapacity;
}
float Volvo::GetFuelConsumption()
{
    return fuelConsumption;
}
float Volvo::GetAverageSpeed(Weather weather)
{
    if(weather==Rain)
        return speedRain;
    if(weather==Sunny)
        return speedSunny;
    return speedSnow;
}