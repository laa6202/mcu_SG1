
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GLOBAL_H
#define __GLOBAL_H

/* Includes ------------------------------------------------------------------*/
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
int get_weight_100g(void);


#endif /* __GLOBAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
