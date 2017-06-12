#include "sys.h"
#include "delay.h"
#include "led.h"
#include "exti.h"


//ÅÜÂíµÆÊµÑé -¿âº¯Êý°æ±¾
//STM32F4¹¤³ÌÄ£°å-¿âº¯Êý°æ±¾
//ÌÔ±¦µêÆÌ£ºhttp://mcudev.taobao.com

int main(void)
{ 
 
	delay_init(168);		  //³õÊ¼»¯ÑÓÊ±º¯Ê
	EXTIX_Init();       //
	LED_Init();		        //³õÊ¼»¯LED¶Ë¿Ú
	
	while(1){
		D2_On();
		delay_ms(500);
		D2_Off();
		delay_ms(500);
	}
}



 



