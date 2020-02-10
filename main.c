
/*
 * main.c
 *
 *  Created on: 8 Sep 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "BitOperations.h"
#include "keypad.h"
#include "LCD.h"

int main (void)
{
	 keypad_init ();
	 LCD_Inint ();
	 U8 key_val = 16;
	 U8 i=0;
	 U8 op = 4;
	 U8 j,h;
	 U8 flag = 0;
     U16 num1=0;
	 U16 num2 = 0;
	 U16 result = 0;
	 char str[15] = {0};
	 char Ans [] = "Ans = ";

    while (1)
	 {

	     key_val = Scan_keypad ();
		 if (key_val != 16 )
			{
			   switch (key_val)
					  {
					   case 0:
							  LCD_PrintNumber (1);
							  str[i] = '1';
							  i ++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 1:
							  LCD_PrintNumber (2);
							  str[i] = '2';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 2:
							  LCD_PrintNumber (3);
							  str[i] = '3';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 3:
							  LCD_SendData ('+');
							  op = 0;
							  str[i] = '+';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 4:
							  LCD_PrintNumber (4);
							  str[i] = '4';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 5:
							  LCD_PrintNumber (5);
							  str[i] = '5';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 6:
							  LCD_PrintNumber (6);
							  str[i] ='6';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 7:
							  LCD_SendData ('-');
							  op = 1;
							  str[i] = '-';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 8:
							  LCD_PrintNumber (7);
							  str[i] = '7';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 9:
							  LCD_PrintNumber (8);
							  str[i] = '8';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 10:
							  LCD_PrintNumber (9);
							  str[i] = '9';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 11:
							  LCD_SendData ('*');
							  op = 2;
							  str[i] = '*';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 12:
							 num1 =0;
							 num2=0;
							 result = 0;
							 //i =0;
							 j=0;
							 flag =0;
							 h = 0;
							 op =4;
							 for (i =0; i<15; i++)
							 {
								 str[i] = 0;
							 }
							 i = 0;
							 LCD_SendCommand (CLR_DISPLAY);
							 LCD_SendCommand (SET_DDR_ADDRESS);
							 while (Scan_keypad () == key_val);
						  break;

						  case 13:
							  LCD_PrintNumber (0);
							  str[i] = '0';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 15:
							  LCD_SendData ('/');
							  op = 3;
							  str[i] = '/';
							  i++;
							  while (Scan_keypad () == key_val);
						  break;

						  case 14:
						      LCD_SendCommand (SECONDLINE_DDR_ADDRESS);
						      num1 =0;
						      num2=0;
						      result = 0;
							  for (j = 0;(( str[j] != '+') && (str[j] != '-' ) && (str[j] != '*') && (str[j] != '/' )); j++)
							  			 {
							  				 num1 = ((num1 *10 ) + (str[j]-48)) ;
							  				 flag = j;

							  			 }

							  			 for (h = (flag+2);( str[h] != '\0' ); h++)
							  			 {
							  				 num2 = ((num2 *10 ) + (str[h]-48));

							  			 }

							  			 switch (op)
							  			 {
							  			 case 0:
							  				LCD_PrintString (Ans);
							  				 result =( num1 + num2);
							  				LCD_PrintNumber (result);
							  			 break;
							  			 case 1:
							  				LCD_PrintString (Ans);
							  			 	result = (num1 - num2) ;
							  			 	LCD_PrintNumber (result);
							  			 break;
							  			 case 2:
							  				LCD_PrintString (Ans);
							  			 	result = (num1 * num2);
							  			 	LCD_PrintNumber (result);
							  			 break;
							  			 case 3:
							  				LCD_PrintString (Ans);
							  			 	 result = (num1 / num2);
							  			 	LCD_PrintNumber (result);
							  			 break;
							  			 default:
										 break;
							  			 }
						  break;



						  default:
						  break;
					}

	         }
	    }
	return 0;
}
