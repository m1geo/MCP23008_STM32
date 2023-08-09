/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: George Smart, M1GEO.
 *         URL: https://github.com/m1geo/MCP23008_STM32
 *         URL: https://www.george-smart.co.uk
 *
 * This code is designed to give you the idea, as is not a functional example.
 * It shows the key steps needed.
 */
 
#include "main.h"
#include "MCP23008.h"

#define MCP23008_ADDR_A  0x20
#define MCP23008_ADDR_B  0x21

I2C_HandleTypeDef hi2c2;

MCP23008_HandleTypeDef MCP23hdev_A;
MCP23008_HandleTypeDef MCP23hdev_B;

uint8_t temp_var;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_I2C2_Init();
  
  if (MCP23008_Init(&hi2c2, &MCP23hdev_A, MCP23008_ADDR_A) != HAL_OK){
    printf("Can't initialise MCP23008_A!\r\n");
  }
  MCP23008_SetDirection(&MCP23hdev_A, 0x7F); // 1's are input.

  if (MCP23008_Init(&hi2c2, &MCP23hdev_B, MCP23008_ADDR_B) != HAL_OK){
    printf("Can't initialise MCP23008_B!\r\n");
  }
  MCP23008_SetDirection(&MCP23hdev_B, 0x00); // 0's are output.

  while (1)
  {
    temp_var = MCP23008_ReadGPIO(&MCP23hdev_A);
    HAL_Delay(100);
    MCP23008_WriteGPIO(&MCP23hdev_B, temp_var);
    HAL_Delay(100);
  }
}
