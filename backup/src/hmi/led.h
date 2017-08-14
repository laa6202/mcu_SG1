
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_H
#define __LED_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
//LED端口定义
#define LED0 PAout(6)	// D2
#define LED1 PAout(7)	// D3	 


/* Exported functions ------------------------------------------------------- */
void LED_Init(void);//初始化		 
void D2_On(void);
void D2_Off(void);
void D3_On(void);
void D3_Off(void);

#endif
