
#include "main.h"
#include "led.h"
#include "gpio.h"
#include "timer.h"
#include "rng.h"



int main(void)
{ 
 

	LED_Init();		        //³õÊ¼»¯LED¶Ë¿Ú
	GPIO_PB_Init();


	RNG_Init();	
	TIM3_Int_Init(5000,8400-1);		//0.8s

	
	while(1){



	}
}



 



