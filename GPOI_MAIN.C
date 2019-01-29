/*
 * GPOI_MAIN.C
 *
 *  Created on: Aug 17, 2018
 *      Author: dardeery
 */
#include "GPIO_DRIVER.H"
int main(void)
{
    SET_PORT_DIRECTION (porta , OUT);

    while (1)
    {
		WRITE_PORT_VALUE(porta , 10);
    }
}


