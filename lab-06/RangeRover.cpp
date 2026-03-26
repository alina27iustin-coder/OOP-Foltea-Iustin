#include "RangeRover.h"
RangeRover::RangeRover()
{
    fuelCapacity=70;
    fuelConsumption=12;
    speedRain=75;
    speedSunny=95;
    speedSnow=65;
}
const char* RangeRover::GetName()
{
    return "RangeRover";
}
float RangeRover::GetFuelCapacity()
{
    return fuelCapacity;
}
float RangeRover::GetFuelConsumption()
{
    return fuelConsumption;
}
float RangeRover::GetAverageSpeed(Weather weather)
{
    if(weather==Rain)
        return speedRain;
    if(weather==Sunny)
        return speedSunny;
    return speedSnow;
}