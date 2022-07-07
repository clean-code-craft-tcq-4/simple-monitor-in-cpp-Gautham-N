#pragma once
class BatteryConditions
{
public:
	bool TemperatureCheck(int threshold);
	bool SocCheck(int threshold);
	bool ChargeRateCheck(int threshold);
	bool batteryIsOk(float temperature, float soc, float chargeRate);
	bool checkRange(float actualValue, float minValue, float maxValue);
};

