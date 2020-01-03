/* File: "bq27542.h"
 * Desc: Header file for TI Fuel Gauge I2C Commands and Functions
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32l4xx_hal.h"
#include "BSP.h"


//I2C Register Constants - See Table 6. Standard Commands in BQ27542 Datasheet
//Control Command
#define bq27542CMD_CNTL_LSB   0x00
#define bq27542CMD_CNTL_MSB   0x01
//Start Control Subcommands
#define bq27542CMD_CNTL_DTYPE_MSB   0x00
#define bq27542CMD_CNTL_DTYPE_LSB   0x01
#define bq27542CMD_CNTL_FWVER_MSB 0x00
#define bq27542CMD_CNTL_FWVER_LSB 0x02
#define bq27542CMD_CNTL_HWVER_MSB 0x00
#define bq27542CMD_CNTL_HWVER_LSB 0x03
//End Control subcommands

#define bq27542CMD_AR_LSB     0x02 //AtRate
#define bq27542CMD_AR_MSB     0x03
#define bq27542CMD_USOC_LSB   0x04 //Unfiltered SOC
#define bq27542CMD_USOC_MSB   0x05
#define bq27542CMD_TEMP_LSB   0x06
#define bq27542CMD_TEMP_MSB   0x07
#define bq27542CMD_VOLT_LSB   0x08
#define bq27542CMD_VOLT_MSB   0x09
#define bq27542CMD_FLAGS_LSB  0x0A
#define bq27542CMD_FLAGS_MSB  0x0B
#define bq27542CMD_NAC_LSB    0x0C //Nom Available Capacity
#define bq27542CMD_NAC_MSB    0x0D
#define bq27542CMD_FAC_LSB    0x0E //Full Available Capacity
#define bq27542CMD_FAC_MSB    0x0F
#define bq27542CMD_RMC_LSB      0x10 //Remaining capacity
#define bq27542CMD_RMC_MSB      0x11
#define bq27542CMD_FCC_LSB    0x12 //Full charge capacity
#define bq27542CMD_FCC_MSB    0x13
#define bq27542CMD_AI_LSB     0x14 //Average current
#define bq27542CMD_AI_MSB     0x15
#define bq27542CMD_TTE_LSB    0x16 //Time to Empty
#define bq27542CMD_TTE_MSB    0x17
#define bq27542CMD_FCCF_LSB     0x18 //Full charge capacity filtered
#define bq27542CMD_FCCF_MSB     0x19
#define bq27542CMD_SS_LSB     0x1A //Safety Status
#define bq27542CMD_SS_MSB     0x1B
#define bq27542CMD_FCCU_LSB   0x1C //Full charge capacity unfiltered
#define bq27542CMD_FCCU_MSB   0x1D
#define bq27542CMD_IMAX_LSB     0x1E //Imax
#define bq27542CMD_IMAX_MSB     0x1F
#define bq27542CMD_RCU_LSB    0x20 //Remaining capacity unfiltered
#define bq27542CMD_RCU_MSB    0x21
#define bq27542CMD_RCF_LSB      0x22 //Remaining capacity filtered
#define bq27542CMD_RCF_MSB      0x23
#define bq27542CMD_BTP1S_LSB    0x24 //BTPSOC1 set
#define bq27542CMD_BTP1S_MSB    0x25
#define bq27542CMD_BTP1C_LSB  0x26 //BTPSOC1 clear
#define bq27542CMD_BTP1C_MSB  0x27
#define bq27542CMD_ITMP_LSB   0x28 //Internal temperature
#define bq27542CMD_ITMP_MSB   0x29
#define bq27542CMD_CC_LSB     0x2A //Cycle count
#define bq27542CMD_CC_MSB     0x2B
#define bq27542CMD_SOC_LSB    0x2C //State of charge
#define bq27542CMD_SOC_MSB    0x2D
#define bq27542CMD_SOH_LSB    0x2E //State of health
#define bq27542CMD_SOH_MSB    0x2F
#define bq27542CMD_CVLT_LSB     0x30 //Charging voltage
#define bq27542CMD_CVLT_MSB     0x31
#define bq27542CMD_CCRNT_LSB    0x32 //Charging current
#define bq27542CMD_CCRNT_MSB    0x33
#define bq27542CMD_PCHRG_LSB    0x34 //Passed charge
#define bq27542CMD_PCHRG_MSB    0x35
#define bq27542CMD_DOD0_LSB     0x36 //DO D0 (D0 not D'O')
#define bq27542CMD_DOD0_MSB     0x37
#define bq27542CMD_SDC_LSB    0x38 //Self discharge current
#define bq27542CMD_SDC_MSB    0x39


#define ATRATE_MA            -100           // USER CONFIG: AtRate setting (mA)
#define BQ27542_ADDR         0xAA           // 0xAA = 0x55 << 1 = 7-bit slave address
//#define BUFFERSIZE             32           // # of bytes for Tx & Rx buffers
/*
extern UINT8 Message[RANDMESGNUMBYTES]; // random message sent to the bq device
extern UINT8 Key[SECRETKEYNUMBYTES]; // secret key - should match contents of bq
extern UINT32 Digest_32[5]; // Result of SHA1/HMAC obtained by MCU stored here
extern UINT32 H[5];

UINT8 DeviceID[DEVICEIDNUMBYTES];           // Stores the Device ID data
UINT8 Digest[DIGESTNUMBYTES];               // SHA1 response from the bq27542
*/

// uint8_t TxData[BUFFERSIZE];           // Stores data bytes to be TX'd
//uint8_t RxData[BUFFERSIZE];           // Stores data bytes that are RX'd
// uint16_t  temperature;                  // Stores temperature
// uint16_t  voltage;                      // Stores voltage
//   signed int  atrate;                       // Stores AtRate
// uint16_t  artte;                        // Stores AtRate Time to Empty
// uint16_t  soc;                          // Stores State of Charge
// uint16_t  dcap;                         // Stores Design Capacity
// uint16_t  dnamelen;                     // Stores Device Name Length


//Function Declarations
//uint16_t transBytes2UnsignedInt(uint8_t msb, uint8_t lsb);
void BQ27542_read(uint8_t cmd, uint16_t bytes);
void BQ27542_cmdWrite(uint8_t cmd, uint8_t data);
void BQ27542_blockWrite(uint8_t *buffer, uint16_t length);
void BQ27542_error(void);

/*
 * Function below based on BQ27542 Datasheet standard data commands (http://www.ti.com/lit/ds/symlink/bq27542-g1.pdf)
 */

uint16_t BQ27542_getDeviceType(void); //0x0542 is the expected result

uint16_t BQ27542_getTemperature(void); //0.1 deg K
// uint16_t BQ27542_getUnfilteredSOC(void); //%
uint16_t BQ27542_getVoltage(void); //mV
uint16_t BQ27542_getNomAvailableCapacity(void); //mAh
uint16_t BQ27542_getFullAvailableCapacity(void); //mAh
// uint16_t BQ27542_getRemainingCapacity(void); //mAh
// uint16_t BQ27542_getFullChargeCapacity(void); //mAh
// uint16_t BQ27542_getAverageCurrent(void); //mA
// uint16_t BQ27542_getTimeToEmpty(void); //min
// uint16_t BQ27542_getFullChargeCapacityFiltered(void); //mAh
// uint16_t BQ27542_getFullChargeCapacityUnfiltered(void); //mAh
// uint16_t BQ27542_getImax(void); //mAh
// uint16_t BQ27542_getRemainingCapacityUnfiltered(void); //mAh
// uint16_t BQ27542_getRemainingCapacityFiltered(void); //mAh
// uint16_t BQ27542_setBTPSOC1(uint16_t mAh); //mAh
// uint16_t BQ27542_clearBTPSOC1(void); //mAh
// uint16_t BQ27542_getInternalTemperature(void); // 0.1 deg K
// uint16_t BQ27542_getCycleCount(void); //count
// uint16_t BQ27542_getStateOfCharge(void); //%
// uint16_t BQ27542_getStateOfHealth(void); //% / num
// uint16_t BQ27542_getChargingVoltage(void); //mV
// uint16_t BQ27542_getChargingCurrent(void); //mA
// uint16_t BQ27542_getPassedCharge(void); //mAh
// uint16_t BQ27542_getDOD0(void); //hex
// uint16_t BQ27542_getSelfDischargeCurrent(void); //mA

