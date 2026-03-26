#include <iostream>
#include "Circuit.h"
using namespace std;
Circuit::Circuit()
{
    length=0;
    weather=Sunny;
    carsCount=0;
    for(int i=0; i<100; i++)
    {
        cars[i]=nullptr;
        times[i]=0;
        finished[i]=false;
    }
}
Circuit::~Circuit()
{
    for(int i=0; i<carsCount; i++)
        delete cars[i];
}
void Circuit::SetLength(int length)
{
    this->length=length;
}
void Circuit::SetWeather(Weather weather)
{
    this->weather=weather;
}
void Circuit::AddCar(Car* car)
{
    if(carsCount<100)
        cars[carsCount++]=car;
}
void Circuit::Race()
{
    for (int i=0; i<carsCount; i++)
    {
        float fuelCapacity=cars[i]->GetFuelCapacity();
        float fuelConsumption=cars[i]->GetFuelConsumption();
        float maxDistance=fuelCapacity/fuelConsumption * 100;
        if (maxDistance>=length)
        {
            finished[i]=true;
            times[i]=(float)length/cars[i]->GetAverageSpeed(weather);
        }
        else
        {
            finished[i]=false;
            times[i]=0;
        }
    }

    for (int i=0; i<carsCount-1; i++)
        for (int j=i+1; j<carsCount; j++)
            if (finished[i] && finished[j] && times[i]>times[j])
            {
                float auxTime=times[i];
                times[i]=times[j];
                times[j]=auxTime;

                Car* auxCar=cars[i];
                cars[i]=cars[j];
                cars[j]=auxCar;

                bool auxFinished=finished[i];
                finished[i]=finished[j];
                finished[j]=auxFinished;
            }
}
void Circuit::ShowFinalRanks()
{
    for(int i=0; i<carsCount; i++)
        if(finished[i])
            cout<<cars[i]->GetName()<< " " <<times[i]<<endl;
}
void Circuit::ShowWhoDidNotFinish()
{
    for(int i=0; i<carsCount; i++)
        if(!finished[i])
            cout<<cars[i]->GetName()<<endl;
}