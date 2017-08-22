


/* Includes ------------------------------------------------------------------*/
#include "action.h" 
#include "global.h"
#include "speaker.h"
#include "us100.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int action_speak(){
	int height_mm = get_height_mm();
	int weight_100g = get_weight_100g();
	speak_h3w2(height_mm,weight_100g);
	wait_idle();
	return 0;
}


int action_height(){
	int height;
	us100_measure();
	height = get_height();
	set_height_mm(height);
	return 0;
}



