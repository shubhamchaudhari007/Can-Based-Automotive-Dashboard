/*
 * File:   message_handler.c
 * Author: HP
 *
 * Created on 7 April, 2026, 12:00 PM
 */


#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"
#include <string.h>

unsigned short msg_id;
unsigned char data[10];
unsigned char len;

volatile unsigned char led_state = LED_OFF, status = e_ind_off;

extern unsigned int sec;
void handle_speed_data(uint8_t *data, uint8_t len)
{
    //Implement the speed function
    data[2] = '\0';
//    clcd_putch(data[0],LINE2(0));
//    clcd_putch(data[1],LINE2(1));
    clcd_print(data,LINE2(0));
}

void handle_gear_data(uint8_t *data, uint8_t len) 
{
    //Implement the gear function
    data[2] = '\0';
    clcd_print(data,LINE2(3));
//    clcd_putch(data[0],LINE2(3));
//    clcd_putch(data[1],LINE2(4));
}

void handle_rpm_data(uint8_t *data, uint8_t len) 
{
    //Implement the rpm function
    data[4] = '\0';
//    clcd_putch(data[0],LINE2(6));
//    clcd_putch(data[1],LINE2(7));
//    clcd_putch(data[2],LINE2(8));
//    clcd_putch(data[3],LINE2(9));
    clcd_print(data,LINE2(6));
}

void handle_engine_temp_data(uint8_t *data, uint8_t len) 
{
    //Implement the temperature function
}

void handle_indicator_data(uint8_t *data, uint8_t len) 
{
    //Implement the indicator function
    //clcd_putch(len,LINE2(11));
    //data[len] = '\0';
    if(*data == 'L'){
        //clcd_print("<-",LINE2(11));
        clcd_print("<-",LINE2(11));
        //clcd_putch('-',LINE2(12));
        if(sec < 2){
            PORTBbits.RB0 = 1;
            PORTBbits.RB1 = 1;
            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;
        }else if(sec < 4){
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;
        }else 
            sec = 0;
    }
    if(*data== 'O'){
        //clcd_print(" ",LINE2(11));
        clcd_print(""  "",LINE2(11));
        //clcd_putch(' ',LINE2(12));
        
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;
    }
    if(*data=='R'){
        //clcd_print("->",LINE2(10));
        clcd_print("->",LINE2(11));
        //clcd_putch('>',LINE2(12));
        if(sec < 2){
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB6 = 1;
            PORTBbits.RB7 = 1;
        }else if(sec < 4){
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;
        }else 
            sec = 0;
    }
}

void process_canbus_data() 
{   
    //process the CAN bus data
    can_receive(&msg_id,data,&len);
    
    if(msg_id == SPEED_MSG_ID){
        handle_speed_data(data,len);
    }
    if(msg_id == GEAR_MSG_ID){
        handle_gear_data(data,len);
    }
    if(msg_id == RPM_MSG_ID){
        handle_rpm_data(data,len);
    }
    if(msg_id == INDICATOR_MSG_ID){
        handle_indicator_data(data,len);
    }
}
