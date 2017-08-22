


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include "action.h"


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
	


	while(1){
		int st_main = get_main();
		switch (st_main) {
			case S_CAP:
				__nop();
				set_main(S_WEIGHT);
				break;
			case S_WEIGHT:
				__nop();
				set_main(S_HEIGHT);
				break;
			case S_HEIGHT:
				action_height();
				set_main(S_CALC);			
				break;
			case S_CALC:
				__nop();
				set_main(S_SPEAK);
				break;
			case S_SPEAK:
				action_speak();
				set_main(S_IDLE);
				break;
			default : ;

			
		}
	}
	

}



 



