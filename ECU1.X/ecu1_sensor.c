/*
 * File:   ecu1_sensor.c
 * Author: HP
 *
 * Created on 1 April, 2026, 1:08 PM
 */


#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#include "clcd.h"
#include "matrix_keypad.h"

unsigned short value;
unsigned short data;
unsigned char speed[3];

unsigned char gear[9][3] = {"ON","NE","G1","G2","G3","G4","G5","GR","CL"};
char key;
 int index = 0;

unsigned short msg_id1;
unsigned char data1[3];
unsigned char len1;

unsigned short msg_id2;
unsigned char data2[3];
unsigned char len2;

uint16_t get_speed()
{
    // Implement the speed function
    
    
    value = read_adc(CHANNEL4);
    
    data = value / 10.23;
    
    speed[0] = data / 10 + '0';
    speed[1] = data % 10 + '0';
    speed[2] = '\0';
    
    
    can_transmit(SPEED_MSG_ID,speed,2);
    
    __delay_ms(80);
    
//    can_receive(&msg_id1,data1,&len1);
//    data1[len1] = '\0';
//    clcd_print(data1,LINE2(1));
}

unsigned char get_gear_pos()
{
    // Implement the gear function    
    
    key = read_switches(STATE_CHANGE);
    
    if(key == MK_SW1){
        if(index < 7)
            index++;
    }else if(key == MK_SW2){
        if(index > 0)
            index--;
    }else if(key == MK_SW3){
        index = 8;
    }
    
    can_transmit(GEAR_MSG_ID,gear[index],2);
    
    __delay_ms(80);
    
//    can_receive(&msg_id2,data2,&len2);
//    data1[len2] = '\0';
//    clcd_print(data2,LINE2(9));
    
    //clcd_print(gear[index],LINE2(9));
    
}
