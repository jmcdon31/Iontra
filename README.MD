___________Iontra Embedded Software Engineer Technical Assignment___________

__Project Statement__
Design an LED interface not specific to any one microcontroller or LED driver that provides functions to control the state, color and brightness of an LED.Also, do one simple implementation of the LED interface for an RGB LED on an STM32.

__Overview__
Iontra may choose to use different microcontrollers in various products, but ideally a lot of the core code should remain the same. Rather than having to modify the core code every time, we should aim to write Iontra interfaces and be able to swap out the underlying code depending on the hardware platform we choose.

__Interface Requirements__
Initialize the LEDs.
Support up to 5 LEDs.
Change the LED state: Off, Red, Green, Blue
Change the brightness of an LED: 0 –100%

__Implementation__
We’dlike to see animplementation of the LED interface writtento control a single RGB LEDon an STM32 microcontroller. You are notexpected toactuallyrun this on an STM32, but the HAL libraries provided by ST should be referencedfor peripheral control. You can choose to either integrate the HAL libraries into your code, or you can just stub out the functions needed to make the code compile.

Assume there is a simple RGB LED(example here: https://www.mouser.com/datasheet/2/445/150202M153130-1838938.pdf)connected to 3 pins on the STM32. Write an implementation of the LED interface that would meet all of the functionality from the interface requirements. Itis ok to assume the STM32 is initialized by the time the LED functions are being called(system initialized and clock set). 

__Delivery__
Iontra uses Github for version control. If possible, please use a personal Github repository to upload and share your code. If you wish to use a private repository, please add mtm0183 (Mark Mulrooney) as a collaborator to the private repository. If you’re unable to use Github, please zip up the code and email it. 




__Comments and steps for completion__
Having used the HAL and LL drivers for stm32 before I already have some insight as to what those look like. 
	Lets download the STM32Cube MCU and MPU packages
		Iontra is Developing battery efficient systems so a micro-controller that is low powered seems like a good choice.
			Lets choose the STM32L4
	
In a RGB LED each color will be able to vary the intensity to produce an overall different color. The interface should be able to toggle between red green and blue but it would also be nice if it could support all of the colors in between as well.

Assuming the requirement to support up to 5 LEDs means supporting 5 RGB LEDs, it really needs to support 15 gpio input/outputs as each RGB LED has 3 individual LEDs in it. 

Lets create an interface that supports the following struct
	struct rgb_led {	
		int red_gpio;
		char red_brightness;
		int green_pio;
		char green_brightness;
		int blue_gpio
		char blue_brightness;
		}
each char controls the brightness of the individual led inside of the rgb led. 0 corresponds to low or off and 255 corresponds to high or fully on.
