/*
 * button.c
 *
 *  Created on: 15 Sep 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "BitOperations.h"
#include "Registers.h"
#include "DIO.h"
#include "button.h"

U8 button_state (U8 BUTTON_PORT ,U8 BUTTON_PIN)
{
	U8 ret_val = R;
	static U8 state = RELEASED;
	static U16 counter = 0;

	switch (state)
	{
	 	 case RELEASED:
	 		 if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == LOW)
	 		 {
	 			 state = PREPRESSED;
	 		 }
	 		 ret_val = R;
	 		 break;

	 	 case PREPRESSED:
	 		ret_val = R;
	 		if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == HIGH)
	 		{
	 			state = RELEASED;
	 			counter = 0;
	 		}
	 		if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == LOW)
	 		{
	 			counter ++;
	 			if(counter >= MAX)
	 			{
	 				state = PRESSED;
	 				counter = 0;
	 			}
	 		}
	 		break;

	 	 case PRESSED:
	 		ret_val = P;
	 		if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == HIGH)
	 		{
	 			state = PRERELEASED;
	 		}
	 		break;

	 	 case PRERELEASED:
	 		ret_val = P;
	 		if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == LOW)
	 		{
	 			state = PRESSED;
	 			counter = 0;
	 		}
	 		if (DIO_GetPinValue (BUTTON_PORT, BUTTON_PIN) == HIGH)
	 		{
	 			counter ++;
	 			if(counter >= MAX)
	 			{
	 				state = RELEASED;
	 				counter = 0;
	 			}
	 		}
	 		break;

	 	 default:
	 		 break;
	}

	return (ret_val);
}
