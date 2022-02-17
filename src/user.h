#ifndef USER_H_
#define USER_H_

#include "stm32f37x.h"

//------ Board port lines definitions ------------------------------

//Shift register serial input
#define SI_GPIO					GPIOA
#define SI_GPIO_Pin			GPIO_Pin_15

//Shift register serial clock
#define SCLK_GPIO				GPIOF
#define SCLK_GPIO_Pin		GPIO_Pin_7

//Shift register latch clock
#define LCLK_GPIO				GPIOF
#define LCLK_GPIO_Pin		GPIO_Pin_6


// -- System clocks init -------------------------------------------
void RCC_init(void);

// -- GPIOs init ---------------------------------------------------
void GPIO_init(void);

// -- 74HC595 Port Extender Definitions ----------------------------
#define K1			(uint16_t) (1<<2)
#define K2			(uint16_t) (1<<3)
#define K3			(uint16_t) (1<<4)
#define K4			(uint16_t) (1<<5)
#define K5			(uint16_t) (1<<6)
#define K6			(uint16_t) (1<<7)
#define K7			(uint16_t) (1<<13)
#define K8			(uint16_t) (1<<14)
#define K9			(uint16_t) (1<<15)
#define K10			(uint16_t) (1<<0)
#define K11			(uint16_t) (1<<1)
#define K12			(uint16_t) (1<<8)
#define K13			(uint16_t) (1<<9)
#define K14			(uint16_t) (1<<10)
#define K15			(uint16_t) (1<<11)
#define K16			(uint16_t) (1<<12)
#define K_NULL	(uint16_t) (0x0000)



// -- 74HC595 Port Extender Set Out Value --------------------------
// Function usage like this:		ShiftRegSetOut(K1 | K3 | K9);
// Will set K... and reset other bits to "low"

void ShiftRegSetOut(uint16_t val);

// -- 74HC595 Set Out Bits (without changing others) ---------------
void ShiftRegSetBits(uint16_t val);

// -- 74HC595 Reset Out Bits (without changing others) -------------
void ShiftRegResetBits(uint16_t val);


// -- Definitions for Step Amplifier state vontrol -----------------

#define ST_AMP_POSITIVE				ShiftRegResetBits(K1);
#define ST_AMP_NEGATIVE				ShiftRegSetBits(K1);

#define ST_AMP_I_RANGE1				ShiftRegResetBits(K3|K4|K5|K6);\
															ShiftRegSetBits(K2);

#define ST_AMP_I_RANGE2				ShiftRegResetBits(K2|K3|K4|K5|K6);

#define ST_AMP_I_RANGE3				ShiftRegResetBits(K3|K4|K6);\
															ShiftRegSetBits(K2|K5);

#define ST_AMP_I_RANGE4				ShiftRegResetBits(K2|K3|K4|K6);\
															ShiftRegSetBits(K5);

#define ST_AMP_I_RANGE5				ShiftRegResetBits(K3|K5|K6);\
															ShiftRegSetBits(K2|K4);

#define ST_AMP_I_RANGE6				ShiftRegResetBits(K2|K3|K5|K6);\
															ShiftRegSetBits(K4);

#define ST_AMP_I_RANGE7				ShiftRegResetBits(K3|K5);\
															ShiftRegSetBits(K2|K4|K6);

#define ST_AMP_I_RANGE8				ShiftRegResetBits(K2|K3|K5);\
															ShiftRegSetBits(K4|K6);

#define ST_AMP_V_RANGE1				ShiftRegResetBits(K4|K5|K6);\
															ShiftRegSetBits(K2|K3);

#define ST_AMP_V_RANGE2				ShiftRegResetBits(K2|K4|K5|K6);\
															ShiftRegSetBits(K3);

#define ST_AMP_V_RANGE3				ShiftRegResetBits(K4|K6);\
															ShiftRegSetBits(K2|K3|K5);

#define ST_AMP_V_RANGE4				ShiftRegResetBits(K2|K4|K6);\
															ShiftRegSetBits(K3|K5);

#define ST_AMP_V_RANGE5				ShiftRegResetBits(K5|K6);\
															ShiftRegSetBits(K2|K3|K4);

#define ST_AMP_V_RANGE6				ShiftRegResetBits(K2|K5|K6);\
															ShiftRegSetBits(K3|K4);

#define ST_AMP_V_RANGE7				ShiftRegResetBits(K5);\
															ShiftRegSetBits(K2|K3|K4|K6);

#define ST_AMP_V_RANGE8				ShiftRegResetBits(K2|K5);\
															ShiftRegSetBits(K3|K4|K6);





#endif
