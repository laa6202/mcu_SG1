/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PWM_DATA_H
#define __PWM_DATA_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void set_pwm(u32 data);
void set_pwm_f32(float data);
u32 get_pwm(void);
void inc_pwm(void);

#endif
