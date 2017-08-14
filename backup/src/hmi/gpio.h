

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
//GPIO端口定义
#define PB13 PBout(13)	
#define PB14 PBout(14)

/* Exported functions ------------------------------------------------------- */
void GPIO_PB_Init(void);//初始化		 


#endif
