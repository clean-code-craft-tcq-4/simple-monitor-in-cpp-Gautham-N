#include <iostream>
#include "BatteryConditions.h"
#include <assert.h>
int main()
{
BatteryConditions BatteryConditionCheck;
   assert(BatteryConditionCheck.batteryIsOk(25, 70, 0.7) == true);
    assert(BatteryConditionCheck.batteryIsOk(50, 85, 0) == false);
    assert(BatteryConditionCheck.batteryIsOk(30, 70, 0.1) == true);
    assert(BatteryConditionCheck.batteryIsOk(30, 70, 0.9) == false);
    assert(BatteryConditionCheck.batteryIsOk(1, 70, 0.7) == true);
    assert(BatteryConditionCheck.batteryIsOk(25, 78, 0.7) == true);
    assert(BatteryConditionCheck.batteryIsOk(25, 70, 0.7) == true);
    assert(BatteryConditionCheck.batteryIsOk(25, 70, 0.79) == true);
}
