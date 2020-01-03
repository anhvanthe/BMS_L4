/* File: "fuel_gauge.h"
 * Desc: Header file for Fuel Gauge driver (wrapper around TI BQ27542)
 * Requirements
 * Standard
 * - Be able to report a battery is currently being charged.
 * - Be able to report a battery is currently being discharged.
 * - Be able to report a battery is fully charged.
 * - Be able to report a battery is at least 3% battery left (1 or 2% would be nice to haves).
 * Advanced
 * - A semi-accurate representation of battery status. 5% error margin is required.
 * - Reporting that is monotonically increasing or decreasing. People will not trust our battery reporting once they see this and there is nothing more annoying than seeing a battery report 90% to 85% to 88% to 84% to 87%. We need it to always go down or always go up when charging or discharging. I don't care if this happens at the component or firmware level. I'm blind to it.
 * Decay
 * - All requirements within this spec should be achieved at every 20 cycles up to 500 cycles. The reporting should be accurate even as the battery ages. I get that we'll discharge faster, but we should reflect this with a semi-accurate percentage. I would put this requirement up to the recommended lifetime of the battery.
 * Performance
 * - In under 500ms recognize and be able to report that a battery goes from charging to discharging.
 * - In under 500ms recognize and be able to report that a battery goes from discharging to charging.
 * - In under 1s be able to report a percentage change in battery (i.e. going from 95% to 94% for example) while discharging.
 * - In under 1s be able to report a percentage change in battery (i.e. going from 94% to 95% for example) while charging
*/

//Includes
#include "bq27542.h"
#include "stdbool.h"
void FuelGauge_error(void);
uint16_t FuelGauge_getTemperature(void);
uint16_t FuelGauge_getDeviceType(void);
bool FuelGauge_isCharging(void);
bool FuelGauge_isDischarging(void);
bool FuelGauge_isCharged(void);
float FuelGauge_getBatteryPercent(void);