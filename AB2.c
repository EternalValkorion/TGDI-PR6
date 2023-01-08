#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>


int main()
{

char buffer[12];

// Initialisation and configuration of used pins.
bcm2835_init();
bcm2835_i2c_begin();

// Baudrate configuration
bcm2835_i2c_setClockDivider(2500);

// Address of corresponding Temp sensor.
bcm2835_i2c_setSlaveAddress(0x48);
for(int cycle = 0; cycle < 11; cycle++)
{
        bcm2835_i2c_read(buffer, 2);
}

        //Shift Values to MSB. Value will be transformed without LSB part to not show float values. (deprecated comment)
        //int16_t i16 = data_read[0] << 8 | data_read[1];
        //float temp = i16 / 256.0;

        // Printing Results
        for(int i = 0; i < 12; i++)
        {
                float temp = buffer[i];
                printf("Temperature = %.3f\r\n",temp);

        }

        //Selection of gpio pins for activation of LED on successfull Print of Temperatures
        bcm2835_gpio_fsel(18, 0x01);
        bcm2835_gpio_fsel(25, 0x01);
        bcm2835_gpio_fsel(13, 0x01);

        // Activationcommands for LEDS.
        bcm2835_gpio_set(18);
        bcm2835_gpio_set(25);
        bcm2835_gpio_set(13);

// Revertion of pin configuration to default.
bcm2835_i2c_end();
bcm2835_close();


return 0;
}
