#include "Fiat.h"
Fiat::Fiat()
{
    fuelCapacity=45;
    fuelConsumption=6.5f;
    speedRain=65;
    speedSunny=85;
    speedSnow=45;
}
const char* Fiat::GetName()
{
    return "Fiat";
}
float Fiat::GetFuelCapacity()
{
    return fuelCapacity;
}
float Fiat::GetFuelConsumption()
{
    return fuelConsumption;
}
float Fiat::GetAverageSpeed(Weather weather)
{
    if(weather==Rain)
        return speedRain;
    if(weather==Sunny)
        return speedSunny;
    return speedSnow;
}