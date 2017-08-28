


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
u8 debug[4];

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

int set_height_mm(int height){
	if(height > 9999)
		height_mm = 9999;
	else if(height <= 100)
		height_mm = 100;
	else 
		height_mm = height;
	return height_mm;
}

int get_weight_100g(void){
	return wieght_100g;
}


u8 read_regs(u8 addr_h,u8 addr_l){
	u8 res;
	switch(addr_h){
		case 0x0:	break;
		case 0x10:	break;
		case 0xF0: res = get_debug_regs(addr_l);break;
		default : res = 0;
	}
	return res;
}


u8 write_regs(u8 addr_h,u8 addr_l, u8 data){
	u8 res;
	switch(addr_h){
		case 0x0 : break;
		case 0x10: break;
		case 0xF0: res = set_debug_regs(addr_l,data);break;
		default : res = 0;
	}
	return res;
}


u8 get_stat_regs(u8 addr_l){
	
	return 0;
}
u8 set_stat_regs(u8 addr_l,u8 data){
	
	return 0;
}

u8 get_debug_regs(u8 addr_l){
	u8 res;
	switch(addr_l){
		case 0x0: res = debug[0] ; break;
		case 0x1: res = debug[1] ; break;
		case 0x2: res = debug[2] ; break;
		case 0x3: res = debug[3] ; break;
		default : res = 0;
	}	
	return res;
}
u8 set_debug_regs(u8 addr_l,u8 data){
	switch(addr_l){
		case 0x0: debug[0] = data; break;
		case 0x1: debug[1] = data; break;
		case 0x2: debug[2] = data; break;
		case 0x3: debug[3] = data; break;
		default : ;
	}
	return 0x4F;
}


