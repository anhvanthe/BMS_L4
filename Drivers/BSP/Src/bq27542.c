/*
 * bq27542.c
 * Desc: TI Fuel Gauge driver code
 */

//Includes
#include "bq27542.h"

void BQ27542_read(uint8_t cmd, uint16_t bytes)
{
  uint8_t tx[1];

  tx[0] = cmd;
  if(HAL_I2C_Master_Transmit(&hi2c1, bq27542_ADDR, tx, 1, 0xFFFF) != HAL_OK){
	  BQ27542_error();
  }
  if(HAL_I2C_Master_Receive(&hi2c1, bq27542_ADDR, RxData, bytes, 0xFFFF) != HAL_OK){
	  BQ27542_error();
  }

}

void BQ27542_cmdWrite(uint8_t cmd, uint8_t data)
{
  uint8_t tx[2];
  tx[0] = cmd;
  tx[1] = data;
  if(HAL_I2C_Master_Transmit(&hi2c1, bq27542_ADDR, tx, 2, 0xFFFF) != HAL_OK){
	  BQ27542_error();
  }

}

void BQ27542_blockWrite(uint8_t *buffer, uint16_t length)
{
  if(HAL_I2C_Master_Transmit(&hi2c1, bq27542_ADDR, buffer, length, 0xFFFF) != HAL_OK){
	  BQ27542_error();
  }
}

void BQ27542_error(void)
{
	uint16_t error = 1;
}

uint16_t BQ27542_getTemperature(void){
	// Read Temperature (units = 0.1K)
	BQ27542_read(bq27542CMD_TEMP_LSB, 2);
	temperature = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return temperature;
}

uint16_t BQ27542_getDeviceType(void){
	// Read Device Type
	TxData[0] = bq27542CMD_CNTL_LSB;
	TxData[1] = bq27542CMD_CNTL_DTYPE_LSB;
	TxData[2] = bq27542CMD_CNTL_DTYPE_MSB;
	BQ27542_blockWrite(TxData, 3);
	//wait_sec(0.01);
	BQ27542_read(bq27542CMD_CNTL_LSB, 2);
	uint16_t devType = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return devType;
}

uint16_t BQ27542_getUnfilteredSOC(void){
	//units: %
	uint16_t soc;
	BQ27542_read(bq27542CMD_USOC_LSB, 2);
	soc = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return soc;
}

uint16_t BQ27542_getVoltage(void){
	//units: mV
	uint16_t mV; //bq27542CMD_VOLT_LSB
	BQ27542_read(bq27542CMD_VOLT_LSB, 2);
	mV = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return mV;
}

uint16_t BQ27542_getNomAvailableCapacity(void){
	//units: mAh
	uint16_t nomCap;

	BQ27542_read(bq27542CMD_NAC_LSB, 2);
	nomCap = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return nomCap;
}

uint16_t BQ27542_getFullAvailableCapacity(void){
	//units: mAh
	uint16_t fullCap;
	BQ27542_read(bq27542CMD_FAC_LSB, 2);
	fullCap = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return fullCap;
}

uint16_t BQ27542_getRemainingCapacity(void){
	//units: mAh
	uint16_t remCap;
	BQ27542_read(bq27542CMD_RMC_LSB, 2);
	remCap = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return remCap;
}

uint16_t BQ27542_getFullChargeCapacity(void){
	//units: mAh
	uint16_t fullChrgCap;
	BQ27542_read(bq27542CMD_FCC_LSB, 2);
	fullChrgCap = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return fullChrgCap;
}

uint16_t BQ27542_getAverageCurrent(void){
	//units: mA
	uint16_t aveCurrent;
	BQ27542_read(bq27542CMD_AI_LSB, 2);
	aveCurrent = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return aveCurrent;
}

uint16_t BQ27542_getTimeToEmpty(void){
	//units: min
	uint16_t timeToEmpty;
	BQ27542_read(bq27542CMD_TTE_LSB, 2);
	timeToEmpty = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return timeToEmpty;
}

uint16_t BQ27542_getFullChargeCapacityFiltered(void){
	//units: mAh
	uint16_t fullChrgCapFilt;

	BQ27542_read(bq27542CMD_FCCF_LSB, 2);
	fullChrgCapFilt = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return fullChrgCapFilt;
}

uint16_t BQ27542_getFullChargeCapacityUnfiltered(void){
	//units: mAh
	uint16_t fullChrgCapUnfilt;

	BQ27542_read(bq27542CMD_FCCU_LSB, 2);
	fullChrgCapUnfilt = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return fullChrgCapUnfilt;
}

uint16_t BQ27542_getImax(void){
	//units: mAh
	uint16_t imax;

	BQ27542_read(bq27542CMD_IMAX_LSB, 2);
	imax = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return imax;
}

uint16_t BQ27542_getRemainingCapacityUnfiltered(void){
	//units: mAh
	uint16_t remCapUnfilt;

	BQ27542_read(bq27542CMD_RCU_LSB, 2);
	remCapUnfilt = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return remCapUnfilt;
}

uint16_t BQ27542_getRemainingCapacityFiltered(void){
	//units: mAh
	uint16_t remCapFilt;

	BQ27542_read(bq27542CMD_RCF_LSB, 2);
	remCapFilt = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return remCapFilt;
}

uint16_t BQ27542_setBTPSOC1(uint16_t mAh){
	//units: mAh
	uint16_t btpsoc1;
	//TODO: Josh - need to write command
	//BQ27542_read(bq27542CMD_BTP1S_LSB, 2);
	//btpsoc1 = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return btpsoc1;
}

uint16_t BQ27542_clearBTPSOC1(void){
	//units: mAh
	uint16_t btpsoc1;
	//TODO: Josh - need to sent write command to clear
	//BQ27542_read(bq27542CMD_BTP1C_LSB, 2);
	//btpsoc1 = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return btpsoc1;
}
uint16_t BQ27542_getInternalTemperature(void){
	//units: 0.1 deg K
	uint16_t intTemp;
	BQ27542_read(bq27542CMD_ITMP_LSB, 2);
	intTemp = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return intTemp;
}

uint16_t BQ27542_getCycleCount(void){
	//units: count
	uint16_t cycleCnt;
	BQ27542_read(bq27542CMD_CC_LSB, 2);
	cycleCnt = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return cycleCnt;
}

uint16_t BQ27542_getStateOfCharge(void){
	//units: %
	uint16_t soc;
	BQ27542_read(bq27542CMD_SOC_LSB, 2);
	soc = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return soc;
}

uint16_t BQ27542_getStateOfHealth(void){
	//units % / num
	uint16_t soh;
	BQ27542_read(bq27542CMD_SOH_LSB, 2);
	soh = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return soh;
}

uint16_t BQ27542_getChargingVoltage(void){
	//units: mV
	uint16_t chrgVolt;
	BQ27542_read(bq27542CMD_CVLT_LSB, 2);
	chrgVolt = transBytes2UnsignedInt(RxData[1], RxData[0]);//TODO: Josh - develop  code

	return chrgVolt;
}

uint16_t BQ27542_getChargingCurrent(void){
	//units: mA
	uint16_t chrgCurrent;

	BQ27542_read(bq27542CMD_CCRNT_LSB, 2);
	chrgCurrent = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return chrgCurrent;
}

uint16_t BQ27542_getPassedCharge(void){
	//units: mAh
	uint16_t passedChrg;
	BQ27542_read(bq27542CMD_PCHRG_LSB, 2);
	passedChrg = transBytes2UnsignedInt(RxData[1], RxData[0]);//TODO: Josh - develop  code

	return passedChrg;
}

uint16_t BQ27542_getDOD0(void){
	//units: hex
	uint16_t dod0;
	BQ27542_read(bq27542CMD_DOD0_LSB, 2);
	dod0 = transBytes2UnsignedInt(RxData[1], RxData[0]);

	return dod0;
}

uint16_t BQ27542_getSelfDischargeCurrent(void){
	//units: mA
	uint16_t disCurrent;

	BQ27542_read(bq27542CMD_SDC_LSB, 2);
	disCurrent = transBytes2UnsignedInt(RxData[1], RxData[0]);
	return disCurrent;
}
