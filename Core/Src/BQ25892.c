#include "bq2589x.h"
#include "BQ25892.h"



/* Charger information */
static const struct charger_info bq2589x_charger_info = {
	.name         = "bq2589x",
	.voltage_max  = 4608,
	.voltage_min  = 3840,
	.voltage_step = 16,
	.current_max  = 5056,
	.current_min  = 0,
	.current_step = 64,
	.input_current_max  = 3250,
	.input_current_min  = 100,
	.input_current_step = 50,
};

static int bq2589x_read(int reg, int *value)
{
	//HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
	return HAL_I2C_Mem_Read(I2C_PORT_CHARGER, BQ2589X_ADDR, reg, value);
}
static int bq2589x_write(int reg, int value)
{
	return i2c_write8(I2C_PORT_CHARGER, BQ2589X_ADDR, reg, value);
}
static int bq2589x_watchdog_reset(void)
{
	int rv, val;
	rv = bq2589x_read(BQ2589X_REG_CFG2, &val);
	if (rv)
		return rv;
	val |= BQ2589X_CFG2_WD_RST;
	return bq2589x_write(BQ2589X_REG_CFG2, val);
}
static int bq2589x_set_terminate_current(int current)
{
	int reg_val, rv;
	int val = (current - 64) / 64;
	rv = bq2589x_read(BQ2589X_REG_PRE_CHG_CURR, &reg_val);
	if (rv)
		return rv;
	reg_val = (reg_val & ~0xf) | (val & 0xf);
	return bq2589x_write(BQ2589X_REG_PRE_CHG_CURR, reg_val);
}
#ifdef CONFIG_CHARGER_OTG
int charger_enable_otg_power(int enabled)
{
	int val, rv;
	rv = bq2589x_read(BQ2589X_REG_CFG2, &val);
	if (rv)
		return rv;
	val = (val & ~(BQ2589X_CFG2_CHG_CONFIG | BQ2589X_CFG2_OTG_CONFIG))
	    | (enabled ? BQ2589X_CFG2_OTG_CONFIG : BQ2589X_CFG2_CHG_CONFIG);
	return bq2589x_write(BQ2589X_REG_CFG2, val);
}
#endif