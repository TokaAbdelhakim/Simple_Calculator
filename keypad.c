/*
 * keypad.c
 *
 *  Created on: 6 Sep 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "BitOperations.h"
#include "Registers.h"
#include "DIO.h"
#include "keypad.h"
#include "button.h"


void keypad_init (void)
{
	DIO_SetPinDirection (ROWPORT0, ROWPIN0, OUTPUT);
	DIO_SetPinDirection (ROWPORT1, ROWPIN1, OUTPUT);
	DIO_SetPinDirection (ROWPORT2, ROWPIN2, OUTPUT);
	DIO_SetPinDirection (ROWPORT3, ROWPIN3, OUTPUT);
	DIO_SetPinPullup (COLPORT0, COLPIN0);
	DIO_SetPinDirection (COLPORT0, COLPIN0, INPUT);
	DIO_SetPinPullup (COLPORT1, COLPIN1);
	DIO_SetPinDirection (COLPORT1, COLPIN1, INPUT);
	DIO_SetPinPullup (COLPORT2, COLPIN2);
	DIO_SetPinDirection (COLPORT2, COLPIN2, INPUT);
	DIO_SetPinPullup (COLPORT3, COLPIN3);
	DIO_SetPinDirection (COLPORT3, COLPIN3, INPUT);

	//DIO_SetPinDirection (PORT1, PIN7, OUTPUT);
}

U8 Scan_keypad (void)
{
	U8 Row_array[4] ={ROWPORT0,ROWPORT1,ROWPORT2,ROWPORT3};
	U8 Row_Pin_array[4] ={ROWPIN0,ROWPIN1,ROWPIN2,ROWPIN3};
	U8 col_array[4] = {COLPORT0 , COLPORT1, COLPORT2, COLPORT3};
	U8 col_pin_array[4] = { COLPIN0 , COLPIN1 , COLPIN2, COLPIN3};
	U8 i,j,x;
	U8 index = 16;


	for (i=0; i<4 ; i++)
	{
		DIO_SetPinValue(Row_array[i],Row_Pin_array[i],LOW);
		for (j=0; j<4 ; j ++)
		{
			x= DIO_GetPinValue(col_array[j],col_pin_array[j]);
			//x = button_state (col_array[j],col_pin_array[j]);
			if (x == 0)
			{
			    //DIO_SetPinValue(PORT1,PIN7,HIGH);
				index=((i*4)+j);

			}
		}


		DIO_SetPinValue(Row_array[0],Row_Pin_array[0],HIGH);
		DIO_SetPinValue(Row_array[1],Row_Pin_array[1],HIGH);
		DIO_SetPinValue(Row_array[2],Row_Pin_array[2],HIGH);
		DIO_SetPinValue(Row_array[3],Row_Pin_array[3],HIGH);
	}
	return (index);
}


