#include "BatteryConditions.h"
#include "iostream"

bool BatteryConditions::batteryIsOk(float temperature, float soc, float chargeRate)
{
    
    if (TemperatureCheck(temperature) && SocCheck(soc)
        && ChargeRateCheck(chargeRate))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BatteryConditions::TemperatureCheck(int threshold)
{
    if (threshold < 0 || threshold > 45) {
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
    if (threshold < 20 || threshold > 80) {
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
    if (threshold > 0.8) {
        std::cout << "Charge Rate out of range!\n";
        return false;
    }
    else
    {
        return true;
    }
}
