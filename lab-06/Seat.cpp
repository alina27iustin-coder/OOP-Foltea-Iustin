#include "Seat.h"
Seat::Seat()
{
    fuelCapacity=50;
    fuelConsumption=6;
    speedRain=75;
    speedSunny=95;
    speedSnow=55;
}
const char* Seat::GetName()
{
    return "Seat";
}
float Seat::GetFuelCapacity()
{
    return fuelCapacity;
}
float Seat::GetFuelConsumption()
{
    return fuelConsumption;
}
float Seat::GetAverageSpeed(Weather weather)
{
    if(weather==Rain)
        return speedRain;
    if(weather==Sunny)
        return speedSunny;
    return speedSnow;
}