
/* Includes ------------------------------------------------------------------*/
#include "exti_key.h"
#include "led.h"
#include "speaker.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int init_exti_key(void){
	//K0 - PE4		K1 - PE3		press down
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	GPIOE->MODER |= 0x0 << 6; //PE3 	input
	GPIOE->MODER |= 0x0 << 8; //PE4 	input
	GPIOE->PUPDR |= 0x1 << 6;	//PE3 	pull up
	GPIOE->PUPDR |= 0x1 << 8;	//PE4 	pull up
	
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PE;		//EXTI3 - PE
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PE;		//EXTI4 - PE
	
	EXTI->IMR |= EXTI_IMR_MR3;	//mask open exti3
	EXTI->IMR |= EXTI_IMR_MR4;	//mask open exti4
	EXTI->FTSR |= EXTI_FTSR_TR3;
	EXTI->FTSR |= EXTI_FTSR_TR4;
	
	
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	
	return 0;
}


void EXTI3_IRQHandler(void){
	EXTI->IMR &= (~ EXTI_IMR_MR3);
	__nop();
	speak_content(1);
	EXTI->PR |= 0x1 <<3;		//clear pending
	EXTI->IMR |= EXTI_IMR_MR3;
}

void EXTI4_IRQHandler(void){
	EXTI->IMR &= (~ EXTI_IMR_MR4);
	__nop();
	speak_content(2);
	EXTI->PR |= 0x1 <<4;		//clear pending
	EXTI->IMR |= EXTI_IMR_MR4;
}


