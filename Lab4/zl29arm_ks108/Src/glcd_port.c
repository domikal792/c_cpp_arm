
#include "glcd_port.h"

uint8_t glcd_pos_x = 0;
uint8_t glcd_pos_y = 0;


void glcd_EnableController(uint8_t controller)
{
    switch(controller)
    {
        case 0 : HAL_GPIO_WritePin(GLCD_CS1_GPIO_Port, GLCD_CS1_Pin, GPIO_PIN_RESET);
                 break;
        case 1 : HAL_GPIO_WritePin(GLCD_CS2_GPIO_Port, GLCD_CS2_Pin, GPIO_PIN_RESET);
                 break;
        default: ;
	}
}


void glcd_DisableController(uint8_t controller)
{
    switch(controller)
    {
        case 0 : HAL_GPIO_WritePin(GLCD_CS1_GPIO_Port, GLCD_CS1_Pin, GPIO_PIN_SET);
                 break;
        case 1 : HAL_GPIO_WritePin(GLCD_CS2_GPIO_Port, GLCD_CS2_Pin, GPIO_PIN_SET);
                 break;
        default: ;
	}
}

void glcd_SetDataPortAsInput(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0, 0, 0, 0};

    GPIO_InitStruct.Pin = LCD_D2_Pin|LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin|LCD_D0_Pin|LCD_D1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GLCD_DATA_PORT, &GPIO_InitStruct);
}


uint8_t glcd_ReadStatus(uint8_t controller)
{
    uint8_t status;

    glcd_SetDataPortAsInput();
    
    HAL_GPIO_WritePin(GLCD_RW_GPIO_Port, GLCD_RW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_RS_GPIO_Port, GLCD_RS_Pin, GPIO_PIN_RESET);
    
    glcd_EnableController(controller);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_SET);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);

    status = (uint8_t)((GLCD_DATA_PORT->IDR) & 0x00FF);
    //if (HAL_GPIO_ReadPin(GLCD_DATA_PORT, GLCD_D7_Pin) == GPIO_PIN_RESET) status = 0x00;
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_RESET);

    glcd_DisableController(controller);
    
    return status;
}

void glcd_SetDataPortAsOutput(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0, 0, 0, 0};

    GPIO_InitStruct.Pin = LCD_D2_Pin|LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin|LCD_D0_Pin|LCD_D1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GLCD_DATA_PORT, &GPIO_InitStruct);
}


void glcd_WriteCommand(uint8_t controller, uint8_t command)
{
    while((glcd_ReadStatus(controller) & GLCD_STATUS_BUSY));
    
    HAL_GPIO_WritePin(GLCD_RW_GPIO_Port, GLCD_RW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GLCD_RS_GPIO_Port, GLCD_RS_Pin, GPIO_PIN_RESET);
    glcd_SetDataPortAsOutput();
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    glcd_EnableController(controller);
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    GLCD_DATA_PORT->ODR &= 0xFF00;
    GLCD_DATA_PORT->ODR |= (command & 0x00FF);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_SET);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_RESET);
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);

    glcd_DisableController(controller);
}


uint8_t glcd_ReadData(void)
{
    uint8_t tmp;
    
    while( glcd_ReadStatus(glcd_pos_x / 64) & GLCD_STATUS_BUSY );

    glcd_SetDataPortAsInput();
    HAL_GPIO_WritePin(GLCD_RW_GPIO_Port, GLCD_RW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_RS_GPIO_Port, GLCD_RS_Pin, GPIO_PIN_SET);
    
    glcd_EnableController(glcd_pos_x / 64);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
   
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_SET);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    tmp = (GLCD_DATA_PORT->IDR) & 0x00FF;
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_RESET);

    glcd_DisableController(glcd_pos_x / 64);
    glcd_pos_x++;
    //if (glcd_pos_x > 127) glcd_pos_x = 0; 

    return tmp;
}


void glcd_WriteData(uint8_t data)
{
    while( glcd_ReadStatus(glcd_pos_x / 64) & GLCD_STATUS_BUSY );
   
    HAL_GPIO_WritePin(GLCD_RW_GPIO_Port, GLCD_RW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GLCD_RS_GPIO_Port, GLCD_RS_Pin, GPIO_PIN_SET);
    glcd_SetDataPortAsOutput();
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);

    glcd_EnableController(glcd_pos_x / 64);
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);

    GLCD_DATA_PORT->ODR &= 0xFF00;
    GLCD_DATA_PORT->ODR |= (data & 0x00FF);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_SET);
    HAL_TIM7_Delay_us(GLCD_WAITTIME);
    HAL_GPIO_WritePin(GLCD_E_GPIO_Port, GLCD_E_Pin, GPIO_PIN_RESET);
    //HAL_TIM7_Delay_us(GLCD_WAITTIME);

    glcd_DisableController(glcd_pos_x / 64);
    glcd_pos_x++;
    //if (glcd_pos_x > 127) glcd_pos_x = 0; 
}

void glcd_PortInitialize(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0, 0, 0, 0};

    __HAL_RCC_GPIOE_CLK_ENABLE();  
    
    GPIO_InitStruct.Pin = LCD_D2_Pin|LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin|LCD_D0_Pin|LCD_D1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LCD_RS_Pin|LCD_E_Pin|LCD_RW_Pin|LCD_CS1_Pin
                          |LCD_CS2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    
    HAL_GPIO_WritePin(GLCD_RS_GPIO_Port, GLCD_RS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_RW_GPIO_Port, GLCD_RW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_CS1_GPIO_Port, GLCD_CS1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_CS2_GPIO_Port, GLCD_CS2_Pin, GPIO_PIN_SET);
}
