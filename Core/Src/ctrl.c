#include "ctrl.h"
#include "key.h"
#include "lcd.h"
#include "sram.h"
#include "mymalloc.h"
#include "w25qxx.h"

 const u8 TEXT_Buffer[]={"qwertyuioplkjhgfdsazxcvbm"};
#define SIZE sizeof(TEXT_Buffer)	
	
void KeyMenu(void){ 
		u32 FLASH_SIZE;
		u8 datatemp[SIZE];
		FLASH_SIZE=16*1024*1024;
    switch(keys.key_num){ 
         
        case KEY_WK_UP_PRESS: 
					LED = 0;   
					LCD_Fill(0,170,239,319,WHITE);//清除半屏    
					LCD_ShowString(30,170,200,16,16,"Start Write W25Q128....");
					W25QXX_Write((u8*)TEXT_Buffer,0,SIZE);		//从倒数第100个地址处开始,写入SIZE长度的数据
					LCD_ShowString(30,170,200,16,16,"W25Q128 Write Finished!");	//提示传送完成
        break;
        case KEY_WK_UP_RELEASE:
					LED = 1; 
        break;
        case KEY_WK_UP_CONTINUED:
					LED = 1; 
        break;
				
				case KEY_ID0_PRESS:  
						LCD_ShowString(30,170,200,16,16,"Start Read W25Q128.... ");
						W25QXX_Read(datatemp,0,SIZE);					//从倒数第100个地址处开始,读出SIZE个字节
						LCD_ShowString(30,170,200,16,16,"The Data Readed Is:   ");	//提示传送完成
						LCD_ShowString(30,190,200,16,16,datatemp);					//显示读到的字符串
						LED = 0; 
        break;
        case KEY_ID0_RELEASE:
						
						LED = 1; 
        break;
        case KEY_ID0_CONTINUED:
						LED = 1; 
        break;
				
				
				case KEY_ID1_PRESS:
 
						LED = 0; 
        break;
        case KEY_ID1_RELEASE:
						LED = 1; 
        break;
        case KEY_ID1_CONTINUED:
						LED = 1; 
        break;
				
				case KEY_ID2_PRESS:
 
						LED = 0; 
        break;
        case KEY_ID2_RELEASE:
						LED = 1; 
        break;
        case KEY_ID2_CONTINUED:
						LED = 1; 
        break;
        default:

        break; 
    }
    if(keys.key_num){
        keys.key_num = 0;
    } 
}

void ShowColour(void){
	static u8 x;
		switch(x)
		{
			case 0:LCD_Clear(WHITE);break;
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break; 
			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		x++;
		if(x==12)x=0;
}
