#include "BMW.h"
BMW::BMW()
{
    fuelCapacity=5;
    fuelConsumption=7;
    speedRain=80;
    speedSunny=100;
    speedSnow=60;
}
const char* BMW::GetName()
{
    return "BMW";
}
float BMW::GetFuelCapacity()
{
    return fuelCapacity;
}
float BMW::GetFuelConsumption()
{
    return fuelConsumption;
}
float BMW::GetAverageSpeed(Weather weather)
{
    if(weather==Rain)
        return speedRain;
    if(weather==Sunny)
        return speedSunny;
    return speedSnow;
}