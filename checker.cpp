#include <iostream>
#include "BatteryConditions.h"
#include <assert.h>
int main()
{
BatteryConditions BatteryConditionCheck;
    assert(BatteryConditionCheck.batteryIsOk(25, 70, 0.7) == true);
    assert(BatteryConditionCheck.batteryIsOk(50, 85, 0) == false);
}
