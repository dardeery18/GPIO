/*
 *
 * GPIO_DRIVER.C
 *
 *  Created on: Jul 29, 2018
 *      Author: dardeery
 */

#include "GPIO_DRIVER.H"


/*************************************************************************************************************
 *  correct done
 *************************************************************************************************************/

void SET_PORT_DIRECTION (PORT_BASE port , direction state)
{
    //bool_t ret_val =E_TRUE;
if (state == OUT)

{
	switch (port)
	{
	case porta:
		DDRA |=0xff;
		break ;

	case portb:
		DDRB |=0xff;
		break ;
	case portc:
		DDRC |=0xff;
		break ;
	case portd:
		DDRD |=0xff;
		break ;
	}
}

else if (state == IN)
 {
  {
	switch (port)
	{
	case porta:
		DDRA |=0x00;
		break ;

	case portb:
		DDRB |=0x00;
		break ;
	case portc:
		DDRC |=0x00;
		break ;
	case portd:
		DDRD |=0x00;
		break ;
	}
  }
 }
 //return ret_val ;
}


/*************************************************************************************************************
 *  correct done
 *************************************************************************************************************/

void WRITE_PORT_VALUE (PORT_BASE port , uint8 val)

{
    //bool_t ret_val = E_TRUE;
	switch (port)
	{
	case porta :
		PORTA =val;
		break ;
	case portb :
		PORTB =val;
		break ;
	case portc :
		PORTC =val;
		break ;
	case portd :
		PORTD =val;
		break ;

	}
	//return ret_val ;
}

/*************************************************************************************************************
 *  correct done
 *************************************************************************************************************/


void   SET_PIN_DIRECTION   (PORT_BASE PORT , uint8 PIN_NUM ,direction state)     //set one pin from the port
{
	//bool_t ret_val = true;
	if (state == OUT)
	{
	switch (PORT)
	{
		case  porta:
		 SET_BIT (DDRA, PIN_NUM);
		 break;
		case  portb:
		SET_BIT (DDRB, PIN_NUM);
		break;
		case  portc:
		SET_BIT (DDRC, PIN_NUM);
		break;
		case  portd:
		SET_BIT (DDRD, PIN_NUM);
		break;
								 
	}
	}
	else if(state == IN )
	{
	switch (PORT)
	{
		case  porta:
		CLEAR_BIT (PORTA, PIN_NUM);
		break;
		case  portb:
		CLEAR_BIT (PORTB, PIN_NUM);
		break;
		case  portc:
		CLEAR_BIT (PORTC, PIN_NUM);
		break;
		case  portd:
		CLEAR_BIT (PORTD, PIN_NUM);
		break;
		
	}
	}
	//return ret_val;
}


/*************************************************************************************************************
 *  correct done
 *************************************************************************************************************/

uint8 READ_PORT (PORT_BASE PORT )                      //read port
{
	uint8 result = 255;
	switch (PORT)
	{
	case porta :
	result &= PINA;
	return result;
	break;
	case portb :
	result &= PINB;
	return result;
	break;
	case portc :
	result &= PINC;
	return result;
	break;
	case portd :
	result &= PIND;
	return result;		
	break;	
   }

}
/************************************************************************/
/*  correct done                                                                    
/************************************************************************/
uint8 READ_BIN (PORT_BASE PORT , uint8 PIN_NUM)                      //read pins
{
	uint8 result = 0;
	
	switch (PORT)
	{
		case  porta:
		 result = BIT_IS_SET (PINA, PIN_NUM);
		 return result ;
		 break;
		case  portb:
		 result = BIT_IS_SET(PINB , PIN_NUM);
		 return result ;
		break;
		case  portc:
		 result = BIT_IS_SET (PINC, PIN_NUM);
		 return result ;
		break;
		case  portd:
		 result = BIT_IS_SET (PIND, PIN_NUM);
		 return result ;
		break;
	}

	return result;
}

/*************************************************************************************************************
 *    Correct done
 *************************************************************************************************************/
void WRITE_PIN (PORT_BASE PORT , uint8 PIN_NUM , val_t value)                      // write on pins
{
	//bool_t ret_val = true;
if (value == HIGH)
	{
	switch (PORT)
	{
		case  porta:
		 SET_BIT(PORTA,PIN_NUM);
		 break;
		case  portb:
		SET_BIT(PORTB,PIN_NUM);
		break;
		case  portc:
		SET_BIT(PORTC,PIN_NUM);
		break;
		case  portd:
		SET_BIT(PORTD,PIN_NUM);
		break;
								 
	}
	}
	else if(value == LOW )
	{
	switch (PORT)
	{
		case  porta:
		CLEAR_BIT(PORTA,PIN_NUM);
		break;
		case  portb:
		CLEAR_BIT(PORTB,PIN_NUM);
		break;
		case  portc:
		CLEAR_BIT(PORTC,PIN_NUM);
		break;
		case  portd:
		CLEAR_BIT(PORTD,PIN_NUM);
		break;
		
	}
	}

	//return ret_val;
}

