
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_KEY_H
#define __EXTI_KEY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int init_exti_key(void);
int get_measure_now(void);
int set_measure_now(int flag);

	
#endif /* __EXTI_KEY_H */


