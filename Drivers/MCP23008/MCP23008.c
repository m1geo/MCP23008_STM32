/*
 * MCP23008.c
 *
 *  Created on: Aug 9, 2023
 *      Author: George Smart, M1GEO.
 *         URL: https://github.com/m1geo/MCP23008_STM32
 *         URL: https://www.george-smart.co.uk
 *
 * With influence from https://github.com/RobTillaart/MCP23008
 */

#include "MCP23008.h"

#include "stm32f1xx_hal.h"

HAL_StatusTypeDef MCP23008_Init(I2C_HandleTypeDef *hi2c, MCP23008_HandleTypeDef *hdfm, uint8_t deviceAddress)
{
	// The MCP23008 can only be address 0x20-0x27. Out of this range isn't possible.
	if ( (deviceAddress < 0x20) || (deviceAddress > 0x27) ) return HAL_ERROR; // Return an error (not a HAL error, but it'll do)

	HAL_StatusTypeDef hal_retval;
	hdfm->hi2c = hi2c;
	hdfm->addr = deviceAddress << 1; // store shifted 7b address.

	hal_retval = HAL_I2C_IsDeviceReady(hdfm->hi2c, hdfm->addr, MCP23008_I2C_RETRIES, MCP23008_I2C_DELAY);
	return hal_retval;
}


// dir: When a bit is set, the corresponding pin becomes an input. When a bit is clear, the corresponding pin becomes an output.
uint8_t MCP23008_SetDirection(MCP23008_HandleTypeDef *hdfm, uint8_t dir)
{
	HAL_StatusTypeDef hal_retval;
    uint8_t data[] = { MCP23008_DDR, dir };
    hal_retval = HAL_I2C_Master_Transmit(hdfm->hi2c, hdfm->addr, data, sizeof(data), MCP23008_I2C_DELAY);
    return (uint8_t) hal_retval;
}

uint8_t MCP23008_GetDirection(MCP23008_HandleTypeDef *hdfm)
{
	uint8_t dir;
	HAL_I2C_Mem_Read(hdfm->hi2c, hdfm->addr, MCP23008_DDR, 1, &dir, sizeof(dir), MCP23008_I2C_DELAY);
	return dir;
}



uint8_t MCP23008_SetPolarity(MCP23008_HandleTypeDef *hdfm, uint8_t pol)
{
	HAL_StatusTypeDef hal_retval;
    uint8_t data[] = { MCP23008_POL, pol };
    hal_retval = HAL_I2C_Master_Transmit(hdfm->hi2c, hdfm->addr, data, sizeof(data), MCP23008_I2C_DELAY);
    return (uint8_t) hal_retval;
}

uint8_t MCP23008_GetPolarity(MCP23008_HandleTypeDef *hdfm)
{
	uint8_t pol;
	HAL_I2C_Mem_Read(hdfm->hi2c, hdfm->addr, MCP23008_POL, 1, &pol, sizeof(pol), MCP23008_I2C_DELAY);
	return pol;
}



uint8_t MCP23008_SetPullups(MCP23008_HandleTypeDef *hdfm, uint8_t pull)
{
	HAL_StatusTypeDef hal_retval;
    uint8_t data[] = { MCP23008_PUR, pull };
    hal_retval = HAL_I2C_Master_Transmit(hdfm->hi2c, hdfm->addr, data, sizeof(data), MCP23008_I2C_DELAY);
    return (uint8_t) hal_retval;
}

uint8_t MCP23008_GetPullups(MCP23008_HandleTypeDef *hdfm)
{
	uint8_t pull;
	HAL_I2C_Mem_Read(hdfm->hi2c, hdfm->addr, MCP23008_PUR, 1, &pull, sizeof(pull), MCP23008_I2C_DELAY);
	return pull;
}



uint8_t MCP23008_WriteGPIO(MCP23008_HandleTypeDef *hdfm, uint8_t value)
{
	HAL_StatusTypeDef hal_retval;
    uint8_t data[] = { MCP23008_GPIO, value }; // Write data to GPIO
    hal_retval = HAL_I2C_Master_Transmit(hdfm->hi2c, hdfm->addr, data, sizeof(data), MCP23008_I2C_DELAY);
    return (uint8_t) hal_retval;
}

uint8_t MCP23008_ReadGPIO(MCP23008_HandleTypeDef *hdfm)
{
    uint8_t value;
    HAL_I2C_Mem_Read(hdfm->hi2c, hdfm->addr, MCP23008_GPIO, 1, &value, sizeof(value), MCP23008_I2C_DELAY);
    return value;
}
