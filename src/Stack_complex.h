/*
 * Stack.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Master
 */

#ifndef STACK_COMPLEX_H_
#define STACK_COMPLEX_H_

#define BUFFER_SIZE		100

typedef struct{
	COMPLEX buffer[BUFFER_SIZE];
	COMPLEX *top;
	COMPLEX *start;
	uint8_t isEmpty;
}StackComplex_t;


void stack_complex_ctor(StackComplex_t *this);
uint8_t stack_complex_isEmpty(StackComplex_t *this);
void stack_complex_push(StackComplex_t *this, COMPLEX input);
void stack_complex_pop(StackComplex_t *this);
COMPLEX stack_complex_top(StackComplex_t *this);


#endif /* STACK_COMPLEX_H_ */
