

#include "app_key.h"



void App_key_init(void)
{
    xl9555_init();
    xl9555_io_config(KEY0 | KEY1 | KEY2 | KEY3 , IO_SET_INPUT);
 
}


uint8_t App_get_keylevel( uint16_t port_pin )
{
    uint8_t keylevel ;

    keylevel = xl9555_get_pin(port_pin) ;

    // Serial.printf("key %d is %d\r\n " , port_pin , keylevel);
    return keylevel;

}

void App_key_check_process(void)
{
    if (!IIC_INT)
    {
        if (xl9555_get_pin(KEY0) ==  0 )
        {
            Serial.print("key 0 is press\r\n ");
            /* code */
        }
        
        if (xl9555_get_pin(KEY1) ==  0 )
        {
            Serial.print("key 1 is press\r\n ");
            /* code */
        }

        if (xl9555_get_pin(KEY2) ==  0 )
        {
            Serial.print("key 2 is press\r\n ");
            /* code */
        }

        if (xl9555_get_pin(KEY3) ==  0 )
        {
            Serial.print("key 3 is press\r\n ");
            /* code */
        }
        /* code */
    }
    
}














