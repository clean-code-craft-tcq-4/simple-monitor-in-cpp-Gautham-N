#include <iostream>
#include "BatteryConditions.h"
#include <assert.h>
bool batteryIsOk(float temperature, float soc, float chargeRate)
{
    BatteryConditions BatteryConditionCheck;
    if (BatteryConditionCheck.TemperatureCheck(temperature) && BatteryConditionCheck.SocCheck(soc)
        && BatteryConditionCheck.ChargeRateCheck(chargeRate))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
