#include <bcm2835.h>  
#include <stdio.h>

int main()  
{  
    char buf[1];
    char regaddr[1];
    uint8_t sts = 0;
    uint8_t addr = 0x28;

    if(!bcm2835_init()){
        printf("Error initialising BCM2835");
    }
    if (!bcm2835_i2c_begin()){
        printf("Error initialising I2C");
    }                //Start I2C operations.
    bcm2835_i2c_setSlaveAddress(addr);  //I2C address
    // bcm2835_i2c_set_baudrate(11520);    //1M baudrate

    // while(1)  
    // {   
    //     buf[0] = 0xEF;    //LED ON
    //     bcm2835_i2c_write(buf,1);
    //     bcm2835_delay(500);
    //     buf[0] = 0xFF;     //LED OFF
    //     bcm2835_i2c_write(buf,1);
    //     bcm2835_delay(500); 
    // } 
    // char addr[1] = 0x01;   
    buf[0] = 0x01;
    regaddr[0] = 0x06;
    sts = bcm2835_i2c_read_register_rs(regaddr,buf,1);
    printf("Status = %x", sts);
    // bcm2835_i2c_end();  
    return 0;  
}
