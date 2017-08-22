


/* Includes ------------------------------------------------------------------*/
#include "global.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int st_main;
int st_test;
int count;
int height_mm = 1720;
int wieght_100g = 950;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int set_main(int state){
	st_main = state;
	if(state != S_IDLE)
		count ++;
	return 0;
}

int set_test(int state){
	st_test = state;
	return 0;
}

int get_main(void){
	return st_main;
}

int get_test(void){
	return st_test;
}

int get_height_mm(void){
	return height_mm;
}

int get_weight_100g(void){
	return wieght_100g;
}

