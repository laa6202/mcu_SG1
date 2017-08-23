


/* Includes ------------------------------------------------------------------*/
#include "led.h" 


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int d3_flag;

void LED_Init(void)
{ 
//init PA6 PA7 for LED	
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= (0x01 << 12);		//PA6
	GPIOA->MODER |= (0x01 << 14);		//PA7
	D2_Off();
	d3_flag = 1;
	D3_On();
	
//Enable Tim7 for D3 on and off period
	NVIC_EnableIRQ(TIM7_IRQn);
	NVIC_SetPriority(TIM7_IRQn,(7<<1) + 1);
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;		//clk APB1 = 168 /4 = 42MHz
	
	TIM7->PSC = 41999;	//t = 1ms;
	TIM7->ARR = 1000;		
	TIM7->DIER |= TIM_DIER_UIE;
	TIM7->CR1 |= TIM_CR1_ARPE;
	TIM7->CR1 |= TIM_CR1_CEN;
	
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



void TIM7_IRQHandler(void){
	if((TIM7->SR & TIM_SR_UIF) ==  TIM_SR_UIF){
		
		if(d3_flag == 1){
			d3_flag = 0;
			D3_Off();
		}
		else {
			d3_flag = 1;
			D3_On();			
		}
	
		TIM7->SR &= (~TIM_SR_UIF);
	}
	else 
		__nop();
	
}
 



