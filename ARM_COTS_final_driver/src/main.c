#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_int.h"

int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_APB1,RCC_EN_GPIOA);
	while(1)
	{

	}
}
