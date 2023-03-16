/*
 ============================================================================
 Name        : Calculator.c
 Author      : Ahmed
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "main.h"


int main(void) {

	char infixNotation[BUFFER_SIZE];
	memset(infixNotation, 0, BUFFER_SIZE);
	strcpy(infixNotation, "(((1+2)*3-5)*2)" );


	char postfixNotation[BUFFER_SIZE];
	memset(postfixNotation, 0, BUFFER_SIZE);

	infixToPostfix(infixNotation, postfixNotation);
	uint8_t value = evaluatePostfix(postfixNotation);

	printf("%s=%d", infixNotation, value);

	return 0;
}
