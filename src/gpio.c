
/* Includes ------------------------------------------------------------------*/
#include "gpio.h" 


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void GPIO_PWM_Init(void)
{    	 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//ʹ��GPIOAʱ��
	GPIOE->MODER |= 0x55;

}


void GPIO_PWN_H(void){
	GPIOE->ODR |= 0xf;
}


void GPIO_PWN_L(void){
	GPIOE->ODR &= 0xfff0;
}






