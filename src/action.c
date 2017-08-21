


/* Includes ------------------------------------------------------------------*/
#include "action.h" 
#include "global.h"
#include "speaker.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int action_speak(){
	int height_mm = get_height_mm();
	speak_h3(height_mm);
	
	return 0;
}




