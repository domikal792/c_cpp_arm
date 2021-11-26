/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "glcd.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  glcd_Initialize();
  glcd_ClearScreen();
  
  /*
  for (uint8_t y = 0; y < GLCD_HEIGHT; y++)
    for (uint8_t x = 0; x < GLCD_WIDTH; x++)
    {
        glcd_PutPixel(x, y, 1);
        //HAL_Delay(1);
    }

  for (uint8_t y = 0; y < GLCD_HEIGHT; y++)
    for (uint8_t x = 0; x < GLCD_WIDTH; x++)
    {
        glcd_PutPixel(x, y, 0);
        //HAL_Delay(1);
    }
  
  for (uint8_t z =0; z < 64; z++)
  {
    glcd_WriteCommand(0, GLCD_CMD_SET_LINE | z);  
    glcd_WriteCommand(1, GLCD_CMD_SET_LINE | z);  
    HAL_Delay(100);
  }
  */

  //glcd_PutPixel(0, 0, 1);
  //glcd_PutPixel(127, 63, 1);
  //glcd_PutPixel(20, 20, 1);
	
  glcd_GoTo(0, 0);
	//glcd_WriteString("Hello World!");
	glcd_WriteString(0, 0,
		"Lorem Ipsum is simply dummy text of the printing and typesetting industry. "
		"Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, "
		"when an unknown printer took a galley of type and scrambled it to make a type "
		"specimen book. It has survived not only five centuries, but also the leap into "
		"electronic typesetting, remaining essentially unchanged. It was popularised "
		"in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, "
		"and more recently with desktop publishing software like Aldus PageMaker including "
		"versions of Lorem Ipsum."
	);
	
/*
  glcd_GoTo(0, 0);
  glcd_PutChar('A');
  glcd_GoTo(10, 1);
  glcd_PutChar('B');
  glcd_GoTo(20, 2);
  glcd_PutChar('C');
  glcd_GoTo(30, 3);
  glcd_PutChar('D');
  glcd_GoTo(40, 4);
  glcd_PutChar('E');
  glcd_GoTo(50, 5);
  glcd_PutChar('F');
  glcd_GoTo(60, 6);
  glcd_PutChar('G');
  glcd_GoTo(70, 7);
  glcd_PutChar('H');

  glcd_GoTo(80, 0);
  glcd_PutChar('I');
  glcd_GoTo(90, 1);
  glcd_PutChar('J');
  glcd_GoTo(100, 2);
  glcd_PutChar('K');
  glcd_GoTo(110, 3);
  glcd_PutChar('L');
  glcd_GoTo(120, 4);
  glcd_PutChar('M');
*/
  uint8_t z = 0;
  for (;;)
  {
    glcd_WriteCommand(0, GLCD_CMD_SET_LINE | (z & 0x3F));  
    glcd_WriteCommand(1, GLCD_CMD_SET_LINE | (z & 0x3F));  
    HAL_Delay(400);
    z++;
  }


/* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
  //glcd_SetDataPortAsInput();
  //GPIOE->ODR &= 0xFF00;
  //GPIOE->ODR |= 0x0055;
  
  
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
      
    for (uint16_t i = 0; i < 100; i++)
      HAL_TIM7_Delay_us(1000);
      
    if ((glcd_ReadStatus(0) & GLCD_STATUS_BUSY) == 0)
        HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
      
      
      
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV5;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_PLL2;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL2_ON;
  RCC_OscInitStruct.PLL2.PLL2MUL = RCC_PLL2_MUL8;
  RCC_OscInitStruct.PLL2.HSEPrediv2Value = RCC_HSE_PREDIV2_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the Systick interrupt time
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
