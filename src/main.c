


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
u16 adc_s1 = 0;
float adc_s2 = 0;
float adc_s3 = 0;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int main(void)
{ 
 
	
	LED_Init();		        //初始化LED端口
	GPIO_PWM_Init();
	TIM3_Int_Init(999,167);		//2ms

	SysTick->LOAD = 0x1000;
	SysTick->CTRL = 0x3;
	
	Adc_Init();         //初始化ADC

	while(1){
	adc_s1 =	Get_Adc_Average(ADC_Channel_5,20);//获取通道5的转换值，20次取平均
	adc_s2 =	ad_step1(adc_s1);
	adc_s3 =	ad_step2(adc_s2);

	set_pwm_f32(adc_s3);
	}
	

}



 



