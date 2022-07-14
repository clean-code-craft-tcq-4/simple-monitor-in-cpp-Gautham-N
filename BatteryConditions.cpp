#include "BatteryConditions.h"
#include "iostream"
#include "BatteryLimitParams.h"


bool BatteryConditions::checkRange(float actualValue, float minValue, float maxValue)
{
	return (actualValue <= minValue || actualValue > maxValue);
}

void BatteryConditions::checkBreachLow(float actualValue, float minValue, float maxValue, BATTERY_PARAMETER parameter)
{
	float tolerance = (maxValue * 5) / 100;
	if (actualValue > minValue && actualValue < (minValue + tolerance))
	{
		printWarnMessage(parameter, LOW);
	}
}

void BatteryConditions::checkBreachHigh(float actualValue, float maxValue, BATTERY_PARAMETER parameter)
{
	float tolerance = (maxValue * 5) / 100;
	if (actualValue >= (maxValue - tolerance) && actualValue <= maxValue)
	{
		printWarnMessage(parameter, HIGH);
	}
}

void BatteryConditions::printWarnMessage(BATTERY_PARAMETER parameter, PARAMETER_BREACH_TYPE breachType)
{
	std::cout << messageWarn[breachType] << "_" << messageFactor[languageOption][parameter] << "_WARN\n";
}

void BatteryConditions::printErrorMessage(BATTERY_PARAMETER messageKey)
{
	std::cout << messageFactor[languageOption][messageKey] << " " << messageTrailing[languageOption] << "\n";
}

bool BatteryConditions::batteryTemperatureIsOk(float temperature)
{
	bool result = true;
	checkBreachLow(temperature, temperature_min, temperature_max, BATTERY_TEMPERATURE);
	checkBreachHigh(temperature, temperature_max, BATTERY_TEMPERATURE);
	if (checkRange(temperature, temperature_min, temperature_max))
	{
		printErrorMessage(BATTERY_TEMPERATURE);
		result = false;
	}
	return result;
}

bool BatteryConditions::batterySocIsOk(float soc)
{
	bool result = true;
	checkBreachLow(soc, soc_min, soc_max, BATTERY_SOC);
	checkBreachHigh(soc, soc_max, BATTERY_SOC);
	if (checkRange(soc, soc_min, soc_max))
	{
		printErrorMessage(BATTERY_SOC);
		result = false;
	}
	return result;
}

bool BatteryConditions::batteryChargeRateIsOk(float chargeRate)
{
	bool result = true;
	checkBreachLow(chargeRate, chargeRate_min, chargeRate_max, BATTERY_CHARGE_RATE);
	checkBreachHigh(chargeRate, chargeRate_max, BATTERY_CHARGE_RATE);
	if (checkRange(chargeRate, chargeRate_min, chargeRate_max))
	{
		printErrorMessage(BATTERY_CHARGE_RATE);
		result = false;
	}
	return result;
}

bool BatteryConditions::batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (batteryTemperatureIsOk(temperature) && batterySocIsOk(soc) && batteryChargeRateIsOk(chargeRate));
}
