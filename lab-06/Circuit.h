#ifndef UNTITLED3_CIRCUIT_H
#define UNTITLED3_CIRCUIT_H
#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
    int length;
    Weather weather;

    Car* cars[100];
    int carsCount;

    float times[100];//timpii masinolor
    bool finished[100];//a terminat?
public:
    Circuit();
    ~Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
#endif