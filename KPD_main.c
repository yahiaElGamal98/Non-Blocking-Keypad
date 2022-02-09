/*
 * KPD_main.c
 *
 * Created: 2/8/2022 6:36:56 PM
 *  Author: No. 01
 */ 
#include "./01-LIB/STD_types.h"
#include "./03-HAL/Keypad/KPD_Interface.h"
#include "./03-HAL/LED/LED.h"



int main()
{
	uint8_t u8_KPD_val;
	EN_KPD_states_t EN_currentState;
	KPD_init();		/*initialization of keypad */
	LED_init(LED0);
	LED_init(LED1);
	LED_init(LED2);
	LED_init(LED3);
	
	while(1)
	{
		
		EN_currentState=KPD_getVal(&u8_KPD_val);	/*get Keypad value*/
		if(EN_KPD_DONE==EN_currentState)
		{
			if(u8_KPD_val=='1')
			{
				LED_ON(LED0);
				LED_OFF(LED1);
				LED_OFF(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='2')
			{
				LED_OFF(LED0);
				LED_ON(LED1);
				LED_OFF(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='3')
			{
				LED_ON(LED0);
				LED_ON(LED1);
				LED_OFF(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='4')
			{
				LED_OFF(LED0);
				LED_OFF(LED1);
				LED_ON(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='5')
			{
				LED_ON(LED0);
				LED_OFF(LED1);
				LED_ON(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='6')
			{
				LED_OFF(LED0);
				LED_ON(LED1);
				LED_ON(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='7')
			{
				LED_ON(LED0);
				LED_ON(LED1);
				LED_ON(LED2);
				LED_OFF(LED3);
			}
			else if(u8_KPD_val=='8')
			{
				LED_OFF(LED0);
				LED_OFF(LED1);
				LED_OFF(LED2);
				LED_ON(LED3);
			}
			else if(u8_KPD_val=='9')
			{
				LED_ON(LED0);
				LED_OFF(LED1);
				LED_OFF(LED2);
				LED_ON(LED3);
			}
			EN_currentState=EN_KPD_NPRESSED;
		}
	}
	return 0;

}