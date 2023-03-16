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
#include "Stack.h"

void stack_ctor(Stack_t *this) {
	memset(this, 0, sizeof(Stack_t));
	this->start = (char*) (&(this->buffer[0])) - 1;
	this->top = this->start;
	this->isEmpty = TRUE;
}

uint8_t stack_isEmpty(Stack_t *this) {
	return this->isEmpty;
}

void stack_push(Stack_t *this, char input) {
	(this->top)++;
	*(this->top) = input;
	this->isEmpty = FALSE;
}

void stack_pop(Stack_t *this) {
	if (this->top != this->start) {
		*(this->top) = 0;
		(this->top)--;

		if (this->top == this->start) {
			this->isEmpty = TRUE;
		}
	}
}

char stack_top(Stack_t *this) {
	char rtnChar = 0;
	if (this->top != this->start) {
		rtnChar = *(this->top);
	}
	return rtnChar;
}

void stack_get_string(Stack_t *this, char *string) {
	strcpy(string, this->buffer);
}

void stack_print(Stack_t *this) {
	printf("%s\t", this->buffer);
}
