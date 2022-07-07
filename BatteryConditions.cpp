#include "BatteryConditions.h"
#include "iostream"
#include "BatteryLimitParams.h"


bool BatteryConditions::checkRange(float actualValue, float minValue, float maxValue)
{
    return (actualValue < minValue || actualValue > maxValue);
}

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
    if (checkRange(threshold , bms::temperature_min , bms::temperature_max)) {
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
    if (checkRange(threshold, bms::soc_min, bms::soc_max) ){
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
    if (checkRange(threshold, bms::chargeRate_min,bms::chargeRate_max) ){
        std::cout << "Charge Rate out of range!\n";
        return false;
    }
    else
    {
        return true;
    }
}
