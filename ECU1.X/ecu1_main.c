/*
 * File:   ecu1_main.c
 * Author: HP
 *
 * Created on 1 April, 2026, 1:08 PM
 */


#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"
#include "clcd.h"
#include "matrix_keypad.h"

char sp[] = "Speed";
char sp2[] = "Gear";

int main()
{
    //Call the functions
    init_adc();
    //init_clcd();
    init_matrix_keypad();
    init_can();
    
    while(1){
        //clcd_print(sp,LINE1(1));
        //clcd_print(sp2,LINE1(9));
        
        get_speed();
        
        get_gear_pos();
    }
}
