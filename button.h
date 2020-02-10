/*
 * button.h
 *
 *  Created on: 15 Sep 2019
 *      Author: Kimo Store
 */

#ifndef BUTTON_H_
#define BUTTON_H_

//MAX COUNTER VALUE
#define MAX 50

//RETURN VALUES
#define R 0
#define P 1

//AVALIABLE STATES
#define RELEASED 2
#define PREPRESSED 3
#define PRESSED 4
#define PRERELEASED 5

//BUTTON CONFG
//#define BUTTON_PORT PORT3
//#define BUTTON_PIN PIN0

U8 button_state (U8 BUTTON_PORT , U8 BUTTON_PIN);

#endif /* BUTTON_H_ */
