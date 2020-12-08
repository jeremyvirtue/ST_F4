#ifndef __key_h
#define __key_h


#include "main.h"


#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)
#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2        HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)
#define KEY_WK	    HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin)

#define KEY_COUNT 4//按键数量	
#define KEY_DOWN 1
#define KEY_UP   0

#define KEY_DURATION_TIME 100 

typedef enum{
    KEY_ID0 = 0,
    KEY_ID1,
    KEY_ID2,
    KEY_WK_UP,

}KEY_ID;

typedef enum{
	KEY_NULL = 0,

   KEY_ID0_PRESS,
   KEY_ID0_RELEASE,
   KEY_ID0_CONTINUED,

   KEY_ID1_PRESS,
   KEY_ID1_RELEASE,
   KEY_ID1_CONTINUED,

   KEY_ID2_PRESS,
   KEY_ID2_RELEASE,
   KEY_ID2_CONTINUED,

   KEY_WK_UP_PRESS,
   KEY_WK_UP_RELEASE,
   KEY_WK_UP_CONTINUED, 
}KEY_N;

typedef struct
{
  u8 now:1;         //当前键值
  u8 press:1;       //按下
  u8 release:1;     //释放
  u8 continued:1;   //持续按下
  u16 duration;    //持续按下时间
}Key;
	
typedef struct
{
	Key       key[KEY_COUNT]; 
	u8 			key_num;
}KeyData;


extern KeyData   keys;  

 
void KeyScan(void);



#endif

