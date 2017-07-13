


/* Includes ------------------------------------------------------------------*/
#include "irq.h"
#include "led.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u32 tim3_count = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
	tim3_count++;
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
	{
		
		
		
		if((tim3_count % 1000) == 1)
			D2_On();
		if((tim3_count % 1000) == 501)
			D2_Off();
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
}
