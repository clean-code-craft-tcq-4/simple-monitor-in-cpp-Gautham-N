#include "BatteryConditions.h"
#include "iostream"



bool BatteryConditions::checkRange(float actualValue, float minValue, float maxValue)
{
    return (actualValue < minValue || actualValue > maxValue);
}

bool BatteryConditions::batteryIsOk(float temperature, float soc, float chargeRate)
{
    
    return (TemperatureCheck(temperature) && SocCheck(soc)
        && ChargeRateCheck(chargeRate))
    
}

bool BatteryConditions::TemperatureCheck(int threshold)
{
    if (checkRange(threshold , 0 , 45)) {
     std::cout << "Temperature out of range!\n";
        return false;
    }
    else
    {
        return true;
    }
}

bool BatteryConditions::SocCheck(int threshold)
{
    if (checkRange(threshold, 20, 80) ){
        std::cout << "State of Charge out of range!\n";
        return false;
    }
    else
    {
        return true;
    }
}

bool BatteryConditions::ChargeRateCheck(int threshold)
{
    if (checkRange(threshold, 0,0.8) ){
        std::cout << "Charge Rate out of range!\n";
        return false;
    }
    else
    {
        return true;
    }
}
