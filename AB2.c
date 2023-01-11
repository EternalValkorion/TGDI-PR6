
                float readshift = buffer[0] << 8 | buffer[1];
                float temp = readshift / 256;

                if(temp >= 0 && temp <= 150)
                {
                        printf("%d.Temperature = %.3f Grad Celsius\r\n", count, temp);
                        count++;
                }else
                {
                        minustemp = 256-temp;
                        printf("%d.Temperature = -%.3f Grad Celsius\r\n", count, minustemp);
                        count++;
                }

                // Commands for LEDS.
                if(temp <= 4 || minustemp <= 150)
                {
                        printf("FROSTWARNUNG es ist unter +4 GRAD CELSIUS\r\n");
                        bcm2835_gpio_set(18);

                        bcm2835_delay(1000);

                        bcm2835_gpio_clr(18);
                        minustemp = 151;

                }

                bcm2835_delay(1000);
        }


// Revertion of pin configuration to default.
bcm2835_i2c_end();
bcm2835_close();


return 0;
}


