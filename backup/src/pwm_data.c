

/* Includes ------------------------------------------------------------------*/
#include "pwm_data.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u32 pwm_data = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void set_pwm(u32 data){
	pwm_data = data;
}

void set_pwm_f32(float data){
	pwm_data = (u32)(data*99 +1);
}

u32 get_pwm(void){
	return pwm_data;
}

void inc_pwm(void){
	pwm_data++;
	if(pwm_data == 101)
		pwm_data = 1;
}


