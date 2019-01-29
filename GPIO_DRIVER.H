/*
 * GPIO_DRIVER.H
 *
 *  Created on: Jul 28, 2018
 *  Author    : dardeery
 *
 *
 *           there just prototype
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "common.h"
#include "REGISTERS.H"

typedef enum
{
	LOW   = 0,
    HIGH  = 1,

}val_t;

#define   set_pin_output(reg,bit_num)  reg|=(1<<bit_num)
#define   WRITE_PIN_HIGH(reg,pin_num)  reg|=(1<<pin_num)
#define   WRITE_PIN_LOW(reg,pin_num)   reg&=~(1<<pin_num)
#define   set_pin_input(reg,bit_num)   reg&=(~(1<<bit_num))
#define   toggle_pin(reg,bit_num)     reg^=(1<<bit_num)

typedef enum
{
	porta = 0,
	portb  ,
	portc  ,
	portd  ,
}PORT_BASE;


void   SET_PORT_DIRECTION  (PORT_BASE port , direction state);                  // set all pins in the port
void   SET_PIN_DIRECTION   (PORT_BASE PORT , uint8 PIN_NUM ,direction state);      //set one pin from the port
void   WRITE_PORT_VALUE    (PORT_BASE port , uint8 val);                           //write on port
uint8  READ_BIN            (PORT_BASE PORT , uint8 PIN_NUM);                      //read pins
void   WRITE_PIN           (PORT_BASE PORT , uint8 PIN_NUM , uint8 value);             // write on pins
uint8  READ_PORT           (PORT_BASE PORT );                                  // read port

#endif /* GPIO_DRIVER_H_ */
