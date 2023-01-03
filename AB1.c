#include <stdio.h>
#include <stdlib.h>

int main()
{
    bcm2835_init();
   // bcm2835_gpio_fsel(GPIO18,<Funktion>);
    for (int cycle = 0; cycle < 20; cycle++)
    {
        bcm2835_gpio_set(18);
        bcm2835_gpio_set(25);
        bcm2835_gpio_set(13);
        bcm2835_delay(100);
        bcm2835_gpio_clr(18);
    }
    bcm2835_close();
    return 0;
}










