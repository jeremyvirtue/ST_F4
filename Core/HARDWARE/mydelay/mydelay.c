#include "mydelay.h"
#include "tim.h"

/*δ�������� ���治�ȶ���������Ȼû�н��*/
void my_delayus(u32 us){
	  u16 differ=0xffff-us-5;
    /*Ϊ��ֹ���жϴ����ʱ����ɼ�������.
     ���0xfffE��ʼ��ʱ1us,�������жϴ��
    ����ʱ���������ڼ����������������0xffff��
    ��ֹͣ�����������ڴ������ֵ��������arrֵ��
    ����ʵ����ʱ(0xffff+1)us
    */

    HAL_TIM_Base_Start(&htim3);
		__HAL_TIM_SetCounter(&htim3,differ);
    while(differ<0xffff-5)
    {
        differ=__HAL_TIM_GetCounter(&htim3);
    }
    HAL_TIM_Base_Stop(&htim3);
}

