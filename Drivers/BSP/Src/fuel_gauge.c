/*
 * fuel_gauge.c
 * Desc: Fuel Gauge driver code using TI bq27542 fuel gauge driver
 */

//Includes
#include "fuel_gauge.h"

void FuelGauge_error(void)
{

}

uint16_t FuelGauge_getTemperature(void){
	// Read Temperature (units = 0.1K)
	int temperature = BQ27542_getTemperature();
	return temperature;
}

uint16_t FuelGauge_getDeviceType(void){
	// Read Device Type
	uint16_t devType = BQ27542_getDeviceType();
	return devType;
}

bool FuelGauge_isCharging(void){
	bool charging;

	//TODO: Josh - Develop code
	return charging;
}

bool FuelGauge_isDischarging(void){
	bool discharging;

	//TODO: Josh - Develop code
	return discharging;
}

bool FuelGauge_isCharged(void){
	bool ischarged;

	//TODO: Josh - Develop code
	return ischarged;
}

float FuelGauge_getBatteryPercent(void){
	float percent; //% battery charge

	//TODO: Josh - Develop code
	return percent;
}
