


/* Includes ------------------------------------------------------------------*/
#include "led.h" 


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



void LED_Init(void)
{    	 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIOA->MODER |= (0x01 << 12);
	GPIOA->MODER |= (0x01 << 14);
}


void D2_On(void){
	GPIOA->ODR &= 0xffbf;
}


void D2_Off(void){
	GPIOA->ODR |= (0x1 << 6);
}


void D3_On(void){
	GPIOA->ODR &= 0xff7f;
}


void D3_Off(void){
	GPIOA->ODR |= (0x1 << 7);
}






