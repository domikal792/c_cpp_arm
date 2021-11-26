/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_D2_Pin          GPIO_PIN_2
#define LCD_D2_GPIO_Port    GPIOE
#define LCD_D3_Pin          GPIO_PIN_3
#define LCD_D3_GPIO_Port    GPIOE
#define LCD_D4_Pin          GPIO_PIN_4
#define LCD_D4_GPIO_Port    GPIOE
#define LCD_D5_Pin          GPIO_PIN_5
#define LCD_D5_GPIO_Port    GPIOE
#define LCD_D6_Pin          GPIO_PIN_6
#define LCD_D6_GPIO_Port    GPIOE
#define SW4_Pin             GPIO_PIN_13
#define SW4_GPIO_Port       GPIOC
#define SW_EXT_1_Pin        GPIO_PIN_4
#define SW_EXT_1_GPIO_Port  GPIOC
#define JOY_UP_Pin          GPIO_PIN_5
#define JOY_UP_GPIO_Port    GPIOC
#define SW_EXT_4_Pin        GPIO_PIN_1
#define SW_EXT_4_GPIO_Port  GPIOB
#define LCD_D7_Pin          GPIO_PIN_7
#define LCD_D7_GPIO_Port    GPIOE
#define LCD_RS_Pin          GPIO_PIN_8
#define LCD_RS_GPIO_Port    GPIOE
#define LCD_E_Pin           GPIO_PIN_9
#define LCD_E_GPIO_Port     GPIOE
#define LCD_RW_Pin          GPIO_PIN_10
#define LCD_RW_GPIO_Port    GPIOE
#define LCD_CS1_Pin         GPIO_PIN_11
#define LCD_CS1_GPIO_Port   GPIOE
#define LCD_CS2_Pin         GPIO_PIN_12
#define LCD_CS2_GPIO_Port   GPIOE
#define BUZZER_Pin          GPIO_PIN_13
#define BUZZER_GPIO_Port    GPIOE
#define LED_1_Pin           GPIO_PIN_14
#define LED_1_GPIO_Port     GPIOE
#define LED_2_Pin           GPIO_PIN_15
#define LED_2_GPIO_Port     GPIOE
#define SW_EXT_2_Pin        GPIO_PIN_14
#define SW_EXT_2_GPIO_Port  GPIOB
#define SW_EXT_6_Pin        GPIO_PIN_15
#define SW_EXT_6_GPIO_Port  GPIOB
#define JOY_DOWN_Pin        GPIO_PIN_6
#define JOY_DOWN_GPIO_Port  GPIOC
#define JOY_RIGHT_Pin       GPIO_PIN_7
#define JOY_RIGHT_GPIO_Port GPIOC
#define JOY_LEFT_Pin        GPIO_PIN_8
#define JOY_LEFT_GPIO_Port  GPIOC
#define JOY_OK_Pin          GPIO_PIN_9
#define JOY_OK_GPIO_Port    GPIOC
#define SW3_Pin             GPIO_PIN_12
#define SW3_GPIO_Port       GPIOC
#define LED_EXT_1_Pin       GPIO_PIN_1
#define LED_EXT_1_GPIO_Port GPIOD
#define LED_EXT_2_Pin       GPIO_PIN_2
#define LED_EXT_2_GPIO_Port GPIOD
#define LED_EXT_3_Pin       GPIO_PIN_3
#define LED_EXT_3_GPIO_Port GPIOD
#define LED_EXT_4_Pin       GPIO_PIN_4
#define LED_EXT_4_GPIO_Port GPIOD
#define LED_EXT_5_Pin       GPIO_PIN_5
#define LED_EXT_5_GPIO_Port GPIOD
#define LED_EXT_6_Pin       GPIO_PIN_6
#define LED_EXT_6_GPIO_Port GPIOD
#define LED_EXT_7_Pin       GPIO_PIN_7
#define LED_EXT_7_GPIO_Port GPIOD
#define SW_EXT_5_Pin        GPIO_PIN_5
#define SW_EXT_5_GPIO_Port  GPIOB
#define SW_EXT_3_Pin        GPIO_PIN_9
#define SW_EXT_3_GPIO_Port  GPIOB
#define LCD_D0_Pin          GPIO_PIN_0
#define LCD_D0_GPIO_Port    GPIOE
#define LCD_D1_Pin          GPIO_PIN_1
#define LCD_D1_GPIO_Port    GPIOE

#define GLCD_DATA_PORT       GPIOE
#define GLCD_D0_Pin          GPIO_PIN_0
#define GLCD_D0_GPIO_Port    GPIOE
#define GLCD_D1_Pin          GPIO_PIN_1
#define GLCD_D1_GPIO_Port    GPIOE
#define GLCD_D2_Pin          GPIO_PIN_2
#define GLCD_D2_GPIO_Port    GPIOE
#define GLCD_D3_Pin          GPIO_PIN_3
#define GLCD_D3_GPIO_Port    GPIOE
#define GLCD_D4_Pin          GPIO_PIN_4
#define GLCD_D4_GPIO_Port    GPIOE
#define GLCD_D5_Pin          GPIO_PIN_5
#define GLCD_D5_GPIO_Port    GPIOE
#define GLCD_D6_Pin          GPIO_PIN_6
#define GLCD_D6_GPIO_Port    GPIOE
#define GLCD_D7_Pin          GPIO_PIN_7
#define GLCD_D7_GPIO_Port    GPIOE
#define GLCD_CTRL_PORT       GPIOE
#define GLCD_RS_Pin          GPIO_PIN_8
#define GLCD_RS_GPIO_Port    GPIOE
#define GLCD_E_Pin           GPIO_PIN_9
#define GLCD_E_GPIO_Port     GPIOE
#define GLCD_RW_Pin          GPIO_PIN_10
#define GLCD_RW_GPIO_Port    GPIOE
#define GLCD_CS1_Pin         GPIO_PIN_12
#define GLCD_CS1_GPIO_Port   GPIOE
#define GLCD_CS2_Pin         GPIO_PIN_11
#define GLCD_CS2_GPIO_Port   GPIOE


/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
