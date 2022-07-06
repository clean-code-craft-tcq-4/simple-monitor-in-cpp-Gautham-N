#pragma once
class BatteryConditions
{
public:
	bool TemperatureCheck(int threshold);
	bool SocCheck(int threshold);
	bool ChargeRateCheck(int threshold);
};

