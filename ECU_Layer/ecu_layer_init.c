/* 
 * File:   ecu_layet_init.c
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 13, 2023, 12:08 PM
 */


#include "ecu_layer_init.h"

keypad_t keypad1 = {
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[0].pin = PIN0,
    .keypad_row_pins[0].direction = OUTPUT,
    .keypad_row_pins[0].logic = LOW,
    
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[1].pin = PIN1,
    .keypad_row_pins[1].direction = OUTPUT,
    .keypad_row_pins[1].logic = LOW,
    
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[2].pin = PIN2,
    .keypad_row_pins[2].direction = OUTPUT,
    .keypad_row_pins[2].logic = LOW,
    
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[3].pin = PIN3,
    .keypad_row_pins[3].direction = OUTPUT,
    .keypad_row_pins[3].logic = LOW,
    
    .keypad_column_pins[0].port = PORTD_INDEX,
    .keypad_column_pins[0].pin = PIN4,
    .keypad_column_pins[0].direction = INPUT,
    .keypad_column_pins[0].logic = LOW,
    
    .keypad_column_pins[1].port = PORTD_INDEX,
    .keypad_column_pins[1].pin = PIN5,
    .keypad_column_pins[1].direction = INPUT,
    .keypad_column_pins[1].logic = LOW,
    
    .keypad_column_pins[2].port = PORTD_INDEX,
    .keypad_column_pins[2].pin = PIN6,
    .keypad_column_pins[2].direction = INPUT,
    .keypad_column_pins[2].logic = LOW,
    
    .keypad_column_pins[3].port = PORTD_INDEX,
    .keypad_column_pins[3].pin = PIN7,
    .keypad_column_pins[3].direction = INPUT,
    .keypad_column_pins[3].logic = LOW,
};


led_t led1 = {
  .port_name =  PORTB_INDEX,
  .pin = PIN0,
  .led_status = LOW,    
};

void ecu_layer_Initialize(void){
    Std_ReturnType ret = E_NOT_OK;
   ret = keypad_intialize(&keypad1);
   ret = led_initialize(&led1);
}