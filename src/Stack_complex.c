/*
 * Stack.c
 *
 *  Created on: Mar 16, 2023
 *      Author: Master
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "defines.h"
#include "Complex.h"
#include "Stack_complex.h"

void stack_complex_ctor(StackComplex_t *this) {
	memset(this, 0, sizeof(StackComplex_t));
	this->start = (COMPLEX*) (&(this->buffer[0])) - 1;
	this->top = this->start;
	this->isEmpty = TRUE;
}

uint8_t stack_complex_isEmpty(StackComplex_t *this) {
	return this->isEmpty;
}

void stack_complex_push(StackComplex_t *this, COMPLEX input) {
	(this->top)++;
	*(this->top) = input;
	this->isEmpty = FALSE;
}

void stack_complex_pop(StackComplex_t *this) {
	if (this->top != this->start) {
		DestroyComplex(this->top);
		(this->top)--;

		if (this->top == this->start) {
			this->isEmpty = TRUE;
		}
	}
}

COMPLEX stack_complex_top(StackComplex_t *this) {
	COMPLEX rtnChar = {0, 0};
	if (this->top != this->start) {
		rtnChar = *(this->top);
	}
	return rtnChar;
}
