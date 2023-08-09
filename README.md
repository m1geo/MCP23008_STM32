# MCP23008_STM32
STM32 HAL driver for MCP23008 I2C 8-channel port expander. A simple, bare-bones driver, that would be easily expanded if required. Supports multiple devices on the same device on the same or difference I2C PHYs. Only port-wide operations are supported (no read-mod-write support, yet). If you add any features, please send a pull request.

## Interface

To use, simply include the driver folder into the project, add the folder to the build path, and then include the header in your `main.c` file.

```cpp
#include "MCP23008.h"
```

The driver impliments the following functions:

- **HAL_StatusTypeDef MCP23008_Init(I2C_HandleTypeDef \*hi2c, MCP23008_HandleTypeDef \*hdfm, uint8_t deviceAddress)** - pass the STM32 HAL I2C handle, a MCP23008 device handle, and device address. This allows you to have more than one device (with a different address).
- **uint8_t MCP23008_SetDirection(MCP23008_HandleTypeDef \*hdfm, uint8_t dir)** - Set the direction register. 1=input, 0=output.
- **uint8_t MCP23008_GetDirection(MCP23008_HandleTypeDef \*hdfm)** - Read the direction register. 1=input, 0=output.
- **uint8_t MCP23008_SetPolarity(MCP23008_HandleTypeDef \*hdfm, uint8_t pol)** - Set the polarity register. 1=inverted, 0=as per pin.
- **uint8_t MCP23008_GetPolarity(MCP23008_HandleTypeDef \*hdfm)**  - Read the polarity register. 1=inverted, 0=as per pin.
- **uint8_t MCP23008_SetPullups(MCP23008_HandleTypeDef \*hdfm, uint8_t pull)** - Set the pullups register. 1=pullup enabled, 0=pullup disabled.
- **uint8_t MCP23008_GetPullups(MCP23008_HandleTypeDef \*hdfm)** - Read the pullups register. 1=pullup enabled, 0=pullup disabled.
- **uint8_t MCP23008_WriteGPIO(MCP23008_HandleTypeDef \*hdfm, uint8_t value)** - Set the outputs
- **uint8_t MCP23008_ReadGPIO(MCP23008_HandleTypeDef \*hdfm)** - Read the inputs