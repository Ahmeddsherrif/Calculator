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
#include "Stack_char.h"

void stack_char_ctor(StackChar_t *this) {
	memset(this, 0, sizeof(StackChar_t));
	this->start = (char*) (&(this->buffer[0])) - 1;
	this->top = this->start;
	this->isEmpty = TRUE;
}

uint8_t stack_char_isEmpty(StackChar_t *this) {
	return this->isEmpty;
}

void stack_char_push(StackChar_t *this, char input) {
	(this->top)++;
	*(this->top) = input;
	this->isEmpty = FALSE;
}

void stack_char_pop(StackChar_t *this) {
	if (this->top != this->start) {
		*(this->top) = 0;
		(this->top)--;

		if (this->top == this->start) {
			this->isEmpty = TRUE;
		}
	}
}

char stack_char_top(StackChar_t *this) {
	char rtnChar = 0;
	if (this->top != this->start) {
		rtnChar = *(this->top);
	}
	return rtnChar;
}

void stack_char_get_string(StackChar_t *this, char *string) {
	strcpy(string, this->buffer);
}

void stack_char_print(StackChar_t *this) {
	printf("%s\t", this->buffer);
}
