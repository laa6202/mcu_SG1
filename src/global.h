
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GLOBAL_H
#define __GLOBAL_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define S_IDLE 	 0
#define S_CAP 	 1
#define S_WEIGHT 2
#define S_HEIGHT  3
#define S_CALC 	 4
#define S_SPEAK  5

/* Exported functions ------------------------------------------------------- */
int set_main(int state);
int set_test(int state);
int get_main(void);
int get_test(void);
int get_height_mm(void);
int set_height_mm(int height);
int get_weight_100g(void);

u8 read_regs(u8,u8);
u8 write_regs(u8,u8, u8);

u8 get_stat_regs(u8);
u8 set_stat_regs(u8,u8);
u8 get_debug_regs(u8);
u8 set_debug_regs(u8,u8);
#endif /* __GLOBAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
