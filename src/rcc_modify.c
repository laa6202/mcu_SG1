


/* Includes ------------------------------------------------------------------*/
#include "rcc_modify.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//hope HSE is 25MHz,but the actual HSE is 8MHz,now modify the RCC PLLM config
int rcc_modify(void)
{ 
	RCC->CFGR &= (~RCC_CFGR_SW_HSE);	//0xffffffd;		//sw1 = 0 HSI

	while((RCC->CFGR & RCC_CFGR_SWS_1) == RCC_CFGR_SWS_1);	//wait SW1=0
	
	RCC->CR &= (~RCC_CR_PLLON);		//PLL OFF
	RCC->PLLCFGR &= 0xffffffc0;		//clear PLLM
	RCC->PLLCFGR |= 0x8;					//PLLM = 8
	RCC->CR |= RCC_CR_PLLON;			//PLL ON
	while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY);	//wait PLL rdy
	RCC->CFGR |= RCC_CFGR_SW_HSE;			//sw1 = 1	 HSE
	while((RCC->CFGR & RCC_CFGR_SWS_1) != RCC_CFGR_SWS_1) ;	//wait SW1 = 1;
	
	
	
	return 0;
}



 



