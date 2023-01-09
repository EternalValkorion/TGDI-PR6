#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>


int main()
{

char buffer[12];
int count = 1;

// Initialisation and configuration of used pins.
bcm2835_init();
bcm2835_i2c_begin();

// Baudrate configuration
bcm2835_i2c_setClockDivider(2500);

// Address of corresponding Temp sensor.
bcm2835_i2c_setSlaveAddress(0x48);

//Selection of gpio pins for activation of LED on successfull Print of Temperatures
bcm2835_gpio_fsel(18, 0x01);
bcm2835_gpio_fsel(25, 0x01);
bcm2835_gpio_fsel(13, 0x01);

        //Shift Values to MSB and Printing Results
        for(int i = 0; i < 100; i++)
        {
                for(int cycle = 0; cycle < 11; cycle++)
                {
                        bcm2835_i2c_read(buffer, 2);
                }

                float readshift = buffer[0] << 7 | buffer[1];
                float temp = readshift / 256;
                printf("%d.Temperature = %.3f Grad Celsius\r\n", count, temp);

                count++;

                // Commands for LEDS.
                bcm2835_gpio_set(18);
                bcm2835_gpio_set(25);
                bcm2835_gpio_set(13);

                bcm2835_delay(1000);

                bcm2835_gpio_clr(18);
                bcm2835_gpio_clr(25);
                bcm2835_gpio_clr(13);
        }


// Revertion of pin configuration to default.
bcm2835_i2c_end();
bcm2835_close();


return 0;
}

