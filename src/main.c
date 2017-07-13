


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "led.h"
#include "timer.h"
#include "gpio.h"
#include "pwm_data.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int main(void)
{ 
 
	
	LED_Init();		        //��ʼ��LED�˿�
	GPIO_PWM_Init();
	TIM3_Int_Init(9999,167);		//20ms

		SysTick->LOAD = 0x10000;
		SysTick->CTRL = 0x3;
	
	
	while(1){

		set_pwm(100);	//for debug


	}
}



 



