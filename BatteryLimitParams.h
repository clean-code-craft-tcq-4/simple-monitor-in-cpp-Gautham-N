#pragma once
#include<vector>
#include<iostream>
    enum BATTERY_PARAMETER : int
    {
        BATTERY_TEMPERATURE = 0,
        BATTERY_SOC = 1,
        BATTERY_CHARGE_RATE = 2
    };
    enum PARAMETER_BREACH_TYPE : int
    {
        LOW = 0,
        HIGH = 1
    };
	static float temperature_min = 0;
	static float temperature_max = 45;
	static float soc_min = 20;
	static float soc_max = 80;
	static float chargeRate_min = 0;
	static float chargeRate_max = 0.8;
    static int languageOption = 0;		//0 - English, 1- German
    static std::vector<std::vector<std::string>> messageFactor = { { "Temperature", "State of charge", "Charge Rate" }, {"Temperatur", "Ladezustand", "Ladestrom"} };
    static std::vector<std::string> messageTrailing = { "out of range!", "auﬂerhalb des Bereichs!" };
    static std::vector<std::string> messageWarn = { "LOW", "HIGH" };
