


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
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= (0x01 << 12);		//PA6
	GPIOA->MODER |= (0x01 << 14);		//PA7
	D2_Off();
	D3_On();
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






