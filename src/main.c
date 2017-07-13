


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "led.h"
#include "timer.h"
#include "gpio.h"
#include "pwm_data.h"
#include "adc.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u16 adcx = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int main(void)
{ 
 
	
	LED_Init();		        //��ʼ��LED�˿�
	GPIO_PWM_Init();
	TIM3_Int_Init(999,167);		//2ms

	SysTick->LOAD = 0x1000;
	SysTick->CTRL = 0x3;
	
	Adc_Init();         //��ʼ��ADC
	
	while(1){
	adcx=Get_Adc_Average(ADC_Channel_5,20);//��ȡͨ��5��ת��ֵ��20��ȡƽ��
	int ad_reg = (adcx * 99/ 4096)   +1;
	set_pwm(ad_reg);


	}
}



 



