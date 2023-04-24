/* 
 * File:     ecu_layet_init.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 13, 2023, 12:08 PM
 */


#include "ecu_layer_init.h"

chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTA_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.logic = LOW,
    
    .lcd_en.port = PORTA_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.direction = OUTPUT,
    .lcd_en.logic = LOW,
    
    .lcd_data[0].port = PORTA_INDEX,
    .lcd_data[0].pin = PIN2,
    .lcd_data[0].direction = OUTPUT,
    .lcd_data[0].logic = LOW,
    .lcd_data[1].port = PORTA_INDEX,
    .lcd_data[1].pin = PIN3,
    .lcd_data[1].direction = OUTPUT,
    .lcd_data[1].logic = LOW,
    .lcd_data[2].port = PORTA_INDEX,
    .lcd_data[2].pin = PIN4,
    .lcd_data[2].direction = OUTPUT,
    .lcd_data[2].logic = LOW,
    .lcd_data[3].port = PORTA_INDEX,
    .lcd_data[3].pin = PIN5,
    .lcd_data[3].direction = OUTPUT,
    .lcd_data[3].logic = LOW,
};

chr_lcd_8bit_t lcd_2 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.logic = LOW,
    
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.direction = OUTPUT,
    .lcd_en.logic = LOW,
    
    .lcd_data[0].port = PORTB_INDEX,
    .lcd_data[0].pin = PIN0,
    .lcd_data[0].direction = OUTPUT,
    .lcd_data[0].logic = LOW,
    .lcd_data[1].port = PORTB_INDEX,
    .lcd_data[1].pin = PIN1,
    .lcd_data[1].direction = OUTPUT,
    .lcd_data[1].logic = LOW,
    .lcd_data[2].port = PORTB_INDEX,
    .lcd_data[2].pin = PIN2,
    .lcd_data[2].direction = OUTPUT,
    .lcd_data[2].logic = LOW,
    .lcd_data[3].port = PORTB_INDEX,
    .lcd_data[3].pin = PIN3,
    .lcd_data[3].direction = OUTPUT,
    .lcd_data[3].logic = LOW,
    
    .lcd_data[4].port = PORTB_INDEX,
    .lcd_data[4].pin = PIN4,
    .lcd_data[4].direction = OUTPUT,
    .lcd_data[4].logic = LOW,
    .lcd_data[5].port = PORTB_INDEX,
    .lcd_data[5].pin = PIN5,
    .lcd_data[5].direction = OUTPUT,
    .lcd_data[5].logic = LOW,
    .lcd_data[6].port = PORTB_INDEX,
    .lcd_data[6].pin = PIN6,
    .lcd_data[6].direction = OUTPUT,
    .lcd_data[6].logic = LOW,
    .lcd_data[7].port = PORTB_INDEX,
    .lcd_data[7].pin = PIN7,
    .lcd_data[7].direction = OUTPUT,
    .lcd_data[7].logic = LOW,
};

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
   ret = lcd_4bit_initialize(&lcd_1);
   ret = lcd_8bit_initialize(&lcd_2);
}