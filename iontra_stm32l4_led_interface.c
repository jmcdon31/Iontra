#include "iontra_led_interface.h"
#include "stm32l4xx_hal_gpio.h"
#include <stdio.h>

static GPIO_InitTypeDef  GPIO_InitStruct;


LED_ReturnStatus_TypeDef Led_MCU_Target_Init( RGB_LED_TypeDef * rgb_led_ref)
{
	printf("Initing Test Board and MCU\n");


	/* Init Hal */
	HAL_Init();

	/* Configure system Clock */
	SystemClock_Config();

	/* Enable GPIO clock so it accepts new configurations */
	__HAL_RCC_GPIOB_CLK_ENABLE()

	/* Setup GPIO to be the Alternate Function TIM1 */
	GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
  	GPIO_InitStruct.Pull  = GPIO_PULLUP;
  	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  	GPIO_InitStruct.Pin = rgb_led_ref->.red.gpio_add   | 
			      rgb_led_ref->.green.gpio_add |
			      rgb_led_ref->.blue.gpio_add;

	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);



	//TODO: Init Timer 1 and setup channels 1, 2, 3
	


	return 0;
}

LED_ReturnStatus_TypeDef Led_MCU_Target_Write( RGB_LED_TypeDef * rgb_led_ref,
					       int red_intensity,
					       int green_intensity,
					       int blue_intensity) 
{
	//TODO: Write to timer1 with new PWM intensity level depending on channel
	return 0;

}




/* Test Functionality of the Iontra LED Interface using a STM32 Micro Controller
 */
int main()
{
	LED_ReturnStatus_TypeDef led_return;

	RGB_LED_TypeDef * front_led;

	led_return = Led_Init(&front_led, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);
	if (led_return != LED_RETURN_SUCCESS )
		return-1;

	/* Test Cases */
	//Init 6 instances and make sure the 6th fails
	//Deinit an instance and make sure a new one can be created
	//Test all colors - also tests brightness
	//Make sure LED turns off
	//Test deinit
	//
	return 0;
}








