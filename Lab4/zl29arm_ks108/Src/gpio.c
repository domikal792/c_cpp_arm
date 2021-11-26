/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  //HAL_GPIO_WritePin(GPIOE, LCD_RS_Pin|LCD_E_Pin|LCD_RW_Pin|LCD_CS1_Pin
  //                        |LCD_CS2_Pin|BUZZER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED_1_Pin|LED_2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_EXT_1_Pin|LED_EXT_2_Pin|LED_EXT_3_Pin|LED_EXT_4_Pin
                          |LED_EXT_5_Pin|LED_EXT_6_Pin|LED_EXT_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin */
  //GPIO_InitStruct.Pin = LCD_D2_Pin|LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin
  //                        |LCD_D6_Pin|LCD_D7_Pin|LCD_D0_Pin|LCD_D1_Pin;
  //GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  //GPIO_InitStruct.Pull = GPIO_NOPULL;
  //HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = SW4_Pin|SW_EXT_1_Pin|JOY_UP_Pin|JOY_DOWN_Pin
                          |JOY_RIGHT_Pin|JOY_LEFT_Pin|JOY_OK_Pin|SW3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin */
  GPIO_InitStruct.Pin = SW_EXT_4_Pin|SW_EXT_2_Pin|SW_EXT_6_Pin|SW_EXT_5_Pin
                          |SW_EXT_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin PEPin */
  //GPIO_InitStruct.Pin = BUZZER_Pin|LCD_RS_Pin|LCD_E_Pin|LCD_RW_Pin|LCD_CS1_Pin
  //                        |LCD_CS2_Pin;
  //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  //GPIO_InitStruct.Pull = GPIO_NOPULL;
  //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  //HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = LED_EXT_1_Pin|LED_EXT_2_Pin|LED_EXT_3_Pin|LED_EXT_4_Pin
                          |LED_EXT_5_Pin|LED_EXT_6_Pin|LED_EXT_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
