
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/pwr.h>

#include <libopencm3/stm32/gpio.h>





static void gpio_setup(void)
{
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOA);


	
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9);
	
	return;
	
	
}

int main(void)
{
	
	int i;
	gpio_setup();

	while (1) {
		
		 gpio_set(GPIOB, GPIO9);
		 for (i = 0; i < 1000; i++)	/* Wait a bit. */
			__asm__("nop");
		 gpio_clear(GPIOB, GPIO9);
		 for (i = 0; i < 1000; i++)	/* Wait a bit. */
			__asm__("nop");

	}

	return 0;
}
