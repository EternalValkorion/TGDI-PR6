// Starten mit folgendem gcc command: sudo gcc -Wall -o AB1 AB1.c -l bcm2835
// ALS SUDO COMPILEN UND ALS SUDO AUSFUEHREN!!!

#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <unistd.h>

int main()
{
    bcm2835_init();
    bcm2835_gpio_fsel(18, 0x01);
    bcm2835_gpio_fsel(25, 0x01);
    bcm2835_gpio_fsel(13, 0x01);

    do
    {
        bcm2835_gpio_set(18);
        bcm2835_gpio_set(25);
        bcm2835_gpio_set(13);

        bcm2835_delay(1000);

        bcm2835_gpio_clr(18);
        bcm2835_gpio_clr(25);
        bcm2835_gpio_clr(13);

        bcm2835_delay(1000);

    }while(1);


    /*for (int cycle = 0; cycle < 10; cycle++)
    {
        bcm2835_gpio_set(18);
        bcm2835_gpio_set(25);
        bcm2835_gpio_set(13);

        bcm2835_delay(1000);

        bcm2835_gpio_clr(18);
        bcm2835_gpio_clr(25);
        bcm2835_gpio_clr(13);
    }*/

    bcm2835_close();

    return 0;
}



