#pragma once
long double operator "" _Kelvin(unsigned long long x){//functia operator pentru literalul Kelvin
    return x-273.15;
}
long double operator "" _Fahrenheit(unsigned long long x){
    return (x-32)*5.0/9.0;
}