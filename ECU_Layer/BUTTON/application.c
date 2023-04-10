/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"

led_t led_1 = {
    .port_name = PORTD_INDEX,
    .pin = PIN0,
    .led_status = LED_OFF,
};

led_t led_2 = {
    .port_name = PORTD_INDEX,
    .pin = PIN1,
    .led_status = LED_OFF,
};

led_t led_3 = {
    .port_name = PORTD_INDEX,
    .pin = PIN2,
    .led_status = LED_OFF,
};

button_t btn_1 = {
    .btn_pin.port = PORTC_INDEX,
    .btn_pin.pin = PIN0,
    .btn_pin.direction = INPUT,
    .btn_pin.logic = LOW,
    .btn_connection = BUTTON_ACTIVE_HIGH,
    .btn_state = BUTTON_RELESED,
};

button_t btn_2 = {
    .btn_pin.port = PORTC_INDEX,
    .btn_pin.pin = PIN1,
    .btn_pin.direction = INPUT,
    .btn_pin.logic = HIGH,
    .btn_connection = BUTTON_ACTIVE_LOW,
    .btn_state = BUTTON_RELESED,
};



Std_ReturnType ret = E_NOT_OK;
button_state_t button_high_status = BUTTON_RELESED;
button_state_t button_low_status = BUTTON_RELESED;
button_state_t btn_high_valid_status = BUTTON_RELESED;
button_state_t btn_high_last_valid_status = BUTTON_RELESED;
led_status_t led1_status = LED_OFF;
uint8 btn_flag = 0;
uint32 btn_high_valid = 0;
uint8 Program_Selected = 0;

int main() {
     Application_Initialize();

    while(1){
        ret = button_read_status(&btn_1, &button_high_status);
        ret = button_read_status(&btn_2, &button_low_status);
        if(BUTTON_PRESSED == button_high_status){
            btn_high_valid++;
            //led_turn_on(&led_1);
           // btn_flag = 1;
            if(btn_high_valid > 500){
                btn_high_valid_status = BUTTON_PRESSED;
            }
        }
        else {
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELESED;
        }
        if(btn_high_valid_status != btn_high_last_valid_status){
            btn_high_last_valid_status = btn_high_valid_status;
            if(BUTTON_PRESSED == btn_high_valid_status){
                Program_Selected++;
                /*
                if(LED_OFF == led1_status){
                    led_turn_on(&led_1);
                    led1_status = LED_ON;
                }
                else{
                    led_turn_off(&led_1);
                    led1_status = LED_OFF;
                }
                 * */
                switch(Program_Selected){
            case 1 : Program1(); break;
            case 2 : Program2(); break;
            case 3 : Program3(); break;
            default : Program4(); break; /* Nothing */
        }
            }
        }
        

        
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
    ret = led_initialize(&led_1);
    ret = led_initialize(&led_2);
    ret = led_initialize(&led_3);
    ret = button_initialize(&btn_1);
    ret = button_initialize(&btn_2);
}

void Program1(void){
    led_turn_on(&led_1);
    led_turn_off(&led_2);
    led_turn_off(&led_3);
    
}
void Program2(void){
    led_turn_off(&led_1);
    led_turn_on(&led_2);
    led_turn_off(&led_3);
}
void Program3(void){
    led_turn_off(&led_1);
    led_turn_off(&led_2);
    led_turn_on(&led_3);
}

void Program4(void){
    Program_Selected = 0x00;
    led_turn_off(&led_1);
    led_turn_off(&led_2);
    led_turn_off(&led_3);
    
}