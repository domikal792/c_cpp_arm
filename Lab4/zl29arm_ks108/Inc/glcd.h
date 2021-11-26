#ifndef GLCD_H
#define GLCD_H

#include "glcd_port.h"
#include "font.h"
#include "stdint.h"

#define GLCD_WIDTH		    128
#define GLCD_HEIGHT	        64

#define GLCD_CMD_SET_Y      0x40
#define GLCD_CMD_SET_X      0xB8
#define GLCD_CMD_SET_LINE   0xC0
#define GLCD_CMD_ON_OFF		0x3E
  #define GLCD_CMD_ON	    0x01
  #define GLCD_CMD_OFF	    0x00
#define GLCD_STATUS_BUSY    0x80

void glcd_Initialize(void);
void glcd_ClearScreen(void);
void glcd_GoTo(uint8_t pos_x, uint8_t pos_y);
void glcd_PutPixel(uint8_t pos_x, uint8_t pos_y, uint8_t color);
void glcd_PutChar(uint8_t c);
void glcd_WriteString(uint8_t pos_x, uint8_t pos_y, const char* p_str);
    
#endif//GLCD_H
