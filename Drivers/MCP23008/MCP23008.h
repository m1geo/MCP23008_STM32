/*
 * MCP23008.h
 *
 *  Created on: Aug 9, 2023
 *      Author: George Smart, M1GEO.
 *         URL: https://github.com/m1geo/MCP23008_STM32
 *         URL: https://www.george-smart.co.uk
 *
 * With influence from https://github.com/RobTillaart/MCP23008
 */

#ifndef _MCP23008_H_
#define _MCP23008_H_

#include "stm32f1xx_hal.h"

// I2C Timeout Delay & Retries
#define MCP23008_I2C_DELAY   500
#define MCP23008_I2C_RETRIES   3

// MCP23008 Registers               //   DESCRIPTION                  DATASHEET
#define MCP23008_DDR        0x00    //   Data Direction Register A      P 10
#define MCP23008_POL        0x01    //   Input Polarity A               P 11
#define MCP23008_GPINTEN    0x02    //   NOT USED interrupt enable      P 12
#define MCP23008_DEFVAL     0x03    //   NOT USED interrupt def         P 13
#define MCP23008_INTCON     0x04    //   NOT USED interrupt control     P 14
#define MCP23008_IOCR       0x05    //   NOT USED IO control register   P 15
#define MCP23008_PUR        0x06    //   Pull Up Resistors A            P 16
#define MCP23008_INTF       0x07    //   NOT USED interrupt flag        P 17
#define MCP23008_INTCAP     0x08    //   NOT USED interrupt capture     P 18
#define MCP23008_GPIO       0x09    //   General Purpose IO A           P 19
#define MCP23008_OLAT       0x0A    //   NOT USED output latch          P 20

typedef struct {
	I2C_HandleTypeDef *hi2c;
	uint16_t addr;
} MCP23008_HandleTypeDef;

// Function prototypes
HAL_StatusTypeDef MCP23008_Init(I2C_HandleTypeDef *hi2c, MCP23008_HandleTypeDef *hdfm, uint8_t deviceAddress);
uint8_t MCP23008_SetDirection(MCP23008_HandleTypeDef *hdfm, uint8_t dir);
uint8_t MCP23008_GetDirection(MCP23008_HandleTypeDef *hdfm);
uint8_t MCP23008_SetPolarity(MCP23008_HandleTypeDef *hdfm, uint8_t pol);
uint8_t MCP23008_GetPolarity(MCP23008_HandleTypeDef *hdfm);
uint8_t MCP23008_SetPullups(MCP23008_HandleTypeDef *hdfm, uint8_t pull);
uint8_t MCP23008_GetPullups(MCP23008_HandleTypeDef *hdfm);
uint8_t MCP23008_WriteGPIO(MCP23008_HandleTypeDef *hdfm, uint8_t value);
uint8_t MCP23008_ReadGPIO(MCP23008_HandleTypeDef *hdfm);

#endif /* _MCP23008_H_ */
