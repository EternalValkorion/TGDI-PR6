#include <stdio.h>

void main()
{
    bcm2835_init();
    bcm2835_gpio_fsel(GPIO18,<Funktion>);
    for (int cycle = 0; i < 20; cycle++)
    {
        bcm2835_gpio_set(GPIO18);
        bcm2835_delay(100);
        bcm2835_gpio_clr(GPIO18);
    }
    
    
    
    bcm2835_close();
}