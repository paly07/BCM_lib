#include <stdio.h>
#include <bcm2835.h>

int main() {

    bcm2835_init();
    bcm2835_gpio_fsel(RPI_GPIO_P1_13, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_write(RPI_GPIO_P1_13, HIGH);


    return 0;
}