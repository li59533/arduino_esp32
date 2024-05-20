#ifndef __APP_KEY_H
#define __APP_KEY_H


#include "xl9555.h"


  
void App_key_init(void);

void App_key_check_process(void);
uint8_t App_get_keylevel( uint16_t port_pin );
 
#endif
