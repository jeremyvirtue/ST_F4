#include "os.h"
#include "key.h"
#include "tim.h"

MyDelay   taskDelay[MAXTASK];

/*------任务0------*/
static void Task0(void)
{		
//		HAL_GPIO_TogglePin(  GPIOF, GPIO_PIN_10);
} 


/*------任务1------*/
static void Task1(void)
{	 
 
 
} 

/*------任务2------*/
static void Task2(void)
{	 
 
 
} 

/*------任务1------*/
static void Task3(void)
{	  
  	KeyScan();
		KeyMenu();
			
} 

void OSTaskInit(void)
{
	//5ms
	u8   i=0;
	taskDelay[0].delay=1000;		// 
	taskDelay[1].delay=100;			// 	 
	taskDelay[2].delay=50;		// 
	taskDelay[3].delay=20;			// 	 
	
	for (i=0;i < MAXTASK;i++)
	{
	  taskDelay[i].counter=taskDelay[i].delay;
	}
	
}


/**         任务调度
*
*
*/
void OSTaskScan(void)
{
	u8  i=0;
  static  void (*  Task[])()={&Task0,&Task1,&Task2,&Task3}; 

    for (i=0;i<MAXTASK;i++)
    {
      if (taskDelay[i].counter==0)
      {
        taskDelay[i].counter=taskDelay[i].delay;
        Task[i]();
      }
    }
}

//1ms定时调度
void OSTick(void)
{ 
  u8 i; 
  for (i=0;i<MAXTASK;i++)
  {
    if (taskDelay[i].counter>0)
    {
      taskDelay[i].counter--;
    }				
  }
}










