/*
 * main_app.c
 *
 *  Created on: Jan 14, 2026
 *      Author: etienne.lima
 */

#include "stm32f4xx_hal.h"

void SystemClockConfig(void);
void Error_handler(void);
void TIMER10_Init(void);
void GPIO_Init(void);

TIM_HandleTypeDef htim10;

int main(void)
{
	HAL_Init();
	SystemClockConfig();
	GPIO_Init();
	TIMER10_Init();


	//lets start timer
	HAL_TIM_Base_Start(&htim10);


	while(1)
	{
		/*loop until update flag event is set*/
		while(!(TIM10->SR & TIM_SR_UIF));
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		TIM10->SR = 0;
	}
}

void GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &ledgpio);
}

void Error_handler(void)
{

}
void SystemClockConfig()
{

}

void TIMER10_Init(void)
{
	htim10.Instance = TIM10;
	htim10.Init.Prescaler = 24;
	htim10.Init.Period = 64000 - 1;
	if(HAL_TIM_Base_Init(&htim10) != HAL_OK)
	{
		Error_handler();
	}
}
