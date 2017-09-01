


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


int uid_match =0;


int check_uid(){
	u32 uid[3];
	uid[0] = (*(volatile uint32_t *)0x1fff7a10);
	uid[1] = (*(volatile uint32_t *)0x1fff7a14);
	uid[2] = (*(volatile uint32_t *)0x1fff7a18);
	if((uid[2] == get_key(2)) & (uid[1] == get_key(1))&(uid[0] == get_key(0)))
		uid_match = 1;
	else
		uid_match = 0;
	return 0;
}

int core_init(){
	rcc_modify();									//system clock = 168MHz
	NVIC_SetPriorityGrouping(4);	//use 3:1 priority
	check_uid();
	return 0;
}


int main(void)
{ 
	uid_match = 0;
	core_init();
	LED_Init();
	speaker_init();
	raspi_init();
	us100_init();
	exti_key_init();

	


	while(uid_match){
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
		}	//switch
	}	//while( res_core_init == 0 )
	
	while(1){
		D2_On();
		D3_On();
		__nop();
	}	;
	
}





