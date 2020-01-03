/* 
 * File: "BSP.h"
 * Desc: Common define for BSP's function
 * 
 * TuongPV <phamtuongbk999@outlook.com>
*/
#include "stm32l4xx_hal.h"

#define I2C_BUFFERSIZE             32           // # of bytes for Tx & Rx buffers
#define BUFFERSIZE 32

#define LED_R_Pin GPIO_PIN_2
#define LED_R_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_8
#define LED_G_GPIO_Port GPIOE
#define MFX_I2C_SLC_Pin GPIO_PIN_10
#define MFX_I2C_SLC_GPIO_Port GPIOB
#define MFX_I2C_SDA_Pin GPIO_PIN_11
#define MFX_I2C_SDA_GPIO_Port GPIOB
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_5
#define USART_TX_GPIO_Port GPIOD
#define USART_RX_Pin GPIO_PIN_6
#define USART_RX_GPIO_Port GPIOD
#define I2C1_SCL_Pin GPIO_PIN_6
#define I2C1_SCL_GPIO_Port GPIOB
#define I2C1_SDA_Pin GPIO_PIN_7
#define I2C1_SDA_GPIO_Port GPIOB


#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

void Error_Handler(void);
void MX_GPIO_Init(void);
void MX_I2C1_Init(void);
void MX_I2C2_Init(void);
void MX_USART2_UART_Init(void);
void MX_TIM1_Init(void);

uint16_t i2c_scanner(void);

