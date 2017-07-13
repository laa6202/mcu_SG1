


/* Includes ------------------------------------------------------------------*/
#include "irq.h"
#include "led.h"
#include "pwm_data.h"
#include "gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u32 tim3_count = 0;
u32 befor = 0;
u32 now   = 0;
u32 diff  = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		u32 pwm_data = get_pwm();
		u32 pwm_cycle = pwm_data * 0x50000 / 100;
		SysTick->LOAD = pwm_cycle;
		SysTick->CTRL = 0x3;
		D3_On();
		GPIO_PWN_H();		
	
		
		tim3_count++;
		if((tim3_count % 100) == 1)
			D2_On();
		if((tim3_count % 100) == 51)
			D2_Off();
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}


void act_SysTickFlag(void){
	SysTick ->CTRL = 0;
	D3_Off();
	GPIO_PWN_L();
}


/*
freq(AHB) = 168MHz
freq(SysTick) = freq(AHB) / 8 = 21MHz
21 cycle = 1us


*/
