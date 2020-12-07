#include "key.h"
 
KeyData   keys;  

static void KeyPress(void);
static void KeyRelease(void);
static void KeyContinued(void);

void KeyMenu(void){
    switch(keys.key_num){ 
         
        case KEY_WK_UP_PRESS:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
        break;
        case KEY_WK_UP_RELEASE:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
        break;
        case KEY_WK_UP_CONTINUED:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
        break;
				
				case KEY_ID0_PRESS:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
        break;
        case KEY_ID0_RELEASE:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
        break;
        case KEY_ID0_CONTINUED:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
        break;
				
				
				case KEY_ID1_PRESS:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
        break;
        case KEY_ID1_RELEASE:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
        break;
        case KEY_ID1_CONTINUED:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
        break;
				
				case KEY_ID2_PRESS:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
        break;
        case KEY_ID2_RELEASE:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
        break;
        case KEY_ID2_CONTINUED:
						HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
        break;
        default:

        break; 
    }
    if(keys.key_num){
        keys.key_num = 0;
    }


}

void KeyScan(void){
	u8 i; 
	for (i=0;i<KEY_COUNT;i++)
	{
		keys.key[i].now = 0;
	} 
    if(!KEY0){
        keys.key[KEY_ID0].now=KEY_DOWN; 
    }
    if(!KEY1){
        keys.key[KEY_ID1].now=KEY_DOWN; 
    }
    if(!KEY2){
        keys.key[KEY_ID2].now=KEY_DOWN; 
    }
    if(KEY_WK){
        keys.key[KEY_WK_UP].now=KEY_DOWN; 
    }

	for (i=0;i<KEY_COUNT;i++)
	{
		keys.key[i].press=keys.key[i].now & (keys.key[i].now^keys.key[i].continued);
		keys.key[i].release=keys.key[i].now ^ keys.key[i].press ^ keys.key[i].continued;
		keys.key[i].continued=keys.key[i].now;
		if (keys.key[i].continued==0x00)
		  keys.key[i].duration =0;
	}
	KeyPress();   
	KeyRelease(); 
	KeyContinued(); 
 
}





static void KeyPress(void){
	if (keys.key[KEY_ID0].press)// 
	{ 
		keys.key_num = KEY_ID0_PRESS;
	} 
    if (keys.key[KEY_ID1].press)// 
	{ 
		keys.key_num = KEY_ID1_PRESS;
	} 
    if (keys.key[KEY_ID2].press)// 
	{ 
		keys.key_num = KEY_ID2_PRESS;
	} 
    if (keys.key[KEY_WK_UP].press)// 
	{ 
		keys.key_num = KEY_WK_UP_PRESS;
	}  
}

static void KeyRelease(void){
	if (keys.key[KEY_ID0].release)// 
	{ 
		 keys.key_num = KEY_ID0_RELEASE;
	} 
    if (keys.key[KEY_ID1].release)// 
	{ 
		 keys.key_num = KEY_ID1_RELEASE;
	}  
    if (keys.key[KEY_ID2].release)// 
	{ 
		 keys.key_num = KEY_ID2_RELEASE;
	} 
    if (keys.key[KEY_WK_UP].release)// 
	{ 
		 keys.key_num = KEY_WK_UP_RELEASE;
	} 
}

static void KeyContinued(void){
	if (keys.key[KEY_ID0].continued)// 
	{
		if (keys.key[KEY_ID0].duration<KEY_DURATION_TIME*10)
			keys.key[KEY_ID0].duration++;
		if(keys.key[KEY_ID0].duration==KEY_DURATION_TIME)
		{
			keys.key_num = KEY_ID0_CONTINUED;
		} 
	} 	
    if (keys.key[KEY_ID1].continued)// 
	{
		if (keys.key[KEY_ID1].duration<KEY_DURATION_TIME*10)
			keys.key[KEY_ID1].duration++;
		if(keys.key[KEY_ID1].duration==KEY_DURATION_TIME)
		{
			keys.key_num = KEY_ID1_CONTINUED;
		} 
	} 	

    if (keys.key[KEY_ID2].continued)// 
	{
		if (keys.key[KEY_ID2].duration<KEY_DURATION_TIME*10)
			keys.key[KEY_ID2].duration++;
		if(keys.key[KEY_ID2].duration==KEY_DURATION_TIME)
		{
			keys.key_num = KEY_ID2_CONTINUED;
		} 
	} 	
    if (keys.key[KEY_WK_UP].continued)// 
	{
		if (keys.key[KEY_WK_UP].duration<KEY_DURATION_TIME*10)
			keys.key[KEY_WK_UP].duration++;
		if(keys.key[KEY_WK_UP].duration==KEY_DURATION_TIME)
		{
			keys.key_num = KEY_WK_UP_CONTINUED;
		} 
	} 	
}


