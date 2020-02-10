/*
 * keypad.h
 *
 *  Created on: 6 Sep 2019
 *      Author: Kimo Store
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define ROWPORT0 PORT3
#define ROWPORT1 PORT3
#define ROWPORT2 PORT3
#define ROWPORT3 PORT3

#define ROWPIN0 PIN0
#define ROWPIN1 PIN1
#define ROWPIN2 PIN2
#define ROWPIN3 PIN3

#define COLPORT0 PORT3
#define COLPORT1 PORT3
#define COLPORT2 PORT3
#define COLPORT3 PORT3

#define COLPIN0 PIN7
#define COLPIN1 PIN6
#define COLPIN2 PIN5
#define COLPIN3 PIN4

#define not_pressed 16;

void keypad_init (void);

/*
 * a: num of row
 * b: num of colums
 */
void display (U8 a, U8 b);

U8 Scan_keypad (void);

U8 keypad_to_seg (U8 row);
#endif /* KEYPAD_H_*/
