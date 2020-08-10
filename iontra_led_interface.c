/*******************************************************************
 * Iontra LED Interface Function Implementation
 *
 * 	Author: Jason McDonald <jmcdon31@gmail.com>
 *
 ********************************************************************/
#include <stdio.h>
#include "iontra_led_interface.h"

/* MAX_RGB_LED_SUPPORTED array which hold instances of initialized leds */ 
static RGB_LED_TypeDef _RGB_LED_Instance[MAX_RGB_LED_SUPPORTED];

/* bit array tracking the used positions of the _RGB_LED_Instance array */
static int _Available_Instance = (1<<MAX_RGB_LED_SUPPORTED) -1;

/* Get and set an available Instance to initialize a new led */
static int _get_available_instance()
{
	int i;
	for (i=0; i < MAX_RGB_LED_SUPPORTED; i++)
	{
	/* Bitwise AND the ith position to check if its being used */
		if (_Available_Instance & (1<<i))
		{
	/* Bitwise XOR the ith position to set it to 0 and use it */
			_Available_Instance ^=1<<i;
			return i;
		}
	}
	return -1; 

}


LED_ReturnStatus_TypeDef Led_Custom_Color( RGB_LED_TypeDef * rgb_led_ref,
					   int red_intensity,
					   int green_intensity,
					   int blue_intensity)
{
	/* Now MCU specific calls will need to be made to set the correct registers */
	//TODO:
	return Led_MCU_Target_Write(rgb_led_ref, red_intensity,
			     green_intensity, blue_intensity );

}


LED_ReturnStatus_TypeDef Led_Init( RGB_LED_TypeDef ** rgb_led_ref,
				   int gpio_red,
				   int gpio_green,
				   int gpio_blue)
{
	int instance_index;
	/* check if there is available space in the instance array */
	if ( (instance_index = _get_available_instance()) < 0 )
		return LED_RETURN_FAILED;
	*rgb_led_ref = &_RGB_LED_Instance[instance_index];

	(*rgb_led_ref)->instance = instance_index;

	(*rgb_led_ref)->red.gpio_add = gpio_red;
	(*rgb_led_ref)->red.intensity = 0;

	(*rgb_led_ref)->green.gpio_add = gpio_green;
	(*rgb_led_ref)->green.intensity = 0;

	(*rgb_led_ref)->blue.gpio_add = gpio_blue;
	(*rgb_led_ref)->blue.intensity = 0;


	/* Now we must call MCU specific initializations */
	Led_MCU_Target_Init(*rgb_led_ref);

	return  LED_RETURN_SUCCESS;
}

LED_ReturnStatus_TypeDef Led_Deinit( RGB_LED_TypeDef * rgb_led_ref )
{
	Led_Off(rgb_led_ref);
	_Available_Instance ^=
		( 1<< rgb_led_ref->instance );
	return  LED_RETURN_SUCCESS;

}


LED_ReturnStatus_TypeDef Led_Off(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 0;
	rgb_led_ref->green.intensity = 0;
	rgb_led_ref->blue.intensity = 0;

	return  Led_Custom_Color(rgb_led_ref, 0, 0, 0);
}

LED_ReturnStatus_TypeDef Led_Red(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 255;
	rgb_led_ref->green.intensity = 0;
	rgb_led_ref->blue.intensity = 0;

	return  Led_Custom_Color(rgb_led_ref, 255, 0, 0);
}

LED_ReturnStatus_TypeDef Led_Blue(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 0;
	rgb_led_ref->green.intensity = 0;
	rgb_led_ref->blue.intensity = 255;

	return  Led_Custom_Color(rgb_led_ref, 0, 0, 255);
}

LED_ReturnStatus_TypeDef Led_Green(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 0;
	rgb_led_ref->green.intensity = 255;
	rgb_led_ref->blue.intensity = 0;

	return  Led_Custom_Color(rgb_led_ref, 0, 255, 0);
}

LED_ReturnStatus_TypeDef Led_Amber(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 255;
	rgb_led_ref->green.intensity = 128;
	rgb_led_ref->blue.intensity = 0;

	return  Led_Custom_Color(rgb_led_ref, 255, 128, 0);
}

LED_ReturnStatus_TypeDef Led_Purple(RGB_LED_TypeDef * rgb_led_ref)
{
	rgb_led_ref->red.intensity = 255;
	rgb_led_ref->green.intensity = 0;
	rgb_led_ref->blue.intensity = 255;

	return  Led_Custom_Color(rgb_led_ref, 255, 0, 255);
}

