#ifndef USER_H_
#define USER_H_


//------ Board port lines definitions ------------------

//Shift register serial input
#define SI_GPIO				GPIOA
#define SI_GPIO_Pin			GPIO_Pin_15

//Shift register serial clock
#define SCLK_GPIO			GPIOF
#define SCLK_GPIO_Pin		GPIO_Pin_7

//Shift register latch clock
#define LCLK_GPIO			GPIOF
#define LCLK_GPIO_Pin		GPIO_Pin_6


// -- System clocks init -------------------------------
void RCC_init(void);

// -- GPIOs init ---------------------------------------
void GPIO_init(void);


// -- 74HC595 Port Extender Definitions ----------------
#define K1		2
#define K2		3
#define K3		4
#define K4		5
#define K5		6
#define K6		7
#define K7		13
#define K8		14
#define K9		15
#define K10		0
#define K11		1
#define K12		8
#define K13		9
#define K14		10
#define K15		11
#define K16		12


// -- 74HC595 Port Extender Set Out Value --------------
void SetShiftRegOut (uint16_t val);

#endif
