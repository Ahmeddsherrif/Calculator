/*
 * Stack.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Master
 */

#ifndef STACK_H_
#define STACK_H_

#define BUFFER_SIZE		100

typedef struct{
	char buffer[BUFFER_SIZE];
	char *top;
	char *start;
	uint8_t isEmpty;
}Stack_t;


void stack_ctor(Stack_t *this);
uint8_t stack_isEmpty(Stack_t *this);
void stack_push(Stack_t *this, char input);
void stack_pop(Stack_t *this);
char stack_top(Stack_t *this);

//Works only if the stack buffer is Terminated by a NULL
void stack_print(Stack_t *this);
void stack_get_string(Stack_t *this, char *string);



#endif /* STACK_H_ */
