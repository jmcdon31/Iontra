/*********************************************************************
 *
 * Iontra LED Interface
 *
 * 	Author: Jason McDonald <jmcdon31@gmail.com>
 *
 *
 * 	Description: A general interface for supporting common RGB LED
 * 			actions on a micro-controller.
 *
 * 		Note: Current support is only for RGB LEDs and not single 			color
 *
 * 		Interface Requirements:
 * 		Initialize the LEDs.
 * 		Support up to 5 LEDs.
 * 		Change the LED state: Off, Red, Green, Blue
 * 		Change the brightness of an LED: 0 –100%
 *
 *******************************************************************/
#define MAX_RGB_LED_SUPPORTED (5)

/* variable strength LED type. 0 to 255 strength */
typedef struct {
	int gpio_add;
	short int intensity;
} Variable_LED_TypeDef;


/* RGB LED type */
typedef struct {
	Variable_LED_TypeDef red;
	Variable_LED_TypeDef green;
	Variable_LED_TypeDef blue;
	int instance; 	/*the position this led has been initialized at */
} RGB_LED_TypeDef;

/* return status for led interface functions */
typedef enum {
	LED_RETURN_FAILED = -1,  /* Failed to perform requested action */
	LED_RETURN_SUCCESS     /* function succeeded */
} LED_ReturnStatus_TypeDef;


/*
 * Function: LED_MCU_Target_Init()
 * 	Initialize MCU and Board specific interfaces for LED. 
 * 	This function is designed to be written for each supported target.
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be initialized
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_MCU_Target_Init( RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: LED_MCU_Target_Write()
 * 	Write given digital values with the MCU write method
 * 	This function is designed to be written for each supported target.
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be written to.
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_MCU_Target_Write( RGB_LED_TypeDef * rgb_led_ref,
					       int red_intensity,
					       int green_intensity,
					       int blue_intensity);


/*
 * Function: LED_Custom_Color()
 * 	Turn the RGB LED off completely
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be changed
 * 		*_intensity - (0,255) value of brightness desired for 
 * 				that color
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Custom_Color( RGB_LED_TypeDef * rgb_led_ref,
					   int red_intensity,
					   int green_intensity,
					   int blue_intensity);

/*
 * Function: LED_Init()
 * 	Initialize an RGB LED
 *
 * 	Params: rgb_led_ref - a pointer that will be filled with an 
 * 		initialized RGB_LED type
 * 		gpio_*: the GPIO addressed for each led
 *
 * 	Return: Success if initialized or Failed
 */
LED_ReturnStatus_TypeDef Led_Init( RGB_LED_TypeDef ** rgb_led_ref,
				   int gpio_red,
				   int gpio_green,
				   int gpio_blue);
/*
 * Function: LED_Deinit()
 * 	DeInit an RGB LED
 *
 * 	Params: rgb_led_ref - a pointer to an instance of an initialized
 * 		reg led that will now be deinited
 *
 * 	Return: Success if deinitialized or Failed
 */
LED_ReturnStatus_TypeDef Led_Deinit( RGB_LED_TypeDef * rgb_led_ref );


/*
 * Function: Led_Off()
 * 	Turn the RGB LED off completely
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned off
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Off(RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: Led_Red()
 * 	Turn the RGB LED to Red
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned Red
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Red(RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: Led_Blue()
 * 	Turn the RGB LED to Blue
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned Blue
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Blue(RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: Led_Green()
 * 	Turn the RGB LED to Green
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned Green
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Green(RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: Led_Amber()
 * 	Turn the RGB LED to Amber
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned Amber
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Amber(RGB_LED_TypeDef * rgb_led_ref);

/*
 * Function: Led_Purple()
 * 	Turn the RGB LED to Purple
 *
 * 	Params: rgb_led_ref - a pointer to the 
 * 		initialized RGB_LED type that will be turned Purple
 *
 * 	Return: Success or Failed
 */
LED_ReturnStatus_TypeDef Led_Purple(RGB_LED_TypeDef * rgb_led_ref);


