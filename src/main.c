


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


//int uid_match =0;


int check_uid(){
	int uid_match;
	u32 uid[3];
	uid[0] = (*(volatile uint32_t *)0x1fff7a10);
	uid[1] = (*(volatile uint32_t *)0x1fff7a14);
	uid[2] = (*(volatile uint32_t *)0x1fff7a18);
	if((uid[2] == get_key(2)) & (uid[1] == get_key(1))&(uid[0] == get_key(0)))
		uid_match = 1;
	else
		uid_match = 0;
	return uid_match;
}

int core_init(){
	int uid_match;
	rcc_modify();									//system clock = 168MHz
	NVIC_SetPriorityGrouping(4);	//use 3:1 priority
	uid_match = check_uid();
	return uid_match;
}


int main(void)
{ 
	int uid_match = 0;
	uid_match = core_init();
	LED_Init();
	speaker_init();
	raspi_init();
	us100_init();
	exti_key_init();

	


	while(uid_match){
		int st_main = get_main();
		switch (st_main) {
			case S_IDLE:		//use EXTI2_IRQHandler set_main(S_CAP)
				__nop();
				break;
			case S_CAP:		//use SPI2_IRQHandler -> action_raspi -> write_regs -> write_status(S_WEIGHT)
				__nop();
				break;
			case S_WEIGHT:
				__nop();
				set_main(S_HEIGHT);
				break;
			case S_HEIGHT:
	//			action_height();
				set_main(S_CALC);			
				break;
			case S_CALC: 	//use SPI2_IRQHandler -> action_raspi -> write_regs -> write_status(S_WEIGHT)
				__nop();
				break;
			case S_SPEAK:
	//			action_speak();
				set_main(S_IDLE);
				break;
			default : ;
		}	//switch
	}	//while( uid_match == 0 )
	
	while(1){
		D2_On();
		D3_On();
		__nop();
	}	;
	
}





