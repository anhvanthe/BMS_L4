#include "main.h"
#include "BSP.h"
//#include "bq25892.h"
//#include "bq27542.h"
#include <stdio.h>
#include <string.h>

//HAL_StatusTypeDef check = HAL_OK;

// I2C_HandleTypeDef hi2c1;
// I2C_HandleTypeDef hi2c2;



uint8_t dummy = 0;
uint16_t t=0;
//uint16_t dev_count=0;

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
void SystemClock_Config(void);
static void Error_Handler(void);

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM1_Init(void);

// A simple atoi() function 
uint16_t myAtoi(char* str);

void LED_BLink(void);

uint16_t i2c_scanner(void);

//static int bq2589x_read(uint16_t Reg, uint8_t *pBuffer);
//static int bq2589x_write(uint16_t Reg, uint8_t val);

/* UART-to-USB debug output */
/*void printDebug(char *buf)
{
  HAL_UART_Transmit(&huart2, (uint8_t *) buf, strlen(buf), HAL_MAX_DELAY);
}
*/

/****************** MAIN **********************/

int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();

  //HAL_TIM_Base_Start_IT(&htim1);

  // Turn on Green LED to indicate
  HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
  HAL_Delay(100);

  //printDebug("STM32L4 Started !!.\r\n");
  printf("STM32L4 Started !!.\r\n");
	//printDebug("Console is ready to use......\r\n");
  printf("Console is ready to use......\r\n");

  ///i2c_scanner();

  while (1)
  {
    LED_BLink();
    i2c_scanner();

    /* BQ27542-G1
    Addr 7 bit: 0x55
    Addr 8 bit 0xAA (Write) and 0xAB (Read)
    */

    /*
    if(i2c_scanner() != 0)
    {
      bq2589x_write(BQ25892_REG_07, 0x8D);
      bq2589x_write(BQ25892_REG_03, 0x3A);

			
      for (t = 0; t < 20; ++t)
      {
        bq2589x_read(t, &dummy);

        printf("Dummy value of 0x%02X is 0x%02X\n\r", (uint8_t)t, dummy);
        HAL_Delay(10u);
      }
    }
    */
    
    HAL_Delay(1000u);

  }

}


/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_I2C2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration 
  */
  HAL_RCCEx_EnableMSIPLLMode();
}








/* USER CODE BEGIN 4 */

uint16_t myAtoi(char* str) 
{ 
    int res = 0; // Initialize result 
  
    // Iterate through all characters of input string and 
    // update result 
    for (int i = 0; str[i] != '\0'; ++i) 
        res = res * 10 + str[i] - '0'; 
  
    // return result. 
    return res; 
}

void LED_BLink(void)
{
    HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);

    HAL_Delay(200);
    HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);

    HAL_Delay(200);
}

uint16_t i2c_scanner(void)
{
  uint8_t i2c_addr = 0;
	
  uint8_t i = 0;
  uint8_t devices = 0;
  printf("\r\nStart scanning.........\n\r");

  for (i = 1; i < 127; i++)
  {
    i2c_addr = i << 1;
    if (HAL_OK == HAL_I2C_IsDeviceReady(&hi2c1, i2c_addr, 1,100u) )
    {
			//printDebug("Device found: ....\n\r");
      printf("Device found: 0x%02X\n\r", i2c_addr);
			//printDebug(&i2c_addr);
      devices++;
    }
  }

  /* Feedback of the total number of devices. */
  if (0u == devices)
  {
    printf("No device found.\n\r");
  }
  else
  {
    printf("Total found devices: %d\n\r", devices);
  }

  return devices;
}



//static int bq2589x_read(uint16_t Reg, uint8_t *pBuffer)
//{
//  //HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
//  HAL_StatusTypeDef status = HAL_OK;
//  //uint8_t value = 0x0;
//  //status = HAL_I2C_Mem_Read(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, &value, 1, 100);
//  status = HAL_I2C_Mem_Read(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, pBuffer, 1, 100);
//  /* Check the communication status */
//  if (status != HAL_OK)
//  {
//    /* Re-Initiaize the BUS */
//    //I2C1_Error();
//  }
//  return status;
//}


//static int bq2589x_write(uint16_t Reg, uint8_t val)
//{//if(HAL_I2C_IsDeviceReady(BMP280_I2C_handler,BMP280_IC2ADDRESS, 10, 100)==HAL_OK)
//  HAL_StatusTypeDef status = HAL_OK;
//  //if(HAL_I2C_IsDeviceReady(&hi2c1, (BQ25892_ADDR), 1,100u) == HAL_OK)
//  {
//    status = HAL_I2C_Mem_Write(&hi2c1, (BQ25892_ADDR<<1), (uint16_t)Reg, 1, &val, 1, 100);
//  }

//	/* Check the communication status */
//  if (status != HAL_OK)
//  {
//    /* Re-Initiaize the BUS */
//    //I2C1_Error();
//  }
//  return status;
//}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
