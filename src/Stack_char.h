/*
 * Stack.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Master
 */

#ifndef STACK_CHAR_H_
#define STACK_CHAR_H_

#define BUFFER_SIZE		100

typedef struct{
	char buffer[BUFFER_SIZE];
	char *top;
	char *start;
	uint8_t isEmpty;
}StackChar_t;


void stack_char_ctor(StackChar_t *this);
uint8_t stack_char_isEmpty(StackChar_t *this);
void stack_char_push(StackChar_t *this, char input);
void stack_char_pop(StackChar_t *this);
char stack_char_top(StackChar_t *this);

//Works only if the stack_char buffer is Terminated by a NULL
void stack_char_print(StackChar_t *this);
void stack_char_get_string(StackChar_t *this, char *string);



#endif /* STACK_CHAR_H_ */
