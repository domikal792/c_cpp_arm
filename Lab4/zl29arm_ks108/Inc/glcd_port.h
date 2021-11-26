#ifndef GLCD_PORT_H
#define GLCD_PORT_H

#include <stdint.h>
#include "main.h"
#include "tim.h"

#define GLCD_STATUS_BUSY    0x80
#define GLCD_WAITTIME       1

//-------------------------------------------------------------------------------------------------
// Enalbe/Disable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void glcd_EnableController(uint8_t controller);
void glcd_DisableController(uint8_t controller);

//-------------------------------------------------------------------------------------------------
// Read/Write Status/Command byte from specified controller (0-2)
//-------------------------------------------------------------------------------------------------
uint8_t glcd_ReadStatus(uint8_t controller);
void glcd_WriteCommand(uint8_t controller, uint8_t command);

//-------------------------------------------------------------------------------------------------
// Read/Write data from/to current position
//-------------------------------------------------------------------------------------------------
uint8_t glcd_ReadData(void);
void glcd_WriteData(uint8_t data);

void glcd_PortInitialize(void);

#endif//GLCD_PORT_H
