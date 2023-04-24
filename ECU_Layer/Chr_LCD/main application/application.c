/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"




uint8 lcd1_counter = ZERO_INIT;
uint8 lcd_counter_txt[4];
Std_ReturnType ret = E_NOT_OK;

const uint8 customChar1[] = {0x0E,0x0A,0x11,0x11,0x11,0x11,0x1F,0x00};
const uint8 customChar2[] = {0x0E,0x0A,0x11,0x11,0x11,0x1F,0x1F,0x00};
const uint8 customChar3[] = {0x0E,0x0A,0x11,0x11,0x1F,0x1F,0x1F,0x00};
const uint8 customChar4[] = {0x0E,0x0A,0x11,0x1F,0x1F,0x1F,0x1F,0x00};
const uint8 customChar5[] = {0x0E,0x0A,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
const uint8 customChar6[] = {0x0E,0x0E,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};

void welcome_message(void){
    for(lcd1_counter = 1; lcd1_counter<=5; ++lcd1_counter){
            lcd_4bit_send_string_pos(&lcd_1, 1, 7,"Welcome");
            lcd_4bit_send_string_pos(&lcd_1, 2, 3,"Ahmed Abu Daqqa");
            __delay_ms(500);
            lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
            __delay_ms(100);
        }
}

void loading_screen(void){
    lcd_8bit_send_string_pos(&lcd_2, 1, 1,"Loading");
    uint8 l_lcd2_counter = ZERO_INIT;
    for(l_lcd2_counter = 8; l_lcd2_counter<=15; ++l_lcd2_counter){
            lcd_8bit_send_char_data_pos(&lcd_2, 1, l_lcd2_counter, '.');
            __delay_ms(50);
        }
    lcd_8bit_send_string_pos(&lcd_2, 1, 8,"        ");
}

int main() {
     Application_Initialize();
     
      lcd_8bit_send_string_pos(&lcd_2, 1, 1,"Counter: ");
    while(1){
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar1, 0); __delay_ms(100);
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar2, 0); __delay_ms(100);
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar3, 0); __delay_ms(100);
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar4, 0); __delay_ms(100);
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar5, 0); __delay_ms(100);
        ret = lcd_8bit_send_custome_char(&lcd_2, 1,20, customChar6, 0); __delay_ms(100);
        
        
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar1, 0); __delay_ms(100);
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar2, 0); __delay_ms(100);
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar3, 0); __delay_ms(100);
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar4, 0); __delay_ms(100);
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar5, 0); __delay_ms(100);
        ret = lcd_4bit_send_custome_char(&lcd_1, 1,20, customChar6, 0); __delay_ms(100);
         /*
        ret = convert_uint8_to_string(lcd1_counter, lcd_counter_txt);
        ret = lcd_8bit_send_string_pos(&lcd_2, 1, 10, lcd_counter_txt);
        lcd1_counter++;
        __delay_ms(100);
       
        for(lcd1_counter = 5; lcd1_counter<=7; ++lcd1_counter){
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, lcd1_counter,"Welcome");
            __delay_ms(200);
            ret = lcd_4bit_send_char_data_pos(&lcd_1, 1, lcd1_counter, ' ');
        }
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 5 ,"            ");
        */
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
   ecu_layer_Initialize();
}

