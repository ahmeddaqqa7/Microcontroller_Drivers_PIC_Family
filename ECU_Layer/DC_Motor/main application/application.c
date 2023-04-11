/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"


dc_motor_t dc_motor_1 = {
    .dc_motor_pin[0].port = PORTA_INDEX,
    .dc_motor_pin[0].pin = PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = OUTPUT,
    .dc_motor_pin[1].port = PORTA_INDEX,
    .dc_motor_pin[1].pin = PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = OUTPUT,
};

dc_motor_t dc_motor_2 = {
    .dc_motor_pin[0].port = PORTA_INDEX,
    .dc_motor_pin[0].pin = PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = OUTPUT,
    .dc_motor_pin[1].port = PORTA_INDEX,
    .dc_motor_pin[1].pin = PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = OUTPUT,
};

Std_ReturnType ret = E_NOT_OK;

int main() {
     Application_Initialize();

    while(1){
        dc_motor_move_right(&dc_motor_1);
        dc_motor_move_right(&dc_motor_2);
        __delay_ms(3000);
        dc_motor_move_left(&dc_motor_1);
        dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        dc_motor_stop(&dc_motor_1);
        dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        dc_motor_move_right(&dc_motor_1);
        dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        dc_motor_stop(&dc_motor_1);
        dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        dc_motor_move_left(&dc_motor_1);
        dc_motor_move_right(&dc_motor_2);
        __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
    ret = dc_motor_initailize(&dc_motor_1);
    ret = dc_motor_initailize(&dc_motor_2);
}

