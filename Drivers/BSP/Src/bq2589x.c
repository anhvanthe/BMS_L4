/* 
 * File: "bq2589x.c"
 * Desc: TI Fuel Gauge driver code
 * 
 * TuongPV <phamtuongbk999@outlook.com>
*/
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_i2c.h"
#include "bq2589x.h"
#include "BSP.h"

extern I2C_HandleTypeDef hi2c1;

uint16_t bq2589x_read(uint16_t Reg, uint8_t *pBuffer)
{
 HAL_StatusTypeDef status = HAL_OK;
 //uint8_t value = 0x0;
 //status = HAL_I2C_Mem_Read(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, &value, 1, 100);
 status = HAL_I2C_Mem_Read(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, pBuffer, 1, 100);
 /* Check the communication status */
 if (status != HAL_OK)
 {
   /* Re-Initiaize the BUS */
   //I2C1_Error();
 }
 return status;
}


uint16_t bq2589x_write(uint16_t Reg, uint8_t val)
{//if(HAL_I2C_IsDeviceReady(BMP280_I2C_handler,BMP280_IC2ADDRESS, 10, 100)==HAL_OK)
 HAL_StatusTypeDef status = HAL_OK;
 //if(HAL_I2C_IsDeviceReady(&hi2c1, (BQ25892_ADDR), 1,100u) == HAL_OK)
 {
   status = HAL_I2C_Mem_Write(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, &val, 1, 100);
 }

	/* Check the communication status */
 if (status != HAL_OK)
 {
   /* Re-Initiaize the BUS */
   //I2C1_Error();
 }
 return status;
}
