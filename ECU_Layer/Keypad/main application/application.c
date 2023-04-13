/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"





Std_ReturnType ret = E_NOT_OK;
uint8 key_value = 0;
int main() {
     Application_Initialize();

    while(1){
        ret = keypad_get_value(&keypad1,&key_value);
        if('7' == key_value){
            led_turn_on(&led1);
        }
        else if('8' == key_value){
            led_turn_off(&led1);
        }
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
   ecu_layer_Initialize();
}

