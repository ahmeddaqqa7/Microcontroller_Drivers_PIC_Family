/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"


relay_t relay_1 = {
    .relay_port = PORTB_INDEX,
    .relay_pin = PIN0,
    .relay_status = RELAY_OFF_STATUS,
};


Std_ReturnType ret = E_NOT_OK;

int main() {
     Application_Initialize();

    while(1){
       ret = relay_turn_on(&relay_1);
       __delay_ms(500);
        ret = relay_turn_off(&relay_1);
        __delay_ms(500);
        }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
    ret = relay_initialize(&relay_1);
}

