#include "user.h"

// -- System clocks init -------------------------------------------
void RCC_init(void)
{
RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOA, ENABLE);
RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOB, ENABLE);
RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOE, ENABLE);
RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOF, ENABLE);
}


// -- GPIOs init ---------------------------------------------------
void GPIO_init(void)
{
GPIO_InitTypeDef GPIO_InitStruct;

// Serial output for 74HC595 shift register
GPIO_InitStruct.GPIO_Pin   = SI_GPIO_Pin;
GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_1;
GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
GPIO_Init(SI_GPIO, &GPIO_InitStruct);

// Serial clock for 74HC595 shift register
GPIO_InitStruct.GPIO_Pin   = SCLK_GPIO_Pin;
GPIO_Init(SCLK_GPIO, &GPIO_InitStruct);

// Latch clock for 74HC595 shift register
GPIO_InitStruct.GPIO_Pin   = LCLK_GPIO_Pin;
GPIO_Init(LCLK_GPIO, &GPIO_InitStruct);

// Reset control lines to "low" on init phase
GPIO_ResetBits(SI_GPIO, SI_GPIO_Pin);
GPIO_ResetBits(SCLK_GPIO, SCLK_GPIO_Pin);
GPIO_ResetBits(LCLK_GPIO, LCLK_GPIO_Pin);

// Set all shift reg. outputs to "low" on init phase
SetShiftRegOut(K_NULL);
}





static uint16_t sh_reg;		// Cached shift reg. state


// -- 74HC595 Port Extender Set Out Value --------------------------
void ShiftRegSetOut(uint16_t val)
{
uint8_t j;

	// Save new state of shift register
	sh_reg = val;	
	
	// Shift out data to register
	for (j=0; j<16; j++)
	{
		if ( (val<<j) & 0x8000)	//Set "high" on data line
		{
		GPIO_SetBits(SI_GPIO, SI_GPIO_Pin);
		}
		else										//Set "low" on data line
		{
		GPIO_ResetBits(SI_GPIO, SI_GPIO_Pin);
		}
	
	// Form rising edge on shift clock (SCLK) line -> set "high", then "low"
	GPIO_SetBits(SCLK_GPIO, SCLK_GPIO_Pin);
	GPIO_ResetBits(SCLK_GPIO, SCLK_GPIO_Pin);
	}
	
	// Form rising edge on latch clock (LCLK) line -> set "high", then "low"
	GPIO_SetBits(LCLK_GPIO, LCLK_GPIO_Pin);
	GPIO_ResetBits(LCLK_GPIO, LCLK_GPIO_Pin);
}


// -- 74HC595 Set Out Bits (without changing others) ---------------
void ShiftRegSetBits(uint16_t val)
{
//Put on set-mask and got reg. state cached
ShiftRegSetOut(sh_reg | val);
}


// -- 74HC595 Reset Out Bits (without changing others) -------------
void ShiftRegResetBits(uint16_t val)
{
//Put on reset-mask and got reg. state cached
ShiftRegSetOut(sh_reg & ~val);
}

// *****************************************************************

