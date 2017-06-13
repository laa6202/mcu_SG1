#include "sys.h"
#include "delay.h"
#include "led.h"
#include "gpio.h"
#include "exti.h"
#include "uart.h"



int main(void)
{ 
 
	delay_init(168);		  //³õÊ¼»¯ÑÓÊ±º¯Ê
	EXTIX_Init();       //
	LED_Init();		        //³õÊ¼»¯LED¶Ë¿Ú
	GPIO_PB_Init();
	uart_init(115200);
	
	while(1){
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		D2_On();
		delay_ms(400);
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		D2_Off();
		delay_ms(400);
		printf("abcs");
	}
}



 



