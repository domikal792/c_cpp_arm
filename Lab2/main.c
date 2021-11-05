#include <stdint.h>
#include <stm32f10x.h>

int main()
{
	GPIOE->CRH |= GPIO_CRH_MODE14_1;
	GPIOE->CRH |= GPIO_CRH_CNF14_0;
	
	for()
	{
		
	}
}
