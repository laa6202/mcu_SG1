


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int main(void)
{ 
	LED_Init();
	rcc_modify();
	init_speaker();
	init_exti_key();
	init_us100();
	
	us100_measure();
	while(1){
		int measure_now = get_measure_now(); 
		if(measure_now !=0){
			us100_measure();
			measure_now = 0;
			set_measure_now(measure_now);
		}
		
	}
	

}



 



