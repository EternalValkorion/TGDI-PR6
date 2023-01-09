#include <stdio.h>                                                  // Header fuer Ein-/Ausgaben
#include <bcm2835.h>                                        // Header fuer Broadcom

#define PIN                             RPI_BPLUS_GPIO_J8_12                                                    // PWM-Pin
#define PWM_CHANNEL             0                                                                                               // PWM-Channel
#define PWM_RANGE               1024                                                                                    // PWM-Range
#define SPEED                   1                                                                                               // Geschwindigkeit

int main(void){
        if(bcm2835_init()==0) return 1;                                                                         // Library initalisieren

        do{
        bcm2835_gpio_fsel(18, 0x02);
        bcm2835_pwm_set_clock(1);
        bcm2835_pwm_set_mode(0,1,1);
        bcm2835_pwm_set_range(0, 1024);
        bcm2835_pwm_set_data(0, 90);
        bcm2835_delay(2000);
        }while(1);
        // PWM Funktionalität an Pin freischalten

        // PWM Frequenz einstellen

        // PWM Modus einstellen und starten

        // PWM Range einstellen

        // In Schleife
                // PWM Duty einstellen
                // Pause

        if(bcm2835_close()==0) return 1;                                                                        // Library schließen
        return 0;                                                               // Programmende
}









