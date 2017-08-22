
/* Includes ------------------------------------------------------------------*/
#include "us100.h"
#include "led.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char us100_dh;
char us100_dl;
char us100_vld;
int height;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int init_us100(void){
	//using uart6 PC6/PC7 to speaker control
	RCC->APB2ENR |= RCC_APB2ENR_USART6EN;		//	168MHz/2 = 84MHz
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;		//	168MHz
	
	NVIC_EnableIRQ(USART6_IRQn);
	
	GPIOC->MODER |= 0x2 << 12;  //PC6 -- UART6_TX
	GPIOC->MODER |= 0x2 << 14;  //PC7 -- UART6_RX
	GPIOC->AFR[0] |= 0x8 << 24;		//PC6-AF8
	GPIOC->AFR[0] |= 0x80000000;//0x8 << 28;		//PC7-AF8
	
	//freq div = 84000000 / (16 * 9600) = 546.875
	USART6->BRR |= 546 << 4;		
	USART6->BRR |= 14;

	USART6->CR1 |= USART_CR1_RXNEIE;
	
	USART6->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART6->CR1 |= USART_CR1_UE;
	
	us100_vld =0;
	
	return 0;
}


void USART6_IRQHandler(void){
	D2_On();
	if((USART6->SR & USART_SR_RXNE) == USART_SR_RXNE){
		if(us100_vld == 0)
			us100_dh = USART6->DR;	
		else 
			us100_dl = USART6->DR;	
		us100_vld = us100_vld + 1;
		if(us100_vld == 2)
			height = us100_dh * 256 + us100_dl;
	}
	D2_Off();
}


int us100_putch(char c){
	us100_vld = 0;
	while((USART6->SR & USART_SR_TC)!= USART_SR_TC);	
	USART6->DR = c;
	
	return 0;
}


int us100_measure(void){
	us100_putch(0x55);
	__nop();
	while(us100_vld != 2) 
		__nop();;
	return height;
}


int get_height(void){
	return height;
}



