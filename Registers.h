/*
 * Registers.h
 *
 *  Created on: 30 Aug 2019
 *      Author: Kimo Store
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PORTA (*((volatile U8*)0x3B))
#define PORTB (*((volatile U8*)0x38))
#define PORTC (*((volatile U8*)0x35))
#define PORTD (*((volatile U8*)0x32))

#define DDRA (*((volatile U8*)0x3A))
#define DDRB (*((volatile U8*)0x37))
#define DDRC (*((volatile U8*)0x34))
#define DDRD (*((volatile U8*)0x31))

#define PINA (*((volatile U8*)0x39))
#define PINB (*((volatile U8*)0x36))
#define PINC (*((volatile U8*)0x33))
#define PIND (*((volatile U8*)0x30))

#define SFIOR (*((volatile U8*)0x50))

#endif /* REGISTERS_H_ */
