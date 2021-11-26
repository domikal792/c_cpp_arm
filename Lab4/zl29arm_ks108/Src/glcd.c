
#include "glcd.h"
#include "string.h"

extern uint8_t glcd_pos_x;
extern uint8_t glcd_pos_y;


void glcd_Initialize(void)
{
    glcd_PortInitialize();
    
    for(uint8_t i = 0; i < 2; i++)
        glcd_WriteCommand(i, GLCD_CMD_ON_OFF | GLCD_CMD_ON);
}


void glcd_ClearScreen(void)
{
    for(uint8_t j = 0; j < (GLCD_HEIGHT / 8); j++)
    {
        glcd_GoTo(0, j);
 
        for(uint8_t i = 0; i < GLCD_WIDTH; i++)
            glcd_WriteData(0x00);
    }
    
    glcd_GoTo(0, 0);
}


void glcd_GoTo(uint8_t pos_x, uint8_t pos_y)
{
    glcd_pos_x = pos_x;
    glcd_pos_y = pos_y;

    for(uint8_t i = 0; i < (GLCD_WIDTH / 64); i++)
    {
        glcd_WriteCommand(i, GLCD_CMD_SET_Y | 0);
        glcd_WriteCommand(i, GLCD_CMD_SET_X | pos_y);
        glcd_WriteCommand(i, GLCD_CMD_SET_LINE | 0);
    }

    glcd_WriteCommand((pos_x /64), GLCD_CMD_SET_Y | (pos_x % 64));
    glcd_WriteCommand((pos_x /64), GLCD_CMD_SET_X | pos_y);
    glcd_WriteCommand((pos_x /64), GLCD_CMD_SET_LINE | 0);
}


void glcd_PutPixel(uint8_t pos_x, uint8_t pos_y, uint8_t color)
{
    uint8_t tmp;
    
    glcd_GoTo(pos_x, (pos_y / 8));
    tmp = glcd_ReadData();
    glcd_GoTo(pos_x, (pos_y / 8));
    tmp = glcd_ReadData();
    glcd_GoTo(pos_x, (pos_y / 8));
    
    if (color != 0)
    {
        tmp |= (1 << (pos_y % 8));
    }
    else
    {
        tmp &= ~(1 << (pos_y % 8));
    }
    glcd_WriteData(tmp);    
}


void glcd_PutChar(uint8_t c)
{
    for(uint8_t i = 0; i < 5; i++)
        glcd_WriteData(font5x7[5 * c + i]);
}

void glcd_WriteString(uint8_t pos_x, uint8_t pos_y, const char* p_str)
{
	const uint32_t MAX_LINE_LEN = 25U;
	const uint32_t LINES_NUM = 8U;
	const uint32_t MAX_STR_LEN = MAX_LINE_LEN * LINES_NUM;
	uint8_t line_no = pos_x;
	
	glcd_GoTo(pos_x, pos_y);
	
	for (uint32_t i = 0U; i < MAX_STR_LEN; ++i)
	{
		uint8_t chars_num = 0U;
		
		for (uint32_t j = 0U; j < MAX_LINE_LEN; ++j)
		{
			if (*(p_str + j) == NULL)
			{
				chars_num = j;
				break;
			}
			
			if (*(p_str + j) == ' ')
			{
				chars_num = j;
			}
		}
		
		if (*(p_str + chars_num) == NULL)
		{
			break;
		}
		
		for (uint8_t j = 0U; j < chars_num; ++j)
		{
			glcd_PutChar(*(p_str++));
		}
		
		line_no += 1U;
		glcd_GoTo(0, line_no);
		
		/*
		glcd_PutChar(*(p_str++));
		
		if (*p_str == NULL)
		{
			break;
		}*/
	}
}
