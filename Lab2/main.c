#include <stdint.h>
#include <stm32f10x.h>
//#include "main.h"

void delay(void)
{
	for(volatile uint32_t d=0; d < 1E6; d++);
}

int main()
{
	*((uint32_t*)0x40021018)|= (uint32_t)0x40; //RCCBASE
	
	GPIOE->CRH |= GPIO_CRH_MODE14_1;
	GPIOE->CRH |= GPIO_CRH_CNF14_0;
	
	for(;;)
	{
		GPIOE->ODR ^= GPIO_ODR_ODR14;
		delay();
	}
}
