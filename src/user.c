#include "user.h"
#include "stm32f37x.h"

// -- System clocks init --------------------------------------
void RCC_init(void)
{

}


// -- GPIOs init ----------------------------------------------
void GPIO_init(void)
{

}


// -- 74HC595 Port Extender Set Out Value ---------------------
void SetShiftRegOut (uint16_t val)
{
uint8_t j;

	// Shift out data to register
	for (j=0; j++; j<16)
	{
		if ( (val<<j) & 0x8000))	//Set "high" on data line
		{
		
		}
		else						//Set "low" on data line
		{
		
		}
	// Form rising edge on shift clock (SCLK) line -> set "high", then "low"
	
	
	}
	
	// Form rising edge on latch clock (LCLK) line -> set "high", then "low"


}
// *************************************************************

